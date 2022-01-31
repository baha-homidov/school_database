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
public:
     Student(int n_id_number,string n_name, string n_major, Date n_birth_date, Date n_enroll_date, Marks n_marks);   //parameterized contructor
     void symbolic_print(std::ostream& os);
     int get_id() const;    //function to return Student's id number
     string get_name() const;  //function to return Student's full name 
     friend ostream& operator<<(ostream& os, const Student& s);    //overloaded ostream operator
     void edit_name(string new_name){name=new_name;}
     void edit_major(string new_major) {major=new_major;}
     void edit_birth_date(Date new_date) {birth_date=new_date;}
     void edit_enroll_date(Date new_date) {enroll_date=new_date;}
     Marks* marks_ptr(){return &marks;}      //return a pointer to a private data-member 'marks' (possibly sloppy code writing)
private:
     string name;
     string major;
     int id_number;
     Date birth_date;  
     Date enroll_date;  //enrollment date
     Marks marks;
};
//------------------------------------------------------------------------------------------------------


#endif