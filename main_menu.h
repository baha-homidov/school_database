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
        <<"[2]Search for student by id number\n"
        <<"[3]Search for student by full name\n"
        <<"[4]Add students\n"
        <<"[5]Go back to main menu\n"
        <<"[6]Quit\n"
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
    {
        system("clear");
        int id_num;
        cout<<"Input id number: ";
        cin>>id_num;
        school.search_by_id(id_num);
        break;
    }
    case 3: 
      {
        system("clear");
        string name;
        cout<<"Input full name: ";
        cin.ignore();
        getline(cin,name);
        school.search_by_name(name);
        break;
    }  
    case 4:
        system("clear");
        school.input_data();            //add students and rewrite current file
        school.save_as_file(filename);
        break;
    case 5:        //go back to main menu
        return;
        break;
    case 6:       
        exit(0);
        break;
    default:
        cout<<"Invalid input.\n";
        break;
    }
    }
}