#pragma once

#include "Board.h"
#include "MochiGoma.h"

class Shogi
{
public:
	Shogi();

public:
	const Board& getBoard() const;
	const MochiGoma& getSenteMochi() const;
	const MochiGoma& getGoteMochi() const;

private:
	Board m_board;
	MochiGoma m_senteMochi;
	MochiGoma m_goteMochi;
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
