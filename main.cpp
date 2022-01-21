#include <iostream>
#include <algorithm>
#include <fstream>
#include "student.h"
#include "school.h"
using namespace std;











int main(){
  try{
  School my_school;
  ofstream ofs {"file.txt"};
  my_school.input_data();
  my_school.output_all(ofs);




  }
  catch(exception& e)
  {
  cerr<<e.what()<<endl;
  return -1;
  }


}





