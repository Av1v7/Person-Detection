#include "detectInfo.h"

using namespace std;

int main() {
    vector<PersonDetails> data = readDataFromCSV("Details.csv");
    searchPerson(data);

    return 0;
}