#pragma once;
#include "c_cvars.h"

EXTERN_CVAR(Bool, cl_crosshair)
EXTERN_CVAR(Bool, cl_automsg)
EXTERN_CVAR(Int, cl_autoaim)
EXTERN_CVAR(Bool, cl_autorun)
EXTERN_CVAR(Bool, cl_runmode)
EXTERN_CVAR(Bool, cl_autosave)
EXTERN_CVAR(Bool, cl_autosavedeletion)
EXTERN_CVAR(Int, cl_maxautosaves)
EXTERN_CVAR(Int, cl_autovote)
EXTERN_CVAR(Int, cl_cheatmask)
EXTERN_CVAR(Bool, cl_obituaries)
EXTERN_CVAR(Bool, cl_democams)
EXTERN_CVAR(Bool, cl_idplayers)
EXTERN_CVAR(Bool, cl_showcoords)
EXTERN_CVAR(Bool, cl_viewbob)
EXTERN_CVAR(Bool, cl_weaponsway)
EXTERN_CVAR(Bool, cl_viewhbob)
EXTERN_CVAR(Bool, cl_viewvbob)
EXTERN_CVAR(Bool, cl_interpolate)
EXTERN_CVAR(Bool, cl_slopetilting)
EXTERN_CVAR(Bool, cl_showweapon)
EXTERN_CVAR(Int, cl_weaponswitch)
EXTERN_CVAR(Int, cl_crosshairscale)

EXTERN_CVAR(Bool, demorec_diffcompress_cvar)
EXTERN_CVAR(Bool, demorec_synccompress_cvar)
EXTERN_CVAR(Bool, demorec_seeds_cvar)
EXTERN_CVAR(Bool, demoplay_diffs)
EXTERN_CVAR(Bool, demoplay_showsync)
EXTERN_CVAR(Bool, demorec_diffs_cvar)
EXTERN_CVAR(Bool, demorec_force_cvar)
EXTERN_CVAR(Int, demorec_difftics_cvar)

EXTERN_CVAR(Bool, snd_ambience)
EXTERN_CVAR(Bool, snd_enabled)
EXTERN_CVAR(Bool, snd_tryformats)
EXTERN_CVAR(Bool, snd_doppler)
EXTERN_CVAR(Bool, mus_enabled)
EXTERN_CVAR(Bool, mus_restartonload)
EXTERN_CVAR(Bool, mus_redbook)
EXTERN_CVAR(Bool, snd_reversestereo)
EXTERN_CVAR(Int, snd_fxvolume)
EXTERN_CVAR(Int, snd_mixrate)
EXTERN_CVAR(Int, snd_numchannels)
EXTERN_CVAR(Int, snd_numvoices)
EXTERN_CVAR(Int, snd_speech)
EXTERN_CVAR(Int, mus_volume)

EXTERN_CVAR(Int, hud_layout)
EXTERN_CVAR(Int, hud_scale)
EXTERN_CVAR(Int, hud_custom)
EXTERN_CVAR(Bool, hud_stats)
EXTERN_CVAR(Bool, hud_showmapname)
EXTERN_CVAR(Int, r_fov)

EXTERN_CVAR(Bool, r_horizcenter)
EXTERN_CVAR(Int, r_drawweapon)
EXTERN_CVAR(Int, r_showfps)
EXTERN_CVAR(Int, r_showfpsperiod)
EXTERN_CVAR(Int, r_ambientlight)
EXTERN_CVAR(Int, r_shadows)


EXTERN_CVAR(Bool, in_joystick)
EXTERN_CVAR(Bool, in_mouse)
EXTERN_CVAR(Bool, in_aimmode)
EXTERN_CVAR(Int, in_mousebias)
EXTERN_CVAR(Int, in_mousedeadzone)
EXTERN_CVAR(Bool, in_mouseflip)
EXTERN_CVAR(Bool, in_mousemode)
EXTERN_CVAR(Bool, in_mousesmoothing)
extern int32_t g_MyAimMode;
EXTERN_CVAR(Bool, in_mousemode)

extern float r_ambientlightrecip;
extern int hud_statusbarrange;	// will be set by the game's configuration setup.
bool G_ChangeHudLayout(int direction);
bool G_CheckAutorun(bool button);
void G_LoadConfig(const char*);
void G_SaveConfig();
