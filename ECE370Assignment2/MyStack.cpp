//
// Created by Stephen Stranahan on 2020-09-28.
//

#include "MyStack.h"

template <typename T>
MyStack<T>::MyStack(int capacity)
{
    arr = new T[capacity];
    this->capacity = capacity;
    top = -1;
}

template <typename T>
void MyStack<T>::push(T element)
{
    if (isFull())
    {
        std::cout << "Stack overflow.\nTerminating program.\n";
        exit(EXIT_FAILURE);
    }

    arr[++top] = element;
}

template <typename T>
T MyStack<T>::pop()
{
    if (isEmpty())
    {
        std::cout << "Stack underflow.\nTerminating program.\n";
        exit(EXIT_FAILURE);
    }

    return arr[top--];
}

template <typename T>
T MyStack<T>::peek()
{
    if (!isEmpty())
        return arr[top];
    else
        std::cout << "Cannot peek.\nStack is empty.\nTerminating program.\n";
}

template <typename T>
int MyStack<T>::getSize()
{
    return top + 1;
}

template <typename T>
bool MyStack<T>::isEmpty()
{
    return top == -1;
}

template <typename T>
bool MyStack<T>::isFull()
{
    return top == capacity -1;
}