#pragma once
#include <iostream>

template <typename T>
struct Node {
    Node() {
      next = nullptr;
      prev = nullptr;
    }

    Node* next;
    Node* prev;
    T data;
};

template <typename T>
class MyLinkListContainer1 {
public:
    MyLinkListContainer1()
        : size_{0}
        , first_{nullptr} {}
    ~MyLinkListContainer1() {
        if (first_ == nullptr) {
            return;
        }
        Node<T>* tmp = first_;
        while (tmp != nullptr) {
            Node<T>* next = tmp->next;
            delete tmp;
            tmp = next;
        }
    };

    void push_back(T value);
    void insert(std::size_t index, T value);
    void erase(std::size_t index);
    size_t size();

    T operator[](std::size_t index);
    template <typename U> friend std::ostream& operator<<(std::ostream &os, const MyLinkListContainer1<U>& container);

private:
    size_t size_;
    Node<T>* first_;
};

template <typename T>
T MyLinkListContainer1<T>::operator[](std::size_t index) {
    if (index >= size_) {
        throw std::logic_error("IndexError");
    }
    Node<T>* tmp = first_;
    for (size_t i = 0; i < size_; ++i) {
        if (i == index)
            return tmp->data;
        tmp = tmp->next;
    };
    throw std::logic_error("IndexError");
};

template <typename T>
std::ostream& operator<<(std::ostream &os, const MyLinkListContainer1<T> & container) {
    Node<T>* tmp = container.first_;
    while (tmp != nullptr)
    {
        os << tmp->data;
        if (tmp->next != nullptr) {
            os << " -> ";
        }
        tmp = tmp->next;
    }
    return os;
};

template <typename T>
void MyLinkListContainer1<T>::push_back(T value) {
    Node<T>* new_node = new Node<T>();
    new_node->data = value;
    new_node->next = nullptr;
    if (first_ == nullptr) {
        first_ = new_node;
    } else {
        Node<T>* tmp = first_;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }
    size_ += 1;
};

template <typename T>
void MyLinkListContainer1<T>::insert(std::size_t index, T value) {
    if (index >= size_) {
        throw std::logic_error("IndexError");
    }
    Node<T>* new_node = new Node<T>();
    new_node->data = value;
    Node<T>* tmp = first_;
    if (index == 0) {
        new_node->next = tmp;
        first_ = new_node;
    } else {
        tmp = tmp->next;
        Node<T>* prev = first_;
        for (size_t i = 1; i < size_; ++i) {
            if (i == index) {
                prev->next = new_node;
                new_node->next = tmp;
                break;
            }                
            prev = prev->next;
            tmp = tmp->next;
        };
    };
    size_ += 1;
};

template <typename T>
void MyLinkListContainer1<T>::erase(std::size_t index) {
    if (index >= size_) {
        throw std::logic_error("IndexError");        
    }
    Node<T>* tmp = first_;
    if (index == 0) {
        tmp = first_->next;
        delete [] first_;
        first_ = tmp;
    } else {
        tmp = tmp->next;
        Node<T>* prev = first_;
        for (size_t i = 1; i < size_; ++i) {
            if (i == index) {
                prev->next = tmp->next;
                delete [] tmp;
                break;
            }                
            prev = prev->next;
            tmp = tmp->next;
        };
    }
    size_ -= 1;
};

template <typename T>
size_t MyLinkListContainer1<T>::size() {
    return size_;
};