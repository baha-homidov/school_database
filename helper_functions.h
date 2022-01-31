//file helper_functions.h
#ifndef HELPER_FUNCTIONS_GUARD
#define HELPER_FUNCTIONS_GUARD
#include <iostream>

std::string int_to_month(int i);

void checked_int_input(int& num);

void checked_int_input(int& num, int min, int max);

void checked_double_input(double& num);

void checked_double_input(double& num, double min, double max);



#endif