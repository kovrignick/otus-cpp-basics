#include "Std.hpp"

void Std::update(double next) {
    total_value += next;
    count++;
    m_std.push_back(next);
}

double Std::eval() const {
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

const char * Std::name() const {
    return "std";
}