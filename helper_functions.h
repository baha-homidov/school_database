// file helper_functions.h
#ifndef HELPER_FUNCTIONS_GUARD
#define HELPER_FUNCTIONS_GUARD
#include <iostream>

std::string int_to_month(int i);

int checked_int_input();

int checked_int_input(int min, int max);

double checked_double_input();

double checked_double_input(double min, double max);

#endif