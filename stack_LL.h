#ifndef STACK_LL_H
#define STACK_LL_H

#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node *next;

    Node(T input)
    {
        data = input;
        next = nullptr;
    }
};

template <typename T>
class Stack_LL
{
public:
    Stack_LL() : top(nullptr) {}
    ~Stack_LL();
    void push(T data);
    void pop();
    T top_data();
    bool is_empty();
    void print_stack();

private:
    Node<T> *top;
};

template <typename T>
Stack_LL<T>::~Stack_LL()
{
    Node<T> *current, *next;

    current = top;

    while (current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void Stack_LL<T>::push(T data)
{
    Node<T> *ptr = new Node<T>(data);

    ptr->next = top;
    top = ptr;
}

template <typename T>
void Stack_LL<T>::pop()
{
    if (top == nullptr)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        Node<T> *temp = top;
        top = top->next;
        delete temp;
    }
}

template <typename T>
T Stack_LL<T>::top_data()
{
    if (top == nullptr)
    {
        cout << "Stack is empty" << endl;
        return T();
    }

    return top->data;
}

template <typename T>
bool Stack_LL<T>::is_empty()
{
    return top == nullptr;
}

template <typename T>
void Stack_LL<T>::print_stack()
{
    Node<T> *current = top;

    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

#endif // STACK_LL_H