#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include "student.h"
#include "date.h" 



using namespace std;


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
};


//------------------------------------------------------------------------------------------------------------

void School::input_data(){   //input loop to add students to student_list from user input
    int student_num;
    cout<<"Number of students you want to input: ";
    cin>>student_num;
    for(int i=0; i<student_num; ++i)  //input loop
    {
    
    string name; 
    string major;
    int id_number;
    //birth date variables
    int birth_month;
    int birth_day;
    int birth_year;
    //Enrollment date variables
    int enroll_month;
    int enroll_day;
    int enroll_year;
    cout<<"Student "<<i+1<<'\n';
    cout<<"Input id_number: ";
    cin>>id_number;
    cin.ignore();
    cout<<"Input full name: ";
    
    getline(cin,name);
    cout<<"Input major: ";
    
    getline(cin,major);
    cout<<"Input birthday: \nMonth: ";
    cin>>birth_month; 
    if(birth_month<1||birth_month>12) throw invalid_argument("Invalid month index. Index should in be in range 1-12\n");
    cout<<"Day: ";
    cin>>birth_day; if(birth_day<1||birth_day>31) throw invalid_argument("Invalid day index. Index should in be in range 1-31\n");
    cout<<"Year: ";
    cin>>birth_year;
    if(birth_year<1900||birth_year>2025) throw invalid_argument("Invalid day index. Index should in be in range 1900-2025\n");
    
    cout<<"Input enrollment date: \n Month: ";
    cin>>enroll_month; 
    if(enroll_month<1||enroll_month>12) throw invalid_argument("Invalid month index. Index should in be in range 1-12\n");
    cout<<"Day: ";
    cin>>enroll_day;
    if(enroll_day<1||enroll_day>31) throw invalid_argument("Invalid day index. Index should in be in range 1-31\n");
    cout<<"Year: ";
    cin>>enroll_year;
    if(enroll_year<1900||enroll_year>2025) throw invalid_argument("Invalid day index. Index should in be in range 1900-2025\n");
    
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
      ifs>>name_prefix;
      getline(ifs,full_name);     //getline because name can consist of multiple names
      ifs>>birth_prefix>>birth_date;
      ifs>>major_prefix;
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
    sort(students_list.begin(),students_list.end(),
    [](const Student& a, const Student& b)
    { return a.name<b.name; });
}

//------------------------------------------------------------------------------------------------------------------------

void School::sort_by_id(){   //sort the student in student_list by id numbers
    if(students_list.size()<2) return; //don't do sorting if students_list's size is smaller than 2
    sort(students_list.begin(),students_list.end(),
    [](const Student& a, const Student& b)
    { return a.id_number<b.id_number; });
}


void School::save_as_file(string filename){   //save data to a text file
    ofstream ofs {filename};
    output_all(ofs);
}
