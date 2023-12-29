#include <iostream>
#include "SequentialContainer.hpp"
#include "LinkListContainer.hpp"

template <typename T>
void start(T container) {
    // 2
    for (size_t i = 0; i < 10; ++i) {
        container.push_back(i);
    }
    // 3
    std::cout << container << std::endl;
    // 4
    std::cout << "size: " << container.size() << std::endl;
    // 5
    container.erase(6);
    container.erase(4);
    container.erase(2);
    // 6
    std::cout << container << std::endl;
    // 7
    container.insert(0, 10);
    // 8
    std::cout << container << std::endl;
    // 9
    container.insert(4, 20);
    // 10
    std::cout << container << std::endl;
    // 11
    container.push_back(30);
    // 12
    std::cout << container << std::endl;
}

int main() 
{
    // Sequential container
    std::cout << "Sequential container: " << std::endl;
    // 1
    MySequentialContainer<int> seq_int;
    start(seq_int);
    
    std::cout << std::endl;
    
    // Unidirectional LinkList container
    std::cout << "Unidirectional LinkList container: " << std::endl;
    // 1
    MyLinkListContainer1<int> linklist1_int;
    start(linklist1_int);

	return 0;
}