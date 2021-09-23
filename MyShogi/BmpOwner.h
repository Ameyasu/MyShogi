/*
* ‰æ–Ê‚É•`‰æ‚·‚é‰æ‘œ‚ğ¶¬E•ÛE”jŠü‚·‚é
*/

#pragma once

#include "framework.h"

namespace BmpOwner
{
extern void onCreate(HINSTANCE hinst, HWND hwnd);
extern void onDestroy();

extern HDC getBoard();
extern HDC getSenteKoma();
extern HDC getGoteKoma();
}
