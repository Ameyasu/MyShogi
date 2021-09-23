#pragma once

#include "framework.h"
#include "Shogi.h"

namespace Painter
{
extern void paintFront(HDC hdc);
extern void paintMem(const Shogi& shogi);
}