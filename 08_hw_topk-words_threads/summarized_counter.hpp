#pragma once
#include <map>
#include <string>

class SummarizedCounter {
private:
    std::map<std::string, std::size_t> sc;
public:
    ~SummarizedCounter(){};
    
    SummarizedCounter(){};
    
    SummarizedCounter(std::string value, std::size_t count) { sc[value] = count; }
    
    std::size_t& operator[](const std::string& value) { return sc[value]; }

    SummarizedCounter& operator+= (const SummarizedCounter& other) {
        for (const auto& element : other.sc) { sc[element.first] += element.second; }
        return *this;
    }
    inline std::size_t size() const noexcept {
        return sc.size();
    }
    std::map<std::string, std::size_t>::iterator begin() {
        return sc.begin();
    }
    std::map<std::string, std::size_t>::iterator end() {
        return sc.end();
    }
};

const SummarizedCounter operator+ (const SummarizedCounter& lhs, const SummarizedCounter& rhs) {
  auto result = lhs;
  result += rhs;
  return result;
}