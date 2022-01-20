#include <iostream>
#include <algorithm>
#include "student.h"
using namespace std;











int main(){
try{
Student student("Mirzobakhtiyor Homidov", "Ai", 19911192, {Month(6),2,2001}, {Month(9),2, 2021});
cout<<student;
}

catch(exception& e)
{
  cerr<<e.what()<<endl;
  return -1;
}


}





