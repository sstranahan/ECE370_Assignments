#include <iostream>
#include <fstream>

#include "people.h"

using namespace std;

int main() {
    person people[20];

    ifstream inFile("a1.txt");

    int i = 0;

    if(inFile.is_open()) {
        while (!inFile.eof()) {

            string fullName;
            getline(inFile, fullName);

            people[i].Last_Name = fullName.substr(0, fullName.find(","));
            people[i].First_Name = fullName.substr(fullName.find(","));

            getline(inFile, people[i].ID);


        }
    }
    else cout << "Unable to open file.";

    return 0;
}