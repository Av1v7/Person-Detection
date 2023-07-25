#include <iostream>
#include "detectInfo.h"
#include "utils.h"

using namespace std;

int main() {
    // Please ensure that your data file is placed in the same directory as the program.
    vector<PersonDetails> data = readDataFromCSV("Details.csv");

    logString("Do you want to search for a victim by? (1: First and last name, 2: ID): ");
    int choice;
    getIntValue(choice);

    if (choice == 1) {
        searchByFirstNameAndLastName(data);
    }
    else if (choice == 2) {
        searchByID(data);
    }
    else {
        logLine("Invalid choice. Please enter 1 or 2.");
    }

    return 0;
}