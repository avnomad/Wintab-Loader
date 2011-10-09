/* Created by Anogeianakis Vaptistis on 10/10/2011 */
#ifndef WINTAB_LOAD_H
#define WINTAB_LOAD_H

/* eventually I should remove inclusions of windows.h and replace
   its functions with others throwing exceptions and using namespaces ect. */

#include <windows.h>
#define NOWTFUNCTIONS
#include <Wintab.h>

// function pointer types
typedef UINT (WINAPI*WTInfoW_Type)(UINT,UINT,LPVOID);
typedef HCTX (WINAPI*WTOpenW_Type)(HWND,LPLOGCONTEXTW,BOOL);
typedef BOOL (WINAPI*WTClose_Type)(HCTX);
typedef int (WINAPI*WTPacketsGet_Type)(HCTX,int,LPVOID);
typedef BOOL (WINAPI*WTEnable_Type)(HCTX,BOOL);
typedef int (WINAPI*WTQueueSizeGet_Type)(HCTX);
typedef BOOL (WINAPI*WTQueueSizeSet_Type)(HCTX,int);

// function pointers
extern WTInfoW_Type WTInfoW;
extern WTOpenW_Type WTOpenW;
extern WTClose_Type WTClose;
extern WTPacketsGet_Type WTPacketsGet;
extern WTEnable_Type WTEnable;
extern WTQueueSizeGet_Type WTQueueSizeGet;
extern WTQueueSizeSet_Type WTQueueSizeSet;

// additional functions
void wtLoad(void);
void wtUnLoad(void);

#endif