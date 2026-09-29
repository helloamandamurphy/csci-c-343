// This program shows an example of Open Record, all content are public!
// compiled with g++ -std=c++1z EmployeeRecord.h
// OpenRecord to store Employee Records. 

#pragma once
#include<string>
#include<iostream>
using namespace std;


//
// Create EmployeeRecord
//
class EmployeeRecord {
   public:
      string eeid;
      string name;
      string jobTitle;
      string department;
      string gender;
      int age;
      int annualSalary; // must convert to an int
      string city;
      // Not used for this assignment
      // string address;
      // string state;
      // int zip;

   // Constructor
      EmployeeRecord () {
         clear(); // create an instance with empty values
      }

   // Deconstructor
      ~EmployeeRecord () {}

   // Clear function (sets all fields to empty values)
      void clear(void)
      {
         eeid="";
         name="";
         jobTitle="";
         department="";
         gender="";
         age=0;
         annualSalary=0;
         city="";
         // Not used for this assignment
         // address="" ;
         // state="";
         // zip=0;
      } // clear

      EmployeeRecord& operator = (EmployeeRecord& rhs)
      {
         eeid=rhs.eeid;
         name = rhs.name;
         jobTitle=rhs.jobTitle;
         department=rhs.department;
         gender=rhs.gender;
         age=rhs.age;
         annualSalary=rhs.annualSalary;
         city=rhs.city;

         // Not used for this assignment
         // address = rhs.address;
         // state = rhs.state;
         // zip = rhs.zip;

         return *this;
      } // operator =

      void transferFrom(EmployeeRecord& source)
      {
         eeid=source.eeid;
         name=source.name;
         jobTitle=source.jobTitle;
         department=source.department;
         gender=source.gender;
         age=source.age;
         annualSalary=source.annualSalary;
         city=source.city;

         // Not used for this assignment
         // address=source.address ;
         // state=source.state ;
         // zip=source.zip ;
      } // transferFrom

      // overloading the output operator.The outputSequence function will make use
      // of this. Must be friend because EmployeeRecord is not primitive type.
      friend ostream& operator << (ostream &os, EmployeeRecord& r)
      {
         os << "(" << r.eeid << "," << r.name << "," << r.jobTitle << "," << r.department << "," << r.gender << "," << r.age << "," << r.annualSalary << "," << r.city << ")";
         return os;
      } // operator <<
};


