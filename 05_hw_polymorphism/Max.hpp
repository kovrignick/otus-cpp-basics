#pragma once
#include <iostream>
#include <limits>
#include "IStatistics.hpp"

class Max : public IStatistics {
public:
	Max();
	void update(double next) override;
	double eval() const override;
	const char * name() const override;
    
private:
	double m_max;
	unsigned int count = 0;
};