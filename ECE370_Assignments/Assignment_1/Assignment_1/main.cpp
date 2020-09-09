#include <iostream>
#include <fstream>

#include "people.h"

using namespace std;

void printAllRecords(person people[], int numRecords);
void swap(person *p1, person *p2);
void sortPplArr(person people[], int numRecs);
bool promptMoreToAdd();
void getRecordFromUser(person people[], int &numRecords);
bool promptToSearch();
person searchRecord(person people[], int numRecs, person foundPeople[], int &numFound);

int main() {
    int numRecords = 0;
    int numFound = 0;
    person people[20];
    person foundPeople[20];

    ifstream inFile("./a1.txt");

    int i = 0;

    if(inFile.is_open()) {
        while (!inFile.eof()) {

            string fullName;
            string idStr;
            getline(inFile, fullName);

            people[i].Last_Name = fullName.substr(0, fullName.find(","));
            people[i].First_Name = fullName.substr(fullName.find(",") + 2);

            inFile >> people[i].ID;

            inFile.ignore();

            getline(inFile, people[i].Address);

            inFile.ignore();
            i++;
            numRecords++;
        }
        inFile.close();
    }
    else cout << "Unable to open file.";

    sortPplArr(people, numRecords);
    printAllRecords(people, numRecords);

    bool moreToAdd;

    moreToAdd = promptMoreToAdd();
    cout << endl;

    while (moreToAdd) {
        getRecordFromUser(people, numRecords);
        moreToAdd = promptMoreToAdd();
        cout << endl;
    }

    bool toSearchFlag;

    toSearchFlag = promptToSearch();
    cout << endl;

    while (toSearchFlag) {
        searchRecord(people, numRecords, foundPeople, numFound);
        toSearchFlag = promptToSearch();
    }

    cout << "Printing list of searched and found people in order searched and found." << endl;
    cout << endl;

    for (int i = 0; i < numFound; i++) {
        printPerson(foundPeople[i]);
    }

    cout << endl;
    cout << "Thank you!" << endl;
    cout << endl;

    return 0;
}

void printAllRecords(person people[], int numRecords) {
    cout << "Printing List of Records:" << endl;
    cout << endl;

    for (int i = 0; i < numRecords; i++) {
        printPerson(people[i]);
        cout << endl;
    }
    return;
}

void swap(person *p1, person *p2){

    person temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    return;
}

void sortPplArr(person people[], int numRecs) {

    int i, j;
    for (i=0; i < numRecs - 1; i++) {
        for (j=0; j < numRecs - i  - 1; j++) {
            if(people[j].ID > people[j+1].ID)
                swap(&people[j], &people[j+1]);
        }
    }
    return;
}

bool promptMoreToAdd() {
    char response;
    cout << "Would you like to add another person to the list? (Y or N)" << endl;
    cin >> response;
    response = tolower(response);
    if (response == 'y')
        return true;
    else
        return false;
}

void getRecordFromUser(person people[], int &numRecords){
    int i = numRecords;
    string fullName = "";

    cin.ignore();       // Clear input buffer of newline

    cout << "Please enter last name, followed by comma and then space, followed by first name and return key." << endl;
    getline(cin, fullName);

    people[i].Last_Name = fullName.substr(0, fullName.find(","));
    people[i].First_Name = fullName.substr(fullName.find(",") + 2);
    cout << endl;

    cout << "Please enter ID#, followed by return key." << endl;
    cin >> people[i].ID;
    cout << endl;

    cin.ignore();       // Clear input buffer of newline

    cout << "Please enter full address, followed by return key." << endl;
    getline(cin, people[i].Address);
    cout << endl;

    numRecords++;

    return;
}

bool promptToSearch() {
    char response;
    cout << "Would you like to search for a person by last name? (Y or N)" << endl;
    cin >> response;
    response = tolower(response);
    if (response == 'y')
        return true;
    else
        return false;
}

// TODO: Fix up search function.

person searchRecord(person people[], int numRecs, person foundPeople[], int &numFound) {

    string response;

    cin.ignore();       // Clear input buffer

    cout << "Please enter the last name for which you would like to search followed by return key." << endl;
    getline(cin, response);
    cout << endl;

    for (int i = 0; i < response.length(); i++) {
        response[i] = tolower(response[i]);
    }

    for (int i = 0; i < numRecs; i++) {
        string lastName;
        for (int j = 0; j < people[i].Last_Name.length(); j++ ) {
            lastName[j] = tolower(people[i].Last_Name[j]);
        }
        if (lastName == response) {
            printPerson(people[i]);
            foundPeople[numFound] = people[i];
            numFound++;
        } else {
            cout << "No record found with that last name." << endl;
        }
    }
}