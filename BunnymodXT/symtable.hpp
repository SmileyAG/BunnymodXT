#pragma once

/*
	This file is intended to declare symbols for accessing functions.

	Macros here must have a strict declaration format and it looks like this:

	1. The macro must begin with the SYM_ prefix.
	2. Then the name of the module from which this symbol is taken is indicated. Here is a list of the following available module names: HW_, CL_, SV_.
	3. Then the name of the function. If it's a class function then you must replace the :: with __ for format.
	4. And at the end a suffix must be added indicating the platform under which this symbol serves. Here is a list of the following available module names: _WIN, _LINUX.

	MacOS symbols seem to differ from Linux symbols only in that there is an additional underscore at the beginning of the symbol.
	So if someone wants to add support for MacOS, you can just take a Linux symbol and use the BXT_CONCATENATE_DETAIL(_, symbol) macro to add an extra underscore to the beginning of the symbol in hooking code.
*/

#define SYM_SV_DispatchSpawn_LINUX _Z13DispatchSpawnP7edict_s
#define SYM_SV_DispatchTouch_LINUX _Z13DispatchTouchP7edict_sS0_
#define SYM_SV_DispatchKeyValue_LINUX _Z16DispatchKeyValueP7edict_sP14KeyValueData_s
#define SYM_SV_ClientCommand_LINUX _Z13ClientCommandP7edict_s
#define SYM_SV_ServerActivate_LINUX _Z14ServerActivateP7edict_sii
#define SYM_SV_ServerDeactivate_LINUX _Z16ServerDeactivatev
#define SYM_SV_PlayerPreThink_LINUX _Z14PlayerPreThinkP7edict_s
#define SYM_SV_PlayerPostThink_LINUX _Z15PlayerPostThinkP7edict_s
#define SYM_SV_PM_Move_LINUX PM_Move
#define SYM_SV_AddToFullPack_LINUX _Z13AddToFullPackP14entity_state_siP7edict_sS2_iiPh
#define SYM_SV_CmdStart_LINUX _Z8CmdStartPK7edict_sPK9usercmd_sj
#define SYM_SV_CmdEnd_LINUX _Z6CmdEndPK7edict_s
