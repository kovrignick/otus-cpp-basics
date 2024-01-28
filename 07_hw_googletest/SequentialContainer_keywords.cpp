#include "../06_hw_details_container/SequentialContainer.hpp"

bool SequentialArray_push_back() {
    MySequentialContainer<int> array{};
    for (int i = 0; i < 10; ++i) {
        array.push_back(i);
    }
    for (int i = 0; i < 10; ++i) {
        if (array[i] != i) {
            return false;
        }
    }
    return true;
}
bool SequentialArray_insert_front() {
    MySequentialContainer<int> array{};
    for (int i = 0; i < 10; ++i) {
        array.insert(0, i);
    }
    int j = 9;
    for (int i = 0; i < 10; ++i) {
        if (array[i] != j) {
            return false;
        }
        --j;
    }
    return true;
}

bool SequentialArray_insert() {
    MySequentialContainer<int> array{};
    for (int i = 0; i < 10; ++i) {
        if (i % 2 == 0) { array.push_back(i); }
    }
    for (int i = 0; i < 10; ++i) {
        if (i % 2 == 1) { array.insert(i, i); }
    }
    for (int i = 0; i < 10; ++i) {
        if (array[i] != i) {
            return false;
        }
    }
    return true;
}

bool SequentialArray_erase_back() {
    MySequentialContainer<int> array{};
    array.push_back(0);
    array.push_back(1);
    array.push_back(2);
    array.erase(2);
    array[2];
    return true;
}

bool SequentialArray_erase_front() {
    MySequentialContainer<int> array{};
    array.push_back(99);
    for (int i = 0; i < 10; ++i) {
        array.push_back(i);
    }
    array.erase(0);
    for (int i = 0; i < 10; ++i) {
        if (array[i] != i) {
            return false;
        }
    }
    return true;
}

bool SequentialArray_erase() {
    MySequentialContainer<int> array{};
    for (int i = 0; i < 10; ++i) {
        array.push_back(i);
    }
    for (int i = 9; i > 0; --i) {
        if (i % 2 == 1) { array.erase(i); }
    }
    int j = 0;
    for (int i = 0; i < 5; ++i) {
        if (array[i] != j) {
            return false;
        }
        j += 2;
    }
    return true;
}

bool SequentialArray_size_increase() {
    MySequentialContainer<int> array{};
    size_t expected_size = 0;
    size_t actual_size = array.size();
    for (int i = 0; i < 10; ++i) {
        if (expected_size != actual_size) { return false; }
        array.push_back(i);
        ++expected_size;
        actual_size = array.size();
        if (expected_size != actual_size) { return false; }
    }
    return true;
}

bool SequentialArray_size_decrease() {
    MySequentialContainer<int> array{};
    for (int i = 0; i < 10; ++i) {
        array.push_back(i);
    }
    size_t expected_size = 10;
    size_t actual_size = array.size();
    for (int i = 0; i < 10; ++i) {
        if (expected_size != actual_size) { return false; }
        array.erase(0);
        --expected_size;
        actual_size = array.size();
        if (expected_size != actual_size) { return false; }
    }
    return true;
}

bool SequentialArray_capacity_increase() {
    MySequentialContainer<int> array{};
    size_t expected_capacity = 5;
    size_t actual_capacity = array.capacity();
    for (int i = 0; i < 5; ++i) {
        if (expected_capacity != actual_capacity) { return false; }
        array.push_back(i);
        actual_capacity = array.capacity();
        if (expected_capacity != actual_capacity) { return false; }
    }
    expected_capacity *= 2;
    for (int i = 0; i < 5; ++i) {
        array.push_back(i);
        actual_capacity = array.capacity();
        if (expected_capacity != actual_capacity) { return false; }
    }
    array.push_back(0);
    expected_capacity *= 2;
    actual_capacity = array.capacity();
    if (expected_capacity != actual_capacity) { return false; }
    return true;
}

bool SequentialArray_copy_cstor() {
    MySequentialContainer<int> list1{};
    for (int i = 0; i < 10; ++i) {
        list1.push_back(i);
    }
    MySequentialContainer<int> list2{ list1 };
    for (int i = 0; i < 10; ++i) {
        if (list2[i] != i) { return false; }
    }
    if (list2.size() != list1.size()) { return false; }
    for (int i = 0; i < 10; ++i) {
        if (list1[i] != i) { return false; }
    }
    return true;
}

bool SequentialArray_move_cstor() {
    MySequentialContainer<int> list1{};
    for (int i = 0; i < 10; ++i) {
        list1.push_back(i);
    }
    MySequentialContainer<int> list2{ std::move(list1) };
    for (int i = 0; i < 10; ++i) {
        if (list2[i] != i) { return false; }
    }
    if (list2.size() == list1.size()) { return false; }
    if (list1.size() != 0) { return false; }
    return true;
}

bool SequentialArray_copy_assigment() {
    MySequentialContainer<int> list1{};
    for (int i = 0; i < 10; ++i) {
        list1.push_back(i);
    }
    MySequentialContainer<int> list2{};
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

bool SequentialArray_move_assigment() {
    MySequentialContainer<int> list1{};
    for (int i = 0; i < 10; ++i) {
        list1.push_back(i);
    }
    MySequentialContainer<int> list2{};
    list2 = std::move(list1);
    for (int i = 0; i < 10; ++i) {
        if (list2[i] != i) { return false; }
    }
    if (list2.size() == list1.size()) { return false; }
    if (list1.size() != 0) { return false; }
    return true;
}
