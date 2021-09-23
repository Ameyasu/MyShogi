#include "BmpOwner.h"
#include "Resource.h"
#include "ScreenLayout.h"

using namespace ScreenLayout;

namespace BmpOwner
{
//______________________________________________________________
// 以下、private 変数定義
namespace
{
// ボード画像
HDC g_hBoardDC;
HBITMAP g_hBoardBmpPrev;

// 先手駒画像
HDC g_hSenteKomaDC;
HBITMAP g_hSenteKomaBmpPrev;

// 後手駒画像
HDC g_hGoteKomaDC;
HBITMAP g_hGoteKomaBmpPrev;
}


//______________________________________________________________
// 以下、private プロトタイプ宣言
namespace
{
void createBoard(HINSTANCE hinst, HDC hdc);
void createSenteKoma(HINSTANCE hinst, HDC hdc);
void createGoteKoma(HINSTANCE hinst, HDC hdc);
}



//______________________________________________________________
// 以下、public 関数定義

void onCreate(HINSTANCE hinst, HWND hwnd)
{
	HDC hdc = GetDC(hwnd);

	createBoard(hinst, hdc);
	createSenteKoma(hinst, hdc);
	createGoteKoma(hinst, hdc);

	ReleaseDC(hwnd, hdc);
}

void onDestroy()
{
	// ボード画像を破棄する
	HBITMAP hbmp = (HBITMAP)SelectObject(g_hBoardDC, g_hBoardBmpPrev);
	DeleteObject(hbmp);
	DeleteDC(g_hBoardDC);

	// 先手駒画像を破棄する
	hbmp = (HBITMAP)SelectObject(g_hSenteKomaDC, g_hSenteKomaBmpPrev);
	DeleteObject(hbmp);
	DeleteDC(g_hSenteKomaDC);

	// 後手駒画像を破棄する
	hbmp = (HBITMAP)SelectObject(g_hGoteKomaDC, g_hGoteKomaBmpPrev);
	DeleteObject(hbmp);
	DeleteDC(g_hGoteKomaDC);
}

HDC getBoard()
{
	return g_hBoardDC;
}

HDC getSenteKoma()
{
	return g_hSenteKomaDC;
}

HDC getGoteKoma()
{
	return g_hGoteKomaDC;
}



//______________________________________________________________
// 以下、private 関数定義
namespace
{
void createBoard(HINSTANCE hinst, HDC hdc)
{
	// masu.bmpを読み込む
	HDC hMasuDC = CreateCompatibleDC(hdc);
	HBITMAP hMasuBmp = LoadBitmap(hinst, MAKEINTRESOURCE(IDB_MASU));
	HBITMAP hbmpPrev = (HBITMAP)SelectObject(hMasuDC, hMasuBmp);

	// 空画像を生成する
	g_hBoardDC = CreateCompatibleDC(hdc);
	HBITMAP hBoardBmp = CreateCompatibleBitmap(hdc, BOARD_X_SIZE_PX, BOARD_Y_SIZE_PX);
	g_hBoardBmpPrev = (HBITMAP)SelectObject(g_hBoardDC, hBoardBmp);

	// 空画像にmasu.bmpを描画してボード画像を完成させる
	for (int y = 0; y < BOARD_Y_SIZE; ++y)
	{
		int paintY = y * MASU_Y_SIZE_PX;
		for (int x = 0; x < ScreenLayout::BOARD_X_SIZE; ++x)
		{
			int paintX = x * MASU_X_SIZE_PX;
			BitBlt(g_hBoardDC, paintX, paintY, MASU_X_SIZE_PX, MASU_Y_SIZE_PX, hMasuDC, 0, 0, SRCCOPY);
		}
	}

	// masu.bmpを破棄する
	SelectObject(hMasuDC, hbmpPrev);
	DeleteObject(hMasuBmp);
	DeleteDC(hMasuDC);
}

void createSenteKoma(HINSTANCE hinst, HDC hdc)
{
	// koma.bmpを読み込む
	g_hSenteKomaDC = CreateCompatibleDC(hdc);
	HBITMAP hbmp = LoadBitmap(hinst, MAKEINTRESOURCE(IDB_KOMA));
	g_hSenteKomaBmpPrev = (HBITMAP)SelectObject(g_hSenteKomaDC, hbmp);
}
void createGoteKoma(HINSTANCE hinst, HDC hdc)
{
	// 空画像を生成する
	g_hGoteKomaDC = CreateCompatibleDC(hdc);
	HBITMAP hGoteKomaBmp = CreateCompatibleBitmap(hdc, KOMA_X_SIZE_PX, KOMA_Y_SIZE_PX);
	g_hGoteKomaBmpPrev = (HBITMAP)SelectObject(g_hGoteKomaDC, hGoteKomaBmp);

	// 空画像にkoma.bmpの各駒を180度回転させて同じ位置に描画する
	for (int y = 0; y < 2; ++y)
	{
		for (int x = 0; x < 9; ++x)
		{
			// 回転後の座標の設定
			POINT p[3];
			p[0] = {(x + 1) * MASU_X_SIZE_PX, (y + 1) * MASU_Y_SIZE_PX}; // 左上を右下に
			p[1] = {x * MASU_X_SIZE_PX - 1, (y + 1) * MASU_Y_SIZE_PX}; // 右上を左下に
			p[2] = {(x + 1) * MASU_X_SIZE_PX, y * MASU_Y_SIZE_PX - 1}; // 左下を右上に

			PlgBlt(g_hGoteKomaDC, p, g_hSenteKomaDC, x * MASU_X_SIZE_PX, y * MASU_Y_SIZE_PX, MASU_X_SIZE_PX, MASU_Y_SIZE_PX, nullptr, 0, 0);
		}
	}
}
}
}

