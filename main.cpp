#include <iostream>
#include <algorithm>
#include <fstream>
#include "student.h"
#include "school.h"
#include "main_menu.h"
#include "helper_functions.h"
using namespace std;





int main(){
  try{
   
  

  
  Menu menu;
  menu.main_menu();
  


  }
  catch(exception& e)
  {
  cerr<<"Error: "<<e.what()<<endl;
  return -1;
  }


}





