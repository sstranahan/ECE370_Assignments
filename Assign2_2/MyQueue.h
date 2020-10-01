//
// Created by Stephen Stranahan on 2020-09-28.
//

#include <iostream>
#include <stdlib.h>

#ifndef ECE370ASSIGNMENT2_MYQUEUE_H
#define ECE370ASSIGNMENT2_MYQUEUE_H

const int DEFAULT_CAPACITY = 50;


//********************************************************************************************************************//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Class: MyQueue                                                                                                     //
//               FIFO Data Structure                                                                                  //
//                                                                                                                    //
// Data members:                                                                                                      //
//              arr :     Array of type (template type) T. Holds data in queue                                        //
//              capacity: Maximum capacity of queue - defaults to const DEFAULT_CAPACITY                              //
//              front:    Index pointing to front element of queue                                                    //
//              back:     Index pointing to back element of queue                                                     //
//              count:    Number of elements stored in queue                                                          //
//                                                                                                                    //
// Methods:                                                                                                           //
//              void enqueue(T): Adds element of type T to back of queue                                                        //
//              void dequeue():  Removes element from front of queue. (Does not return element)                       //
//              T peek():        Returns element at front of queue. Does not delete it.                               //
//              int size():      Returns number of elements stored in queue                                           //
//              bool isEmpty():  Returns true if queue is empty (no elements) ; false otherwise                       //
//              bool isFull():   Returns true if queue is full (numElements = capacity) ; false otherwise             //
//                                                                                                                    //
// Notes:                                                                                                             //
//              Template class implementation of queue using "circular" array. Enqueueing and dequeueing              //
//              elements just moves indices pointing to front and back elements.                                      //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//********************************************************************************************************************//

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

    void enqueue(T element);
    void dequeue();
    T peek();
    int size();
    bool isEmpty();
    bool isFull();
};


#endif //ECE370ASSIGNMENT2_MYQUEUE_H
