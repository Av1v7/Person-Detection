#include "utils.h"
#include <iostream>

using namespace std;

void logString(const string& message) {
    cout << message;
}

void logLine(const string& message) {
    cout << message << endl;
}

void getStringValue(string& message) {
    cin >> message;
}