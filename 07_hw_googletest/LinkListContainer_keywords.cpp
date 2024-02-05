#include "../06_hw_details_container/LinkListContainer.hpp"

bool LinkList_push_back() {
    MyLinkListContainer1<int> list{};
    for (int i = 0; i < 10; ++i) {
        list.push_back(i);
    }
    for (int i = 0; i < 10; ++i) {
        if (list[i] != i) {
            return false;
        }
    }
    return true;
}

bool LinkList_insert_front() {
    MyLinkListContainer1<int> list{};
    for (int i = 0; i < 10; ++i) {
        list.insert(0, i);
    }
    int j = 9;
    for (int i = 0; i < 10; ++i) {
        if (list[i] != j) {
            return false;
        }
        --j;
    }
    return true;
}

bool LinkList_insert() {
    MyLinkListContainer1<int> list{};
    for (int i = 0; i < 10; ++i) {
        if (i % 2 == 0) { list.push_back(i); }
    }
    for (int i = 0; i < 10; ++i) {
        if (i % 2 == 1) { list.insert(i, i); }
    }
    for (int i = 0; i < 10; ++i) {
        if (list[i] != i) {
            return false;
        }
    }
    return true;
}

bool LinkList_erase_back() {
    MyLinkListContainer1<int> list{};
    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.erase(2);
    list[2];
    return true;
}

bool LinkList_erase_front() {
    MyLinkListContainer1<int> list{};
    list.push_back(99);
    for (int i = 0; i < 10; ++i) {
        list.push_back(i);
    }
    list.erase(0);
    for (int i = 0; i < 10; ++i) {
        if (list[i] != i) {
            return false;
        }
    }
    return true;
}

bool LinkList_erase() {
    MyLinkListContainer1<int> list{};
    for (int i = 0; i < 10; ++i) {
        list.push_back(i);
    }
    for (int i = 9; i > 0; --i) {
        if (i % 2 == 1) { list.erase(i); }
    }
    int j = 0;
    for (int i = 0; i < 5; ++i) {
        if (list[i] != j) {
            return false;
        }
        j += 2;
    }
    return true;
}

bool LinkList_size_increase() {
    MyLinkListContainer1<int> list{};
    size_t expected_size = 0;
    size_t actual_size = list.size();
    for (int i = 0; i < 10; ++i) {
        if (expected_size != actual_size) { return false; }
        list.push_back(i);
        ++expected_size;
        actual_size = list.size();
        if (expected_size != actual_size) { return false; }
    }
    return true;
}

bool LinkList_size_decrease() {
    MyLinkListContainer1<int> list{};
    for (int i = 0; i < 10; ++i) {
        list.push_back(i);
    }
    size_t expected_size = 10;
    size_t actual_size = list.size();
    for (int i = 0; i < 10; ++i) {
        if (expected_size != actual_size) { return false; }
        list.erase(0);
        --expected_size;
        actual_size = list.size();
        if (expected_size != actual_size) { return false; }
    }
    return true;
}

bool LinkList_copy_cstor() {
    MyLinkListContainer1<int> list1{};
    for (int i = 0; i < 10; ++i) {
        list1.push_back(i);
    }
    MyLinkListContainer1<int> list2{ list1 };
    for (int i = 0; i < 10; ++i) {
        if (list2[i] != i) { return false; }
    }
    if (list2.size() != list1.size()) { return false; }
    for (int i = 0; i < 10; ++i) {
        if (list1[i] != i) { return false; }
    }
    return true;
}

bool LinkList_move_cstor() {
    MyLinkListContainer1<int> list1{};
    for (int i = 0; i < 10; ++i) {
        list1.push_back(i);
    }
    MyLinkListContainer1<int> list2{ std::move(list1) };
    for (int i = 0; i < 10; ++i) {
        if (list2[i] != i) { return false; }
    }
    if (list2.size() == list1.size()) { return false; }
    if (list1.size() != 0) { return false; }
    return true;
}

bool LinkList_copy_assigment() {
    MyLinkListContainer1<int> list1{};
    for (int i = 0; i < 10; ++i) {
        list1.push_back(i);
    }
    MyLinkListContainer1<int> list2{};
    list2 = list1;
    for (int i = 0; i < 10; ++i) {
        if (list2[i] != i) { return false; }
    }
    if (list2.size() != list1.size()) { return false; }
    for (int i = 0; i < 10; ++i) {
        if (list1[i] != i) { return false; }
    }
    return true;
}

bool LinkList_move_assigment() {
    MyLinkListContainer1<int> list1{};
    for (int i = 0; i < 10; ++i) {
        list1.push_back(i);
    }
    MyLinkListContainer1<int> list2{};
    list2 = std::move(list1);
    for (int i = 0; i < 10; ++i) {
        if (list2[i] != i) { return false; }
    }
    if (list2.size() == list1.size()) { return false; }
    if (list1.size() != 0) { return false; }
    return true;
}