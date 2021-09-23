/*
* ウィンドウメッセージとそれに対応する機能の仲介者
*/

#pragma once

#include "framework.h"

namespace Activity
{
extern void onCreate(HINSTANCE hinst, HWND hwnd);
extern void onDestroy();

extern void onPaint(HDC hdc);
}