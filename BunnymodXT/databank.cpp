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
};