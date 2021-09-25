#pragma once

#include "framework.h"
#include "KomaAbs.h"

class MochiGoma
{
public:
	MochiGoma();

public:
	const std::vector<std::unique_ptr<KomaAbs>>& get() const;
	void add(std::unique_ptr<KomaAbs> koma);
	std::unique_ptr<KomaAbs> remove(KomaState::Type type);
	void clear();

private:
	std::vector<std::unique_ptr<KomaAbs>> m_mochi;
};

inline const std::vector<std::unique_ptr<KomaAbs>>& MochiGoma::get() const
{
	return m_mochi;
}