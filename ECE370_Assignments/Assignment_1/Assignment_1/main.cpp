#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct person {
    char Last_Name[30];
    char First_Name[30];
    int ID;
    char Address[50];
};

int main() {
    person people[20];

    ifstream inFile("a1.txt");

    int i = 0;

    if(inFile.is_open()) {
        while (!inFile.eof()) {

            

        }
    }
    else cout << "Unable to open file.";



    return 0;
}