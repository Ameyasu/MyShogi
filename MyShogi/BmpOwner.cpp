#include "BmpOwner.h"
#include "Resource.h"
#include "ScreenLayout.h"

using namespace ScreenLayout;

namespace BmpOwner
{
//______________________________________________________________
// �ȉ��Aprivate �ϐ���`
namespace
{
// �{�[�h�摜
HDC g_hBoardDC;
HBITMAP g_hBoardBmpPrev;

// ����摜
HDC g_hSenteKomaDC;
HBITMAP g_hSenteKomaBmpPrev;

// ����摜
HDC g_hGoteKomaDC;
HBITMAP g_hGoteKomaBmpPrev;
}


//______________________________________________________________
// �ȉ��Aprivate �v���g�^�C�v�錾
namespace
{
void createBoard(HINSTANCE hinst, HDC hdc);
void createSenteKoma(HINSTANCE hinst, HDC hdc);
void createGoteKoma(HINSTANCE hinst, HDC hdc);
}



//______________________________________________________________
// �ȉ��Apublic �֐���`

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
	// �{�[�h�摜��j������
	HBITMAP hbmp = (HBITMAP)SelectObject(g_hBoardDC, g_hBoardBmpPrev);
	DeleteObject(hbmp);
	DeleteDC(g_hBoardDC);

	// ����摜��j������
	hbmp = (HBITMAP)SelectObject(g_hSenteKomaDC, g_hSenteKomaBmpPrev);
	DeleteObject(hbmp);
	DeleteDC(g_hSenteKomaDC);

	// ����摜��j������
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
// �ȉ��Aprivate �֐���`
namespace
{
void createBoard(HINSTANCE hinst, HDC hdc)
{
	// masu.bmp��ǂݍ���
	HDC hMasuDC = CreateCompatibleDC(hdc);
	HBITMAP hMasuBmp = LoadBitmap(hinst, MAKEINTRESOURCE(IDB_MASU));
	HBITMAP hbmpPrev = (HBITMAP)SelectObject(hMasuDC, hMasuBmp);

	// ��摜�𐶐�����
	g_hBoardDC = CreateCompatibleDC(hdc);
	HBITMAP hBoardBmp = CreateCompatibleBitmap(hdc, BOARD_X_SIZE_PX, BOARD_Y_SIZE_PX);
	g_hBoardBmpPrev = (HBITMAP)SelectObject(g_hBoardDC, hBoardBmp);

	// ��摜��masu.bmp��`�悵�ă{�[�h�摜������������
	for (int y = 0; y < BOARD_Y_SIZE; ++y)
	{
		int paintY = y * MASU_Y_SIZE_PX;
		for (int x = 0; x < ScreenLayout::BOARD_X_SIZE; ++x)
		{
			int paintX = x * MASU_X_SIZE_PX;
			BitBlt(g_hBoardDC, paintX, paintY, MASU_X_SIZE_PX, MASU_Y_SIZE_PX, hMasuDC, 0, 0, SRCCOPY);
		}
	}

	// masu.bmp��j������
	SelectObject(hMasuDC, hbmpPrev);
	DeleteObject(hMasuBmp);
	DeleteDC(hMasuDC);
}

void createSenteKoma(HINSTANCE hinst, HDC hdc)
{
	// koma.bmp��ǂݍ���
	g_hSenteKomaDC = CreateCompatibleDC(hdc);
	HBITMAP hbmp = LoadBitmap(hinst, MAKEINTRESOURCE(IDB_KOMA));
	g_hSenteKomaBmpPrev = (HBITMAP)SelectObject(g_hSenteKomaDC, hbmp);
}
void createGoteKoma(HINSTANCE hinst, HDC hdc)
{
	// ��摜�𐶐�����
	g_hGoteKomaDC = CreateCompatibleDC(hdc);
	HBITMAP hGoteKomaBmp = CreateCompatibleBitmap(hdc, KOMA_X_SIZE_PX, KOMA_Y_SIZE_PX);
	g_hGoteKomaBmpPrev = (HBITMAP)SelectObject(g_hGoteKomaDC, hGoteKomaBmp);

	// ��摜��koma.bmp�̊e���180�x��]�����ē����ʒu�ɕ`�悷��
	for (int y = 0; y < 2; ++y)
	{
		for (int x = 0; x < 9; ++x)
		{
			// ��]��̍��W�̐ݒ�
			POINT p[3];
			p[0] = {(x + 1) * MASU_X_SIZE_PX, (y + 1) * MASU_Y_SIZE_PX}; // ������E����
			p[1] = {x * MASU_X_SIZE_PX - 1, (y + 1) * MASU_Y_SIZE_PX}; // �E���������
			p[2] = {(x + 1) * MASU_X_SIZE_PX, y * MASU_Y_SIZE_PX - 1}; // �������E���

			PlgBlt(g_hGoteKomaDC, p, g_hSenteKomaDC, x * MASU_X_SIZE_PX, y * MASU_Y_SIZE_PX, MASU_X_SIZE_PX, MASU_Y_SIZE_PX, nullptr, 0, 0);
		}
	}
}
}
}

