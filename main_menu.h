// file main_menu.h
#ifndef MAIN_MENU_GUARD
#define MAIN_MENU_GUARD
#include <iostream>
#include "school.h"
#include "helper_functions.h"

namespace Menu
{
    void main_menu();
    void import_data();
    void new_data();
    void work_on_file(School school, std::string filename);
    void edit_student(std::vector<Student>::iterator &s);
    void edit_birth(Student &stud);
    void edit_enroll(Student &stud);
    void edit_marks(Student &stud);
    void name_search(School &school, std::string filename);
    void id_search(School &school, std::string filename);
    void delete_student(School &school, std::string filename);
    void clear_all_data(School &school, std::string filename);
    void input_data(School &school, std::string filename);
};

#endif