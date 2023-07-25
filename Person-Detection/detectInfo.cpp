#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include "detectInfo.h"
#include "utils.h"

using namespace std;

string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

vector<PersonDetails> readDataFromCSV(const string& filename) {
    vector<PersonDetails> data;
    ifstream file(filename);
    if (!file) {
        logString("Error opening file: " + filename);
        exit(1);
    }

    string line;
    getline(file, line);

    istringstream headerStream(line);
    string header;
    vector<string> headers;
    while (getline(headerStream, header, ',')) {
        headers.push_back(header);
    }

    while (getline(file, line)) {
        istringstream iss(line);
        PersonDetails person;

        for (const string& header : headers) {
            string value;
            if (getline(iss, value, ',')) {
                person.data[header] = value;
                person.headerOrder.push_back(header);
            }
        }

        data.push_back(person);
    }

    return data;
}

void downloadToFile(const string& firstName, const string& lastName, const vector<PersonDetails>& data, int foundCount, bool searchByID = false, int targetID = 0) {
    string filename;

    if (searchByID) {
        filename = "PersonID_" + to_string(targetID) + "-(" + to_string(foundCount) + ").txt";
    }
    else {
        filename = firstName + "_" + lastName + "-(" + to_string(foundCount) + ").txt";
    }

    ofstream outFile(filename);
    if (!outFile) {
        logLine("Error creating file: " + filename);
        return;
    }

    if (searchByID) {
        outFile << "Person ID: " << targetID << "\n\n";
    }
    else {
        outFile << firstName;
        if (toLowerCase(lastName) != "none") {
            outFile << " " << lastName;
        }
        outFile << " Details:\n\n";
    }

    for (const PersonDetails& person : data) {
        string lowerFirstName = toLowerCase(person.data.at("First Name"));
        string lowerLastName = toLowerCase(person.data.at("Last Name"));

        bool isMatchingFirstName = toLowerCase(firstName) == lowerFirstName;
        bool isMatchingLastName = toLowerCase(lastName) == lowerLastName || toLowerCase(lastName) == "none";

        if ((!searchByID && isMatchingFirstName && isMatchingLastName) ||
            (searchByID && stoi(person.data.at("Person_ID")) == targetID)) {
            for (const auto& header : person.headerOrder) {
                outFile << header << ": " << person.data.at(header) << "\n";
            }
            outFile << "\n";
        }
    }

    outFile << "\n© Credit to Av1v. All rights reserved.\n";

    outFile.close();

    string command = "move \"" + filename + "\" \"%HOMEPATH%\\Downloads\\" + filename + "\"";
    system(command.c_str());

    logLine("Details downloaded to \"" + filename + "\" in the \"Downloads\" folder.");

    string openCommand = "start \"\" \"%HOMEPATH%\\Downloads\\" + filename + "\"";
    system(openCommand.c_str());
}

void searchByFirstNameAndLastName(const vector<PersonDetails>& data) {
    string firstName, lastName, city;

    do {
        logString("Please enter the first name of this person: ");
        getStringValue(firstName);

        if (firstName.empty()) {
            logLine("First name cannot be empty. Please enter a valid first name.");
        }
    } while (firstName.empty());

    do {
        logString("Please enter " + firstName + "'s last name: ");
        getStringValue(lastName);

        if (lastName.empty()) {
            logLine("Last name cannot be empty. Please enter a valid last name.");
        }
    } while (lastName.empty());

    logString("Please enter city (if you don't know city enter \"None\"): ");
    getline(cin, city);

    if (city.empty()) {
        city = "None";
    }

    int foundCount = 0;

    #ifdef _WIN32
        system("cls");
    #endif

    sleepWithDots("Fetching results", 3, 700);

    for (const PersonDetails& person : data) {
        string lowerFirstName = toLowerCase(person.data.at("First Name"));
        string lowerLastName = toLowerCase(person.data.at("Last Name"));
        string lowerCity = toLowerCase(person.data.at("City"));

        bool isMatchingFirstName = toLowerCase(firstName) == lowerFirstName;
        bool isMatchingLastName = toLowerCase(lastName) == lowerLastName;
        bool isMatchingCity = toLowerCase(city) == "none" || lowerCity == toLowerCase(city);

        if (isMatchingFirstName && isMatchingLastName) {
            if (isMatchingCity) {
                foundCount++;
                logLine("\n...");
                for (const auto& header : person.headerOrder) {
                    logLine(header + ": " + person.data.at(header));
                }
                logLine("...\n");
            }
        }
    }
    logLine("\nFound `" + to_string(foundCount) + "` person" + (foundCount > 1 ? "(s)" : "") + " with this info.\n");

    if (foundCount == 0) {
        return logLine("Failed to fetch any matching person with the provided information.");
    }

    logString("Do you want to download the information to a text file? (yes/no): ");
    string downloadChoice;
    getStringValue(downloadChoice);

    if (toLowerCase(downloadChoice) == "yes") {
        downloadToFile(toLowerCase(firstName), toLowerCase(lastName), data, foundCount);
    }
}

void searchByID(const vector<PersonDetails>& data) {
    int targetID;
    logString("Please enter the ID of the person you want to search: ");
    getIntValue(targetID);

    int foundCount = 0;

    #ifdef _WIN32
        system("cls");
    #endif

    sleepWithDots("Fetching results", 3, 700);

    for (const PersonDetails& person : data) {
        int personID;
        stringstream(person.data.at("Person_ID")) >> personID;

        if (personID == targetID) {
            foundCount++;
            logLine("\n...");
            for (const auto& header : person.headerOrder) {
                logLine(header + ": " + person.data.at(header));
            }
            logLine("...\n");

            logLine("Successfully found " + person.data.at("First Name") + " " + person.data.at("Last Name") + " details by ID " + to_string(targetID) + ".\n");
        }
    }

    if (foundCount > 0) {
        logString("Do you want to download the information to a text file? (yes/no): ");
        string downloadChoice;
        getStringValue(downloadChoice);

        if (toLowerCase(downloadChoice) == "yes") {
            string firstName = data[targetID - 1].data.at("First Name");
            string lastName = data[targetID - 1].data.at("Last Name");
            downloadToFile(toLowerCase(firstName), toLowerCase(lastName), data, foundCount, true, targetID);
        }
    }
    else {
        logLine("\nNo matching person found with ID " + to_string(targetID) + ".");
    }
}