#pragma once
#include <iostream>
#include "school.h"
#include "helper_functions.h"






struct Menu{
    void main_menu();
    void import_data();
    void new_data();
    void work_on_file(School school, string filename);
    void edit_student(vector<Student>::iterator& s);

};



//------------------------------------------------------------------

void Menu::main_menu(){
    int input;
    
    while(true){
    cout<<"*****School database******\n\n\n"<<"--Main Menu--\n\n"
        <<"[1]Open an existing file\n"
        <<"[2]Create a new file.\n"
        <<"[3]Quit\n\nInput: ";
    checked_int_input(input,1,3);
    switch (input)
    {
    case 1:
        import_data();
        break;
    case 2:
        new_data();
        break;
    case 3:
        return;
        break;
    default:
        cout<<"Invalid input.\n";
        break;
    }
    }
}

//------------------------------------------------------------------


void Menu::import_data(){     //import data from a given file <<filename>>
   School import_school;
   std::string filename;
   cout<<"Please input file name you want to load: ";
   cin>>filename;
   import_school.fill_from_file(filename);

   
   work_on_file(import_school,filename);
}


//------------------------------------------------------------------
void Menu::new_data(){
    School new_school;
    string filename;
    cout<<"Name of your save file: ";
    cin>>filename;
    work_on_file(new_school,filename);
}

//------------------------------------------------------------------

void Menu::work_on_file(School school,string filename){
    while(true){
    int input;
    cout<<"*****School database******\n\n\n"<<"--Working on file: "<<filename<< "--\n\n"
        <<"[1]Show all the students\n"
        <<"[2]Sort students by name\n"
        <<"[3]Sort student by ID number\n"
        <<"[4]Search for student by id number\n"
        <<"[5]Search for student by full name\n"
        <<"[6]Add students\n"
        <<"[7]Delete a student\n"
        <<"[8]Clear the database\n"
        <<"[9]Go back to main menu\n"
        <<"[10]Quit\n"
        <<"\nInput: ";
    checked_int_input(input,1,10);
    switch (input)
    {
    case 1:
        system("clear");
        school.print(cout);
        break;
    case 2:
        school.sort_by_name();             //sort the students by name
        school.save_as_file(filename);     //and rewrite the save file
        break;
    case 3:
        school.sort_by_id();              //sort the students by ID number
        school.save_as_file(filename);   //and rewrite the save file
        break;
    case 4:
    {
        system("clear");      //find a student by ID number
        int id_num;
        cout<<"Input ID number: ";
        checked_int_input(id_num);
        auto s=school.search_by_id(id_num);
        if(s==school.students_list_end()) cout<<"Student ID number: "<<id_num<<" not found.\n";   //check if search was successfull
        else {
            int input;
            system("clear");
            Student stud=*s;
            cout<<"Result: \n";
            stud.symbolic_print(cout);
            cout<<"\n------------------\nOptions:\n"
                <<"[1]Edit data\n"
                <<"[2]Delete student\n"
                <<"[3]Back\n";
            
            while(input!=3){
            cout<<"Input: "; checked_int_input(input,1,3);    //take input from user
            if(input==1) {edit_student(s); school.save_as_file(filename); }  //edit student and rewrite the save file
            else if(input==2){school.delete_stud(id_num); school.save_as_file(filename); break; }  //delete student and rewrite the save file
            else cout<<"Invalid input\n";
            }
            
        }
        break;
    }
    case 5: 
      {
        system("clear");      //find a student by ID number
        string name;
        int id_num;
        cout<<"Input full name: ";
        cin.ignore();
        getline(cin,name);
        auto s=school.search_by_name(name);
        if(s==school.students_list_end()) cout<<"Student name: "<<name<<" not found.\n";   //check if search was successfull
        else {
            int input;
            system("clear");
            Student stud=*s;
            id_num=stud.get_id();
            cout<<"Result: \n";
            stud.symbolic_print(cout);
            cout<<"\n------------------\nOptions:\n"
                <<"[1]Edit data\n"
                <<"[2]Delete student\n"
                <<"[3]Back\n";
            while(input!=3){
            cout<<"Input: "; checked_int_input(input,1,3);    //take input from user
            if(input==1) {edit_student(s); school.save_as_file(filename); }  //edit student and rewrite the save file
            else if(input==2){school.delete_stud(id_num); school.save_as_file(filename); break; }  //delete student and rewrite the save file
            else cout<<"Invalid input\n";
            }
        }
        break;
    }
    case 6:
        system("clear");
        school.input_data();            //add students and rewrite current file
        school.save_as_file(filename);
        break;
    case 7:
        {
        int id_num;              //add a student by ID number
        cout<<"Add student ID number for deletion: ";
        checked_int_input(id_num);
        school.delete_stud(id_num);       //delete the student
        school.save_as_file(filename);    //rewrite the save file
        break;
        }
    case 8:
        { 
        int input;
        cout<<"All data will be lost. Are you sure you want to clear the database?\n[1]YES     [2]NO\n";
        checked_int_input(input,1,2);
        if(input==1){
            school.clear();                   //clear all the data in school
            school.save_as_file(filename);    //rewrite the save file
            cout<<"All the data was erased.\n";
            break;
        }
        else {cout<<"Action was canceled\n"; break;}

        }
    case 9:        //go back to main menu
        return;
        break;
    case 10:       
        exit(0);
        break;
    default:
        cout<<"Invalid input.\n";
        break;
    }
    }
}

//------------------------------------------------------------------

void Menu::edit_student(vector<Student>::iterator& s){             //edit Student data 
    int input;
            Student stud=*s;
            cout<<"\n------------------\nOptions:\n"
                <<"[1]Edit full name\n"
                <<"[2]Edit major\n"
                <<"[3]Edit birth date\n"
                <<"[4]Edit enrollment date\n"
                <<"[5]Back\n";

    while(true){
    cout<<"Input: "; checked_int_input(input,1,5);    //take input from user
    switch (input)
    {
    case 1:
        {
        string name;                 //edit full name
        cout<<"Input new name: ";
        cin.ignore();
        getline(cin,name);
        stud.edit_name(name);
        }
        break;
    case 2:
        {                          //edit major name
        string major;
        cout<<"Input new major: ";
        cin.ignore();
        getline(cin,major);
        stud.edit_major(major);
        }
  
    case 3: 
        {                         //edit birth date 
        int month,day,year;       //TODO: implement a function for editig date

        cout<<"Input new enroll date: \nMonth: "; checked_int_input(month,1,12);
        
        cout<<"Day: "; checked_int_input(day,1,31);
        
        cout<<"Year: "; checked_int_input(year,1900,2025);

        stud.edit_birth_date(Date{Month(month),day,year});
        }
        break;
    case 4:
        {                             //edit enrollment date
        int month,day,year;           //TODO: imlement a function for editig date

        cout<<"Input new birthday: \nMonth: "; checked_int_input(month,1,12);

        cout<<"Day: "; checked_int_input(day,1,31);

        cout<<"Year: "; checked_int_input(year,1900,2025);

        stud.edit_enroll_dat(Date{Month(month),day,year});
        }
        break;
    case 5:                       //save changes and exit from the function 
        *s=stud;
        return;
        default:
        cout<<"Invalid input\n";
        break;
        }
    }
}