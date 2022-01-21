#include <iostream>
#include <algorithm>
#include "student.h"
#include "school.h"
using namespace std;











int main(){
  try{
  School my_school;
  my_school.input_data();




  }
  catch(exception& e)
  {
  cerr<<e.what()<<endl;
  return -1;
  }


}





