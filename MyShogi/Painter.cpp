#include "Painter.h"
#include "BmpOwner.h"
#include "ScreenLayout.h"

using namespace ScreenLayout;
using namespace BmpOwner;

namespace Painter
{
void paintFront(HDC hdc)
{
	BitBlt(hdc, 0, 0, CLIENT_X_SIZE, CLIENT_Y_SIZE, getMem(), 0, 0, SRCCOPY);
}
void paintMem(const Shogi& shogi)
{
	// 取りあえず全部真っ白にリセット
	PatBlt(getMem(), 0, 0, CLIENT_X_SIZE, CLIENT_Y_SIZE, WHITENESS);

	// ボード
	BitBlt(getMem(), BOARD_X, BOARD_Y, BOARD_X_SIZE_PX, BOARD_Y_SIZE_PX, getBoard(), 0, 0, SRCCOPY);

	// ボード上の駒
	const Board& board = shogi.getBoard();
	for (int y = 0; y < BOARD_Y_SIZE; ++y)
	{
		int paintY = (y * BOARD_Y_SIZE_PX) + BOARD_Y;
		for (int x = 0; x < BOARD_X_SIZE; ++x)
		{
			int paintX = (x * BOARD_X_SIZE_PX) + BOARD_X;
			auto& koma = board.get(x, y);
			if (!koma)
			{
				continue;
			}
			auto& state = koma->getKomaState();
			auto img = getKoma(state);
			TransparentBlt(getMem(), paintX, paintY, KOMA_X_SIZE_PX, KOMA_Y_SIZE_PX, std::get<0>(img), std::get<1>(img), std::get<2>(img), KOMA_X_SIZE_PX, KOMA_Y_SIZE_PX, RGB(255, 255, 255));
		}
	}
}

}

