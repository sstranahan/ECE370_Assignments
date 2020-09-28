/* *******************************************************************************************
 * *******************************************************************************************
 *
 * ECE 370 Fall 2020
 * Assigned 9/28/2020
 * Due 10/12/2020
 * Programming Assignment 2
 *
 * Author: Stephen Stranahan
 *
 * *******************************************************************************************
 * *******************************************************************************************
 *
 * This program is to implement the conversion from infix expression to postfix expression,
 * and then evaluate the postfix. You will need to write two functions:
 * 1. INFIX_TO_POSTFIX -converts infix expression to postfix using stack and queue
 * 2. EVALUATE_POSTFIX -evaluates postfix expression using a stack
 *
 * You will also need PUSH, POP, and other procedures for the basic operations of stacks. You
 * must implement stack and queue, as defined in the textbook or a style of similar. You
 * cannot just make a function call to the standard stack or queue libraries. The stack and
 * queue functions must be in your own code.
 *
 * The infix expressions to be evaluated are follows. Your main program reads in an infix
 * expression, calls INFIX_TO_POSTFIX to convert it to postfix form, and then calls
 * EVALUATE_POSTFIX to evaluate it.
 *
 * For each infix expression, your program should print (1) the original infix expression, (2) its
 * postfix expression, and (3) the result of the evaluation (that is, the value of the expression).
 * Your program should check for end-of-file and stop when there are no more infix
 * expressions. After processing all the expressions, your program should print a final line that
 * is the sum of all the values.
 *
 * The only operators used in the infix expressions are multiplication (*), division (/), addition
 * (+), subtraction (-), and exponential (^). Standard C++ precedence rules are observed.
 * Parentheses are also used. As is customary, anything within parenthesis is evaluated before
 * anything else is evaluated. You may assume there will be no unary minus. All operands are
 * one-digit decimal numbers with no decimal point. The result of each calculation should be
 * float.
 *
 * You may use arrays to implement stacks and queues. You can assume the infix expression is
 * limited to 50 chars.
 *
 * The input data file name should be
 * "a2.txt"
 *
 * *******************************************************************************************
 *
 * Sample Test Data:
 * 8-3*2
 * 7+(4-6)*(8+6)/3
 * 4+1+(2-1)*8/4
 * 2^8
 * 0/1+4*5
 * 8*2+((4-3)*2)/2
 *
 * *******************************************************************************************
 * *******************************************************************************************
 */

#include <iostream>
#include <string>
#include <fstream>

#include "MyStack.cpp"
#include "MyQueue.cpp"

using namespace std;

template <typename T>
string INFIX_TO_POSTFIX(string infix, MyStack<T> stack, MyQueue<T> queue);

template <typename T>
string EVALUATE_POSTFIX(string infix, MyStack<T> stack, MyQueue<T> queue);

int main()
{
    MyStack<float> stack;
    MyQueue<float> queue;

    return 0;
}

template<typename T>
string INFIX_TO_POSTFIX(string infix, MyStack<T> stack, MyQueue<T> queue)
{
    return ;
}

template<typename T>
string EVALUATE_POSTFIX(string infix, MyStack<T> stack, MyQueue<T> queue)
{
    return ;
}
