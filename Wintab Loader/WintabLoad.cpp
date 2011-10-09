#include "WintabLoad.h"


static const int WTInfoW_Ordinal = 1020;
static const int WTOpenW_Ordinal = 1021;
static const int WTClose_Ordinal = 22;
static const int WTPacketsGet_Ordinal = 23;
static const int WTEnable_Ordinal = 40;
static const int WTQueueSizeGet_Ordinal = 84;
static const int WTQueueSizeSet_Ordinal = 85;

typedef UINT (WINAPI*WTInfoW_Type)(UINT,UINT,LPVOID);
typedef HCTX (WINAPI*WTOpenW_Type)(HWND,LPLOGCONTEXTW,BOOL);
typedef BOOL (WINAPI*WTClose_Type)(HCTX);
typedef int (WINAPI*WTPacketsGet_Type)(HCTX,int,LPVOID);
typedef BOOL (WINAPI*WTEnable_Type)(HCTX,BOOL);
typedef int (WINAPI*WTQueueSizeGet_Type)(HCTX);
typedef BOOL (WINAPI*WTQueueSizeSet_Type)(HCTX,int);

WTInfoW_Type WTInfoW;
WTOpenW_Type WTOpenW;
WTClose_Type WTClose;
WTPacketsGet_Type WTPacketsGet;
WTEnable_Type WTEnable;
WTQueueSizeGet_Type WTQueueSizeGet;
WTQueueSizeSet_Type WTQueueSizeSet;
