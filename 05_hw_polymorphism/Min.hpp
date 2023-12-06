#pragma once
#include <iostream>
#include <limits>
#include "IStatistics.hpp"

class Min : public IStatistics {
public:
	Min();
	void update(double next) override;
	double eval() const override;
	const char * name() const override;

private:
	double m_min;
	unsigned int count = 0;
};