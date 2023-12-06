#include "Mean.hpp"

void Mean::update(double next) {
    total_value += next;
    count++;
    m_mean = total_value / count;
}

double Mean::eval() const {
    return m_mean;
}

const char * Mean::name() const {
    return "mean";
}
