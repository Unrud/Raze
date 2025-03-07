//-------------------------------------------------------------------------
/*
Copyright (C) 1997, 2005 - 3D Realms Entertainment

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

#include "build.h"

#include "names2.h"
#include "tags.h"
#include "game.h"
#include "ai.h"
#include "misc.h"

BEGIN_SW_NS

#define GORO_PAIN_R0 GORO_STAND_R0
#define GORO_PAIN_R1 GORO_STAND_R1
#define GORO_PAIN_R2 GORO_STAND_R2
#define GORO_PAIN_R3 GORO_STAND_R3
#define GORO_PAIN_R4 GORO_STAND_R4

DECISION GoroBattle[] =
{
    {697,   InitActorMoveCloser         },
    {700,   InitActorAmbientNoise         },
    {1024,  InitActorAttack             }
};

DECISION GoroOffense[] =
{
    {797,   InitActorMoveCloser         },
    {800,   InitActorAttackNoise        },
    {1024,  InitActorAttack             }
};

DECISION GoroBroadcast[] =
{
    {3,    InitActorAmbientNoise          },
    {1024,  InitActorDecide            }
};

DECISION GoroSurprised[] =
{
    {701,   InitActorMoveCloser         },
    {1024,  InitActorDecide            }
};

DECISION GoroEvasive[] =
{
    {10,    InitActorEvade            },
    {1024,  InitActorMoveCloser       }
};

DECISION GoroLostTarget[] =
{
    {900,   InitActorFindPlayer         },
    {1024,  InitActorWanderAround       }
};

DECISION GoroCloseRange[] =
{
    {700,   InitActorAttack             },
    {1024,  InitActorReposition         }
};

PERSONALITY GoroPersonality =
{
    GoroBattle,
    GoroOffense,
    GoroBroadcast,
    GoroSurprised,
    GoroEvasive,
    GoroLostTarget,
    GoroCloseRange,
    GoroCloseRange
};

ATTRIBUTE GoroAttrib =
{
    {160, 180, 200, 230},               // Speeds
    {3, 0, -2, -3},                     // Tic Adjusts
    3,                                 // MaxWeapons;
    {
        DIGI_GRDAMBIENT, DIGI_GRDALERT, 0,
        DIGI_GRDPAIN, DIGI_GRDSCREAM, DIGI_GRDSWINGAXE,
        DIGI_GRDFIREBALL,0,0,0
    }
};


//////////////////////
//
// GORO RUN
//
//////////////////////

#define GORO_RUN_RATE 18

ANIMATOR DoGoroMove,NullGoro,DoActorDebris,InitEnemyFireball;

STATE s_GoroRun[5][4] =
{
    {
        {GORO_RUN_R0 + 0, GORO_RUN_RATE|SF_TIC_ADJUST, DoGoroMove, &s_GoroRun[0][1]},
        {GORO_RUN_R0 + 1, GORO_RUN_RATE|SF_TIC_ADJUST, DoGoroMove, &s_GoroRun[0][2]},
        {GORO_RUN_R0 + 2, GORO_RUN_RATE|SF_TIC_ADJUST, DoGoroMove, &s_GoroRun[0][3]},
        {GORO_RUN_R0 + 3, GORO_RUN_RATE|SF_TIC_ADJUST, DoGoroMove, &s_GoroRun[0][0]},
    },
    {
        {GORO_RUN_R1 + 0, GORO_RUN_RATE|SF_TIC_ADJUST, DoGoroMove, &s_GoroRun[1][1]},
        {GORO_RUN_R1 + 1, GORO_RUN_RATE|SF_TIC_ADJUST, DoGoroMove, &s_GoroRun[1][2]},
        {GORO_RUN_R1 + 2, GORO_RUN_RATE|SF_TIC_ADJUST, DoGoroMove, &s_GoroRun[1][3]},
        {GORO_RUN_R1 + 3, GORO_RUN_RATE|SF_TIC_ADJUST, DoGoroMove, &s_GoroRun[1][0]},
    },
    {
        {GORO_RUN_R2 + 0, GORO_RUN_RATE|SF_TIC_ADJUST, DoGoroMove, &s_GoroRun[2][1]},
        {GORO_RUN_R2 + 1, GORO_RUN_RATE|SF_TIC_ADJUST, DoGoroMove, &s_GoroRun[2][2]},
        {GORO_RUN_R2 + 2, GORO_RUN_RATE|SF_TIC_ADJUST, DoGoroMove, &s_GoroRun[2][3]},
        {GORO_RUN_R2 + 3, GORO_RUN_RATE|SF_TIC_ADJUST, DoGoroMove, &s_GoroRun[2][0]},
    },
    {
        {GORO_RUN_R3 + 0, GORO_RUN_RATE|SF_TIC_ADJUST, DoGoroMove, &s_GoroRun[3][1]},
        {GORO_RUN_R3 + 1, GORO_RUN_RATE|SF_TIC_ADJUST, DoGoroMove, &s_GoroRun[3][2]},
        {GORO_RUN_R3 + 2, GORO_RUN_RATE|SF_TIC_ADJUST, DoGoroMove, &s_GoroRun[3][3]},
        {GORO_RUN_R3 + 3, GORO_RUN_RATE|SF_TIC_ADJUST, DoGoroMove, &s_GoroRun[3][0]},
    },
    {
        {GORO_RUN_R4 + 0, GORO_RUN_RATE|SF_TIC_ADJUST, DoGoroMove, &s_GoroRun[4][1]},
        {GORO_RUN_R4 + 1, GORO_RUN_RATE|SF_TIC_ADJUST, DoGoroMove, &s_GoroRun[4][2]},
        {GORO_RUN_R4 + 2, GORO_RUN_RATE|SF_TIC_ADJUST, DoGoroMove, &s_GoroRun[4][3]},
        {GORO_RUN_R4 + 3, GORO_RUN_RATE|SF_TIC_ADJUST, DoGoroMove, &s_GoroRun[4][0]},
    }
};


STATE* sg_GoroRun[] =
{
    &s_GoroRun[0][0],
    &s_GoroRun[1][0],
    &s_GoroRun[2][0],
    &s_GoroRun[3][0],
    &s_GoroRun[4][0]
};

//////////////////////
//
// GORO CHOP
//
//////////////////////

#define GORO_CHOP_RATE 14
ANIMATOR InitActorDecide;
ANIMATOR InitGoroChop;

STATE s_GoroChop[5][7] =
{
    {
        {GORO_CHOP_R0 + 0, GORO_CHOP_RATE, NullGoro, &s_GoroChop[0][1]},
        {GORO_CHOP_R0 + 1, GORO_CHOP_RATE, NullGoro, &s_GoroChop[0][2]},
        {GORO_CHOP_R0 + 2, GORO_CHOP_RATE, NullGoro, &s_GoroChop[0][3]},
        {GORO_CHOP_R0 + 2, 0|SF_QUICK_CALL, InitGoroChop, &s_GoroChop[0][4]},
        {GORO_CHOP_R0 + 2, GORO_CHOP_RATE, NullGoro, &s_GoroChop[0][5]},
        {GORO_CHOP_R0 + 2, 0|SF_QUICK_CALL, InitActorDecide, &s_GoroChop[0][6]},
        {GORO_CHOP_R0 + 2, GORO_CHOP_RATE, DoGoroMove, &s_GoroChop[0][6]},
    },
    {
        {GORO_CHOP_R1 + 0, GORO_CHOP_RATE, NullGoro, &s_GoroChop[1][1]},
        {GORO_CHOP_R1 + 1, GORO_CHOP_RATE, NullGoro, &s_GoroChop[1][2]},
        {GORO_CHOP_R1 + 2, GORO_CHOP_RATE, NullGoro, &s_GoroChop[1][3]},
        {GORO_CHOP_R1 + 2, 0|SF_QUICK_CALL, InitGoroChop, &s_GoroChop[1][4]},
        {GORO_CHOP_R1 + 2, GORO_CHOP_RATE, NullGoro, &s_GoroChop[1][5]},
        {GORO_CHOP_R1 + 2, 0|SF_QUICK_CALL, InitActorDecide, &s_GoroChop[1][6]},
        {GORO_CHOP_R1 + 2, GORO_CHOP_RATE, DoGoroMove, &s_GoroChop[1][6]},
    },
    {
        {GORO_CHOP_R2 + 0, GORO_CHOP_RATE, NullGoro, &s_GoroChop[2][1]},
        {GORO_CHOP_R2 + 1, GORO_CHOP_RATE, NullGoro, &s_GoroChop[2][2]},
        {GORO_CHOP_R2 + 2, GORO_CHOP_RATE, NullGoro, &s_GoroChop[2][3]},
        {GORO_CHOP_R2 + 2, 0|SF_QUICK_CALL, InitGoroChop, &s_GoroChop[2][4]},
        {GORO_CHOP_R2 + 2, GORO_CHOP_RATE, NullGoro, &s_GoroChop[2][5]},
        {GORO_CHOP_R2 + 2, 0|SF_QUICK_CALL, InitActorDecide, &s_GoroChop[2][6]},
        {GORO_CHOP_R2 + 2, GORO_CHOP_RATE, DoGoroMove, &s_GoroChop[2][6]},
    },
    {
        {GORO_CHOP_R3 + 0, GORO_CHOP_RATE, NullGoro, &s_GoroChop[3][1]},
        {GORO_CHOP_R3 + 1, GORO_CHOP_RATE, NullGoro, &s_GoroChop[3][2]},
        {GORO_CHOP_R3 + 2, GORO_CHOP_RATE, NullGoro, &s_GoroChop[3][3]},
        {GORO_CHOP_R3 + 2, 0|SF_QUICK_CALL, InitGoroChop, &s_GoroChop[3][4]},
        {GORO_CHOP_R3 + 2, GORO_CHOP_RATE, NullGoro, &s_GoroChop[3][5]},
        {GORO_CHOP_R3 + 2, 0|SF_QUICK_CALL, InitActorDecide, &s_GoroChop[3][6]},
        {GORO_CHOP_R3 + 2, GORO_CHOP_RATE, DoGoroMove, &s_GoroChop[3][6]},
    },
    {
        {GORO_CHOP_R4 + 0, GORO_CHOP_RATE, NullGoro, &s_GoroChop[4][1]},
        {GORO_CHOP_R4 + 1, GORO_CHOP_RATE, NullGoro, &s_GoroChop[4][2]},
        {GORO_CHOP_R4 + 2, GORO_CHOP_RATE, NullGoro, &s_GoroChop[4][3]},
        {GORO_CHOP_R4 + 2, 0|SF_QUICK_CALL, InitGoroChop, &s_GoroChop[4][4]},
        {GORO_CHOP_R4 + 2, GORO_CHOP_RATE, NullGoro, &s_GoroChop[4][5]},
        {GORO_CHOP_R4 + 2, 0|SF_QUICK_CALL, InitActorDecide, &s_GoroChop[4][6]},
        {GORO_CHOP_R4 + 2, GORO_CHOP_RATE, DoGoroMove, &s_GoroChop[4][6]},
    }
};


STATE* sg_GoroChop[] =
{
    &s_GoroChop[0][0],
    &s_GoroChop[1][0],
    &s_GoroChop[2][0],
    &s_GoroChop[3][0],
    &s_GoroChop[4][0]
};


//////////////////////
//
// GORO SPELL
//
//////////////////////

#define GORO_SPELL_RATE 6
#define GORO_SPELL_PAUSE 30

STATE s_GoroSpell[5][10] =
{
    {
        {GORO_SPELL_R0 + 0, GORO_SPELL_PAUSE, NullGoro,      &s_GoroSpell[0][1]},
        {GORO_SPELL_R0 + 1, GORO_SPELL_PAUSE, NullGoro,      &s_GoroSpell[0][2]},
        {GORO_SPELL_R0 + 1, GORO_SPELL_RATE, InitEnemyFireball, &s_GoroSpell[0][3]},
        {GORO_SPELL_R0 + 1, GORO_SPELL_RATE, NullGoro,      &s_GoroSpell[0][4]},
        {GORO_SPELL_R0 + 1, GORO_SPELL_RATE, InitEnemyFireball, &s_GoroSpell[0][5]},
        {GORO_SPELL_R0 + 1, GORO_SPELL_RATE, NullGoro,      &s_GoroSpell[0][6]},
        {GORO_SPELL_R0 + 1, GORO_SPELL_RATE, InitEnemyFireball, &s_GoroSpell[0][7]},
        {GORO_SPELL_R0 + 1, GORO_SPELL_PAUSE, NullGoro,      &s_GoroSpell[0][8]},
        {GORO_SPELL_R0 + 1, 0|SF_QUICK_CALL, InitActorDecide,   &s_GoroSpell[0][9]},
        {GORO_SPELL_R0 + 1, GORO_SPELL_RATE, DoGoroMove,        &s_GoroSpell[0][9]},
    },
    {
        {GORO_SPELL_R1 + 0, GORO_SPELL_PAUSE, NullGoro,      &s_GoroSpell[1][1]},
        {GORO_SPELL_R1 + 1, GORO_SPELL_PAUSE, NullGoro,      &s_GoroSpell[1][2]},
        {GORO_SPELL_R1 + 1, GORO_SPELL_RATE, InitEnemyFireball, &s_GoroSpell[1][3]},
        {GORO_SPELL_R1 + 1, GORO_SPELL_RATE, NullGoro,      &s_GoroSpell[1][4]},
        {GORO_SPELL_R1 + 1, GORO_SPELL_RATE, InitEnemyFireball, &s_GoroSpell[1][5]},
        {GORO_SPELL_R1 + 1, GORO_SPELL_RATE, NullGoro,      &s_GoroSpell[1][6]},
        {GORO_SPELL_R1 + 1, GORO_SPELL_RATE, InitEnemyFireball, &s_GoroSpell[1][7]},
        {GORO_SPELL_R1 + 1, GORO_SPELL_PAUSE, NullGoro,      &s_GoroSpell[1][8]},
        {GORO_SPELL_R1 + 1, 0|SF_QUICK_CALL, InitActorDecide,   &s_GoroSpell[1][9]},
        {GORO_SPELL_R1 + 1, GORO_SPELL_RATE, DoGoroMove,        &s_GoroSpell[1][9]},
    },
    {
        {GORO_SPELL_R2 + 0, GORO_SPELL_PAUSE, NullGoro,      &s_GoroSpell[2][1]},
        {GORO_SPELL_R2 + 1, GORO_SPELL_PAUSE, NullGoro,      &s_GoroSpell[2][2]},
        {GORO_SPELL_R2 + 1, GORO_SPELL_RATE, InitEnemyFireball, &s_GoroSpell[2][3]},
        {GORO_SPELL_R2 + 1, GORO_SPELL_RATE, NullGoro,      &s_GoroSpell[2][4]},
        {GORO_SPELL_R2 + 1, GORO_SPELL_RATE, InitEnemyFireball, &s_GoroSpell[2][5]},
        {GORO_SPELL_R2 + 1, GORO_SPELL_RATE, NullGoro,      &s_GoroSpell[2][6]},
        {GORO_SPELL_R2 + 1, GORO_SPELL_RATE, InitEnemyFireball, &s_GoroSpell[2][7]},
        {GORO_SPELL_R2 + 1, GORO_SPELL_PAUSE, NullGoro,      &s_GoroSpell[2][8]},
        {GORO_SPELL_R2 + 1, 0|SF_QUICK_CALL, InitActorDecide,   &s_GoroSpell[2][9]},
        {GORO_SPELL_R2 + 1, GORO_SPELL_RATE, DoGoroMove,        &s_GoroSpell[2][9]},
    },
    {
        {GORO_SPELL_R3 + 0, GORO_SPELL_PAUSE, NullGoro,      &s_GoroSpell[3][1]},
        {GORO_SPELL_R3 + 1, GORO_SPELL_PAUSE, NullGoro,      &s_GoroSpell[3][2]},
        {GORO_SPELL_R3 + 1, GORO_SPELL_RATE, InitEnemyFireball, &s_GoroSpell[3][3]},
        {GORO_SPELL_R3 + 1, GORO_SPELL_RATE, NullGoro,      &s_GoroSpell[3][4]},
        {GORO_SPELL_R3 + 1, GORO_SPELL_RATE, InitEnemyFireball, &s_GoroSpell[3][5]},
        {GORO_SPELL_R3 + 1, GORO_SPELL_RATE, NullGoro,      &s_GoroSpell[3][6]},
        {GORO_SPELL_R3 + 1, GORO_SPELL_RATE, InitEnemyFireball, &s_GoroSpell[3][7]},
        {GORO_SPELL_R3 + 1, GORO_SPELL_PAUSE, NullGoro,      &s_GoroSpell[3][8]},
        {GORO_SPELL_R3 + 1, 0|SF_QUICK_CALL, InitActorDecide,   &s_GoroSpell[3][9]},
        {GORO_SPELL_R3 + 1, GORO_SPELL_RATE, DoGoroMove,        &s_GoroSpell[3][9]},
    },
    {
        {GORO_SPELL_R4 + 0, GORO_SPELL_PAUSE, NullGoro,      &s_GoroSpell[4][1]},
        {GORO_SPELL_R4 + 1, GORO_SPELL_PAUSE, NullGoro,      &s_GoroSpell[4][2]},
        {GORO_SPELL_R4 + 1, GORO_SPELL_RATE, InitEnemyFireball, &s_GoroSpell[4][3]},
        {GORO_SPELL_R4 + 1, GORO_SPELL_RATE, NullGoro,      &s_GoroSpell[4][4]},
        {GORO_SPELL_R4 + 1, GORO_SPELL_RATE, InitEnemyFireball, &s_GoroSpell[4][5]},
        {GORO_SPELL_R4 + 1, GORO_SPELL_RATE, NullGoro,      &s_GoroSpell[4][6]},
        {GORO_SPELL_R4 + 1, GORO_SPELL_RATE, InitEnemyFireball, &s_GoroSpell[4][7]},
        {GORO_SPELL_R4 + 1, GORO_SPELL_PAUSE, NullGoro,      &s_GoroSpell[4][8]},
        {GORO_SPELL_R4 + 1, 0|SF_QUICK_CALL, InitActorDecide,   &s_GoroSpell[4][9]},
        {GORO_SPELL_R4 + 1, GORO_SPELL_RATE, DoGoroMove,        &s_GoroSpell[4][9]},
    }
};


STATE* sg_GoroSpell[] =
{
    &s_GoroSpell[0][0],
    &s_GoroSpell[1][0],
    &s_GoroSpell[2][0],
    &s_GoroSpell[3][0],
    &s_GoroSpell[4][0]
};

//////////////////////
//
// GORO STAND
//
//////////////////////

#define GORO_STAND_RATE 12

STATE s_GoroStand[5][1] =
{
    {
        {GORO_STAND_R0 + 0, GORO_STAND_RATE, DoGoroMove, &s_GoroStand[0][0]},
    },
    {
        {GORO_STAND_R1 + 0, GORO_STAND_RATE, DoGoroMove, &s_GoroStand[1][0]},
    },
    {
        {GORO_STAND_R2 + 0, GORO_STAND_RATE, DoGoroMove, &s_GoroStand[2][0]},
    },
    {
        {GORO_STAND_R3 + 0, GORO_STAND_RATE, DoGoroMove, &s_GoroStand[3][0]},
    },
    {
        {GORO_STAND_R4 + 0, GORO_STAND_RATE, DoGoroMove, &s_GoroStand[4][0]},
    },
};


STATE* sg_GoroStand[] =
{
    s_GoroStand[0],
    s_GoroStand[1],
    s_GoroStand[2],
    s_GoroStand[3],
    s_GoroStand[4]
};

//////////////////////
//
// GORO PAIN
//
//////////////////////

#define GORO_PAIN_RATE 12
ANIMATOR DoGoroPain;

STATE s_GoroPain[5][1] =
{
    {
        {GORO_PAIN_R0 + 0, GORO_PAIN_RATE, DoGoroPain, &s_GoroPain[0][0]},
    },
    {
        {GORO_PAIN_R1 + 0, GORO_PAIN_RATE, DoGoroPain, &s_GoroPain[1][0]},
    },
    {
        {GORO_PAIN_R2 + 0, GORO_PAIN_RATE, DoGoroPain, &s_GoroPain[2][0]},
    },
    {
        {GORO_PAIN_R3 + 0, GORO_PAIN_RATE, DoGoroPain, &s_GoroPain[3][0]},
    },
    {
        {GORO_PAIN_R4 + 0, GORO_PAIN_RATE, DoGoroPain, &s_GoroPain[4][0]},
    },
};


STATE* sg_GoroPain[] =
{
    s_GoroPain[0],
    s_GoroPain[1],
    s_GoroPain[2],
    s_GoroPain[3],
    s_GoroPain[4]
};

//////////////////////
//
// GORO DIE
//
//////////////////////

#define GORO_DIE_RATE 16

STATE s_GoroDie[] =
{
    {GORO_DIE + 0, GORO_DIE_RATE, NullGoro, &s_GoroDie[1]},
    {GORO_DIE + 1, GORO_DIE_RATE, NullGoro, &s_GoroDie[2]},
    {GORO_DIE + 2, GORO_DIE_RATE, NullGoro, &s_GoroDie[3]},
    {GORO_DIE + 3, GORO_DIE_RATE, NullGoro, &s_GoroDie[4]},
    {GORO_DIE + 4, GORO_DIE_RATE, NullGoro, &s_GoroDie[5]},
    {GORO_DIE + 5, GORO_DIE_RATE, NullGoro, &s_GoroDie[6]},
    {GORO_DIE + 6, GORO_DIE_RATE, NullGoro, &s_GoroDie[7]},
    {GORO_DIE + 7, GORO_DIE_RATE, NullGoro, &s_GoroDie[8]},
    {GORO_DIE + 8, GORO_DIE_RATE, NullGoro, &s_GoroDie[9]},
    {GORO_DEAD, SF_QUICK_CALL, QueueFloorBlood, &s_GoroDie[10]},
    {GORO_DEAD,    GORO_DIE_RATE, DoActorDebris, &s_GoroDie[10]},
};

STATE s_GoroDead[] =
{
    {GORO_DEAD, GORO_DIE_RATE, DoActorDebris, &s_GoroDead[0]},
};

STATE* sg_GoroDie[] =
{
    s_GoroDie
};

STATE* sg_GoroDead[] =
{
    s_GoroDead
};

/*
STATE* *Stand[MAX_WEAPONS];
STATE* *Run;
STATE* *Jump;
STATE* *Fall;
STATE* *Crawl;
STATE* *Swim;
STATE* *Fly;
STATE* *Rise;
STATE* *Sit;
STATE* *Look;
STATE* *Climb;
STATE* *Pain;
STATE* *Death1;
STATE* *Death2;
STATE* *Dead;
STATE* *DeathJump;
STATE* *DeathFall;
STATE* *CloseAttack[2];
STATE* *Attack[6];
STATE* *Special[2];
*/

ACTOR_ACTION_SET GoroActionSet =
{
    sg_GoroStand,
    sg_GoroRun,
    nullptr, //sg_GoroJump,
    nullptr, //sg_GoroFall,
    nullptr, //sg_GoroCrawl,
    nullptr, //sg_GoroSwim,
    nullptr, //sg_GoroFly,
    nullptr, //sg_GoroRise,
    nullptr, //sg_GoroSit,
    nullptr, //sg_GoroLook,
    nullptr, //climb
    sg_GoroPain,
    sg_GoroDie,
    nullptr, //sg_GoroHariKari,
    sg_GoroDead,
    nullptr, //sg_GoroDeathJump,
    nullptr, //sg_GoroDeathFall,
    {sg_GoroChop},
    {1024},
    {sg_GoroSpell},
    {1024},
    {nullptr,nullptr},
    nullptr,
    nullptr
};

int SetupGoro(DSWActor* actor)
{
    ANIMATOR DoActorDecide;

    if (!(actor->spr.cstat & CSTAT_SPRITE_RESTORE))
    {
        SpawnUser(actor, GORO_RUN_R0,s_GoroRun[0]);
        actor->user.Health = HEALTH_GORO;
    }

    ChangeState(actor, s_GoroRun[0]);
    actor->user.Attrib = &GoroAttrib;
    DoActorSetSpeed(actor, NORM_SPEED);
    actor->user.StateEnd = s_GoroDie;
    actor->user.Rot = sg_GoroRun;


    EnemyDefaults(actor, &GoroActionSet, &GoroPersonality);
    actor->spr.clipdist = 512 >> 2;
    actor->user.Flags |= (SPR_XFLIP_TOGGLE);

    return 0;
}

int NullGoro(DSWActor* actor)
{
    if (actor->user.Flags & (SPR_SLIDING))
        DoActorSlide(actor);

    KeepActorOnFloor(actor);

    DoActorSectorDamage(actor);
    return 0;
}

int DoGoroPain(DSWActor* actor)
{
    NullGoro(actor);

    if ((actor->user.WaitTics -= ACTORMOVETICS) <= 0)
        InitActorDecide(actor);
    return 0;
}

int DoGoroMove(DSWActor* actor)
{
    if (actor->user.Flags & (SPR_SLIDING))
        DoActorSlide(actor);

    if (actor->user.track >= 0)
        ActorFollowTrack(actor, ACTORMOVETICS);
    else
        (*actor->user.ActorActionFunc)(actor);

    KeepActorOnFloor(actor);

    DoActorSectorDamage(actor);
    return 0;
}


#include "saveable.h"

static saveable_code saveable_goro_code[] =
{
    SAVE_CODE(NullGoro),
    SAVE_CODE(DoGoroPain),
    SAVE_CODE(DoGoroMove),
};

static saveable_data saveable_goro_data[] =
{
    SAVE_DATA(GoroBattle),
    SAVE_DATA(GoroOffense),
    SAVE_DATA(GoroBroadcast),
    SAVE_DATA(GoroSurprised),
    SAVE_DATA(GoroEvasive),
    SAVE_DATA(GoroLostTarget),
    SAVE_DATA(GoroCloseRange),

    SAVE_DATA(GoroPersonality),

    SAVE_DATA(GoroAttrib),

    SAVE_DATA(s_GoroRun),
    SAVE_DATA(sg_GoroRun),
    SAVE_DATA(s_GoroChop),
    SAVE_DATA(sg_GoroChop),
    SAVE_DATA(s_GoroSpell),
    SAVE_DATA(sg_GoroSpell),
    SAVE_DATA(s_GoroStand),
    SAVE_DATA(sg_GoroStand),
    SAVE_DATA(s_GoroPain),
    SAVE_DATA(sg_GoroPain),
    SAVE_DATA(s_GoroDie),
    SAVE_DATA(s_GoroDead),
    SAVE_DATA(sg_GoroDie),
    SAVE_DATA(sg_GoroDead),

    SAVE_DATA(GoroActionSet),
};

saveable_module saveable_goro =
{
    // code
    saveable_goro_code,
    SIZ(saveable_goro_code),

    // data
    saveable_goro_data,
    SIZ(saveable_goro_data)
};
END_SW_NS
