#include "MochiGoma.h"

MochiGoma::MochiGoma()
	: m_mochi()
{
}

void MochiGoma::add(std::unique_ptr<KomaAbs> koma)
{
}

std::unique_ptr<KomaAbs> MochiGoma::remove(KomaState::Type type)
{
	return std::unique_ptr<KomaAbs>();
}
