#pragma once
#include <vector>
#include <math.h>
#include "IStatistics.hpp"

class Std : public IStatistics {
public:
	void update(double next) override;
	double eval() const override;
	const char * name() const override;

private:
	std::vector<double> m_std;
	unsigned int count = 0;
	double total_value = 0;
};