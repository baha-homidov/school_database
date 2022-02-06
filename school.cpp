#include "school.h"

//*********************************************************************************************************

void School::output_all(std::ostream &os)
{ // output all the students int studets_list to ostream
    for (int i = 0; i < students_list.size(); ++i)
    {
        os << students_list[i];
        if (i < (students_list.size() - 1))
            os << "----\n";
    }
}

//------------------------------------------------------------------------------------------------------------------------

void School::fill_from_file(std::string file_name) // fill the students_list vector from a text file
{
    std::ifstream ifs{file_name};
    while (!ifs.eof())
    {
        std::string id_prefix, name_prefix, birth_prefix, major_prefix, enroll_prefix, end_data, marks_prefix;
        int id_number;
        std::string full_name;
        std::string major;
        Date birth_date;
        Date enroll_date;
        Marks marks;
        ifs >> id_prefix >> id_number;
        ifs >> name_prefix >> std::ws;
        std::getline(ifs, full_name); // getline because name can consist of multiple names
        ifs >> birth_prefix >> birth_date;
        ifs >> major_prefix >> std::ws;
        std::getline(ifs, major); // getline because a major name can consist of multiple names
        ifs >> enroll_prefix >> enroll_date;
        ifs >> marks_prefix >> marks;
        ifs >> end_data;
        students_list.push_back(Student(id_number, full_name, major, birth_date, enroll_date, marks));
    }
}

//------------------------------------------------------------------------------------------------

void School::print(std::ostream &os) // print out all the student formatted for readabilty
{
    std::cout << "Number of students: " << students_list.size() << '\n'
              << "************************************\n************************************\n";
    for (int i = 0; i < students_list.size(); ++i)
    {
        os << "Student №" << i + 1 << '\n';
        students_list[i].symbolic_print(os);
        os << "----\n";
    }
}

//------------------------------------------------------------------------------------------------------------------------

void School::sort_by_name()
{ // sort the students in student_list by names
    if (students_list.size() < 2)
        return; // don't do sorting if students_list's size is smaller than 2
    std::sort(students_list.begin(), students_list.end(),
              [](Student a, Student b)
              { return a.name < b.name; });
}

//------------------------------------------------------------------------------------------------------------------------

void School::sort_by_id()
{ // sort the student in student_list by id numbers
    if (students_list.size() < 2)
        return; // don't do sorting if students_list's size is smaller than 2
    std::sort(students_list.begin(), students_list.end(),
              [](Student a, Student b)
              { return a.id_number < b.id_number; });
}

void School::save_as_file(std::string filename)
{ // save data to a text file
    std::ofstream ofs{filename};
    output_all(ofs);
}

//------------------------------------------------------------------------------------------------------------

std::vector<Student>::iterator School::search_by_id(int id_num) // search for student with given id_num in students_list
{
    auto s = std::find_if(students_list.begin(), students_list.end(),
                          [id_num](const Student &s)
                          { return s.id_number == id_num; });
    return s;
}

//------------------------------------------------------------------------------------------------------------

std::vector<Student>::iterator School::search_by_name(std::string name)
{
    auto s = std::find_if(students_list.begin(), students_list.end(),
                          [name](const Student &s)
                          { return s.name == name; });
    return s;
}

//-------------------------------------------------------------------------------------------------------------

void School::delete_stud(int id_num) // delete a  student by ID number
{
    auto s = std::find_if(students_list.begin(), students_list.end(), [id_num](const Student &s)
                          { return s.id_number == id_num; });
    if (s != students_list.end())
    {
        students_list.erase(s);
        std::cout << "Student ID: " << id_num << " deleted.\n";
    }
    else
        std::cout << "No student found with id number: " << id_num << ".\n";
}

//------------------------------------------------------------------------------------------------------------------------

void School::clear()
{
    students_list.clear(); // students
}

//------------------------------------------------------------------------------------------------------------------------

double School::av_score()
{
    if (students_list.size() == 0)
        return 0;
    double sum = 0;
    for (int i = 0; i < students_list.size(); ++i)
    {
        sum += students_list[i].marks.av_mark();
    }
    return sum / students_list.size();
}