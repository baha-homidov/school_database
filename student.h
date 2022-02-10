// file student.h
#ifndef STUDENT_GUARD
#define STUDENT_GUARD
#include <vector>
#include <string>
#include "date.h"
#include "helper_functions.h"
#include "marks.h"

struct Student
// class which holds the key info about the student
{
     Student(std::string n_id_number, std::string n_name, std::string n_major, Date n_birth_date, Date n_enroll_date, Marks n_marks); // explicit contructor
     void symbolic_print(std::ostream &os);
     std::string name;
     std::string major;
     std::string id_number;
     Date birth_date;
     Date enroll_date; // enrollment date
     Marks marks;
};
//------------------------------------------------------------------------------------------------------
std::ostream &operator<<(std::ostream &os, const Student &s);

#endif