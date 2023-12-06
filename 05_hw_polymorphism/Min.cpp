#include "Min.hpp"

Min::Min() {
    m_min = std::numeric_limits<double>::min();
}

void Min::update(double next) {
    if (count == 0) {
        m_min = next;
    }
    count++;
    if (next < m_min) {			
        m_min = next;
    }
}

double Min::eval() const {
    return m_min;
}

const char * Min::name() const {
    return "min";
}