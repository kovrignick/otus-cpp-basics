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

void rule_of_five_manual_test() {
    
    std::cout << "rule_of_five_manual_test - MySequentialContainer" << std::endl;
    /* Sequential container */
    MySequentialContainer<int> seq_int;
    seq_int.push_back(0);
    seq_int.push_back(1);
    seq_int.push_back(2);
    MySequentialContainer<int> seq_int2;
    seq_int2.push_back(4);
    seq_int2.push_back(5);
    //
    // MySequentialContainer<int> seq_int2 {seq_int};
    // MySequentialContainer<int> seq_int2 {std::move(seq_int)};
    // seq_int2 = seq_int;
    seq_int2 = std::move(seq_int);
    //
    seq_int.push_back(3);
    seq_int.push_back(4);
    seq_int2.push_back(6);
    seq_int2.push_back(7);
    seq_int2.push_back(8);
    std::cout << "data: " << seq_int << std::endl;
    std::cout << "size: " << seq_int.size() << std::endl;
    std::cout << "capa: " << seq_int.capacity() << std::endl;
    std::cout << std::endl;
    std::cout << "data: " << seq_int2 << std::endl;
    std::cout << "size: " << seq_int2.size() << std::endl;
    std::cout << "capa: " << seq_int2.capacity() << std::endl;
    
    std::cout << std::endl;
    std::cout << "rule_of_five_manual_test - MyLinkListContainer1" << std::endl;
    /* Unidirectional LinkList container */
    MyLinkListContainer1<int> linklist1_int;
    linklist1_int.push_back(0);
    linklist1_int.push_back(1);
    linklist1_int.push_back(2);
    MyLinkListContainer1<int> link2;
    link2.push_back(4);
    link2.push_back(5);
    //
    // MyLinkListContainer1<int> link2 {linklist1_int};
    // MyLinkListContainer1<int> link2 {std::move(linklist1_int)};
    // link2 = linklist1_int;
    link2 = std::move(linklist1_int);
    //
    linklist1_int.push_back(3);
    linklist1_int.push_back(4);
    link2.push_back(6);
    link2.push_back(7);
    link2.push_back(8);
    std::cout << "data: " << linklist1_int << std::endl;
    std::cout << "size: " << linklist1_int.size() << std::endl;
    std::cout << std::endl;
    std::cout << "data: " << link2 << std::endl;
    std::cout << "size: " << link2.size() << std::endl;

    std::cout << "rule_of_five_manual_test - done" << std::endl;
    std::cout << std::endl;
}


int main() 
{
    rule_of_five_manual_test();
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