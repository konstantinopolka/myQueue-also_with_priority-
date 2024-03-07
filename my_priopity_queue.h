#pragma once
template <typename T>
class my_priopity_queue {
public:
    my_priopity_queue();
    explicit my_priopity_queue(int n); // OK
    my_priopity_queue(int n, const T& value); // OK
    my_priopity_queue(const my_priopity_queue<T>& list); // OK
    my_priopity_queue<T>& operator=(my_priopity_queue<T> other); // OK

    bool operator==(my_priopity_queue<T> const& other) const; // OK
    bool operator!=(my_priopity_queue<T> const& other) const; // OK

    T& top() const; // OK
    int size() const; // OK
    bool empty() const; // OK

    void push(const T& value); // TO DO

    void pop(); // OK
    void clear(); // OK
    void show_list();


    static void swap(my_priopity_queue<T>& list1, my_priopity_queue<T>& list2) // OK
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




