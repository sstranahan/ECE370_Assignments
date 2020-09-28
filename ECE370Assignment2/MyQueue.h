//
// Created by Stephen Stranahan on 2020-09-28.
//

#include <iostream>
#include <stdlib.h>

#ifndef ECE370ASSIGNMENT2_MYQUEUE_H
#define ECE370ASSIGNMENT2_MYQUEUE_H

const int DEFAULT_CAPACITY = 50;

template <typename T>
class MyQueue
{
private:
    T * arr;
    int capacity;
    int front;
    int back;
    int count;
public:
    MyQueue (int capacity = DEFAULT_CAPACITY);
    ~MyQueue() {
        delete[] arr;
    }
    void dequeue();
    void enqueue(T element);
    T peek();
    int size();
    bool isEmpty();
    bool isFull();

};


#endif //ECE370ASSIGNMENT2_MYQUEUE_H
