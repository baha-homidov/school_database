#include "date.h"
#include "helper_functions.h"



//------------------------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, Month m){       //ouput operator for Month
  return os<<int(m);
}


//------------------------------------------------------------------------------------------------


Date::Date(Month new_month, int new_day, int new_year):
month(new_month),
day(new_day),
year(new_year)
{}



Date::Date(){    //default constructor
  month=Month::jan;
    day=1;
    year=2000;
}

//------------------------------------------------------------------------------------------------


std::ostream& operator<<(std::ostream& os, const Date& d){
os<<d.month<<' '<<d.day<<' '<<d.year;
return os;
}

//------------------------------------------------------------------------------------------------

std::istream &operator>>(std::istream& is, Date& d){
  int month, day, year;
  is>>month>>day>>year;
  if(month<1||month>12) throw std::invalid_argument("Invalid month index. Month shoould be in 1-12 range \n");
  if(day<1||month>31) throw std::invalid_argument("Invalid day index. Day shoould be in 1-31 range.\n");
  if(year<1900||year>2030) throw std::invalid_argument("Invalid year index. Year shoould be in range 1900-2030,\n");
  d.month=Month(month);
  d.day=day;
  d.year=year;
  return is;
}

//------------------------------------------------------------------------------------------------

void Date::symbolic_print(std::ostream& os){
  os<<int_to_month(int(month))<<" "<<day<<" "<<year;
}

//************************************************************************************************
