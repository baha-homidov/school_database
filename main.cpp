#include <iostream>
#include <algorithm>
#include <fstream>
#include "main_menu.h"
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





