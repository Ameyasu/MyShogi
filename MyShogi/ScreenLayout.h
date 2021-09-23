#pragma once

/*
* ウィンドウサイズ・画像のサイズなどを定義する
*/

namespace ScreenLayout
{
// masu.bmpのサイズ
constexpr int MASU_X_SIZE_PX = 50;
constexpr int MASU_Y_SIZE_PX = 52;

constexpr int BOARD_X_SIZE = 9;
constexpr int BOARD_Y_SIZE = 9;

constexpr int BOARD_X_SIZE_PX = MASU_X_SIZE_PX * BOARD_X_SIZE;
constexpr int BOARD_Y_SIZE_PX = MASU_Y_SIZE_PX * BOARD_Y_SIZE;

// ボードの左上座標
constexpr int BOARD_X = 0;
constexpr int BOARD_Y = 0;

// koma.bmpのサイズ
// 駒1つ1つのサイズはmasu.bmpと同じ
constexpr int KOMA_X_SIZE_PX = 450;
constexpr int KOMA_Y_SIZE_PX = 104;
};