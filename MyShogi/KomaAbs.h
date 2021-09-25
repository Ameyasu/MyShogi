/*
* 駒の抽象クラス
* 銀とか金とかがこのクラスを継承する
*/

#pragma once

#include "framework.h"
#include "KomaState.h"

class Board;

class KomaAbs
{
public:
	KomaAbs(KomaState::Type type);
	virtual ~KomaAbs() = default;

public:
	const KomaState& getKomaState() const;
	void setNari(KomaState::Nari nari);
	void setSenteGote(KomaState::SenteGote senteGote);

	virtual std::vector<POINT> makeMovablePoints(const Board& board, int ox, int oy) = 0;

private:
	KomaState m_komaState;
};

inline KomaAbs::KomaAbs(KomaState::Type type)
	: m_komaState()
{
	m_komaState.type = type;
}

inline const KomaState& KomaAbs::getKomaState() const
{
	return m_komaState;
}

inline void KomaAbs::setNari(KomaState::Nari nari)
{
	m_komaState.nari = nari;
}

inline void KomaAbs::setSenteGote(KomaState::SenteGote senteGote)
{
	m_komaState.senteGote = senteGote;
}

