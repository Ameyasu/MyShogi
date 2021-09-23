/*
* ‰æ–Ê‚É•`‰æ‚·‚é‰æ‘œ‚ğ¶¬E•ÛE”jŠü‚·‚é
*/

#pragma once

#include "framework.h"
#include "Shogi.h"

namespace BmpOwner
{
extern void onCreate(HINSTANCE hinst, HWND hwnd);
extern void onDestroy();

extern HDC getBoard();
extern std::tuple<HDC, int, int> getKoma(const KomaState& state);
extern std::tuple<HDC, int, int> getTurn(KomaState::SenteGote senteGote, Shogi::Turn turn);
extern HDC getMem();
extern HDC getMemTmp();
}
