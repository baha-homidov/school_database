#include "school.h"

//*********************************************************************************************************

void School::output_all(std::ostream &os)
{ // output all the students int studets_list to ostream
    const std::string break_point = "----";

    os << "SCHOOL_NAME: " << name << '\n';

    for(std::string subj_name: subject_list)  //first output list of the students
        os << "subject_name: " << subj_name<<'\n';

    os << "---"; //breakpoint to divide subject list for student list

    for (int i = 0; i < students_list.size(); ++i)
    {
        os << students_list[i];
        if (i < (students_list.size() - 1))
            os << '\n'<<break_point ;
    }
}

//------------------------------------------------------------------------------------------------------------------------

void School::fill_from_file(std::string file_name) // fill the students_list vector from a text file
{
    std::ifstream ifs{file_name};
    std::string name_prefix;
    ifs >> name_prefix;
    ifs.ignore();
    std::getline(ifs, name);
    while (true)
    {
        const std::string break_point = "---";
        std::string subject_prefix;
        std::string subject_name;
        ifs >> subject_prefix;
        if (subject_prefix == break_point)
            break;
        else
        {
            ifs.ignore();
            std::getline(ifs, subject_name);
            subject_list.push_back(subject_name);
        }
    }
    if(ifs.peek()==EOF)
        return; //if file file_name is an empty file to get any input and just exit the function

    while (!ifs.eof()) // fill student_list
    {
        std::string id_prefix, name_prefix, birth_prefix, major_prefix, enroll_prefix, end_data, marks_prefix;
        int id_number;
        std::string full_name;
        std::string major;
        Date birth_date;
        Date enroll_date;
        Marks marks;
        ifs >> id_prefix >> id_number;
        if(ifs.fail())   //if there are no student entries exit the function
            return;
        ifs >> name_prefix >> std::ws;
        std::getline(ifs, full_name); // getline because name can consist of multiple names
        ifs >> birth_prefix >> birth_date;
        ifs >> major_prefix >> std::ws;
        std::getline(ifs, major); // getline because a major name can consist of multiple names
        ifs >> enroll_prefix;
        ifs >> enroll_date;
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