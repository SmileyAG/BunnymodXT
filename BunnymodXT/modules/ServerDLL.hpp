#pragma once

#include <deque>
#include "../sptlib-wrapper.hpp"
#include <SPTLib/IHookableDirFilter.hpp>
#include "taslogger/writer.hpp"

class ServerDLL : public IHookableDirFilter
{
	HOOK_DECL(void, __cdecl, PM_Jump) // PM_Jump (non-exported)
	HOOK_DECL(void, __cdecl, PM_PreventMegaBunnyJumping) // PM_PreventMegaBunnyJumping (non-exported)
	HOOK_DECL(void, __cdecl, PM_PlayerMove, qboolean server) // PM_PlayerMove (non-exported)
	HOOK_DECL(int, __cdecl, PM_ClipVelocity, float in[3], float normal[3], float out[3], float overbounce) // PM_ClipVelocity (non-exported)
	HOOK_DECL(void, __cdecl, PM_WaterMove) // PM_WaterMove (non-exported)
	HOOK_DECL(void, __cdecl, PM_WalkMove) // PM_WalkMove (non-exported)
	HOOK_DECL(void, __cdecl, PM_FlyMove) // PM_FlyMove (non-exported)
	HOOK_DECL(bool, __cdecl, PM_AddToTouched, pmtrace_t tr, float* impactvelocity) // PM_AddToTouched (non-exported)
	HOOK_DECL(void, __cdecl, PM_Move, struct playermove_s* ppmove, int server) // PM_Move (exported from DLL_FUNCTIONS struct)
	HOOK_DECL(void, __cdecl, CmdStart, const edict_t* player, const usercmd_t* cmd, unsigned int random_seed) // _Z8CmdStartPK7edict_sPK9usercmd_sj (Linux, for Windows it's exported from DLL_FUNCTIONS struct)
	HOOK_DECL(void, __fastcall, CNihilanth__DyingThink, void* thisptr, int edx) // ?DyingThink@CNihilanth@@QAEXXZ (exported)
	HOOK_DECL(void, __cdecl, CNihilanth__DyingThink_Linux, void* thisptr) // _ZN10CNihilanth10DyingThinkEv
	HOOK_DECL(void, __fastcall, COFGeneWorm__DyingThink, void* thisptr, int edx) // ?DyingThink@COFGeneWorm@@QAEXXZ (exported, game: Half-Life Opposing Force)
	HOOK_DECL(void, __cdecl, COFGeneWorm__DyingThink_Linux, void* thisptr) // _ZN11COFGeneWorm10DyingThinkEv (Game: Half-Life Opposing Force)
	HOOK_DECL(void, __fastcall, CApache__DyingThink, void* thisptr) // ?DyingThink@CApache@@AAEXXZ (exported)
	//HOOK_DECL(void, __cdecl, CApache__DyingThink_Linux, void* thisptr) // _ZN7CApache10DyingThinkEv
	HOOK_DECL(void, __fastcall, CBreakable__Die, void* thisptr, int edx) // ?Die@CBreakable@@QAEXXZ (exported)
	HOOK_DECL(void, __cdecl, CBreakable__Die_Linux, void* thisptr) // _ZN10CBreakable3DieEv
	HOOK_DECL(int, __fastcall, CBaseDoor__DoorActivate, void* thisptr, int edx) // ?DoorActivate@CBaseDoor@@QAEHXZ (non-exported)
	HOOK_DECL(void, __fastcall, CBaseDoor__DoorGoUp, void* thisptr) // ?DoorGoUp@CBaseDoor@@QAEXXZ (exported)
	HOOK_DECL(void, __fastcall, CBaseDoor__DoorHitTop, void* thisptr) // ?DoorHitTop@CBaseDoor@@QAEXXZ (exported)
	HOOK_DECL(void, __fastcall, CBaseMonster__Killed, void* thisptr, int edx, entvars_t* pevAttacker, int iGib) // ?Killed@CBaseMonster@@UAEXPAUentvars_s@@H@Z (non-exported)
	//HOOK_DECL(void, __cdecl, CBaseMonster__Killed_Linux, void* thisptr, entvars_t* pevAttacker, int iGib) // _ZN12CBaseMonster6KilledEP9entvars_si
	HOOK_DECL(void, __fastcall, CMultiManager__ManagerThink, void* thisptr, int edx) // ?ManagerThink@CMultiManager@@QAEXXZ (exported)
	//HOOK_DECL(void, __cdecl, CMultiManager__ManagerThink_Linux, void* thisptr) // _ZN13CMultiManager12ManagerThinkEv
	HOOK_DECL(void, __cdecl, FireTargets_Linux, char* targetName, void* pActivator, void* pCaller, int useType, float value) // FireTargets (non-exported)
																															// _Z11FireTargetsPKcP11CBaseEntityS2_8USE_TYPEf
	HOOK_DECL(int, __cdecl, AddToFullPack, struct entity_state_s* state, int e, edict_t* ent, edict_t* host, int hostflags, int player, unsigned char* pSet) // _Z13AddToFullPackP14entity_state_siP7edict_sS2_iiPh (Linux, for Windows it's exported from DLL_FUNCTIONS struct)
	HOOK_DECL(void, __fastcall, CTriggerVolume__Spawn, void* thisptr) // ?Spawn@CTriggerVolume@@UAEXXZ (non-exported)
	HOOK_DECL(void, __cdecl, CTriggerVolume__Spawn_Linux, void* thisptr) // _ZN14CTriggerVolume5SpawnEv
	HOOK_DECL(void, __cdecl, ClientCommand, edict_t* pEntity) // _Z13ClientCommandP7edict_s (Linux, for Windows it's exported from DLL_FUNCTIONS struct)
	HOOK_DECL(void, __fastcall, CPushable__Move, void* thisptr, int edx, void* pOther, int push) // ?Move@CPushable@@QAEXPAVCBaseEntity@@H@Z (non-exported)
	HOOK_DECL(void, __cdecl, CPushable__Move_Linux, void* thisptr, void* pOther, int push) // _ZN9CPushable4MoveEP11CBaseEntityi
	HOOK_DECL(int, __fastcall, CBasePlayer__TakeDamage, void* thisptr, int edx, entvars_t* pevInflictor, entvars_t* pevAttacker, float flDamage, int bitsDamageType) // ?TakeDamage@CBasePlayer@@UAEHPAUentvars_s@@0MH@Z (non-exported)
	HOOK_DECL(int, __cdecl, CBasePlayer__TakeDamage_Linux, void* thisptr, entvars_t* pevInflictor, entvars_t* pevAttacker, float flDamage, int bitsDamageType) // _ZN11CBasePlayer10TakeDamageEP9entvars_sS1_fi
	HOOK_DECL(void, __fastcall, CGraph__InitGraph, void* thisptr) // ?InitGraph@CGraph@@QAEXXZ (non-exported)
	HOOK_DECL(void, __cdecl, CGraph__InitGraph_Linux, void* thisptr) // _ZN6CGraph9InitGraphEv
	HOOK_DECL(void, __fastcall, CBasePlayer__CheatImpulseCommands, void* thisptr, int edx, int iImpulse) // ?CheatImpulseCommands@CBasePlayer@@QAEXH@Z (non-exported)
	HOOK_DECL(void, __cdecl, CBasePlayer__CheatImpulseCommands_Linux, void* thisptr, int iImpulse) // _ZN11CBasePlayer20CheatImpulseCommandsEi
	HOOK_DECL(void, __fastcall, CTriggerSave__SaveTouch, void* thisptr, int edx, void* pOther) // ?SaveTouch@CTriggerSave@@QAEXPAVCBaseEntity@@@Z (exported)
	HOOK_DECL(void, __cdecl, CTriggerSave__SaveTouch_Linux, void* thisptr, void* pOther) // _ZN12CTriggerSave9SaveTouchEP11CBaseEntity
	HOOK_DECL(void, __fastcall, CChangeLevel__UseChangeLevel, void* thisptr, int edx, void* pActivator, void* pCaller, int useType, float value) // ?UseChangeLevel@CChangeLevel@@QAEXPAVCBaseEntity@@0W4USE_TYPE@@M@Z (exported)
	//HOOK_DECL(void, __cdecl, CChangeLevel__UseChangeLevel_Linux, void* thisptr, void* pActivator, void* pCaller, int useType, float value) // _ZN12CChangeLevel14UseChangeLevelEP11CBaseEntityS1_8USE_TYPEf
	HOOK_DECL(void, __fastcall, CChangeLevel__TouchChangeLevel, void* thisptr, int edx, void* pOther) // ?TouchChangeLevel@CChangeLevel@@QAEXPAVCBaseEntity@@@Z (exported)
	//HOOK_DECL(void, __cdecl, CChangeLevel__TouchChangeLevel_Linux, void* thisptr, void* pOther) // _ZN12CChangeLevel16TouchChangeLevelEP11CBaseEntity
	HOOK_DECL(void, __fastcall, CBaseEntity__FireBullets, void* thisptr, int param1, unsigned long cShots, Vector vecSrc, Vector vecDirShooting, Vector vecSpread, float flDistance, int iBulletType, int iTracerFreq, int iDamage, entvars_t* pevAttacker) // ?FireBullets@CBaseEntity@@QAEXKVVector@@00MHHHPAUentvars_s@@@Z (non-exported)
	HOOK_DECL(void, __cdecl, CBaseEntity__FireBullets_Linux, void* thisptr, unsigned long cShots, Vector vecSrc, Vector vecDirShooting, Vector vecSpread, float flDistance, int iBulletType, int iTracerFreq, int iDamage, entvars_t* pevAttacker) // _ZN11CBaseEntity11FireBulletsEj6VectorS0_S0_fiiiP9entvars_s
	HOOK_DECL(void, __fastcall, CBaseEntity__FireBulletsPlayer, void* thisptr, int edx, float param1, unsigned long cShots, Vector vecSrc, Vector vecDirShooting, Vector vecSpread, float flDistance, int iBulletType, int iTracerFreq, int iDamage, entvars_t* pevAttacker, int shared_rand) // ?FireBulletsPlayer@CBaseEntity@@QAE?AVVector@@KV2@00MHHHPAUentvars_s@@H@Z (non-exported)
	HOOK_DECL(Vector, __cdecl, CBaseEntity__FireBulletsPlayer_Linux, void* thisptr, unsigned long cShots, Vector vecSrc, Vector vecDirShooting, Vector vecSpread, float flDistance, int iBulletType, int iTracerFreq, int iDamage, entvars_t* pevAttacker, int shared_rand) // _ZN11CBaseEntity17FireBulletsPlayerEj6VectorS0_S0_fiiiP9entvars_si
	HOOK_DECL(void, __fastcall, CBaseButton__ButtonUse, void* thisptr, int edx, void* pActivator, void* pCaller, int useType, float value) // ?ButtonUse@CBaseButton@@QAEXPAVCBaseEntity@@0W4USE_TYPE@@M@Z (exported)
	HOOK_DECL(void, __fastcall, CBaseButton__ButtonTriggerAndWait, void* thisptr, int edx) // ?TriggerAndWait@CBaseButton@@QAEXXZ (exported)
	HOOK_DECL(void, __fastcall, CTriggerEndSection__EndSectionUse, void* thisptr, int edx, void* pActivator, void* pCaller, int useType, float value) // ?EndSectionUse@CTriggerEndSection@@QAEXPAVCBaseEntity@@0W4USE_TYPE@@M@Z (exported)
	HOOK_DECL(void, __fastcall, CTriggerEndSection__EndSectionTouch, void* thisptr, int edx, void* pOther) // ?EndSectionTouch@CTriggerEndSection@@QAEXPAVCBaseEntity@@@Z (exported)
	HOOK_DECL(void, __cdecl, PM_Duck) // PM_Duck (non-exported)
	HOOK_DECL(void, __cdecl, PM_UnDuck) // PM_UnDuck (non-exported)
	HOOK_DECL(void, __cdecl, ShiftMonsters, Vector origin) // Game: Cry of Fear (Patch 1.2 and newer)
	HOOK_DECL(void, __fastcall, CBasePlayer__ViewPunch, void* thisptr, int edx, float p, float y, float r) // Game: PARANOIA, Cry of Fear
	HOOK_DECL(void, __fastcall, CBasePlayer__Jump, void* thisptr) // ?Jump@CBasePlayer@@UAEXXZ (non-exported, 4 entries above of CBasePlayer::UpdateClientData in CBasePlayer vtable)
	//HOOK_DECL(void, __cdecl, CBasePlayer__Jump_Linux, void* thisptr) // _ZN11CBasePlayer4JumpEv
	//HOOK_DECL(void, __cdecl, PlayerPreThink, edict_t* pEntity) // _Z14PlayerPreThinkP7edict_s (Linux, for Windows it's exported from DLL_FUNCTIONS struct)
	HOOK_DECL(void, __cdecl, PlayerPostThink, edict_t* pEntity) // _Z15PlayerPostThinkP7edict_s (Linux, for Windows it's exported from DLL_FUNCTIONS struct)
	//HOOK_DECL(void, __fastcall, COsprey__DyingThink, void* thisptr, int edx) // ?DyingThink@COsprey@@QAEXXZ (exported)
	//HOOK_DECL(void, __cdecl, COsprey__DyingThink_Linux, void* thisptr) // _ZN7COsprey10DyingThinkEv
	//HOOK_DECL(void, __fastcall, CBaseTrigger__TeleportTouch, void* thisptr, int edx, void* pOther) // ?TeleportTouch@CBaseTrigger@@QAEXPAVCBaseEntity@@@Z (exported)
	//HOOK_DECL(void, __cdecl, CBaseTrigger__TeleportTouch_Linux, void* thisptr, void* pOther) // _ZN12CBaseTrigger13TeleportTouchEP11CBaseEntity
	//HOOK_DECL(void, __cdecl, ClientPutInServer, edict_t* pEntity) // _Z17ClientPutInServerP7edict_s (Linux, for Windows it's exported from DLL_FUNCTIONS struct)
	//HOOK_DECL(void, __cdecl, player, entvars_t* pev) // player (exported)
	//HOOK_DECL(int, __cdecl, DispatchSpawn, edict_t *pent) // _Z13DispatchSpawnP7edict_s (Linux, for Windows it's exported from DLL_FUNCTIONS struct)
	//HOOK_DECL(void, __cdecl, DispatchTouch, edict_t *pentTouched, edict_t *pentOther) // _Z13DispatchTouchP7edict_sS0_ (Linux, for Windows it's exported from DLL_FUNCTIONS struct)
	//HOOK_DECL(void, __cdecl, CChangeLevel__ChangeLevelNow_Linux, void* thisptr, void* pActivator) // _ZN12CChangeLevel14ChangeLevelNowEP11CBaseEntity

public:
	static ServerDLL& GetInstance()
	{
		static ServerDLL instance;
		return instance;
	}

	virtual void Hook(const std::wstring& moduleName, void* moduleHandle, void* moduleBase, size_t moduleLength, bool needToIntercept);
	virtual void Unhook();
	virtual void Clear();
	virtual bool CanHook(const std::wstring& moduleFullName);

	bool GetGlobalState(const std::string& name, int& state);

	std::vector<const edict_t *> GetUseableEntities(const Vector &origin, float radius) const;
	std::vector<const Vector *> GetNodePositions() const;
	std::vector<const Vector *> GetDisplacerTargets() const;
	bool GetNihilanthInfo(float &health, int &level, int &irritation, bool &recharger, int &nspheres, int &sequence, float &frame) const;

	bool GetGonarchInfo(float& health, int& sequence, float& frame) const;

	static void OnMultiManagerFired(const char *classname);

	static void DoAutoStopTasks();

	static void GetTriggerColor(const char *classname, float &r, float &g, float &b);
	static const char* GetClassNameFromTriggerColor(int r, int g, int b);

	static void GetTriggerAlpha(const char *classname, bool inactive, bool additive, float &a);

	TraceResult TraceLine(const float v1[3], const float v2[3], int fNoMonsters, edict_t *pentToSkip) const;

	enginefuncs_t *pEngfuncs; // g_engfuncsExportedToDlls (type: enginefuncs_t, global variable)

	entvars_t *obboPushable = nullptr;

	const std::deque<std::array<Vector, 2>>& GetBulletsEnemyTrace() const;
	const std::deque<bool>& GetBulletsEnemyTraceHit() const;
	const std::deque<std::array<Vector, 2>>& GetBulletsPlayerTrace() const;
	const std::deque<bool>& GetBulletsPlayerTraceHit() const;
	void ClearBulletsTrace();
	void ClearBulletsEnemyTrace();
	void TraceLineWrap(const Vector* vecStart, const Vector* vecEnd, int igmon, edict_t* pentIgnore, TraceResult* ptr);

	void SetStamina(bool makeItZero);

	/*
		Cry of Fear source code is based on the SDK from PARANOIA modification
		PARANOIA SDK is open-source and can be found on GitHub
		And, CoF developers left the .pdb file for server-side DLL in mod versions

		CoF versions prior to 1.6 patch are called mods since it installs over of regular GoldSrc builds
		Starting from 1.6, it is distributed as a free standalone game on Steam and uses its own modified fork of pre-Steampipe engine (entvars_t structure is modified, making it incompatible with regular engine versions)
	*/

	bool is_paranoia = false;
	bool is_cof = false; // Cry of Fear-specific
	//bool is_cof_old_stats = false; // Cry of Fear-specific
	//ptrdiff_t offplayerstats; // playerstats (class: CBasePlayer, type: statistics, game: Cry of Fear)
	//ptrdiff_t offm_iKeypadNumber; // m_iKeypadNumber (class: CBasePlayer, type: int, game: Cry of Fear)
	ptrdiff_t offm_fStamina; // m_fStamina (class: CBasePlayer, type: float, game: Cry of Fear)
	//ptrdiff_t offm_iPadlockNumber; // m_iPadlockNumber (class: CBasePlayer, type: int[5], game: Cry of Fear)

	ptrdiff_t offm_rgAmmoLast; // m_rgAmmoLast (class: CBasePlayer, type: int[MAX_AMMO_SLOTS])
	int maxAmmoSlots = MAX_AMMO_SLOTS;
	ptrdiff_t offm_pClientActiveItem; // m_pClientActiveItem (class: CBasePlayer, type: CBasePlayerItem*)
	//ptrdiff_t offm_iPrimaryAmmoType; // m_iPrimaryAmmoType (class: CBasePlayerWeapon, type: int)

private:
	ServerDLL() : IHookableDirFilter({ L"dlls", L"cl_dlls"}) {};
	ServerDLL(const ServerDLL&);
	void operator=(const ServerDLL&);

protected:
	// Engine calls server-side functions from gEntityInterface (global variable)
	typedef int(__cdecl *_GetEntityAPI)(DLL_FUNCTIONS* pFunctionTable, int interfaceVersion); // GetEntityAPI (exported)
	_GetEntityAPI ORIG_GetEntityAPI;

	typedef void(__fastcall *_CBasePlayer__ForceClientDllUpdate)(void *thisptr); // ?ForceClientDllUpdate@CBasePlayer@@QAEXXZ (non-exported)
	_CBasePlayer__ForceClientDllUpdate ORIG_CBasePlayer__ForceClientDllUpdate;
	typedef void(__cdecl *_CBasePlayer__ForceClientDllUpdate_Linux)(void *thisptr); // _ZN11CBasePlayer20ForceClientDllUpdateEv
	_CBasePlayer__ForceClientDllUpdate_Linux ORIG_CBasePlayer__ForceClientDllUpdate_Linux;
	typedef int(__cdecl* _PM_CheckStuck)(); // PM_CheckStuck (non-exported)
	_PM_CheckStuck ORIG_PM_CheckStuck;
	typedef void*(__cdecl *_PM_Ladder)(); // PM_Ladder (non-exported)
	_PM_Ladder ORIG_PM_Ladder;
	typedef int(__cdecl *_CChangeLevel__InTransitionVolume)(void *pEntity, char *pVolumeName); // ?InTransitionVolume@CChangeLevel@@SAHPAVCBaseEntity@@PAD@Z (non-exported)
	_CChangeLevel__InTransitionVolume ORIG_CChangeLevel__InTransitionVolume;
	typedef void(__fastcall *_CBasePlayer__GiveNamedItem)(void *thisptr, int edx, const char *pszName); // ?GiveNamedItem@CBasePlayer@@QAEXPBD@Z (non-exported)
	_CBasePlayer__GiveNamedItem ORIG_CBasePlayer__GiveNamedItem;
	typedef void(__cdecl *_CBasePlayer__GiveNamedItem_Linux)(void *thisptr, const char *pszName); // _ZN11CBasePlayer13GiveNamedItemEPKc
	_CBasePlayer__GiveNamedItem_Linux ORIG_CBasePlayer__GiveNamedItem_Linux;
	typedef void(__fastcall *_CoF_CBasePlayer__GiveNamedItem)(void *thisptr, int edx, const char *pszName, bool deletewhendropped); // Game: Cry of Fear
	_CoF_CBasePlayer__GiveNamedItem ORIG_CoF_CBasePlayer__GiveNamedItem;

	typedef bool (__fastcall *_IsPlayer)(void *thisptr);
	typedef void (__fastcall *_Center)(void *thisptr, int edx, Vector *center);

#ifdef _WIN32
	typedef int (__fastcall *_ObjectCaps)(void *thisptr);
#else
	typedef int (__cdecl *_ObjectCaps)(void *thisptr);
#endif

	void FindStuff();
	void RegisterCVarsAndCommands();
	void LogPlayerMove(bool pre, uintptr_t pmove) const;
	bool IsPlayerMovingPushable(const entvars_t *pevPushable, const entvars_t *pevToucher, int push) const;

	void DoWouldCrashMessage();
	void CoFChanges();

	void **ppmove; // pmove (type: playermove_t*, global variable)

	ptrdiff_t offPlayerIndex; // player_index (struct: playermove_t, type: int)
	ptrdiff_t offOrigin; // origin (struct: playermove_t, type: vec3_t)
	ptrdiff_t offAngles; // angles (struct: playermove_t, type: vec3_t)
	ptrdiff_t offVelocity; // velocity (struct: playermove_t, type: vec3_t)
	ptrdiff_t offBasevelocity; // basevelocity (struct: playermove_t, type: vec3_t)
	ptrdiff_t offInDuck; // bInDuck (struct: playermove_t, type: qboolean)
	ptrdiff_t offPunchangles; // punchangle (struct: playermove_t, type: vec3_t)
	ptrdiff_t offFlags; // flags (struct: playermove_t, type: int)
	ptrdiff_t offEntGravity; // gravity (struct: playermove_t, type: float)
	ptrdiff_t offEntFriction; // friction (struct: playermove_t, type: float)
	ptrdiff_t offOldbuttons; // oldbuttons (struct: playermove_t, type: int)
	ptrdiff_t offOnground; // onground (struct: playermove_t, type: int)
	ptrdiff_t offWaterlevel; // waterlevel (struct: playermove_t, type: int)
	ptrdiff_t offCmd; // cmd (struct: playermove_t, type: usercmd_t)

	void *pGlobalState;

	ptrdiff_t offFuncIsPlayer = 0x9C; // IsPlayer
	ptrdiff_t offFuncCenter = 0xC8; // Center
	ptrdiff_t offFuncObjectCaps = 0x14; // ObjectCaps

	ptrdiff_t offNihilanthLevel;
	ptrdiff_t offNihilanthIrritation;
	ptrdiff_t offNihilanthRecharger;
	ptrdiff_t offNihilanthSpheres;

	ptrdiff_t offm_iClientFOV; // m_iClientFOV (class: CBasePlayer, type: int)

	void *WorldGraph = nullptr;
	size_t size_CNode;
	ptrdiff_t offm_pNodes;
	ptrdiff_t offm_cNodes;
	ptrdiff_t offm_vecOrigin;

	ptrdiff_t offBhopcap;
	ptrdiff_t pCZDS_Velocity_Byte;
	ptrdiff_t pAddToFullPack_PVS_Byte;
	ptrdiff_t pBhopcapWindows;
	byte originalBhopcapInsn[6];

	ptrdiff_t pCS_Stamina_Value;
	ptrdiff_t pCS_Bhopcap;
	ptrdiff_t pCS_Bhopcap_Windows;

	ptrdiff_t pCBasePlayer__Jump_OldButtons_Check_Byte;

	ptrdiff_t offm_bInfiniteStamina; // m_bInfiniteStamina (class: CBasePlayer, type: bool, game: Cry of Fear)
	ptrdiff_t offm_old_iAmmo; // old_m_iAmmo (class: CBasePlayerItem, type: int, game: Cry of Fear)
	ptrdiff_t offm_iPlayerSaveLock; // m_iPlayerSaveLock (class: CBasePlayer, type: int, game: Cry of Fear)

	ptrdiff_t offm_CMultiManager_index; // m_index (class: CMultiManager, type: int)

	bool spirit_sdk = false;
	bool is_czeror = false;

	bool callerIsWalkMove;
	bool callerIsFlyMove;
	bool firstFlyMoveEnded;
	float firstFlyMoveEndVelocity[3];
	float firstFlyMoveEndOrigin[3];

	std::deque<TASLogger::Collision> firstFlyMoveTouchQueue;
	std::deque<TASLogger::Collision> secondFlyMoveTouchQueue;

	std::unordered_map<int, bool> cantJumpNextTime;

	unsigned long fireBulletsPlayer_count = 0;
	unsigned long fireBullets_count = 0;
	std::deque<std::array<Vector, 2>> traceLineFireBulletsPlayer;
	std::deque<bool> traceLineFireBulletsPlayerHit;
	std::deque<std::array<Vector, 2>> traceLineFireBullets;
	std::deque<bool> traceLineFireBulletsHit;

	bool insideCBasePlayerJump = false; // CBasePlayer::Jump
};
