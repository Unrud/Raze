#pragma once
#include "ns.h"

BEGIN_WH_NS

enum
{
	MAXWEAPONS = 10,
	MAXPOTIONS = 5,

	BACKBUTTON = 9216,
	BACKSCALE = 16384,
	MOUSECURSOR = 9217,
	RESERVED1 = 9218,
	RESERVED2 = 9219,
	
	WHLOGO = 9220,
	MENUFONT = 9221, //+32
	
	MINITEXTPOINT = 9254,
	MINITEXTSLASH = 9255,
	
	WH2FONTBIGLETTERS = 9256,
	WH2FONTLILLETTERS = 9282,
	WH2FONTNUMBERS = 9308,
	WH2LOGO = 9335,
	WH2FONTBACKGROUND = 9336,
	
	ARROWCOUNTLIMIT = 100,
	THROWPIKELIMIT = 100,
	
	GRAVITYCONSTANT = (4 << 7) - 32,
	JUMPVEL = (4 << 10) - 256,
	
	WH2GRAVITYCONSTANT = (8 << 5),
	WH2JUMPVEL = (6 << 10), //(8 << 10)
	GROUNDBIT = 1,
	PLATFORMBIT = 2,

	TICSPERFRAME = 3,
	TIMERRATE = 120,

	kExtraTile = MAXTILES - MAXUSERTILES,

	// Hit definitions
	kHitTypeMask = 0xE000,
	kHitIndexMask = 0x1FFF,
	kHitFloor = 0x4000,
	kHitSector = 0x4000,
	kHitCeiling = 0x6000,
	kHitWall = 0x8000,
	kHitSprite = 0xC000,

	PLAYERHEIGHT = 48,
	WH2PLAYERHEIGHT = 64,
	MAXNUMORBS = 8,
	MAXHEALTH = 100,
	MAXKEYS = 4,
	MAXTREASURES = 18,

	LOW = 1,
	HIGH = 2,

	TOP = 1,
	BOTTOM = 2,

	INACTIVE = 0,
	PATROL = 1,
	CHASE = 2,
	AMBUSH = 3,
	BIRTH = 4,
	DODGE = 5,
	ATTACK = 6,
	DEATH = 7,
	STAND = 8,

	MISSILE = 100,
	FX = 101,
	HEATSEEKER = 102,
	YELL = 103,
	CAST = 104,
	PUSH = 105,
	FALL = 106,
	DIE = 107,
	DEAD = 108,
	FACE = 109,
	SHOVE = 110,
	SHATTER = 111,
	FIRE = 112,
	LIFTUP = 113,
	LIFTDN = 114,
	PENDULUM = 115,
	RESURECT = 116,
	BOB = 117,
	SHOVER = 118,
	TORCHER = 119,
	MASPLASH = 120,
	CHUNKOMEAT = 121,
	FLEE = 122,
	DORMANT = 123,
	ACTIVE = 124,
	ATTACK2 = 125,
	WITCHSIT = 126,
	CHILL = 127,
	SKIRMISH = 128,
	FLOCK = 129,
	FLOCKSPAWN = 130,
	PAIN = 131,
	WAR = 132,
	TORCHLIGHT = 133,
	GLOWLIGHT = 134,
	BLOOD = 135,
	DRIP = 136,
	DEVILFIRE = 137,
	FROZEN = 138,
	PULLTHECHAIN = 139,
	FLOCKCHIRP = 140,
	CHUNKOWALL = 141,
	FINDME = 142,
	DRAIN = 143,
	RATRACE = 144,
	SMOKE = 145,
	EXPLO = 146,
	JAVLIN = 147,
	ANIMLEVERUP = 148,
	ANIMLEVERDN = 149,
	BROKENVASE = 150,
	NUKED = 151,
	WARPFX = 152,
	PATROLFLAG = 153,
	PLACECONE = 154,
	REMOVECONE = 155,
	FIRSTCONE = 156,
	GOTOCONE = 157,
	TORCHFRONT = 158,
	APATROLPOINT = 159,
	SHADE = 160,
	EVILSPIRIT = 161,
	STONETOFLESH = 162,
	SPARKS = 163,
	SPARKSUP = 164,
	SPARKSDN = 165,
	LAND = 166,
	SHARDOFGLASS = 167,
	FIRECHUNK = 168,
	DUDE = 170,
	
	  ACTIVATESECTOR  =    1,
	  ACTIVATESECTORONCE = 2,

	  DOORUPTAG   =   6,
	  DOORDOWNTAG  =  7,
	  DOORSPLITHOR =  8,
	  DOORSPLITVER =  9,
	  DOORSWINGTAG =  13,
	  DOORBOX     =   16,

	  PLATFORMELEVTAG = 1000,
	  BOXELEVTAG    = 1003,

	  SECTOREFFECT  = 104,
	  PULSELIGHT    = 0,
	  FLICKERLIGHT  = 1,
	  DELAYEFFECT  =  2,
	  XPANNING     =  3,

	  DOORDELAY    =  480, // 4 second delay for doors to close
	  DOORSPEED    =  128,
	  ELEVSPEED   =   256,

	  PICKDISTANCE =  512, // for picking up sprites
	  PICKHEIGHT  =   40,
	  PICKHEIGHT2  =  64,

	  JETPACKPIC   =  93 ,  // sprites available to pick up

	  MAXSWINGDOORS = 32,
	
	  JETPACKITEM =   0,
	  SHOTGUNITEM =   1,

	  SHOTGUNPIC   =  101,
	  SHOTGUNVIEW  =  102,

	  KILLSECTOR = 4444,
	
	TDIAMONDRING = 0, //armortype3 200units
	TSHADOWAMULET = 1, //shadow
	TGLASSSKULL = 2, //add score
	TAHNK = 3, //health 250units
	TBLUESCEPTER = 4, //lava walk
	TYELLOWSCEPTER = 5, //water walk
	TADAMANTINERING = 6, //unfinity attack protection
	TONYXRING = 7, //projectiles protection
	TPENTAGRAM = 8, //exit
	TCRYSTALSTAFF = 9, //health 250units armortype2 200units
	TAMULETOFTHEMIST = 10, //invisible
	THORNEDSKULL = 11, //end game
	TTHEHORN = 12, //vampire
	TSAPHIRERING = 13, //set armortype to 3 
	TBRASSKEY = 14,
	TBLACKKEY = 15,
	TGLASSKEY = 16,
	TIVORYKEY = 17,

	MAXWEAPONS = 10,
	MAXPOTIONS = 5,

};

END_WH_NS
