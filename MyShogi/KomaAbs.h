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
	KomaAbs();

public:
	const KomaState& GetKomaState() const;
	void SetNari(KomaState::Nari nari);
	void SetSenteGote(KomaState::SenteGote senteGote);

	virtual std::vector<POINT> MakeMovablePoints(const Board& board, int ox, int oy) = 0;

protected:
	KomaState m_komaState;
};

inline KomaAbs::KomaAbs()
	: m_komaState()
{
}

inline const KomaState& KomaAbs::GetKomaState() const
{
	return m_komaState;
}

inline void KomaAbs::SetNari(KomaState::Nari nari)
{
	m_komaState.nari = nari;
}

inline void KomaAbs::SetSenteGote(KomaState::SenteGote senteGote)
{
	m_komaState.senteGote = senteGote;
}

