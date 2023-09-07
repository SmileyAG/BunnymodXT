//========= Copyright © 1996-2002, Valve LLC, All rights reserved. ============
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================

#if !defined EDICT_H
#define EDICT_H
#ifdef _WIN32
#pragma once
#endif

#ifdef SDK10_BUILD
#define	MAX_ENT_LEAFS	24
#elif NIGHTFIRE_BUILD
#define	MAX_ENT_LEAFS	64
#else
#define	MAX_ENT_LEAFS	48
#endif

#include "progdefs.h"
#include "../common/entity_state.h"

/*
	Size of 'edict_t' in HLSDK 1.0 builds is 0x2C8 (712)
	Size of 'edict_t' in HLSDK 2.0+ builds is 0x324 (804)
	Size of 'edict_t' in Cry of Fear [Steam] is 0x32C (812)
	Size of 'edict_t' in James Bond 007: Nightfire [PC] is 0x3E0 (992)
*/

struct edict_s
{
	qboolean	free;
	int			serialnumber;
	link_t		area;				// linked to a division node or leaf

	#ifndef SDK10_BUILD
	int			headnode;			// -1 to use normal leaf check
	#endif

	int			num_leafs;

	#ifdef NIGHTFIRE_BUILD
	int		leafnums[MAX_ENT_LEAFS];
	#else
	short		leafnums[MAX_ENT_LEAFS];
	#endif

	#ifdef SDK10_BUILD
	entity_state_t	baseline;
	#endif

	float		freetime;			// sv.time when the object was freed

	void*		pvPrivateData;		// Alloced and freed by engine, used by DLLs

	entvars_t	v;					// C exported fields from progs

	// other fields from progs come immediately after
};

#endif
