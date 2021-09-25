#include "Shogi.h"
#include "InitialPlacer.h"

Shogi::Shogi()
	: m_board()
	, m_senteMochi()
	, m_goteMochi()
	, m_turn()
	, m_winner()
{
}

void Shogi::startNewGame()
{
	InitialPlacer::hirate(m_board);
	m_senteMochi.clear();
	m_goteMochi.clear();
	m_turn = Turn::SENTE;
	m_winner = Winner::GAMING;
}