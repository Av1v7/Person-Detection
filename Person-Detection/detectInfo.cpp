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

void downloadToFile(const string& firstName, const string& lastName, const vector<PersonDetails>& data) {
    string filename = firstName + "_" + lastName + ".txt";

    ofstream outFile(filename);
    if (!outFile) {
        logLine("Error creating file: " + filename);
        return;
    }

    outFile << firstName << " " << lastName << " Details:\n\n";

    for (const PersonDetails& person : data) {
        string lowerFirstName = toLowerCase(person.data.at("First Name"));
        string lowerLastName = toLowerCase(person.data.at("Last Name"));
        if (toLowerCase(firstName) == lowerFirstName && toLowerCase(lastName) == lowerLastName) {
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
}

void searchByFirstNameAndLastName(const vector<PersonDetails>& data) {
    string firstName, lastName, city;
    logString("Please enter the first name of this person: ");
    getStringValue(firstName);

    logString("Please enter " + firstName + "'s last name: ");
    getStringValue(lastName);

    logString("Please enter city (if you don't know city enter \"None\"): ");
    getline(cin, city);

    if (city.empty()) {
        city = "None";
    }

    int foundCount = 0;

    logLine("\nFetching results...");

    logLine("\n...");
    for (const PersonDetails& person : data) {
        string lowerFirstName = toLowerCase(person.data.at("First Name"));
        string lowerLastName = toLowerCase(person.data.at("Last Name"));
        string lowerCity = toLowerCase(person.data.at("City"));

        if (toLowerCase(firstName) == lowerFirstName && toLowerCase(lastName) == lowerLastName) {
            if (toLowerCase(city) == "none" || lowerCity == toLowerCase(city)) {
                foundCount++;
                for (const auto& header : person.headerOrder) {
                    logLine(header + ": " + person.data.at(header));
                }
                logLine("...\n");
            }
        }
    }
    logLine("\nFound `" + to_string(foundCount) + "` person" + (foundCount > 1 ? "(s)" : "") + " with this info.\n");

    logString("Do you want to download the information to a text file? (yes/no): ");
    string downloadChoice;
    getStringValue(downloadChoice);

    if (toLowerCase(downloadChoice) == "yes") {
        downloadToFile(toLowerCase(firstName), toLowerCase(lastName), data);
    }
}

void searchByID(const vector<PersonDetails>& data) {
    int targetID;
    logString("Please enter the ID of the person you want to search: ");
    getIntValue(targetID);

    int foundCount = 0;

    logLine("\nFetching results...");
    logLine("\n...");

    for (const PersonDetails& person : data) {
        int personID;
        stringstream(person.data.at("ID")) >> personID;

        if (personID == targetID) {
            foundCount++;
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
            downloadToFile(toLowerCase(firstName), toLowerCase(lastName), data);
        }
    }
    else {
        logLine("\nNo matching person found with ID " + to_string(targetID) + ".");
    }
}