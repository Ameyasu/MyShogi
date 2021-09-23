#include "Activity.h"
#include "BmpOwner.h"
#include "Shogi.h"

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
	// debug
	BitBlt(hdc, 0, 0, 450, 468, BmpOwner::getBoard(), 0, 0, SRCCOPY);
	TransparentBlt(hdc, 0, 0, 450, 104, BmpOwner::getSenteKoma(), 0, 0, 450, 104, RGB(255, 255, 255));
	TransparentBlt(hdc, 0, 104, 450, 104, BmpOwner::getGoteKoma(), 0, 0, 450, 104, RGB(255, 255, 255));
	//BitBlt(hdc, 0, 468, 450, 104, BmpOwner::getSenteKoma(), 0, 0, SRCCOPY);
	//BitBlt(hdc, 0, 572, 450, 104, BmpOwner::getGoteKoma(), 0, 0, SRCCOPY);
}
}