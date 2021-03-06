#include <vector>
#include <string>
#include "date.h"
#include "helper_functions.h"
#include "student.h"

// explicit constructor
Student::Student(std::string n_id_number, std::string n_name, std::string n_major, Date n_birth_date, Date n_enroll_date, Marks n_marks) : id_number(n_id_number),
                                                                                                                                   name(n_name),
                                                                                                                                   major(n_major),
                                                                                                                                   birth_date(n_birth_date),
                                                                                                                                   enroll_date(n_enroll_date),
                                                                                                                                   marks(n_marks)
{
}

//------------------------------------------------------------------------------------------------------

std::ostream &operator<<(std::ostream &os, const Student &s)
{
  os << "\nStudent_ID: " << s.id_number << '\n'
     << "Full_name: " << s.name << '\n'
     << "Birth_date: " << s.birth_date << '\n'
     << "Major: " << s.major << '\n'
     << "Enrollment_date: " << s.enroll_date << '\n'
     << "Mark_list:"<<s.marks ;
  return os;
}

//------------------------------------------------------------------------------------------------------

// ouput Student's data formatted for readabilty
void Student::symbolic_print(std::ostream &os)
{
  os << "Student_ID: " << id_number << '\n'
     << "Full_name: " << name << '\n';
  os << "Birth date: ";
  birth_date.symbolic_print(os);
  os << "\nMajor: " << major << '\n';
  os << "Enrollment date: ";
  enroll_date.symbolic_print(os);
  os << "\nMarks:\n";
  marks.print(os);
  os << '\n';
  os << "Average score: " << marks.av_mark() << '\n';
}

//************************************************************************************************
