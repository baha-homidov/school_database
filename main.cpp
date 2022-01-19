#include <iostream>
#include <algorithm>
using namespace std;

class Student{
public:
    Student(string new_name, int new_number, int new_birth_date, string new_major);
    void set_name(string name);
    void set_id_number(int number);  
    void set_birth_date(int birth_date);
    void set_major(string major);
  
    string name;
    int id_number;
    int birth_date;
    string major;

};
//************************************************************************************************

Student::Student(string new_name, int new_number, int new_birth_date, string new_major){
    name=new_name;
    id_number=new_number;
    birth_date=new_birth_date;
    major=new_major;
};


int main(){
  Student stud("Abdukadu Olimov", 2001, 20010602, "computer science");
  
}





