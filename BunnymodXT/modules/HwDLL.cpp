#include "../stdafx.hpp"

#include "../sptlib-wrapper.hpp"
#include <SPTLib/MemUtils.hpp>
#include <SPTLib/Hooks.hpp>
#include "HwDLL.hpp"
#include "ClientDLL.hpp"
#include "../patterns.hpp"
#include "../cvars.hpp"

// Linux hooks.
#ifndef _WIN32
extern "C" void __cdecl Cbuf_Execute()
{
	return HwDLL::HOOKED_Cbuf_Execute();
}
#endif

void HwDLL::Hook(const std::wstring& moduleName, void* moduleHandle, void* moduleBase, size_t moduleLength, bool needToIntercept)
{
	Clear(); // Just in case.

	m_Handle = moduleHandle;
	m_Base = moduleBase;
	m_Length = moduleLength;
	m_Name = moduleName;
	m_Intercepted = needToIntercept;

	FindStuff();

	if (needToIntercept)
		MemUtils::Intercept(moduleName, {
			{ reinterpret_cast<void**>(&ORIG_Cbuf_Execute), reinterpret_cast<void*>(HOOKED_Cbuf_Execute) },
			{ reinterpret_cast<void**>(&ORIG_SeedRandomNumberGenerator), reinterpret_cast<void*>(HOOKED_SeedRandomNumberGenerator) },
			{ reinterpret_cast<void**>(&ORIG_time), reinterpret_cast<void*>(HOOKED_time) },
			{ reinterpret_cast<void**>(&ORIG_RandomFloat), reinterpret_cast<void*>(HOOKED_RandomFloat) },
			{ reinterpret_cast<void**>(&ORIG_RandomLong), reinterpret_cast<void*>(HOOKED_RandomLong) }
		});
}

void HwDLL::Unhook()
{
	if (m_Intercepted)
		MemUtils::RemoveInterception(m_Name, {
			{ reinterpret_cast<void**>(&ORIG_Cbuf_Execute), reinterpret_cast<void*>(HOOKED_Cbuf_Execute) },
			{ reinterpret_cast<void**>(&ORIG_SeedRandomNumberGenerator), reinterpret_cast<void*>(HOOKED_SeedRandomNumberGenerator) },
			{ reinterpret_cast<void**>(&ORIG_time), reinterpret_cast<void*>(HOOKED_time) },
			{ reinterpret_cast<void**>(&ORIG_RandomFloat), reinterpret_cast<void*>(HOOKED_RandomFloat) },
			{ reinterpret_cast<void**>(&ORIG_RandomLong), reinterpret_cast<void*>(HOOKED_RandomLong) }
	});

	Clear();
}

void HwDLL::Clear()
{
	ORIG_Cbuf_Execute = nullptr;
	ORIG_SeedRandomNumberGenerator = nullptr;
	ORIG_time = nullptr;
	ORIG_RandomFloat = nullptr;
	ORIG_RandomLong = nullptr;
	ORIG_Cbuf_InsertText = nullptr;
	ORIG_Con_Printf = nullptr;
	ORIG_Cvar_RegisterVariable = nullptr;
	ORIG_Cvar_DirectSet = nullptr;
	ORIG_Cvar_FindVar = nullptr;
	ORIG_Cmd_AddMallocCommand = nullptr;
	ORIG_Cmd_Argc = nullptr;
	ORIG_Cmd_Args = nullptr;
	ORIG_Cmd_Argv = nullptr;
	registeredVarsAndCmds = false;
	cls = nullptr;
	sv = nullptr;
	cmd_text = nullptr;
	host_frametime = nullptr;
	executing = false;
	loading = false;
	insideCbuf_Execute = false;
	finishingLoad = false;
	dontPauseNextCycle = false;
	insideSeedRNG = false;
	player = {};
	input.Clear();
	runningFrames = false;
	wasRunningFrames = false;
	currentFramebulk = 0;
	totalFramebulks = 0;
	currentRepeat = 0;
}

void HwDLL::FindStuff()
{
	ORIG_Cbuf_Execute = reinterpret_cast<_Cbuf_Execute>(MemUtils::GetSymbolAddress(m_Handle, "Cbuf_Execute"));
	if (ORIG_Cbuf_Execute)
	{
		EngineDevMsg("[hw dll] Found Cbuf_Execute at %p.\n", ORIG_Cbuf_Execute);

		cls = MemUtils::GetSymbolAddress(m_Handle, "cls");
		if (cls)
			EngineDevMsg("[hw dll] Found cls at %p.\n", cls);
		else
			EngineDevWarning("[hw dll] Could not find cls.\n");

		sv = MemUtils::GetSymbolAddress(m_Handle, "sv");
		if (sv)
			EngineDevMsg("[hw dll] Found sv at %p.\n", sv);
		else
			EngineDevWarning("[hw dll] Could not find sv.\n");

		cmd_text = reinterpret_cast<cmdbuf_t*>(MemUtils::GetSymbolAddress(m_Handle, "cmd_text"));
		if (cmd_text)
			EngineDevMsg("[hw dll] Found cmd_text at %p.\n", cmd_text);
		else
			EngineDevWarning("[hw dll] Could not find cmd_text.\n");

		host_frametime = reinterpret_cast<double*>(MemUtils::GetSymbolAddress(m_Handle, "host_frametime"));
		if (host_frametime)
			EngineDevMsg("[hw dll] Found host_frametime at %p.\n", sv);
		else
			EngineDevWarning("[hw dll] Could not find host_frametime.\n");

		if (!cls || !sv || !cmd_text || !host_frametime)
			ORIG_Cbuf_Execute = nullptr;

		#define FIND(f) \
			ORIG_##f = reinterpret_cast<_##f>(MemUtils::GetSymbolAddress(m_Handle, #f)); \
			if (ORIG_##f) \
				EngineDevMsg("[hw dll] Found " #f " at %p.\n", ORIG_##f); \
			else \
			{ \
				EngineDevWarning("[hw dll] Could not find " #f ".\n"); \
				ORIG_Cbuf_Execute = nullptr; \
			}
		FIND(Con_Printf)
		FIND(Cvar_RegisterVariable)
		FIND(Cvar_DirectSet)
		FIND(Cvar_FindVar)
		FIND(Cbuf_InsertText)
		FIND(Cmd_AddMallocCommand)
		FIND(SeedRandomNumberGenerator)
		//FIND(RandomFloat)
		//FIND(RandomLong)
		#undef FIND
	}
	else
	{
		#define DEF_FUTURE(name) auto f##name = MemUtils::FindPatternOnly(reinterpret_cast<void**>(&ORIG_##name), m_Base, m_Length, Patterns::ptns##name, [](MemUtils::ptnvec_size ptnNumber) { }, []() { });
		DEF_FUTURE(Cvar_RegisterVariable)
		DEF_FUTURE(Cvar_DirectSet)
		DEF_FUTURE(Cvar_FindVar)
		DEF_FUTURE(Cbuf_InsertText)
		DEF_FUTURE(Cmd_AddMallocCommand)
		//DEF_FUTURE(RandomFloat)
		//DEF_FUTURE(RandomLong)
		#undef DEF_FUTURE

		auto fCbuf_Execute = MemUtils::FindPatternOnly(reinterpret_cast<void**>(&ORIG_Cbuf_Execute), m_Base, m_Length, Patterns::ptnsCbuf_Execute,
			[&](MemUtils::ptnvec_size ptnNumber) {
				switch (ptnNumber)
				{
				case 0:
					cmd_text = reinterpret_cast<cmdbuf_t*>(*reinterpret_cast<uintptr_t*>(reinterpret_cast<uintptr_t>(ORIG_Cbuf_Execute) + 11) - offsetof(cmdbuf_t, cursize));
					break;
				case 1:
					cmd_text = reinterpret_cast<cmdbuf_t*>(*reinterpret_cast<uintptr_t*>(reinterpret_cast<uintptr_t>(ORIG_Cbuf_Execute) + 2) - offsetof(cmdbuf_t, cursize));
					break;
				}
			}, []() {}
		);

		auto fSeedRandomNumberGenerator = MemUtils::FindPatternOnly(reinterpret_cast<void**>(&ORIG_SeedRandomNumberGenerator), m_Base, m_Length, Patterns::ptnsSeedRandomNumberGenerator,
			[&](MemUtils::ptnvec_size ptnNumber) {
				ORIG_time = reinterpret_cast<_time>(
					*reinterpret_cast<uintptr_t*>(reinterpret_cast<uintptr_t>(ORIG_SeedRandomNumberGenerator) + 3)
					+ reinterpret_cast<uintptr_t>(ORIG_SeedRandomNumberGenerator) + 7
				);
			}, []() {}
		);

		void *SCR_DrawFPS;
		auto fSCR_DrawFPS = MemUtils::FindPatternOnly(&SCR_DrawFPS, m_Base, m_Length, Patterns::ptnsSCR_DrawFPS,
			[&](MemUtils::ptnvec_size ptnNumber) {
				host_frametime = *reinterpret_cast<double**>(reinterpret_cast<uintptr_t>(SCR_DrawFPS) + 21);
			}, []() {}
		);

		void *Host_Tell_f;
		auto fHost_Tell_f = MemUtils::FindPatternOnly(&Host_Tell_f, m_Base, m_Length, Patterns::ptnsHost_Tell_f,
			[&](MemUtils::ptnvec_size ptnNumber) {
				uintptr_t offCmd_Argc, offCmd_Args, offCmd_Argv;
				switch (ptnNumber)
				{
				case 0: // SteamPipe.
					offCmd_Argc = 28;
					offCmd_Args = 42;
					offCmd_Argv = 145;
					break;
				case 1: // NGHL.
					offCmd_Argc = 24;
					offCmd_Args = 38;
					offCmd_Argv = 143;
					break;
				}

				auto f = reinterpret_cast<uintptr_t>(Host_Tell_f);
				ORIG_Cmd_Argc = reinterpret_cast<_Cmd_Argc>(
					*reinterpret_cast<uintptr_t*>(f + offCmd_Argc)
					+ (f + offCmd_Argc + 4)
				);
				ORIG_Cmd_Args = reinterpret_cast<_Cmd_Args>(
					*reinterpret_cast<uintptr_t*>(f + offCmd_Args)
					+ (f + offCmd_Args + 4)
				);
				ORIG_Cmd_Argv = reinterpret_cast<_Cmd_Argv>(
					*reinterpret_cast<uintptr_t*>(f + offCmd_Argv)
					+ (f + offCmd_Argv + 4)
				);
			}, []() { }
		);

		void *Host_AutoSave_f;
		auto fHost_AutoSave_f = MemUtils::FindPatternOnly(&Host_AutoSave_f, m_Base, m_Length, Patterns::ptnsHost_AutoSave_f,
			[&](MemUtils::ptnvec_size ptnNumber) {
				auto f = reinterpret_cast<uintptr_t>(Host_AutoSave_f);
				sv = *reinterpret_cast<void**>(f + 19);
				ORIG_Con_Printf = reinterpret_cast<_Con_Printf>(
					*reinterpret_cast<ptrdiff_t*>(f + 33)
					+ (f + 37)
					);
				cls = *reinterpret_cast<void**>(f + 69);
			}, []() {}
		);

		auto n = fCbuf_Execute.get();
		if (ORIG_Cbuf_Execute) {
			EngineDevMsg("[hw dll] Found Cbuf_Execute at %p (using the %s pattern).\n", ORIG_Cbuf_Execute, Patterns::ptnsCbuf_Execute[n].build.c_str());
			EngineDevMsg("[hw dll] Found cmd_text at %p.\n", cmd_text);
		} else
			EngineDevWarning("[hw dll] Could not find Cbuf_Execute.\n");

		n = fHost_AutoSave_f.get();
		if (Host_AutoSave_f) {
			EngineDevMsg("[hw dll] Found Host_AutoSave_f at %p (using the %s pattern).\n", Host_AutoSave_f, Patterns::ptnsHost_AutoSave_f[n].build.c_str());
			EngineDevMsg("[hw dll] Found cls at %p.\n", cls);
			EngineDevMsg("[hw dll] Found sv at %p.\n", sv);
			EngineDevMsg("[hw dll] Found Con_Printf at %p.\n", ORIG_Con_Printf);
		} else {
			EngineDevWarning("[hw dll] Could not find Host_AutoSave_f.\n");
			ORIG_Cbuf_Execute = nullptr;
		}

		n = fSeedRandomNumberGenerator.get();
		if (ORIG_SeedRandomNumberGenerator) {
			EngineDevMsg("[hw dll] Found SeedRandomNumberGenerator at %p (using the %s pattern).\n", ORIG_SeedRandomNumberGenerator, Patterns::ptnsSeedRandomNumberGenerator[n].build.c_str());
			EngineDevMsg("[hw dll] ORIG_time is %p.\n", ORIG_time);
		} else {
			EngineDevWarning("[hw dll] Could not find SeedRandomNumberGenerator.\n");
			ORIG_Cbuf_Execute = nullptr;
		}

		n = fSCR_DrawFPS.get();
		if (SCR_DrawFPS) {
			EngineDevMsg("[hw dll] Found SCR_DrawFPS at %p (using the %s pattern).\n", SCR_DrawFPS, Patterns::ptnsSCR_DrawFPS[n].build.c_str());
			EngineDevMsg("[hw dll] Found host_frametime at %p.\n", host_frametime);
		} else {
			EngineDevWarning("[hw dll] Could not find SCR_DrawFPS.\n");
			ORIG_Cbuf_Execute = nullptr;
		}

		#define GET_FUTURE(name) \
			n = f##name.get(); \
			if (ORIG_##name) { \
				EngineDevMsg("[hw dll] Found " #name " at %p (using the %s pattern).\n", ORIG_##name, Patterns::ptns##name[n].build.c_str()); \
			} else { \
				EngineDevWarning("[hw dll] Could not find " #name ".\n"); \
				ORIG_Cbuf_Execute = nullptr; \
			}
		GET_FUTURE(Cvar_RegisterVariable)
		GET_FUTURE(Cvar_DirectSet)
		GET_FUTURE(Cvar_FindVar)
		GET_FUTURE(Cbuf_InsertText)
		GET_FUTURE(Cmd_AddMallocCommand)
		//GET_FUTURE(RandomFloat)
		//GET_FUTURE(RandomLong)
		#undef GET_FUTURE

		n = fHost_Tell_f.get();
		if (Host_Tell_f) {
			EngineDevMsg("[hw dll] Found Host_Tell_f at %p (using the %s pattern).\n", Host_Tell_f, Patterns::ptnsHost_Tell_f[n].build.c_str());
			EngineDevMsg("[hw dll] Found Cmd_Argc at %p.\n", ORIG_Cmd_Argc);
			EngineDevMsg("[hw dll] Found Cmd_Args at %p.\n", ORIG_Cmd_Args);
			EngineDevMsg("[hw dll] Found Cmd_Argv at %p.\n", ORIG_Cmd_Argv);
		} else {
			EngineDevWarning("[hw dll] Could not find Host_Tell_f.\n");
			ORIG_Cmd_AddMallocCommand = nullptr;
			ORIG_Cbuf_Execute = nullptr;
		}
	}

	if (ORIG_Cbuf_Execute && !ORIG_time)
		ORIG_time = time;
}

void HwDLL::Cmd_BXT_TAS_LoadScript()
{
	return HwDLL::GetInstance().Cmd_BXT_TAS_LoadScript_f();
}
void HwDLL::Cmd_BXT_TAS_LoadScript_f()
{
	runningFrames = false;
	currentFramebulk = 0;
	currentRepeat = 0;

	if (ORIG_Cmd_Argc() != 2) {
		ORIG_Con_Printf("Usage: bxt_tas_loadscript <filename>\n");
		return;
	}

	ORIG_Cvar_DirectSet(bxt_tas.GetPointer(), "1");

	std::string filename(ORIG_Cmd_Argv(1));
	auto err = input.Open(filename).get();
	if (err.Code != HLTAS::ErrorCode::OK) {
		ORIG_Con_Printf("Error loading the script file on line %u: %s\n", err.LineNumber, HLTAS::GetErrorMessage(err));
		return;
	}

	if (!input.GetFrames().empty()) {
		runningFrames = true;
		totalFramebulks = input.GetFrames().size();
		std::ostringstream ss;
		ss << "host_framerate " << input.GetFrame(0).Frametime.c_str() << "\n";
		ORIG_Cbuf_InsertText(ss.str().c_str());
	}
}

void HwDLL::RegisterCVarsAndCommandsIfNeeded()
{
	if (!registeredVarsAndCmds)
	{
		registeredVarsAndCmds = true;
		if (ORIG_Cvar_RegisterVariable)
		{
			ORIG_Cvar_RegisterVariable(bxt_tas.GetPointer());
			ORIG_Cvar_RegisterVariable(_bxt_taslog.GetPointer());
		}
		if (ORIG_Cmd_AddMallocCommand)
			ORIG_Cmd_AddMallocCommand("bxt_tas_loadscript", Cmd_BXT_TAS_LoadScript, 2); // 2 - Cmd_AddGameCommand.
	}
}

bool HwDLL::CheckUnpause()
{
	size_t current_cmd;
	for (size_t off = 0; off < cmd_text->cursize; ++off)
	{
		current_cmd = off;
		unsigned quotes = 0;
		for (; off < cmd_text->cursize; ++off)
		{
			char c = cmd_text->data[off];
			quotes += (c == '"');
			if (!(quotes & 1) && c == ';')
				break;
			if (c == '\n')
				break;
		}

		if (off - current_cmd == 7 && !std::strncmp(cmd_text->data + current_cmd, "unpause", 7))
			return true;
	}

	return false;
}

void HwDLL::InsertCommands()
{
	if (currentFramebulk >= totalFramebulks)
		runningFrames = false;

	if (runningFrames) {
		auto f = input.GetFrames()[currentFramebulk];
		auto p = HLStrafe::MainFunc(player, GetMovementVars(), f);

		// TODO viewangles.

		#define INS(btn, cmd) \
			if (p.btn && !previousButtons.btn) \
				ORIG_Cbuf_InsertText("+" #cmd "\n"); \
			else if (!p.btn && previousButtons.btn) \
				ORIG_Cbuf_InsertText("-" #cmd "\n");
		INS(Forward, forward)
		INS(Left, moveleft)
		INS(Right, moveright)
		INS(Back, back)
		INS(Up, moveup)
		INS(Down, movedown)
		INS(Jump, jump)
		INS(Duck, duck)
		INS(Use, use)
		INS(Attack1, attack)
		INS(Attack2, attack2)
		INS(Reload, reload)
		#undef INS

		// TODO speeds.

		// We need this to be in the beginning of the buffer.
		if (!wasRunningFrames)
			ResetButtons();

		previousButtons = p;

		if (++currentRepeat >= f.GetRepeats()) {
			currentFramebulk++;
			currentRepeat = 0;
			if (currentFramebulk < totalFramebulks) {
				auto next = input.GetFrame(currentFramebulk);
				if (next.Frametime != f.Frametime) {
					std::ostringstream ss;
					ss << "host_framerate " << next.Frametime.c_str() << "\n";
					ORIG_Cbuf_InsertText(ss.str().c_str());
				}
			}
		}
	} else {
		if (wasRunningFrames)
			ResetButtons();
	}

	wasRunningFrames = runningFrames;
}

void HwDLL::ResetButtons()
{
	ORIG_Cbuf_InsertText("-forward\n"
	                     "-moveleft\n"
	                     "-moveright\n"
	                     "-back\n"
	                     "-moveup\n"
	                     "-movedown\n"
	                     "-left\n"
	                     "-right\n"
	                     "-lookup\n"
	                     "-lookdown\n"
	                     "-jump\n"
	                     "-duck\n"
	                     "-use\n"
	                     "-attack\n"
	                     "-attack2\n"
	                     "-reload\n");
	previousButtons = {};
}

void HwDLL::FindCVarsIfNeeded()
{
	if (sv_maxvelocity_.GetPointer())
		return;

	sv_maxvelocity_.Assign(ORIG_Cvar_FindVar("sv_maxvelocity"));
	sv_maxspeed_.Assign(ORIG_Cvar_FindVar("sv_maxspeed"));
	sv_stopspeed_.Assign(ORIG_Cvar_FindVar("sv_stopspeed"));
	sv_friction_.Assign(ORIG_Cvar_FindVar("sv_friction"));
	sv_edgefriction_.Assign(ORIG_Cvar_FindVar("sv_edgefriction"));
	sv_accelerate_.Assign(ORIG_Cvar_FindVar("sv_accelerate"));
	sv_airaccelerate_.Assign(ORIG_Cvar_FindVar("sv_airaccelerate"));
	sv_gravity_.Assign(ORIG_Cvar_FindVar("sv_gravity"));
}

HLStrafe::MovementVars HwDLL::GetMovementVars()
{
	HLStrafe::MovementVars vars = {};
	
	FindCVarsIfNeeded();
	vars.Frametime = static_cast<float>(*host_frametime);
	vars.Maxvelocity = sv_maxvelocity_.GetFloat();
	vars.Maxspeed = sv_maxspeed_.GetFloat();
	vars.Stopspeed = sv_stopspeed_.GetFloat();
	vars.Friction = sv_friction_.GetFloat();
	vars.Edgefriction = sv_edgefriction_.GetFloat();
	vars.EntFriction = 1.0f; // TBD
	vars.Accelerate = sv_accelerate_.GetFloat();
	vars.Airaccelerate = sv_airaccelerate_.GetFloat();
	vars.Gravity = sv_gravity_.GetFloat();
	vars.EntGravity = 1.0f; // TBD

	return vars;
}

void HwDLL::SetPlayerOrigin(float origin[3])
{
	player.Origin[0] = origin[0];
	player.Origin[1] = origin[1];
	player.Origin[2] = origin[2];
}

void HwDLL::SetPlayerVelocity(float velocity[3])
{
	player.Velocity[0] = velocity[0];
	player.Velocity[1] = velocity[1];
	player.Velocity[2] = velocity[2];
}

HOOK_DEF_0(HwDLL, void, __cdecl, Cbuf_Execute)
{
	RegisterCVarsAndCommandsIfNeeded();

	int state = *reinterpret_cast<int*>(cls);
	int paused = *(reinterpret_cast<int*>(sv) + 1);

	// If cls.state == 4 and the game isn't paused, execute "pause" right now.
	// This case happens when loading a savegame.
	if (state == 4 && !paused && bxt_tas.GetBool())
	{
		ORIG_Cbuf_InsertText("pause\n");
		finishingLoad = true;
	}

	// All map load / change commands call Cbuf_Execute inside them, while we already are inside one.
	if (insideCbuf_Execute)
	{
		loading = true;
		executing = false;
	}
	if (state != 5)
		executing = false;
	if (!loading && state == 5)
		executing = true;
	if (loading && state == 3)
		loading = false;
	// Manually unpause in WON.
	if (finishingLoad && state == 5 && paused && !CheckUnpause())
		ORIG_Cbuf_InsertText("pause\n");

	static unsigned counter = 1;
	auto c = counter++;
	std::string buf(cmd_text->data, cmd_text->cursize); // TODO: ifdef this so it doesn't waste performance.
	if (_bxt_taslog.GetBool())
		ORIG_Con_Printf("Cbuf_Execute() #%u begin; cls.state: %d; sv.paused: %d; time: %f; loading: %s; executing: %s; host_frametime: %f; buffer: %s\n", c, state, paused, *reinterpret_cast<double*>(reinterpret_cast<uintptr_t>(sv)+16), (loading ? "true" : "false"), (executing ? "true" : "false"), *host_frametime, buf.c_str());

	insideCbuf_Execute = true;
	ORIG_Cbuf_Execute(); // executing might change inside if we had some kind of load command in the buffer.

	// Insert our commands after any commands that might have been on this frame
	// and call Cbuf_Execute again to execute them.
	if (executing)
	{
		finishingLoad = false;
		// For stopping Cbuf_Execute. Goes first because InsertCommands() inserts into beginning.
		if (cmd_text->cursize)
			ORIG_Cbuf_InsertText("wait\n");
		InsertCommands();

		buf.assign(cmd_text->data, cmd_text->cursize);
		if (_bxt_taslog.GetBool())
			ORIG_Con_Printf("Cbuf_Execute() #%u executing; buffer: %s\n", c, buf.c_str());

		// Setting to true once again because it might have been reset in Cbuf_Execute.
		insideCbuf_Execute = true;
		ORIG_Cbuf_Execute();
	}
	insideCbuf_Execute = false;

	buf.assign(cmd_text->data, cmd_text->cursize);
	if (_bxt_taslog.GetBool())
		ORIG_Con_Printf("Cbuf_Execute() #%u end; host_frametime: %f; buffer: %s\n", c, *host_frametime, buf.c_str());

	// If cls.state == 3 and the game isn't paused, execute "pause" on the next cycle.
	// This case happens when starting a map.
	if (!dontPauseNextCycle && state == 3 && !paused && bxt_tas.GetBool())
	{
		ORIG_Cbuf_InsertText("pause\n");
		finishingLoad = true;
		dontPauseNextCycle = true;
	}
	else
		dontPauseNextCycle = false;
}

HOOK_DEF_0(HwDLL, void, __cdecl, SeedRandomNumberGenerator)
{
	insideSeedRNG = true;
	EngineMsg("Calling SeedRandomNumberGenerator!\n");
	ORIG_SeedRandomNumberGenerator();
	insideSeedRNG = false;
}

HOOK_DEF_1(HwDLL, time_t, __cdecl, time, time_t*, Time)
{
	if (insideSeedRNG)
	{
		EngineMsg("Called time from SeedRandomNumberGenerator!\n");
		return 0;
	}

	return ORIG_time(Time);
}

HOOK_DEF_2(HwDLL, long double, __cdecl, RandomFloat, float, a1, float, a2)
{
	//ORIG_Con_Printf("Calling RandomFloat.\n");
	return ORIG_RandomFloat(a1, a2);
}

HOOK_DEF_2(HwDLL, long, __cdecl, RandomLong, long, a1, long, a2)
{
	//ORIG_Con_Printf("Calling RandomLong.\n");
	return ORIG_RandomLong(a1, a2);
}
