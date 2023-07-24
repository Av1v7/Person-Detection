#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
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

void searchPerson(const vector<PersonDetails>& data) {
    string firstName, lastName, city;
    logString("Please enter the first name of this person: ");
    cin >> firstName;

    logString("Please enter " + firstName + "'s last name: ");
    cin >> lastName;

    logString("Please enter city (if you don't know city enter \"None\"): ");
    cin.ignore();
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
}