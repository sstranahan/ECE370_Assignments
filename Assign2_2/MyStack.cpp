// Implementation of MyStack class
// Created by Stephen Stranahan on 2020-09-28.
//

#include "MyStack.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:        Constructor                                                                                       //
// Notes:           None                                                                                              //
// Parameters:      capacity: Maximum size (num elements) of stack                                                    //
// Return Value:    Void                                                                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
MyStack<T>::MyStack(int capacity)
{
    arr = new T[capacity];
    this->capacity = capacity;
    top = -1;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:        Push                                                                                              //
// Notes:           Adds element to top of stack                                                                      //
// Parameters:      Element: element of type T (template) to be added to stack                                        //
// Return Value:    Void                                                                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:        pop                                                                                               //
// Notes:           Deletes element from top of stack, return deleted element                                         //
// Parameters:      None                                                                                              //
// Return Value:    Returns element of template type T popped from top of stack                                       //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:       peek                                                                                               //
// Notes:          returns element at top of stack                                                                    //
// Parameters:     None                                                                                               //
// Return Value:   element from top of stack                                                                          //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
T MyStack<T>::peek()
{
    if (!isEmpty())
        return arr[top];
    else {
        std::cout << "Cannot peek.\nStack is empty.\nTerminating program.\n";
        exit(EXIT_FAILURE);
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:                                                                                                          //
// Notes:                                                                                                             //
// Parameters:                                                                                                        //
// Return Value:                                                                                                      //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
int MyStack<T>::getSize()
{
    return top + 1;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:                                                                                                          //
// Notes:                                                                                                             //
// Parameters:                                                                                                        //
// Return Value:                                                                                                      //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool MyStack<T>::isEmpty()
{
    return top == -1;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:                                                                                                          //
// Notes:                                                                                                             //
// Parameters:                                                                                                        //
// Return Value:                                                                                                      //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool MyStack<T>::isFull()
{
    return top == capacity -1;
}