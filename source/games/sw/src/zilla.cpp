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
#include "panel.h"
#include "game.h"
#include "tags.h"
#include "ai.h"
#include "misc.h"
#include "gamecontrol.h"
#include "mapinfo.h"

BEGIN_SW_NS

ANIMATOR InitZillaCharge;

DECISION ZillaBattle[] =
{
    {100,   InitActorRunAway      },
    {690,   InitActorMoveCloser   },
    {692,   InitActorAlertNoise   },
    {1024,  InitActorAttack       }
};

DECISION ZillaOffense[] =
{
    {100,   InitActorRunAway      },
    {690,   InitActorMoveCloser   },
    {692,   InitActorAlertNoise   },
    {1024,  InitActorAttack       }
};

DECISION ZillaBroadcast[] =
{
    {2,     InitActorAlertNoise   },
    {4,     InitActorAmbientNoise  },
    {1024,  InitActorDecide       }
};

DECISION ZillaSurprised[] =
{
    {700,   InitActorMoveCloser   },
    {703,   InitActorAlertNoise   },
    {1024,  InitActorDecide       }
};

DECISION ZillaEvasive[] =
{
    {1024, InitActorWanderAround }
};

DECISION ZillaLostTarget[] =
{
    {900,   InitActorFindPlayer         },
    {1024,  InitActorWanderAround       }
};

DECISION ZillaCloseRange[] =
{
    {1024,  InitActorAttack         }
};

PERSONALITY ZillaPersonality =
{
    ZillaBattle,
    ZillaOffense,
    ZillaBroadcast,
    ZillaSurprised,
    ZillaEvasive,
    ZillaLostTarget,
    ZillaCloseRange,
    ZillaCloseRange
};

ATTRIBUTE ZillaAttrib =
{
    {100, 100, 100, 100},                 // Speeds
    {3, 0, 0, 0},                     // Tic Adjusts
    3,                               // MaxWeapons;
    {
        DIGI_Z17010, DIGI_Z17010, DIGI_Z17025,
        DIGI_Z17052, DIGI_Z17025, 0,0,0,0,0
    }
};


//////////////////////
//
// ZILLA RUN
//
//////////////////////

#define ZILLA_RATE 48

ANIMATOR DoZillaMove,NullZilla,DoStayOnFloor,
         DoActorDebris, SpawnZillaExp, DoZillaStomp,
         SpawnCoolg;

STATE s_ZillaRun[5][6] =
{
    {
        {ZILLA_RUN_R0 + 0, ZILLA_RATE, DoZillaMove, &s_ZillaRun[0][1]},
        {ZILLA_RUN_R0 + 1, SF_QUICK_CALL, DoZillaStomp, &s_ZillaRun[0][2]},
        {ZILLA_RUN_R0 + 1, ZILLA_RATE, DoZillaMove, &s_ZillaRun[0][3]},
        {ZILLA_RUN_R0 + 2, ZILLA_RATE, DoZillaMove, &s_ZillaRun[0][4]},
        {ZILLA_RUN_R0 + 3, SF_QUICK_CALL, DoZillaStomp, &s_ZillaRun[0][5]},
        {ZILLA_RUN_R0 + 3, ZILLA_RATE, DoZillaMove, &s_ZillaRun[0][0]}
    },
    {
        {ZILLA_RUN_R1 + 0, ZILLA_RATE, DoZillaMove, &s_ZillaRun[1][1]},
        {ZILLA_RUN_R1 + 1, SF_QUICK_CALL, DoZillaStomp, &s_ZillaRun[1][2]},
        {ZILLA_RUN_R1 + 1, ZILLA_RATE, DoZillaMove, &s_ZillaRun[1][3]},
        {ZILLA_RUN_R1 + 2, ZILLA_RATE, DoZillaMove, &s_ZillaRun[1][4]},
        {ZILLA_RUN_R1 + 3, SF_QUICK_CALL, DoZillaStomp, &s_ZillaRun[1][5]},
        {ZILLA_RUN_R1 + 3, ZILLA_RATE, DoZillaMove, &s_ZillaRun[1][0]}
    },
    {
        {ZILLA_RUN_R2 + 0, ZILLA_RATE, DoZillaMove, &s_ZillaRun[2][1]},
        {ZILLA_RUN_R2 + 1, SF_QUICK_CALL, DoZillaStomp, &s_ZillaRun[2][2]},
        {ZILLA_RUN_R2 + 1, ZILLA_RATE, DoZillaMove, &s_ZillaRun[2][3]},
        {ZILLA_RUN_R2 + 2, ZILLA_RATE, DoZillaMove, &s_ZillaRun[2][4]},
        {ZILLA_RUN_R2 + 3, SF_QUICK_CALL, DoZillaStomp, &s_ZillaRun[2][5]},
        {ZILLA_RUN_R2 + 3, ZILLA_RATE, DoZillaMove, &s_ZillaRun[2][0]}
    },
    {
        {ZILLA_RUN_R3 + 0, ZILLA_RATE, DoZillaMove, &s_ZillaRun[3][1]},
        {ZILLA_RUN_R3 + 1, SF_QUICK_CALL, DoZillaStomp, &s_ZillaRun[3][2]},
        {ZILLA_RUN_R3 + 1, ZILLA_RATE, DoZillaMove, &s_ZillaRun[3][3]},
        {ZILLA_RUN_R3 + 2, ZILLA_RATE, DoZillaMove, &s_ZillaRun[3][4]},
        {ZILLA_RUN_R3 + 3, SF_QUICK_CALL, DoZillaStomp, &s_ZillaRun[3][5]},
        {ZILLA_RUN_R3 + 3, ZILLA_RATE, DoZillaMove, &s_ZillaRun[3][0]}
    },
    {
        {ZILLA_RUN_R4 + 0, ZILLA_RATE, DoZillaMove, &s_ZillaRun[4][1]},
        {ZILLA_RUN_R4 + 1, SF_QUICK_CALL, DoZillaStomp, &s_ZillaRun[4][2]},
        {ZILLA_RUN_R4 + 1, ZILLA_RATE, DoZillaMove, &s_ZillaRun[4][3]},
        {ZILLA_RUN_R4 + 2, ZILLA_RATE, DoZillaMove, &s_ZillaRun[4][4]},
        {ZILLA_RUN_R4 + 3, SF_QUICK_CALL, DoZillaStomp, &s_ZillaRun[4][5]},
        {ZILLA_RUN_R4 + 3, ZILLA_RATE, DoZillaMove, &s_ZillaRun[4][0]}
    }
};

STATE* sg_ZillaRun[] =
{
    &s_ZillaRun[0][0],
    &s_ZillaRun[1][0],
    &s_ZillaRun[2][0],
    &s_ZillaRun[3][0],
    &s_ZillaRun[4][0]
};


//////////////////////
//
// ZILLA STAND
//
//////////////////////

STATE s_ZillaStand[5][1] =
{
    {
        {ZILLA_RUN_R0 + 0, ZILLA_RATE, DoZillaMove, &s_ZillaStand[0][0]}
    },
    {
        {ZILLA_RUN_R1 + 0, ZILLA_RATE, DoZillaMove, &s_ZillaStand[1][0]}
    },
    {
        {ZILLA_RUN_R2 + 0, ZILLA_RATE, DoZillaMove, &s_ZillaStand[2][0]}
    },
    {
        {ZILLA_RUN_R3 + 0, ZILLA_RATE, DoZillaMove, &s_ZillaStand[3][0]}
    },
    {
        {ZILLA_RUN_R4 + 0, ZILLA_RATE, DoZillaMove, &s_ZillaStand[4][0]}
    }
};

STATE* sg_ZillaStand[] =
{
    &s_ZillaStand[0][0],
    &s_ZillaStand[1][0],
    &s_ZillaStand[2][0],
    &s_ZillaStand[3][0],
    &s_ZillaStand[4][0]
};

//////////////////////
//
// ZILLA PAIN
//
//////////////////////

#define ZILLA_PAIN_RATE 30

STATE s_ZillaPain[5][2] =
{
    {
        {ZILLA_PAIN_R0 + 0, ZILLA_PAIN_RATE, NullZilla, &s_ZillaPain[0][1]},
        {ZILLA_PAIN_R0 + 0, 0|SF_QUICK_CALL, InitActorDecide, &s_ZillaPain[0][0]}
    },
    {
        {ZILLA_PAIN_R1 + 0, ZILLA_PAIN_RATE, NullZilla, &s_ZillaPain[1][1]},
        {ZILLA_PAIN_R1 + 0, 0|SF_QUICK_CALL, InitActorDecide, &s_ZillaPain[1][0]}
    },
    {
        {ZILLA_PAIN_R2 + 0, ZILLA_PAIN_RATE, NullZilla, &s_ZillaPain[2][1]},
        {ZILLA_PAIN_R2 + 0, 0|SF_QUICK_CALL, InitActorDecide, &s_ZillaPain[2][0]}
    },
    {
        {ZILLA_PAIN_R3 + 0, ZILLA_PAIN_RATE, NullZilla, &s_ZillaPain[3][1]},
        {ZILLA_PAIN_R3 + 0, 0|SF_QUICK_CALL, InitActorDecide, &s_ZillaPain[3][0]}
    },
    {
        {ZILLA_PAIN_R4 + 0, ZILLA_PAIN_RATE, NullZilla, &s_ZillaPain[4][1]},
        {ZILLA_PAIN_R4 + 0, 0|SF_QUICK_CALL, InitActorDecide, &s_ZillaPain[4][0]}
    }
};

STATE* sg_ZillaPain[] =
{
    &s_ZillaPain[0][0],
    &s_ZillaPain[1][0],
    &s_ZillaPain[2][0],
    &s_ZillaPain[3][0],
    &s_ZillaPain[4][0]
};

//////////////////////
//
// ZILLA RAIL
//
//////////////////////

#define ZILLA_RAIL_RATE 12
ANIMATOR InitZillaRail;

STATE s_ZillaRail[5][14] =
{
    {
        {ZILLA_RAIL_R0 + 0, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[0][1]},
        {ZILLA_RAIL_R0 + 1, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[0][2]},
        {ZILLA_RAIL_R0 + 2, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[0][3]},
        {ZILLA_RAIL_R0 + 3, SF_QUICK_CALL, InitZillaRail, &s_ZillaRail[0][4]},
        {ZILLA_RAIL_R0 + 0, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[0][5]},
        {ZILLA_RAIL_R0 + 1, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[0][6]},
        {ZILLA_RAIL_R0 + 2, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[0][7]},
        {ZILLA_RAIL_R0 + 3, SF_QUICK_CALL, InitZillaRail, &s_ZillaRail[0][8]},
        {ZILLA_RAIL_R0 + 0, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[0][9]},
        {ZILLA_RAIL_R0 + 1, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[0][10]},
        {ZILLA_RAIL_R0 + 2, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[0][11]},
        {ZILLA_RAIL_R0 + 3, SF_QUICK_CALL, InitZillaRail, &s_ZillaRail[0][12]},
        {ZILLA_RAIL_R0 + 3, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[0][13]},
        {ZILLA_RAIL_R0 + 3, SF_QUICK_CALL, InitActorDecide, &s_ZillaRail[0][0]}
    },
    {
        {ZILLA_RAIL_R1 + 0, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[1][1]},
        {ZILLA_RAIL_R1 + 1, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[1][2]},
        {ZILLA_RAIL_R1 + 2, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[1][3]},
        {ZILLA_RAIL_R1 + 3, SF_QUICK_CALL, InitZillaRail, &s_ZillaRail[1][4]},
        {ZILLA_RAIL_R1 + 0, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[1][5]},
        {ZILLA_RAIL_R1 + 1, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[1][6]},
        {ZILLA_RAIL_R1 + 2, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[1][7]},
        {ZILLA_RAIL_R1 + 3, SF_QUICK_CALL, InitZillaRail, &s_ZillaRail[1][8]},
        {ZILLA_RAIL_R1 + 0, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[1][9]},
        {ZILLA_RAIL_R1 + 1, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[1][10]},
        {ZILLA_RAIL_R1 + 2, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[1][11]},
        {ZILLA_RAIL_R1 + 3, SF_QUICK_CALL, InitZillaRail, &s_ZillaRail[1][12]},
        {ZILLA_RAIL_R1 + 3, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[1][13]},
        {ZILLA_RAIL_R1 + 3, SF_QUICK_CALL, InitActorDecide, &s_ZillaRail[1][0]}
    },
    {
        {ZILLA_RAIL_R2 + 0, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[2][1]},
        {ZILLA_RAIL_R2 + 1, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[2][2]},
        {ZILLA_RAIL_R2 + 2, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[2][3]},
        {ZILLA_RAIL_R2 + 3, SF_QUICK_CALL, InitZillaRail, &s_ZillaRail[2][4]},
        {ZILLA_RAIL_R2 + 0, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[2][5]},
        {ZILLA_RAIL_R2 + 1, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[2][6]},
        {ZILLA_RAIL_R2 + 2, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[2][7]},
        {ZILLA_RAIL_R2 + 3, SF_QUICK_CALL, InitZillaRail, &s_ZillaRail[2][8]},
        {ZILLA_RAIL_R2 + 0, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[2][9]},
        {ZILLA_RAIL_R2 + 1, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[2][10]},
        {ZILLA_RAIL_R2 + 2, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[2][11]},
        {ZILLA_RAIL_R2 + 3, SF_QUICK_CALL, InitZillaRail, &s_ZillaRail[2][12]},
        {ZILLA_RAIL_R2 + 3, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[2][13]},
        {ZILLA_RAIL_R2 + 3, SF_QUICK_CALL, InitActorDecide, &s_ZillaRail[2][0]}
    },
    {
        {ZILLA_RAIL_R3 + 0, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[3][1]},
        {ZILLA_RAIL_R3 + 1, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[3][2]},
        {ZILLA_RAIL_R3 + 2, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[3][3]},
        {ZILLA_RAIL_R3 + 3, SF_QUICK_CALL, InitZillaRail, &s_ZillaRail[3][4]},
        {ZILLA_RAIL_R3 + 0, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[3][5]},
        {ZILLA_RAIL_R3 + 1, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[3][6]},
        {ZILLA_RAIL_R3 + 2, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[3][7]},
        {ZILLA_RAIL_R3 + 3, SF_QUICK_CALL, InitZillaRail, &s_ZillaRail[3][8]},
        {ZILLA_RAIL_R3 + 0, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[3][9]},
        {ZILLA_RAIL_R3 + 1, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[3][10]},
        {ZILLA_RAIL_R3 + 2, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[3][11]},
        {ZILLA_RAIL_R3 + 3, SF_QUICK_CALL, InitZillaRail, &s_ZillaRail[3][12]},
        {ZILLA_RAIL_R3 + 3, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[3][13]},
        {ZILLA_RAIL_R3 + 3, SF_QUICK_CALL, InitActorDecide, &s_ZillaRail[3][0]}
    },
    {
        {ZILLA_RAIL_R4 + 0, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[4][1]},
        {ZILLA_RAIL_R4 + 1, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[4][2]},
        {ZILLA_RAIL_R4 + 2, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[4][3]},
        {ZILLA_RAIL_R4 + 3, SF_QUICK_CALL, InitZillaRail, &s_ZillaRail[4][4]},
        {ZILLA_RAIL_R4 + 0, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[4][5]},
        {ZILLA_RAIL_R4 + 1, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[4][6]},
        {ZILLA_RAIL_R4 + 2, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[4][7]},
        {ZILLA_RAIL_R4 + 3, SF_QUICK_CALL, InitZillaRail, &s_ZillaRail[4][8]},
        {ZILLA_RAIL_R4 + 0, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[4][9]},
        {ZILLA_RAIL_R4 + 1, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[4][10]},
        {ZILLA_RAIL_R4 + 2, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[4][11]},
        {ZILLA_RAIL_R4 + 3, SF_QUICK_CALL, InitZillaRail, &s_ZillaRail[4][12]},
        {ZILLA_RAIL_R4 + 3, ZILLA_RAIL_RATE, NullZilla, &s_ZillaRail[4][13]},
        {ZILLA_RAIL_R4 + 3, SF_QUICK_CALL, InitActorDecide, &s_ZillaRail[4][0]}
    }
};

STATE* sg_ZillaRail[] =
{
    &s_ZillaRail[0][0],
    &s_ZillaRail[1][0],
    &s_ZillaRail[2][0],
    &s_ZillaRail[3][0],
    &s_ZillaRail[4][0]
};

//////////////////////
//
// ZILLA ROCKET
//
//////////////////////

#define ZILLA_ROCKET_RATE 12
ANIMATOR InitZillaRocket;

STATE s_ZillaRocket[5][7] =
{
    {
        {ZILLA_ROCKET_R0 + 0, ZILLA_ROCKET_RATE, NullZilla, &s_ZillaRocket[0][1]},
        {ZILLA_ROCKET_R0 + 1, ZILLA_ROCKET_RATE, NullZilla, &s_ZillaRocket[0][2]},
        {ZILLA_ROCKET_R0 + 2, ZILLA_ROCKET_RATE*4, NullZilla, &s_ZillaRocket[0][3]},
        {ZILLA_ROCKET_R0 + 2, SF_QUICK_CALL, InitZillaRocket, &s_ZillaRocket[0][4]},
        {ZILLA_ROCKET_R0 + 2, ZILLA_ROCKET_RATE*4, NullZilla, &s_ZillaRocket[0][5]},
        {ZILLA_ROCKET_R0 + 3, SF_QUICK_CALL, InitActorDecide, &s_ZillaRocket[0][6]},
        {ZILLA_ROCKET_R0 + 3, ZILLA_ROCKET_RATE*10, NullZilla, &s_ZillaRocket[0][5]}
    },
    {
        {ZILLA_ROCKET_R1 + 0, ZILLA_ROCKET_RATE, NullZilla, &s_ZillaRocket[1][1]},
        {ZILLA_ROCKET_R1 + 1, ZILLA_ROCKET_RATE, NullZilla, &s_ZillaRocket[1][2]},
        {ZILLA_ROCKET_R1 + 2, ZILLA_ROCKET_RATE*4, NullZilla, &s_ZillaRocket[1][3]},
        {ZILLA_ROCKET_R1 + 2, SF_QUICK_CALL, InitZillaRocket, &s_ZillaRocket[1][4]},
        {ZILLA_ROCKET_R1 + 2, ZILLA_ROCKET_RATE*4, NullZilla, &s_ZillaRocket[1][5]},
        {ZILLA_ROCKET_R1 + 3, SF_QUICK_CALL, InitActorDecide, &s_ZillaRocket[1][6]},
        {ZILLA_ROCKET_R1 + 3, ZILLA_ROCKET_RATE*10, NullZilla, &s_ZillaRocket[1][5]}
    },
    {
        {ZILLA_ROCKET_R2 + 0, ZILLA_ROCKET_RATE, NullZilla, &s_ZillaRocket[2][1]},
        {ZILLA_ROCKET_R2 + 1, ZILLA_ROCKET_RATE, NullZilla, &s_ZillaRocket[2][2]},
        {ZILLA_ROCKET_R2 + 2, ZILLA_ROCKET_RATE*4, NullZilla, &s_ZillaRocket[2][3]},
        {ZILLA_ROCKET_R2 + 2, SF_QUICK_CALL, InitZillaRocket, &s_ZillaRocket[2][4]},
        {ZILLA_ROCKET_R2 + 2, ZILLA_ROCKET_RATE*4, NullZilla, &s_ZillaRocket[2][5]},
        {ZILLA_ROCKET_R2 + 3, SF_QUICK_CALL, InitActorDecide, &s_ZillaRocket[2][6]},
        {ZILLA_ROCKET_R2 + 3, ZILLA_ROCKET_RATE*10, NullZilla, &s_ZillaRocket[2][5]}
    },
    {
        {ZILLA_ROCKET_R3 + 0, ZILLA_ROCKET_RATE, NullZilla, &s_ZillaRocket[3][1]},
        {ZILLA_ROCKET_R3 + 1, ZILLA_ROCKET_RATE, NullZilla, &s_ZillaRocket[3][2]},
        {ZILLA_ROCKET_R3 + 2, ZILLA_ROCKET_RATE*4, NullZilla, &s_ZillaRocket[3][3]},
        {ZILLA_ROCKET_R3 + 2, SF_QUICK_CALL, InitZillaRocket, &s_ZillaRocket[3][4]},
        {ZILLA_ROCKET_R3 + 2, ZILLA_ROCKET_RATE*4, NullZilla, &s_ZillaRocket[3][5]},
        {ZILLA_ROCKET_R3 + 3, SF_QUICK_CALL, InitActorDecide, &s_ZillaRocket[3][6]},
        {ZILLA_ROCKET_R3 + 3, ZILLA_ROCKET_RATE*10, NullZilla, &s_ZillaRocket[3][5]}
    },
    {
        {ZILLA_ROCKET_R4 + 0, ZILLA_ROCKET_RATE, NullZilla, &s_ZillaRocket[4][1]},
        {ZILLA_ROCKET_R4 + 1, ZILLA_ROCKET_RATE, NullZilla, &s_ZillaRocket[4][2]},
        {ZILLA_ROCKET_R4 + 2, ZILLA_ROCKET_RATE*4, NullZilla, &s_ZillaRocket[4][3]},
        {ZILLA_ROCKET_R4 + 2, SF_QUICK_CALL, InitZillaRocket, &s_ZillaRocket[4][4]},
        {ZILLA_ROCKET_R4 + 2, ZILLA_ROCKET_RATE*4, NullZilla, &s_ZillaRocket[4][5]},
        {ZILLA_ROCKET_R4 + 3, SF_QUICK_CALL, InitActorDecide, &s_ZillaRocket[4][6]},
        {ZILLA_ROCKET_R4 + 3, ZILLA_ROCKET_RATE*10, NullZilla, &s_ZillaRocket[4][5]}
    }
};

STATE* sg_ZillaRocket[] =
{
    &s_ZillaRocket[0][0],
    &s_ZillaRocket[1][0],
    &s_ZillaRocket[2][0],
    &s_ZillaRocket[3][0],
    &s_ZillaRocket[4][0]
};

//////////////////////
//
// ZILLA UZI
//
//////////////////////

#define ZILLA_UZI_RATE 8
ANIMATOR InitEnemyUzi;

STATE s_ZillaUzi[5][17] =
{
    {
        {ZILLA_SHOOT_R0 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[0][1]},
        {ZILLA_SHOOT_R0 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[0][2]},
        {ZILLA_SHOOT_R0 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[0][3]},
        {ZILLA_SHOOT_R0 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[0][4]},
        {ZILLA_SHOOT_R0 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[0][5]},
        {ZILLA_SHOOT_R0 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[0][6]},
        {ZILLA_SHOOT_R0 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[0][7]},
        {ZILLA_SHOOT_R0 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[0][8]},
        {ZILLA_SHOOT_R0 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[0][9]},
        {ZILLA_SHOOT_R0 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[0][10]},
        {ZILLA_SHOOT_R0 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[0][11]},
        {ZILLA_SHOOT_R0 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[0][12]},
        {ZILLA_SHOOT_R0 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[0][13]},
        {ZILLA_SHOOT_R0 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[0][14]},
        {ZILLA_SHOOT_R0 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[0][15]},
        {ZILLA_SHOOT_R0 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[0][16]},
        {ZILLA_SHOOT_R0 + 0, 0 | SF_QUICK_CALL, InitActorDecide, &s_ZillaUzi[0][16]},
    },
    {
        {ZILLA_SHOOT_R1 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[1][1]},
        {ZILLA_SHOOT_R1 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[1][2]},
        {ZILLA_SHOOT_R1 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[1][3]},
        {ZILLA_SHOOT_R1 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[1][4]},
        {ZILLA_SHOOT_R1 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[1][5]},
        {ZILLA_SHOOT_R1 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[1][6]},
        {ZILLA_SHOOT_R1 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[1][7]},
        {ZILLA_SHOOT_R1 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[1][8]},
        {ZILLA_SHOOT_R1 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[1][9]},
        {ZILLA_SHOOT_R1 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[1][10]},
        {ZILLA_SHOOT_R1 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[1][11]},
        {ZILLA_SHOOT_R1 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[1][12]},
        {ZILLA_SHOOT_R1 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[1][13]},
        {ZILLA_SHOOT_R1 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[1][14]},
        {ZILLA_SHOOT_R1 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[1][15]},
        {ZILLA_SHOOT_R1 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[1][16]},
        {ZILLA_SHOOT_R1 + 0, 0 | SF_QUICK_CALL, InitActorDecide, &s_ZillaUzi[1][16]},
    },
    {
        {ZILLA_SHOOT_R2 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[2][1]},
        {ZILLA_SHOOT_R2 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[2][2]},
        {ZILLA_SHOOT_R2 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[2][3]},
        {ZILLA_SHOOT_R2 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[2][4]},
        {ZILLA_SHOOT_R2 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[2][5]},
        {ZILLA_SHOOT_R2 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[2][6]},
        {ZILLA_SHOOT_R2 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[2][7]},
        {ZILLA_SHOOT_R2 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[2][8]},
        {ZILLA_SHOOT_R2 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[2][9]},
        {ZILLA_SHOOT_R2 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[2][10]},
        {ZILLA_SHOOT_R2 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[2][11]},
        {ZILLA_SHOOT_R2 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[2][12]},
        {ZILLA_SHOOT_R2 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[2][13]},
        {ZILLA_SHOOT_R2 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[2][14]},
        {ZILLA_SHOOT_R2 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[2][15]},
        {ZILLA_SHOOT_R2 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[2][16]},
        {ZILLA_SHOOT_R2 + 0, 0 | SF_QUICK_CALL, InitActorDecide, &s_ZillaUzi[2][16]},
    },
    {
        {ZILLA_SHOOT_R3 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[3][1]},
        {ZILLA_SHOOT_R3 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[3][2]},
        {ZILLA_SHOOT_R3 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[3][3]},
        {ZILLA_SHOOT_R3 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[3][4]},
        {ZILLA_SHOOT_R3 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[3][5]},
        {ZILLA_SHOOT_R3 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[3][6]},
        {ZILLA_SHOOT_R3 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[3][7]},
        {ZILLA_SHOOT_R3 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[3][8]},
        {ZILLA_SHOOT_R3 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[3][9]},
        {ZILLA_SHOOT_R3 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[3][10]},
        {ZILLA_SHOOT_R3 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[3][11]},
        {ZILLA_SHOOT_R3 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[3][12]},
        {ZILLA_SHOOT_R3 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[3][13]},
        {ZILLA_SHOOT_R3 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[3][14]},
        {ZILLA_SHOOT_R3 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[3][15]},
        {ZILLA_SHOOT_R3 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[3][16]},
        {ZILLA_SHOOT_R3 + 0, 0 | SF_QUICK_CALL, InitActorDecide, &s_ZillaUzi[3][16]},
    },
    {
        {ZILLA_SHOOT_R4 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[4][1]},
        {ZILLA_SHOOT_R4 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[4][2]},
        {ZILLA_SHOOT_R4 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[4][3]},
        {ZILLA_SHOOT_R4 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[4][4]},
        {ZILLA_SHOOT_R4 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[4][5]},
        {ZILLA_SHOOT_R4 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[4][6]},
        {ZILLA_SHOOT_R4 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[4][7]},
        {ZILLA_SHOOT_R4 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[4][8]},
        {ZILLA_SHOOT_R4 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[4][9]},
        {ZILLA_SHOOT_R4 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[4][10]},
        {ZILLA_SHOOT_R4 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[4][11]},
        {ZILLA_SHOOT_R4 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[4][12]},
        {ZILLA_SHOOT_R4 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[4][13]},
        {ZILLA_SHOOT_R4 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[4][14]},
        {ZILLA_SHOOT_R4 + 0, ZILLA_UZI_RATE, NullZilla, &s_ZillaUzi[4][15]},
        {ZILLA_SHOOT_R4 + 0, 0 | SF_QUICK_CALL, InitEnemyUzi, &s_ZillaUzi[4][16]},
        {ZILLA_SHOOT_R4 + 0, 0 | SF_QUICK_CALL, InitActorDecide, &s_ZillaUzi[4][16]},
    },
};


STATE* sg_ZillaUzi[] =
{
    s_ZillaUzi[0],
    s_ZillaUzi[1],
    s_ZillaUzi[2],
    s_ZillaUzi[3],
    s_ZillaUzi[4]
};


//////////////////////
//
// ZILLA DIE
//
//////////////////////

#define ZILLA_DIE_RATE 30
ANIMATOR DoZillaDeathMelt;

STATE s_ZillaDie[] =
{
    {ZILLA_DIE + 0, ZILLA_DIE_RATE*15, DoZillaDeathMelt, &s_ZillaDie[1]},
    {ZILLA_DIE + 1, ZILLA_DIE_RATE, NullZilla, &s_ZillaDie[2]},
    {ZILLA_DIE + 2, ZILLA_DIE_RATE, NullZilla, &s_ZillaDie[3]},
    {ZILLA_DIE + 3, ZILLA_DIE_RATE, NullZilla, &s_ZillaDie[4]},
    {ZILLA_DIE + 4, ZILLA_DIE_RATE, NullZilla, &s_ZillaDie[5]},
    {ZILLA_DIE + 5, ZILLA_DIE_RATE, NullZilla, &s_ZillaDie[6]},
    {ZILLA_DIE + 6, ZILLA_DIE_RATE, NullZilla, &s_ZillaDie[7]},
    {ZILLA_DIE + 7, ZILLA_DIE_RATE*3, NullZilla, &s_ZillaDie[8]},
    {ZILLA_DEAD, ZILLA_DIE_RATE, DoActorDebris, &s_ZillaDie[8]}
};

STATE* sg_ZillaDie[] =
{
    s_ZillaDie
};

STATE s_ZillaDead[] =
{
    {ZILLA_DEAD, ZILLA_DIE_RATE, DoActorDebris, &s_ZillaDead[0]},
};

STATE* sg_ZillaDead[] =
{
    s_ZillaDead
};

ACTOR_ACTION_SET ZillaActionSet =
{
    sg_ZillaStand,
    sg_ZillaRun,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr, //climb
    sg_ZillaPain, //pain
    sg_ZillaDie,
    nullptr,
    sg_ZillaDead,
    nullptr,
    nullptr,
    {sg_ZillaUzi,sg_ZillaRail},
    {950,1024},
    {sg_ZillaUzi,sg_ZillaRocket,sg_ZillaRail},
    {400,950,1024},
    {nullptr},
    nullptr,
    nullptr
};

int SetupZilla(DSWActor* actor)
{
    ANIMATOR DoActorDecide;

    if (!(actor->spr.cstat & CSTAT_SPRITE_RESTORE))
    {
        SpawnUser(actor, ZILLA_RUN_R0, s_ZillaRun[0]);
        actor->user.Health = 6000;
    }

    if (Skill == 0) actor->user.Health = 2000;
    if (Skill == 1) actor->user.Health = 4000;

    ChangeState(actor,s_ZillaRun[0]);
    actor->user.Attrib = &ZillaAttrib;
    DoActorSetSpeed(actor, NORM_SPEED);
    actor->user.StateEnd = s_ZillaDie;
    actor->user.Rot = sg_ZillaRun;

    EnemyDefaults(actor, &ZillaActionSet, &ZillaPersonality);

    actor->spr.clipdist = (512) >> 2;
    actor->spr.xrepeat = 97;
    actor->spr.yrepeat = 79;

    return 0;
}

int NullZilla(DSWActor* actor)
{
#if 0
    if (actor->user.State == s_ZillaDie)
    {
        getzsofslopeptr(actor->sector(), actor->spr.pos.X, actor->spr.y, &actor->user.hiz, &actor->user.loz);
        actor->user.lo_sectp = actor->sector();
        actor->user.hi_sectp = actor->sector();
        actor->spr.z = actor->user.loz;
    }
#endif

    getzsofslopeptr(actor->sector(), actor->spr.pos.X, actor->spr.pos.Y, &actor->user.hiz, &actor->user.loz);
    actor->user.lo_sectp = actor->sector();
    actor->user.hi_sectp = actor->sector();
    actor->user.lowActor = nullptr;
    actor->user.highActor = nullptr;
    actor->spr.pos.Z = actor->user.loz;

    DoActorSectorDamage(actor);

    return 0;
}

int DoZillaMove(DSWActor* actor)
{
    short choose;

    // Random Zilla taunts
    if (!SoundValidAndActive(actor, CHAN_AnimeMad))
    {
        choose = StdRandomRange(1000);
        if (choose > 990)
            PlaySound(DIGI_Z16004, actor, v3df_none, CHAN_AnimeMad);
        else if (choose > 985)
            PlaySound(DIGI_Z16004, actor, v3df_none, CHAN_AnimeMad);
        else if (choose > 980)
            PlaySound(DIGI_Z16004, actor, v3df_none, CHAN_AnimeMad);
        else if (choose > 975)
            PlaySound(DIGI_Z16004, actor, v3df_none, CHAN_AnimeMad);
    }


    if (actor->user.track >= 0)
        ActorFollowTrack(actor, ACTORMOVETICS);
    else
        (*actor->user.ActorActionFunc)(actor);

    KeepActorOnFloor(actor);

    if (DoActorSectorDamage(actor))
    {
        return 0;
    }

    return 0;
}

int DoZillaStomp(DSWActor* actor)
{
    PlaySound(DIGI_ZILLASTOMP, actor, v3df_follow);

    return 0;
}

int DoZillaDeathMelt(DSWActor* actor)
{
    if (RandomRange(1000) > 800)
        SpawnGrenadeExp(actor);

    actor->user.ID = ZILLA_RUN_R0;
    actor->user.Flags &= ~(SPR_JUMPING|SPR_FALLING|SPR_MOVED);

    //DoMatchEverything(nullptr, actor->spr.lotag, ON);
    if (!SW_SHAREWARE)
    {
        // Resume the regular music - in a hack-free fashion.
        PlaySong(currentLevel->music, currentLevel->cdSongId);
    }

    //KeepActorOnFloor(actor);
    getzsofslopeptr(actor->sector(), actor->spr.pos.X, actor->spr.pos.Y, &actor->user.hiz, &actor->user.loz);
    actor->user.lo_sectp = actor->sector();
    actor->user.hi_sectp = actor->sector();
    actor->user.lowActor = nullptr;
    actor->user.highActor = nullptr;
    actor->spr.pos.Z = actor->user.loz;

    BossSpriteNum[2] = nullptr;
    return 0;
}


#include "saveable.h"

static saveable_code saveable_zilla_code[] =
{
    SAVE_CODE(NullZilla),
    SAVE_CODE(DoZillaMove),
    SAVE_CODE(DoZillaStomp),
    SAVE_CODE(DoZillaDeathMelt),
};

static saveable_data saveable_zilla_data[] =
{
    SAVE_DATA(ZillaBattle),
    SAVE_DATA(ZillaOffense),
    SAVE_DATA(ZillaBroadcast),
    SAVE_DATA(ZillaSurprised),
    SAVE_DATA(ZillaEvasive),
    SAVE_DATA(ZillaLostTarget),
    SAVE_DATA(ZillaCloseRange),

    SAVE_DATA(ZillaPersonality),

    SAVE_DATA(ZillaAttrib),

    SAVE_DATA(s_ZillaRun),
    SAVE_DATA(sg_ZillaRun),
    SAVE_DATA(s_ZillaStand),
    SAVE_DATA(sg_ZillaStand),
    SAVE_DATA(s_ZillaPain),
    SAVE_DATA(sg_ZillaPain),
    SAVE_DATA(s_ZillaRail),
    SAVE_DATA(sg_ZillaRail),
    SAVE_DATA(s_ZillaRocket),
    SAVE_DATA(sg_ZillaRocket),
    SAVE_DATA(s_ZillaUzi),
    SAVE_DATA(sg_ZillaUzi),
    SAVE_DATA(s_ZillaDie),
    SAVE_DATA(sg_ZillaDie),
    SAVE_DATA(s_ZillaDead),
    SAVE_DATA(sg_ZillaDead),

    SAVE_DATA(ZillaActionSet),
};

saveable_module saveable_zilla =
{
    // code
    saveable_zilla_code,
    SIZ(saveable_zilla_code),

    // data
    saveable_zilla_data,
    SIZ(saveable_zilla_data)
};

END_SW_NS
