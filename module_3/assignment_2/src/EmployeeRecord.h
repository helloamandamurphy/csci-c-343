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
      string name;
      string address;
      string state;
      int zip;
      
      EmployeeRecord () {}
      ~EmployeeRecord () {}

      void clear(void)
      {
         name="";
         address="" ;
         state="";
         zip=0;
      } // clear

      EmployeeRecord& operator = (EmployeeRecord& rhs)
      {
         name = rhs.name;
         address = rhs.address;
         state = rhs.state;
         zip = rhs.zip;

         return *this;
      } // operator =

      void transferFrom(EmployeeRecord& source)
      {
         name=source.name ;
         address=source.address ;
         state=source.state ;
         zip=source.zip ;
      } // transferFrom

      // overloading the output operator.The outputSequence function will make use
      // of this. Must be friend becuse EmployeeRecord is not primitive type.
    
      friend ostream& operator << (ostream &os, EmployeeRecord& r)
      {
         os << "(" << r.name << "," << r.address<< "," << r.state<< "," << r.zip << ")";
         return os;
      } // operator <<
};


