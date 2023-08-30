#pragma once

#include "../sptlib-wrapper.hpp"
#include <SPTLib/IHookableNameFilter.hpp>
#include "../hud_custom.hpp"

class ClientDLL : public IHookableNameFilter
{
	/*
		All exported client functions in pre-HLSDK 2.0 versions:

		HUD_Init, HUD_Redraw, HUD_Reset, HUD_UpdateClientData, HUD_VidInit, Initialize
	*/

	HOOK_DECL(void, __cdecl, PM_Jump) // PM_Jump (non-exported)
	HOOK_DECL(void, __cdecl, PM_PlayerMove, qboolean server) // PM_PlayerMove (non-exported)
	HOOK_DECL(void, __cdecl, PM_PreventMegaBunnyJumping) // PM_PreventMegaBunnyJumping (non-exported)
	HOOK_DECL(int, __cdecl, PM_ClipVelocity, float in[3], float normal[3], float out[3], float overbounce) // PM_ClipVelocity (non-exported)
	HOOK_DECL(void, __cdecl, PM_WaterMove) // PM_WaterMove (non-exported)
	HOOK_DECL(void, __cdecl, PM_Move, struct playermove_s* ppmove, int server) // PM_Move (non-exported)
	HOOK_DECL(void, __cdecl, V_CalcRefdef, ref_params_t* pparams) // V_CalcRefdef (exported)
	HOOK_DECL(void, __cdecl, HUD_Init) // HUD_Init (exported)
	HOOK_DECL(void, __cdecl, HUD_VidInit) // HUD_VidInit (exported)
	HOOK_DECL(void, __cdecl, HUD_Reset) // HUD_Reset (exported)
	HOOK_DECL(void, __cdecl, HUD_Redraw, float time, int intermission) // HUD_Redraw (exported)
	HOOK_DECL(void, __cdecl, HUD_PostRunCmd, local_state_s* from, local_state_s* to, usercmd_s* cmd, int runfuncs, double time, unsigned int random_seed) // HUD_PostRunCmd (exported)
	HOOK_DECL(void, __cdecl, HUD_Frame, double time) // HUD_Frame (exported)
	HOOK_DECL(void, __cdecl, HUD_DrawTransparentTriangles) // HUD_DrawTransparentTriangles (exported)
	HOOK_DECL(int, __cdecl, HUD_Key_Event, int down, int keynum, const char* pszCurrentBinding) // HUD_Key_Event (exported)
	HOOK_DECL(int, __cdecl, HUD_UpdateClientData, client_data_t* pcldata, float flTime) // HUD_UpdateClientData (exported)
	HOOK_DECL(void, __fastcall, CStudioModelRenderer__StudioCalcAttachments, void* thisptr) // ?StudioCalcAttachments@CStudioModelRenderer@@UAEXXZ (non-exported, + 0x1C in CStudioModelRenderer vtable)
	HOOK_DECL(void, __cdecl, CStudioModelRenderer__StudioCalcAttachments_Linux, void* thisptr) // _ZN20CStudioModelRenderer21StudioCalcAttachmentsEv
	HOOK_DECL(void, __cdecl, VectorTransform, float *in1, float *in2, float *out) // _Z15VectorTransformPKfPA4_fPf (Linux)
	HOOK_DECL(void, __cdecl, EV_GetDefaultShellInfo, event_args_t *args, float *origin, float *velocity, float *ShellVelocity, float *ShellOrigin,
	          float *forward, float *right, float *up, float forwardScale, float upScale, float rightScale) // _Z22EV_GetDefaultShellInfoP12event_args_sPfS1_S1_S1_S1_S1_S1_fff (Linux)
	HOOK_DECL(void, __fastcall, CStudioModelRenderer__StudioSetupBones, void* thisptr) // ?StudioSetupBones@CStudioModelRenderer@@UAEXXZ (non-exported, + 0x18 in CStudioModelRenderer vtable)
	HOOK_DECL(void, __cdecl, CStudioModelRenderer__StudioSetupBones_Linux, void* thisptr) // _ZN20CStudioModelRenderer16StudioSetupBonesEv
	HOOK_DECL(int, __cdecl, HUD_AddEntity, int type, cl_entity_s *ent, char *modelname) // HUD_AddEntity (exported)
	HOOK_DECL(int, __cdecl, CL_IsThirdPerson) // CL_IsThirdPerson (exported)
	HOOK_DECL(void, __fastcall, CStudioModelRenderer__StudioRenderModel, void* thisptr) // ?StudioRenderModel@CStudioModelRenderer@@UAEXXZ (non-exported, + 0x48 in CStudioModelRenderer vtable)
	HOOK_DECL(void, __cdecl, CStudioModelRenderer__StudioRenderModel_Linux, void* thisptr) // _ZN20CStudioModelRenderer17StudioRenderModelEv
	HOOK_DECL(void, __cdecl, ScaleColors, int* r, int* g, int* b, int a) // _Z11ScaleColorsRiS_S_i (Linux)
	HOOK_DECL(int, __fastcall, HistoryResource__DrawAmmoHistory, void *thisptr, int edx, float flTime) // ?DrawAmmoHistory@HistoryResource@@QAEHM@Z (non-exported)
	HOOK_DECL(int, __cdecl, HistoryResource__DrawAmmoHistory_Linux, void *thisptr, float flTime) // _ZN15HistoryResource15DrawAmmoHistoryEf
	HOOK_DECL(int, __fastcall, CHudHealth__DrawDamage, void *thisptr, int edx, float flTime) // ?DrawDamage@CHudHealth@@AAEHM@Z (non-exported)
	HOOK_DECL(int, __cdecl, CHudHealth__DrawDamage_Linux, void *thisptr, float flTime) // _ZN10CHudHealth10DrawDamageEf
	HOOK_DECL(int, __fastcall, CHudHealth__DrawPain, void *thisptr, int edx, float flTime) // ?DrawPain@CHudHealth@@AAEHM@Z (non-exported)
	HOOK_DECL(int, __cdecl, CHudHealth__DrawPain_Linux, void *thisptr, float flTime) // _ZN10CHudHealth8DrawPainEf
	HOOK_DECL(void, __fastcall, CHudFlashlight__drawNightVision, void* thisptr)
	HOOK_DECL(void, __cdecl, CHudFlashlight__drawNightVision_Linux, void* thisptr) // _ZN14CHudFlashlight15drawNightVisionEv (Game: Half-Life Opposing Force)
	HOOK_DECL(bool, __fastcall, CHud__DrawHudNightVision, void *thisptr, int edx, float flTime)
	HOOK_DECL(bool, __cdecl, CHud__DrawHudNightVision_Linux, void *thisptr, float flTime) // _ZN4CHud18DrawHudNightVisionEf (Game: Counter-Strike Condition Zero Deleted Scenes)
	HOOK_DECL(bool, __fastcall, CHud__DrawHudFiberCamera, void *thisptr, int edx, float flTime)
	HOOK_DECL(bool, __cdecl, CHud__DrawHudFiberCamera_Linux, void *thisptr, float flTime) // _ZN4CHud18DrawHudFiberCameraEf (Game: Counter-Strike Condition Zero Deleted Scenes)
	HOOK_DECL(int, __fastcall, CHudIcons__Draw, void *thisptr, int edx, float flTime)
	HOOK_DECL(int, __cdecl, CHudIcons__Draw_Linux, void *thisptr, float flTime) // _ZN9CHudIcons4DrawEf (Game: Counter-Strike Condition Zero Deleted Scenes)
	HOOK_DECL(void, __cdecl, V_PunchAxis, int axis, float punch) // _Z11V_PunchAxisif (Linux)
	HOOK_DECL(void, __cdecl, HUD_Shutdown) // HUD_Shutdown (exported)
	//HOOK_DECL(void, __cdecl, PM_Duck) // PM_Duck (non-exported)
	//HOOK_DECL(void, __cdecl, PM_UnDuck) // PM_UnDuck (non-exported)
	//HOOK_DECL(int, __fastcall, CHud__DrawHudNumber, void* thisptr, int edx, int x, int y, int iFlags, int iNumber, int r, int g, int b) // ?DrawHudNumber@CHud@@QAEHHHHHHHH@Z (non-exported)
	//HOOK_DECL(int, __cdecl, CHud__DrawHudNumber_Linux, void* thisptr, int x, int y, int iFlags, int iNumber, int r, int g, int b) // _ZN4CHud13DrawHudNumberEiiiiiii
	//HOOK_DECL(int, __fastcall, CHudHealth__Draw, void* thisptr, int edx, float flTime) // ?Draw@CHudHealth@@UAEHM@Z (non-exported)
	//HOOK_DECL(int, __cdecl, CHudHealth__Draw_Linux, void* thisptr, float flTime) // _ZN10CHudHealth4DrawEf
	//HOOK_DECL(int, __fastcall, WeaponsResource__CountAmmo, void *thisptr, int edx, int iId) // ?CountAmmo@WeaponsResource@@QAEHH@Z (non-exported)
	//HOOK_DECL(int, __cdecl, WeaponsResource__CountAmmo_Linux, void *thisptr, int iId) // _ZN15WeaponsResource9CountAmmoEi
	//HOOK_DECL(int, __fastcall, CHudAmmo__Draw, void *thisptr, int edx, float flTime) // ?Draw@CHudAmmo@@UAEHM@Z (non-exported)
	//HOOK_DECL(int, __cdecl, CHudAmmo__Draw_Linux, void *thisptr, float flTime) // _ZN8CHudAmmo4DrawEf

public:
	static ClientDLL& GetInstance()
	{
		static ClientDLL instance;
		return instance;
	}

	virtual void Hook(const std::wstring& moduleName, void* moduleHandle, void* moduleBase, size_t moduleLength, bool needToIntercept);
	virtual void Unhook();
	virtual void Clear();

	void ResetSeedsQueued() { SeedsQueued = 0; }

	inline bool IsInsideKeyEvent() const { return insideKeyEvent; }

	cl_enginefunc_t *pEngfuncs; // cl_enginefuncs (struct: cl_enginefunc_t)

	Vector last_vieworg;
	Vector last_viewangles;
	Vector last_viewforward;
	Vector last_viewright;
	Vector last_viewup;

	void StudioAdjustViewmodelAttachments(Vector &vOrigin);

	bool DoesGameDirMatch(const char *game);
	bool DoesGameDirContain(const char *game);

	size_t GetMapName(char* dest, size_t count);
	bool DoesMapNameMatch(const char *map);
	bool DoesMapNameContain(const char *map);

	bool orig_forcehltv_found = false;
	bool orig_righthand_not_found = false;

	unsigned char custom_r, custom_g, custom_b;
	bool custom_hud_color_set = false;
	bool bxt_hud_color_set = false;
	bool bxt_hud_color_fill = false;

	unsigned char colorize_entities_r, colorize_entities_g, colorize_entities_b;
	bool colorize_entities_set = false;

	bool insideDrawAmmoHistory = false;
	bool insideDrawHealthDamage = false;
	bool insideDrawHealthPain = false;
	bool insideDrawNightVision = false;
	bool insideDrawFiberCameraCZDS = false;
	bool insideDrawHudIconsCZDS = false;
	float drawdamage_flTime;

	unsigned short last_buttons;

	// When set to false, the mouse won't move the camera.
	void SetMouseState(bool active);

	Vector AnglesToForward(const Vector &angles);

	void SetAngleSpeedCap(bool capped);

	void SetSpeedScaling(bool scaled);

	void FileBase(const char *in, char *out);
	void ConvertToLowerCase(const char *str);

	bool hlsdk_tables = true; // Only change it if the engine tables is completely differs

	// WRAPPER FUNCTIONS - START

	void GetViewAngles(float *va);
	void SetViewAngles(float *va);
	cl_entity_t *GetLocalPlayer();
	const char *GetLevelName();
	const char *GetLevelNameCl();
	const char *GetLevelNameSv();
	cl_entity_t *GetViewModel();
	cl_entity_t *GetCurrentEntity();
	float GetTimeCl();
	const char *GetGameDirectory();
	void DrawSetTextColor(float r, float g, float b);
	int DrawString(int x, int y, const char* str);
	Vector GetRefdefViewAngles();
	Vector GetRefdefViewOrigin();
	//Vector GetRefdefSimVelocity();
	//Vector GetRefdefSimOrigin();
	float GetFOV();
	float GetFOVFromCvar();

	// WRAPPER FUNCTIONS - END

	void SetupTraceVectors(float start[3], float end[3]);

private:
	ClientDLL() : IHookableNameFilter({ L"client.dll", L"client.so" }) {};
	ClientDLL(const ClientDLL&);
	void operator=(const ClientDLL&);

protected:
	typedef void(__cdecl *_IN_ActivateMouse) (); // IN_ActivateMouse (exported)
	_IN_ActivateMouse ORIG_IN_ActivateMouse;
	typedef void(__cdecl *_IN_DeactivateMouse) (); // IN_DeactivateMouse (exported)
	_IN_DeactivateMouse ORIG_IN_DeactivateMouse;

	void FindStuff();
	bool FindHUDFunctions();
	void RegisterCVarsAndCommands();
	void AddHudElem(void* pHudElem);

	void **ppmove;
	ptrdiff_t offOldbuttons;
	ptrdiff_t offOnground;
	ptrdiff_t offIUser1;

	ptrdiff_t offBhopcap;
	ptrdiff_t pBhopcapWindows;
	byte originalBhopcapInsn[6];

	ptrdiff_t pCS_AngleSpeedCap;
	ptrdiff_t pCS_AngleSpeedCap_Linux;

	ptrdiff_t pCS_SpeedScaling;
	ptrdiff_t pCS_SpeedScaling_Linux;

	ptrdiff_t offVectorTransform;

	bool cantJumpNextTime;

	unsigned SeedsQueued;

	bool insideKeyEvent;
	bool insideStudioCalcAttachmentsViewmodel;

	ptrdiff_t offpCurrentEntity; // m_pCurrentEntity (class: CStudioModelRenderer)
	ptrdiff_t offpStudioHeader; // m_pStudioHeader (class: CStudioModelRenderer)
};
