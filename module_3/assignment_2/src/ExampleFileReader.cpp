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

    // Skip column row
    getline(file,line);

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

// helper for sort function
int partition(std::vector<EmployeeRecord*>& arr, int low, int high) {
    int pivot = arr[high]->annualSalary;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        // if salary is higher than the pivot, move it to the front
        if (arr[j]->annualSalary > pivot) {
            i++;
            std::swap(arr[i], arr[j])
        }
    }

    // Put pivot in correct place
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick sort
void quickSort(std::vector<EmployeeRecord*>& arr, int low, int high) {
    if (low < high) {
        int partion_index = partition(arr, low, high);

        // Use recursion to sort elements before and after partition index
        quickSort(arr, low, partition_index -1);
        quickSort(arr, parition_index + 1, high);
    }
}

void sortAndDisplayEmployees(EmployeeSequence& empSeq) {
    // Create vector of EmployeeRecord pointers
    std::vector<EmployeeRecord*> pointerVector;

    // Add memory addresses from the Sequence to the vector
    for (int i = 0; i < empSeq.size(); i++) {
        pointerVector.push_back(&empSeq.get(i));
    }

    if (!pointerVector.empty()) {
        quickSort(pointerVector, 0, pointerVector.size() - 1);
    }

    cout << "\n EMPLOYEES BY SALARY (DESCENDING)" << endl;

    for (int i = 0; i < empSeq.size(); i++) {
        cout << pointerVector[i]->annualSalary << " | "
        << pointerVector[i]->eeid << " | "
        << pointerVector[i]->name << " | "
        << pointerVector[i]->jobTitle << " | "
        << pointerVector[i]->department << " | "
        << pointerVector[i]->gender << " | "
        << pointerVector[i]->age << " | "
        << pointerVector[i]->city << endl;
    }

}

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

