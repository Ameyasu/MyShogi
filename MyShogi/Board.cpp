#include "Board.h"

Board::Board()
	: m_board()
{
}

const std::unique_ptr<KomaAbs>& Board::get(int x, int y) const
{
	if (in(x, y))
		return m_board[y][x];

	static std::unique_ptr<KomaAbs> s_null;
	return s_null;
}

void Board::set(int x, int y, std::unique_ptr<KomaAbs> koma)
{
	if (in(x, y))
		m_board[y][x] = std::move(koma);
}

std::unique_ptr<KomaAbs> Board::move(int bx, int by, int ax, int ay)
{
	if (!in(bx, by) || !in(ax, ay))
		return std::unique_ptr<KomaAbs>();

	std::unique_ptr<KomaAbs> ret = std::move(m_board[ay][ax]);
	m_board[ay][ax] = std::move(m_board[by][bx]);

	return ret;
}

bool Board::in(int x, int y) const
{
	return 0 <= x && x < X_SIZE && 0 <= y && y < Y_SIZE;
}

void Board::clear()
{
	for (int y = 0; y < Y_SIZE; ++y)
	{
		for (int x = 0; x < X_SIZE; ++x)
		{
			m_board[y][x] = std::unique_ptr<KomaAbs>();
		}
	}
}
