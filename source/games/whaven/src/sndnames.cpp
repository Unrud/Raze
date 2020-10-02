#include "ns.h"
#include "gamecontrol.h"

int S_THUNDER1 = 0;
int S_THUNDER2 = 1;
int S_THUNDER3 = 2;
int S_THUNDER4 = 3;
int S_WINDLOOP1 = 4;
int S_WAVELOOP1 = 5;
int S_LAVALOOP1 = 6;
int S_FIRELOOP1 = 7;
int S_STONELOOP1 = 8;
int S_BATSLOOP = 9;
int S_PLRWEAPON0 = 10;
int S_PLRWEAPON1 = 11;
int S_PLRWEAPON2 = 12;
int S_PLRWEAPON3 = 13;
int S_PLRWEAPON4 = 14;
int S_GOBLIN1 = 15;
int S_GOBLIN2 = 16;
int S_GOBLIN3 = 17;
int S_GOBPAIN1 = 18;
int S_GOBPAIN2 = 19;
int S_GOBDIE1 = 20;
int S_GOBDIE2 = 21;
int S_GOBDIE3 = 22;
int S_KSNARL1 = 23;
int S_KSNARL2 = 24;
int S_KSNARL3 = 25;
int S_KSNARL4 = 26;
int S_KPAIN1 = 27;
int S_KPAIN2 = 28;
int S_KDIE1 = 29;
int S_KDIE2 = 30;
int S_DEMON1 = 31;
int S_DEMON2 = 32;
int S_DEMON3 = 33;
int S_DEMON4 = 34;
int S_DEMON5 = 35;
int S_DEMONDIE1 = 36;
int S_DEMONDIE2 = 37;
int S_MSNARL1 = 38;
int S_MSNARL2 = 39;
int S_MSNARL3 = 40;
int S_MSNARL4 = 41;
int S_MPAIN1 = 42;
int S_MDEATH1 = 43;
int S_DRAGON1 = 44;
int S_DRAGON2 = 45;
int S_DRAGON3 = 46;
int S_RIP1 = 47;
int S_RIP2 = 48;
int S_RIP3 = 49;
int S_SKELHIT1 = 50;
int S_SKELHIT2 = 51;
int S_SKELETONDIE = 52;
int S_GUARDIAN1 = 53;
int S_GUARDIAN2 = 54;
int S_GUARDIANPAIN1 = 55;
int S_GUARDIANPAIN2 = 56;
int S_GUARDIANDIE = 57;
int S_WISP = 58;
int S_WISP2 = 59;
int S_SPLASH1 = 60;
int S_SPLASH2 = 61;
int S_SPLASH3 = 62;
int S_SPLASH4 = 63;
int S_SPLASH5 = 64;
int S_SPLASH6 = 65;
int S_WILLOWDIE = 66;
int S_FATWITCHDIE = 67;
int S_JUDY1 = 68;
int S_JUDY2 = 69;
int S_JUDY3 = 70;
int S_JUDY4 = 71;
int S_JUDYDIE = 72;
int S_SKULLWITCH1 = 73;
int S_SKULLWITCH2 = 74;
int S_SKULLWITCH3 = 75;
int S_SKULLWITCHDIE = 76;
int S_GRONDEATHA = 77;
int S_GRONDEATHB = 78;
int S_GRONDEATHC = 79;
int S_CHAIN1 = 80;
int S_FLAME1 = 81;
int S_GRONPAINA = 82;
int S_GRONPAINB = 83;
int S_GRONPAINC = 84;
int S_CLUNK = 85;
int S_DEMONTHROW = 86;
int S_WITCHTHROW = 87;
int S_DOOR1 = 88;
int S_DOOR2 = 89;
int S_DOOR3 = 90;
int S_CREAKDOOR1 = 91;
int S_CREAKDOOR2 = 92;
int S_CREAKDOOR3 = 93;
int S_STING1 = 94;
int S_STING2 = 95;
int S_POTION1 = 96;
int S_GENTHROW = 97;
int S_GENSWING = 98;
int S_ARROWHIT = 99;
int S_WALLHIT1 = 100;
int S_GONG = 101;
int S_SPELL1 = 102;
int S_FREEZE = 103;
int S_FREEZEDIE = 104;
int S_TRAP1 = 105;
int S_TRAP2 = 106;
int S_RATS1 = 107;
int S_RATS2 = 108;
int S_WINDLOOP2 = 109;
int S_BREATH1 = 110;
int S_BREATH2 = 111;
int S_PUSH1 = 112;
int S_PUSH2 = 113;
int S_PLRPAIN1 = 114;
int S_PLRPAIN2 = 115;
int S_GORE1 = 116;
int S_GORE2 = 117;
int S_GORE1A = 118;
int S_GORE1B = 119;
int S_DEADSTEP = 120;
int S_HEARTBEAT = 121;
int S_SOFTCHAINWALK = 122;
int S_SOFTCREAKWALK = 123;
int S_LOUDCHAINWALK = 124;
int S_GRATEWALK = 125;
int S_SCARYDUDE = 126;
int S_WATERY = 127;
int S_GLASSBREAK1 = 128;
int S_GLASSBREAK2 = 129;
int S_GLASSBREAK3 = 130;
int S_TREASURE1 = 131;
int S_SWORD1 = 132;
int S_SWORD2 = 133;
int S_SWORDCLINK1 = 134;
int S_SWORDCLINK2 = 135;
int S_SWORDCLINK3 = 136;
int S_SWORDCLINK4 = 137;
int S_SOCK1 = 138;
int S_SOCK2 = 139;
int S_SOCK3 = 140;
int S_SOCK4 = 141;
int S_KOBOLDHIT = 142;
int S_SPIDERBITE = 143;
int S_FIREBALL = 144;
int S_WOOD1 = 145;
int S_CHAINDOOR1 = 146;
int S_PULLCHAIN1 = 147;
int S_PICKUPAXE = 148;
int S_EXPLODE = 149;
int S_SKELSEE = 150;
int S_BARRELBREAK = 151;
int S_WARP = 152;
int S_PICKUPFLAG = 155;
int S_DROPFLAG = 156;
int S_LAUGH = 157;
int S_DRINK = 158;
int S_PAGE = 159;
int S_BOTTLES = 160;
int S_CRACKING = 161;
int S_PLRDIE1 = 162;
int S_FATLAUGH = 163;

void InitSoundNames()
{
	if (isWh2()) {
		S_WINDLOOP1 = 3;
		S_WAVELOOP1 = 4;
		S_LAVALOOP1 = 5;
		S_FIRELOOP1 = 6;
		S_STONELOOP1 = 7;
		S_BATSLOOP = 8;
		S_PLRWEAPON0 = 9;
		S_PLRWEAPON1 = 10;
		S_PLRWEAPON2 = 11;
		S_PLRWEAPON3 = 12;
		S_PLRWEAPON4 = 13;
		S_KSNARL1 = 14;
		S_KSNARL2 = 15;
		S_KSNARL3 = 16;
		S_KSNARL4 = 17;
		S_KPAIN1 = 18;
		S_KPAIN2 = 19;
		S_KDIE1 = 20;
		S_KDIE2 = 21;
		S_DEMON1 = 22;
		S_DEMON2 = 23;
		S_DEMON3 = 24;
		S_DEMON4 = 25;
		S_DEMON5 = 26;
		S_DEMONDIE1 = 27;
		S_DEMONDIE2 = 28;
		S_MSNARL1 = 29;
		S_MSNARL2 = 30;
		S_MSNARL3 = 31;
		S_MSNARL4 = 32;
		S_MPAIN1 = 33;
		S_MDEATH1 = 34;
		S_RIP1 = 35;
		S_RIP2 = 36;
		S_RIP3 = 37;
		S_SKELHIT1 = 38;
		S_SKELHIT2 = 39;
		S_SKELETONDIE = 40;
		S_SKELSEE = 41;
		S_GUARDIAN1 = 42;
		S_GUARDIAN2 = 43;
		S_GUARDIANPAIN1 = 44;
		S_GUARDIANPAIN2 = 45;
		S_GUARDIANDIE = 46;
		S_WISP = 47;
		S_WISP2 = 48;
		S_SPLASH1 = 49;
		S_SPLASH2 = 50;
		S_SPLASH3 = 51;
		S_SPLASH4 = 52;
		S_SPLASH5 = 53;
		S_WILLOWDIE = 54;
		S_JUDY1 = 55;
		S_JUDYDIE = 56;
		S_CHAIN1 = 57;
		S_FLAME1 = 58;
		S_CLUNK = 59;
		S_DEMONTHROW = 60;
		S_DOOR1 = 61;
		S_DOOR2 = 62;
		S_DOOR3 = 63;
		S_CREAKDOOR1 = 64;
		S_CREAKDOOR2 = 65;
		S_CREAKDOOR3 = 66;
		S_STING1 = 67;
		S_STING2 = 68;
		S_POTION1 = 69;
		S_GENTHROW = 70;
		S_GENSWING = 71;
		S_ARROWHIT = 72;
		S_WALLHIT1 = 73;
		S_GONG = 74;
		S_SPELL1 = 75;
		S_FREEZE = 76;
		S_FREEZEDIE = 77;
		S_TRAP1 = 78;
		S_TRAP2 = 79;
		S_RATS1 = 80;
		S_RATS2 = 81;
		S_WINDLOOP2 = 82;
		S_BREATH1 = 83;
		S_BREATH2 = 84;
		S_PUSH1 = 85;
		S_PUSH2 = 86;
		S_PLRPAIN1 = 87;
		S_PLRPAIN2 = 88;
		S_GORE1 = 89;
		S_GORE2 = 90;
		S_GORE1A = 91;
		S_GORE1B = 92;
		S_DEADSTEP = 93;
		S_HEARTBEAT = 94;
		S_SOFTCHAINWALK = 95;
		S_SOFTCREAKWALK = 96;
		S_LOUDCHAINWALK = 97;
		S_SCARYDUDE = 98;
		S_WATERY = 99;
		S_GLASSBREAK1 = 100;
		S_GLASSBREAK2 = 101;
		S_GLASSBREAK3 = 102;
		S_TREASURE1 = 103;
		S_SWORD1 = 104;
		S_SWORD2 = 105;
		S_SWORDCLINK1 = 106;
		S_SWORDCLINK2 = 107;
		S_SWORDCLINK3 = 108;
		S_SWORDCLINK4 = 109;
		S_SOCK1 = 110;
		S_SOCK2 = 111;
		S_SOCK3 = 112;
		S_SOCK4 = 113;
		S_KOBOLDHIT = 114;
		S_FIREBALL = 115;
		S_PULLCHAIN1 = 116;
		S_PICKUPAXE = 117;
		S_EXPLODE = 118;
		S_BARRELBREAK = 119;
		S_WARP = 120;
		S_PICKUPFLAG = 121;
		S_DROPFLAG = 122;
		S_LAUGH = 123;
		S_DRINK = 124;
		S_PAGE = 125;
		S_BOTTLES = 126;
		S_CRACKING = 127;
		S_PLRDIE1 = 128;
		S_GRONDEATHA = 136;
		S_GRONDEATHB = 137;
		S_GRONDEATHC = 138;
		S_GRONPAINA = 142;
	}
}