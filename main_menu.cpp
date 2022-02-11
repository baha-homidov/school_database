
#include <iostream>
#include "school.h"
#include "helper_functions.h"
#include "main_menu.h"

//------------------------------------------------------------------

void Menu::main_menu()
{
    int input;

    while (true)
    {
        std::cout << "*****School database******\n\n\n"
                  << "--Main Menu--\n\n"
                  << "[1]Show school's list.\n"
                  << "[2]About\n"
                  << "[3]Quit\n\nInput: ";
        input = checked_int_input(1, 3);
        switch (input)
        {
        case 1:
            show_list();
            break;
        case 2:
            std::cout << "***Student data management***\n\nToy project made by Mirzobakhtiyor Homidov\n";
            break;
        case 3:
            return;
            break;
        default:
            std::cout << "Invalid input.\n";
            break;
        }
    }
}

//------------------------------------------------------------------

void Menu::show_list()
{ // get school's list from a file
    const std::string filename = "school_list";
    std::vector<School_entry> school_entries;
    std::ifstream ifs{filename};
    while (ifs.peek() != EOF)
    {
        School_entry s;
        ifs >> s;
        school_entries.push_back(s);
    }

    // Make manipulations on the list
    while (true)
    {

        int input;
        std::cout << "Please choose a school.\n\n";
        if (school_entries.size() == 0)
            std::cout << "****List is empty****\n\n";
        else
        {
            for (int i = 0; i < school_entries.size(); ++i) // output School's list as formatted text
                std::cout << '[' << i + 1 << ']' << school_entries[i].name << '\n';
        }
        std::cout << '\n'
                  << '[' << school_entries.size() + 1 << ']' << "Add a new school.\n";

        std::cout << '[' << school_entries.size() + 2 << ']' << "Back\n";

        std::cout << "\n\nInput: ";

        input = checked_int_input(1, school_entries.size() + 2);
        if (input > school_entries.size()) // if user doesn't choose a school check for input
        {                                  // whether to add a new school or leave currrent menu
            if (input == school_entries.size() + 1)
            {
                add_school_entry(school_entries);
                std::ofstream ofs(filename, std::ios_base::app); // append new school_entry to the school_list file
                ofs << school_entries[school_entries.size() - 1];
            }

            else
                return;
        }
        else
            password_check(school_entries[input - 1]); // if user chooses a school go to password_check menu
    }
}

//------------------------------------------------------------------

void Menu::work_on_file(std::string filename)
{ // make operations on a given file
    School school;
    school.fill_from_file(filename);

    while (true)
    {
        int input;
        std::cout << "*****School database******\n\n\n"
                  << "--Working on School: " << school.name << "--\n\n"
                  << "[1]Show all the students\n"
                  << "[2]Show the average marks\n"
                  << "[3]Sort students by name\n"
                  << "[4]Sort students by ID number\n"
                  << "[5]Search for student by id number\n"
                  << "[6]Search for student by full name\n"
                  << "[7]Add students\n"
                  << "[8]Delete a student\n"
                  << "[9]Clear the database\n"
                  << "[10]Go back to school list\n"
                  << "[11]Quit\n"
                  << "\nInput: ";
        input = checked_int_input(1, 11);
        switch (input)
        {
        case 1:
            std::system("clear"); // show all the students
            school.print(std::cout);
            break;
        case 2:
            std::cout << "Average score of all the students in school: " // show the average score
                      << school.name << ": " << school.av_score() << '\n';
            break;
        case 3:
            school.sort_by_name();         // sort the students by name
            school.save_as_file(filename); // and rewrite the save file
            break;
        case 4:
            school.sort_by_id();           // sort the students by ID number
            school.save_as_file(filename); // and rewrite the save file
            break;
        case 5:
            id_search(school, filename); // find a student by ID number
            break;
        case 6:
            name_search(school, filename); // find a student by full name
            break;
        case 7:
            std::system("clear");
            input_data(school, filename);
            break;
        case 8:
            delete_student(school, filename); // delete a student
            break;
        case 9:
            clear_all_data(school, filename); // clear all the data in current file
            break;
        case 10: // go back to main menu
            return;
            break;
        case 11:
            exit(0);
            break;
        default:
            std::cout << "Invalid input.\n";
            break;
        }
    }
}

//------------------------------------------------------------------

void Menu::edit_student(std::vector<Student>::iterator &s)
{ // edit Student data
    while (true)
    {
        int input;

        std::cout << "\n------------------\nOptions:\n"
                  << "[1]Edit full name\n"
                  << "[2]Edit major\n"
                  << "[3]Edit birth date\n"
                  << "[4]Edit enrollment date\n"
                  << "[5]Edit marks\n"
                  << "[6]Back\n";

        std::cout << "Input: ";
        input = checked_int_input(1, 6); // take input from user
        switch (input)
        {
        case 1:
        {
            // edit full name
            std::string new_name;
            std::cout << "Input new name: ";
            std::cin.ignore();
            std::getline(std::cin, new_name);
            (*s).name = new_name;
        }
        break;
        case 2:
        {
            // edit major name
            std::string new_major;
            std::cout << "Input new major: ";
            std::cin.ignore();
            std::getline(std::cin, new_major);
            (*s).major = new_major;
        }
        break;
        case 3:
            // edit birth date
            edit_birth(*s);
            break;
        case 4:
            // edit enroll date
            edit_enroll(*s);
            break;
        case 5:
            // edit marks
            edit_marks(*s);
            break;
        case 6: // exit from the function
            return;
        default:
            std::cout << "Invalid input\n";
            break;
        }
    }
}

//-----------------------------------------------------------------

void Menu::edit_birth(Student &stud) // edit birth date of a given Student
{
    int month, day, year;

    std::cout << "Input new birth date: \nMonth: ";
    month = checked_int_input(1, 12);

    std::cout << "Day: ";
    day = checked_int_input(1, 31);

    std::cout << "Year: ";
    year = checked_int_input(1900, 2025);

    stud.birth_date = Date{Month(month), day, year};
}

//-----------------------------------------------------------------

void Menu::edit_enroll(Student &stud) // edit enroll date of a given Student
{
    int month, day, year;

    std::cout << "Input new enroll date: \nMonth: ";
    month = checked_int_input(1, 12);

    std::cout << "Day: ";
    day = checked_int_input(1, 31);

    std::cout << "Year: ";
    year = checked_int_input(1900, 2025);

    stud.enroll_date = Date{Month(month), day, year};
}

//----------------------------------------------------------------

void Menu::id_search(School &school, std::string filename)
// menu for searching a student by ID number and making operations on it
{
    std::system("clear"); // find a student by ID number
    std::string id_num;
    std::cout << "Input ID number: ";
    std::cin >> id_num;
    auto s = school.search_by_id(id_num);
    if (s == school.students_list.end())
        std::cout << "Student ID number: " << id_num << " not found.\n"; // check if search was successfull
    else
    {
        while (true)
        {
            int input;
            std::system("clear");
            Student stud = *s;
            std::cout << "Result: \n";
            stud.symbolic_print(std::cout);
            std::cout << "\n------------------\nOptions:\n"
                      << "[1]Edit data\n"
                      << "[2]Delete student\n"
                      << "[3]Back\n";
            std::cout << "Input: ";
            input = checked_int_input(1, 3); // take input from user
            switch (input)
            {
            case 1:
                edit_student(s);
                school.save_as_file(filename); // edit student and rewrite the save file
                break;
            case 2:
                school.delete_stud(id_num);
                school.save_as_file(filename); // delete student and rewrite the save file
                return;
                break;
            case 3:
                // leave current menu
                return;
                break;
            default:
                std::cout << "Invalid input.";
                break;
            }
        }
    }
}

//----------------------------------------------------------------

void Menu::name_search(School &school, std::string filename)
// menu for searching a student by full name and making operations on it
{
    std::system("clear"); // find a student by ID number
    std::string name;
    std::string id_num;

    std::cout << "Input full name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    
    auto s = school.search_by_name(name);
    if (s == school.students_list.end())
        std::cout << "Student name: " << name << " not found.\n"; // check if search was successfull
    else
    {
        while (true)
        {
            int input;
            std::system("clear");
            Student stud = *s;
            id_num = stud.id_number;
            std::cout << "Result: \n";
            stud.symbolic_print(std::cout);

            std::cout << "\n------------------\nOptions:\n"
                      << "[1]Edit data\n"
                      << "[2]Delete student\n"
                      << "[3]Back\n";
            std::cout << "Input: ";
            input = checked_int_input(1, 3); // take input from user
            
            switch (input)
            {
            case 1:
                edit_student(s);
                school.save_as_file(filename); // edit student and rewrite the save file
                break;
            case 2:
                school.delete_stud(id_num);
                school.save_as_file(filename); // delete student and rewrite the save file
                return;
                break;
            case 3:
                // leave the menu
                return;
                break;
            default:
                std::cout << "Invalid input.";
                break;
            }
        }
    }
}

//------------------------------------------------------------------

void Menu::delete_student(School &school, std::string filename)
{ // delete a student by ID number
    std::string id_num;
    std::cout << "Input student ID number for deletion: ";
    std::cin >> id_num;
    school.delete_stud(id_num);    // delete the student or output "Student doesn't exist" in the case of invalid ID number
    school.save_as_file(filename); // rewrite the save file
}

//------------------------------------------------------------------

void Menu::clear_all_data(School &school, std::string filename)
{
    int input;
    std::cout << "All data will be lost. Are you sure you want to clear the database?\n[1]YES     [2]NO\n";
    input = checked_int_input(1, 2);
    if (input == 1)
    {
        school.clear();                // clear all the data in school
        school.save_as_file(filename); // rewrite the save file
        std::cout << "All the data was erased.\n";
    }
    else
        std::cout << "Action was canceled\n";
}

//------------------------------------------------------------------

void Menu::edit_marks(Student &stud)
{
    while (true)
    {
        int input;
        double new_score;
        std::cout << "Current marks:\n";
        stud.marks.print(std::cout);
        std::cout << "Choose subject to edit data:\n";
        
        for (int i = 0; i < stud.marks.marks_list.size(); i++)       //print out all the subjects as formatted text
            std::cout << '[' << i + 1 << ']' << stud.marks.marks_list[i].first << '\n';

        std::cout << '[' << stud.marks.marks_list.size() + 1 << ']' << "Back\n";

        std::cout << "Input: ";
        input = checked_int_input(1, 5);
        
        if (input == stud.marks.marks_list.size() + 1)
            return; // if input==back exit the function
        else
        {
            std::cout << "New " << stud.marks.marks_list[input - 1].first << " mark: ";
            new_score = checked_double_input(0, 100);
            stud.marks.marks_list[input - 1].second = new_score;
        }
    }
}

//---------------------------------------------------------------------------------------------------------------

void Menu::input_data(School &school, std::string filename)    //function for adding students to the data base
{
    int student_num;
    std::cout << "Number of students you want to input: ";
    student_num = checked_int_input();
    for (int i = 0; i < student_num; ++i) // input loop
    {

        std::string name;
        std::string major;
        // birth date variables
        int birth_month;
        int birth_day;
        int birth_year;
        // Enrollment date variables
        int enroll_month;
        int enroll_day;
        int enroll_year;
        // Marks variables
        Marks marks;

        std::cout << "Student " << i + 1 << '\n';
        std::cout << "New entry\n";
        std::cin.ignore();
        std::cout << "Input full name: ";

        std::getline(std::cin, name);
        std::cout << "Input major: ";

        std::getline(std::cin, major);
        std::cout << "Input birthday: \nMonth: ";
        birth_month = checked_int_input(1, 12); // get checked input from user
        std::cout << "Day: ";
        birth_day = checked_int_input(1, 31);
        std::cout << "Year: ";
        birth_year = checked_int_input(1900, 2025);
        std::cout << "Input enrollment date: \n Month: ";
        enroll_month = checked_int_input(1, 12);
        std::cout << "Day: ";
        enroll_day = checked_int_input(1, 31);
        std::cout << "Year: ";
        enroll_year = checked_int_input(1900, 2025);

        // Generating ID number according to the added data
        std::string id_num = std::to_string(rand_num()) + std::to_string(birth_month) + std::to_string(birth_day) + std::to_string(birth_year);
        std::cout << "Generated ID number: " << id_num << '\n';
        std::cout << "Adding marks\n\n";

        for (int i = 0; i < school.subject_list.size(); i++)
        // input score data according to school->subject_list
        {
            int score;
            std::cout << "Input " << school.subject_list[i] << " score: \n\n"
                      << "Input: ";
            score = checked_double_input(0, 100);
            marks.marks_list.push_back(std::make_pair(school.subject_list[i], score));
        }
        school.students_list.push_back(Student(id_num, name, major, {Month(birth_month), birth_day, birth_year}, {Month(enroll_month), enroll_day, enroll_year}, marks));
    }
    school.save_as_file(filename);
}

//---------------------------------------------------------------------------------------------------------------

void Menu::add_school_entry(std::vector<School_entry> &school_entry)
{
    // Add a new entry into a school_entry
    // Make a new 'School' get the list of subjects from user input and save it as a a file

    std::string filename = "file" + std::to_string(rand_num());   //generating random name for filename
    std::string password;
    School school;
    int subject_num;

    std::cout << "*****Adding a new School*****\n\n"
              << "Input you New School's name: \n"
              << "Input: ";
    std::cin.ignore();
    std::getline(std::cin, school.name);
    std::cout << "Input a password to protect your data(In future you'll need to input this password to access this data.)\n"
              << "Input: ";
    std::cin >> password;
    std::cout << "Now you need to input subjects for \"" << school.name << "\"\n"
              << "How many subjects do you want to have?\n"
              << "Input: ";
    subject_num = checked_int_input(1, 40);
    for (int i = 0; i < subject_num; ++i)
    {
        std::string subject_name;
        std::cout << "Subject " << i + 1 << "'s name\n"
                  << "Input: ";
        if (i == 0)
            std::cin.ignore(); // do this if statement to get correct input withour losing any characters
        std::getline(std::cin, subject_name);
        school.subject_list.push_back(subject_name);
    }
    school.save_as_file(filename);
    school_entry.push_back({school.name, password, filename});
    std::cout << "School: " << school.name << " is successfully added to the list.\n";
}

//---------------------------------------------------------------------------------------------------------------

void Menu::password_check(const School_entry &school_entry)
{ // function to do a simple passwork check
    std::string attempt;
    std::cout << "Input password for " << school_entry.name << '\n'
              << "\nInput: ";
    std::cin >> attempt;
    if (attempt == school_entry.password)
        work_on_file(school_entry.filename); // if the password is correct then start working on that file
    else
        std::cout << "Incorrect password.\n";
}