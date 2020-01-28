
#ifndef __I_SYSTEM__
#define __I_SYSTEM__

#include "basics.h"
#include <thread>
#include "tarray.h"
#include "zstring.h"
#include "utf8.h"

struct ticcmd_t;
struct WadStuff;

// [RH] Detects the OS the game is running under.
void I_DetectOS (void);

// Called by DoomMain.
void I_Init (void);

// Return a seed value for the RNG.
unsigned int I_MakeRNGSeed();
void I_ShowFatalError(const char* msg);


//
// Called by D_DoomLoop,
// called before processing any tics in a frame
// (just after displaying a frame).
// Time consuming syncronous operations
// are performed here (joystick reading).
// Can call D_PostEvent.
//
void I_StartFrame (void);


//
// Called by D_DoomLoop,
// called before processing each tic in a frame.
// Quick syncronous operations are performed here.
// Can call D_PostEvent.
void I_StartTic (void);

// Asynchronous interrupt functions should maintain private queues
// that are read by the synchronous functions
// to be converted into events.

// Either returns a null ticcmd,
// or calls a loadable driver to build it.
// This ticcmd will then be modified by the gameloop
// for normal input.
ticcmd_t *I_BaseTiccmd (void);


// Called by M_Responder when quit is selected.
// Clean exit, displays sell blurb.
void I_Quit (void);


void I_Tactile (int on, int off, int total);

// Set the mouse cursor. The texture must be 32x32.
class FTexture;
bool I_SetCursor(FTexture *cursor);

// Repaint the pre-game console
void I_PaintConsole (void);

void I_DebugPrint (const char *cp);

// Print a console string
void I_PrintStr (const char *cp);

// Set the title string of the startup window
void I_SetIWADInfo ();

// Pick from multiple IWADs to use
int I_PickIWad (WadStuff *wads, int numwads, bool queryiwad, int defaultiwad);

// The ini could not be saved at exit
bool I_WriteIniFailed ();

// [RH] Used by the display code to set the normal window procedure
void I_SetWndProc();

// [RH] Checks the registry for Steam's install path, so we can scan its
// directories for IWADs if the user purchased any through Steam.
TArray<FString> I_GetSteamPath();

// [GZ] Same deal for GOG paths
TArray<FString> I_GetGogPaths();

// Damn Microsoft for doing Get/SetWindowLongPtr half-assed. Instead of
// giving them proper prototypes under Win32, they are just macros for
// Get/SetWindowLong, meaning they take LONGs and not LONG_PTRs.
#ifdef _WIN64
typedef long long WLONG_PTR;
#elif _MSC_VER
typedef _W64 long WLONG_PTR;
#else
typedef long WLONG_PTR;
#endif

// Wrapper for GetLongPathName
FString I_GetLongPathName(const FString &shortpath);

// Directory searching routines

// Mirror WIN32_FIND_DATAA in <winbase.h>
#ifndef MAX_PATH
#define MAX_PATH 260
#endif
#ifndef PATH_MAX
#define PATH_MAX 260
#endif

struct findstate_t
{
private:
	struct WinData
	{
		uint32_t Attribs;
		uint32_t Times[3 * 2];
		uint32_t Size[2];
		uint32_t Reserved[2];
		wchar_t Name[MAX_PATH];
		wchar_t AltName[14];
	};
	WinData FindData;
	FString UTF8Name;

	friend void *I_FindFirst(const char *filespec, findstate_t *fileinfo);
	friend int I_FindNext(void *handle, findstate_t *fileinfo);
	friend const char *I_FindName(findstate_t *fileinfo);
	friend int I_FindAttr(findstate_t *fileinfo);
};

void *I_FindFirst (const char *filespec, findstate_t *fileinfo);
int I_FindNext (void *handle, findstate_t *fileinfo);
int I_FindClose (void *handle);

const char *I_FindName(findstate_t *fileinfo);
inline int I_FindAttr(findstate_t *fileinfo)
{
	return fileinfo->FindData.Attribs;
}

#define FA_RDONLY	0x00000001
#define FA_HIDDEN	0x00000002
#define FA_SYSTEM	0x00000004
#define FA_DIREC	0x00000010
#define FA_ARCH		0x00000020

int I_GetNumaNodeCount();
int I_GetNumaNodeThreadCount(int numaNode);
void I_SetThreadNumaNode(std::thread &thread, int numaNode);

int I_ReadRegistryValue(char const * const SubKey, char const * const Value, char * const Output, size_t * OutputSize);

#endif
