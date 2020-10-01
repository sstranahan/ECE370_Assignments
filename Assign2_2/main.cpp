/* *********************************************************************************************************************
 * *********************************************************************************************************************
 *
 *  ECE 370 Fall 2020
 *  Assigned 9/28/2020
 *  Due 10/12/2020
 *  Programming Assignment 2
 *
 *  Author: Stephen Stranahan
 *
 * *********************************************************************************************************************
 * *********************************************************************************************************************
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
 * *********************************************************************************************************************
 * *********************************************************************************************************************
 *
 * Sample Test Data:
 * 8-3*2
 * 7+(4-6)*(8+6)/3
 * 4+1+(2-1)*8/4
 * 2^8
 * 0/1+4*5
 * 8*2+((4-3)*2)/2
 *
 * *********************************************************************************************************************
 * *********************************************************************************************************************
 */

//  TODO: Function documentation, running comments

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

#include "MyStack.cpp"
#include "MyQueue.cpp"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// Function Prototypes ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

string INFIX_TO_POSTFIX(string infix);

float EVALUATE_POSTFIX(string postfix);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////// Main Program ///////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    ifstream inFile;

    inFile.open("./a2.txt");

    if (!inFile.is_open()){
        cout << "Error. Failed to open file.\nTerminating program.\n";
        exit(EXIT_FAILURE);
    }

    string fileInput = "";
    float result = 0.0;
    float sum = 0.0;
    string postfixExp;

    while (!inFile.eof()) {         // Main loop - will read expressions (lines) from file and evaluate them until reaching EOF
        getline(inFile, fileInput);

        if (fileInput.empty())
            break;

        cout << "Expression read from file: " << fileInput << "\n";

        postfixExp = INFIX_TO_POSTFIX(fileInput);

        cout << "Translated postfix expression: " << postfixExp << "\n";

        result = EVALUATE_POSTFIX(postfixExp);

        cout << "Evaluation: " << result << "\n";

        sum += result;
    }

    cout << "Sum of all evaluated expressions: " << sum << "\n";

    inFile.close();

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////// Function Definitions ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:                                                                                                          //
// Notes:                                                                                                             //
// Parameters:                                                                                                        //
// Return Value:                                                                                                      //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string INFIX_TO_POSTFIX(string infix)
{
    int precedenceNext = 0;
    int precedenceTop = 0;

    MyStack<char> stack;
    MyQueue<char> queue;

    string result;

    for (int i = 0; i < infix.length(); i++) {
        switch (infix[i]) {
            case '(' :
                stack.push(infix[i]);
                break;
            case ')' :
                while (stack.peek() != '(') {
                    if (stack.isEmpty()){
                        cout << "Error. Translation failed.\nTerminating program.\n";
                        exit(EXIT_FAILURE);
                    }
                    queue.enqueue(stack.pop());
                }
                stack.pop();
                break;
            default :
                if (isdigit(infix[i])) {
                    queue.enqueue(infix[i]);
                    break;
                }
                else if (infix[i] == '-' || infix[i] == '+' || infix[i] == '/' || infix[i] == '*' || infix[i] == '^') {
                    switch (infix[i]){
                        case '+' :
                            precedenceNext = 1;
                            break;
                        case '-' :
                            precedenceNext = 1;
                            break;
                        case '*' :
                            precedenceNext = 2;
                            break;
                        case '/' :
                            precedenceNext = 2;
                            break;
                        case '^' :
                            precedenceNext = 3;
                            break;
                        default:
                            cout << "Error. Translation failed.\nTerminating program.\n";
                            exit(EXIT_FAILURE);
                    }
                    if (!stack.isEmpty()) {
                        char top = stack.peek();
                        switch (top){
                            case '(' :
                                precedenceTop = 0;
                                break;
                            case ')' :
                                precedenceTop = 0;
                                break;
                            case '+' :
                                precedenceTop = 1;
                                break;
                            case '-' :
                                precedenceTop = 1;
                                break;
                            case '*' :
                                precedenceTop = 2;
                                break;
                            case '/' :
                                precedenceTop = 2;
                                break;
                            case '^' :
                                break;
                                precedenceTop = 3;
                            default:
                                cout << "Error. Translation failed.\nTerminating program.\n";
                                exit(EXIT_FAILURE);
                        }
                    }
                    while (precedenceTop >= precedenceNext && !stack.isEmpty()) {
                        queue.enqueue(stack.pop());
                        if (!stack.isEmpty()) {
                            char top = stack.peek();
                            switch (top){
                                case '(' :
                                    precedenceTop = 0;
                                    break;
                                case ')' :
                                    precedenceTop = 0;
                                    break;
                                case '+' :
                                    precedenceTop = 1;
                                    break;
                                case '-' :
                                    precedenceTop = 1;
                                    break;
                                case '*' :
                                    precedenceTop = 2;
                                    break;
                                case '/' :
                                    precedenceTop = 2;
                                    break;
                                case '^' :
                                    break;
                                    precedenceTop = 3;
                                default:
                                    cout << "Error. Translation failed.\nTerminating program.\n";
                                    exit(EXIT_FAILURE);
                            }
                        }
                    }
                    stack.push(infix[i]);
                }
                else {
                    cout << "Error. Invalid character read from file.\nTerminating program.\n";
                    exit(EXIT_FAILURE);
                }
        }
    }

    while (!stack.isEmpty()) {
        queue.enqueue(stack.pop());
    }

    while (!queue.isEmpty()) {
        for (int i = 0; i < queue.size(); i++){
            result += queue.peek();
            queue.dequeue();
        }
    }
    return result;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:                                                                                                          //
// Notes:                                                                                                             //
// Parameters:                                                                                                        //
// Return Value:                                                                                                      //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float EVALUATE_POSTFIX(string postfix)
{
    float result = 0.0;
    MyStack<float> stack;
    MyQueue<char> queue;

    for (int i = 0; i < postfix.length(); i++)      // Load queue with postfix expression from string argument
        queue.enqueue(postfix[i]);

    while (!queue.isEmpty()) {
        if (isdigit(queue.peek())) {
            stack.push((float)(queue.peek() - '0'));
            queue.dequeue();
        } else if(queue.peek() == '+' || queue.peek() == '-' || queue.peek() == '*' || queue.peek() == '/' || queue.peek() == '^') {
            float v1, v2, res;
            int exp = 0;
            int base = 0;
            char oper = queue.peek();
            queue.dequeue();
            v2 = stack.pop();
            v1 = stack.pop();
            switch(oper) {
                case '+' :
                    res = v1 + v2;
                    break;
                case '-':
                    res = v1 - v2;
                    break;
                case '*':
                    res = v1 * v2;
                    break;
                case '/':
                    res = v1 / v2;
                    break;
                case '^' :
                    exp = (int)(v2);
                    base = (int)(v1);
                    for (int i = 0; i < exp - 1 ; i++)
                        v1 *= base;
                    res = v1;
                    break;
                default:
                    cout << "Error. Evaluation failed.\nTerminating program.\n";
                    exit(EXIT_FAILURE);
            }
            stack.push(res);

        } else {
            cout << "Error. Evaluation failed.\nTerminating program.\n";
            exit(EXIT_FAILURE);
        }
    }

    result = stack.pop();

    if (!stack.isEmpty()) {
        cout << "Error. Evaluation failed.\nTerminating program.\n";
        exit(EXIT_FAILURE);
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////// Thank You!! ///////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
