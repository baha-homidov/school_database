#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "student.h"
#include "date.h" 
#include "helper_functions.h"



using namespace std;

bool comp_name(Student a, Student b){     //helper function to compare to name of two Students
    return a.get_name()<b.get_name();        //used for School::sort_by_name()
}

//*********************************************************************************************************

bool comp_id(Student a, Student b){     //helper function to compare to name of two Students
    return a.get_id()<b.get_id();        //used for School::sort_by_name()
}

//*********************************************************************************************************

class Id_search{    //function class to check if School has a student with similar id number
   int id_number;
public:
   Id_search(int id) : id_number(id) {}
   bool operator()(const Student& s) const { return id_number==s.get_id(); }
};

//*********************************************************************************************************


class Name_search{    //function class to check if School has a student with similar name
   string name;
public:
   Name_search(string nname) : name(nname) {}
   bool operator()(const Student& s) const { return name==s.get_name(); }
};

//*********************************************************************************************************





class School{
    vector<Student> students_list;

public:
    void sort_by_name();  //sort the students in student_list by names
    void sort_by_id();    //sort the student in student_list by id numbers
    void fill_from_file(string file_name);    //fill the students_list vector from a text file
    void input_data();  //input loop to add students to student_list from user input
    void output_all(ostream& os);   //output all the students int studets_list to ostream
    void print(std::ostream& os);    //print out all the student formatted for readabilty
    void save_as_file(string filename);   //save data to a text file
    void search_by_id(int id_num);       //search for student with given id_num in students_list
    void search_by_name(string name);    //search for student with given id_num in students_list
    void delete_stud(int id_num);        //delete a  student by ID number
    void clear();                   //delete all the data in students_list
};


//------------------------------------------------------------------------------------------------------------

void School::input_data(){   //input loop to add students to student_list from user input
    int student_num;
    cout<<"Number of students you want to input: ";
    cin>>student_num;
    while(cin.fail())    //check for a non-digit input
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Bad entry.  Enter a NUMBER: ";
        cin >> student_num;
    }
    for(int i=0; i<student_num; ++i)  //input loop
    {
    
    string name; 
    string major;
    int id_number=students_list.size()+1;    //initalize ID number according to student_list
    //birth date variables
    int birth_month;
    int birth_day;
    int birth_year;
    //Enrollment date variables
    int enroll_month;
    int enroll_day;
    int enroll_year;
    cout<<"Student "<<i+1<<'\n';
    cout<<"New entry. ID number: "<<id_number<<'\n';
    cin.ignore();
    cout<<"Input full name: ";
    
    getline(cin,name);
    cout<<"Input major: ";
    
    getline(cin,major);
    cout<<"Input birthday: \nMonth: ";
    while(true){    //keep asking for valid input
        cin>>birth_month;
        while(cin.fail())    //check for a non-digit input
        {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Bad entry.  Enter a NUMBER: ";
        cin >> birth_month;
        }
        if(birth_month<13&&birth_month>0) break;
        else cout<<"Month should be in 1-12 range.\nMonth: ";
    }
    cout<<"Day: ";
    while(true){
        cin>>birth_day;
        while(cin.fail())    //check for a non-digit input
        {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Bad entry.  Enter a NUMBER: ";
        cin >> birth_day;
        }
        if(birth_day<32&&birth_day>0) break;
        else cout<<"Day should be in 1-31 range.\nDay:";
    }
    cout<<"Year: ";
    while(true){
        cin>>birth_year;
         while(cin.fail())    //check for a non-digit input
        {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Bad entry.  Enter a NUMBER: ";
        cin >> birth_year;
        }
        if(birth_year<2022&&birth_year>1900) break;
        else cout<<"Year should be in 1900-2025 range.\nYear: ";
    }
    cout<<"Input enrollment date: \n Month: ";
    while(true){    //keep asking for valid input
        cin>>enroll_month;
        while(cin.fail())    //check for a non-digit input
        {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Bad entry.  Enter a NUMBER: ";
        cin >> enroll_month;
        }
        if(enroll_month<13&&enroll_month>0) break;
        else cout<<"Month should be in 1-12 range.\nMonth: ";
    }
    cout<<"Day: ";
    while(true){
        cin>>enroll_day;
        while(cin.fail())    //check for a non-digit input
        {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Bad entry.  Enter a NUMBER: ";
        cin >> enroll_day;
        }
        if(enroll_day<32&&enroll_day>0) break;
        else cout<<"Day should be in 1-31 range.\nDay:";
    }
    cout<<"Year: ";
    while(true){
        cin>>enroll_year;
        while(cin.fail())    //check for a non-digit input
        {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Bad entry.  Enter a NUMBER: ";
        cin >> enroll_year;
        }
        if(enroll_year<2023&&enroll_year>1899) break;
        else cout<<"Year should be in 1900-2025 range.\nYear: ";
    }
    students_list.push_back(Student(id_number,name,major,{Month(birth_month),birth_day,birth_year},{Month(enroll_month),enroll_day,enroll_year}));
    }
}

//------------------------------------------------------------------------------------------------------------------------

void School::output_all(ostream& os){    //output all the students int studets_list to ostream
for(int i=0; i<students_list.size(); ++i){
    os<<students_list[i];
    if(i<(students_list.size()-1))os<<"----\n";
}
}

//------------------------------------------------------------------------------------------------------------------------


void School::fill_from_file(string file_name)   //fill the students_list vector from a text file
{
  std::ifstream ifs {file_name};
  while(!ifs.eof()){
      string id_prefix, name_prefix, birth_prefix, major_prefix, enroll_prefix, end_data;
      int id_number;
      string full_name;
      string major;
      Date birth_date;
      Date enroll_date;
      ifs>>id_prefix>>id_number;
      ifs>>name_prefix>>std::ws;
      getline(ifs,full_name);     //getline because name can consist of multiple names
      ifs>>birth_prefix>>birth_date;
      ifs>>major_prefix>>std::ws;
      getline(ifs,major);     //getline because a major name can consist of multiple names
      ifs>>enroll_prefix>>enroll_date;
      ifs>>end_data;
      students_list.push_back(Student(id_number,full_name,major,birth_date,enroll_date));
  }
}

//------------------------------------------------------------------------------------------------

void School::print(std::ostream& os)  //print out all the student formatted for readabilty
{      
   cout<<"Number of students: "<<students_list.size()<<'\n'
   <<"************************************\n************************************\n";
   for(int i=0; i<students_list.size();++i){
       os<<"Student №"<<i+1<<'\n';
       students_list[i].symbolic_print(os);
       os<<"----\n";
   }
}

//------------------------------------------------------------------------------------------------------------------------

void School::sort_by_name(){   //sort the students in student_list by names
    if(students_list.size()<2) return; //don't do sorting if students_list's size is smaller than 2
    sort(students_list.begin(),students_list.end(),comp_name);
}

//------------------------------------------------------------------------------------------------------------------------

void School::sort_by_id(){   //sort the student in student_list by id numbers
    if(students_list.size()<2) return; //don't do sorting if students_list's size is smaller than 2
    sort(students_list.begin(),students_list.end(),comp_id);
}


void School::save_as_file(string filename){   //save data to a text file
    ofstream ofs {filename};
    output_all(ofs);
}

//------------------------------------------------------------------------------------------------------------

void School::search_by_id(int id_num)  //search for student with given id_num in students_list
{       
    auto s=  find_if(students_list.begin(),students_list.end(),Id_search(id_num));
    if(s!=students_list.end()) {
        Student stud=*s;
        cout<<"\nResult:\n";
        stud.symbolic_print(cout);
    }
    else cout<<"No student found with id number: "<<id_num<<".\n";
}

//------------------------------------------------------------------------------------------------------------

void School::search_by_name(string name){
    auto s=  find_if(students_list.begin(),students_list.end(),Name_search(name));
    if(s!=students_list.end()) {
        Student stud=*s;
        cout<<"\nResult:\n";
        stud.symbolic_print(cout);
    }
    else cout<<"No student found with name: "<<name<<".\n";
}

//-------------------------------------------------------------------------------------------------------------

void School::delete_stud(int id_num)  //delete a  student by ID number
{       
    auto s=  find_if(students_list.begin(),students_list.end(),Id_search(id_num));
    if(s!=students_list.end()) {
        students_list.erase(s);
        cout<<"Student ID: "<<id_num<<" deleted.\n";
    }
    else cout<<"No student found with id number: "<<id_num<<".\n";
}

//------------------------------------------------------------------------------------------------------------------------

void School::clear(){
   students_list.clear();    //students
}
