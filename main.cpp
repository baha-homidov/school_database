#include <iostream>
#include <algorithm>
#include <fstream>
#include "student.h"
#include "school.h"
using namespace std;











int main(){
  try{
  School my_school;
  my_school.fill_from_file("file.txt");
  my_school.sort_by_name();
  my_school.print(cout);
 



  }
  catch(exception& e)
  {
  cerr<<"Error: "<<e.what()<<endl;
  return -1;
  }


}





