//-------------------------------------------------------------------------
/*
Copyright (C) 1996, 2003 - 3D Realms Entertainment
Copyright (C) 2020 - Christoph Oelckers

This file is part of Duke Nukem 3D version 1.5 - Atomic Edition

Duke Nukem 3D is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Original Source: 1996 - Todd Replogle
Prepared for public release: 03/21/2003 - Charlie Wiederhold, 3D Realms
Modifications for JonoF's port by Jonathon Fowler (jf@jonof.id.au)
*/
//------------------------------------------------------------------------- 

// all code related to startup, up to entering the main loop.

#include "ns.h"	// Must come before everything else!

#include "duke3d.h"
#include "m_argv.h"
#include "mapinfo.h"
#include "texturemanager.h"
#include "statusbar.h"
#include "st_start.h"
#include "i_interface.h"
#include "prediction.h"
#include "gamestate.h"
#include "razefont.h"
#include "psky.h"
#include "vm.h"
#include "thingdef.h"

BEGIN_DUKE_NS

void SetDispatcher();
void InitCheats();
int registerosdcommands(void);

//---------------------------------------------------------------------------
//
// DObject stuff - everything GC related.
//
//---------------------------------------------------------------------------

IMPLEMENT_CLASS(DDukeActor, false, true)
IMPLEMENT_POINTERS_START(DDukeActor)
IMPLEMENT_POINTER(ownerActor)
IMPLEMENT_POINTER(hitOwnerActor)
IMPLEMENT_POINTER(temp_actor)
IMPLEMENT_POINTER(seek_actor)
IMPLEMENT_POINTERS_END

size_t DDukeActor::PropagateMark()
{
	for (auto& var : uservars)
	{
		var.Mark();
	}
	return Super::PropagateMark();
}

static void markgcroots()
{
	GC::Mark(camsprite);
	GC::Mark(BellSprite);
	GC::MarkArray(spriteq, countof(spriteq));
	GC::Mark(currentCommentarySprite);
	GC::Mark(ud.cameraactor);
	for (auto& crn : cranes) GC::Mark(crn.poleactor);
	for (auto& pl : ps)
	{
		GC::Mark(pl.actor);
		GC::Mark(pl.actorsqu);
		GC::Mark(pl.wackedbyactor);
		GC::Mark(pl.on_crane);
		GC::Mark(pl.holoduke_on);
		GC::Mark(pl.somethingonplayer);
		GC::Mark(pl.access_spritenum);
		GC::Mark(pl.dummyplayersprite);
		GC::Mark(pl.newOwner);
		for (auto& var : pl.uservars)
		{
			var.Mark();
		}
	}
}

//---------------------------------------------------------------------------
//
// game specific command line args go here. 
//
//---------------------------------------------------------------------------

static void checkcommandline()
{
#if 0
	val = Args->CheckValue("-respawn");
	if (!val) val = Args->CheckValue("-t");
	if (val)
	{
		if (*val == '1') ud.m_respawn_monsters = 1;
		else if (*val == '2') ud.m_respawn_items = 1;
		else if (*val == '3') ud.m_respawn_inventory = 1;
		else
		{
			ud.m_respawn_monsters = 1;
			ud.m_respawn_items = 1;
			ud.m_respawn_inventory = 1;
		}
		Printf("Respawn on.\n");
	}
#endif
}

//---------------------------------------------------------------------------
//
// 
//
//---------------------------------------------------------------------------

static void genspriteremaps(void)
{
	int j;

	auto fr = fileSystem.OpenFileReader("lookup.dat");
	if (!fr.isOpen())
		return;

	j = lookups.loadTable(fr);

	if (j < 0)
	{
		if (j == -1)
			Printf("ERROR loading \"lookup.dat\": failed reading enough data.\n");

		return;
	}

	uint8_t paldata[768];

	for (j = 1; j <= 5; j++)
	{
		if (fr.Read(paldata, 768) != 768)
			return;

		for (int k = 0; k < 768; k++) // Build uses 6 bit VGA palettes.
			paldata[k] = (paldata[k] << 2) | (paldata[k] >> 6);

		paletteSetColorTable(j, paldata, j == DREALMSPAL || j == ENDINGPAL, j > SLIMEPAL);
	}

	for (int i = 0; i < 256; i++)
	{
		// swap red and blue channels.
		paldata[i * 3] = GPalette.BaseColors[i].b;
		paldata[i * 3 + 1] = GPalette.BaseColors[i].g;
		paldata[i * 3 + 2] = GPalette.BaseColors[i].r;
	}
	paletteSetColorTable(DRUGPAL, paldata, false, false); // todo: implement this as a shader effect (swap R and B in postprocessing.)

	if (isRR())
	{
		uint8_t table[256];
		for (j = 0; j < 256; j++)
			table[j] = j;
		for (j = 0; j < 32; j++)
			table[j] = j + 32;

		lookups.makeTable(7, table, 0, 0, 0, 0);

		for (j = 0; j < 256; j++)
			table[j] = j;
		lookups.makeTable(30, table, 0, 0, 0, 0);
		lookups.makeTable(31, table, 0, 0, 0, 0);
		lookups.makeTable(32, table, 0, 0, 0, 0);
		lookups.makeTable(33, table, 0, 0, 0, 0);
		if (isRRRA())
			lookups.makeTable(105, table, 0, 0, 0, 0);

		int unk = 63;
		for (j = 64; j < 80; j++)
		{
			unk--;
			table[j] = unk;
			table[j + 16] = j - 24;
		}
		table[80] = 80;
		table[81] = 81;
		for (j = 0; j < 32; j++)
		{
			table[j] = j + 32;
		}
		lookups.makeTable(34, table, 0, 0, 0, 0);
		for (j = 0; j < 256; j++)
			table[j] = j;
		for (j = 0; j < 16; j++)
			table[j] = j + 129;
		for (j = 16; j < 32; j++)
			table[j] = j + 192;
		lookups.makeTable(35, table, 0, 0, 0, 0);
		if (isRRRA())
		{
			lookups.makeTable(50, nullptr, 12 * 4, 12 * 4, 12 * 4, 0);
			lookups.makeTable(51, nullptr, 12 * 4, 12 * 4, 12 * 4, 0);
			lookups.makeTable(54, lookups.getTable(8), 32 * 4, 32 * 4, 32 * 4, 0);
		}
	}
}

//---------------------------------------------------------------------------
//
// Define sky layouts.
// This one's easy - the other games are a total mess
//
//---------------------------------------------------------------------------

static void setupbackdrop()
{
	static const int16_t moonoff[8] = { 0, 2, 3, 0, 2, 0, 1, 0 };
	static const int16_t orbitoff[8] = { 0, 0, 4, 0, 0, 1, 2, 3 };
	static const int16_t laoff[8] = { 1, 2, 1, 3, 4, 0, 2, 3 };
	static const int16_t defoff[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	static const int16_t defoff1[8] = { 1, 2, 3, 4, 5, 6, 7, 0 };
	static const int16_t defoff4[8] = { 4, 5, 6, 7, 0, 1, 2, 3 };
	static const int16_t defoff7[8] = { 7, 0, 1, 2, 3, 4, 5, 6 };

	defineSky(DEFAULTPSKY, 3, nullptr);
	defineSky(TILE_CLOUDYOCEAN, 3, nullptr);
	defineSky(TILE_MOONSKY1, 3, moonoff);
	defineSky(TILE_BIGORBIT1, 3, orbitoff);
	defineSky(TILE_LA, 3, laoff);
	if (isWorldTour())
	{
		defineSky(5284, 3, defoff);
		defineSky(5412, 3, defoff, 80);
		defineSky(5420, 3, defoff, 80);
		defineSky(5450, 3, defoff7, 80);
		defineSky(5540, 3, defoff, 80);
		defineSky(5548, 3, defoff, 80);
		defineSky(5556, 3, defoff1, 80);
		defineSky(5720, 3, defoff4, 80);
		defineSky(5814, 3, defoff, 80);
	}

	if (isNam())
	{
		defineSky(212, 3, nullptr, 0, 1, 140);
		defineSky(225, 3, nullptr, 0, 1, 140);
	}

	if (isWW2GI() && (g_gameType & GAMEFLAG_ADDON))
	{
		defineSky(1086, 3, nullptr, 0, 1, 140);
	}

	// this sky isn't actually placed wrong - it's just so poorly designed that it needs to be shifted down to hide its shortcomings as good as possible.
	if (isDuke() && (g_gameType & GAMEFLAG_DUKEDC))
	{
		defineSky(3708, 3, nullptr, 0, 1, -40);
	}
}

//---------------------------------------------------------------------------
//
//
//
//---------------------------------------------------------------------------

static void initTiles()
{
	tileDelete(TILE_MIRROR);
	skiptile = TILE_W_FORCEFIELD + 1;

	if (isRR())
		tileDelete(0);

	tileDelete(FOF);
}

#define x(a, b) registerName(#a, b);
#define y(a, b)	// Do not create names for RRTILExxxx.
static void SetTileNames()
{
	auto registerName = [](const char* name, int index)
	{
		TexMan.AddAlias(name, tileGetTexture(index));
		TileFiles.addName(name, index);
	};
	if (!isRR())
	{
#include "namelist_d.h"
	}
	else
	{
#include "namelist_r.h"
	}
}
#undef x
#undef y


void GameInterface::loadPalette()
{
	paletteLoadFromDisk();
	genspriteremaps();
}

int GameInterface::GetCurrentSkill()
{
	return ud.player_skill - 1;
}

//---------------------------------------------------------------------------
//
// set up the game module's state
//
//---------------------------------------------------------------------------

void GameInterface::app_init()
{
	GC::AddMarkerFunc(markgcroots);

	if (isRR()) C_SetNotifyFontScale(0.5);
	ud.god = 0;
	ud.m_respawn_items = 0;
	ud.m_respawn_monsters = 0;
	ud.m_respawn_inventory = 0;
	ud.cashman = 0;
	ud.player_skill = 2;
	ud.wchoice[0][0] = 3;
	ud.wchoice[0][1] = 4;
	ud.wchoice[0][2] = 5;
	ud.wchoice[0][3] = 7;
	ud.wchoice[0][4] = 8;
	ud.wchoice[0][5] = 6;
	ud.wchoice[0][6] = 0;
	ud.wchoice[0][7] = 2;
	ud.wchoice[0][8] = 9;
	ud.wchoice[0][9] = 1;
	ud.multimode = 1;
	ud.m_monsters_off = userConfig.nomonsters;
	ps[0].aim_mode = 1;
	ud.cameraactor = nullptr;

	if (fileSystem.FileExists("DUKESW.BIN"))
		g_gameType |= GAMEFLAG_SHAREWARE;

	numplayers = 1;
	playerswhenstarted = ud.multimode;

	connectpoint2[0] = -1;

	SetDispatcher();
	S_InitSound();


	loadcons();
	fi.initactorflags();
	duke_menufont.Callback(); // depends on the .CON files so it must be after loadcons

	OnEvent(EVENT_INIT);

	//Net_SendClientInfo();

	initTiles();
	setupbackdrop();
	SetupGameButtons();
	InitCheats();
	checkcommandline();
	registerosdcommands();

	screenpeek = myconnectindex;

	SetTileNames();
	C_InitConback(TexMan.CheckForTexture("MENUSCREEN", ETextureType::Any), false, 0.75);

	if (ud.multimode > 1)
	{
		ud.m_monsters_off = 1;
		//ud.player_skill = 0;
	}

	ud.last_level = -1;
	enginecompatibility_mode = ENGINECOMPATIBILITY_19961112;//bVanilla;
	S_ParseDeveloperCommentary();
}


void CallInitialize(DDukeActor* actor)
{
	IFVIRTUALPTR(actor, DDukeActor, initialize)
	{
		VMValue val = actor;
		VMCall(func, &val, 1, nullptr, 0);
	}
}

void CallTick(DDukeActor* actor)
{
	IFVIRTUALPTR(actor, DDukeActor, Tick)
	{
		VMValue val = actor;
		VMCall(func, &val, 1, nullptr, 0);
	}
}

void CallAction(DDukeActor* actor)
{
	IFVIRTUALPTR(actor, DDukeActor, RunState)
	{
		VMValue val = actor;
		VMCall(func, &val, 1, nullptr, 0);
	}
}

END_DUKE_NS
