//-------------------------------------------------------------------------
/*
Copyright (C) 1997, 2005 - 3D Realms Entertainment
Copyright (C) 2019 Christoph Oelckers

This file is part of Shadow Warrior version 1.2

Shadow Warrior is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

Original Source: 1997 - Frank Maddin and Jim Norwood
Prepared for public release: 03/28/2005 - Charlie Wiederhold, 3D Realms
*/
//-------------------------------------------------------------------------
#include "ns.h"
#include "compat.h"
#include "build.h"


#include "keys.h"

#include "names2.h"
#include "mytypes.h"
#include "gamedefs.h"
#include "config.h"


#include "panel.h"
#include "game.h"
#include "sounds.h"
#include "ai.h"
#include "network.h"

#include "cache.h"
#include "text.h"
#include "rts.h"
#include "menus.h"
#include "config.h"
#include "menu/menu.h"
#include "z_music.h"
#include "sound/s_soundinternal.h"
#include "filesystem/filesystem.h"

BEGIN_SW_NS

enum EChanExFlags
{
    CHANEXF_NODOPPLER = 0x20000000,
    CHANEXF_DONTPAN = 0x40000000,
};

// Parentally locked sounds list
int PLocked_Sounds[] =
{
    483,328,334,335,338,478,450,454,452,453,456,457,458,455,460,462,
    461,464,466,465,467,463,342,371,254,347,350,432,488,489,490,76,339,
    499,500,506,479,480,481,482,78,600,467,548,547,544,546,545,542,541,540,
    539,536,529,525,522,521,515,516,612,611,589,625,570,569,567,565,
    558,557
};

//
// Includes digi.h to build the table
//

#define DIGI_TABLE
VOC_INFO voc[] =
{
#include "digi.h"
};

#undef  DIGI_TABLE

//
// Includes ambient.h to build the table of ambient sounds for game
//

#define AMBIENT_TABLE
AMB_INFO ambarray[] =
{
#include "ambient.h"
};
#undef  AMBIENT_TABLE
#define MAX_AMBIENT_SOUNDS 82



//==========================================================================
//
// 
//
//==========================================================================

float S_ConvertPitch(int lpitch)
{
    return pow(2, lpitch / 1200.);
}

//==========================================================================
//
// Sound Distance Calculation
//
//==========================================================================

enum
{
    MAXLEVLDIST = 19000,   // The higher the number, the further away you can hear sound
    DECAY_CONST = 4000
};

short SoundDist(int x, int y, int z, int basedist)
{
    double tx, ty, tz;
    double sqrdist, retval;
    extern short screenpeek;

    tx = fabs(Player[screenpeek].posx - x);
    ty = fabs(Player[screenpeek].posy - y);
    tz = fabs((Player[screenpeek].posz - z) >> 4);

    // Use the Pythagreon Theorem to compute the magnitude of a 3D vector
    sqrdist = fabs(tx * tx + ty * ty + tz * tz);
    retval = sqrt(sqrdist);

    if (basedist < 0) // if basedist is negative
    {
        double decayshift = 2;
        int decay = labs(basedist) / DECAY_CONST;

        for (int i = 0; i < decay; i++)
            decayshift *= 2;

        if (fabs(double(basedist) / decayshift) >= retval)
            retval = 0;
        else
            retval *= decay;
    }
    else
    {
        if (basedist > retval)
            retval = 0;
        else
            retval -= basedist;
    }

    retval = retval * 256 / MAXLEVLDIST;

    if (retval < 0) retval = 0;
    if (retval > 255) retval = 255;

    return retval;
}

//==========================================================================
//
// Calculate rolloff info. 
//
//==========================================================================

FRolloffInfo GetRolloff(int basedist)
{
    FRolloffInfo info;

    if (basedist < 0) // if basedist is negative
    {
        double decayshift = 2;
        int decay = labs(basedist) / DECAY_CONST;

        for (int i = 0; i < decay; i++)
            decayshift *= 2;

        info.RolloffType = ROLLOFF_Doom;
        info.MinDistance = (float)(-basedist / decayshift / 16.);
        info.MaxDistance = MAXLEVLDIST / 16.f / decay;
    }
    else
    {
        info.RolloffType = ROLLOFF_Doom;
        info.MinDistance = basedist / 16.f;
        info.MaxDistance = info.MinDistance + MAXLEVLDIST / 16.f;
    }
    return info;
}


//==========================================================================
//
//
// Ambient sounds
//
//
//==========================================================================

struct AmbientSound
{
    SPRITEp sp;
    FSoundChan* sndChan;
    int ambIndex;
    int vocIndex;
    int ChanFlags;
    int maxIndex;
    int curIndex;
    bool intermit;
};

static TArray<AmbientSound*> ambients;


//==========================================================================
//
//
//
//==========================================================================

void StopAmbientSound(void)
{
    for (auto& amb : ambients)
    {
        if (amb->sndChan)
        {
            soundEngine->StopChannel(amb->sndChan);
        }
    }
    ambients.Clear();
}


//==========================================================================
//
// Play a sound
//
//==========================================================================

void InitAmbient(int num, SPRITEp sp)
{
    VOC_INFOp vp;
    int pitch = 0;
    short angle, sound_dist;
    int tx, ty, tz;
    uint8_t priority;
    int maxtics = 0;

    if (!snd_ambience) return;

    // Ambient sounds need special treatment
    if (num < 0 || num > MAX_AMBIENT_SOUNDS)
    {
        sprintf(ds, "Invalid or out of range ambient sound number %d\n", num);
        PutStringInfo(Player + screenpeek, ds);
        return;
    }
    auto vnum = ambarray[num].diginame;
    if (!soundEngine->isValidSoundId(vnum))
    {
        return; // linked sound does not exist.
    }

    auto amb = new AmbientSound;
    amb->sp = sp;
    amb->ambIndex = num;
    amb->vocIndex = vnum;
    amb->sndChan = nullptr;
    amb->ChanFlags = 0;
    if (ambarray[num].ambient_flags & v3df_dontpan) amb->ChanFlags |= EChanFlags::FromInt(CHANEXF_DONTPAN);
    if (voc[vnum].voc_flags & vf_loop) amb->ChanFlags |= CHANF_LOOP; 
    amb->maxIndex = ambarray[num].maxtics * 8;
    amb->curIndex = 0;
    amb->intermit = !!(ambarray[num].ambient_flags & v3df_intermit);
    ambients.Push(amb);
}

//==========================================================================
//
//
//
//==========================================================================

void StartAmbientSound(void)
{
    short i, nexti;
    extern SWBOOL InMenuLevel;

    if (InMenuLevel || !SoundEnabled()) return; // Don't restart ambience if no level is active! Will crash game.

    TRAVERSE_SPRITE_STAT(headspritestat[STAT_AMBIENT], i, nexti)
    {
        SPRITEp sp = &sprite[i];
        InitAmbient(sp->lotag, sp);
    }
}

//==========================================================================
//
//
//
//==========================================================================

static void RestartAmbient(AmbientSound* amb)
{
    auto& vp = voc[amb->vocIndex];
    auto rolloff = GetRolloff(vp.voc_distance);
    int pitch = 0;
    if (vp.pitch_hi <= vp.pitch_lo) pitch = vp.pitch_lo;
    else pitch = vp.pitch_lo + (STD_RANDOM_RANGE(vp.pitch_hi - vp.pitch_lo));

    soundEngine->StartSound(SOURCE_Ambient, amb, nullptr, CHAN_BODY, EChanFlags::FromInt(amb->ChanFlags), amb->vocIndex, 1.f, ATTN_NORM, &rolloff, S_ConvertPitch(pitch));
}
//==========================================================================
//
//
//
//==========================================================================

static int RandomizeAmbientSpecials(int handle)
{
#define MAXRNDAMB 12
    int ambrand[] =
    {
        56,57,58,59,60,61,62,63,64,65,66,67
    };
    int i;

    // If ambient sound is found in the array, randomly pick a new sound
    for (i = 0; i < MAXRNDAMB; i++)
    {
        if (handle == ambarray[ambrand[i]].diginame)
            return ambrand[STD_RANDOM_RANGE(MAXRNDAMB - 1)];
    }

    return -1;
}

//==========================================================================
//
//
//
//==========================================================================


static void DoTimedSound(AmbientSound* amb)
{
    amb->curIndex += synctics;
    if (amb->curIndex >= amb->maxIndex)
    {
        if (amb->sndChan == nullptr || (amb->sndChan->ChanFlags & CHANF_FORGETTABLE))
        {
            // Check for special case ambient sounds. Since the sound is stopped and doesn't occupy a real channel at this time we can just swap out the sound ID before restarting it.
            int ambid = RandomizeAmbientSpecials(amb->vocIndex);
            if (ambid != -1)
            {
                amb->vocIndex = ambid;
                amb->maxIndex = STD_RANDOM_RANGE(ambarray[ambid].maxtics);
            }
            RestartAmbient(amb);
        }
    }
}

//==========================================================================
//
// 
//
//==========================================================================

static void UpdateAmbients()
{
    for (auto& amb : ambients)
    {
        auto sp = amb->sp;
        auto sdist = SoundDist(sp->pos.x, sp->pos.y, sp->pos.z, voc[amb->vocIndex].voc_distance);

        if (sdist < 255 && amb->vocIndex == DIGI_WHIPME)
        {
            PLAYERp pp = Player + screenpeek;
            if (!FAFcansee(sp->pos.x, sp->pos.y, sp->pos.z, sp->sectnum, pp->posx, pp->posy, pp->posz, pp->cursectnum))
            {
                sdist = 255;
            }
        }
        if (sdist < 255)
        {
            if (amb->intermit) DoTimedSound(amb);
            else RestartAmbient(amb);

        }
        else
        {
            if (amb->sndChan)
            {
                soundEngine->StopChannel(amb->sndChan);
                amb->sndChan = nullptr;
            }
        }

    }
}

//==========================================================================
//
// end of ambient sounds
//
//==========================================================================




//==========================================================================
//
//
//
//==========================================================================

class SWSoundEngine : public SoundEngine
{
    // client specific parts of the sound engine go in this class.
    void CalcPosVel(int type, const void* source, const float pt[3], int channum, int chanflags, FSoundID chanSound, FVector3* pos, FVector3* vel, FSoundChan* chan) override;
    TArray<uint8_t> ReadSound(int lumpnum) override;
    void ChannelEnded(FISoundChannel* chan) override;

public:
    SWSoundEngine()
    {
        S_Rolloff.RolloffType = ROLLOFF_Doom;  
        S_Rolloff.MinDistance = 0;            // These are the default values, SW uses a few different rolloff settings.
        S_Rolloff.MaxDistance = 1187;
    }
};

//==========================================================================
//
//
// 
//==========================================================================

TArray<uint8_t> SWSoundEngine::ReadSound(int lumpnum)
{
    auto wlump = fileSystem.OpenFileReader(lumpnum);
    return wlump.Read();
}

void SWSoundEngine::ChannelEnded(FISoundChannel* chan)
{
    // if this channel belongs to an ambient sound we have to delete the reference to it.
    for (auto amb : ambients)
    {
        if (amb->sndChan == chan)
        {
            amb->sndChan = nullptr;
        }
    }
    SoundEngine::ChannelEnded(chan);
}

//==========================================================================
//
//
//
//==========================================================================

void InitFX(void)
{
    if (soundEngine) return; // just in case.
    soundEngine = new SWSoundEngine;

    auto &S_sfx = soundEngine->GetSounds();
    S_sfx.Resize(countof(voc));
    for (auto& sfx : S_sfx) { sfx.Clear(); sfx.lumpnum = sfx_empty; }
    for (size_t i = 1; i < countof(voc); i++)
    {
        auto& entry = voc[i];
        auto lump = S_LookupSound(entry.name);
        if (lump > 0)
        {
            auto& newsfx = S_sfx[i];
            newsfx.name = entry.name;
            newsfx.lumpnum = lump;
            newsfx.NearLimit = 6;
            newsfx.bTentative = false;
        }
    }
    soundEngine->HashSounds();
    for (auto& sfx : S_sfx)
    {
        soundEngine->CacheSound(&sfx);
    }
}



//==========================================================================
//
// 
//
//==========================================================================

void SWSoundEngine::CalcPosVel(int type, const void* source, const float pt[3], int channum, int chanflags, FSoundID chanSound, FVector3* pos, FVector3* vel, FSoundChan* chan)
{
    if (pos != nullptr)
    {
        PLAYERp pp = Player + screenpeek;
        FVector3 campos = GetSoundPos((vec3_t*)pp);
        vec3_t *vpos = nullptr;

        if (vel) vel->Zero();

        if (type == SOURCE_Unattached)
        {
            pos->X = pt[0];
            pos->Y = pt[1];
            pos->Z = pt[2];
        }
        else if (type == SOURCE_Actor || type == SOURCE_Player)
        {
            vpos = type == SOURCE_Actor ? &((SPRITEp)source)->pos : (vec3_t*)&((PLAYERp)source)->posx;
            FVector3 npos = GetSoundPos(vpos);

            *pos = npos;
            if (!(chanflags & CHANEXF_NODOPPLER) && vel)
            {
                // Hack alert. Velocity may only be set if a) the sound is already running and b) an actual sound channel is modified.
                // It remains to be seen if this is actually workable. I have my doubts. The velocity should be taken from a stable source.
                if (chan && !(chanflags & (CHANF_JUSTSTARTED | CHANF_EVICTED)))
                {
                    *vel = (npos - FVector3(pt[0], pt[1], pt[2])) * 40; // SW ticks 40 times a second.
                    chan->Point[0] = npos.X;
                    chan->Point[1] = npos.Y;
                    chan->Point[2] = npos.Z;
                }
            }
        }
        else if (type == SOURCE_Ambient)
        {
            auto sp = ((AmbientSound*)source)->sp;
            vec3_t* vpos = type == SOURCE_Actor ? &((SPRITEp)source)->pos : (vec3_t*)&((PLAYERp)source)->posx;
            FVector3 npos = GetSoundPos(vpos);

            // Can the ambient sound see the player?  If not, tone it down some.
            if ((chanflags & CHANF_LOOP))
            {
                if (!FAFcansee(vpos->x, vpos->y, vpos->z, sp->sectnum, pp->posx, pp->posy, pp->posz, pp->cursectnum))
                {
                    auto distvec = npos - campos;
                    npos = campos + distvec * 1.75f;  // Play more quietly
                }
            }
            *pos = npos;
        }

        if (vpos && chanflags & CHANEXF_DONTPAN)
        {
            // For unpanned sounds the volume must be set directly and the position taken from the listener.
            *pos = campos;
            auto sdist = SoundDist(vpos->x, vpos->y, vpos->z, voc[chanSound].voc_distance);
            if (chan) SetVolume(chan, (255 - sdist) * (1 / 255.f));
        }


        if ((chanflags & CHANF_LISTENERZ) && campos != nullptr && type != SOURCE_None)
        {
            pos->Y = campos.Y;
        }
    }
}

//==========================================================================
//
// Main function to update 3D sound array
//
//==========================================================================

void DoUpdateSounds(void)
{
    PLAYERp pp = Player + screenpeek;
    SoundListener listener;

    listener.angle = -(float)pp->pang * pi::pi() / 1024; // Build uses a period of 2048.
    listener.velocity.Zero();
    listener.position = GetSoundPos((vec3_t*)&pp->posx);
    listener.underwater = false;
    // This should probably use a real environment instead of the pitch hacking in S_PlaySound3D.
    // listenactor->waterlevel == 3;
    //assert(primaryLevel->Zones.Size() > listenactor->Sector->ZoneNumber);
    listener.Environment = 0;// primaryLevel->Zones[listenactor->Sector->ZoneNumber].Environment;
    listener.valid = true;

    listener.ListenerObject = pp;
    soundEngine->SetListener(listener);

    UpdateAmbients();
    soundEngine->UpdateSounds((int)totalclock);
}

//==========================================================================
//
// Play a sound
//
//==========================================================================

int _PlaySound(int num, SPRITEp sp, PLAYERp pp, vec3_t* pos, Voc3D_Flags flags, int channel)
{
    if (Prediction || !SoundEnabled() || !soundEngine->isValidSoundId(num))
        return -1;

    // Weed out parental lock sounds if PLock is active
    if (adult_lockout || Global_PLock)
    {
        for (unsigned i = 0; i < sizeof(PLocked_Sounds); i++)
        {
            if (num == PLocked_Sounds[i])
                return -1;
        }
    }

    auto vp = &voc[num];
    int sourcetype = SOURCE_None;
    EChanFlags cflags = channel == 8 ? CHANF_OVERLAP : CHANF_NONE;  // for the default channel we do not want to have sounds stopping each other.
    void* source = nullptr;
    // If the sound is not supposd to be positioned, it may not be linked to the launching actor.
    if (!(flags & v3df_follow))
    {
        if (sp && !pos)
        {
            pos = &sp->pos;
            sp = nullptr;
        }
        else if (pp && !pos)
        {
            pos = (vec3_t*)&pp->posx;
            pp = nullptr;
        }
    }

    if (pos != nullptr)
    {
        sourcetype = SOURCE_Unattached;
    }
    else if (sp != nullptr)
    {
        source = sp;
        sourcetype = SOURCE_Actor;
    }
    else if (pp != nullptr)
    {
        source = pp;
        sourcetype = SOURCE_Player;
    }
    // Otherwise it's an unpositioned sound.

    if (flags & v3df_doppler) cflags |= EChanFlags::FromInt(CHANEXF_NODOPPLER);    // this must ensure that CalcPosVel always zeros the velocity.
    if (flags & v3df_dontpan) cflags |= EChanFlags::FromInt(CHANEXF_DONTPAN);      // beware of hackery to emulate this. 
    if (vp->voc_flags & vf_loop) cflags |= CHANF_LOOP;                               // with the new sound engine these can just be started and don't have to be stopped ever.

    int pitch = 0;
    if (vp->pitch_hi <= vp->pitch_lo) pitch = vp->pitch_lo;
    else if (vp->pitch_hi != vp->pitch_lo) pitch = vp->pitch_lo + (STD_RANDOM_RANGE(vp->pitch_hi - vp->pitch_lo));

    auto rolloff = GetRolloff(vp->voc_distance);
    FVector3 spos = pos ? GetSoundPos(pos) : FVector3(0, 0, 0);
    soundEngine->StartSound(sourcetype, source, &spos, channel, cflags, num, 1.f, ATTN_NORM, &rolloff, S_ConvertPitch(pitch));
    return 1;
}

//==========================================================================
//
//
//
//==========================================================================

void PlaySoundRTS(int rts_num)
{
    if (!adult_lockout && SoundEnabled() && RTS_IsInitialized() && snd_speech)
    {
        auto sid = RTS_GetSoundID(rts_num - 1);
        if (sid != -1)
        {
            soundEngine->StartSound(SOURCE_Unattached, nullptr, nullptr, CHAN_VOICE, 0, sid, 0.8f, ATTN_NONE);
        }
    }
}

//==========================================================================
//
//
//
//==========================================================================

void COVER_SetReverb(int amt)
{
    FX_SetReverb(amt);
}

//==========================================================================
//
// Deletes vocs in the 3D sound queue with no owners
//
//==========================================================================

void DeleteNoSoundOwner(short spritenum)
{
    if (!soundEngine) return;
    SPRITEp sp = &sprite[spritenum];

    soundEngine->EnumerateChannels([=](FSoundChan* chan)
        {
            if (chan->Source == sp && chan->ChanFlags & CHANF_LOOP)
            {
                soundEngine->StopChannel(chan);
            }
            return false;
        });
}

//==========================================================================
//
// This is called from KillSprite to kill a follow sound with no valid sprite owner
// Stops any active sound with the follow bit set, even play once sounds.
//
//==========================================================================

void DeleteNoFollowSoundOwner(short spritenum)
{
    SPRITEp sp = &sprite[spritenum];
    soundEngine->StopSound(SOURCE_Actor, sp, -1); // all non-follow sounds are SOURCE_Unattached
}

//==========================================================================
//
// Terminate the sounds list
//
//==========================================================================

void Terminate3DSounds(void)
{
    soundEngine->EnumerateChannels([](FSoundChan* chan)
        {
            if (chan->SourceType == SOURCE_Actor || chan->SourceType == SOURCE_Unattached ||
                (chan->SourceType == SOURCE_Player && chan->EntChannel != CHAN_VOICE))
            {
                soundEngine->StopChannel(chan);
            }
            return false;
        });
}


//==========================================================================
//
// no longer needed, only left to avoid changing the game code
//
//==========================================================================

void Set3DSoundOwner(short spritenum)
{
    
}

//==========================================================================
//
// Play a sound using special sprite setup
//
//==========================================================================

void PlaySpriteSound(short spritenum, int attrib_ndx, Voc3D_Flags flags)
{
    SPRITEp sp = &sprite[spritenum];
    USERp u = User[spritenum];

    ASSERT(u);

    PlaySound(u->Attrib->Sounds[attrib_ndx], sp, flags);
}

//==========================================================================
//
//
//
//==========================================================================

int _PlayerSound(int num, PLAYERp pp)
{
    int handle;
    VOC_INFOp vp;

    if (Prediction)
        return 0;

    if (pp < Player || pp >= Player + MAX_SW_PLAYERS)
    {
        return 0;
    }

    if (num < 0 || num >= DIGI_MAX || !soundEngine->isValidSoundId(num))
        return 0;

    if (TEST(pp->Flags, PF_DEAD)) return 0; // You're dead, no talking!

    // If this is a player voice and he's already yacking, forget it.
    vp = &voc[num];

    // Not a player voice, bail.
    if (vp->priority != PRI_PLAYERVOICE && vp->priority != PRI_PLAYERDEATH)
        return 0;

    // He wasn't talking, but he will be now.
    if (!soundEngine->IsSourcePlayingSomething(SOURCE_Player, pp, CHAN_VOICE))
    {
        soundEngine->StartSound(SOURCE_Player, pp, nullptr, CHAN_VOICE, 0, num, 1.f, ATTN_NORM);
    }

    return 0;
}

void StopPlayerSound(PLAYERp pp)
{
    soundEngine->StopSound(SOURCE_Player, pp, CHAN_VOICE);
}

bool SoundValidAndActive(SPRITEp spr, int channel)
{
    return soundEngine->IsSourcePlayingSomething(SOURCE_Actor, spr, channel);
}


/*
============================================================================
=
= High level sound code (not directly engine related)
=
============================================================================
*/

int PlayerPainVocs[] =
{
    DIGI_PLAYERPAIN1,
    DIGI_PLAYERPAIN2,
    DIGI_PLAYERPAIN3,
    DIGI_PLAYERPAIN4,
    DIGI_PLAYERPAIN5
};

// Don't have these sounds yet
int PlayerLowHealthPainVocs[] =
{
    DIGI_HURTBAD1,
    DIGI_HURTBAD2,
    DIGI_HURTBAD3,
    DIGI_HURTBAD4,
    DIGI_HURTBAD5
};

int TauntAIVocs[] =
{
    DIGI_TAUNTAI1,
    DIGI_TAUNTAI2,
    DIGI_TAUNTAI3,
    DIGI_TAUNTAI4,
    DIGI_TAUNTAI5,
    DIGI_TAUNTAI6,
    DIGI_TAUNTAI7,
    DIGI_TAUNTAI8,
    DIGI_TAUNTAI9,
    DIGI_TAUNTAI10,
    DIGI_COWABUNGA,
    DIGI_NOCHARADE,
    DIGI_TIMETODIE,
    DIGI_EATTHIS,
    DIGI_FIRECRACKERUPASS,
    DIGI_HOLYCOW,
    DIGI_HAHA2,
    DIGI_HOLYPEICESOFCOW,
    DIGI_HOLYSHIT,
    DIGI_HOLYPEICESOFSHIT,
    DIGI_PAYINGATTENTION,
    DIGI_EVERYBODYDEAD,
    DIGI_KUNGFU,
    DIGI_HOWYOULIKEMOVE,
    DIGI_HAHA3,
    DIGI_NOMESSWITHWANG,
    DIGI_RAWREVENGE,
    DIGI_YOULOOKSTUPID,
    DIGI_TINYDICK,
    DIGI_NOTOURNAMENT,
    DIGI_WHOWANTSWANG,
    DIGI_MOVELIKEYAK,
    DIGI_ALLINREFLEXES
};

int PlayerGetItemVocs[] =
{
    DIGI_GOTITEM1,
    DIGI_HAHA1,
    DIGI_BANZAI,
    DIGI_COWABUNGA,
    DIGI_TIMETODIE
};

int PlayerYellVocs[] =
{
    DIGI_PLAYERYELL1,
    DIGI_PLAYERYELL2,
    DIGI_PLAYERYELL3
};


//==========================================================================
//
// PLays music
//
//==========================================================================

extern short Level;

SWBOOL PlaySong(const char* mapname, const char* song_file_name, int cdaudio_track, bool isThemeTrack) //(nullptr, nullptr, -1, false) starts the normal level music.
{
    // Play  CD audio if enabled.
    if (cdaudio_track >= 0 && (mus_redbook || *song_file_name == 0))
    {
        FStringf trackname("track%02d.ogg", cdaudio_track);
        if (!Mus_Play(mapname, trackname, true))
        {
            buildprintf("Can't find CD track %i!\n", cdaudio_track);
        }
        else return true;
    }
    if (!Mus_Play(mapname, song_file_name, true))
    {
        // try the CD track anyway if no MIDI could be found (the original game doesn't have any MIDI, it was CD Audio only, this avoids no music playing id mus_redbook is off.)
        FStringf trackname("track%02d.ogg", cdaudio_track);
        if (!Mus_Play(nullptr, trackname, true)) return false;
    }
    return true;
}

void StopSound(void)
{
    // This gets also called on shutdown.
    if (soundEngine) soundEngine->StopAllChannels();
    Mus_Stop();
}

void StopFX()
{
    if (soundEngine) soundEngine->StopAllChannels();
}


END_SW_NS
