#pragma once

#include "framework.h"
#include "KomaAbs.h"

class Board
{
public:
	static constexpr int X_SIZE = 9;
	static constexpr int Y_SIZE = 9;

public:
	Board();
	
public:
	const std::unique_ptr<KomaAbs>& get(int x, int y) const;
	void set(int x, int y, std::unique_ptr<KomaAbs> koma);

	/*
	* (bx, by)から(ax, ay)へ駒を移動する
	* 
	* @return 移動先にあった駒
	*/
	std::unique_ptr<KomaAbs> move(int bx, int by, int ax, int ay);

	bool in(int x, int y) const;
	void clear();

private:
	std::unique_ptr<KomaAbs> m_board[Y_SIZE][X_SIZE];
};