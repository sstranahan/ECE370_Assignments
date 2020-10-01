//
// Created by Stephen Stranahan on 2020-09-28.
//

#include <iostream>
#include <stdlib.h>

#ifndef ECE370ASSIGNMENT2_MYSTACK_H
#define ECE370ASSIGNMENT2_MYSTACK_H

#endif //ECE370ASSIGNMENT2_MYSTACK_H

const int CAPACITY_DEFAULT = 50;


//********************************************************************************************************************//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Class: MyStack                                                                                                     //
//               LIFO Data Structure                                                                                  //
//                                                                                                                    //
// Data members:                                                                                                      //
//              arr :     Array of type (template type) T. Holds data in stack                                        //
//              capacity: Maximum capacity of stack - defaults to const DEFAULT_CAPACITY                              //
//              top:      Index pointing to top of stack                                                              //
//                                                                                                                    //
// Methods:                                                                                                           //
//              void push(T):    Adds element to top of stack                                                         //
//              T pop():         Returns element from top of stack. Deletes element.                                  //
//              T peek():        Returns element at top of stack. Does not delete it.                                 //
//              int getSize():   Returns number of elements stored in stack                                           //
//              bool isEmpty():  Returns true if stack is empty (no elements) ; false otherwise                       //
//              bool isFull():   Returns true if stack is full (numElements = capacity) ; false otherwise             //
//                                                                                                                    //
// Notes:                                                                                                             //
//              Template class implementation of stack. Index top points to top element of stack. Resizing just       //
//              involves moving that index.                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//********************************************************************************************************************//

template <typename T> class MyStack {

private:
    T *arr;
    int capacity;
    int top;

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
};