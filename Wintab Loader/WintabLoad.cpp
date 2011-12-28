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