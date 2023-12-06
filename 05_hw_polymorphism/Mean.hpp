#pragma once
#include "IStatistics.hpp"

class Mean : public IStatistics {
public:
	void update(double next) override;
	double eval() const override;
	const char * name() const override;

private:
	double m_mean;
	unsigned int count = 0;
	double total_value = 0;
};