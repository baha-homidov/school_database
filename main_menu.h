//file main_menu.h
#ifndef MAIN_MENU_GUARD
#define MAIN_MENU_GUARD
#include <iostream>
#include "school.h"
#include "helper_functions.h"






struct Menu{
    void main_menu();
    void import_data();
    void new_data();
    void work_on_file(School school, string filename);
    void edit_student(vector<Student>::iterator& s);
    void edit_birth(Student& stud);
    void edit_enroll(Student& stud);
    void edit_marks(Student& stud);
    void name_search(School& school, string filename);
    void id_search(School& school, string filename);
    void delete_student(School& school, string filename);
    void clear_all_data(School& school, string filename);

};





#endif