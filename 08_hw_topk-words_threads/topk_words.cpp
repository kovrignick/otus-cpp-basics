// Read files and prints top k word by frequency

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <chrono>
#include <mutex>
#include <thread>

const size_t TOPK = 10;

using Counter = std::map<std::string, std::size_t>;

const Counter operator+ (const Counter& lhs, const Counter& rhs) {
    auto result = lhs;
    for (auto& [string, size]: rhs) result[string] += size;
    return result;
}

std::string tolower(const std::string &str);

void count_words(std::istream& stream, Counter&);

void print_topk(std::ostream& stream, const Counter&, const size_t k);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: topk_words [FILES...]\n";
        return EXIT_FAILURE;
    }

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::ifstream> files;
    for (int i = 1; i < argc; ++i) {
        files.emplace_back(argv[i]);
        if (!files[i-1].is_open()) {
            std::cerr << "Failed to open file " << argv[i] << '\n';
            return EXIT_FAILURE;
        }
    }
    std::vector<std::thread> threads;
    std::vector<Counter> counters{files.size()};
    size_t i = 0;
    for (auto& input: files) {
        std::thread count_th{count_words, std::ref(input), std::ref(counters[i])};
        std::cout << "count_th " << count_th.get_id() << " started working\n";
        threads.emplace_back(std::move(count_th));
        ++i;
    }
    for (auto &count_th: threads) {
        std::thread::id clerk_id = count_th.get_id();
        count_th.join();
        std::cout << "count_th " << clerk_id << " ended his work\n";
    }
    Counter freq_dict;
    for (auto& counter : counters) { 
        freq_dict = freq_dict + counter; 
    }
    print_topk(std::cout, freq_dict, TOPK);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Elapsed time is " << elapsed_ms.count() << " us\n";
}

std::string tolower(const std::string &str) {
    std::string lower_str;
    std::transform(std::cbegin(str), std::cend(str),
                   std::back_inserter(lower_str),
                   [](unsigned char ch) { return std::tolower(ch); });
    return lower_str;
};

void count_words(std::istream& stream, Counter& counter) {
    std::for_each(std::istream_iterator<std::string>(stream),
                  std::istream_iterator<std::string>(),
                  [&counter](const std::string &s) { ++counter[tolower(s)]; });    
}

void print_topk(std::ostream& stream, const Counter& counter, const size_t k) {
    std::vector<Counter::const_iterator> words;
    words.reserve(counter.size());
    for (auto it = std::cbegin(counter); it != std::cend(counter); ++it) {
        words.push_back(it);
    }

    std::partial_sort(
        std::begin(words), std::begin(words) + k, std::end(words),
        [](auto lhs, auto &rhs) { return lhs->second > rhs->second; });

    std::for_each(
        std::begin(words), std::begin(words) + k,
        [&stream](const Counter::const_iterator &pair) {
            stream << std::setw(4) << pair->second << " " << pair->first
                      << '\n';
        });
}