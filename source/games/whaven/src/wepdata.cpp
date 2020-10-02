#include "ns.h"
#include "wh.h"

BEGIN_WH_NS


const WEAPONINF sspellbookanim[MAXNUMORBS][9] =
{
	// SCARE
	{{8, SSPELLBOOK8, 121, 389}, {8, SSPELLBOOK8 + 1, 121, 377},
	{8, SSPELLBOOK8 + 2, 121, 383}, {8, SSPELLBOOK8 + 3, 121, 385},
	{8, SSPELLBOOK8 + 4, 121, 389}, {8, SSPELLBOOK8 + 5, 121, 387},
	{8, SSPELLBOOK8 + 6, 121, 389}, {8, SSPELLBOOK8 + 7, 121, 389},
	{8, SSPELLBOOK8 + 7, 121, 389}
	},
	// NIGHT VISION
	{{8, SSPELLBOOK6, 121, 389}, {8, SSPELLBOOK6 + 1, 121, 377},
	{8, SSPELLBOOK6 + 2, 121, 383}, {8, SSPELLBOOK6 + 3, 121, 385},
	{8, SSPELLBOOK6 + 4, 121, 389}, {8, SSPELLBOOK6 + 5, 121, 387},
	{8, SSPELLBOOK6 + 6, 121, 389}, {8, SSPELLBOOK6 + 7, 121, 389},
	{8, SSPELLBOOK6 + 7, 121, 389}
	},
	// FREEZE
	{{8, SSPELLBOOK3, 121, 389}, {8, SSPELLBOOK3 + 1, 121, 377},
	{8, SSPELLBOOK3 + 2, 121, 383}, {8, SSPELLBOOK3 + 3, 121, 385},
	{8, SSPELLBOOK3 + 4, 121, 389}, {8, SSPELLBOOK3 + 5, 120, 387},
	{8, SSPELLBOOK3 + 6, 120, 389}, {8, SSPELLBOOK3 + 7, 120, 389},
	{8, SSPELLBOOK3 + 7, 121, 389}
	},
	// MAGIC ARROW
	{{8, SSPELLBOOKBLANK, 121, 389}, {8, SSPELLBOOKBLANK + 1, 121, 377},
	{8, SSPELLBOOKBLANK + 2, 121, 383}, {8, SSPELLBOOKBLANK + 3, 121, 385},
	{8, SSPELLBOOKBLANK + 4, 121, 389}, {8, SSPELLBOOKBLANK + 5, 121, 387},
	{8, SSPELLBOOKBLANK + 6, 120, 389}, {8, SSPELLBOOKBLANK + 7, 121, 389},
	{8, SSPELLBOOKBLANK + 7, 122, 389}
	},
	// OPEN DOORS
	{{8, SSPELLBOOK7, 121, 389}, {8, SSPELLBOOK7 + 1, 121, 377},
	{8, SSPELLBOOK7 + 2, 121, 383}, {8, SSPELLBOOK7 + 3, 121, 385},
	{8, SSPELLBOOK7 + 4, 121, 389}, {8, SSPELLBOOK7 + 5, 121, 387},
	{8, SSPELLBOOK7 + 6, 121, 389}, {8, SSPELLBOOK7 + 7, 121, 389},
	{8, SSPELLBOOK7 + 7, 121, 389}
	},
	// FLY
	{{8, SSPELLBOOK2, 121, 389}, {8, SSPELLBOOK2 + 1, 121, 377},
	{8, SSPELLBOOK2 + 2, 121, 383}, {8, SSPELLBOOK2 + 3, 121, 385},
	{8, SSPELLBOOK2 + 4, 121, 389}, {8, SSPELLBOOK2 + 5, 121, 387},
	{8, SSPELLBOOK2 + 6, 121, 389}, {8, SSPELLBOOK2 + 7, 121, 389},
	{8, SSPELLBOOK2 + 7, 121, 389}
	},
	// FIRE BALL
	{{8, SSPELLBOOK4, 121, 389}, {8, SSPELLBOOK4 + 1, 121, 377},
	{8, SSPELLBOOK4 + 2, 121, 383}, {8, SSPELLBOOK4 + 3, 121, 385},
	{8, SSPELLBOOK4 + 4, 121, 389}, {8, SSPELLBOOK4 + 5, 121, 387},
	{8, SSPELLBOOK4 + 6, 121, 389}, {8, SSPELLBOOK4 + 6, 121, 389},
	{8, SSPELLBOOK4 + 6, 121, 389}
	},
	// NUKE!
	{{8, SSPELLBOOK5, 121, 389}, {8, SSPELLBOOK5 + 1, 121, 377},
	{8, SSPELLBOOK5 + 2, 121, 383}, {8, SSPELLBOOK5 + 3, 121, 385},
	{8, SSPELLBOOK5 + 4, 121, 389}, {8, SSPELLBOOK5 + 5, 121, 387},
	{8, SSPELLBOOK5 + 6, 121, 389}, {8, SSPELLBOOK5 + 6, 121, 389},
	{8, SSPELLBOOK5 + 6, 121, 389}
	}

};


const WEAPONINF spikeanimtics[5] =
{ {10, DIESPIKE, 136, 145},
{10, DIESPIKE + 1, 136, 124},
{10, DIESPIKE + 2, 136, 100},
{10, DIESPIKE + 3, 136, 70},
{10, DIESPIKE + 4, 136, 50} };

const WEAPONINF wh2throwanimtics[MAXNUMORBS][MAXFRAMES + 1] =
{
	// MUTWOHANDS  - scare spell
	{{1, EMPTY, 127, 170}, {10, MUTWOHANDS + 1, 0, 128}, {10, MUTWOHANDS + 2, 0, 93},
	{10, MUTWOHANDS + 3, 0, 83}, {10, MUTWOHANDS + 4, 0, 72}, {10, MUTWOHANDS + 5, 0, 83},
	{10, MUTWOHANDS + 6, 10, 96}, {10, MUTWOHANDS + 7, 43, 109}, {10, MUTWOHANDS + 8, 69, 113},
	{10, MUTWOHANDS + 9, 65, 115}, {10, MUTWOHANDS + 10, 64, 117}, {10, MUTWOHANDS + 11, 63, 117},
	{1, EMPTY, 127, 170}
	},
	// MUTWOHANDS  - night vision
	{{10, ZFIREBALL, 0, 177}, {10, ZFIREBALL + 1, 0, 137}, {10, ZFIREBALL + 2, 48, 82},
	{10, ZFIREBALL + 3, 127, 41}, {10, ZFIREBALL + 4, 210, 9}, {10, ZFIREBALL + 5, 284, 26},
	{10, ZFIREBALL + 6, 213, 63}, {10, ZFIREBALL + 7, 147, 99}, {10, ZFIREBALL + 8, 91, 136},
	{10, ZFIREBALL + 9, 46, 183}, {1, EMPTY, 127, 170}, {1, EMPTY, 127, 170},
	{1, EMPTY, 127, 170}
	},
	// MUTWOHANDS  - freeze
	{{1, EMPTY, 127, 170}, {10, ZFREEZE + 1, 0, 51}, {10, ZFREEZE + 2, 0, 71},
	{10, ZFREEZE + 3, 4, 85}, {10, ZFREEZE + 4, 32, 78}, {10, ZFREEZE + 5, 51, 80},
	{10, ZFREEZE + 6, 50, 80}, {10, ZFREEZE + 7, 49, 89}, {10, ZFREEZE + 8, 49, 89},
	{10, ZFREEZE + 9, 49, 98}, {10, ZFREEZE + 10, 47, 105}, {10, ZFREEZE + 11, 48, 121},
	{1, EMPTY, 127, 170}
	},
	// MUTWOHANDS  - magic arrow
	{{1, EMPTY, 127, 170}, {10, MUTWOHANDS + 1, 0, 128}, {10, MUTWOHANDS + 2, 0, 93},
	{10, MUTWOHANDS + 3, 0, 83}, {10, MUTWOHANDS + 4, 0, 72}, {10, MUTWOHANDS + 5, 0, 83},
	{10, MUTWOHANDS + 6, 10, 96}, {10, MUTWOHANDS + 7, 43, 109}, {10, MUTWOHANDS + 8, 69, 113},
	{10, MUTWOHANDS + 9, 65, 115}, {10, MUTWOHANDS + 10, 64, 117}, {10, MUTWOHANDS + 11, 63, 117},
	{1, EMPTY, 127, 170}
	},
	// MUTWOHANDS  - open door
	{{15, MUTWOHANDS, 19, 155}, {15, MUTWOHANDS + 1, 0, 128}, {15, MUTWOHANDS + 2, 0, 93},
	{15, MUTWOHANDS + 3, 0, 83}, {15, MUTWOHANDS + 4, 0, 72}, {15, MUTWOHANDS + 5, 0, 83},
	{15, MUTWOHANDS + 6, 10, 96}, {15, MUTWOHANDS + 7, 43, 109}, {15, MUTWOHANDS + 8, 69, 113},
	{15, MUTWOHANDS + 9, 65, 115}, {15, MUTWOHANDS + 10, 64, 117}, {15, MUTWOHANDS + 11, 63, 117},
	{1, EMPTY, 127, 170}
	},
	// MUMEDUSA    - fly
	{{10, ZLIGHT, 0, 177}, {10, ZLIGHT + 1, 0, 137}, {10, ZLIGHT + 2, 48, 82},
	{10, ZLIGHT + 3, 127, 41}, {10, ZLIGHT + 4, 210, 9}, {10, ZLIGHT + 5, 284, 26},
	{10, ZLIGHT + 6, 213, 63}, {10, ZLIGHT + 7, 147, 99}, {10, ZLIGHT + 8, 91, 136},
	{10, ZLIGHT + 9, 46, 183}, {1, EMPTY, 127, 170}, {1, EMPTY, 127, 170},
	{1, EMPTY, 127, 170}
	},
	// MUTWOHANDS  - fireball
	{{1, EMPTY, 127, 170}, {10, ZFIREBALL + 1, 0, 137}, {10, ZFIREBALL + 2, 48, 82},
	{10, ZFIREBALL + 3, 127, 41}, {10, ZFIREBALL + 4, 210, 9}, {10, ZFIREBALL + 5, 284, 26},
	{10, ZFIREBALL + 6, 213, 63}, {10, ZFIREBALL + 7, 147, 99}, {10, ZFIREBALL + 8, 91, 136},
	{10, ZFIREBALL + 9, 46, 183}, {1, EMPTY, 127, 170}, {1, EMPTY, 127, 170},
	{1, EMPTY, 127, 170}
	},
	// MUTWOHANDS  - nuke
	{{1, EMPTY, 127, 170}, {10, MUTWOHANDS + 1, 0, 128}, {10, MUTWOHANDS + 2, 0, 93},
	{10, MUTWOHANDS + 3, 0, 83}, {10, MUTWOHANDS + 4, 0, 72}, {10, MUTWOHANDS + 5, 0, 83},
	{10, MUTWOHANDS + 6, 10, 96}, {10, MUTWOHANDS + 7, 43, 109}, {10, MUTWOHANDS + 8, 69, 113},
	{10, MUTWOHANDS + 9, 65, 115}, {10, MUTWOHANDS + 10, 64, 117}, {10, MUTWOHANDS + 11, 63, 117},
	{1, EMPTY, 127, 170}
	}
};

const WEAPONINF throwanimtics[MAXNUMORBS][MAXFRAMES + 1] =
{
	// MUTWOHANDS
	{ {10,MUTWOHANDS,19,155},{10,MUTWOHANDS + 1,0,128},{10,MUTWOHANDS + 2,0,93},
	  {10,MUTWOHANDS + 3,0,83},{10,MUTWOHANDS + 4,0,72},{10,MUTWOHANDS + 5,0,83},
	  {10,MUTWOHANDS + 6,10,96},{10,MUTWOHANDS + 7,43,109},{10,MUTWOHANDS + 8,69,113},
	  {10,MUTWOHANDS + 9,65,115},{10,MUTWOHANDS + 10,64,117},{10,MUTWOHANDS + 11,63,117},
	  {1,NULL,127,170}
	},
	// MUMEDUSA
	{ {10,MUMEDUSA,0,177},{10,MUMEDUSA + 1,0,137},{10,MUMEDUSA + 2,48,82},
	  {10,MUMEDUSA + 3,127,41},{10,MUMEDUSA + 4,210,9},{10,MUMEDUSA + 5,284,26},
	  {10,MUMEDUSA + 6,213,63},{10,MUMEDUSA + 7,147,99},{10,MUMEDUSA + 8,91,136},
	  {10,MUMEDUSA + 9,46,183},{1,NULL,127,170},{1,NULL,127,170},
	  {1,NULL,127,170}
	},
	// BMUTWOHANDS
	{ {10,MUTWOHANDS,19,155},{10,MUTWOHANDS + 1,0,128},{10,MUTWOHANDS + 2,0,93},
	  {10,MUTWOHANDS + 3,0,83},{10,BMUTWOHANDS,0,74},{10,BMUTWOHANDS + 1,0,97},
	  {10,BMUTWOHANDS + 2,10,109},{10,BMUTWOHANDS + 3,43,113},{10,BMUTWOHANDS + 4,69,115},
	  {10,BMUTWOHANDS + 5,65,117},{10,BMUTWOHANDS + 6,64,117},{10,BMUTWOHANDS + 7,63,117},
	  {1,NULL,127,170}
	},
	// MUTWOHANDS
	{ {10,MUTWOHANDS,19,155},{10,MUTWOHANDS + 1,0,128},{10,MUTWOHANDS + 2,0,93},
	  {10,MUTWOHANDS + 3,0,83},{10,MUTWOHANDS + 4,0,72},{10,MUTWOHANDS + 5,0,83},
	  {10,MUTWOHANDS + 6,10,96},{10,MUTWOHANDS + 7,43,109},{10,MUTWOHANDS + 8,69,113},
	  {10,MUTWOHANDS + 9,65,115},{10,MUTWOHANDS + 10,64,117},{10,MUTWOHANDS + 11,63,117},
	  {1,NULL,127,170}
	},
	// MUTWOHANDS
	{ {15,MUTWOHANDS,19,155},{15,MUTWOHANDS + 1,0,128},{15,MUTWOHANDS + 2,0,93},
	  {15,MUTWOHANDS + 3,0,83},{15,MUTWOHANDS + 4,0,72},{15,MUTWOHANDS + 5,0,83},
	  {15,MUTWOHANDS + 6,10,96},{15,MUTWOHANDS + 7,43,109},{15,MUTWOHANDS + 8,69,113},
	  {15,MUTWOHANDS + 9,65,115},{15,MUTWOHANDS + 10,64,117},{15,MUTWOHANDS + 11,63,117},
	  {1,NULL,127,170}
	},
	// MUMEDUSA
	{ {10,MUMEDUSA,0,177},{10,MUMEDUSA + 1,0,137},{10,MUMEDUSA + 2,48,82},
	  {10,MUMEDUSA + 3,127,41},{10,MUMEDUSA + 4,210,9},{10,MUMEDUSA + 5,284,26},
	  {10,MUMEDUSA + 6,213,63},{10,MUMEDUSA + 7,147,99},{10,MUMEDUSA + 8,91,136},
	  {10,MUMEDUSA + 9,46,183},{1,NULL,127,170},{1,NULL,127,170},
	  {1,NULL,127,170}
	},
	// MUTWOHANDS
	{ {10,MUTWOHANDS,19,155},{10,MUTWOHANDS + 1,0,128},{10,MUTWOHANDS + 2,0,93},
	  {10,MUTWOHANDS + 3,0,83},{10,MUTWOHANDS + 4,0,72},{10,MUTWOHANDS + 5,0,83},
	  {10,MUTWOHANDS + 6,10,96},{10,MUTWOHANDS + 7,43,109},{10,MUTWOHANDS + 8,69,113},
	  {10,MUTWOHANDS + 9,65,115},{10,MUTWOHANDS + 10,64,117},{10,MUTWOHANDS + 11,63,117},
	  {1,NULL,127,170}
	},
	// MUTWOHANDS
	{ {10,MUTWOHANDS,19,155},{10,MUTWOHANDS + 1,0,128},{10,MUTWOHANDS + 2,0,93},
	  {10,MUTWOHANDS + 3,0,83},{10,MUTWOHANDS + 4,0,72},{10,MUTWOHANDS + 5,0,83},
	  {10,MUTWOHANDS + 6,10,96},{10,MUTWOHANDS + 7,43,109},{10,MUTWOHANDS + 8,69,113},
	  {10,MUTWOHANDS + 9,65,115},{10,MUTWOHANDS + 10,64,117},{10,MUTWOHANDS + 11,63,117},
	  {1,NULL,127,170}
	}

};

const WEAPONINF cockanimtics[MAXFRAMES + 1] =
{
	{24,NULL,10,10},
	{12,BOWREADYEND + 1,101,115},{12,BOWREADYEND + 2,112,0},
	{12,BOWREADYEND + 3,115,0},{12,BOWREADYEND + 4,75,13}
};

const WEAPONINF zcockanimtics[MAXFRAMES + 1] =
{
	 {24, EMPTY, 10, 10},
	 {12, BOWREADYEND + 1, 101, 115}, {12, BOWREADYEND + 2, 112, 0},
	 {12, BOWREADYEND + 3, 115, 0}, {12, ZBOWWALK, 75, 13}
};

//SCOTT
const WEAPONINF zreadyanimtics[MAXWEAPONS][MAXFRAMES + 1] =
{
	// FIST
	{{10, RFIST, 216, 180}, {10, RFIST, 216, 170}, {10, RFIST, 216, 160},
	{10, RFIST, 216, 150}, {10, RFIST, 216, 140}, {10, RFIST, 216, 130},
	{10, RFIST, 216, 124}, {1, RFIST, 216, 124}, {1, RFIST, 216, 124},
	{1, RFIST, 216, 122}, {1, RFIST, 216, 122}, {1, RFIST, 216, 122},
	{1, EMPTY, 147, 76}
	},
	// ZKNIFE
	{{10, ZKNIFEREADY, 69, 171}, {10, ZKNIFEREADY + 1, 11, 146}, {10, ZKNIFEREADY + 2, 25, 146},
	{10, ZKNIFEREADY + 3, 35, 158}, {10, ZKNIFEREADY + 4, 38, 158}, {10, ZKNIFEREADY + 5, 16, 157},
	{10, ZKNIFEREADY + 6, 37, 102}, {10, ZKNIFEREADY + 7, 239, 63}, {10, ZKNIFEREADY + 8, 214, 85},
	{10, ZKNIFEREADY + 9, 206, 110}, {10, ZKNIFEREADY + 10, 217, 108}, {10, ZKNIFEREADY + 11, 204, 95},
	{1, EMPTY, 147, 76}
	},
	// ZSHORTREADY
	{{12, ZSHORTREADY, 79, 169}, {12, ZSHORTREADY + 1, 95, 115}, {12, ZSHORTREADY + 2, 94, 93},
	{12, ZSHORTREADY + 3, 156, 77}, {12, ZSHORTREADY + 4, 218, 64}, {12, ZSHORTREADY + 5, 224, 57},
	{8, ZSHORTREADY + 6, 251, 54}, {1, ZSHORTREADY + 7, 243, 92}, {1, ZSHORTREADY + 7, 243, 92},
	{1, ZSHORTREADY + 7, 243, 92}, {1, ZSHORTREADY + 7, 243, 92}, {1, ZSHORTREADY + 7, 243, 92},
	{1, EMPTY, 147, 76}
	},
	// ZSTARATTACK
	{{6, ZSTARATTACK, 194, 195}, {6, ZSTARATTACK, 194, 185}, {6, ZSTARATTACK, 194, 175},
	{6, ZSTARATTACK, 194, 165}, {6, ZSTARATTACK, 194, 155}, {6, ZSTARATTACK, 194, 145},
	{6, ZSTARATTACK, 194, 135}, {6, ZSTARATTACK, 194, 125}, {6, ZSTARATTACK, 194, 115},
	{6, ZSTARATTACK, 194, 105}, {6, ZSTARATTACK, 194, 95}, {1, ZSTARATTACK, 194, 85},
	{1, EMPTY, 147, 76}
	},
	// SWORD
	{{10, SWORDPULL, 58, 160}, {10, SWORDPULL + 1, 81, 111}, {10, SWORDPULL + 2, 19, 88},
	{10, SWORDPULL + 3, 0, 93}, {10, SWORDPULL + 4, 104, 0}, {10, SWORDPULL + 5, 169, 0},
	{10, SWORDPULL + 6, 244, 38}, {6, SWORDPULL + 7, 225, 121}, {1, SWORDPULL + 7, 225, 121},
	{1, SWORDPULL + 7, 225, 121}, {1, SWORDPULL + 7, 225, 121}, {1, SWORDPULL + 7, 225, 121},
	{1, EMPTY, 147, 76}
	},
	// ZAXE
	{{8, ZAXEREADY, 0, 108}, {8, ZAXEREADY + 1, 0, 58}, {8, ZAXEREADY + 2, 0, 57},
	{8, ZAXEREADY + 3, 0, 69}, {8, ZAXEREADY + 4, 0, 100}, {8, ZAXEREADY + 5, 0, 9},
	{8, ZAXEREADY + 6, 33, 0}, {8, ZAXEREADY + 7, 61, 0}, {8, ZAXEREADY + 8, 73, 20},
	{8, ZAXEREADY + 9, 179, 117}, {8, EMPTY, 182, 116}, {1, EMPTY, 200, 122},
	{1, EMPTY, 147, 76}
	},
	// ZBOW
	{{12, ZBOWREADY, 0, 0}, {12, ZBOWREADY + 1, 0, 20}, {12, ZBOWREADY + 2, 0, 46},
	{12, ZBOWREADY + 3, 0, 26}, {12, ZBOWREADY + 4, 0, 0}, {12, ZBOWREADY + 5, 71, 0},
	{1, ZBOWWALK, 75, 13}, {1, ZBOWWALK, 75, 13}, {1, ZBOWWALK, 75, 13},
	{1, ZBOWWALK, 75, 13}, {1, ZBOWWALK, 75, 13}, {1, ZBOWWALK, 75, 13},
	{1, EMPTY, 147, 76}
	},
	// ZPIKE
	{{8, ZPIKEREADY, 0, 150}, {8, ZPIKEREADY + 1, 0, 94}, {8, ZPIKEREADY + 2, 47, 45},
	{8, ZPIKEREADY + 3, 138, 62}, {8, ZPIKEREADY + 4, 194, 95}, {8, ZPIKEREADY + 5, 59, 121},
	{1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76},
	{1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76},
	{1, EMPTY, 147, 76}
	},
	{{12, ZTWOHANDREADY, 167, 131}, {12, ZTWOHANDREADY + 1, 71, 117}, {12, ZTWOHANDREADY, 0, 128},
	{12, ZTWOHANDREADY + 3, 0, 150}, {12, ZTWOHANDREADY + 4, 10, 74}, {12, ZTWOHANDREADY + 5, 44, 81},
	{12, ZTWOHANDREADY + 6, 0, 53}, {12, ZTWOHANDREADY + 7, 112, 0}, {12, ZTWOHANDREADY + 8, 220, 0},
	{12, ZTWOHANDREADY + 9, 198, 84}, {12, ZTWOHANDREADY + 10, 186, 120}, {12, ZTWOHANDREADY + 11, 188, 124},
	{1, EMPTY, 147, 76}
	},
	{{12, HALBERDDRAW, 183, 62}, {12, HALBERDDRAW + 1, 166, 10}, {12, HALBERDDRAW + 2, 173, 29},
	{12, HALBERDDRAW + 3, 114, 35}, {1, HALBERDATTACK1, 245, 22}, {1, HALBERDATTACK1, 245, 22},
	{1, HALBERDATTACK1, 245, 22}, {1, HALBERDATTACK1, 245, 22}, {1, HALBERDATTACK1, 245, 22},
	{1, HALBERDATTACK1, 245, 22}, {1, HALBERDATTACK1, 245, 22}, {1, ZHALBERDATTACK, 245, 30},
	{1, EMPTY, 147, 76}
	}

};

const WEAPONINF readyanimtics[MAXWEAPONS][MAXFRAMES + 1] =
{
	// FIST
	{{10, RFIST, 216, 180}, {10, RFIST, 216, 170}, {10, RFIST, 216, 160},
	{10, RFIST, 216, 150}, {10, RFIST, 216, 140}, {10, RFIST, 216, 130},
	{10, RFIST, 216, 124}, {1, RFIST, 216, 124}, {1, RFIST, 216, 124},
	{1, RFIST, 216, 122}, {1, RFIST, 216, 122}, {1, RFIST, 216, 122},
	{1, EMPTY, 147, 76}
	},
	// KNIFE
	{{10, KNIFEREADY, 69, 171}, {10, KNIFEREADY + 1, 11, 146}, {10, KNIFEREADY + 2, 25, 146},
	{10, KNIFEREADY + 3, 35, 158}, {10, KNIFEREADY + 4, 38, 158}, {10, KNIFEREADY + 5, 16, 157},
	{10, KNIFEREADY + 6, 37, 102}, {10, KNIFEREADY + 7, 239, 63}, {10, KNIFEREADY + 8, 214, 85},
	{10, KNIFEREADY + 9, 206, 110}, {10, KNIFEREADY + 10, 217, 108}, {10, KNIFEREADY + 11, 204, 95},
	{1, EMPTY, 147, 76}
	},
	// GOBSWORD
	{{12, GOBSWORDPULL, 79, 169}, {12, GOBSWORDPULL + 1, 95, 115}, {12, GOBSWORDPULL + 2, 94, 93},
	{12, GOBSWORDPULL + 3, 156, 77}, {12, GOBSWORDPULL + 4, 218, 64}, {12, GOBSWORDPULL + 5, 224, 57},
	{8, GOBSWORDPULL + 6, 251, 54}, {1, GOBSWORDPULL + 7, 243, 92}, {1, GOBSWORDPULL + 7, 243, 92},
	{1, GOBSWORDPULL + 7, 243, 92}, {1, GOBSWORDPULL + 7, 243, 92}, {1, GOBSWORDPULL + 7, 243, 92},
	{1, EMPTY, 147, 76}
	},
	// MORNINGSTAR
	{{6, MORNINGSTAR, 193, 190}, {6, MORNINGSTAR, 193, 180}, {6, MORNINGSTAR, 193, 170},
	{6, MORNINGSTAR, 193, 160}, {6, MORNINGSTAR, 193, 150}, {6, MORNINGSTAR, 193, 140},
	{6, MORNINGSTAR, 193, 130}, {6, MORNINGSTAR, 193, 120}, {6, MORNINGSTAR, 193, 110},
	{6, MORNINGSTAR, 193, 100}, {6, MORNINGSTAR, 193, 90}, {1, MORNINGSTAR, 193, 90},
	{1, EMPTY, 147, 76}
	},
	// SWORD
	{{10, SWORDPULL, 58, 160}, {10, SWORDPULL + 1, 81, 111}, {10, SWORDPULL + 2, 19, 88},
	{10, SWORDPULL + 3, 0, 93}, {10, SWORDPULL + 4, 104, 0}, {10, SWORDPULL + 5, 169, 0},
	{10, SWORDPULL + 6, 244, 38}, {6, SWORDPULL + 7, 225, 121}, {1, SWORDPULL + 7, 225, 121},
	{1, SWORDPULL + 7, 225, 121}, {1, SWORDPULL + 7, 225, 121}, {1, SWORDPULL + 7, 225, 121},
	{1, EMPTY, 147, 76}
	},
	{{12, BIGAXEDRAW, 71, 108}, {12, BIGAXEDRAW + 1, 17, 58}, {12, BIGAXEDRAW + 2, 0, 56},
	{12, BIGAXEDRAW + 3, 0, 71}, {12, BIGAXEDRAW + 4, 0, 102}, {12, BIGAXEDRAW + 5, 0, 11},
	{12, BIGAXEDRAW + 6, 33, 0}, {12, BIGAXEDRAW + 7, 69, 0}, {12, BIGAXEDRAW + 8, 75, 20},
	{12, BIGAXEDRAW9, 150, 92}, {12, BIGAXEDRAW10, 182, 116}, {1, EMPTY, 200, 122},
	{1, EMPTY, 147, 76}
	},
	// BOW
	{{12, BOWREADY, 0, 0}, {12, BOWREADY + 1, 0, 20}, {12, BOWREADY + 2, 0, 46},
	{12, BOWREADY + 3, 0, 26}, {12, BOWREADY + 4, 0, 0}, {12, BOWREADY + 5, 71, 0},
	{8, BOWREADYEND, 77, 23}, {1, BOWREADYEND, 77, 23}, {1, BOWREADYEND, 77, 23},
	{1, BOWREADYEND, 77, 23}, {1, BOWREADYEND, 77, 23}, {1, BOWREADYEND, 77, 23},
	{1, EMPTY, 147, 76}
	},
	{{8, PIKEDRAW, 0, 156}, {8, PIKEDRAW + 1, 15, 98}, {8, PIKEDRAW + 2, 83, 49},
	{8, PIKEDRAW + 3, 144, 66}, {8, PIKEDRAW + 4, 197, 99}, {8, PIKEDRAW + 5, 216, 131},
	{1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76},
	{1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76},
	{1, EMPTY, 147, 76}
	},
	{{12, EXCALDRAW, 167, 130}, {12, EXCALDRAW + 1, 70, 117}, {12, EXCALDRAW + 2, 0, 128},
	{12, EXCALDRAW + 3, 0, 150}, {12, EXCALDRAW + 4, 4, 72}, {12, EXCALDRAW + 5, 38, 81},
	{12, EXCALDRAW + 6, 0, 44}, {12, EXCALDRAW + 7, 112, 0}, {12, EXCALDRAW + 8, 224, 0},
	{12, EXCALDRAW + 9, 198, 84}, {12, EXCALDRAW + 10, 186, 120}, {12, EXCALDRAW + 11, 188, 123},
	{1, EMPTY, 147, 76}
	},
	{{12, HALBERDDRAW, 183, 62}, {12, HALBERDDRAW + 1, 166, 10}, {12, HALBERDDRAW + 2, 173, 29},
	{12, HALBERDDRAW + 3, 114, 35}, {1, HALBERDATTACK1, 245, 22}, {1, HALBERDATTACK1, 245, 22},
	{1, HALBERDATTACK1, 245, 22}, {1, HALBERDATTACK1, 245, 22}, {1, HALBERDATTACK1, 245, 22},
	{1, HALBERDATTACK1, 245, 22}, {1, HALBERDATTACK1, 245, 22}, {1, HALBERDATTACK1, 245, 22},
	{1, EMPTY, 147, 76}
	}

};

const WEAPONINF weaponanimtics[MAXWEAPONS][MAXFRAMES] =
{
	// FIST
	{{10, RFIST, 216, 120}, {10, RFIST + 1, 166, 113}, {10, RFIST + 2, 156, 129},
	{10, RFIST + 3, 169, 151}, {10, RFIST + 4, 153, 124}, {10, RFIST + 5, 224, 133},
	{1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76},
	{1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76}
	},
	// KNIFE
	{{8, KNIFEATTACK, 189, 52}, {8, KNIFEATTACK + 1, 254, 68}, {8, EMPTY, 147, 76},
	{8, EMPTY, 80, 41}, {8, KNIFEATTACK + 2, 254, 69}, {8, KNIFEATTACK + 3, 218, 80},
	{8, KNIFEATTACK + 4, 137, 83}, {8, KNIFEATTACK + 5, 136, 100}, {8, KNIFEATTACK + 6, 126, 140},
	{8, KNIFEATTACK + 5, 136, 100}, {8, KNIFEATTACK + 4, 137, 83}, {8, KNIFEATTACK, 189, 52}
	},
	// GOBLINATTACK
	{{10, GOBSWORDATTACK, 243, 92}, {10, GOBSWORDATTACK + 1, 255, 68}, {10, GOBSWORDATTACK + 2, 279, 65},
	{10, GOBSWORDATTACK + 3, 238, 55}, {10, GOBSWORDATTACK + 4, 153, 52}, {10, GOBSWORDATTACK + 5, 129, 152},
	{10, GOBSWORDATTACK + 6, 90, 184}, {1, EMPTY, 297, 169}, {1, EMPTY, 275, 24},
	{1, EMPTY, 275, 24}, {1, EMPTY, 275, 24}, {1, EMPTY, 275, 24}
	},
	// MORNINGSTAR
	{{12, MORNINGSTAR, 193, 90}, {12, MORNINGSTAR + 1, 102, 133}, {12, MORNINGSTAR + 2, 77, 164},
	{12, MORNINGSTAR + 3, 239, 86}, {12, EMPTY, 299, 86}, {12, EMPTY, 107, 52},
	{12, MORNINGSTAR + 4, 197, 24}, {12, MORNINGSTAR + 5, 125, 124}, {12, MORNINGSTAR + 6, 109, 191},
	{1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76}
	},
	// SWORD
	{{8, SWORDATTACK, 229, 123}, {8, SWORDATTACK + 1, 221, 87}, {8, SWORDATTACK + 2, 193, 21},
	{8, SWORDATTACK + 3, 173, 0}, {8, SWORDATTACK + 4, 61, 0}, {8, SWORDATTACK + 5, 33, 48},
	{8, SWORDATTACK + 6, 126, 131}, {8, SWORDATTACK + 7, 297, 164}, {3, EMPTY, 147, 76},
	{3, EMPTY, 80, 41}, {3, EMPTY, 107, 52}, {3, EMPTY, 147, 76}
	},
	{{12, BIGAXEATTACK, 184, 123}, {12, BIGAXEATTACK + 1, 223, 112}, {12, BIGAXEATTACK + 2, 63, 151},
	{12, BIGAXEATTACK + 3, 91, 133}, {12, BIGAXEATTACK + 4, 127, 138}, {12, BIGAXEATTACK + 5, 106, 128},
	{12, BIGAXEATTACK + 6, 117, 49}, {12, BIGAXEATTACK + 7, 140, 0}, {12, BIGAXEATTACK + 8, 152, 47},
	{12, BIGAXEATTACK + 9, 166, 143}, {12, EMPTY, 107, 52}, {1, EMPTY, 147, 76}
	},
	// BOW
	{{8, BOWWALK, 75, 13}, {8, BOWWALK + 1, 90, 0}, {8, BOWWALK + 2, 70, 0},
	{8, BOWWALK + 3, 70, 0}, {6, BOWWALK + 4, 70, 0}, {4, BOWWALK + 5, 70, 0},
	{1, EMPTY, 126, 131}, {1, EMPTY, 297, 164}, {1, EMPTY, 147, 76},
	{1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76}
	},
	{{10, PIKEDRAW + 5, 216, 131}, {10, EMPTY, 80, 41}, {10, EMPTY, 107, 52}, {10, EMPTY, 147, 76},
	{10, PIKEATTACK1, 0, 47}, {10, PIKEATTACK1 + 1, 0, 0}, {10, PIKEATTACK1 + 2, 0, 0},
	{10, PIKEATTACK1 + 3, 73, 0}, {10, PIKEATTACK1 + 4, 130, 27}, {10, PIKEATTACK1 + 5, 138, 125},
	{12, EMPTY, 80, 41}, {1, EMPTY, 107, 52}
	},
	{{8, EXCALATTACK1, 98, 133}, {8, EXCALATTACK1 + 1, 123, 130}, {8, EXCALATTACK1 + 2, 125, 128},
	{8, EXCALATTACK1 + 3, 115, 82}, {8, EXCALATTACK1 + 4, 115, 6}, {8, EXCALATTACK1 + 5, 178, 0},
	{8, EXCALATTACK1 + 6, 155, 0}, {8, EXCALATTACK1 + 7, 143, 0}, {8, EXCALATTACK1 + 8, 90, 91},
	{8, EXCALATTACK1 + 9, 30, 159}, {1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}
	},
	{{12, HALBERDATTACK1, 245, 22}, {12, EMPTY, 107, 52}, {12, EMPTY, 147, 76},
	{12, HALBERDATTACK1 + 1, 249, 45}, {12, HALBERDATTACK1 + 2, 161, 60}, {12, HALBERDATTACK1 + 3, 45, 88},
	{12, EMPTY, 80, 41}, {12, HALBERDATTACK1 + 3, 45, 88}, {12, HALBERDATTACK1 + 2, 161, 60},
	{12, HALBERDATTACK1 + 1, 249, 45}, {12, EMPTY, 107, 52}, {1, EMPTY, 147, 76}
	}
};

//SCOTT
const WEAPONINF zweaponanimtics[MAXWEAPONS][MAXFRAMES] =
{
	// FIST
	{{10, RFIST, 216, 120}, {10, RFIST + 1, 166, 113}, {10, RFIST + 2, 156, 129},
	{10, RFIST + 3, 169, 151}, {10, RFIST + 4, 153, 124}, {10, RFIST + 5, 224, 133},
	{1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76},
	{1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76}
	},
	// ZKNIFE
	{{8, ZKNIFEATTACK, 189, 52}, {8, ZKNIFEATTACK + 1, 254, 68},
	{16, EMPTY, 147, 76}, {8, ZKNIFEATTACK + 1, 254, 68},
	{8, ZKNIFEATTACK + 2, 218, 80}, {8, ZKNIFEATTACK + 3, 137, 83},
	{8, ZKNIFEATTACK + 4, 136, 100}, {8, ZKNIFEATTACK + 5, 126, 140},
	{8, ZKNIFEATTACK + 4, 136, 100}, {8, ZKNIFEATTACK + 3, 137, 83},
	{8, ZKNIFEATTACK + 2, 218, 80}, {1, ZKNIFEATTACK, 189, 52}
	},
	// ZSHORTATTACK
	{{10, ZSHORTATTACK, 243, 68}, {10, ZSHORTATTACK + 4, 255, 50},
	{10, ZSHORTATTACK + 5, 279, 66}, {10, ZSHORTATTACK + 6, 238, 52},
	{10, ZSHORTATTACK + 7, 181, 49}, {10, ZSHORTATTACK + 8, 129, 141},
	{1, EMPTY, 90, 184}, {1, EMPTY, 297, 169}, {1, EMPTY, 275, 24},
	{1, EMPTY, 275, 24}, {1, EMPTY, 275, 24}, {1, EMPTY, 275, 24}
	},
	// ZSTARATTACK
	{{12, ZSTARATTACK, 193, 90}, {12, ZSTARATTACK + 3, 102, 128},
	{12, ZSTARATTACK + 4, 77, 159}, {12, ZSTARATTACK + 5, 239, 79},
	{12, EMPTY, 299, 86}, {12, EMPTY, 107, 52},
	{12, ZSTARATTACK + 6, 175, 19}, {12, ZSTARATTACK + 7, 125, 124},
	{12, ZSTARATTACK + 8, 109, 187},
	{1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76}
	},
	// SWORD
	{{8, SWORDATTACK, 229, 123}, {8, SWORDATTACK + 1, 221, 87}, {8, SWORDATTACK + 2, 193, 21},
	{8, SWORDATTACK + 3, 173, 0}, {8, SWORDATTACK + 4, 61, 0}, {8, SWORDATTACK + 5, 33, 48},
	{8, SWORDATTACK + 6, 126, 131}, {8, SWORDATTACK + 7, 297, 164}, {3, EMPTY, 147, 76},
	{3, EMPTY, 80, 41}, {3, EMPTY, 107, 52}, {3, EMPTY, 147, 76}
	},
	// ZAXEATTACK
	{{6, ZAXEATTACK, 179, 117}, {6, ZAXEATTACK + 6, 217, 107},
	{6, ZAXEATTACK + 7, 106, 146}, {6, ZAXEATTACK + 8, 94, 128},
	{6, ZAXEATTACK + 9, 123, 132}, {6, ZAXEATTACK + 10, 102, 134},
	{6, ZAXEATTACK + 11, 112, 45}, {6, ZAXEATTACK + 12, 102, 0},
	{6, ZAXEATTACK + 13, 68, 42}, {6, ZAXEATTACK + 14, 42, 138},
	{6, EMPTY, 107, 52}, {1, EMPTY, 147, 76}
	},
	// ZBOW
	{{8, ZBOWWALK, 75, 13}, {8, ZBOWATTACK, 90, 0}, {8, ZBOWATTACK + 1, 70, 0},
	{8, ZBOWATTACK + 2, 70, 0}, {6, ZBOWATTACK + 3, 70, 0}, {4, ZBOWATTACK + 4, 70, 0},
	{1, ZBOWWALK, 75, 13}, {1, ZBOWWALK, 75, 13}, {1, ZBOWWALK, 75, 13},
	{1, ZBOWWALK, 75, 13}, {1, ZBOWWALK, 75, 13}, {1, EMPTY, 147, 76}
	},
	// ZPIKE
	{{10, ZPIKEREADY + 5, 210, 127}, {10, EMPTY, 80, 41}, {10, EMPTY, 107, 52}, {10, EMPTY, 147, 76},
	{10, ZPIKEATTACK, 0, 43}, {10, ZPIKEATTACK + 1, 0, 0}, {10, ZPIKEATTACK + 2, 0, 0},
	{10, ZPIKEATTACK + 3, 45, 0}, {10, ZPIKEATTACK + 4, 51, 23}, {10, ZPIKEATTACK + 5, 59, 121},
	{12, EMPTY, 80, 41}, {1, EMPTY, 107, 52}
	},
	{{8, ZTWOHANDATTACK, 98, 133}, {8, ZTWOHANDATTACK + 6, 115, 130},
	{8, ZTWOHANDATTACK + 7, 125, 128}, {8, ZTWOHANDATTACK + 8, 116, 82},
	{8, ZTWOHANDATTACK + 9, 117, 9}, {8, ZTWOHANDATTACK + 10, 180, 0},
	{8, ZTWOHANDATTACK + 11, 174, 0}, {8, ZTWOHANDATTACK + 12, 166, 0},
	{8, ZTWOHANDATTACK + 13, 125, 90}, {8, ZTWOHANDATTACK + 14, 83, 166},
	{1, EMPTY, 30, 159}, {1, EMPTY, 80, 41}
	},
	// { { 12,ZHALBERDATTACK,173,29 },{6,EMPTY,107,52},
	// { 6,EMPTY,147,76},{ 12,ZHALBERDATTACK+3,117,0 },
	// { 12,ZHALBERDATTACK+4,245,0},{12,ZHALBERDATTACK+5,237,0},
	// { 6,EMPTY,80,41 },{12,ZHALBERDATTACK+6,115,0},
	// { 12,ZHALBERDATTACK+7,9,0 },{ 12,ZHALBERDATTACK+8,0,42 },
	// { 1,ZHALBERDATTACK,173,29 },{ 1,EMPTY,147,76 }
	// }
	{{12, ZHALBERDATTACK, 245, 30}, {12, EMPTY, 107, 52}, {12, EMPTY, 147, 76},
	{12, HALBERDATTACK1 + 1, 249, 45}, {12, HALBERDATTACK1 + 2, 161, 60}, {12, HALBERDATTACK1 + 3, 45, 88},
	{12, EMPTY, 80, 41}, {12, HALBERDATTACK1 + 3, 45, 88}, {12, HALBERDATTACK1 + 2, 161, 60},
	{12, HALBERDATTACK1 + 1, 249, 45}, {12, EMPTY, 107, 52}, {1, EMPTY, 147, 76}
	}


};

// SCOTT
const WEAPONINF zlefthandanimtics[5][MAXFRAMES] =
{
	 {{10, RFIST, 15, 121}, {10, RFIST + 1, 17, 114}, {10, RFIST + 2, 54, 131},
	 {10, RFIST + 3, 76, 152}, {10, RFIST + 4, 31, 126}, {10, RFIST + 5, 26, 135},
	 {1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76},
	 {1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76}
	 },
	// KNIFE
	{{8, KNIFEATTACK2, 0, 113}, {8, KNIFEATTACK2 + 1, 44, 111}, {8, KNIFEATTACK2 + 2, 119, 137},
	{8, KNIFEATTACK2 + 3, 187, 159}, {16, EMPTY, 136, 100}, {8, KNIFEATTACK2 + 3, 187, 159},
	{8, KNIFEATTACK2 + 2, 119, 137}, {8, KNIFEATTACK2 + 1, 44, 111}, {8, KNIFEATTACK2, 0, 113},
	{1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76}
	},
	// ZSHORTATTACK
	{{10, ZSHORTATTACK, 255, 50}, {10, ZSHORTATTACK + 1, 279, 66}, {10, ZSHORTATTACK + 2, 238, 52},
	{10, ZSHORTATTACK + 3, 181, 49}, {10, ZSHORTATTACK + 4, 129, 141}, {10, ZSHORTATTACK + 5, 70, 93},
	{10, EMPTY, 90, 184}, {1, EMPTY, 297, 169}, {1, EMPTY, 275, 24},
	{1, EMPTY, 275, 24}, {1, EMPTY, 275, 24}, {1, EMPTY, 275, 24}
	},
	// ZSTARATTACK2
	{{12, ZSTARATTACK2, 38, 141}, {12, ZSTARATTACK2 + 1, 0, 111}, {12, ZSTARATTACK2 + 2, 0, 91},
	{12, ZSTARATTACK2 + 3, 0, 47}, {12, EMPTY, 0, 24}, {1, EMPTY, 0, 24},
	{1, EMPTY, 0, 24}, {1, EMPTY, 0, 24}, {1, EMPTY, 0, 24},
	{1, EMPTY, 0, 24}, {1, EMPTY, 0, 24}, {1, EMPTY, 0, 24}
	},
	// ZSHORTATTACK2
	{{10, ZSHORTATTACK2, 238, 99}, {10, ZSHORTATTACK2 + 1, 202, 11}, {10, ZSHORTATTACK2 + 2, 182, 0},
	{10, ZSHORTATTACK2 + 3, 79, 13}, {10, ZSHORTATTACK2 + 4, 79, 13}, {10, ZSHORTATTACK2 + 5, 119, 123},
	{10, ZSHORTATTACK2 + 6, 295, 179}, {1, EMPTY, 275, 24}, {1, EMPTY, 275, 24},
	{1, EMPTY, 275, 24}, {1, EMPTY, 275, 24}, {1, EMPTY, 275, 24}
	}

};

const WEAPONINF weaponanimtics2[MAXWEAPONS][MAXFRAMES] =
{
	// FIST
	{{10, RFIST, 216, 120}, {10, RFIST + 1, 166, 113}, {10, RFIST + 2, 156, 129},
	{10, RFIST + 3, 169, 151}, {10, RFIST + 4, 153, 124}, {10, RFIST + 5, 224, 133},
	{1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76},
	{1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76}
	},
	// KNIFE
	{{8, KNIFEATTACK, 189, 52}, {8, KNIFEATTACK + 1, 254, 68}, {16, EMPTY, 147, 76},
	{8, KNIFEATTACK2, 206, 114}, {8, KNIFEATTACK2 + 1, 107, 112}, {8, KNIFEATTACK2 + 2, 22, 138},
	{8, KNIFEATTACK2 + 3, 0, 161}, {16, EMPTY, 136, 100}, {8, KNIFEATTACK2 + 3, 0, 161},
	{8, KNIFEATTACK2 + 2, 22, 138}, {8, KNIFEATTACK2 + 1, 107, 112}, {8, KNIFEATTACK2, 206, 114}
	},
	// GOBLINATTACK
	{{10, GOBSWORDATTACK2, 236, 99}, {10, GOBSWORDATTACK2 + 1, 202, 24}, {10, GOBSWORDATTACK2 + 2, 181, 0},
	{10, GOBSWORDATTACK2 + 3, 52, 12}, {10, GOBSWORDATTACK2 + 4, 72, 72}, {10, GOBSWORDATTACK2 + 5, 134, 139},
	{10, GOBSWORDATTACK2 + 6, 297, 169}, {1, EMPTY, 275, 24}, {1, EMPTY, 275, 24},
	{1, EMPTY, 275, 24}, {1, EMPTY, 275, 24}, {1, EMPTY, 275, 24}
	},
	// MORNINGATTACK2
	{{12, MORNINGATTACK2, 85, 136}, {12, MORNINGATTACK2 + 1, 34, 110}, {12, MORNINGATTACK2 + 2, 32, 91},
	{12, MORNINGATTACK2 + 3, 186, 47}, {12, MORNINGATTACK2 + 4, 275, 24}, {1, EMPTY, 275, 24},
	{1, EMPTY, 275, 24}, {1, EMPTY, 275, 24}, {1, EMPTY, 275, 24},
	{1, EMPTY, 275, 24}, {1, EMPTY, 275, 24}, {1, EMPTY, 275, 24}
	},
	// SWORD
	{{8, SWORDATTACK2 + 1, 195, 63}, {8, SWORDATTACK2 + 2, 250, 54}, {8, SWORDATTACK2 + 3, 275, 37},
	{16, EMPTY, 61, 0}, {8, SWORDATTACK2 + 4, 229, 66}, {8, SWORDATTACK2 + 5, 185, 0},
	{8, SWORDATTACK2 + 6, 158, 115}, {8, SWORDATTACK2 + 7, 57, 163}, {1, EMPTY, 57, 163},
	{1, EMPTY, 57, 163}, {1, EMPTY, 57, 163}, {1, EMPTY, 57, 163}
	},
	{{12, BIGAXEATTACK2, 200, 111}, {12, BIGAXEATTACK2 + 1, 5, 136}, {12, BIGAXEATTACK2 + 2, 69, 162},
	{12, BIGAXEATTACK2 + 3, 147, 164}, {12, BIGAXEATTACK2 + 4, 76, 152}, {12, BIGAXEATTACK2 + 5, 33, 95},
	{12, BIGAXEATTACK2 + 6, 0, 91}, {12, BIGAXEATTACK2 + 7, 0, 98}, {12, EMPTY, 147, 76},
	{1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76}
	},
	// BOW
	{{8, BOWWALK, 75, 13}, {8, BOWWALK + 1, 90, 0}, {8, BOWWALK + 2, 70, 0},
	{8, BOWWALK + 3, 70, 0}, {6, BOWWALK + 4, 70, 0}, {4, BOWWALK + 5, 70, 0},
	{1, EMPTY, 126, 131}, {1, EMPTY, 297, 164}, {1, EMPTY, 147, 76},
	{1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76}
	},
	{{10, PIKEATTACK2, 266, 147}, {10, PIKEATTACK2 + 1, 182, 117}, {10, PIKEATTACK2 + 2, 123, 84},
	{10, PIKEATTACK2 + 3, 7, 48}, {10, PIKEATTACK2 + 4, 0, 83}, {10, PIKEATTACK2 + 5, 0, 158},
	{10, PIKEATTACK2 + 6, 25, 117}, {10, PIKEATTACK2 + 7, 139, 93}, {10, PIKEATTACK2 + 8, 234, 75},
	{8, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76}
	},
	{{8, EXCALATTACK2, 0, 143}, {8, EXCALATTACK2 + 1, 0, 103}, {8, EXCALATTACK2 + 2, 0, 70},
	{8, EXCALATTACK2 + 3, 48, 0}, {8, EXCALATTACK2 + 4, 67, 0}, {8, EXCALATTACK2 + 5, 78, 21},
	{8, EXCALATTACK2 + 6, 165, 107}, {8, EXCALATTACK2 + 7, 260, 168}, {1, EMPTY, 130, 27},
	{1, EMPTY, 138, 125}, {1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}
	},
	{{12, HALBERDATTACK1, 245, 22}, {12, HALBERDATTACK2, 114, 35}, {12, HALBERDATTACK2 + 1, 105, 87},
	{12, HALBERDATTACK2 + 2, 54, 107}, {12, HALBERDATTACK2 + 3, 48, 102}, {1, HALBERDATTACK2 + 3, 48, 102},
	{1, HALBERDATTACK2 + 3, 48, 102}, {12, HALBERDATTACK2 + 2, 54, 107}, {12, HALBERDATTACK2 + 1, 105, 87},
	{1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76}
	}
};

//SCOTT
const WEAPONINF zweaponanimtics2[MAXWEAPONS][MAXFRAMES] =
{
	// FIST
	{{10, RFIST, 216, 120}, {10, RFIST + 1, 166, 113}, {10, RFIST + 2, 156, 129},
	{10, RFIST + 3, 169, 151}, {10, RFIST + 4, 153, 124}, {10, RFIST + 5, 224, 133},
	{1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76},
	{1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76}
	},
	// ZKNIFE
	{{8, ZKNIFEATTACK, 189, 52}, {8, ZKNIFEATTACK + 1, 254, 68}, {16, EMPTY, 147, 76},
	{8, ZKNIFEATTACK2, 206, 114}, {8, ZKNIFEATTACK2 + 1, 107, 112}, {8, ZKNIFEATTACK2 + 2, 22, 138},
	{8, ZKNIFEATTACK2 + 3, 0, 161}, {16, EMPTY, 136, 100}, {8, KNIFEATTACK2 + 3, 0, 161},
	{8, ZKNIFEATTACK2 + 2, 22, 138}, {8, ZKNIFEATTACK2 + 1, 107, 112}, {8, KNIFEATTACK2, 206, 114}
	},
	// ZSHORTATTACK2
	{{10, ZSHORTATTACK2, 238, 99}, {10, ZSHORTATTACK2 + 1, 202, 11},
	{10, ZSHORTATTACK2 + 2, 182, 0}, {10, ZSHORTATTACK2 + 3, 79, 13},
	{10, ZSHORTATTACK2 + 4, 40, 45}, {10, ZSHORTATTACK2 + 5, 119, 123},
	{10, ZSHORTATTACK2 + 6, 295, 179}, {1, EMPTY, 275, 24}, {1, EMPTY, 275, 24},
	{1, EMPTY, 275, 24}, {1, EMPTY, 275, 24}, {1, EMPTY, 275, 24}
	},
	// ZSTARATTACK2
	{{12, ZSTARATTACK2, 44, 110}, {12, ZSTARATTACK2 + 1, 26, 91}, {12, ZSTARATTACK2 + 2, 177, 38},
	{12, ZSTARATTACK2 + 3, 262, 11}, {12, EMPTY, 275, 24}, {1, EMPTY, 275, 24},
	{1, EMPTY, 275, 24}, {1, EMPTY, 275, 24}, {1, EMPTY, 275, 24},
	{1, EMPTY, 275, 24}, {1, EMPTY, 275, 24}, {1, EMPTY, 275, 24}
	},
	// SWORD
	{{8, SWORDATTACK2 + 1, 195, 63}, {8, SWORDATTACK2 + 2, 250, 54}, {8, SWORDATTACK2 + 3, 275, 37},
	{16, EMPTY, 61, 0}, {8, SWORDATTACK2 + 4, 229, 66}, {8, SWORDATTACK2 + 5, 185, 0},
	{8, SWORDATTACK2 + 6, 158, 115}, {8, SWORDATTACK2 + 7, 57, 163}, {1, EMPTY, 57, 163},
	{1, EMPTY, 57, 163}, {1, EMPTY, 57, 163}, {1, EMPTY, 57, 163}
	},
	// ZAXEATTACK2
	{{6, ZAXEATTACK2, 200, 111}, {6, ZAXEATTACK2 + 1, 5, 136}, {6, ZAXEATTACK2 + 2, 69, 162},
	{6, ZAXEATTACK2 + 3, 147, 164}, {6, ZAXEATTACK2 + 4, 76, 152}, {6, ZAXEATTACK2 + 5, 33, 95},
	{6, ZAXEATTACK2 + 6, 0, 91}, {6, ZAXEATTACK2 + 7, 0, 98}, {6, EMPTY, 147, 76},
	{1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76}
	},
	// ZBOW
   {{8, ZBOWWALK, 75, 13}, {8, ZBOWATTACK, 90, 0}, {8, ZBOWATTACK + 1, 70, 0},
	{8, ZBOWATTACK + 2, 70, 0}, {6, ZBOWATTACK + 3, 70, 0}, {4, ZBOWATTACK + 4, 70, 0},
	{1, ZBOWWALK, 75, 13}, {1, ZBOWWALK, 75, 13}, {1, ZBOWWALK, 75, 13},
	{1, ZBOWWALK, 75, 13}, {1, ZBOWWALK, 75, 13}, {1, EMPTY, 147, 76}
	},

	// ZPIKEATTACK2
	{{10, ZPIKEATTACK2, 266, 147}, {10, ZPIKEATTACK2 + 1, 182, 117}, {10, ZPIKEATTACK2 + 2, 123, 84},
	{10, ZPIKEATTACK2 + 3, 7, 48}, {10, ZPIKEATTACK2 + 4, 0, 83}, {10, ZPIKEATTACK2 + 5, 0, 158},
	{10, ZPIKEATTACK2 + 6, 25, 117}, {10, ZPIKEATTACK2 + 7, 139, 93}, {10, ZPIKEATTACK2 + 8, 234, 75},
	{8, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76}
	},
	// ZTWOHANDATTACK2
	{{8, ZTWOHANDATTACK2, 0, 143}, {8, ZTWOHANDATTACK2 + 1, 0, 103}, {8, ZTWOHANDATTACK2 + 2, 0, 70},
	{8, ZTWOHANDATTACK2 + 3, 41, 0}, {8, ZTWOHANDATTACK2 + 4, 54, 0}, {8, ZTWOHANDATTACK2 + 5, 166, 21},
	{8, ZTWOHANDATTACK2 + 6, 242, 108}, {8, EMPTY, 260, 168}, {1, EMPTY, 130, 27},
	{1, EMPTY, 138, 125}, {1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}
	},
	// ZHALBERDATTACK2
	{{12, HALBERDATTACK1, 245, 22}, {12, HALBERDATTACK2, 114, 35}, {12, HALBERDATTACK2 + 1, 105, 87},
	{12, HALBERDATTACK2 + 2, 54, 107}, {12, HALBERDATTACK2 + 3, 48, 102}, {1, HALBERDATTACK2 + 3, 48, 102},
	{1, HALBERDATTACK2 + 3, 48, 102}, {12, HALBERDATTACK2 + 2, 54, 107}, {12, HALBERDATTACK2 + 1, 105, 87},
	{1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76}
	}

};


const WEAPONINF lefthandanimtics[5][MAXFRAMES] =
{
	 {{10, RFIST, 15, 121}, {10, RFIST + 1, 17, 114}, {10, RFIST + 2, 54, 131},
	 {10, RFIST + 3, 76, 152}, {10, RFIST + 4, 31, 126}, {10, RFIST + 5, 26, 135},
	 {1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76},
	 {1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76}
	 },
	// KNIFE
	{{8, KNIFEATTACK2, 0, 113}, {8, KNIFEATTACK2 + 1, 44, 111}, {8, KNIFEATTACK2 + 2, 119, 137},
	{8, KNIFEATTACK2 + 3, 187, 159}, {16, EMPTY, 136, 100}, {8, KNIFEATTACK2 + 3, 187, 159},
	{8, KNIFEATTACK2 + 2, 119, 137}, {8, KNIFEATTACK2 + 1, 44, 111}, {8, KNIFEATTACK2, 0, 113},
	{1, EMPTY, 80, 41}, {1, EMPTY, 107, 52}, {1, EMPTY, 147, 76}
	},
	// GOBLINATTACK
	{{10, GOBSWORDATTACK, 243, 92}, {10, GOBSWORDATTACK + 1, 255, 68}, {10, GOBSWORDATTACK + 2, 279, 65},
	{10, GOBSWORDATTACK + 3, 238, 55}, {10, GOBSWORDATTACK + 4, 153, 52}, {10, GOBSWORDATTACK + 5, 129, 152},
	{10, GOBSWORDATTACK + 6, 90, 184}, {1, EMPTY, 297, 169}, {1, EMPTY, 275, 24},
	{1, EMPTY, 275, 24}, {1, EMPTY, 275, 24}, {1, EMPTY, 275, 24}
	},
	// MORNINGATTACK2

	{{12, MORNINGATTACK2, 38, 141}, {12, MORNINGATTACK2 + 1, 0, 111}, {12, MORNINGATTACK2 + 2, 0, 91},
	{12, MORNINGATTACK2 + 3, 0, 47}, {12, MORNINGATTACK2 + 4, 0, 24}, {1, EMPTY, 0, 24},
	{1, EMPTY, 0, 24}, {1, EMPTY, 0, 24}, {1, EMPTY, 0, 24},
	{1, EMPTY, 0, 24}, {1, EMPTY, 0, 24}, {1, EMPTY, 0, 24}

	},

	// GOBLINATTACK2
	{{10, GOBSWORDATTACK2, 236, 99}, {10, GOBSWORDATTACK2 + 1, 202, 24}, {10, GOBSWORDATTACK2 + 2, 181, 0},
	{10, GOBSWORDATTACK2 + 3, 52, 12}, {10, GOBSWORDATTACK2 + 4, 72, 72}, {10, GOBSWORDATTACK2 + 5, 134, 139},
	{10, GOBSWORDATTACK2 + 6, 297, 169}, {1, EMPTY, 275, 24}, {1, EMPTY, 275, 24},
	{1, EMPTY, 275, 24}, {1, EMPTY, 275, 24}, {1, EMPTY, 275, 24}
	}

};


END_WH_NS
