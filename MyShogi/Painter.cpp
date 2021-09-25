#include "Painter.h"
#include "BmpOwner.h"
#include "ScreenLayout.h"

using namespace ScreenLayout;
using namespace BmpOwner;

namespace Painter
{
//______________________________________________________________
// �ȉ��Aprivate �ϐ���`
namespace
{
const KomaAbs* g_hoveringKoma;
}


//______________________________________________________________
// �ȉ��Aprivate �v���g�^�C�v�錾
namespace
{
void paintDefault(const Shogi& shogi, const KomaAbs* hoveringKoma);
void paintBoard(const Shogi& shogi, const KomaAbs* hoveringKoma);
void paintMochiGoma(const Shogi& shogi, const KomaAbs* hoveringKoma);
void paintTurn(const Shogi& shogi);
}


//______________________________________________________________
// �ȉ��Apublic �֐���`

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

	// �z�o�����O���Ă��������`�悳��Ă��Ȃ��摜���R�s�[
	BitBlt(getMemTmp(), 0, 0, CLIENT_X_SIZE, CLIENT_Y_SIZE, getMem(), 0, 0, SRCCOPY);
}

void paintKomaHovering(int x, int y)
{
	// �z�o�����O���Ă��������`�悳��Ă��Ȃ��摜��`��
	BitBlt(getMem(), 0, 0, CLIENT_X_SIZE, CLIENT_Y_SIZE, getMemTmp(), 0, 0, SRCCOPY);

	// �z�o�����O���Ă�����`��
}


//______________________________________________________________
// �ȉ��Aprivate �֐���`
namespace
{
void paintDefault(const Shogi& shogi, const KomaAbs* hoveringKoma)
{
	// ��肠�����S���^�����Ƀ��Z�b�g
	PatBlt(getMem(), 0, 0, CLIENT_X_SIZE, CLIENT_Y_SIZE, WHITENESS);

	// �{�[�h
	paintBoard(shogi, hoveringKoma);

	// ������
	paintMochiGoma(shogi, hoveringKoma);

	// ���
	paintTurn(shogi);
}
void paintBoard(const Shogi& shogi, const KomaAbs* hoveringKoma)
{
	// �{�[�h
	BitBlt(getMem(), BOARD_X, BOARD_Y, BOARD_X_SIZE_PX, BOARD_Y_SIZE_PX, getBoard(), 0, 0, SRCCOPY);

	// �{�[�h��̋�
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
				// (��̃}�X || �͂�ł����) �͕`�悵�Ȃ�
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

