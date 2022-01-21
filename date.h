#pragma once
#include <iostream>
#include <vector>
using namespace std;


enum class Month{ 
  //Month enum for symbolic notations
  jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

//------------------------------------------------------------------------------------------------

string int_to_month(int i){      //helper function for Month to convert int to character representation of a month
  vector<string>month_print_tbl={"January", "February", "March", "April", "May", "June", 
                             "July", "August", "September", "October", "November", "December"};
  
  if(i<0||12<i) {throw invalid_argument("Bad month index");}

  return month_print_tbl[i-1];
}

//------------------------------------------------------------------------------------------------

ostream& operator<<(ostream& os, Month m){       //ouput operator for Month
  return os<<int_to_month(int(m));
}


//************************************************************************************************

struct Date{      //Date class to keep dates orginized and check for invalid dates
  Date(Month new_month, int new_day, int new_yer);
  Date();   //default constructor
  friend ostream& operator<<(ostream& os, const Date& d);
  Month month;
  int day;
  int year;
};
//------------------------------------------------------------------------------------------------

Date::Date(Month new_month, int new_day, int new_year){    //parameterized constructor which checks the values
  if(new_day<1 ||new_day>31){throw invalid_argument("Invalid day. Day should be between 1 and 31.");};
  if(new_year<1950||new_year>2025){ throw invalid_argument("Invalid year. Year should be between 1950 and 2010")  ;}
  month=new_month;
  day=new_day;
  year=new_year;
 
}

//------------------------------------------------------------------------------------------------

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


//************************************************************************************************
