/*
* ��ʂɕ`�悷��摜�𐶐��E�ێ��E�j������
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
