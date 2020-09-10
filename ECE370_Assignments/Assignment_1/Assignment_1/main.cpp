 /******************************************************************************************************
 * Stephen Stranahan - ECE 370 - Assignment #1
 * 09/09/20 -> 09/18/20
 * *****************************************************************************************************
 *
 * *****************************************************************************************************
 * Your program reads in from a text file a list of persons, display their information, add new persons,
 * and search for persons. The information of each person consists of:
 * Last_Name, First_Name (30 chars, max)
 * ID (int)
 * Address (50 chars, max)
 * Your program will open a file a1.txt and read one person’s info at a time, and you may assume the
 * entries in the file are all in correct forms.
 *
 * See file 370-F20-a1.pdf for full assignment description
 * *****************************************************************************************************
 *
 * *****************************************************************************************************
 * NOTE: Always flush cin buffer after reading in to variable using cin and before using getline()
 * ----- this clears the newline character left in the buffer
 * *****************************************************************************************************
 *
 * General Algorithm:
 *
 * 1. Open file, create array of person structs, read person records from file into array of structs
 * 2. (Bubble) Sort and then print all records
 * 3. Ask user whether to add record
 * 4. Take in data for user-input record
 * 5. Repeat 3 & 4 until user specifies done adding records
 * 6. Ask user whether to search by last name
 * 7. Read in last name to be searched for -> convert to lower
 * 8. Iterate through array of people, grab last name, convert to lower, compare to user-input search string
 * 9. If match, print that record, store in array of found records, increment number of found records
 * 10. Repeat 6-9 until user is done searching
 * 11. Print all found records
 * 12. Done!
 * *****************************************************************************************************
 * ****************************************************************************************************/

#include <iostream>
#include <fstream>
#include "people.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////// Function Prototypes ///////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

void printAllRecords(person people[], int numRecords);
void swap(person *p1, person *p2);
void sortPplArr(person people[], int numRecs);
bool promptMoreToAdd();
void getRecordFromUser(person people[], int &numRecords);
bool promptToSearch();
void searchRecord(person people[], int numRecs, person foundPeople[], int &numFound);
void printIntroHeader();

/////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    int numRecords = 0;
    int numFound = 0;
    person people[20];
    person foundPeople[20];

    printIntroHeader();

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

            inFile.ignore();        // Ignore empty line in file

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

    cout << endl;
    cout << "***********************************************************************" << endl;
    cout << "Printing list of searched and found people in order searched and found:" << endl;
    cout << "***********************************************************************" << endl;
    cout << endl;

    for (int i = 0; i < numFound; i++) {
        cout << endl;
        cout << "****************************  FOUND RECORD  ***************************" << endl;
        printPerson(foundPeople[i]);
        cout << "***********************************************************************" << endl;
        cout << endl;
    }

    cout << endl;
    cout << "***********************************************************************" << endl;
    cout << "*************************** Thank you! ********************************" << endl;
    cout << "***********************************************************************" << endl;
    cout << endl;

    return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// Function Definitions ///////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////
// Function:       Iterates through array of persons, printing each
//                 by calling print member function
//
// Parameters:     people[]:    Array of people to be printed
//                 numRecords:  Number of records to index loop
//
// Return Value:   Void
/////////////////////////////////////////////////////////////////////////////////////////////////
void printAllRecords(person people[], int numRecords) {
    cout << endl;
    cout << "***********************************************************************" << endl;
    cout << "********************** Printing List of Records: **********************" << endl;
    cout << "***********************************************************************" << endl;
    cout << endl;

    for (int i = 0; i < numRecords; i++) {
        printPerson(people[i]);
        cout << endl;
    }
    return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////
// Function:       Utility swap function to swap two people in array
//                 (used by bubble sort)
//
// Parameters:     p1:    person to be swapped
//                 p2:    person to be swapped
//
// Return Value:   Void
/////////////////////////////////////////////////////////////////////////////////////////////////
void swap(person *p1, person *p2){
    person temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////
// Function:       Bubble sort inplementation to sort array of people by ID number in
//                 ascending order - uses nested loops - standard bubble-sort
//
// Parameters:     people[]:    Array of people to be sorted
//                 numRecs:  Number of records to index loop
//
// Return Value:   Void
/////////////////////////////////////////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////////////////////////////////////////
// Function:       Function to prompt user to ask whether they would like to add a record
//                 to the array
//
// Parameters:     None
//
// Return Value:   Bool - whether or not they would like to add a record
/////////////////////////////////////////////////////////////////////////////////////////////////
bool promptMoreToAdd() {
    char response;
    cout << endl;
    cout << "***********************************************************************" << endl;
    cout << "****** Would you like to add another person to the list? (Y or N) *****" << endl;
    cout << "***********************************************************************" << endl;
    cout << endl;
    cin >> response;
    response = tolower(response);
    if (response == 'y')
        return true;
    else
        return false;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// Function:       Function to prompt user to enter a record, prompt and read in values for all
//                 data members of record
//
// Parameters:     people[]: array of people to add a record to
//                 &numRecords: Number of people in array, passed by reference to be incremented
//                 by this function when a record is added by user
//
// Return Value:   Void
/////////////////////////////////////////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////////////////////////////////////////
// Function:       Function to prompt user to ask whether they would like to search for
//                 a person by last name
//
// Parameters:     None
//
// Return Value:   Bool - whether or not they would like to search for a person
/////////////////////////////////////////////////////////////////////////////////////////////////
bool promptToSearch() {
    char response;
    cout << endl;
    cout << "***********************************************************************" << endl;
    cout << "***** Would you like to search for a person by last name? (Y or N) ****" << endl;
    cout << "***********************************************************************" << endl;
    cout << endl;
    cin >> response;
    response = tolower(response);
    if (response == 'y')
        return true;
    else
        return false;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// Function:       Function to iteratively search for a person by last name (case insensitive)
//                 Will keep track of number of records found, will add found records
//                 to an array to be printed later, will print record upon finding it
//
// Parameters:     people[]: array of people to search for record
//                 numRecs: number of records to index loop for iteration
//                 foundPeople[]: Array to add found records to
//                 &numFound: Counter to keep track of number of records searched & found
//
// Return Value:   Void
/////////////////////////////////////////////////////////////////////////////////////////////////
void searchRecord(person people[], int numRecs, person foundPeople[], int &numFound) {
    string response;
    bool nameFound = false;

    cin.ignore();       // Clear input buffer

    cout << "Please enter the last name for which you would like to search followed by return key." << endl;
    getline(cin, response);
    cout << endl;

    for (int i = 0; i < response.length(); i++) {
        response[i] = tolower(response[i]);
    }

    for (int i = 0; i < numRecs; i++) {
        string searchedLN = "";

        searchedLN = people[i].Last_Name;

        for (int j = 0; j < people[i].Last_Name.length(); j++ ) {
            searchedLN[j] = tolower(searchedLN[j]);
        }
        if (searchedLN == response) {
            printPerson(people[i]);
            foundPeople[numFound] = people[i];
            numFound++;
            nameFound = true;
        }
    }
    if (!nameFound)
        cout << "No record found with that last name." << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// Function:       Simply prints introductory header
//
// Parameters:     None
//
// Return Value:   Void
/////////////////////////////////////////////////////////////////////////////////////////////////
void printIntroHeader() {
    cout << endl;
    cout << "***********************************************************************" << endl;
    cout << "********** ECE 370 - Assignment #1 - Professor: Dongming Zhao *********" << endl;
    cout << "********** Author: Stephen Stranahan - Due Date: 09/18/2020 ***********" << endl;
    cout << "***********************************************************************" << endl;
    cout << endl;
}