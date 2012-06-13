//	Copyright (C) 2011-2012 Vaptistis Anogeianakis <el05208@mail.ntua.gr>
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
#include "WintabLoad.h"

// function pointers
WTInfoW_Type WTInfoW;
WTOpenW_Type WTOpenW;
WTClose_Type WTClose;
WTPacketsGet_Type WTPacketsGet;
WTGetW_Type WTGetW;
WTEnable_Type WTEnable;
WTOverlap_Type WTOverlap;
WTQueueSizeGet_Type WTQueueSizeGet;
WTQueueSizeSet_Type WTQueueSizeSet;

// ordinal values for loading the functions
static const int WTInfoW_Ordinal = 1020;
static const int WTOpenW_Ordinal = 1021;
static const int WTClose_Ordinal = 22;
static const int WTPacketsGet_Ordinal = 23;
static const int WTGetW_Ordinal = 1061;
static const int WTEnable_Ordinal = 40;
static const int WTOverlap_Ordinal = 41;
static const int WTQueueSizeGet_Ordinal = 84;
static const int WTQueueSizeSet_Ordinal = 85;

static HMODULE wintabModuleHandle;

void wtLoad(void)
{
	wintabModuleHandle = LoadLibraryW(L"Wintab32.dll");

#define LoadFunction(A) A = (A##_Type)GetProcAddress(wintabModuleHandle,(LPCSTR)A##_Ordinal)
	LoadFunction(WTInfoW);
	LoadFunction(WTOpenW);
	LoadFunction(WTClose);
	LoadFunction(WTPacketsGet);
	LoadFunction(WTGetW);
	LoadFunction(WTEnable);
	LoadFunction(WTOverlap);
	LoadFunction(WTQueueSizeGet);
	LoadFunction(WTQueueSizeSet);
#undef LoadFunction
} // end function wtLoad

void wtUnLoad(void)
{
	FreeLibrary(wintabModuleHandle);
} // end function wtUnLoad