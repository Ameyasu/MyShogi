#pragma once

#include "KomaAbs.h"

class KomaHu : public KomaAbs
{
public:
	KomaHu() : KomaAbs(KomaState::Type::HU) {}
	std::vector<POINT> makeMovablePoints(const Board& board, int ox, int oy) override;
};

class KomaKyo : public KomaAbs
{
public:
	KomaKyo() : KomaAbs(KomaState::Type::KYO) {}
	std::vector<POINT> makeMovablePoints(const Board& board, int ox, int oy) override;
};

class KomaKei : public KomaAbs
{
public:
	KomaKei() : KomaAbs(KomaState::Type::KEI) {}
	std::vector<POINT> makeMovablePoints(const Board& board, int ox, int oy) override;
};

class KomaGin : public KomaAbs
{
public:
	KomaGin() : KomaAbs(KomaState::Type::GIN) {}
	std::vector<POINT> makeMovablePoints(const Board& board, int ox, int oy) override;
};

class KomaKin : public KomaAbs
{
public:
	KomaKin() : KomaAbs(KomaState::Type::KIN) {}
	std::vector<POINT> makeMovablePoints(const Board& board, int ox, int oy) override;
};

class KomaKaku : public KomaAbs
{
public:
	KomaKaku() : KomaAbs(KomaState::Type::KAKU) {}
	std::vector<POINT> makeMovablePoints(const Board& board, int ox, int oy) override;
};

class KomaHi : public KomaAbs
{
public:
	KomaHi() : KomaAbs(KomaState::Type::HI) {}
	std::vector<POINT> makeMovablePoints(const Board& board, int ox, int oy) override;
};

class KomaGyoku : public KomaAbs
{
public:
	KomaGyoku() : KomaAbs(KomaState::Type::GYOKU) {}
	virtual ~KomaGyoku() = default;
protected:
	KomaGyoku(KomaState::Type type) : KomaAbs(type) {}
public:
	std::vector<POINT> makeMovablePoints(const Board& board, int ox, int oy) override;
};

class KomaO : public KomaGyoku
{
public:
	KomaO() : KomaGyoku(KomaState::Type::O) {}
};

