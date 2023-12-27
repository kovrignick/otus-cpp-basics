#pragma once
#include <iostream>

template <typename T>
class MySequentialContainer {
public:
    MySequentialContainer(): data_{nullptr}, size_{0} {}
    ~MySequentialContainer() { delete data_; };

    void push_back(T value);
    void insert(std::size_t index, T value);
    void erase(std::size_t index);
    size_t size();

    T operator[](std::size_t index);
    template <typename U> friend std::ostream& operator<<(std::ostream &os, const MySequentialContainer<U>& container);

private:
    T * data_ ;
    size_t size_ ;
};

template <typename T>
T MySequentialContainer<T>::operator[](std::size_t index) {
    for (size_t i = 0; i < size_; ++i) {
        if (i == index)
            return data_[i];
    }
    throw std::logic_error("IndexError");
};

template <typename T>
std::ostream& operator<<(std::ostream &os, const MySequentialContainer<T> & container) {
    for (size_t i = 0; i < container.size_; ++i) {
        os << container.data_[i] << " ";
    }
    return os;
}

template <typename T>
void MySequentialContainer<T>::push_back(T value) {
    T * new_data = new T[size_ + 1];
    for (size_t i = 0; i < size_; ++i) {
        new_data[i] = data_[i];
    }
    new_data[size_] = value;
    delete [] data_;
    data_ = new_data;
    size_ += 1;
};

template <typename T>
void MySequentialContainer<T>::insert(std::size_t index, T value) {
    if (index > size_) {
        throw std::logic_error("IndexError");
    }
    T * new_data = new T[size_ + 1];
    for (size_t i = 0; i < index; ++i) {
        new_data[i] = data_[i];
    }
    new_data[index] = value;
    for (size_t i = index; i <= size_; ++i) {
        new_data[i+1] = data_[i];
    }
    delete [] data_;
    data_ = new_data;
    size_ += 1;
};

template <typename T>
void MySequentialContainer<T>::erase(std::size_t index) {
    if (index >= size_) {
        throw std::logic_error("IndexError");        
    }
    T * new_data = new T[size_ - 1];
    for (size_t i = 0; i < index; ++i) {
        new_data[i] = data_[i];
    }
    for (size_t i = index; i < size_; ++i) {
        new_data[i] = data_[i+1];
    }
    delete [] data_;
    data_ = new_data;
    size_ -= 1;
};

template <typename T>
size_t MySequentialContainer<T>::size() {
    return size_;
};