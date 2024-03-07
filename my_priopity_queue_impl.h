#pragma once

#include "my_priopity_queue.h"
#include <iostream>
template <typename T>
my_priopity_queue<T>::my_priopity_queue() : head(nullptr), tail(nullptr), size_(0) {}

template <typename T>
void my_priopity_queue<T>::push(const T& value) {
    if (head == nullptr) {
        head = new node<T>(value);
        tail = head;
    }
    else {
        node<T>* current = head;
        while (current != nullptr && current->value < value) {
            current = current->next;
        }
        if (current == nullptr) {
            tail->next = new node<T>(value, tail);
            tail = tail->next;
        }
        else {
            node<T>* toInsert = new node<T>(value, current->previous, current);
            if (current->previous != nullptr)
                current->previous->next = toInsert;
            current->previous = toInsert;
        }
    }
    size_++;
}



template <typename T>
my_priopity_queue<T>::my_priopity_queue(int n, const T& value) : my_priopity_queue()
{
    while (n--)
        push(value);
}


template <typename T>
my_priopity_queue<T>::my_priopity_queue(int n) : my_priopity_queue(n, T())
{ }

template <typename T>
my_priopity_queue<T>& my_priopity_queue<T>::operator=(my_priopity_queue<T> other) {
    swap(*this, other);
    return *this;
}
template <typename T>
my_priopity_queue<T>::my_priopity_queue(const my_priopity_queue<T>& other) : my_priopity_queue()
{
    if (!other.empty()) {
        node<T>* current = other.head;
        while (current != nullptr) {
            push(current->value);
            current = current->next;
        }
    }

}


template<typename T>
inline bool my_priopity_queue<T>::operator==(my_priopity_queue<T> const& other) const
{
    if (this->head == nullptr && other.head == nullptr)
        return true;
    if (this->head == nullptr || other.head == nullptr)
        return false;
    if (this->size_ != other.size_)
        return false;

    node<T>* current_this = this->head;
    node<T>* current_other = other.head;


    while (current_this != nullptr && current_other != nullptr) {
        if (current_this->value != current_other->value)
            return false;
        current_this = current_this->next;
        current_other = current_other->next;
    }
    return true;
}


template<typename T>
inline bool my_priopity_queue<T>::operator!=(my_priopity_queue<T> const& other) const
{
    return !(*this == other);
}

template<typename T>
inline void my_priopity_queue<T>::pop()
{
    // size > 0
    size_--;
    node<T>* temp = head;
    head = head->next;
    if (head != nullptr)
        head->previous = nullptr;
    delete temp;
    if (size_ == 0)
        tail = nullptr;
}
template <typename T>
void my_priopity_queue<T>::clear() {
    while (size_)
        pop();
}


template<typename T>
inline T& my_priopity_queue<T>::top() const
{
    // size > 0
    return head->value;
}

template<typename T>
inline bool my_priopity_queue<T>::empty() const
{
    return !size_;
}


template<typename T>
inline int my_priopity_queue<T>::size() const
{
    return size_;
}


template<typename T>
typename my_priopity_queue<T>::node<T>* my_priopity_queue<T>::find_node(const int index) const {
    // index < size
    node<T>* found_position;
    int counter;
    if (index < size_ / 2) {
        found_position = head;
        counter = 0;
        while (counter != index) {
            counter++;
            found_position = found_position->next;
        }
    }
    else {
        found_position = tail;
        counter = size_ - 1;
        while (counter != index) {
            counter--;
            found_position = found_position->previous;
        }
    }

    return found_position;
}


template<typename T>
inline int my_priopity_queue<T>::find_value(T value) {
    if (!empty()) {
        node<T>* current = head;
        for (int i = 0; current != nullptr; i++) {
            if (current->value == value)
                return i;
            current = current->next;
        }
        return -1;
    }
}

template<typename T>
inline void my_priopity_queue<T>::show_list() {
    using std::cout;
    node<T>* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << "\n";
}