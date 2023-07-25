#include <iostream>
#include <sstream>
#include <thread>
#include "utils.h"

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

void sleepWithDots(string message,int numDots, int milliseconds) {
    logString(message);
    for (int i = 0; i < numDots; ++i) {
        this_thread::sleep_for(chrono::milliseconds(milliseconds));
        logString(".");
    }
    logLine("");
}
