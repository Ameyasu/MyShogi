#include "framework.h"
#include "InitialPlacer.h"
#include "KomaCon.h"

namespace InitialPlacer
{
void hirate(Board& board)
{
	board.clear();

	// ï‡
	for (int x = 0; x < Board::X_SIZE; ++x)
	{
		board.set(x, 6, std::unique_ptr<KomaAbs>(new KomaHu));

		auto koma = std::unique_ptr<KomaHu>(new KomaHu);
		koma->setSenteGote(KomaState::SenteGote::GOTE);
		board.set(x, 2, std::move(koma));
	}

	// çÅ
	{
		board.set(0, 8, std::unique_ptr<KomaAbs>(new KomaKyo));
		board.set(8, 8, std::unique_ptr<KomaAbs>(new KomaKyo));

		auto koma = std::unique_ptr<KomaAbs>(new KomaKyo);
		koma->setSenteGote(KomaState::SenteGote::GOTE);
		board.set(0, 0, std::move(koma));
		koma = std::unique_ptr<KomaAbs>(new KomaKyo);
		koma->setSenteGote(KomaState::SenteGote::GOTE);
		board.set(8, 0, std::move(koma));
	}

	// åj
	{
		board.set(1, 8, std::unique_ptr<KomaAbs>(new KomaKei));
		board.set(7, 8, std::unique_ptr<KomaAbs>(new KomaKei));

		auto koma = std::unique_ptr<KomaAbs>(new KomaKei);
		koma->setSenteGote(KomaState::SenteGote::GOTE);
		board.set(1, 0, std::move(koma));
		koma = std::unique_ptr<KomaAbs>(new KomaKei);
		koma->setSenteGote(KomaState::SenteGote::GOTE);
		board.set(7, 0, std::move(koma));
	}

	// ã‚
	{
		board.set(2, 8, std::unique_ptr<KomaAbs>(new KomaGin));
		board.set(6, 8, std::unique_ptr<KomaAbs>(new KomaGin));

		auto koma = std::unique_ptr<KomaAbs>(new KomaGin);
		koma->setSenteGote(KomaState::SenteGote::GOTE);
		board.set(2, 0, std::move(koma));
		koma = std::unique_ptr<KomaAbs>(new KomaGin);
		koma->setSenteGote(KomaState::SenteGote::GOTE);
		board.set(6, 0, std::move(koma));
	}

	// ã‡
	{
		board.set(3, 8, std::unique_ptr<KomaAbs>(new KomaKin));
		board.set(5, 8, std::unique_ptr<KomaAbs>(new KomaKin));

		auto koma = std::unique_ptr<KomaAbs>(new KomaKin);
		koma->setSenteGote(KomaState::SenteGote::GOTE);
		board.set(3, 0, std::move(koma));
		koma = std::unique_ptr<KomaAbs>(new KomaKin);
		koma->setSenteGote(KomaState::SenteGote::GOTE);
		board.set(5, 0, std::move(koma));
	}

	// äp
	{
		board.set(1, 7, std::unique_ptr<KomaAbs>(new KomaKaku));

		auto koma = std::unique_ptr<KomaAbs>(new KomaKaku);
		koma->setSenteGote(KomaState::SenteGote::GOTE);
		board.set(7, 1, std::move(koma));
	}

	// îÚ
	{
		board.set(7, 7, std::unique_ptr<KomaAbs>(new KomaHi));

		auto koma = std::unique_ptr<KomaAbs>(new KomaHi);
		koma->setSenteGote(KomaState::SenteGote::GOTE);
		board.set(1, 1, std::move(koma));
	}

	// ã 
	{
		board.set(4, 8, std::unique_ptr<KomaAbs>(new KomaO));

		auto koma = std::unique_ptr<KomaAbs>(new KomaGyoku);
		koma->setSenteGote(KomaState::SenteGote::GOTE);
		board.set(4, 0, std::move(koma));
	}
}

void nimaiochi(Board& board)
{
	// ïΩéËÇ∆ìØÇ∂ÇÊÇ§Ç…íuÇ≠
	hirate(board);

	// äpÇè¡Ç∑
	board.set(1, 7, std::unique_ptr<KomaAbs>());

	// îÚÇè¡Ç∑
	board.set(7, 7, std::unique_ptr<KomaAbs>());
}

}

