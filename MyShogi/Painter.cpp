#include "Painter.h"
#include "BmpOwner.h"
#include "ScreenLayout.h"

using namespace ScreenLayout;
using namespace BmpOwner;

namespace Painter
{
//______________________________________________________________
// 以下、private 変数定義
namespace
{
const KomaAbs* g_hoveringKoma;
}


//______________________________________________________________
// 以下、private プロトタイプ宣言
namespace
{
void paintDefault(const Shogi& shogi, const KomaAbs* hoveringKoma);
void paintBoard(const Shogi& shogi, const KomaAbs* hoveringKoma);
void paintMochiGoma(const Shogi& shogi, const KomaAbs* hoveringKoma);
void paintTurn(const Shogi& shogi);
}


//______________________________________________________________
// 以下、public 関数定義

void paintFront(HDC hdc)
{
	BitBlt(hdc, 0, 0, CLIENT_X_SIZE, CLIENT_Y_SIZE, getMem(), 0, 0, SRCCOPY);
}
void paintMem(const Shogi& shogi)
{
	paintDefault(shogi, nullptr);
}

void startKomaHovering(const Shogi& shogi, const KomaAbs* koma)
{
	g_hoveringKoma = koma;

	paintDefault(shogi, g_hoveringKoma);

	// ホバリングしている駒だけが描画されていない画像をコピー
	BitBlt(getMemTmp(), 0, 0, CLIENT_X_SIZE, CLIENT_Y_SIZE, getMem(), 0, 0, SRCCOPY);
}

void paintKomaHovering(int x, int y)
{
	// ホバリングしている駒だけが描画されていない画像を描画
	BitBlt(getMem(), 0, 0, CLIENT_X_SIZE, CLIENT_Y_SIZE, getMemTmp(), 0, 0, SRCCOPY);

	// ホバリングしている駒を描画
}


//______________________________________________________________
// 以下、private 関数定義
namespace
{
void paintDefault(const Shogi& shogi, const KomaAbs* hoveringKoma)
{
	// 取りあえず全部真っ白にリセット
	PatBlt(getMem(), 0, 0, CLIENT_X_SIZE, CLIENT_Y_SIZE, WHITENESS);

	// ボード
	paintBoard(shogi, hoveringKoma);

	// 持ち駒
	paintMochiGoma(shogi, hoveringKoma);

	// 手番
	paintTurn(shogi);
}
void paintBoard(const Shogi& shogi, const KomaAbs* hoveringKoma)
{
	// ボード
	BitBlt(getMem(), BOARD_X, BOARD_Y, BOARD_X_SIZE_PX, BOARD_Y_SIZE_PX, getBoard(), 0, 0, SRCCOPY);

	// ボード上の駒
	const Board& board = shogi.getBoard();
	for (int y = 0; y < BOARD_Y_SIZE; ++y)
	{
		int paintY = (y * MASU_Y_SIZE_PX) + BOARD_Y;
		for (int x = 0; x < BOARD_X_SIZE; ++x)
		{
			int paintX = (x * MASU_X_SIZE_PX) + BOARD_X;
			auto& koma = board.get(x, y);
			if (!koma || koma.get() == hoveringKoma)
			{
				// (空のマス || 掴んでいる駒) は描画しない
				continue;
			}
			auto& state = koma->getKomaState();
			auto img = getKoma(state);
			TransparentBlt(getMem(), paintX, paintY, MASU_X_SIZE_PX, MASU_Y_SIZE_PX, std::get<0>(img), std::get<1>(img), std::get<2>(img), MASU_X_SIZE_PX, MASU_Y_SIZE_PX, RGB(255, 255, 255));
		}
	}
}
void paintMochiGoma(const Shogi& shogi, const KomaAbs* hoveringKoma)
{

}
void paintTurn(const Shogi& shogi)
{
	auto imgSente = getTurn(KomaState::SenteGote::SENTE, shogi.getTurn());
	BitBlt(getMem(), BOARD_X + BOARD_X_SIZE_PX, BOARD_Y + BOARD_Y_SIZE_PX - MASU_Y_SIZE_PX, MASU_X_SIZE_PX, MASU_Y_SIZE_PX, std::get<0>(imgSente), std::get<1>(imgSente), std::get<2>(imgSente), SRCCOPY);

	auto imgGote = getTurn(KomaState::SenteGote::GOTE, shogi.getTurn());
	BitBlt(getMem(), BOARD_X - MASU_X_SIZE_PX, BOARD_Y, MASU_X_SIZE_PX, MASU_Y_SIZE_PX, std::get<0>(imgGote), std::get<1>(imgGote), std::get<2>(imgGote), SRCCOPY);
}
}
}

