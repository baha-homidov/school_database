#pragma once
#include <iostream>
#include <stdexcept>
#include "helper_functions.h"


using namespace std;



class Marks{
private:
   double computer_science=0;
   double calculus=0;
   double linear_algebra=0;
   double machine_learning=0;
public:
   Marks();  //default constructor
   //setdata fucntions
   void set_cs(double cs){computer_science=cs;}
   void set_calculus(double calc){calculus=calc;}
   void set_lin_alg(double lin_alg){linear_algebra=lin_alg;}
   void set_ml(double ml){machine_learning=ml;}
   //- - - - - - - - - - - - - - - - - - - - - - -
   void print(ostream& os);  //print all marks
   double av_mark();  // average marks
   Marks(double cs,double calc,double lin_algebra,double ml);   //parameterized constructor
   friend ostream& operator<<(ostream& os, const Marks& m);   
   friend istream& operator>>(std::istream& is, Marks& m);  
};