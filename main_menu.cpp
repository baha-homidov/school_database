
#include <iostream>
#include "school.h"
#include "helper_functions.h"
#include "main_menu.h"
using namespace std;



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
void Menu::new_data(){        //make a new save file and start working on it
    School new_school;
    string filename;
    cout<<"Name of your save file: ";
    cin>>filename;
    work_on_file(new_school,filename);
}

//------------------------------------------------------------------

void Menu::work_on_file(School school,string filename){       //make operations on a given file
    while(true){
    int input;
    cout<<"*****School database******\n\n\n"<<"--Working on file: "<<filename<< "--\n\n"
        <<"[1]Show all the students\n"
        <<"[2]Show the average marks\n"
        <<"[3]Sort students by name\n"
        <<"[4]Sort student by ID number\n"
        <<"[5]Search for student by id number\n"
        <<"[6]Search for student by full name\n"
        <<"[7]Add students\n"
        <<"[8]Delete a student\n"
        <<"[9]Clear the database\n"
        <<"[10]Go back to main menu\n"
        <<"[11]Quit\n"
        <<"\nInput: ";
    checked_int_input(input,1,11);
    switch (input)
    {
    case 1:
        system("clear");
        school.print(cout);
        break;
    case 2:
        cout<<"Average score all the students in file: "   //show the average score
        <<filename<<": "<<school.av_score()<<'\n';
        break;
    case 3:
        school.sort_by_name();             //sort the students by name
        school.save_as_file(filename);     //and rewrite the save file
        break;
    case 4:
        school.sort_by_id();              //sort the students by ID number
        school.save_as_file(filename);   //and rewrite the save file
        break;
    case 5:
        id_search(school,filename);    //find a student by ID number
        break;  
    case 6: 
        name_search(school,filename);  //find a student by full name
        break;
    case 7:
        system("clear");
        school.input_data();            //add students and rewrite current file
        school.save_as_file(filename);
        break;
    case 8:
        delete_student(school,filename);  //delete a student
        break;
    case 9:
        clear_all_data(school,filename);  //clear all the data in current file
        break;
    case 10:        //go back to main menu
        return;
        break;
    case 11:       
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
    Student stud=*s;
    while(true){
    int input;
        
        cout<<"\n------------------\nOptions:\n"
            <<"[1]Edit full name\n"
            <<"[2]Edit major\n"
            <<"[3]Edit birth date\n"
            <<"[4]Edit enrollment date\n"
            <<"[5]Edit marks\n"
            <<"[6]Back\n";

    cout<<"Input: "; checked_int_input(input,1,6);    //take input from user
    switch (input)
    {
    case 1:
        {
        //edit full name
        string name;                
        cout<<"Input new name: ";
        cin.ignore();
        getline(cin,name);
        stud.edit_name(name);
        }
        break;
    case 2:
        {    
         //edit major name                     
        string major;
        cout<<"Input new major: ";
        cin.ignore();
        getline(cin,major);
        stud.edit_major(major);
        }
        break;
    case 3: 
        //edit birth date
        edit_birth(stud);
        break;
    case 4:
        //edit enroll date
        edit_enroll(stud);      
        break;
    case 5: 
        //edit marks
        edit_marks(stud);
        break;
    case 6:                       //save changes and exit from the function 
        *s=stud;
        return;
        default:
        cout<<"Invalid input\n";
        break;
        }
    }
}

//-----------------------------------------------------------------

void Menu::edit_birth(Student& stud) //edit birth date of a given Student
{                                    
        int month,day,year;      

        cout<<"Input new birth date: \nMonth: "; checked_int_input(month,1,12);
        
        cout<<"Day: "; checked_int_input(day,1,31);
        
        cout<<"Year: "; checked_int_input(year,1900,2025);

        stud.edit_birth_date(Date{Month(month),day,year});
}

//-----------------------------------------------------------------

void Menu::edit_enroll(Student& stud) //edit enroll date of a given Student
{                                    
        int month,day,year;      

        cout<<"Input new enroll date: \nMonth: "; checked_int_input(month,1,12);
        
        cout<<"Day: "; checked_int_input(day,1,31);
        
        cout<<"Year: "; checked_int_input(year,1900,2025);

        stud.edit_enroll_date(Date{Month(month),day,year});
}

//----------------------------------------------------------------

void Menu::id_search(School& school, string filename)
 //menu for searching a student by ID number and making operations on it
{   
 system("clear");      //find a student by ID number
        int id_num;
        cout<<"Input ID number: ";
        checked_int_input(id_num);
        auto s=school.search_by_id(id_num);
        if(s==school.students_list_end()) cout<<"Student ID number: "<<id_num<<" not found.\n";   //check if search was successfull
        else {
            while (true)
            {
            int input;
            system("clear");
            Student stud=*s;
            cout<<"Result: \n";
            stud.symbolic_print(cout);
            cout<<"\n------------------\nOptions:\n"
                <<"[1]Edit data\n"
                <<"[2]Delete student\n"
                <<"[3]Back\n";
            cout<<"Input: "; checked_int_input(input,1,3);    //take input from user
            switch (input)
            {
            case 1:
               edit_student(s); 
               school.save_as_file(filename);  //edit student and rewrite the save file
            break;
            case 2:
               school.delete_stud(id_num); 
               school.save_as_file(filename); //delete student and rewrite the save file
               return;
               break;
            case 3: 
               //leave the menu
               return;
               break;
            default:
                cout<<"Invalid input.";
                break;
            }
            }
        }
        

}

//----------------------------------------------------------------

void Menu::name_search(School& school, string filename)
//menu for searching a student by full name and making operations on it
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
            while (true)
            {
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
            cout<<"Input: "; checked_int_input(input,1,3);    //take input from user
            switch (input)
            {
            case 1:
               edit_student(s); 
               school.save_as_file(filename);  //edit student and rewrite the save file
            break;
            case 2:
               school.delete_stud(id_num); 
               school.save_as_file(filename); //delete student and rewrite the save file
               return;
               break;
            case 3: 
               //leave the menu
               return;
               break;
            default:
                cout<<"Invalid input.";
                break;
            }
            }
        }
}

//------------------------------------------------------------------

void Menu::delete_student(School& school, string filename){   //delete a student by ID number
    int id_num;              
        cout<<"Input student ID number for deletion: ";
        checked_int_input(id_num);
        school.delete_stud(id_num);       //delete the student or output "Student doesn't exist" in the case of invalid ID number
        school.save_as_file(filename);    //rewrite the save file
}

//------------------------------------------------------------------

void Menu::clear_all_data(School& school, string filename){
int input;
        cout<<"All data will be lost. Are you sure you want to clear the database?\n[1]YES     [2]NO\n";
        checked_int_input(input,1,2);
        if(input==1){
            school.clear();                   //clear all the data in school
            school.save_as_file(filename);    //rewrite the save file
            cout<<"All the data was erased.\n";
        }
        else cout<<"Action was canceled\n";

}

//------------------------------------------------------------------

void Menu::edit_marks(Student& stud){
   while(true){
   int input;
   cout<<"Current marks:\n";
   stud.marks_ptr()->print(cout);
   cout<<"Choose a subject to edit marks:\n"
       <<"[1]Computer science\n"
       <<"[2]Calculus\n"
       <<"[3]Linear algebra\n"
       <<"[4]Machine learning\n"
       <<"[5]Back\n";
    cout<<"Input: ";
    checked_int_input(input,1,5);
    switch (input)
    {
    case 1:
        {
        double cs;
        cout<<"New Computer Science mark: ";
        checked_double_input(cs,0.0,100.0);
        stud.marks_ptr()->set_cs(cs);
        }
        break;
    case 2:
        {
        double calc;
        cout<<"New Calculus mark: ";
        checked_double_input(calc,0.0,100.0);
        stud.marks_ptr()->set_calculus(calc);
        }
        break;
    case 3:
        {
        double lin_alg;
        cout<<"New Linear Algebra mark: ";
        checked_double_input(lin_alg,0.0,100.0);
        stud.marks_ptr()->set_lin_alg(lin_alg);
        }
        break;
    case 4:
        {
        double ml;
        cout<<"New Machine Learning mark: ";
        checked_double_input(ml,0.0,100.0);
        stud.marks_ptr()->set_ml(ml);
        }
        break;
    case 5:
        return;
        break;
    
    default:
    cout<<"Invalid input\n";
        break;
    }

   }   



}

