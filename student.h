//file student.h
#ifndef STUDENT_GUARD
#define STUDENT_GUARD
#include <vector>
#include <string>
#include "date.h"
#include "helper_functions.h"
#include "marks.h"
using namespace std;


struct Student
//class which holds the key info about the student
{
     Student(int n_id_number,string n_name, string n_major, Date n_birth_date, Date n_enroll_date, Marks n_marks);    //explicit contructor
     void symbolic_print(std::ostream& os);
     string name;
     string major;
     int id_number;
     Date birth_date;  
     Date enroll_date;  //enrollment date
     Marks marks;
};
//------------------------------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const Student& s);

#endif