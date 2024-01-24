#pragma once
#include <iostream>
#include <utility>

template <typename T>
class MySequentialContainer {
public:
    MySequentialContainer(): size_{0}, data_{nullptr} {}

    ~MySequentialContainer() { delete [] data_; };

    MySequentialContainer(const MySequentialContainer& other)
        : MySequentialContainer() {
            for (size_t i = 0; i < other.size_; ++i) {
                this->push_back(other.data_[i]);
        }
    };

    MySequentialContainer(MySequentialContainer&& other) noexcept 
        : MySequentialContainer() {
            std::swap(this->data_, other.data_);
            std::swap(this->size_, other.size_);
            std::swap(this->capacity_, other.capacity_);
    };

    MySequentialContainer& operator=(const MySequentialContainer& other) {
        if (this == &other)
            return *this;
        delete [] data_;
        MySequentialContainer temp{other};
        std::swap(this->data_, temp.data_);
        std::exchange(this->size_, temp.size_);
        std::exchange(this->capacity_, temp.capacity_);
        return *this;
    };

    MySequentialContainer& operator=(MySequentialContainer&& other) {
        if (this == &other)
            return *this;
        delete [] data_;
        data_ = nullptr;
        size_ = 0;
        capacity_ = 5;
        std::swap(this->data_, other.data_);
        std::swap(this->size_, other.size_);
        std::swap(this->capacity_, other.capacity_);
        return *this;
    };

    void push_back(T value);

    void insert(std::size_t index, T value);

    void erase(std::size_t index);

    size_t size();

    size_t capacity();

    T operator[](std::size_t index);

    template <typename U> friend std::ostream& operator<<(std::ostream &os, const MySequentialContainer<U>& container);

private:
    size_t capacity_ = 5 ;
    size_t size_ ;
    T * data_ ;
};

template <typename T>
T MySequentialContainer<T>::operator[](std::size_t index) {
    if (index >= size_) {
        throw std::logic_error("IndexError");
    }
    return data_[index];
};

template <typename T>
std::ostream& operator<<(std::ostream &os, const MySequentialContainer<T> & container) {
    for (size_t i = 0; i < container.size_; ++i) {
        os << container.data_[i] << " ";
    }
    return os;
};

template <typename T>
void MySequentialContainer<T>::push_back(T value) {
    if (size_ == 0) {
        data_ = new T[capacity_];
    }
    if (capacity_ < size_ + 1) {
        capacity_ = capacity_ * 2;
        T * new_data = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }
        delete [] data_;
        data_ = new_data;
    }
    data_[size_] = value;
    ++size_;
};

template <typename T>
void MySequentialContainer<T>::insert(std::size_t index, T value) {
    if (index > size_) {
        throw std::logic_error("IndexError");
    }
    if (size_ == 0) {
        data_ = new T[capacity_];
        data_[0] = value;
    }
    if (capacity_ < size_ + 1) {
        capacity_ = capacity_ * 2;
        T * new_data = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }
        delete [] data_;
        data_ = new_data;
    }
    T tmp;
    for (size_t i = 0; i < size_; ++i) {
        if (i == index) {
            data_[size_] = data_[i];
            data_[i] = value;
        }
        if (i > index) {
            tmp = data_[i];
            data_[i] = data_[size_];
            data_[size_] = tmp;
        }
    }
    ++size_;
};

template <typename T>
void MySequentialContainer<T>::erase(std::size_t index) {
    if (index >= size_) {
        throw std::logic_error("IndexError");        
    }
    for (size_t i = 0; i < size_; ++i) {
        if (i >= index) {
            data_[i] = data_[i+1];
        }
    }
    --size_;
};

template <typename T>
size_t MySequentialContainer<T>::size() {
    return size_;
};

template <typename T>
size_t MySequentialContainer<T>::capacity() {
    return capacity_;
};