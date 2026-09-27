# Assignment Details
In this assignment, you will read a text file, create OpenRecords, and then sort the data that are stored in a Sequence.

C++ OpenRecords are public data structures to store pieces of information as a complete record. In this assignment, you will be using Employee data in the EmployeeData.txt file. 

The following example shows how to create an Open Record and read the data file to store Employee records in a Sequence. Of course, you have to modify this example so that you can store all the following fields in the Employee Record.

These are the fields and data types of the Employee Record that you need to work with.
```text
EEID    - string
Full Name     - string
Job Title     - string
Department     - string
Gender     - string
Age    -int
Annual Salary    -string (must convert to an int)
City  - string
```

While you are storing the records in the Sequence of Employee Records you should also create and store a pointer to that record in a C++ vector, you should sort the data in descending (the arrangement of items from highest to lowest) order of employee salary using the quick sort algorithm. It makes it easier to move pointers during sorting when we store the Employee records in the Sequence rather than the whole record itself.

Once all the records are sorted in descending order, you should output all the Employee records in that order.

Turn in your programs, a screenshot of the first 100 records. 

## Requirements
- Read text file (assignment specifies the .txt file which will be a challenge given the spaces are inconsistent between columns and salary has quotations that wrap it)
- Create OpenRecords from the data
- Sort the data stored in a Sequence
- Create and store a pointer to that record in a C++ vector
- Sort data in descending salary using quick sort algorithm
- Output the records in that order
- Screenshot first 100 records

## Planned Steps
1. Review EmployeeRecord.h and update to support all 8 fields required
2. Create custom Sequence.hpp file
3. Create main.cpp file