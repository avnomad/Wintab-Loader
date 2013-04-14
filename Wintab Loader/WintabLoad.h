//	Copyright (C) 2011-2012 Vaptistis Anogeianakis <nomad@cornercase.gr>
/*
 *	This file is part of Wintab Loader.
 *
 *	Wintab Loader is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	Wintab Loader is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with Wintab Loader.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Created by Anogeianakis Vaptistis on 10/10/2011 */
#ifndef WINTAB_LOAD_H
#define WINTAB_LOAD_H

/* eventually I should remove inclusions of windows.h and replace
   its functions with others throwing exceptions and using namespaces etc. */

#include <windows.h>
#define NOWTFUNCTIONS
#include <Wintab.h>

// function pointer types
typedef UINT (WINAPI*WTInfoW_Type)(UINT,UINT,LPVOID);
typedef HCTX (WINAPI*WTOpenW_Type)(HWND,LPLOGCONTEXTW,BOOL);
typedef BOOL (WINAPI*WTClose_Type)(HCTX);
typedef int (WINAPI*WTPacketsGet_Type)(HCTX,int,LPVOID);
typedef BOOL (WINAPI*WTGetW_Type)(HCTX,LPLOGCONTEXTW);
typedef BOOL (WINAPI*WTEnable_Type)(HCTX,BOOL);
typedef BOOL (WINAPI*WTOverlap_Type)(HCTX,BOOL);
typedef int (WINAPI*WTQueueSizeGet_Type)(HCTX);
typedef BOOL (WINAPI*WTQueueSizeSet_Type)(HCTX,int);

// function pointers
extern WTInfoW_Type WTInfoW;
extern WTOpenW_Type WTOpenW;
extern WTClose_Type WTClose;
extern WTPacketsGet_Type WTPacketsGet;
extern WTGetW_Type WTGetW;
extern WTEnable_Type WTEnable;
extern WTOverlap_Type WTOverlap;
extern WTQueueSizeGet_Type WTQueueSizeGet;
extern WTQueueSizeSet_Type WTQueueSizeSet;

// additional functions
void wtLoad(void);
void wtUnLoad(void);

#endif
