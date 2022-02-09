#pragma once
#include <iostream>
#include <stdexcept>
#include "helper_functions.h"
#include <vector>

struct Marks
{
   Marks() { return; }
   Marks(std::vector<std::pair<std::string, int>> new_list); // explicit constructor
   void print(std::ostream &os);                                                 // print all marks
   double av_mark();                                                             // average marks

   std::vector<std::pair<std::string, int>> marks_list;
   
};

//---------------------------------------------------------------------

std::ostream &operator<<(std::ostream &os, const Marks &m);
std::istream &operator>>(std::istream &is, Marks &m);