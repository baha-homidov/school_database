//file date.h
#ifndef DATE_GUARD
#define DATE_GUARD
#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <stdexcept>




enum class Month{ 
  //Month enum for symbolic notations
  jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};


//************************************************************************************************

struct Date{      //Date class to keep dates orginized and check for invalid dates
  Date(Month new_month, int new_day, int new_yer);
  Date();   //default constructor
  void symbolic_print(std::ostream& os);
  Month month;
  int day;
  int year;
};
//------------------------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, const Date& d);   
std::istream& operator>>(std::istream& is, Date& d);

#endif