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
}