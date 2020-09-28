//
// Created by Stephen Stranahan on 2020-09-28.
//

#include <iostream>
#include <stdlib.h>

#ifndef ECE370ASSIGNMENT2_MYSTACK_H
#define ECE370ASSIGNMENT2_MYSTACK_H

#endif //ECE370ASSIGNMENT2_MYSTACK_H

const int CAPACITY_DEFAULT = 50;


template <typename T> class MyStack {

public:
    MyStack (int capacity = CAPACITY_DEFAULT);

    void push(T);
    T pop();
    T peek();

    int getSize();
    bool isEmpty();
    bool isFull();

    ~MyStack(){
        delete[] arr;
    }

private:
    T *arr;
    int capacity;
    int top;
};