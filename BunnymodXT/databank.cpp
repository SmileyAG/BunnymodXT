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
};