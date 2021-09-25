#pragma once

#include "Board.h"
#include "MochiGoma.h"

class Shogi
{
public:
	enum class Turn
	{
		SENTE,
		GOTE
	};
	enum class Winner
	{
		GAMING,
		SENTE,
		GOTE
	};

public:
	Shogi();

public:
	void startNewGame();

	const Board& getBoard() const;
	const MochiGoma& getSenteMochi() const;
	const MochiGoma& getGoteMochi() const;
	Turn getTurn() const;
	Winner getWinner() const;

private:
	Board m_board;
	MochiGoma m_senteMochi;
	MochiGoma m_goteMochi;

	Turn m_turn;
	Winner m_winner;
};


inline const Board& Shogi::getBoard() const
{
	return m_board;
}
inline const MochiGoma& Shogi::getSenteMochi() const
{
	return m_senteMochi;
}
inline const MochiGoma& Shogi::getGoteMochi() const
{
	return m_goteMochi;
}
inline Shogi::Turn Shogi::getTurn() const
{
	return m_turn;
}
inline Shogi::Winner Shogi::getWinner() const
{
	return m_winner;
}