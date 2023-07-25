#ifndef UTILS_H
#define UTILS_H

#include <string>

using namespace std;

void logString(const string& message);

void logLine(const string& message);

void getStringValue(string& message);

void getIntValue(int& value);

void sleepWithDots(string message, int numDots, int milliseconds);

#endif
