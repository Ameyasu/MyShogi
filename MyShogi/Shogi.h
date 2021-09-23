#pragma once

#include "Board.h"
#include "MochiGoma.h"

class Shogi
{
public:
	Shogi();

private:
	Board m_board;
	MochiGoma m_senteMochi;
	MochiGoma m_goteMochi;
};