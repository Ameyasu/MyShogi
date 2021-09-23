#include "Activity.h"
#include "BmpOwner.h"
#include "Shogi.h"
#include "Painter.h"

namespace Activity
{
namespace
{
Shogi g_shogi;
}


void onCreate(HINSTANCE hinst, HWND hwnd)
{
	BmpOwner::onCreate(hinst, hwnd);
}
void onDestroy()
{
	BmpOwner::onDestroy();
}
void onPaint(HDC hdc)
{
	Painter::paintMem(g_shogi);
	Painter::paintFront(hdc);
}
}