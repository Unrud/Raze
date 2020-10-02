#include "ns.h"
#include "gamecontrol.h"

BEGIN_WH_NS

short KNIFEREADY;
short KNIFEATTACK;
short RFIST;
short SWORDATTACK;
short MORNINGSTAR;
short BOWREADY;
short BOWREADYEND;
short BOWWALK;
short KNIFEATTACK2;
short SWORDPULL;
short SWORDATTACK2;
short MORNINGATTACK2;
short MUMEDUSA;
short MUTWOHANDS;
short BMUTWOHANDS;
short GOBSWORDPULL;
short GOBSWORDATTACK;
short GOBSWORDATTACK2;
short BIGAXEATTACK;
short BIGAXEATTACK2;
short BIGAXEDRAW;
short HALBERDATTACK1;
short HALBERDATTACK2;
short HALBERDDRAW;
short PIKEDRAW;
short PIKEATTACK1;
short EXCALATTACK1;
short EXCALATTACK2;
short EXCALDRAW;
short BIGAXEDRAW9;
short BIGAXEDRAW10;
short GEARS2START;
short HORNEDSKULL;
short THEFONT;
short CRYSTALSTAFF;
short TORCH;
short WEAPON1;
short WEAPON1A;
short AMULETOFTHEMIST;
short WEAPON2;
short BRASSKEY;
short BLACKKEY;
short GLASSKEY;
short IVORYKEY;
short NEWCHUNK;
short BOWLOFFIRE;
short SPAWNFIREBALL;
short PENTAGRAM;
short THEHORN;
short BOW;
short SWINGGATE3;
short PLATEARMOR;
short HELMET;
short CHAINMAIL;
short SCROLLSCARE;
short SCROLLNUKE;
short SCROLLFLY;
short SCROLLFIREBALL;
short SCROLLFREEZE;
short SCROLLNIGHT;
short SCROLLMAGIC;
short SCROLLOPEN;
short LEATHERARMOR;
short QUIVER;
short SWINGGATE4;
short SWINGGATE5;
short SMOKEFX;
short STANDINTORCH;
short PENTADOOR3;
short PENTADOOR4;
short PENTADOOR5;
short PENTADOOR6;
short PENTADOOR7;
short SCARY;
short FISH;
short LEVERUP;
short LEVERDOWN;
short SPAWNJAVLIN;
short RAT;
short GUARDIAN;
short GUARDIANATTACK;
short DART;
short WEAPON4;
short WEAPON6;
short WEAPON5;
short WEAPON5B;
short THROWHALBERD;
short WEAPON7;
short THROWPIKE;
short EXPLO2;
short SHATTERVASE;
short SHATTERVASE2;
short SHATTERVASE3;
short HANGMAN;
short SKELETON;
short SKELETONATTACK;
short SKELETONSKULL;
short SKELETONUP;
short SKELETONDIE;
short SKELETONDEAD;
short BONECHUNK1;
short BONECHUNKEND;
short PIKEATTACK2;
short GOBWEAPON;
short SFLASKBLUE;
short SFLASKGREEN;
short SFLASKOCHRE;
short SFLASKRED;
short SFLASKTAN;
short SFLASKBLACK;
short SHEALTHFONT;
short SSCOREFONT;
short SPOTIONFONT;
short SPOTIONBACKPIC;
short SPOTIONARROW;
short SSPELLBOOKBLANK;
short SSPELLBOOK2;
short SSPELLBOOK3;
short SSPELLBOOK4;
short SSPELLBOOK5;
short SSPELLBOOK6;
short SSPELLBOOK7;
short SSPELLBOOK8;
short SARROWS;
short SPLAYERLVL;
short SSTATUSBAR;
short SKEYBLANK;
short SKEYBRASS;
short SKEYBLACK;
short SKEYGLASS;
short SKEYIVORY;
short SHEALTHBACK;
short SSCOREBACKPIC;
short SNDEFFECT;
short SNDLOOP;
short SNDLOOPOFF;
short BROWNCHUNKSTART;
short GREYCHUNKSTART;
short REDCHUNKSTART;
short GREENCHUNKSTART;
short TANCHUNKSTART;
short WILLOW;
short SPIKES;
short STHEFLAG;
short GRONHALATTACK;
short GRONHALATTACKEND;
short GROLHALREADY;
short GRONHALREADYEND;
short GRONHAL;
short GRONHALPAIN;
short GRONHALDIE;
short GRONSWATTACK;
short GRONSW;
short GRONSWPAIN;
short GRONSWDIE;
short GRONMUATTACK;
short GRONDIE;
short GRONDEAD;
short GRONMU;
short GRONMUPAIN;
short GRONMUDIE;
short GRONSHIELD;
short SHIELD;

void InitNames()
{
	if(!isWh2()) {
		KNIFEREADY = 1249;
		KNIFEATTACK = 1261;
		RFIST = 1268;
		SWORDATTACK = 1291;
		MORNINGSTAR = 1306;
		BOWREADY = 1313;
		BOWREADYEND = 1319;
		BOWWALK = 1323;
		KNIFEATTACK2 = 1329;
		SWORDPULL = 1333;
		SWORDATTACK2 = 1340;
		MORNINGATTACK2 = 1348;
		MUMEDUSA = 1353;
		MUTWOHANDS = 1363;
		BMUTWOHANDS = 1378;
		GOBSWORDPULL = 1390;
		GOBSWORDATTACK = 1397;
		GOBSWORDATTACK2 = 1404;
		BIGAXEATTACK = 1411;
		BIGAXEATTACK2 = 1421;
		BIGAXEDRAW = 1429;
		HALBERDATTACK1 = 1438;
		HALBERDATTACK2 = 1443;
		HALBERDDRAW = 1447;
		PIKEDRAW = 1451;
		PIKEATTACK1 = 1457;
		EXCALATTACK1 = 1463;
		EXCALATTACK2 = 1473;
		EXCALDRAW = 1481;
		BIGAXEDRAW9 = 1494;
		BIGAXEDRAW10 = 1495;
		GEARS2START = 1498;
		HORNEDSKULL = 1503;
		THEFONT = 1511;
		CRYSTALSTAFF = 1551;
		TORCH = 1554;
		WEAPON1 = 1567;
		WEAPON1A = 1571;
		AMULETOFTHEMIST = 1575;
		WEAPON2 = 1583;
		BRASSKEY = 1624;
		BLACKKEY = 1632;
		GLASSKEY = 1640;
		IVORYKEY = 1648;
		NEWCHUNK = 1664;
		BOWLOFFIRE = 1705;
		SPAWNFIREBALL = 1718;
		PENTAGRAM = 1760;
		THEHORN = 1768;
		BOW = 1776;
		SWINGGATE3 = 1789;
		PLATEARMOR = 1794;
		HELMET = 1802;
		CHAINMAIL = 1810;
		SCROLLSCARE = 1818;
		SCROLLNUKE = 1826;
		SCROLLFLY = 1834;
		SCROLLFIREBALL = 1842;
		SCROLLFREEZE = 1850;
		SCROLLNIGHT = 1858;
		SCROLLMAGIC = 1866;
		SCROLLOPEN = 1874;
		LEATHERARMOR = 1882;
		QUIVER = 1890;
		SWINGGATE4 = 1898;
		SWINGGATE5 = 1899;
		SMOKEFX = 1904;
		STANDINTORCH = 1908;
		PENTADOOR3 = 1927;
		PENTADOOR4 = 1928;
		PENTADOOR5 = 1929;
		PENTADOOR6 = 1930;
		PENTADOOR7 = 1931;
		SCARY = 1933;
		FISH = 1945;
		LEVERUP = 1947;
		LEVERDOWN = 1949;
		SPAWNJAVLIN = 1958;
		RAT = 1962;
		GUARDIAN = 1994;
		GUARDIANATTACK = 2002;
		DART = 2010;
		WEAPON4 = 2027;
		WEAPON6 = 2039;
		WEAPON5 = 2047;
		WEAPON5B = 2055;
		THROWHALBERD = 2066;
		WEAPON7 = 2067;
		THROWPIKE = 2071;
		EXPLO2 = 2096;
		SHATTERVASE = 2124;
		SHATTERVASE2 = 2131;
		SHATTERVASE3 = 2138;
		HANGMAN = 2145;
		SKELETON = 2156;
		SKELETONATTACK = 2181;
		SKELETONSKULL = 2186;
		SKELETONUP = 2191;
		SKELETONDIE = 2192;
		SKELETONDEAD = 2198;
		BONECHUNK1 = 2199;
		BONECHUNKEND = 2208;
		PIKEATTACK2 = 2209;
		GOBWEAPON = 2218;
		SFLASKBLUE = 2240;
		SFLASKGREEN = 2241;
		SFLASKOCHRE = 2242;
		SFLASKRED = 2243;
		SFLASKTAN = 2244;
		SFLASKBLACK = 2245;
		SHEALTHFONT = 2246;
		SSCOREFONT = 2256;
		SPOTIONFONT = 2266;
		SPOTIONBACKPIC = 2280;
		SPOTIONARROW = 2281;
		SSPELLBOOKBLANK = 2286;
		SSPELLBOOK2 = 2294;
		SSPELLBOOK3 = 2302;
		SSPELLBOOK4 = 2310;
		SSPELLBOOK5 = 2317;
		SSPELLBOOK6 = 2324;
		SSPELLBOOK7 = 2332;
		SSPELLBOOK8 = 2340;
		SARROWS = 2348;
		SPLAYERLVL = 2349;
		SSTATUSBAR = 2358;
		SKEYBLANK = 2359;
		SKEYBRASS = 2360;
		SKEYBLACK = 2361;
		SKEYGLASS = 2362;
		SKEYIVORY = 2363;
		SHEALTHBACK = 2365;
		SSCOREBACKPIC = 2368;
		SNDEFFECT = 2369;
		SNDLOOP = 2370;
		SNDLOOPOFF = 2371;
		BROWNCHUNKSTART = 2387;
		GREYCHUNKSTART = 2395;
		REDCHUNKSTART = 2403;
		GREENCHUNKSTART = 2411;
		TANCHUNKSTART = 2419;
		WILLOW = 2427;
		SPIKES = 2488;
		STHEFLAG = 2491;
		GRONHALATTACK = 2504;
		GRONHALATTACKEND = 2508;
		GROLHALREADY = 2509;
		GRONHALREADYEND = 2510;
		GRONHAL = 2539;
		GRONHALPAIN = 2559;
		GRONHALDIE = 2560;
		GRONSWATTACK = 2561;
		GRONSW = 2581;
		GRONSWPAIN = 2601;
		GRONSWDIE = 2602;
		GRONMUATTACK = 2603;
		GRONDIE = 2633;
		GRONDEAD = 2639;
		GRONMU = 2640;
		GRONMUPAIN = 2660;
		GRONMUDIE = 2661;
		GRONSHIELD = 2680;
		SHIELD = 2684;
	} else { //WH2
		KNIFEREADY = 1248;
		KNIFEATTACK = 1260;
		RFIST = 1267;
		SWORDATTACK = 1290;
		MORNINGSTAR = 1305;
		BOWREADY = 1312;
		BOWREADYEND = 1318;
		BOWWALK = 1322;
		KNIFEATTACK2 = 1328;
		SWORDPULL = 1332;
		SWORDATTACK2 = 1339;
		MORNINGATTACK2 = 1347;
		MUMEDUSA = 1352;
		MUTWOHANDS = 1362;
		BMUTWOHANDS = 1377;
		GOBSWORDPULL = 1389;
		GOBSWORDATTACK = 1396;
		GOBSWORDATTACK2 = 1403;
		BIGAXEATTACK = 1410;
		BIGAXEATTACK2 = 1420;
		BIGAXEDRAW = 1428;
		HALBERDATTACK1 = 1437;
		HALBERDATTACK2 = 1442;
		HALBERDDRAW = 1446;
		PIKEDRAW = 1450;
		PIKEATTACK1 = 1456;
		EXCALATTACK1 = 1462;
		EXCALATTACK2 = 1472;
		EXCALDRAW = 1480;
		BIGAXEDRAW9 = 1493;
		BIGAXEDRAW10 = 1494;
		GEARS2START = 1497;
		HORNEDSKULL = 1502;
		THEFONT = 1510;
		CRYSTALSTAFF = 1550;
		TORCH = 1553;
		WEAPON1 = 1566;
		WEAPON1A = 1570;
		AMULETOFTHEMIST = 1574;
		WEAPON2 = 1582;
		BRASSKEY = 1623;
		BLACKKEY = 1631;
		GLASSKEY = 1639;
		IVORYKEY = 1647;
		NEWCHUNK = 1663;
		BOWLOFFIRE = 1704;
		SPAWNFIREBALL = 1717;
		PENTAGRAM = 1759;
		THEHORN = 1767;
		BOW = 1775;
		SWINGGATE3 = 1788;
		PLATEARMOR = 1793;
		HELMET = 1801;
		CHAINMAIL = 1809;
		SCROLLSCARE = 1817;
		SCROLLNUKE = 1825;
		SCROLLFLY = 1833;
		SCROLLFIREBALL = 1841;
		SCROLLFREEZE = 1849;
		SCROLLNIGHT = 1857;
		SCROLLMAGIC = 1865;
		SCROLLOPEN = 1873;
		LEATHERARMOR = 1881;
		QUIVER = 1889;
		SWINGGATE4 = 1897;
		SWINGGATE5 = 1898;
		SMOKEFX = 1903;
		STANDINTORCH = 1907;
		PENTADOOR3 = 1926;
		PENTADOOR4 = 1927;
		PENTADOOR5 = 1928;
		PENTADOOR6 = 1929;
		PENTADOOR7 = 1930;
		SCARY = 1932;
		FISH = 1944;
		LEVERUP = 1946;
		LEVERDOWN = 1948;
		SPAWNJAVLIN = 1957;
		RAT = 1961;
		GUARDIAN = 1993;
		GUARDIANATTACK = 2001;
		DART = 2009;
		WEAPON4 = 2026;
		WEAPON6 = 2038;
		WEAPON5 = 2046;
		WEAPON5B = 2054;
		THROWHALBERD = 2065;
		WEAPON7 = 2066;
		THROWPIKE = 2070;
		EXPLO2 = 2095;
		SHATTERVASE = 2123;
		SHATTERVASE2 = 2130;
		SHATTERVASE3 = 2137;
		HANGMAN = 2144;
		SKELETON = 2155;
		SKELETONATTACK = 2180;
		SKELETONSKULL = 2185;
		SKELETONUP = 2190;
		SKELETONDIE = 2191;
		SKELETONDEAD = 2197;
		BONECHUNK1 = 2198;
		BONECHUNKEND = 2207;
		PIKEATTACK2 = 2208;
		GOBWEAPON = 2217;
		SFLASKBLUE = 2239;
		SFLASKGREEN = 2240;
		SFLASKOCHRE = 2241;
		SFLASKRED = 2242;
		SFLASKTAN = 2243;
		SFLASKBLACK = 2244;
		SHEALTHFONT = 2245;
		SSCOREFONT = 2255;
		SPOTIONFONT = 2265;
		SPOTIONBACKPIC = 2279;
		SPOTIONARROW = 2280;
		SSPELLBOOKBLANK = 2285;
		SSPELLBOOK2 = 2293;
		SSPELLBOOK3 = 2301;
		SSPELLBOOK4 = 2309;
		SSPELLBOOK5 = 2316;
		SSPELLBOOK6 = 2323;
		SSPELLBOOK7 = 2331;
		SSPELLBOOK8 = 2339;
		SARROWS = 2347;
		SPLAYERLVL = 2348;
		SSTATUSBAR = 2357;
		SKEYBLANK = 2358;
		SKEYBRASS = 2359;
		SKEYBLACK = 2360;
		SKEYGLASS = 2361;
		SKEYIVORY = 2362;
		SHEALTHBACK = 2364;
		SSCOREBACKPIC = 2367;
		SNDEFFECT = 2368;
		SNDLOOP = 2369;
		SNDLOOPOFF = 2370;
		BROWNCHUNKSTART = 2386;
		GREYCHUNKSTART = 2394;
		REDCHUNKSTART = 2402;
		GREENCHUNKSTART = 2410;
		TANCHUNKSTART = 2418;
		WILLOW = 2426;
		SPIKES = 2487;
		STHEFLAG = 2490;
		GRONHALATTACK = 2502;
		GRONHALATTACKEND = 2506;
		GROLHALREADY = 2507;
		GRONHALREADYEND = 2508;
		GRONHAL = 2537;
		GRONHALPAIN = 2557;
		GRONHALDIE = 2558;
		GRONSWATTACK = 2559;
		GRONSW = 2579;
		GRONSWPAIN = 2599;
		GRONSWDIE = 2600;
		GRONMUATTACK = 2601;
		GRONDIE = 2631;
		GRONDEAD = 2637;
		GRONMU = 2638;
		GRONMUPAIN = 2658;
		GRONMUDIE = 2659;
		GRONSHIELD = 2678;
		SHIELD = 2682;
	}
}

END_WH_NS
