#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include "student.h"
#include "date.h"



using namespace std;


class School{
    vector<Student> students_list;
public:
    void input_data();
    void output_all(ostream& os);

};


//------------------------------------------------------------------------------------------------------------

void School::input_data(){
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
    cout<<"Input full name: ";
    cin>>name;
    cout<<"Input major: ";
    cin>>major;
    cout<<"Input id_number: ";
    cin>>id_number;
    
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
    
    students_list.push_back(Student(name,major,id_number,{Month(birth_month),birth_day,birth_year},{Month(enroll_month),enroll_day,enroll_year}));
    }
}

//------------------------------------------------------------------------------------------------------------------------

void School::output_all(ostream& os){
for(int i=0; i<students_list.size(); ++i){
    os<<students_list[i];
}
}

