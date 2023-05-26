#include <iostream>
#include <limits>
#include <vector>
#include <math.h>

class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;
	virtual double eval() const = 0;
	virtual const char * name() const = 0;
};

class Min : public IStatistics {
public:
	Min() : m_min{std::numeric_limits<double>::min()} {
	}

	void update(double next) override {
		if (count == 0) {
			m_min = next;
		}
		count++;
		if (next < m_min) {			
			m_min = next;
		}
	}

	double eval() const override {
		return m_min;
	}

	const char * name() const override {
		return "min";
	}

private:
	double m_min;
	unsigned int count = 0;
};

class Max : public IStatistics {
public:
	Max() : m_max{std::numeric_limits<double>::max()} {
	}

	void update(double next) override {
		if (count == 0) {
			m_max = next;
		}
		count++;
		if (next > m_max) {			
			m_max = next;
		}
	}

	double eval() const override {
		return m_max;
	}

	const char * name() const override {
		return "max";
	}

private:
	double m_max;
	unsigned int count = 0;
};

class Mean : public IStatistics {
public:
	Mean() : m_mean{} {
	}

	void update(double next) override {
		total_value += next;
		count++;
		m_mean = total_value / count;
	}

	double eval() const override {
		return m_mean;
	}

	const char * name() const override {
		return "mean";
	}

private:
	double m_mean;
	unsigned int count = 0;
	double total_value = 0;
};

class Std : public IStatistics {
public:
	Std() : m_std{} {
	}

	void update(double next) override {
		total_value += next;
		count++;
		m_std.push_back(next);
	}

	double eval() const override {
		double mean;
		double variance = 0;
		double deviation = 0;
		mean = total_value / count;
		for (const auto &x : m_std) {
			variance += (x - mean) * (x - mean);
		}
		variance /= count - 1;
		deviation = sqrt(variance);
		return deviation;
	}

	const char * name() const override {
		return "std";
	}

private:
	std::vector<double> m_std;
	unsigned int count = 0;
	double total_value = 0;
};

int main() {

	const size_t statistics_count = 1;
	IStatistics *statistics_min[statistics_count];
	IStatistics *statistics_max[statistics_count];
	IStatistics *statistics_mean[statistics_count];
	IStatistics *statistics_std[statistics_count];

	statistics_min[0] = new Min{};
	statistics_max[0] = new Max{};
	statistics_mean[0] = new Mean{};
	statistics_std[0] = new Std{};

	double val = 0;
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics_min[i]->update(val);
			statistics_max[i]->update(val);
			statistics_mean[i]->update(val);
			statistics_std[i]->update(val);
		}
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics_min[i]->name() << " = " << statistics_min[i]->eval() << std::endl;
		std::cout << statistics_max[i]->name() << " = " << statistics_max[i]->eval() << std::endl;
		std::cout << statistics_mean[i]->name() << " = " << statistics_mean[i]->eval() << std::endl;
		std::cout << statistics_std[i]->name() << " = " << statistics_std[i]->eval() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics_min[i];
		delete statistics_max[i];
		delete statistics_mean[i];
		delete statistics_std[i];
	}

	return 0;
}
