#pragma once
#include <vector>
#include <string>
#include "date.h"
using namespace std;


class Student
//class which holds the key info about the student
{
public:
     Student(string n_name, string n_major, int n_id_number, Date n_birth_date, Date n_enroll_date);   //parameterized contructor
private:
     friend ostream& operator<<(ostream& os, const Student& s);    //overloaded ostream operator
     string name;
     string major;
     int id_number;
     Date birth_date;  
     Date enroll_date;  //enrollment date
};
//------------------------------------------------------------------------------------------------------

Student::Student(string n_name, string n_major, int n_id_number, Date n_birth_date, Date n_enroll_date){
  name=n_name;
  major=n_major;
  id_number=n_id_number;
  birth_date=n_birth_date;
  enroll_date=n_enroll_date;
}

//------------------------------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Student& s){
  os<<"Full name: "<<s.name<<'\n'
    <<"Birth date: "<<s.birth_date<<'\n'
    <<"Student ID: "<<s.id_number<<'\n'
    <<"Major: "<<s.major<<'\n'
    <<"Enrollment date: "<<s.enroll_date<<'\n';
    return os;
}




//************************************************************************************************




