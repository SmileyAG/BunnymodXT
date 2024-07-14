#include "stdafx.hpp"
#include "databank.hpp"

namespace databank
{
	std::string get_difficulty(const int skill)
	{
		switch (skill)
		{
			case 1: return "Easy";
			case 2: return "Normal";
			case 3: return "Hard";
			default: return "Unknown";
		}
	}

	std::string get_hitgroup(const int iHitgroup)
	{
		switch (iHitgroup)
		{
			case HITGROUP_GENERIC: return "Generic";
			case HITGROUP_HEAD: return "Head";
			case HITGROUP_CHEST: return "Chest";
			case HITGROUP_STOMACH: return "Stomach";
			case HITGROUP_LEFTARM: return "Left Arm";
			case HITGROUP_RIGHTARM: return "Right Arm";
			case HITGROUP_LEFTLEG: return "Left Leg";
			case HITGROUP_RIGHTLEG: return "Right Leg";
			default: return "Unknown";
		}
	}

	std::string get_typedescription_fieldtype(const int fieldType)
	{
		switch (fieldType)
		{
			RET_CASE_STR(FIELD_FLOAT)
			RET_CASE_STR(FIELD_STRING)
			RET_CASE_STR(FIELD_ENTITY)
			RET_CASE_STR(FIELD_CLASSPTR)
			RET_CASE_STR(FIELD_EHANDLE)
			RET_CASE_STR(FIELD_EVARS)
			RET_CASE_STR(FIELD_EDICT)
			RET_CASE_STR(FIELD_VECTOR)
			RET_CASE_STR(FIELD_POSITION_VECTOR)
			RET_CASE_STR(FIELD_POINTER)
			RET_CASE_STR(FIELD_INTEGER)
			RET_CASE_STR(FIELD_FUNCTION)
			RET_CASE_STR(FIELD_BOOLEAN)
			RET_CASE_STR(FIELD_SHORT)
			RET_CASE_STR(FIELD_CHARACTER)
			RET_CASE_STR(FIELD_TIME)
			RET_CASE_STR(FIELD_MODELNAME)
			RET_CASE_STR(FIELD_SOUNDNAME)
			RET_CASE_STR(FIELD_TYPECOUNT)
			default: return "Unknown";
		}
	}

	std::string get_renderfx(const int renderfx)
	{
		switch (renderfx)
		{
			RET_CASE_STR(kRenderFxNone)
			RET_CASE_STR(kRenderFxPulseSlow)
			RET_CASE_STR(kRenderFxPulseFast)
			RET_CASE_STR(kRenderFxPulseSlowWide)
			RET_CASE_STR(kRenderFxPulseFastWide)
			RET_CASE_STR(kRenderFxFadeSlow)
			RET_CASE_STR(kRenderFxFadeFast)
			RET_CASE_STR(kRenderFxSolidSlow)
			RET_CASE_STR(kRenderFxSolidFast)
			RET_CASE_STR(kRenderFxStrobeSlow)
			RET_CASE_STR(kRenderFxStrobeFast)
			RET_CASE_STR(kRenderFxStrobeFaster)
			RET_CASE_STR(kRenderFxFlickerSlow)
			RET_CASE_STR(kRenderFxFlickerFast)
			RET_CASE_STR(kRenderFxNoDissipation)
			RET_CASE_STR(kRenderFxDistort)
			RET_CASE_STR(kRenderFxHologram)
			RET_CASE_STR(kRenderFxDeadPlayer)
			RET_CASE_STR(kRenderFxExplode)
			RET_CASE_STR(kRenderFxGlowShell)
			RET_CASE_STR(kRenderFxClampMinScale)
			default: return "Unknown";
		}
	}

	std::string get_rendermode(const int rendermode)
	{
		switch (rendermode)
		{
			RET_CASE_STR(kRenderNormal)
			RET_CASE_STR(kRenderTransColor)
			RET_CASE_STR(kRenderTransTexture)
			RET_CASE_STR(kRenderGlow)
			RET_CASE_STR(kRenderTransAlpha)
			RET_CASE_STR(kRenderTransAdd)
			default: return "Unknown";
		}
	}

	std::string get_effects(const int flags)
	{
		std::ostringstream out;

		// The flags here were arranged in order from smallest to highest bits.
		PRINT_FLAG(EF_BRIGHTFIELD);
		PRINT_FLAG(EF_MUZZLEFLASH);
		PRINT_FLAG(EF_BRIGHTLIGHT);
		PRINT_FLAG(EF_DIMLIGHT);
		PRINT_FLAG(EF_INVLIGHT);
		PRINT_FLAG(EF_NOINTERP);
		PRINT_FLAG(EF_LIGHT);
		PRINT_FLAG(EF_NODRAW);

		out << '\n';

		return out.str();
	}

	std::string get_solid(const int solid)
	{
		switch (solid)
		{
			RET_CASE_STR(SOLID_NOT)
			RET_CASE_STR(SOLID_TRIGGER)
			RET_CASE_STR(SOLID_BBOX)
			RET_CASE_STR(SOLID_SLIDEBOX)
			RET_CASE_STR(SOLID_BSP)
			default: return "Unknown";
		}
	}

	std::string get_movetype(const int movetype)
	{
		switch (movetype)
		{
			RET_CASE_STR(MOVETYPE_NONE)
			RET_CASE_STR(MOVETYPE_WALK)
			RET_CASE_STR(MOVETYPE_STEP)
			RET_CASE_STR(MOVETYPE_FLY)
			RET_CASE_STR(MOVETYPE_TOSS)
			RET_CASE_STR(MOVETYPE_PUSH)
			RET_CASE_STR(MOVETYPE_NOCLIP)
			RET_CASE_STR(MOVETYPE_FLYMISSILE)
			RET_CASE_STR(MOVETYPE_BOUNCE)
			RET_CASE_STR(MOVETYPE_BOUNCEMISSILE)
			RET_CASE_STR(MOVETYPE_FOLLOW)
			RET_CASE_STR(MOVETYPE_PUSHSTEP)
			default: return "Unknown";
		}
	}

	std::string get_flags(const int flags)
	{
		std::ostringstream out;

		// The flags here were arranged in order from smallest to highest bits.
		PRINT_FLAG(FL_FLY);
		PRINT_FLAG(FL_SWIM);
		PRINT_FLAG(FL_CONVEYOR);
		PRINT_FLAG(FL_CLIENT);
		PRINT_FLAG(FL_INWATER);
		PRINT_FLAG(FL_MONSTER);
		PRINT_FLAG(FL_GODMODE);
		PRINT_FLAG(FL_NOTARGET);
		PRINT_FLAG(FL_SKIPLOCALHOST);
		PRINT_FLAG(FL_ONGROUND);
		PRINT_FLAG(FL_PARTIALGROUND);
		PRINT_FLAG(FL_WATERJUMP);
		PRINT_FLAG(FL_FROZEN);
		PRINT_FLAG(FL_FAKECLIENT);
		PRINT_FLAG(FL_DUCKING);
		PRINT_FLAG(FL_FLOAT);
		PRINT_FLAG(FL_GRAPHED);
		PRINT_FLAG(FL_IMMUNE_WATER);
		PRINT_FLAG(FL_IMMUNE_SLIME);
		PRINT_FLAG(FL_IMMUNE_LAVA);
		PRINT_FLAG(FL_PROXY);
		PRINT_FLAG(FL_ALWAYSTHINK);
		PRINT_FLAG(FL_BASEVELOCITY);
		PRINT_FLAG(FL_MONSTERCLIP);
		PRINT_FLAG(FL_ONTRAIN);
		PRINT_FLAG(FL_WORLDBRUSH);
		PRINT_FLAG(FL_SPECTATOR);
		// unknown
		// unknown
		PRINT_FLAG(FL_CUSTOMENTITY);
		PRINT_FLAG(FL_KILLME);
		PRINT_FLAG(FL_DORMANT);

		out << '\n';

		return out.str();
	}

	std::string get_spawnflags_breakable(const int flags, const bool pushable)
	{
		std::ostringstream out;

		// The flags here were arranged in order from smallest to highest bits.
		if (flags & SF_BREAK_TRIGGER_ONLY)
			out << "Only trigger; ";
		if (flags & SF_BREAK_TOUCH)
			out << "Touch; ";
		if (flags & SF_BREAK_PRESSURE)
			out << "Pressure; ";
		// unknown
		// unknown
		// unknown
		// unknown
		if (pushable && (flags & SF_PUSH_BREAKABLE))
			out << "Breakable; ";
		if (flags & SF_BREAK_CROWBAR)
			out << "Instant crowbar; ";

		out << '\n';

		return out.str();
	}

	std::string get_spawnflags_door(const int flags, const bool rotating)
	{
		std::ostringstream out;

		// The flags here were arranged in order from smallest to highest bits.
		if (flags & SF_DOOR_START_OPEN)
			out << "Starts Open; ";
		if (rotating && (flags & SF_DOOR_ROTATE_BACKWARDS))
			out << "Reverse Dir; ";
		// unknown
		if (flags & SF_DOOR_PASSABLE)
			out << "Passable; ";
		if (rotating && (flags & SF_DOOR_ONEWAY))
			out << "One-way; ";
		if (flags & SF_DOOR_NO_AUTO_RETURN)
			out << "Toggle; ";
		if (rotating && (flags & SF_DOOR_ROTATE_Z))
			out << "X Axis; ";
		if (rotating && (flags & SF_DOOR_ROTATE_X))
			out << "Y Axis; ";
		if (flags & SF_DOOR_USE_ONLY)
			out << "Use Only; ";
		if (flags & SF_DOOR_NOMONSTERS)
			out << "Monsters Can't; ";

		out << '\n';

		return out.str();
	}

	std::string get_spawnflags_trigger(const int flags)
	{
		std::ostringstream out;

		// The flags here were arranged in order from smallest to highest bits.
		if (flags & SF_TRIGGER_ALLOWMONSTERS)
			out << "Monsters; ";
		if (flags & SF_TRIGGER_NOCLIENTS)
			out << "No clients; ";
		if (flags & SF_TRIGGER_PUSHABLES)
			out << "Pushables; ";

		out << '\n';

		return out.str();
	}

	std::string get_spawnflags_monster(const int flags)
	{
		std::ostringstream out;

		// The flags here were arranged in order from smallest to highest bits.
		if (flags & SF_MONSTER_WAIT_TILL_SEEN)
			out << "WaitTillSeen; ";
		if (flags & SF_MONSTER_GAG)
			out << "Gag; ";
		if (flags & SF_MONSTER_HITMONSTERCLIP)
			out << "MonsterClip; ";
		// unknown
		if (flags & SF_MONSTER_PRISONER)
			out << "Prisoner; ";
		// unknown
		// unknown
		if (flags & SF_MONSTER_WAIT_FOR_SCRIPT)
			out << "WaitForScript; ";
		if (flags & SF_MONSTER_PREDISASTER)
			out << "Pre-Disaster; ";
		if (flags & SF_MONSTER_FADECORPSE)
			out << "Fade Corpse; ";

		out << '\n';

		return out.str();
	}

	std::string get_spawnflags(const int spawnflags, const char *classname)
	{
		if (!strcmp(classname, "func_breakable"))
			return get_spawnflags_breakable(spawnflags, false);
		else if (!strcmp(classname, "func_pushable"))
			return get_spawnflags_breakable(spawnflags, true);
		else if (!strcmp(classname, "func_door") || !strcmp(classname, "momentary_door"))
			return get_spawnflags_door(spawnflags, false);
		else if (!strcmp(classname, "func_door_rotating"))
			return get_spawnflags_door(spawnflags, true);

		return "\n";
	}
};