/*
Copyright (C) 2011 Jay Satiro <raysatiro@yahoo.com>
All rights reserved.

This file is part of GetHooks.

GetHooks is free software: you can redistribute it and/or modify 
it under the terms of the GNU General Public License as published by 
the Free Software Foundation, either version 3 of the License, or 
(at your option) any later version.

GetHooks is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
GNU General Public License for more details.

You should have received a copy of the GNU General Public License 
along with GetHooks.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _GLOBAL_H
#define _GLOBAL_H

#include <windows.h>


/* ReactOS structures for hooks and handles */
#include "reactos_structs.h"

/* SYSTEM_THREAD_INFORMATION,
SYSTEM_EXTENDED_THREAD_INFORMATION,
SYSTEM_PROCESS_INFORMATION
*/
#include "nt_independent_sysprocinfo_structs.h"

/* program store (command line arguments, OS version, etc) */
#include "prog.h"

/* configuration store (user-specified command line configuration) */
#include "config.h"

/* desktop store (linked list of desktops' heap and thread info) */
#include "desktop.h"

/* snapshot store (system process info, gui threads and hooks) */
#include "snapshot.h"



#ifdef __cplusplus
extern "C" {
#endif


/** The global store. 
This store holds all the stores that must be available globally.
*/
struct global
{
	/* basic program and system info */
	struct prog *prog;   // create_prog_store(), free_prog_store()
	
	/* user-specified configuration. requires prog init. */
	struct config *config;   // create_config_store(), free_config_store()
	
	/* linked list of attached to desktops and their heap info. requires config init. */
	struct desktop *desktops;   // create_desktop_store(), free_desktop_store()
	
	/* previous snapshot of hooks and threads. requires desktops init. */
	struct snapshot *previous;   // create_snapshot_store(), free_snapshot_store()
	
	/* current snapshot of hooks and threads. requires desktops init. */
	struct snapshot *current;   // create_snapshot_store(), free_snapshot_store()
};


/* a global pointer to this process' global store */
extern struct global *G;   // create_global_store(), free_global_store()



/** 
these functions are documented in the comment block above their definitions in global.c
*/
static void create_global_store( void );

static void free_global_store( void );


#ifdef __cplusplus
}
#endif

#endif // _GLOBAL_H
