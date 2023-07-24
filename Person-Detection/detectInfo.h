#ifndef DETECT_INFO_H
#define DETECT_INFO_H

#include <string>
#include <vector>
#include <map>

using namespace std;

struct PersonDetails {
    map<string, string> data;
    vector<string> headerOrder;
};

vector<PersonDetails> readDataFromCSV(const string& filename);

void searchByID(const vector<PersonDetails>& data);

void searchByFirstNameAndLastName(const vector<PersonDetails>& data);

#endif
