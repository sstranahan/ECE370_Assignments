//
// Created by Stephen Stranahan on 2020-09-28.
//

#include "MyQueue.h"

template <typename T>
MyQueue<T>::MyQueue(int capacity)
{
    arr = new T[capacity];
    this->capacity = capacity;
    front = 0;
    back = -1;
    count;
}

template <typename T>
void MyQueue<T>::enqueue(T element)
{
    if (isFull())
    {
        std::cout << "Queue overflow.\nTerminating program.\n";
        exit(EXIT_FAILURE);
    }

    back = (back + 1) % capacity;
    arr[back] = element;
    count++;
}

template<typename T>
void MyQueue<T>::dequeue()
{
    if (isEmpty())
    {
        std::cout << "Queue underflow.\nTerminating prigram.\n";
        exit(EXIT_FAILURE);
    }
    front = (front + 1) % capacity;
    count--;

}

template<typename T>
T MyQueue<T>::peek()
{
    if (isEmpty())
    {
        std::cout << "Queue underflow.\nTerminating prigram.\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

template<typename T>
int MyQueue<T>::size()
{
    return count;
}

template<typename T>
bool MyQueue<T>::isEmpty()
{
    return count == 0;
}

template<typename T>
bool MyQueue<T>::isFull()
{
    return count == capacity;
}


