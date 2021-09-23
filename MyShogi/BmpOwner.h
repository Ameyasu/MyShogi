/*
* ‰æ–Ê‚É•`‰æ‚·‚é‰æ‘œ‚ğ¶¬E•ÛE”jŠü‚·‚é
*/

#pragma once

#include "framework.h"
#include "KomaState.h"

namespace BmpOwner
{
extern void onCreate(HINSTANCE hinst, HWND hwnd);
extern void onDestroy();

extern HDC getBoard();
extern HDC getSenteKoma();
extern HDC getGoteKoma();
extern std::tuple<HDC, int, int> getKoma(const KomaState& state);
extern HDC getMem();
extern HDC getMemTmp();
}
