#pragma once
#include <iostream>
#include <string>
// simple struct to hold name-password-filename entries for schools
struct School_entry
{
    std::string name;
    std::string password;
    std::string filename;
};

//---------------------------------------------------------------------

std::istream &operator>>(std::istream &is, School_entry &s);

//---------------------------------------------------------------------

std::ostream &operator<<(std::ostream &os, const School_entry &s);
