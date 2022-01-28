#pragma once
#include <vector>
#include <string>
#include "date.h"
#include "helper_functions.h"
using namespace std;


struct Student
//class which holds the key info about the student
{
public:
     Student(int n_id_number,string n_name, string n_major, Date n_birth_date, Date n_enroll_date);   //parameterized contructor
     void symbolic_print(std::ostream& os);
     int get_id() const;    //function to return Student's id number
     string get_name() const;  //function to return Student's full name 
     friend ostream& operator<<(ostream& os, const Student& s);    //overloaded ostream operator
     void edit_name(string new_name){name=new_name;}
     void edit_major(string new_major) {major=new_major;}
     void edit_birth_date(Date new_date) {birth_date=new_date;}
     void edit_enroll_date(Date new_date) {enroll_date=new_date;}
private:
     string name;
     string major;
     int id_number;
     Date birth_date;  
     Date enroll_date;  //enrollment date
};
//------------------------------------------------------------------------------------------------------

//parametirized constructor
Student::Student(int n_id_number,string n_name, string n_major, Date n_birth_date, Date n_enroll_date){
  id_number=n_id_number;
  name=n_name;
  major=n_major;
  birth_date=n_birth_date;
  enroll_date=n_enroll_date;
}

//------------------------------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Student& s){
  os<<"Student_ID: "<<s.id_number<<'\n'
    <<"Full_name: " <<s.name<<'\n'
    <<"Birth_date: " <<s.birth_date<<'\n'
    <<"Major: "<<s.major<<'\n'
    <<"Enrollment_date: "<<s.enroll_date<<'\n';
    return os;
}

//------------------------------------------------------------------------------------------------------

//ouput Student's data formatted for readabilty
void Student::symbolic_print(std::ostream& os){
  os<<"Student_ID: "<<id_number<<'\n'
    <<"Full_name: "<<name<<'\n';
    os<<"Birth date: "; birth_date.symbolic_print(os);
    os<<"\nMajor: "<<major<<'\n';
    os<<"Enrollment date: "; enroll_date.symbolic_print(os);
    os<<'\n';
}

//------------------------------------------------------------------------------------------------------

int Student::get_id() const{  //function to return Student's id number
  return id_number;
}

//------------------------------------------------------------------------------------------------------

string Student::get_name() const{  //function to return Student's full name 
  return name;
}
//************************************************************************************************




