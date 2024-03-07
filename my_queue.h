#pragma once

#pragma once
template <typename T>
class my_queue {
public:
    my_queue();
    explicit my_queue(int n); // OK
    my_queue(int n, const T& value); // OK
    my_queue(const my_queue<T>& list); // OK
    my_queue<T>& operator=(my_queue<T> other); // OK

    bool operator==(my_queue<T> const& other) const; // OK
    bool operator!=(my_queue<T> const& other) const; // OK

    T& front() const; // OK
    T& back() const; // OK
    int size() const; // OK
    bool empty() const; // OK

    void push(const T& value); // OK

    void insert(int pos, const T& value); // OK
    void insert(int pos, int n, const T& value); // OK
    void insert(int pos, T* begin, T* end); // OK

    void pop(); // OK
    void clear(); // OK


    static void swap(my_queue<T>& list1, my_queue<T>& list2) // OK
    {
        using std::swap;
        swap(list1.size_, list2.size_);
        swap(list1.head, list2.head);
        swap(list1.tail, list2.tail);
    }

    template <typename T>
    class node {
    public:

        T value;
        node* previous;
        node* next;
        node() : value(T()), previous(nullptr), next(nullptr) {}
        node(T value, node* previous) : value(value), previous(previous), next(nullptr) {}
        node(T value, node* previous, node* next) : value(value), previous(previous), next(next) {}
        node(T value) : value(value), previous(nullptr), next(nullptr) {}
    };


    //1.	Напишіть метод, який буде шукати елемент із заданим ключем у однозв'язному списку.

    int find_value(T value); // OK


private:
    node<T>* head;
    node<T>* tail;
    int size_;

    node<T>* find_node(const int index) const; // OK
};




