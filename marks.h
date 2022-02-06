#pragma once
#include <iostream>
#include <stdexcept>
#include "helper_functions.h"

struct Marks
{
   Marks(double cs = 0, double calc = 0, double lin_algebra = 0, double ml = 0); // parameterized constructor
   void print(std::ostream &os);                                                 // print all marks
   double av_mark();                                                             // average marks

   double computer_science = 0;
   double calculus = 0;
   double linear_algebra = 0;
   double machine_learning = 0;
};

std::ostream &operator<<(std::ostream &os, const Marks &m);
std::istream &operator>>(std::istream &is, Marks &m);