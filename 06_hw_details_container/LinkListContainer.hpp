#pragma once
#include <iostream>
#include <utility>

template <typename T>
struct Node {
    Node(): next{nullptr}, prev{nullptr}{}

	Node(T data): next{nullptr}, prev{nullptr}, data{data}{}

	Node(const Node&) = delete;
	
    Node(Node&&) = default;
	
    Node& operator=(const Node&) = delete;
	
    Node& operator=(Node&&) = default;
	
    ~Node() = default;
    
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
        Node<T>* tmp = first_;
        while (tmp != nullptr) {
            Node<T>* next = tmp->next;
            delete tmp;
            tmp = next;
        }
    };

    MyLinkListContainer1(const MyLinkListContainer1& other)
        : size_(0)
        , first_(nullptr) {
            Node<T>* last = nullptr;
            for (Node<T>* tmp = other.first_; tmp != nullptr; tmp = tmp->next) {
                Node<T>* new_item = new Node(tmp->data);
                if(!first_) {
                    first_ = new_item;
                } else {
                    last->next = new_item;
                }
                last = new_item;
                ++size_;
            }
    }

    MyLinkListContainer1(MyLinkListContainer1&& other) noexcept {
        size_ = other.size_;
        first_ = other.first_;
        other.first_ = nullptr;
    }

    MyLinkListContainer1& operator=(const MyLinkListContainer1& other) {
        MyLinkListContainer1 temp{other};
        std::swap(this->first_, temp.first_);
        std::exchange(this->size_, temp.size_);
        return *this;
    }

    MyLinkListContainer1& operator=(MyLinkListContainer1&& other) {
        if (this == &other)
            return *this;
        Node<T>* tmp = first_;
        while (tmp != nullptr) {
            Node<T>* next = tmp->next;
            delete tmp;
            tmp = next;
        }
        std::swap(this->first_, other.first_);
        std::exchange(this->size_, other.size_);
        std::exchange(other.size_, 0);
        std::exchange(other.first_, nullptr);
        return *this;
    }

    void push_back(T value);

    void insert(std::size_t index, T value);

    void erase(std::size_t index);

    size_t size();

    T& operator[](std::size_t index);

    template <typename U> friend std::ostream& operator<<(std::ostream &os, const MyLinkListContainer1<U>& container);

private:
    size_t size_;
    Node<T>* first_;
};

template <typename T>
T& MyLinkListContainer1<T>::operator[](std::size_t index) {
    if (index >= size_) {
        throw std::logic_error("IndexError");
    }
    Node<T>* tmp = first_;
    for (size_t i = 0; i < index; ++i) {
        tmp = tmp->next;
    };
    return tmp->data;
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
    Node<T>* new_node = new Node<T>(value);
    if (first_ == nullptr) {
        first_ = new_node;
    } else {
        Node<T>* tmp = first_;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }
    ++size_;
};

template <typename T>
void MyLinkListContainer1<T>::insert(std::size_t index, T value) {
    if (index >= size_) {
        throw std::logic_error("IndexError");
    }
    Node<T>* new_node = new Node<T>(value);
    Node<T>* temp = first_;
    if (index == 0) {
        new_node->next = temp;
        first_ = new_node;
    } else {
        temp = temp->next;
        Node<T>* previous = first_;
        for (size_t i = 1; i < index; ++i) {              
            previous = previous->next;
            temp = temp->next;
        };
        previous->next = new_node;
        new_node->next = temp;
    };
    ++size_;
};

template <typename T>
void MyLinkListContainer1<T>::erase(std::size_t index) {
    if (index >= size_) {
        throw std::logic_error("IndexError");        
    }
    Node<T>* temp = first_;
    if (index == 0) {
        temp = first_->next;
        delete first_;
        first_ = temp;
    } else {
        temp = temp->next;
        Node<T>* previous = first_;
        for (size_t i = 1; i < index; ++i) {
            previous = previous->next;
            temp = temp->next;             
        };
        previous->next = temp->next;
        delete temp;
    }
    size_ -= 1;
};

template <typename T>
size_t MyLinkListContainer1<T>::size() {
    return size_;
};