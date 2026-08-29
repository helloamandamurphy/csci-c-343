//
//  PointerTest.cpp
//  
//
//  Created by Hettiarachchi, Suranga D on 8/21/18.
//

#include <iostream>
#include <string>
using namespace std;

class Employee{ //open record
  public:
    string lname;
    int id;
    long ssn;
};

 


void increment_all (int* start, int* stop)
{
    int * current = start;
    while (current != stop) {
        ++(*current);  // increment value pointed
        ++current;     // increment pointer
    }
}

void print_all (const int* start, const int* stop)
{
    const int * current = start;
    while (current != stop) {
        cout << *current << '\n';
        ++current;     // increment pointer
    }
}

void multiply_all(int numbers1[], int val, int size)
{
    int current = 0;
    while (current < size) {
        numbers1[current] *= val;  // increment value pointed
        ++current;     // increment pointer
    }
}

void outputEmployee(Employee& emp){
    cout<<"Employee information \n";
    cout<<emp.lname<<"  ";
    cout<<emp.id<<"  ";
    cout<<emp.ssn<<"\n";
}

void inputEmployee(Employee* emp){
    cout<<"enter employee last name, id, and ssn separated by spaces:";
    cin>>emp->lname>>emp->id>>emp->ssn;
}



int main ()
{
    int firstvalue = 5, secondvalue = 15;
    int *p1, *p2;
    
    p1 = &firstvalue;  // p1 = address of firstvalue
    p2 = &secondvalue; // p2 = address of secondvalue
    *p1 = 10;          // value pointed to by p1 = 10
    *p2 = *p1;         // value pointed to by p2 = value pointed to by p1
    p1 = p2;           // p1 = p2 (value of pointer is copied)
    *p1 = 20;          // value pointed to by p1 = 20
    
    cout << "firstvalue is " << firstvalue << '\n';
    cout << "secondvalue is " << secondvalue << '\n';
    
    
    int numbers[5];
    int * p;
    p = numbers;  *p = 10; //use pointer p to assign values to numbers array
    p++;  *p = 20;
    p = &numbers[2];  *p = 30;
    p = numbers + 3;  *p = 40;
    p = numbers;  *(p+4) = 50;

    cout << "\n what is in numbers array";
    for (int n=0; n<5; n++)
        cout << numbers[n] << ", ";
    cout << "\n";
    
    int numbers1[] = {10,20,30}; // initializer list for an array
    
    multiply_all(numbers1, 2, 3); //passing an array to a function
    print_all (numbers1,numbers1+3); //passing start address and end address of the array to a function
    
    cout << "\n";
    
    increment_all (numbers1,numbers1+3);
    print_all (numbers1,numbers1+3);
    
    //Dynamic memory allocation
    const int Size = 5;
    int *A = new int[Size]; // new requires a pointer variable on the left of = operator
    *(A+2) = 45; // dereference array pointer 
    cout << "\n";
    print_all (A,A+5); //passing start address and end address of the dynamic array to a function
    cout<<"value at index 2 is "<<A[2]<<endl;
    A = new int[2*Size]; // reassign a new array to pointer A 
    *(A+2) = 55;
    cout<<"value at index 2 is "<<A[2]<<endl;
    
    Employee emp1;
    cout<<"enter first employee last name, id, and ssn separated by spaces:";
    cin>>emp1.lname>>emp1.id>>emp1.ssn;
    Employee* emp2 = new Employee;
    
    cout<<"enter second employee last name, id, and ssn separated by spaces:";
    cin>>emp2->lname>>emp2->id>>emp2->ssn;
    outputEmployee(emp1);
    outputEmployee(*emp2);
    
    Employee* emp3 = new Employee; // dynamic object creation
    inputEmployee(emp3);
    outputEmployee(*emp3);

    inputEmployee(&emp1);
    return 0;
}
