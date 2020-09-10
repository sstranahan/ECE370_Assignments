//
// Created by sstranahan on 9/9/2020.
//

#include <string>
#include <iostream>

using namespace std;

#ifndef ASSIGNMENT_1_PEOPLE_H
#define ASSIGNMENT_1_PEOPLE_H

//////////////////////// Defines Person Struct ////////////////////////////////////
struct person {
    string Last_Name;
    string First_Name;
    int ID;
    string Address;
};
///////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
// Function:       Prints a person record
//
// Parameters:     Person to be printed
//
// Return Value:   Void
///////////////////////////////////////////////////////////////////////////////////
void printPerson(person person) {
    cout << person.Last_Name << ", " << person.First_Name << endl;
    cout << person.ID << endl;
    cout << person.Address << endl;
    return;
}

#endif //ASSIGNMENT_1_PEOPLE_H
