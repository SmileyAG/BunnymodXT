#include "../stdafx.hpp"

#include "../sptlib-wrapper.hpp"
#include <SPTLib/MemUtils.hpp>
#include <SPTLib/Hooks.hpp>
#include "ClientDLL.hpp"
#include "ServerDLL.hpp"
#include "HwDLL.hpp"
#include "../patterns.hpp"
#include "../cvars.hpp"
#include "../hud_custom.hpp"
#include "../triangle_drawing.hpp"
#include "../discord_integration.hpp"
#include <GL/gl.h>

// Linux hooks.
#ifndef _WIN32
extern "C" void __cdecl HUD_Init()
{
	return ClientDLL::HOOKED_HUD_Init();
}

extern "C" void __cdecl HUD_VidInit()
{
	return ClientDLL::HOOKED_HUD_VidInit();
}

extern "C" void __cdecl HUD_Reset()
{
	return ClientDLL::HOOKED_HUD_Reset();
}

extern "C" void __cdecl HUD_Redraw(float time, int intermission)
{
	return ClientDLL::HOOKED_HUD_Redraw(time, intermission);
}

extern "C" void __cdecl HUD_PostRunCmd(local_state_s* from, local_state_s* to, usercmd_s* cmd, int runfuncs, double time, unsigned int random_seed)
{
	return ClientDLL::HOOKED_HUD_PostRunCmd(from, to, cmd, runfuncs, time, random_seed);
}

extern "C" void __cdecl HUD_Frame(double time)
{
	return ClientDLL::HOOKED_HUD_Frame(time);
}

extern "C" void __cdecl V_CalcRefdef(ref_params_t* pparams)
{
	return ClientDLL::HOOKED_V_CalcRefdef(pparams);
}

extern "C" void __cdecl HUD_DrawTransparentTriangles()
{
	return ClientDLL::HOOKED_HUD_DrawTransparentTriangles();
}

extern "C" int __cdecl HUD_Key_Event(int down, int keynum, const char* pszCurrentBinding)
{
	return ClientDLL::HOOKED_HUD_Key_Event(down, keynum, pszCurrentBinding);
}

extern "C" int __cdecl HUD_UpdateClientData(client_data_t* pcldata, float flTime)
{
	return ClientDLL::HOOKED_HUD_UpdateClientData(pcldata, flTime);
}

extern "C" void __cdecl _ZN20CStudioModelRenderer21StudioCalcAttachmentsEv(void *thisptr)
{
	return ClientDLL::HOOKED_StudioCalcAttachments_Linux(thisptr);
}

extern "C" void __cdecl _Z15VectorTransformPKfPA4_fPf(float *in1, float *in2, float *out)
{
	return ClientDLL::HOOKED_VectorTransform(in1, in2, out);
}

extern "C" void __cdecl _Z22EV_GetDefaultShellInfoP12event_args_sPfS1_S1_S1_S1_S1_S1_fff(event_args_t *args, float *origin, float *velocity, float *ShellVelocity, float *ShellOrigin,
																						 float *forward, float *right, float *up, float forwardScale, float upScale, float rightScale)
{
	return ClientDLL::HOOKED_EV_GetDefaultShellInfo(args, origin, velocity, ShellVelocity, ShellOrigin, forward, right, up, forwardScale, upScale, rightScale);
}

extern "C" void __cdecl _ZN20CStudioModelRenderer16StudioSetupBonesEv(void *thisptr)
{
	return ClientDLL::HOOKED_CStudioModelRenderer__StudioSetupBones_Linux(thisptr);
}

extern "C" int __cdecl HUD_AddEntity(int type, cl_entity_s* ent, char* modelname)
{
	return ClientDLL::HOOKED_HUD_AddEntity(type, ent, modelname);
}

extern "C" int __cdecl CL_IsThirdPerson()
{
	return ClientDLL::HOOKED_CL_IsThirdPerson();
}

extern "C" void __cdecl _ZN20CStudioModelRenderer17StudioRenderModelEv(void *thisptr)
{
	return ClientDLL::HOOKED_CStudioModelRenderer__StudioRenderModel_Linux(thisptr);
}

extern "C" void __cdecl _ZN14CHudFlashlight15drawNightVisionEv(void *thisptr)
{
	return ClientDLL::HOOKED_CHudFlashlight__drawNightVision_Linux(thisptr);
}

extern "C" void __cdecl _Z11ScaleColorsRiS_S_i(int* r, int* g, int* b, int a)
{
	return ClientDLL::HOOKED_ScaleColors(r, g, b, a);
}

extern "C" void __cdecl HUD_Shutdown()
{
	return ClientDLL::HOOKED_HUD_Shutdown();
}

extern "C" int __cdecl Initialize(cl_enginefunc_t* pEnginefuncs, int iVersion)
{
	return ClientDLL::HOOKED_Initialize(pEnginefuncs, iVersion);
}
#endif

void ClientDLL::Hook(const std::wstring& moduleName, void* moduleHandle, void* moduleBase, size_t moduleLength, bool needToIntercept)
{
	Clear(); // Just in case.

	m_Handle = moduleHandle;
	m_Base = moduleBase;
	m_Length = moduleLength;
	m_Name = moduleName;
	m_Intercepted = needToIntercept;

	FindStuff();
	RegisterCVarsAndCommands();

	MemUtils::AddSymbolLookupHook(moduleHandle, reinterpret_cast<void*>(ORIG_HUD_Init), reinterpret_cast<void*>(HOOKED_HUD_Init));
	MemUtils::AddSymbolLookupHook(moduleHandle, reinterpret_cast<void*>(ORIG_HUD_VidInit), reinterpret_cast<void*>(HOOKED_HUD_VidInit));
	MemUtils::AddSymbolLookupHook(moduleHandle, reinterpret_cast<void*>(ORIG_HUD_Reset), reinterpret_cast<void*>(HOOKED_HUD_Reset));
	MemUtils::AddSymbolLookupHook(moduleHandle, reinterpret_cast<void*>(ORIG_HUD_Redraw), reinterpret_cast<void*>(HOOKED_HUD_Redraw));
	MemUtils::AddSymbolLookupHook(moduleHandle, reinterpret_cast<void*>(ORIG_HUD_PostRunCmd), reinterpret_cast<void*>(HOOKED_HUD_PostRunCmd));
	MemUtils::AddSymbolLookupHook(moduleHandle, reinterpret_cast<void*>(ORIG_HUD_Frame), reinterpret_cast<void*>(HOOKED_HUD_Frame));
	MemUtils::AddSymbolLookupHook(moduleHandle, reinterpret_cast<void*>(ORIG_HUD_DrawTransparentTriangles), reinterpret_cast<void*>(HOOKED_HUD_DrawTransparentTriangles));
	MemUtils::AddSymbolLookupHook(moduleHandle, reinterpret_cast<void*>(ORIG_HUD_Key_Event), reinterpret_cast<void*>(HOOKED_HUD_Key_Event));
	MemUtils::AddSymbolLookupHook(moduleHandle, reinterpret_cast<void*>(ORIG_HUD_UpdateClientData), reinterpret_cast<void*>(HOOKED_HUD_UpdateClientData));
	MemUtils::AddSymbolLookupHook(moduleHandle, reinterpret_cast<void*>(ORIG_HUD_AddEntity), reinterpret_cast<void*>(HOOKED_HUD_AddEntity));
	MemUtils::AddSymbolLookupHook(moduleHandle, reinterpret_cast<void*>(ORIG_HUD_Shutdown), reinterpret_cast<void*>(HOOKED_HUD_Shutdown));
	MemUtils::AddSymbolLookupHook(moduleHandle, reinterpret_cast<void*>(ORIG_CL_IsThirdPerson), reinterpret_cast<void*>(HOOKED_CL_IsThirdPerson));

	if (needToIntercept)
	{
		MemUtils::Intercept(moduleName,
			ORIG_PM_Jump, HOOKED_PM_Jump,
			ORIG_PM_PreventMegaBunnyJumping, HOOKED_PM_PreventMegaBunnyJumping,
			ORIG_V_CalcRefdef, HOOKED_V_CalcRefdef,
			ORIG_HUD_Init, HOOKED_HUD_Init,
			ORIG_HUD_VidInit, HOOKED_HUD_VidInit,
			ORIG_HUD_Reset, HOOKED_HUD_Reset,
			ORIG_HUD_Redraw, HOOKED_HUD_Redraw,
			ORIG_HUD_PostRunCmd, HOOKED_HUD_PostRunCmd,
			ORIG_HUD_Frame, HOOKED_HUD_Frame,
			ORIG_HUD_DrawTransparentTriangles, HOOKED_HUD_DrawTransparentTriangles,
			ORIG_HUD_Key_Event, HOOKED_HUD_Key_Event,
			ORIG_HUD_UpdateClientData, HOOKED_HUD_UpdateClientData,
			ORIG_HUD_AddEntity, HOOKED_HUD_AddEntity,
			ORIG_HUD_Shutdown, HOOKED_HUD_Shutdown,
			ORIG_EV_GetDefaultShellInfo, HOOKED_EV_GetDefaultShellInfo,
			ORIG_StudioCalcAttachments, HOOKED_StudioCalcAttachments,
			ORIG_VectorTransform, HOOKED_VectorTransform,
			ORIG_CStudioModelRenderer__StudioSetupBones, HOOKED_CStudioModelRenderer__StudioSetupBones,
			ORIG_CL_IsThirdPerson, HOOKED_CL_IsThirdPerson,
			ORIG_CStudioModelRenderer__StudioRenderModel, HOOKED_CStudioModelRenderer__StudioRenderModel,
			ORIG_CHudFlashlight__drawNightVision, HOOKED_CHudFlashlight__drawNightVision,
			ORIG_ScaleColors, HOOKED_ScaleColors);
	}

	// HACK: on Windows we don't get a LoadLibrary for SDL2, so when starting using the injector
	// we never see it loaded. Try loading it here.
	Hooks::HookModule(L"SDL2.dll");
	// Similar story on Linux. Not present during the initial BXT scan and no dlopen.
	Hooks::HookModule(L"libSDL2-2.0.so.0");
}

void ClientDLL::Unhook()
{
	if (m_Intercepted)
	{
		MemUtils::RemoveInterception(m_Name,
			ORIG_PM_Jump,
			ORIG_PM_PreventMegaBunnyJumping,
			ORIG_V_CalcRefdef,
			ORIG_HUD_Init,
			ORIG_HUD_VidInit,
			ORIG_HUD_Reset,
			ORIG_HUD_Redraw,
			ORIG_HUD_PostRunCmd,
			ORIG_HUD_Frame,
			ORIG_HUD_DrawTransparentTriangles,
			ORIG_HUD_Key_Event,
			ORIG_HUD_UpdateClientData,
			ORIG_HUD_AddEntity,
			ORIG_HUD_Shutdown,
			ORIG_EV_GetDefaultShellInfo,
			ORIG_StudioCalcAttachments,
			ORIG_VectorTransform,
			ORIG_CStudioModelRenderer__StudioSetupBones,
			ORIG_CL_IsThirdPerson,
			ORIG_CStudioModelRenderer__StudioRenderModel,
			ORIG_CHudFlashlight__drawNightVision,
			ORIG_ScaleColors);
	}

	MemUtils::RemoveSymbolLookupHook(m_Handle, reinterpret_cast<void*>(ORIG_HUD_Init));
	MemUtils::RemoveSymbolLookupHook(m_Handle, reinterpret_cast<void*>(ORIG_HUD_VidInit));
	MemUtils::RemoveSymbolLookupHook(m_Handle, reinterpret_cast<void*>(ORIG_HUD_Reset));
	MemUtils::RemoveSymbolLookupHook(m_Handle, reinterpret_cast<void*>(ORIG_HUD_Redraw));
	MemUtils::RemoveSymbolLookupHook(m_Handle, reinterpret_cast<void*>(ORIG_HUD_PostRunCmd));
	MemUtils::RemoveSymbolLookupHook(m_Handle, reinterpret_cast<void*>(ORIG_HUD_Frame));
	MemUtils::RemoveSymbolLookupHook(m_Handle, reinterpret_cast<void*>(ORIG_HUD_DrawTransparentTriangles));
	MemUtils::RemoveSymbolLookupHook(m_Handle, reinterpret_cast<void*>(ORIG_HUD_Key_Event));
	MemUtils::RemoveSymbolLookupHook(m_Handle, reinterpret_cast<void*>(ORIG_HUD_UpdateClientData));
	MemUtils::RemoveSymbolLookupHook(m_Handle, reinterpret_cast<void*>(ORIG_HUD_AddEntity));
	MemUtils::RemoveSymbolLookupHook(m_Handle, reinterpret_cast<void*>(ORIG_HUD_Shutdown));
	MemUtils::RemoveSymbolLookupHook(m_Handle, reinterpret_cast<void*>(ORIG_CL_IsThirdPerson));

	Clear();
}

void ClientDLL::Clear()
{
	IHookableNameFilter::Clear();
	ORIG_PM_Jump = nullptr;
	ORIG_PM_PlayerMove = nullptr;
	ORIG_PM_PreventMegaBunnyJumping = nullptr;
	ORIG_PM_ClipVelocity = nullptr;
	ORIG_PM_WaterMove = nullptr;
	ORIG_PM_Move = nullptr;
	ORIG_VectorTransform = nullptr;
	ORIG_EV_GetDefaultShellInfo = nullptr;
	ORIG_StudioCalcAttachments = nullptr;
	ORIG_StudioCalcAttachments_Linux = nullptr;
	ORIG_CStudioModelRenderer__StudioSetupBones = nullptr;
	ORIG_CStudioModelRenderer__StudioSetupBones_Linux = nullptr;
	ORIG_CStudioModelRenderer__StudioRenderModel = nullptr;
	ORIG_CStudioModelRenderer__StudioRenderModel_Linux = nullptr;
	ORIG_CHudFlashlight__drawNightVision = nullptr;
	ORIG_CHudFlashlight__drawNightVision_Linux = nullptr;
	ORIG_V_CalcRefdef = nullptr;
	ORIG_HUD_Init = nullptr;
	ORIG_HUD_VidInit = nullptr;
	ORIG_HUD_Reset = nullptr;
	ORIG_HUD_Redraw = nullptr;
	ORIG_HUD_PostRunCmd = nullptr;
	ORIG_HUD_Frame = nullptr;
	ORIG_HUD_DrawTransparentTriangles = nullptr;
	ORIG_HUD_Key_Event = nullptr;
	ORIG_HUD_UpdateClientData = nullptr;
	ORIG_HUD_AddEntity = nullptr;
	ORIG_HUD_Shutdown = nullptr;
	ORIG_IN_ActivateMouse = nullptr;
	ORIG_IN_DeactivateMouse = nullptr;
	ORIG_CL_IsThirdPerson = nullptr;
	ORIG_ScaleColors = nullptr;
	ORIG_Initialize = nullptr;
	ppmove = nullptr;
	offOldbuttons = 0;
	offOnground = 0;
	offBhopcap = 0;
	pBhopcapWindows = 0;
	memset(originalBhopcapInsn, 0, sizeof(originalBhopcapInsn));
	pEngfuncs = nullptr;
	cantJumpNextTime = false;
	SeedsQueued = 0;
	m_Intercepted = false;
	last_vieworg = Vector();
	last_viewangles = Vector();
	last_viewforward = Vector();
	last_viewup = Vector();
	last_viewright = Vector();
	last_buttons = 0;
}

void ClientDLL::FindStuff()
{
	auto fPM_PreventMegaBunnyJumping = FindFunctionAsync(
		ORIG_PM_PreventMegaBunnyJumping,
		"PM_PreventMegaBunnyJumping",
		patterns::shared::PM_PreventMegaBunnyJumping);

	auto fPM_Jump = FindFunctionAsync(
		ORIG_PM_Jump,
		"PM_Jump",
		patterns::shared::PM_Jump,
		[&](auto pattern) {
			offOldbuttons = 200;
			offOnground = 224;
			if (pattern == patterns::shared::PM_Jump.cend()) // Linux.
			{
				void *bhopcapAddr;
				auto n = MemUtils::find_unique_sequence(
					m_Base,
					m_Length,
					patterns::shared::Bhopcap.cbegin(),
					patterns::shared::Bhopcap.cend(),
					bhopcapAddr);
				if (n != patterns::shared::Bhopcap.cend())
				{
					offBhopcap = reinterpret_cast<ptrdiff_t>(bhopcapAddr) - reinterpret_cast<ptrdiff_t>(ORIG_PM_Jump) + 27;
					memcpy(originalBhopcapInsn, reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(bhopcapAddr) + 27), sizeof(originalBhopcapInsn));
				}
			}
			else
			{
				switch (pattern - patterns::shared::PM_Jump.cbegin())
				{
				case 0:
				case 1:
					ppmove = *reinterpret_cast<void***>(reinterpret_cast<uintptr_t>(ORIG_PM_Jump) + 2);
					break;
				case 2: // AG-Server, shouldn't happen here but who knows.
				case 3:
					ppmove = *reinterpret_cast<void***>(reinterpret_cast<uintptr_t>(ORIG_PM_Jump) + 3);
					break;
				case 4:
					ppmove = *reinterpret_cast<void***>(reinterpret_cast<uintptr_t>(ORIG_PM_Jump) + 21);
					break;
				case 10:
				case 11:
				case 5:
					ppmove = *reinterpret_cast<void***>(reinterpret_cast<uintptr_t>(ORIG_PM_Jump) + 5);
					break;
				case 12:
				case 6:
					ppmove = *reinterpret_cast<void***>(reinterpret_cast<uintptr_t>(ORIG_PM_Jump) + 24);
					break;
				case 7:
					ppmove = *reinterpret_cast<void***>(reinterpret_cast<uintptr_t>(ORIG_PM_Jump) + 6);
					break;
				case 8:
				case 9:
					ppmove = *reinterpret_cast<void***>(reinterpret_cast<uintptr_t>(ORIG_PM_Jump) + 8);
					break;
				}
			}
		});

	auto fPM_Jump_Bhopcap_Windows = FindAsync(
		pBhopcapWindows,
		patterns::shared::Bhopcap_Windows,
		[&](auto pattern) {
			switch (pattern - patterns::shared::Bhopcap_Windows.cbegin()) {
			case 0: // DSM-Demo-1
				pBhopcapWindows += 36;
				break;
			default:
				assert(false);
			}
		});

	auto fStudioCalcAttachments = FindAsync(
		ORIG_StudioCalcAttachments,
		patterns::client::StudioCalcAttachments,
		[&](auto pattern) {
			switch (pattern - patterns::client::StudioCalcAttachments.cbegin()) {
			case 0: // HL-WON-1712
			case 1: // CSCZDS
				ORIG_VectorTransform = reinterpret_cast<_VectorTransform>(
					*reinterpret_cast<uintptr_t*>(reinterpret_cast<uintptr_t>(ORIG_StudioCalcAttachments) + 101)
					+ reinterpret_cast<uintptr_t>(ORIG_StudioCalcAttachments) + 105);
				break;
			case 2: // Echoes
				ORIG_VectorTransform = reinterpret_cast<_VectorTransform>(
					*reinterpret_cast<uintptr_t*>(reinterpret_cast<uintptr_t>(ORIG_StudioCalcAttachments) + 187)
					+ reinterpret_cast<uintptr_t>(ORIG_StudioCalcAttachments) + 191);
				break;
			case 3: // AoMDC
				ORIG_VectorTransform = reinterpret_cast<_VectorTransform>(
					*reinterpret_cast<uintptr_t*>(reinterpret_cast<uintptr_t>(ORIG_StudioCalcAttachments) + 190)
					+ reinterpret_cast<uintptr_t>(ORIG_StudioCalcAttachments) + 194);
				break;
			case 4: // TWHL-Tower-2
				ORIG_VectorTransform = reinterpret_cast<_VectorTransform>(
					*reinterpret_cast<uintptr_t*>(reinterpret_cast<uintptr_t>(ORIG_StudioCalcAttachments) + 100)
					+ reinterpret_cast<uintptr_t>(ORIG_StudioCalcAttachments) + 104);
				break;
			case 5: // Halfquake-Trilogy
				ORIG_VectorTransform = reinterpret_cast<_VectorTransform>(
					*reinterpret_cast<uintptr_t*>(reinterpret_cast<uintptr_t>(ORIG_StudioCalcAttachments) + 70)
					+ reinterpret_cast<uintptr_t>(ORIG_StudioCalcAttachments) + 74);
				break;
			case 6: // Reissues
				ORIG_VectorTransform = reinterpret_cast<_VectorTransform>(
					*reinterpret_cast<uintptr_t*>(reinterpret_cast<uintptr_t>(ORIG_StudioCalcAttachments) + 97)
					+ reinterpret_cast<uintptr_t>(ORIG_StudioCalcAttachments) + 101);
				break;
			default:
				assert(false);
				break;
			}
		});

	auto fEV_GetDefaultShellInfo = FindAsync(ORIG_EV_GetDefaultShellInfo, patterns::client::EV_GetDefaultShellInfo);
	auto fCStudioModelRenderer__StudioSetupBones = FindAsync(
		ORIG_CStudioModelRenderer__StudioSetupBones,
		patterns::client::CStudioModelRenderer__StudioSetupBones);
	auto fCStudioModelRenderer__StudioRenderModel = FindAsync(
		ORIG_CStudioModelRenderer__StudioRenderModel,
		patterns::client::CStudioModelRenderer__StudioRenderModel);
	auto fCHudFlashlight__drawNightVision = FindAsync(
		ORIG_CHudFlashlight__drawNightVision,
		patterns::client::CHudFlashlight__drawNightVision);
	auto fScaleColors = FindAsync(ORIG_ScaleColors, patterns::client::ScaleColors);

	ORIG_PM_PlayerMove = reinterpret_cast<_PM_PlayerMove>(MemUtils::GetSymbolAddress(m_Handle, "PM_PlayerMove")); // For Linux.
	ORIG_PM_ClipVelocity = reinterpret_cast<_PM_ClipVelocity>(MemUtils::GetSymbolAddress(m_Handle, "PM_ClipVelocity")); // For Linux.
	ORIG_PM_WaterMove = reinterpret_cast<_PM_WaterMove>(MemUtils::GetSymbolAddress(m_Handle, "PM_WaterMove")); // For Linux.
	ORIG_PM_Move = reinterpret_cast<_PM_Move>(MemUtils::GetSymbolAddress(m_Handle, "PM_Move")); // For Linux.

	pEngfuncs = reinterpret_cast<cl_enginefunc_t*>(MemUtils::GetSymbolAddress(m_Handle, "gEngfuncs"));
	if (pEngfuncs) {
		EngineDevMsg("[client dll] pEngfuncs is %p.\n", pEngfuncs);
	} else {
		// In AG, this thing is the main function, so check that first.
		auto pInitialize = MemUtils::GetSymbolAddress(m_Handle, "?Initialize_Body@@YAHPAUcl_enginefuncs_s@@H@Z");
		if (!pInitialize)
			pInitialize = MemUtils::GetSymbolAddress(m_Handle, "Initialize");
		if (pInitialize)
		{
			EngineDevMsg("Found Initialize at %p.\n", pInitialize);

			// In some cases Initialize contains just a jump to the real function (Residual Life).
			if (*reinterpret_cast<byte*>(pInitialize) == 0xE9) {
				pInitialize = reinterpret_cast<void*>(
					*reinterpret_cast<uintptr_t*>(reinterpret_cast<uintptr_t>(pInitialize) + 1)
					+ reinterpret_cast<uintptr_t>(pInitialize) + 5);
				EngineDevMsg("Jump detected, found the real Initialize at %p.\n", pInitialize);
			}

			// Find "mov edi, offset dword; rep movsd" inside Initialize. The pointer to gEngfuncs is that dword.
			static constexpr auto p = PATTERN("BF ?? ?? ?? ?? F3 A5");
			auto addr = MemUtils::find_pattern(pInitialize, 40, p);
			if (!addr) {
				static constexpr auto p = PATTERN("B9 ?? ?? ?? ?? 8B 54 24 10");
				addr = MemUtils::find_pattern(pInitialize, 40, p);
			}
			if (!addr) {
				// client.dll that comes with TWHL Tower 2
				static constexpr auto p = PATTERN("B8 ?? ?? ?? ?? 8B F8 F3 A5");
				addr = MemUtils::find_pattern(pInitialize, 40, p);
			}
			if (!addr) {
				// Halfquake Trilogy
				static constexpr auto p = PATTERN("B8 ?? ?? ?? ?? 56 8B 75 08");
				addr = MemUtils::find_pattern(pInitialize, 40, p);
			}
			if (!addr) {
				// Reissues
				static constexpr auto p = PATTERN("B8 ?? ?? ?? ?? 59 8B F8 F3 A5");
				addr = MemUtils::find_pattern(pInitialize, 40, p);
			}
			if (!addr) {
				// Half-Payne
				static constexpr auto p = PATTERN("BF ?? ?? ?? ?? F3 A5 74 12");
				addr = MemUtils::find_pattern(pInitialize, 50, p);
			}
			if (!addr) {
				// OpenAG
				static constexpr auto p = PATTERN("BF ?? ?? ?? ?? 8B F0 F3 A5");
				addr = MemUtils::find_pattern(pInitialize, 70, p);
			}

			if (addr)
			{
				pEngfuncs = *reinterpret_cast<cl_enginefunc_t**>(addr+1);
				EngineDevMsg("[client dll] pEngfuncs is %p.\n", pEngfuncs);
			}
			else
			{
				EngineDevWarning("[client dll] Couldn't find the pattern in Initialize.\n");
				EngineWarning("Custom HUD is not available.\n");
				EngineWarning("Clientside logging is not available.\n");
			}
		}
		else
		{
			EngineDevWarning("[client dll] Couldn't get the address of Initialize.\n");
			EngineWarning("Custom HUD is not available.\n");
			EngineWarning("Clientside logging is not available.\n");
		}
	}

	// We can draw stuff only if we know that we have already received / will receive engfuncs.
	if (pEngfuncs) {
		if (!FindHUDFunctions()) {
			ORIG_HUD_Init = nullptr;
			ORIG_HUD_VidInit = nullptr;
			ORIG_HUD_Reset = nullptr;
			ORIG_HUD_Redraw = nullptr;
			EngineWarning("Custom HUD is not available.\n");
		}
	}

	// Linux hook
	#ifndef _WIN32
	ORIG_Initialize = reinterpret_cast<_Initialize>(MemUtils::GetSymbolAddress(m_Handle, "Initialize"));
	#endif

	ORIG_V_CalcRefdef = reinterpret_cast<_V_CalcRefdef>(MemUtils::GetSymbolAddress(m_Handle, "V_CalcRefdef"));
	if (ORIG_V_CalcRefdef) {
		EngineDevMsg("[client dll] Found V_CalcRefdef at %p.\n", ORIG_V_CalcRefdef);
	} else {
		EngineDevWarning("[client dll] Could not find V_CalcRefdef.\n");
		EngineWarning("Velocity display during demo playback is not available.\n");
	}

	ORIG_HUD_PostRunCmd = reinterpret_cast<_HUD_PostRunCmd>(MemUtils::GetSymbolAddress(m_Handle, "HUD_PostRunCmd"));
	if (ORIG_HUD_PostRunCmd)
		EngineDevMsg("[client dll] Found HUD_PostRunCmd at %p.\n", ORIG_HUD_PostRunCmd);
	else
		EngineDevWarning("[client dll] Could not find HUD_PostRunCmd.\n");

	ORIG_HUD_Frame = reinterpret_cast<_HUD_Frame>(MemUtils::GetSymbolAddress(m_Handle, "HUD_Frame"));
	if (ORIG_HUD_Frame) {
		EngineDevMsg("[client dll] Found HUD_Frame at %p.\n", ORIG_HUD_Frame);
	} else {
		EngineDevWarning("[client dll] Could not find HUD_Frame.\n");
		EngineWarning("In-game timer is not available.\n");
	}

	ORIG_HUD_DrawTransparentTriangles = reinterpret_cast<_HUD_DrawTransparentTriangles>(MemUtils::GetSymbolAddress(m_Handle, "HUD_DrawTransparentTriangles"));
	if (ORIG_HUD_DrawTransparentTriangles) {
		EngineDevMsg("[client dll] Found HUD_DrawTransparentTriangles at %p.\n", ORIG_HUD_DrawTransparentTriangles);
	} else {
		EngineDevWarning("[client dll] Could not find HUD_DrawTransparentTriangles.\n");
		EngineWarning("Features utilizing TriAPI are unavailable.\n");
	}

	ORIG_HUD_Key_Event = reinterpret_cast<_HUD_Key_Event>(MemUtils::GetSymbolAddress(m_Handle, "HUD_Key_Event"));
	if (ORIG_HUD_Key_Event) {
		EngineDevMsg("[client dll] Found HUD_Key_Event at %p.\n", ORIG_HUD_Key_Event);
	} else {
		EngineDevWarning("[client dll] Could not find HUD_Key_Event.\n");
	}

	ORIG_HUD_UpdateClientData = reinterpret_cast<_HUD_UpdateClientData>(MemUtils::GetSymbolAddress(m_Handle, "HUD_UpdateClientData"));
	if (ORIG_HUD_UpdateClientData) {
		EngineDevMsg("[client dll] Found HUD_UpdateClientData at %p.\n", ORIG_HUD_UpdateClientData);
	} else {
		EngineDevWarning("[client dll] Could not find HUD_UpdateClientData.\n");
	}

	ORIG_HUD_AddEntity = reinterpret_cast<_HUD_AddEntity>(MemUtils::GetSymbolAddress(m_Handle, "HUD_AddEntity"));
	if (ORIG_HUD_AddEntity) {
		EngineDevMsg("[client dll] Found HUD_AddEntity at %p.\n", ORIG_HUD_AddEntity);
	} else {
		EngineDevWarning("[client dll] Could not find HUD_AddEntity.\n");
		EngineWarning("bxt_show_hidden_entities_clientside is not available.\n");
	}

	ORIG_HUD_Shutdown = reinterpret_cast<_HUD_Shutdown>(MemUtils::GetSymbolAddress(m_Handle, "HUD_Shutdown"));
	if (ORIG_HUD_Shutdown) {
		EngineDevMsg("[client dll] Found HUD_Shutdown at %p.\n", ORIG_HUD_Shutdown);
	} else {
		EngineDevWarning("[client dll] Could not find HUD_Shutdown.\n");
	}

	ORIG_IN_ActivateMouse = reinterpret_cast<_IN_ActivateMouse>(MemUtils::GetSymbolAddress(m_Handle, "IN_ActivateMouse"));
	if (ORIG_IN_ActivateMouse) {
		EngineDevMsg("[client dll] Found IN_ActivateMouse at %p.\n", ORIG_IN_ActivateMouse);
	} else {
		EngineDevWarning("[client dll] Could not find IN_ActivateMouse.\n");
	}

	ORIG_IN_DeactivateMouse = reinterpret_cast<_IN_DeactivateMouse>(MemUtils::GetSymbolAddress(m_Handle, "IN_DeactivateMouse"));
	if (ORIG_IN_DeactivateMouse) {
		EngineDevMsg("[client dll] Found IN_DeactivateMouse at %p.\n", ORIG_IN_DeactivateMouse);
	} else {
		EngineDevWarning("[client dll] Could not find IN_DeactivateMouse.\n");
	}

	ORIG_CL_IsThirdPerson = reinterpret_cast<_CL_IsThirdPerson>(MemUtils::GetSymbolAddress(m_Handle, "CL_IsThirdPerson"));
	if (ORIG_CL_IsThirdPerson) {
		EngineDevMsg("[client dll] Found CL_IsThirdPerson at %p.\n", ORIG_CL_IsThirdPerson);
	} else {
		EngineDevWarning("[client dll] Could not find CL_IsThirdPerson.\n");
	}

	bool noBhopcap = false;
	{
		auto pattern = fPM_PreventMegaBunnyJumping.get();
		if (ORIG_PM_PreventMegaBunnyJumping) {
			if (pattern == patterns::shared::PM_PreventMegaBunnyJumping.cend())
				EngineDevMsg("[client dll] Found PM_PreventMegaBunnyJumping at %p.\n", ORIG_PM_PreventMegaBunnyJumping);
			else
				EngineDevMsg("[client dll] Found PM_PreventMegaBunnyJumping at %p (using the %s pattern).\n", ORIG_PM_PreventMegaBunnyJumping, pattern->name());
		} else {
			EngineDevWarning("[client dll] Could not find PM_PreventMegaBunnyJumping.\n");
			EngineWarning("Bhopcap prediction disabling is not available.\n");
			noBhopcap = true;
		}
	}

	{
		auto pattern = fPM_Jump.get();
		auto pattern2 = fPM_Jump_Bhopcap_Windows.get();
		if (ORIG_PM_Jump) {
			if (pattern == patterns::shared::PM_Jump.cend())
				EngineDevMsg("[client dll] Found PM_Jump at %p.\n", ORIG_PM_Jump);
			else
				EngineDevMsg("[client dll] Found PM_Jump at %p (using the %s pattern).\n", ORIG_PM_Jump, pattern->name());
			if (offBhopcap)
				EngineDevMsg("[client dll] Found the bhopcap pattern at %p.\n", reinterpret_cast<void*>(offBhopcap + reinterpret_cast<uintptr_t>(ORIG_PM_Jump)-27));
			if (pBhopcapWindows)
				EngineDevMsg("[client dll] Found bhopcap jump instruction at %p (using the %s pattern).\n", pBhopcapWindows, pattern2->name());
		} else {
			EngineDevWarning("[client dll] Could not find PM_Jump.\n");
			EngineWarning("Autojump prediction is not available.\n");
			if (!noBhopcap)
				EngineWarning("Bhopcap prediction disabling is not available.\n");
		}

		if (!ppmove)
			ppmove = reinterpret_cast<void**>(MemUtils::GetSymbolAddress(m_Handle, "pmove"));
	}

	{
		auto pattern = fEV_GetDefaultShellInfo.get();
		if (ORIG_EV_GetDefaultShellInfo) {
			EngineDevMsg("[client dll] Found EV_GetDefaultShellInfo at %p (using the %s pattern).\n", ORIG_EV_GetDefaultShellInfo, pattern->name());
		} else {
			ORIG_EV_GetDefaultShellInfo = reinterpret_cast<_EV_GetDefaultShellInfo>(MemUtils::GetSymbolAddress(m_Handle, "_Z22EV_GetDefaultShellInfoP12event_args_sPfS1_S1_S1_S1_S1_S1_fff"));
			if (ORIG_EV_GetDefaultShellInfo) {
				EngineDevMsg("[client dll] Found EV_GetDefaultShellInfo at %p.\n", ORIG_EV_GetDefaultShellInfo);
			} else {
				EngineDevWarning("[client dll] Could not find EV_GetDefaultShellInfo.\n");
				EngineWarning("[client dll] Special effects of weapons will be misplaced when bxt_viewmodel_fov is used.\n");
			}
		}
	}

	{
		auto pattern = fStudioCalcAttachments.get();
		if (ORIG_StudioCalcAttachments) {
			EngineDevMsg("[client dll] Found StudioCalcAttachment at %p (using the %s pattern).\n", ORIG_StudioCalcAttachments, pattern->name());
			if (ORIG_VectorTransform)
				EngineDevMsg("[client dll] Found VectorTransform at %p.\n", ORIG_VectorTransform);
		} else {
			ORIG_StudioCalcAttachments_Linux = reinterpret_cast<_StudioCalcAttachments_Linux>(MemUtils::GetSymbolAddress(m_Handle, "_ZN20CStudioModelRenderer21StudioCalcAttachmentsEv"));
			ORIG_VectorTransform = reinterpret_cast<_VectorTransform>(MemUtils::GetSymbolAddress(m_Handle, "_Z15VectorTransformPKfPA4_fPf"));
			if (ORIG_StudioCalcAttachments_Linux && ORIG_VectorTransform) {
				EngineDevMsg("[client dll] Found StudioCalcAttachments_Linux at %p.\n", ORIG_StudioCalcAttachments_Linux);
				EngineDevMsg("[client dll] Found VectorTransform at %p.\n", ORIG_VectorTransform);
			} else {
				EngineDevWarning("[client dll] Could not find StudioCalcAttachments.\n");
				EngineDevWarning("[client dll] Could not find VectorTransform.\n");
				EngineWarning("[client dll] Special effects of weapons will be misplaced when bxt_viewmodel_fov is used.\n");
			}
		}
	}

	{
		auto pattern = fCStudioModelRenderer__StudioSetupBones.get();
		if (ORIG_CStudioModelRenderer__StudioSetupBones) {
			EngineDevMsg("[client dll] Found CStudioModelRenderer::StudioSetupBones at %p (using the %s pattern).\n", ORIG_CStudioModelRenderer__StudioSetupBones, pattern->name());
		} else {
			ORIG_CStudioModelRenderer__StudioSetupBones_Linux = reinterpret_cast<_CStudioModelRenderer__StudioSetupBones_Linux>(MemUtils::GetSymbolAddress(m_Handle, "_ZN20CStudioModelRenderer16StudioSetupBonesEv"));
			if (ORIG_CStudioModelRenderer__StudioSetupBones_Linux) {
				EngineDevMsg("[client dll] Found CStudioModelRenderer::StudioSetupBones [Linux] at %p.\n", ORIG_CStudioModelRenderer__StudioSetupBones_Linux);
			} else {
				EngineDevWarning("[client dll] Could not find CStudioModelRenderer::StudioSetupBones.\n");
				EngineWarning("[client dll] Disabling weapon viewmodel idle or equip sequences is not available.\n");
			}
		}
	}

	{
		auto pattern = fCStudioModelRenderer__StudioRenderModel.get();
		if (ORIG_CStudioModelRenderer__StudioRenderModel) {
			EngineDevMsg("[client dll] Found CStudioModelRenderer::StudioRenderModel at %p (using the %s pattern).\n", ORIG_CStudioModelRenderer__StudioRenderModel, pattern->name());
		} else {
			ORIG_CStudioModelRenderer__StudioRenderModel_Linux = reinterpret_cast<_CStudioModelRenderer__StudioRenderModel_Linux>(MemUtils::GetSymbolAddress(m_Handle, "_ZN20CStudioModelRenderer17StudioRenderModelEv"));
			if (ORIG_CStudioModelRenderer__StudioRenderModel_Linux) {
				EngineDevMsg("[client dll] Found CStudioModelRenderer::StudioRenderModel [Linux] at %p.\n", ORIG_CStudioModelRenderer__StudioRenderModel_Linux);
			} else {
				EngineDevWarning("[client dll] Could not find CStudioModelRenderer::StudioRenderModel.\n");
				EngineWarning("[client dll] Changing weapon viewmodel opacity is not available.\n");
			}
		}
	}

	{
		auto pattern = fCHudFlashlight__drawNightVision.get();
		if (ORIG_CHudFlashlight__drawNightVision) {
			EngineDevMsg("[client dll] Found CHudFlashlight::drawNightVision at %p (using the %s pattern).\n", ORIG_CHudFlashlight__drawNightVision, pattern->name());
		} else {
			ORIG_CHudFlashlight__drawNightVision_Linux = reinterpret_cast<_CHudFlashlight__drawNightVision_Linux>(MemUtils::GetSymbolAddress(m_Handle, "_ZN14CHudFlashlight15drawNightVisionEv"));
			if (ORIG_CHudFlashlight__drawNightVision_Linux) {
				EngineDevMsg("[client dll] Found CHudFlashlight::drawNightVision [Linux] at %p.\n", ORIG_CHudFlashlight__drawNightVision_Linux);
			} else {
				EngineDevWarning("[client dll] Could not find HudFlashlight::drawNightVision [Linux].\n");
				EngineWarning("[client dll] Disabling Opposing Force nightvision sprite is unavailable.\n");
			}
		}
	}

	{
		auto pattern = fScaleColors.get();
		if (ORIG_ScaleColors) {
			EngineDevMsg("[client dll] Found ScaleColors at %p (using the %s pattern).\n", ORIG_ScaleColors, pattern->name());
		} else {
			ORIG_ScaleColors = reinterpret_cast<_ScaleColors>(MemUtils::GetSymbolAddress(m_Handle, "_Z11ScaleColorsRiS_S_i"));
			if (ORIG_ScaleColors) {
				EngineDevMsg("[client dll] Found ScaleColors at %p.\n", ORIG_ScaleColors);
			} else {
				EngineDevWarning("[client dll] Could not find ScaleColors.\n");
				EngineWarning("[client dll] Changing HUD color and alpha is not available.\n");
			}
		}
	}
}

bool ClientDLL::FindHUDFunctions()
{
	if ((ORIG_HUD_Init = reinterpret_cast<_HUD_Init>(MemUtils::GetSymbolAddress(m_Handle, "HUD_Init")))) {
		EngineDevMsg("[client dll] Found HUD_Init at %p.\n", ORIG_HUD_Init);
	} else {
		EngineDevWarning("[client dll] Could not find HUD_Init.\n");
		return false;
	}

	if ((ORIG_HUD_VidInit = reinterpret_cast<_HUD_VidInit>(MemUtils::GetSymbolAddress(m_Handle, "HUD_VidInit")))) {
		EngineDevMsg("[client dll] Found HUD_VidInit at %p.\n", ORIG_HUD_VidInit);
	} else {
		EngineDevWarning("[client dll] Could not find HUD_VidInit.\n");
		return false;
	}

	if ((ORIG_HUD_Reset = reinterpret_cast<_HUD_Reset>(MemUtils::GetSymbolAddress(m_Handle, "HUD_Reset")))) {
		EngineDevMsg("[client dll] Found HUD_Reset at %p.\n", ORIG_HUD_Reset);
	} else {
		EngineDevWarning("[client dll] Could not find HUD_Reset.\n");
		return false;
	}

	if ((ORIG_HUD_Redraw = reinterpret_cast<_HUD_Redraw>(MemUtils::GetSymbolAddress(m_Handle, "HUD_Redraw")))) {
		EngineDevMsg("[client dll] Found HUD_Redraw at %p.\n", ORIG_HUD_Redraw);
	} else {
		EngineDevWarning("[client dll] Could not find HUD_Redraw.\n");
		EngineWarning("bxt_disable_hud is not available.\n");
		return false;
	}

	return true;
}

void ClientDLL::RegisterCVarsAndCommands()
{
	EngineDevMsg("[client dll] Registering CVars.\n");

	#define REG(cvar) HwDLL::GetInstance().RegisterCVar(CVars::cvar)
	if (ORIG_PM_Jump)
		REG(bxt_autojump_prediction);

	if (ORIG_PM_PreventMegaBunnyJumping || pBhopcapWindows)
		REG(bxt_bhopcap_prediction);

	if (ORIG_HUD_DrawTransparentTriangles && pEngfuncs) {
		REG(bxt_show_triggers);
		REG(bxt_show_custom_triggers);
		REG(bxt_triggers_color);
		REG(bxt_show_nodes);
		REG(bxt_show_pickup_bbox);
		REG(bxt_show_displacer_earth_targets);
		REG(bxt_hud_useables);
		REG(bxt_hud_useables_radius);
	}

	if (ORIG_V_CalcRefdef) {
		REG(bxt_unlock_camera_during_pause);
		REG(bxt_viewmodel_ofs_forward);
		REG(bxt_viewmodel_ofs_right);
		REG(bxt_viewmodel_ofs_up);
	}

	if (ORIG_HUD_Init)
	{
		CVars::con_color.Assign(HwDLL::GetInstance().FindCVar("con_color"));
		REG(bxt_hud);
		REG(bxt_hud_color);
		REG(bxt_hud_precision);
		REG(bxt_hud_quickgauss);
		REG(bxt_hud_quickgauss_offset);
		REG(bxt_hud_quickgauss_anchor);
		REG(bxt_hud_velocity);
		REG(bxt_hud_velocity_offset);
		REG(bxt_hud_velocity_anchor);
		REG(bxt_hud_origin);
		REG(bxt_hud_origin_offset);
		REG(bxt_hud_origin_anchor);
		REG(bxt_hud_viewangles);
		REG(bxt_hud_viewangles_offset);
		REG(bxt_hud_viewangles_anchor);
		REG(bxt_hud_distance);
		REG(bxt_hud_distance_offset);
		REG(bxt_hud_distance_anchor);
		REG(bxt_hud_entity_info);
		REG(bxt_hud_entity_info_offset);
		REG(bxt_hud_entity_info_anchor);
		REG(bxt_hud_selfgauss);
		REG(bxt_hud_selfgauss_offset);
		REG(bxt_hud_selfgauss_anchor);
		REG(bxt_hud_armor);
		REG(bxt_hud_armor_offset);
		REG(bxt_hud_armor_anchor);
		REG(bxt_hud_speedometer);
		REG(bxt_hud_speedometer_offset);
		REG(bxt_hud_speedometer_anchor);
		REG(bxt_hud_jumpspeed);
		REG(bxt_hud_jumpspeed_offset);
		REG(bxt_hud_jumpspeed_anchor);
		REG(bxt_hud_health);
		REG(bxt_hud_health_offset);
		REG(bxt_hud_health_anchor);
		REG(bxt_hud_nihilanth);
		REG(bxt_hud_nihilanth_offset);
		REG(bxt_hud_nihilanth_anchor);
		REG(bxt_hud_gonarch);
		REG(bxt_hud_gonarch_offset);
		REG(bxt_hud_gonarch_anchor);
		REG(bxt_hud_timer);
		REG(bxt_hud_timer_offset);
		REG(bxt_hud_timer_anchor);
		REG(bxt_hud_visible_landmarks);
		REG(bxt_hud_visible_landmarks_offset);
		REG(bxt_hud_visible_landmarks_anchor);
		REG(bxt_hud_incorrect_fps_indicator);
		REG(bxt_hud_tas_editor_status);
		REG(bxt_hud_tas_editor_status_offset);
		REG(bxt_hud_tas_editor_status_anchor);
		REG(bxt_hud_entities);
		REG(bxt_hud_entities_offset);
		REG(bxt_hud_entities_anchor);
		REG(bxt_cross);
		REG(bxt_cross_color);
		REG(bxt_cross_alpha);
		REG(bxt_cross_thickness);
		REG(bxt_cross_size);
		REG(bxt_cross_gap);
		REG(bxt_cross_outline);
		REG(bxt_cross_circle_radius);
		REG(bxt_cross_dot_color);
		REG(bxt_cross_dot_size);
		REG(bxt_cross_top_line);
		REG(bxt_cross_bottom_line);
		REG(bxt_cross_left_line);
		REG(bxt_cross_right_line);
	}

	if (ORIG_HUD_Redraw) {
		REG(bxt_disable_hud);
	}

	if (ORIG_HUD_AddEntity) {
		REG(bxt_show_hidden_entities_clientside);
	}

	if (ORIG_CL_IsThirdPerson) {
		REG(bxt_show_player_in_hltv);
	}

	if (ORIG_CHudFlashlight__drawNightVision_Linux || ORIG_CHudFlashlight__drawNightVision) {
		REG(bxt_disable_nightvision_sprite);
	}

	if (ORIG_ScaleColors) {
		REG(bxt_hud_game_color);
		REG(bxt_hud_game_alpha);
	}
	#undef REG
}

void ClientDLL::SetMouseState(bool active)
{
	if (ORIG_IN_ActivateMouse && ORIG_IN_DeactivateMouse) {
		if (active)
			ORIG_IN_ActivateMouse();
		else
			ORIG_IN_DeactivateMouse();
	}
}

Vector ClientDLL::AnglesToForward(const Vector &angles) {
	assert(pEngfuncs);

	Vector forward, right, up;
	pEngfuncs->pfnAngleVectors(angles, forward, right, up);
	return forward;
}

void ClientDLL::StudioAdjustViewmodelAttachments(Vector &vOrigin)
{
	// V_CalcRefDef didn't give us info, let's bail out since we'd just make the attachments be somewhere in the world
	// and nowhere near the player's viewmodel
	if (last_vieworg.x == 0.0f && last_vieworg.y == 0.0f && last_vieworg.z == 0.0f)
		return;

	double worldx = tan(HwDLL::GetInstance().currentRenderFOV  * M_PI / 360.0);
	double viewx = tan(CVars::bxt_viewmodel_fov.GetFloat() * M_PI / 360.0);

	// aspect ratio cancels out, so only need one factor
	// the difference between the screen coordinates of the 2 systems is the ratio
	// of the coefficients of the projection matrices (tan (fov/2) is that coefficient)
	float factor = (float)worldx / (float)viewx;

	// Get the coordinates in the viewer's space.
	Vector tmp = vOrigin - last_vieworg;

	Vector vTransformed(DotProduct(last_viewright, tmp), DotProduct(last_viewup, tmp), DotProduct(last_viewforward, tmp));

	// Now squash X and Y.
	vTransformed.x *= factor;
	vTransformed.y *= factor;

	// Transform back to world space.
	Vector vOut = (last_viewright * vTransformed.x) + (last_viewup * vTransformed.y) + (last_viewforward * vTransformed.z);
	vOrigin = last_vieworg + vOut;
}

bool ClientDLL::DoesGameDirMatch(const char *game)
{
	if (!pEngfuncs)
		return false;

	const char *gameDir = pEngfuncs->pfnGetGameDirectory();

	return !std::strcmp(gameDir, game);
}

HOOK_DEF_0(ClientDLL, void, __cdecl, PM_Jump)
{
	auto pmove = reinterpret_cast<uintptr_t>(*ppmove);
	int *onground = reinterpret_cast<int*>(pmove + offOnground);
	int orig_onground = *onground;

	int *oldbuttons = reinterpret_cast<int*>(pmove + offOldbuttons);
	int orig_oldbuttons = *oldbuttons;

	if (CVars::bxt_autojump_prediction.GetBool())
	{
		if ((orig_onground != -1) && !cantJumpNextTime) {
			if (HwDLL::GetInstance().ducktap == false || (HwDLL::GetInstance().ducktap == true && CVars::bxt_autojump_priority.GetBool())) {
				*oldbuttons &= ~IN_JUMP;
			}
		}
	}

	cantJumpNextTime = false;

	if (offBhopcap)
	{
		auto pPMJump = reinterpret_cast<ptrdiff_t>(ORIG_PM_Jump);
		if (CVars::bxt_bhopcap_prediction.GetBool())
		{
			if (*reinterpret_cast<byte*>(pPMJump + offBhopcap) == 0x90
				&& *reinterpret_cast<byte*>(pPMJump + offBhopcap + 1) == 0x90)
				MemUtils::ReplaceBytes(reinterpret_cast<void*>(pPMJump + offBhopcap), 6, originalBhopcapInsn);
		}
		else if (*reinterpret_cast<byte*>(pPMJump + offBhopcap) == 0x0F
				&& *reinterpret_cast<byte*>(pPMJump + offBhopcap + 1) == 0x82)
				MemUtils::ReplaceBytes(reinterpret_cast<void*>(pPMJump + offBhopcap), 6, reinterpret_cast<const byte*>("\x90\x90\x90\x90\x90\x90"));
	}

	if (pBhopcapWindows)
		MemUtils::ReplaceBytes(reinterpret_cast<void*>(pBhopcapWindows), 1, reinterpret_cast<const byte*>(CVars::bxt_bhopcap_prediction.GetBool() ? "\x83" : "\x82"));

	ORIG_PM_Jump();

	if ((orig_onground != -1) && (*onground == -1))
		cantJumpNextTime = true;

	if (CVars::bxt_autojump_prediction.GetBool())
		*oldbuttons = orig_oldbuttons;
}

HOOK_DEF_1(ClientDLL, void, __cdecl, PM_PlayerMove, qboolean, server)
{
	ORIG_PM_PlayerMove(server);
}

HOOK_DEF_0(ClientDLL, void, __cdecl, PM_PreventMegaBunnyJumping)
{
	if (CVars::bxt_bhopcap_prediction.GetBool())
		ORIG_PM_PreventMegaBunnyJumping();
}

HOOK_DEF_4(ClientDLL, int, __cdecl, PM_ClipVelocity, float*, in, float*, normal, float*, out, float, overbounce)
{
	return ORIG_PM_ClipVelocity(in, normal, out, overbounce);
}

HOOK_DEF_0(ClientDLL, void, __cdecl, PM_WaterMove)
{
	return ORIG_PM_WaterMove();
}

HOOK_DEF_2(ClientDLL, void, __cdecl, PM_Move, struct playermove_s*, ppmove, int, server)
{
	return ORIG_PM_Move(ppmove, server);
}

HOOK_DEF_1(ClientDLL, void, __cdecl, V_CalcRefdef, ref_params_t*, pparams)
{
	CustomHud::UpdatePlayerInfoInaccurate(pparams->simvel, pparams->simorg);

	const HwDLL &hwDLL = HwDLL::GetInstance();

	static bool free_cam_was_active = false;

	auto paused = pparams->paused;
	auto unlock_camera = CVars::bxt_unlock_camera_during_pause.GetBool() || hwDLL.free_cam_active
		// We want to unlock the camera 1 frame after free cam has been disabled so that it can
		// snap back to its original position.
		|| (!hwDLL.free_cam_active && free_cam_was_active);
	free_cam_was_active = hwDLL.free_cam_active;

	if (unlock_camera)
		pparams->paused = false;

	ORIG_V_CalcRefdef(pparams);

	float forward_offset = CVars::bxt_viewmodel_ofs_forward.GetFloat();
	float right_offset = CVars::bxt_viewmodel_ofs_right.GetFloat();
	float up_offset = CVars::bxt_viewmodel_ofs_up.GetFloat();

	if (pEngfuncs) {
		auto view = pEngfuncs->GetViewModel();

		if (!paused) {
			for (int i = 0; i < 3; i++) {
				view->origin[i] += forward_offset * pparams->forward[i] +
					right_offset * pparams->right[i] +
					up_offset * pparams->up[i];
			}
		}
	}

	if (hwDLL.GetIsOverridingCamera()) {
		// We want to keep looking as is in freecam.
		if (!hwDLL.free_cam_active)
			hwDLL.GetCameraOverrideAngles(pparams->viewangles);

		hwDLL.GetCameraOverrideOrigin(pparams->vieworg);
	} else if (hwDLL.GetIsOffsettingCamera()) {
		static float old_camera_offset_angles[3] = { 0.0f };
		static float old_camera_offset_origin[3] = { 0.0f };

		float vector[3];
		hwDLL.GetCameraOffsetAngles(vector);

		if (pparams->paused) {
			for (int i = 0; i < 3; ++i)
				pparams->viewangles[i] += vector[i] - old_camera_offset_angles[i];
		} else {
			for (int i = 0; i < 3; ++i)
				pparams->viewangles[i] += vector[i];
		}

		for (int i = 0; i < 3; ++i)
			old_camera_offset_angles[i] = vector[i];

		hwDLL.GetCameraOffsetOrigin(vector);

		if (pparams->paused) {
			for (int i = 0; i < 3; ++i)
				pparams->vieworg[i] += vector[i] - old_camera_offset_origin[i];
		} else {
			for (int i = 0; i < 3; ++i)
				pparams->vieworg[i] += vector[i];
		}

		for (int i = 0; i < 3; ++i)
			old_camera_offset_origin[i] = vector[i];
	}

	if (unlock_camera)
		pparams->paused = paused;

	last_vieworg = pparams->vieworg;
	last_viewangles = pparams->viewangles;
	last_viewforward = pparams->forward;
	last_viewright = pparams->right;
	last_viewup = pparams->up;
}

HOOK_DEF_0(ClientDLL, void, __cdecl, HUD_Init)
{
	ORIG_HUD_Init();

	CustomHud::Init();
}

HOOK_DEF_0(ClientDLL, void, __cdecl, HUD_VidInit)
{
	ORIG_HUD_VidInit();

	CustomHud::InitIfNecessary();
	CustomHud::VidInit();

	TriangleDrawing::VidInit();
}

HOOK_DEF_0(ClientDLL, void, __cdecl, HUD_Reset)
{
	ORIG_HUD_Reset();

	CustomHud::InitIfNecessary();
	CustomHud::VidInit();
}

HOOK_DEF_2(ClientDLL, void, __cdecl, HUD_Redraw, float, time, int, intermission)
{
	custom_hud_color_set = false;

	if (sscanf(CVars::bxt_hud_game_color.GetString().c_str(), "%hhu %hhu %hhu", &custom_r, &custom_g, &custom_b) == 3)
		custom_hud_color_set = true;

	if (!CVars::bxt_disable_hud.GetBool())
		ORIG_HUD_Redraw(time, intermission);

	CustomHud::Draw(time);
}

HOOK_DEF_6(ClientDLL, void, __cdecl, HUD_PostRunCmd, local_state_s*, from, local_state_s*, to, usercmd_s*, cmd, int, runfuncs, double, time, unsigned int, random_seed)
{
	HwDLL::GetInstance().SetLastRandomSeed(random_seed);
	auto seed = random_seed;
	bool changedSeed = false;
	if (HwDLL::GetInstance().IsCountingSharedRNGSeed()) {
		auto lastSeed = HwDLL::GetInstance().GetSharedRNGSeedCounter();
		seed = lastSeed - HwDLL::GetInstance().QueuedSharedRNGSeeds + 1 + SeedsQueued;
		SeedsQueued++;
		changedSeed = true;
	}

	last_buttons = cmd->buttons;

	// Not sure if this is the best spot.
	HwDLL::GetInstance().FreeCamTick();

	if (CVars::_bxt_taslog.GetBool())
		if (pEngfuncs)
		{
			#define PRINTF(format, ...) pEngfuncs->Con_Printf(const_cast<char*>(format), ##__VA_ARGS__)
			PRINTF("-- HUD_PostRunCmd Start --\n");
			PRINTF("Msec %hhu (%Lf)\n", cmd->msec, static_cast<long double>(cmd->msec) * 0.001);
			PRINTF("Viewangles: %.8f %.8f %.8f; forwardmove: %f; sidemove: %f; upmove: %f\n", cmd->viewangles[0], cmd->viewangles[1], cmd->viewangles[2], cmd->forwardmove, cmd->sidemove, cmd->upmove);
			PRINTF("Buttons: %hu\n", cmd->buttons);
			PRINTF("Random seed: %u", random_seed);
			if (changedSeed)
				PRINTF(" (overriding with %u)", seed);
			PRINTF("\n");
			PRINTF("-- HUD_PostRunCmd End --\n");
			#undef P
		}

	return ORIG_HUD_PostRunCmd(from, to, cmd, runfuncs, time, seed);
}

HOOK_DEF_1(ClientDLL, void, __cdecl, HUD_Frame, double, time)
{
	ORIG_HUD_Frame(time);

	if (CVars::_bxt_taslog.GetBool() && pEngfuncs)
		pEngfuncs->Con_Printf(const_cast<char*>("HUD_Frame time: %f\n"), time);

	SeedsQueued = 0;

	discord_integration::on_frame();
}

HOOK_DEF_0(ClientDLL, void, __cdecl, HUD_DrawTransparentTriangles)
{
	ORIG_HUD_DrawTransparentTriangles();

	if (pEngfuncs) {
		glDisable(GL_TEXTURE_2D);

		TriangleDrawing::Draw();

		glEnable(GL_TEXTURE_2D);

		// This is required for the WON DLLs.
		pEngfuncs->pTriAPI->RenderMode(kRenderNormal);
	}
}

HOOK_DEF_3(ClientDLL, int, __cdecl, HUD_Key_Event, int, down, int, keynum, const char*, pszCurrentBinding)
{
	insideKeyEvent = true;

	auto rv = ORIG_HUD_Key_Event(down, keynum, pszCurrentBinding);

	insideKeyEvent = false;

	return rv;
}

HOOK_DEF_2(ClientDLL, int, __cdecl, HUD_UpdateClientData, client_data_t*, pcldata, float, flTime)
{
	const auto norefresh = CVars::_bxt_norefresh.GetBool();
	int (*ORIG_GetScreenInfo)(SCREENINFO *pscrinfo) = nullptr;

	if (norefresh && pEngfuncs) {
		ORIG_GetScreenInfo = pEngfuncs->pfnGetScreenInfo;
		pEngfuncs->pfnGetScreenInfo = [](SCREENINFO *pscrinfo) { return 0; };
	}

	const auto rv = ORIG_HUD_UpdateClientData(pcldata, flTime);

	HwDLL::GetInstance().currentRenderFOV = pcldata->fov;

	if (norefresh && pEngfuncs) {
		pEngfuncs->pfnGetScreenInfo = ORIG_GetScreenInfo;
	}

	discord_integration::on_update_client_data();

	return rv;
}

HOOK_DEF_3(ClientDLL, void, __cdecl, VectorTransform, float*, in1, float*, in2, float*, out)
{
	// No need for a NeedViewmodelAdjustments() here since insideStudioCalcAttachmentsViewmodel is
	// always FALSE from StudioCalcAttachments if we do NOT need the adjustments
	if (insideStudioCalcAttachmentsViewmodel == false)
		ORIG_VectorTransform(in1, in2, out);
	else
	{
		ORIG_VectorTransform(in1, in2, out);
		Vector vOrigin(out);
		StudioAdjustViewmodelAttachments(vOrigin);
		out[0] = vOrigin[0];
		out[1] = vOrigin[1];
		out[2] = vOrigin[2];
	}
}

HOOK_DEF_1(ClientDLL, void, __fastcall, StudioCalcAttachments, void*, thisptr)
{
	if (pEngfuncs && HwDLL::GetInstance().ORIG_studioapi_GetCurrentEntity)
	{
		auto currententity = HwDLL::GetInstance().ORIG_studioapi_GetCurrentEntity();
		if (currententity == pEngfuncs->GetViewModel() && HwDLL::GetInstance().NeedViewmodelAdjustments())
			insideStudioCalcAttachmentsViewmodel = true;
	}
	ORIG_StudioCalcAttachments(thisptr);
	insideStudioCalcAttachmentsViewmodel = false;
}

HOOK_DEF_1(ClientDLL, void, __cdecl, StudioCalcAttachments_Linux, void*, thisptr)
{
	if (pEngfuncs && HwDLL::GetInstance().ORIG_studioapi_GetCurrentEntity)
	{
		auto currententity = HwDLL::GetInstance().ORIG_studioapi_GetCurrentEntity();
		if (currententity == pEngfuncs->GetViewModel() && HwDLL::GetInstance().NeedViewmodelAdjustments())
			insideStudioCalcAttachmentsViewmodel = true;
	}
	ORIG_StudioCalcAttachments_Linux(thisptr);
	insideStudioCalcAttachmentsViewmodel = false;
}

HOOK_DEF_11(ClientDLL, void, __cdecl, EV_GetDefaultShellInfo, event_args_t*, args, float*, origin, float*, velocity, float*, ShellVelocity, float*, ShellOrigin,
            float*, forward, float*, right, float*, up, float, forwardScale, float, upScale, float, rightScale)
{
	if (ORIG_CL_IsThirdPerson) {
		if (!ORIG_CL_IsThirdPerson()) {
			rightScale += CVars::bxt_viewmodel_ofs_right.GetFloat();
			forwardScale += CVars::bxt_viewmodel_ofs_forward.GetFloat();
			upScale += CVars::bxt_viewmodel_ofs_up.GetFloat();
		}
	}

	ORIG_EV_GetDefaultShellInfo(args, origin, velocity, ShellVelocity, ShellOrigin, forward, right, up, forwardScale, upScale, rightScale);
	if (pEngfuncs)
	{
		// Are we overriding viewmodel fov && is the entity that the shell info is for the local player?
		if (HwDLL::GetInstance().NeedViewmodelAdjustments() && pEngfuncs->pEventAPI->EV_IsLocal(args->entindex - 1))
		{
			Vector ShellOriginVec(ShellOrigin);
			StudioAdjustViewmodelAttachments(ShellOriginVec);
			ShellOrigin[0] = ShellOriginVec.x;
			ShellOrigin[1] = ShellOriginVec.y;
			ShellOrigin[2] = ShellOriginVec.z;
		}
	}
}

HOOK_DEF_1(ClientDLL, void, __fastcall, CStudioModelRenderer__StudioSetupBones, void*, thisptr)
{
	auto pCurrentEntity = *reinterpret_cast<cl_entity_t**>(reinterpret_cast<uintptr_t>(thisptr) + 48);
	auto pStudioHeader = *reinterpret_cast<studiohdr_t**>(reinterpret_cast<uintptr_t>(thisptr) + 68);
	auto pseqdesc = reinterpret_cast<mstudioseqdesc_t*>(reinterpret_cast<byte*>(pStudioHeader) +
		pStudioHeader->seqindex) + pCurrentEntity->curstate.sequence;

	if (pEngfuncs) {
		if (pCurrentEntity == pEngfuncs->GetViewModel()) {
			if (CVars::bxt_viewmodel_disable_idle.GetBool()) {
				if (strstr(pseqdesc->label, "idle") != NULL || strstr(pseqdesc->label, "fidget") != NULL) {
					pCurrentEntity->curstate.framerate = 0; // don't animate at all
				}
			}

			if (CVars::bxt_viewmodel_disable_equip.GetBool()) {
				if (strstr(pseqdesc->label, "holster") != NULL || strstr(pseqdesc->label, "draw") != NULL ||
					strstr(pseqdesc->label, "deploy") != NULL || strstr(pseqdesc->label, "up") != NULL ||
					strstr(pseqdesc->label, "down") != NULL) {
					pCurrentEntity->curstate.sequence = 0; // instead set to idle sequence
					pseqdesc = reinterpret_cast<mstudioseqdesc_t*>(reinterpret_cast<byte*>(pStudioHeader) +
						pStudioHeader->seqindex) + pCurrentEntity->curstate.sequence;
					pseqdesc->numframes = 1;
					pseqdesc->fps = 1;
				}
			}
		}
	}

	ORIG_CStudioModelRenderer__StudioSetupBones(thisptr);
}

HOOK_DEF_1(ClientDLL, void, __cdecl, CStudioModelRenderer__StudioSetupBones_Linux, void*, thisptr)
{
	auto pCurrentEntity = *reinterpret_cast<cl_entity_t**>(reinterpret_cast<uintptr_t>(thisptr) + 44);
	auto pStudioHeader = *reinterpret_cast<studiohdr_t**>(reinterpret_cast<uintptr_t>(thisptr) + 64);
	auto pseqdesc = reinterpret_cast<mstudioseqdesc_t*>(reinterpret_cast<byte*>(pStudioHeader) +
		pStudioHeader->seqindex) + pCurrentEntity->curstate.sequence;

	if (pEngfuncs) {
		if (pCurrentEntity == pEngfuncs->GetViewModel()) {
			if (CVars::bxt_viewmodel_disable_idle.GetBool()) {
				if (strstr(pseqdesc->label, "idle") != NULL || strstr(pseqdesc->label, "fidget") != NULL) {
					pCurrentEntity->curstate.framerate = 0; // don't animate at all
				}
			}

			if (CVars::bxt_viewmodel_disable_equip.GetBool()) {
				if (strstr(pseqdesc->label, "holster") != NULL || strstr(pseqdesc->label, "draw") != NULL ||
					strstr(pseqdesc->label, "deploy") != NULL || strstr(pseqdesc->label, "up") != NULL ||
					strstr(pseqdesc->label, "down") != NULL) {
					pCurrentEntity->curstate.sequence = 0; // instead set to idle sequence
					pseqdesc = reinterpret_cast<mstudioseqdesc_t*>(reinterpret_cast<byte*>(pStudioHeader) +
						pStudioHeader->seqindex) + pCurrentEntity->curstate.sequence;
					pseqdesc->numframes = 1;
					pseqdesc->fps = 1;
				}
			}
		}
	}

	ORIG_CStudioModelRenderer__StudioSetupBones_Linux(thisptr);
}

HOOK_DEF_3(ClientDLL, int, __cdecl, HUD_AddEntity, int, type, cl_entity_s*, ent, char*, modelname)
{
	if (CVars::bxt_show_hidden_entities_clientside.GetBool()) {
		if (ent->curstate.rendermode != kRenderNormal)
			ent->curstate.renderamt = 255;
	}

	return ORIG_HUD_AddEntity(type, ent, modelname);
}

HOOK_DEF_0(ClientDLL, int, __cdecl, CL_IsThirdPerson)
{
	const auto& hw = HwDLL::GetInstance();

	if (hw.insideCLEmitEntities && CVars::bxt_show_player_in_hltv.GetBool() && CVars::sv_cheats.GetBool())
		return 1;

	return ORIG_CL_IsThirdPerson();
}

HOOK_DEF_1(ClientDLL, void, __fastcall, CStudioModelRenderer__StudioRenderModel, void*, thisptr)
{
	auto pCurrentEntity = *reinterpret_cast<cl_entity_t**>(reinterpret_cast<uintptr_t>(thisptr) + 48);

	int old_rendermode = pCurrentEntity->curstate.rendermode;

	if (pEngfuncs) {
		if (pCurrentEntity == pEngfuncs->GetViewModel()) {
			if (CVars::bxt_viewmodel_semitransparent.GetBool()) {
				pEngfuncs->pTriAPI->RenderMode(kRenderTransAdd);
				pEngfuncs->pTriAPI->Brightness(2);
			} else {
				pEngfuncs->pTriAPI->RenderMode(old_rendermode);
			}
		}
	}

	ORIG_CStudioModelRenderer__StudioRenderModel(thisptr);
}

HOOK_DEF_1(ClientDLL, void, __cdecl, CStudioModelRenderer__StudioRenderModel_Linux, void*, thisptr)
{
	auto pCurrentEntity = *reinterpret_cast<cl_entity_t**>(reinterpret_cast<uintptr_t>(thisptr) + 44);

	int old_rendermode = pCurrentEntity->curstate.rendermode;

	if (pEngfuncs) {
		if (pCurrentEntity == pEngfuncs->GetViewModel()) {
			if (CVars::bxt_viewmodel_semitransparent.GetBool()) {
				pEngfuncs->pTriAPI->RenderMode(kRenderTransAdd);
				pEngfuncs->pTriAPI->Brightness(2);
			} else {
				pEngfuncs->pTriAPI->RenderMode(old_rendermode);
			}
		}
	}

	ORIG_CStudioModelRenderer__StudioRenderModel_Linux(thisptr);
}

HOOK_DEF_1(ClientDLL, void, __fastcall, CHudFlashlight__drawNightVision, void*, thisptr)
{
	if (CVars::bxt_disable_nightvision_sprite.GetBool())
		return;
	ORIG_CHudFlashlight__drawNightVision(thisptr);
}

HOOK_DEF_1(ClientDLL, void, __cdecl, CHudFlashlight__drawNightVision_Linux, void*, thisptr)
{
	if (CVars::bxt_disable_nightvision_sprite.GetBool())
		return;
	ORIG_CHudFlashlight__drawNightVision_Linux(thisptr);
}

HOOK_DEF_4(ClientDLL, void, __cdecl, ScaleColors, int*, r, int*, g, int*, b, int, a)
{
	if (custom_hud_color_set) {
		*r = custom_r;
		*g = custom_g;
		*b = custom_b;
	}

	if (CVars::bxt_hud_game_alpha.GetInt() >= 1 && CVars::bxt_hud_game_alpha.GetInt() <= 255)
		a = CVars::bxt_hud_game_alpha.GetInt();

	ORIG_ScaleColors(r, g, b, a);
}

HOOK_DEF_2(ClientDLL, int, __cdecl, Initialize, cl_enginefunc_t*, pEnginefuncs, int, iVersion)
{
	discord_integration::initialize();

	return ORIG_Initialize(pEnginefuncs, iVersion);
}

HOOK_DEF_0(ClientDLL, void, __cdecl, HUD_Shutdown)
{
	ORIG_HUD_Shutdown();

	discord_integration::shutdown();
}
