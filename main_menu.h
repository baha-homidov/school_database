#pragma once
#include <iostream>
#include "school.h"
#include "helper_functions.h"


struct Menu{
    void main_menu();
    void import_data();
    void new_data();
    void work_on_file(School school, string filename);

};



//------------------------------------------------------------------

void Menu::main_menu(){
    int input;
    
    while(true){
    cout<<"*****School database******\n\n\n"<<"--Main Menu--\n\n"
        <<"[1]Open an existing file\n"
        <<"[2]Create a new file.\n"
        <<"[3]Quit\n\nInput: ";
    cin>>input;
    while(cin.fail())    //check for a non-digit input
        {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Bad entry.  Enter a NUMBER: ";
        cin >> input;
        
        }

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
    cin>>input;
    while(cin.fail())    //check for a non-digit input
        {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Bad entry.  Enter a NUMBER: ";
        cin >> input;
        }
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
        cin>>id_num;
        school.search_by_id(id_num);
        break;
    }
    case 5: 
      {
        system("clear");
        string name;       //find a student by full name
        cout<<"Input full name: ";
        cin.ignore();
        getline(cin,name);
        school.search_by_name(name);
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
        cin>>id_num;
        while(cin.fail())    //check for a non-digit input
        {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Bad entry.  Enter a NUMBER: ";
        cin >> id_num;
        }
        school.delete_stud(id_num);       //delete the student
        school.save_as_file(filename);    //rewrite the save file
        break;
        }
    case 8:
        { 
        int input;
        cout<<"All data will be lost. Are you sure you want to clear the database?\n[1]YES     [2]NO\n";
        cin>>input;
        while(cin.fail()||(input!=1&&input!=2))    //check for a non-digit input
        {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Bad entry.  Enter a [1] or [2]: ";
        cin >> input;
        }
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