// file main_menu.h
#ifndef MAIN_MENU_GUARD
#define MAIN_MENU_GUARD
#include <iostream>
#include "school.h"
#include "helper_functions.h"
#include "school_entry.h"

namespace Menu
{
    void main_menu();
    void show_list();
    void add_school_entry(std::vector<School_entry> &school_entry);
    void password_check(const School_entry &school_entry);
    void work_on_file(std::string filename);
    void edit_student(std::vector<Student>::iterator &s);
    void edit_birth(Student &stud);
    void edit_enroll(Student &stud);
    void edit_marks(Student &stud);
    void name_search(School &school, std::string filename);
    void id_search(School &school, std::string filename);
    void delete_student(School &school, std::string filename);
    void clear_all_data(School &school, std::string filename);
    void input_data(School &school, std::string filename);
    void about();
};

#endif