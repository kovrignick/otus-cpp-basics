#include <iostream>
#include "SequentialContainer.hpp"

int main() 
{
    // Sequential container
    std::cout << "Sequential container: " << std::endl;
    // 1
    MySequentialContainer<int> seq_int;
    // 2
    for (size_t i = 0; i < 10; ++i) {
        seq_int.push_back(i);
    }
    // 3
    std::cout << seq_int << std::endl;
    // 4
    std::cout << "size: " << seq_int.size() << std::endl;
    // 5
    seq_int.erase(6);
    seq_int.erase(4);
    seq_int.erase(2);
    // 6
    std::cout << seq_int << std::endl;
    // 7
    seq_int.insert(0, 10);
    // 8
    std::cout << seq_int << std::endl;
    // 9
    seq_int.insert(4, 20);
    // 10
    std::cout << seq_int << std::endl;
    // 11
    seq_int.push_back(30);
    // 12
    std::cout << seq_int << std::endl;



	return 0;
}