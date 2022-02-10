// file school.h
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
#include "marks.h"

struct School
{
    std::string name;
    std::vector<Student> students_list;   //TODO: rename to student_list
    std::vector<std::string> subject_list; //list to hold subjects 
    std::vector<Student>::iterator students_list_end() { return students_list.end(); }
    void sort_by_name();                                             // sort the students in student_list by names
    void sort_by_id();                                               // sort the student in student_list by id numbers
    void fill_from_file(std::string file_name);                      // fill the students_list vector from a text file
    void output_all(std::ostream &os);                               // output all the students int studets_list to ostream
    double av_score();                                               // average score of all the students
    void print(std::ostream &os);                                    // print out all the student formatted for readabilty
    void save_as_file(std::string filename);                         // save data to a text file
    std::vector<Student>::iterator search_by_id(std::string id_num); // search for student with given id_num in students_list
    std::vector<Student>::iterator search_by_name(std::string name); // search for student with given id_num in students_list
    void delete_stud(std::string id_num);                                    // delete a  student by ID number
    void clear();                                                    // delete all the data in students_list
};

//------------------------------------------------------------------------------------------------------------

#endif