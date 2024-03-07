#pragma once

#include "my_queue.h"
#include <iostream>
template <typename T>
my_queue<T>::my_queue() : head(nullptr), tail(nullptr), size_(0) {}

template <typename T>
void my_queue<T>::push(const T& value) {
    if (head == nullptr) {
        head = new node<T>(value);
        tail = head;
    }
    else {
        tail->next = new node<T>(value, tail);
        tail = tail->next;
    }
    size_++;
}


template <typename T>
my_queue<T>::my_queue(int n, const T& value) : my_queue()
{
    while (n--)
        push(value);
}


template <typename T>
my_queue<T>::my_queue(int n) : my_queue(n, T())
{ }

template <typename T>
my_queue<T>& my_queue<T>::operator=(my_queue<T> other) {
    swap(*this, other);
    return *this;
}
template <typename T>
my_queue<T>::my_queue(const my_queue<T>& other) : my_queue()
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
inline bool my_queue<T>::operator==(my_queue<T> const& other) const
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
inline bool my_queue<T>::operator!=(my_queue<T> const& other) const
{
    return !(*this == other);
}

template<typename T>
inline void my_queue<T>::pop()
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
void my_queue<T>::clear() {
    while (size_)
        pop();
}


template<typename T>
inline T& my_queue<T>::front() const
{
    // size > 0
    return head->value;
}

template<typename T>
inline T& my_queue<T>::back() const
{
    // size > 0
    return tail->value;
}

template<typename T>
inline bool my_queue<T>::empty() const
{
    return !size_;
}


template<typename T>
inline int my_queue<T>::size() const
{
    return size_;
}


template<typename T>
inline void my_queue<T>::insert(int pos, const T& value) {
    insert(pos, 1, value);
}
template<typename T>
inline void my_queue<T>::insert(int pos, int n, const T& value) {
    if (empty()) {
        while (n--)
            push(value);
        return;
    }
    size_ += n;
    node<T>* found_position = find_node(pos);

    while (n--) {
        found_position->previous = new node<T>(value, found_position->previous, found_position);
        found_position = found_position->previous;
        if (found_position->previous != nullptr)
            found_position->previous->next = found_position;
    }
    if (pos == 0)
        head = found_position;

}
template<typename T>
inline void my_queue<T>::insert(int pos, T* begin, T* end) {
    if (empty()) {
        while (begin != end)
            push(*(begin++));
        return;
    }

    node<T>* found_position = find_node(pos);

    size_ += end - begin;

    while (begin != end) {
        found_position->previous = new node<T>(*begin, found_position->previous, found_position);
        found_position = found_position->previous;
        if (found_position->previous != nullptr)
            found_position->previous->next = found_position;
        begin++;
    }
    if (pos == 0)
        head = found_position;

}

template<typename T>
typename my_queue<T>::node<T>* my_queue<T>::find_node(const int index) const {
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
inline int my_queue<T>::find_value(T value) {
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

