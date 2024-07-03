//========= Copyright © 1996-2002, Valve LLC, All rights reserved. ============
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================

// exefuncs.h
#ifndef EXEFUNCS_H
#define EXEFUNCS_H

/*
	_Smiley:

	The only original fields from HLSDK here are the following:
	fMMX, iCPUMhz, VID_ForceLockState, VID_ForceUnlockedAndReturnState, ErrorMessage, Sys_Printf

	All other fields were reverse-engineered by me from HLDS 3.0.1.6 (Linux) and HLDS 3.1.0.7 (Linux).
	HLDS versions start numbering patches from 3 instead of 1, so you can literally take this as structures intended for 1.0.1.6 and 1.1.0.7 WON builds.
	
	Those reverse-engineered fields that have no parameters and use a void as return type - mean that it is more likely that only function names have been added by me, 
	so they may need further reverse-engineering.

	If the reverse-engineered fields even have parameters specified, but the return type is void, then this may mean that most likely I did not reverse the return type and instead used void for the default stub.
	This is because from these function symbols you can only demangle the parameters, the return type can only be accurately extracted from DWARF info (if present) or presumably found by decompilers in tools like Ghidra.

	The return types and argument names for some of the reverse-engineered fields were taken from the leaked Source SDK 2003 (public/launcher_int.h)
	Also, you can then look at the Quake code to get the likely return types and parameters for some of the other reverse-engineered fields (because I too lazy to do it for now LOL).

	If param_ is specified in the name of the parameters, it means that this field was only reverse-engineered, e.g. do not have a reference in the Source SDK, so we cannot know the actual name of parameters.

	And I noticed that the functions at the end of the structure are noticeably different between both WON builds, this is the reason why I decided to make two structures.
*/

// Engine hands this to DLLs for functionality callbacks
typedef struct exefuncs_hlds_3016_s
{
	int			fMMX; // gHasMMXTechnology
	int			iCPUMhz; // gProcessorSpeed
	void		(*VID_LockBuffer)(void); // VID_LockBuffer
	void		(*VID_UnlockBuffer)(void); // VID_UnlockBuffer
	void		(*VID_Shutdown)(void); // VID_Shutdown
	void		(*VID_Update)(void); // VID_Update
	void		(*VID_ForceLockState)(int lk); // VID_ForceLockState
	int			(*VID_ForceUnlockedAndReturnState)(void); // VID_ForceUnlockedAndReturnState
	void		(*VID_SetDefaultMode)(void); // VID_SetDefaultMode
	void		(*VID_GetExtModeDescription)(void); // VID_GetExtModeDescription
	void		(*VID_GetVID)(void); // VID_GetVID
	void		(*D_BeginDirectRect)(void); // D_BeginDirectRect
	void		(*D_EndDirectRect)(void); // D_EndDirectRect
	void		(*AppActivate)(void); // AppActivate
	void		(*CDAudio_Play)(void); // CDAudio_Play
	void		(*CDAudio_Pause)(void); // CDAudio_Pause
	void		(*CDAudio_Resume)(void); // CDAudio_Resume
	void		(*CDAudio_Update)(void); // CDAudio_Update
	void		(*Launcher_InitCmds)(void); // Launcher_InitCmds__Fv
	void		(*ErrorMessage)(int nLevel, const char *pszErrorMessage); // ErrorMessage__FiPCc
	void		(*D_SurfaceCacheForRes)(void); // D_SurfaceCacheForRes
	void		(*Sys_Printf)(char *fmt, ...); // Sys_Printf, Console_Printf
	void		(*UTIL_GetCDKey)(char *pszCDKey, int *nLen, int *bDedicated); // UTIL_GetCDKey__FPcPiPi, Launcher_GetCDKey
	void		(*UTIL_GetClientID)(void *param_1); // UTIL_GetClientID__FPv, Launcher_GetClientID
	void		(*UTIL_GetUUID)(void *param_1, int *param_2, int *param_3); // UTIL_GetUUID__FPvPiPi
	void		(*Launcher_VerifyMessage)(int param_1, unsigned char *param_2, int param_3, char *param_4, int param_5, unsigned char *param_6); // Launcher_VerifyMessage__FiPUciPciT1, Launcher_VerifyMessage
	void		(*Launcher_GetCertificate)(void *param_1, int *param_2); // Launcher_GetCertificate__FPvPi, Launcher_GetCertificate
	void		(*Launcher_RequestNewClientCertificate)(void); // Launcher_RequestNewClientCertificate__Fv, Launcher_RequestNewClientCertificate
	void		(*Launcher_ValidateClientCertificate)(void *param_1, int param_2); // Launcher_ValidateClientCertificate__FPvi, Launcher_ValidateClientCertificate
	void		(*Launcher_AuthRequest)(void *param_1, int param_2, struct authchallenge_t *param_3); // Launcher_AuthRequest__FPviP15authchallenge_t, Launcher_AuthRequest
	void		(*Launcher_AuthChallenge1)(void *param_1, int param_2, struct authchallenge_t *param_3); // Launcher_AuthChallenge1__FPviP15authchallenge_t, Launcher_AuthChallenge1
	void		(*Launcher_AuthChallenge2)(void *param_1, int param_2, struct authchallenge_t *param_3); // Launcher_AuthChallenge2__FPviP15authchallenge_t, Launcher_AuthChallenge2
	void		(*Launcher_AuthComplete)(void *param_1, int param_2, struct authchallenge_t *param_3); // Launcher_AuthComplete__FPviP15authchallenge_t, Launcher_AuthComplete
	void		(*Launcher_DecodeAuthComplete)(void *param_1, int param_2, struct authchallenge_t *param_3); // Launcher_DecodeAuthComplete__FPviP15authchallenge_t, Launcher_DecodeAuthComplete
	void		(*Launcher_DeleteAuthData)(struct authchallenge_t *param_1); // Launcher_DeleteAuthData__FP15authchallenge_t, Launcher_DeleteAuthData
	void		(*Launcher_GetConnectionKey)(void *param_1, int *param_2); // Launcher_GetConnectionKey__FPvPi, Launcher_GetConnectionKey
	void		(*Launcher_BFEncrypt)(void *param_1, int param_2, void *param_3, int *param_4); // Launcher_BFEncrypt__FPviT0Pi, Launcher_BFEncrypt
	void		(*Launcher_GetRawBFKey)(void *param_1, void *param_2, int *param_3); // Launcher_GetRawBFKey__FPvT0Pi, Launcher_GetRawBFKey
	int			(*Launcher_IsValidCD)(void); // Launcher_IsValidCD

	// In HLDS 3.0.1.6 (Linux) there is a global variable 'ef' that uses such struct and which sizeof is 164 - based on what Elf32_Sym struct shows in the .symtab section
	// Right now we are at 156 offset.
	// Therefore, most likely there should still be some two unknown pointer functions below.
} exefuncs_hlds_3016_t;

typedef struct exefuncs_hlds_3107_s
{
	int			fMMX; // gHasMMXTechnology
	int			iCPUMhz; // gProcessorSpeed
	void		(*VID_LockBuffer)(void); // VID_LockBuffer
	void		(*VID_UnlockBuffer)(void); // VID_UnlockBuffer
	void		(*VID_Shutdown)(void); // VID_Shutdown
	void		(*VID_Update)(void); // VID_Update
	void		(*VID_ForceLockState)(int lk); // VID_ForceLockState
	int			(*VID_ForceUnlockedAndReturnState)(void); // VID_ForceUnlockedAndReturnState
	void		(*VID_SetDefaultMode)(void); // VID_SetDefaultMode
	void		(*VID_GetExtModeDescription)(void); // VID_GetExtModeDescription
	void		(*VID_GetVID)(void); // VID_GetVID
	void		(*D_BeginDirectRect)(void); // D_BeginDirectRect
	void		(*D_EndDirectRect)(void); // D_EndDirectRect
	void		(*AppActivate)(void); // Launcher_AppActivate
	void		(*CDAudio_Play)(void); // Launcher_CDAudio_Play
	void		(*CDAudio_Pause)(void); // Launcher_CDAudio_Pause
	void		(*CDAudio_Resume)(void); // Launcher_CDAudio_Resume
	void		(*CDAudio_Update)(void); // Launcher_CDAudio_Update
	void		(*Launcher_InitCmds)(void); // Launcher_InitCmds
	void		(*ErrorMessage)(int nLevel, const char *pszErrorMessage); // Launcher_ErrorMessage
	void		(*D_SurfaceCacheForRes)(void); // D_SurfaceCacheForRes
	void		(*Sys_Printf)(char *fmt, ...); // Sys_Printf, Console_Printf, Launcher_ConsolePrintf
	void		(*UTIL_GetCDKey)(char *pszCDKey, int *nLen, int *bDedicated); // Launcher_GetCDKey
	void		(*unknown1)(void);
	void		(*unknown2)(void);
	void		(*unknown3)(void);
	int			(*Launcher_IsValidCD)(void); // Launcher_IsValidCD
	void		(*Launcher_ChangeGameDirectory)(const char *pszNewDirectory); // Launcher_ChangeGameDirectory
	void		(*unknown4)(void);
	void		(*Launcher_AuthFailed)(void); // Launcher_AuthFailed
} exefuncs_hlds_3107_t;

#endif
