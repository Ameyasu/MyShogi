#include "KomaCon.h"
#include "Board.h"

std::vector<POINT> KomaHu::makeMovablePoints(const Board& board, int ox, int oy)
{
	int x = ox;
	int y = (getKomaState().senteGote == KomaState::SenteGote::SENTE) ? oy - 1 : oy + 1;
	if (!board.in(x, y))
		return std::vector<POINT>();

	auto& koma = board.get(x, y);
	if (!koma || koma->getKomaState().senteGote != getKomaState().senteGote)
		return {{x, y}};

	return std::vector<POINT>();
}

std::vector<POINT> KomaKyo::makeMovablePoints(const Board& board, int ox, int oy)
{
	std::vector<POINT> ret;
	int dy = (getKomaState().senteGote == KomaState::SenteGote::SENTE) ? -1 : 1;
	int x = ox;

	// 行けるところまで前
	for (int y = oy + dy; board.in(x, y); y += dy)
	{
		auto& koma = board.get(x, y);
		if (!koma)
		{
			ret.push_back({x, y});
		}
		else
		{
			if (koma->getKomaState().senteGote != getKomaState().senteGote)
			{
				ret.push_back({x, y});
			}
			break;
		}
	}
	return ret;
}

std::vector<POINT> KomaKei::makeMovablePoints(const Board& board, int ox, int oy)
{
	std::vector<POINT> ret;
	int x = ox - 1;
	int y = (getKomaState().senteGote == KomaState::SenteGote::SENTE) ? -2 : 2;

	// 左前
	auto& komaLeft = board.get(x, y);
	if (board.in(x, y) && (!komaLeft || komaLeft->getKomaState().senteGote != getKomaState().senteGote))
		ret.push_back({x, y});

	// 右前
	x = ox + 1;
	auto& komaRight = board.get(x, y);
	if (board.in(x, y) && (!komaRight || komaRight->getKomaState().senteGote != getKomaState().senteGote))
		ret.push_back({x, y});

	return ret;
}

std::vector<POINT> KomaGin::makeMovablePoints(const Board& board, int ox, int oy)
{
	std::vector<POINT> ret;
	int dy = (getKomaState().senteGote == KomaState::SenteGote::SENTE) ? 1 : -1;
	int y = oy - dy;

	// 前の３マス
	for (int dx = -1; dx <= 1; ++dx) {
		int x = ox + dx;
		auto& koma = board.get(x, y);
		if (board.in(x, y) && (!koma || koma->getKomaState().senteGote != getKomaState().senteGote))
			ret.push_back({x, y});
	}

	// 左後ろ 右後ろ
	y = oy + dy;
	for (int dx = -1; dx <= 1; dx += 2) {
		int x = ox + dx;
		auto& koma = board.get(x, y);
		if (board.in(x, y) && (!koma || koma->getKomaState().senteGote != getKomaState().senteGote))
			ret.push_back({x, y});
	}

	return ret;
}

std::vector<POINT> KomaKin::makeMovablePoints(const Board& board, int ox, int oy)
{
	std::vector<POINT> ret;
	int dy = (getKomaState().senteGote == KomaState::SenteGote::SENTE) ? 1 : -1;
	int y = oy - dy;

	// 前の３マス
	for (int dx = -1; dx <= 1; ++dx) {
		int x = ox + dx;
		auto& koma = board.get(x, y);
		if (board.in(x, y) && (!koma || koma->getKomaState().senteGote != getKomaState().senteGote))
			ret.push_back({x, y});
	}

	// 左右
	y = oy;
	for (int dx = -1; dx <= 1; dx += 2) {
		int x = ox + dx;
		auto& koma = board.get(x, y);
		if (board.in(x, y) && (!koma || koma->getKomaState().senteGote != getKomaState().senteGote))
			ret.push_back({x, y});
	}

	// 真後ろ
	y = oy + dy;
	{
		int x = ox;
		auto& koma = board.get(x, y);
		if (board.in(x, y) && (!koma || koma->getKomaState().senteGote != getKomaState().senteGote))
			ret.push_back({x, y});
	}

	return ret;
}

std::vector<POINT> KomaKaku::makeMovablePoints(const Board& board, int ox, int oy)
{
	std::vector<POINT> ret;
	for (int dy = -1; dy <= 1; dy += 2)
	{
		for (int dx = -1; dx <= 1; dx += 2)
		{
			// 行けるところまで
			for (int x = ox + dx, y = oy + dy; board.in(x, y); x += dx, y += dy)
			{
				auto& koma = board.get(x, y);
				if (!koma)
				{
					ret.push_back({x, y});
				}
				else
				{
					if (koma->getKomaState().senteGote != getKomaState().senteGote)
					{
						ret.push_back({x, y});
					}
					break;
				}
			}
		}
	}
	return ret;
}

std::vector<POINT> KomaHi::makeMovablePoints(const Board& board, int ox, int oy)
{
	std::vector<POINT> ret;
	for (int dy = -1; dy <= 1; dy += 2)
	{
		// 行けるところまで
		for (int y = oy + dy; board.in(ox, y); y += dy)
		{
			auto& koma = board.get(ox, y);
			if (!koma)
			{
				ret.push_back({ox, y});
			}
			else
			{
				if (koma->getKomaState().senteGote != getKomaState().senteGote)
				{
					ret.push_back({ox, y});
				}
				break;
			}
		}
	}
	for (int dx = -1; dx <= 1; dx += 2)
	{
		// 行けるところまで
		for (int x = ox + dx; board.in(x, oy); x += dx)
		{
			auto& koma = board.get(x, oy);
			if (!koma)
			{
				ret.push_back({x, oy});
			}
			else
			{
				if (koma->getKomaState().senteGote != getKomaState().senteGote)
				{
					ret.push_back({x, oy});
				}
				break;
			}
		}
	}
	return ret;
}

std::vector<POINT> KomaGyoku::makeMovablePoints(const Board& board, int ox, int oy)
{
	std::vector<POINT> ret;
	for (int dy = -1; dy <= 1; ++dy)
	{
		for (int dx = -1; dx <= 1; ++dx)
		{
			if (dx == 0 && dy == 0)
				continue;

			int x = ox + dx;
			int y = oy + dy;
			auto& koma = board.get(x, y);
			if (board.in(x, y) && (!koma || koma->getKomaState().senteGote != getKomaState().senteGote))
				ret.push_back({x, y});
		}
	}
	return ret;
}
