#pragma once

#include "framework.h"
#include "Shogi.h"

namespace Painter
{
extern void paintFront(HDC hdc);
extern void paintMem(const Shogi& shogi);

extern void startKomaHovering(const Shogi& shogi, const KomaAbs* koma);
extern void paintKomaHovering(int x, int y);
}