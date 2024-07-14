#pragma once

#define RET_CASE_STR(c) case c: return "" #c "";
#define PRINT_FLAG(fl) \
	if (flags & fl) \
		out << "" #fl "; ";

namespace databank
{
	std::string get_difficulty(const int skill);
	std::string get_hitgroup(const int iHitgroup);
	std::string get_typedescription_fieldtype(const int fieldType);
	std::string get_renderfx(const int renderfx);
	std::string get_rendermode(const int rendermode);
	std::string get_effects(const int flags);
	std::string get_solid(const int solid);
	std::string get_movetype(const int movetype);
	std::string get_flags(const int flags);
	std::string get_spawnflags(const int spawnflags, const char *classname);
	std::string get_monster_triggercondition(const int m_iTriggerCondition);
}