#ifndef MEMORY_H
#define MEMORY_H

#include <string>
#include <vector>
#include <map>

using namespace std;

struct PersonDetails {
    map<string, string> data;
    vector<string> headerOrder;
};

vector<PersonDetails> readDataFromCSV(const string& filename);

void searchPerson(const vector<PersonDetails>& data);

#endif