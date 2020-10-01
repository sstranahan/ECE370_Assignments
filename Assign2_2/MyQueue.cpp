// Implementation of MyQueue class
// Created by Stephen Stranahan on 2020-09-28.
//

#include "MyQueue.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:        Constructor                                                                                       //
// Notes:                                                                                                             //
// Parameters:      Capacity : Max capacity of queue - defaults to const DEFAULT_CAPACITY in MyQUEUE.h                //
// Return Value:                                                                                                      //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
MyQueue<T>::MyQueue(int capacity)
{
    arr = new T[capacity];
    this->capacity = capacity;
    front = 0;
    back = -1;
    count = 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:        enqueue                                                                                           //
// Notes:           Adds element to back of queue                                                                     //
// Parameters:      element: element of template type T to be added to queue                                          //
// Return Value:    Void                                                                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:        dequeue                                                                                           //
// Notes:           removes element from front of queue - does not return element                                     //
// Parameters:      None                                                                                              //
// Return Value:    Void                                                                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
void MyQueue<T>::dequeue()
{
    if (isEmpty())
    {
        std::cout << "Queue underflow.\nTerminating program.\n";
        exit(EXIT_FAILURE);
    }
    front = (front + 1) % capacity;
    count--;

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:        peek                                                                                              //
// Notes:                                                                                                             //
// Parameters:                                                                                                        //
// Return Value:                                                                                                      //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:                                                                                                          //
// Notes:                                                                                                             //
// Parameters:                                                                                                        //
// Return Value:                                                                                                      //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
int MyQueue<T>::size()
{
    return count;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:                                                                                                          //
// Notes:                                                                                                             //
// Parameters:                                                                                                        //
// Return Value:                                                                                                      //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
bool MyQueue<T>::isEmpty()
{
    return count == 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:                                                                                                          //
// Notes:                                                                                                             //
// Parameters:                                                                                                        //
// Return Value:                                                                                                      //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
bool MyQueue<T>::isFull()
{
    return count == capacity;
}


