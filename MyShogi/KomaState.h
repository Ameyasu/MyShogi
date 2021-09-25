/*
* ‹î‚PŒÂ•ª‚Ìó‘Ô‚ğ•\‚·
*/

#pragma once

struct KomaState
{
	enum class Type
	{
		HU,
		KYO,
		KEI,
		GIN,
		KIN,
		KAKU,
		HI,
		GYOKU,
		O
	};
	enum class Nari
	{
		NARAZU,
		NARI
	};
	enum class SenteGote
	{
		SENTE,
		GOTE
	};
	Type type = {};
	Nari nari = {};
	SenteGote senteGote = {};
};