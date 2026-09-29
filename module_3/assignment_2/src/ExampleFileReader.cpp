// author Dr.H on 10/25/2019
// compiled with g++ -std=c++1z driver.cpp
// This code read EmployeeRecords from a text file into a Sequence, then output the data.

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "Sequence.hpp"
#include "EmployeeRecord.h"

using namespace std;

typedef Sequence<EmployeeRecord> EmployeeSequence;

int convertSalaryStringToInt(string salaryString) {
    // Only return digits (no $ or , )
    cout << "Input: " << salaryString << endl;

    salaryString.erase(remove_if(salaryString.begin(), salaryString.end(), [](unsigned char c) {
        return !std::isdigit(c);
    }), salaryString.end());

    int output = stoi(salaryString);
    cout << "Output: " << output << endl;
    return output;
}

void doInputPersonDataFromFile(EmployeeSequence& personData)
{
    EmployeeRecord r;
    string filename = string(PROJECT_SOURCE_DIR) + "/data/EmployeeData.txt";

    // Open the filestream
    std::ifstream file(filename);

    // Check if it opened successfully
    if (!file.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
        exit(1); // terminate with error
    }

    string line;

    // Read file line by line
    while (getline(file, line)) {
        // Make line a string stream
        char tab = '\t';
        stringstream ss(line);
        getline(ss, r.eeid, tab);
        getline(ss, r.name, tab);
        getline(ss, r.jobTitle, tab);
        getline(ss, r.department, tab);
        getline(ss, r.gender, tab);

        // Handle age string -> int conversion
        string ageString;
        getline(ss, ageString, tab);
        r.age = std::stoi(ageString);

        // Handle salary string -> int conversion
        string salaryString;
        getline(ss, salaryString, tab);
        r.annualSalary = convertSalaryStringToInt(salaryString);

        getline(ss, r.city, tab);


        personData.add(r,0);
    }

    file.close();

    cout << "Number of Records :"<< personData.size();

 } // doInputPersonDataFromFile>
 


int main(int argc, char* argv[])
{

    EmployeeSequence eSequence;

    cout << "Reading EmployeeRecords from file" << endl;
    doInputPersonDataFromFile(eSequence);
    cout << "\nCompleted Reading, File contains following Employee Records" << endl;
    eSequence.outputSequence();
    cout<< endl;

    return 0;
}

