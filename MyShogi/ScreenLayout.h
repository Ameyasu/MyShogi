#pragma once

/*
* �E�B���h�E�T�C�Y�E�摜�̃T�C�Y�Ȃǂ��`����
*/

namespace ScreenLayout
{
// masu.bmp�̃T�C�Y
constexpr int MASU_X_SIZE_PX = 50;
constexpr int MASU_Y_SIZE_PX = 52;

constexpr int BOARD_X_SIZE = 9;
constexpr int BOARD_Y_SIZE = 9;

constexpr int BOARD_X_SIZE_PX = MASU_X_SIZE_PX * BOARD_X_SIZE;
constexpr int BOARD_Y_SIZE_PX = MASU_Y_SIZE_PX * BOARD_Y_SIZE;

// �{�[�h�̍�����W
constexpr int BOARD_X = 0;
constexpr int BOARD_Y = 0;

// koma.bmp�̃T�C�Y
// ��1��1�̃T�C�Y��masu.bmp�Ɠ���
constexpr int KOMA_X_SIZE_PX = 450;
constexpr int KOMA_Y_SIZE_PX = 104;
};