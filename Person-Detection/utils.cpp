#include "utils.h"
#include <iostream>
#include <sstream>

using namespace std;

void logString(const string& message) {
    cout << message;
}

void logLine(const string& message) {
    cout << message << endl;
}

void getStringValue(string& message) {
    getline(cin, message);
}

void getIntValue(int& value) {
    string input;
    getline(cin, input);
    stringstream ss(input);
    if (!(ss >> value)) {
        logLine("Invalid input. Please enter a valid integer.");
        value = 0;
    }
}
