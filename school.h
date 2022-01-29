//file school.h
#ifndef SCHOOL_GUARD
#define SCHOOL_GUARD
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "student.h"
#include "date.h" 
#include "helper_functions.h"



using namespace std;

bool comp_name(Student a, Student b);

//*********************************************************************************************************

bool comp_id(Student a, Student b);

//*********************************************************************************************************

class Id_search{    //function class to check if School has a student with similar id number
   int id_number;
public:
   Id_search(int id) : id_number(id) {}
   bool operator()(const Student& s) const { return id_number==s.get_id(); }
};

//*********************************************************************************************************


class Name_search{    //function class to check if School has a student with similar name
   string name;
public:
   Name_search(string nname) : name(nname) {}
   bool operator()(const Student& s) const { return name==s.get_name(); }
};

//*********************************************************************************************************





class School{
    vector<Student> students_list;

public:
    vector<Student>::iterator students_list_end(){ return students_list.end(); } 
    void sort_by_name();  //sort the students in student_list by names
    void sort_by_id();    //sort the student in student_list by id numbers
    void fill_from_file(string file_name);    //fill the students_list vector from a text file
    void input_data();  //input loop to add students to student_list from user input
    void output_all(ostream& os);   //output all the students int studets_list to ostream
    void print(std::ostream& os);    //print out all the student formatted for readabilty
    void save_as_file(string filename);   //save data to a text file
    vector<Student>::iterator search_by_id(int id_num);       //search for student with given id_num in students_list
    vector<Student>::iterator search_by_name(string name);    //search for student with given id_num in students_list
    void delete_stud(int id_num);        //delete a  student by ID number
    void clear();                   //delete all the data in students_list
};


//------------------------------------------------------------------------------------------------------------


#endif