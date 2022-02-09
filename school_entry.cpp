
#include "school_entry.h"

//---------------------------------------------------------------------

std::istream &operator>>(std::istream &is, School_entry &s)
{
    std::string name_prefix, password_prefix, filename_prefix, break_point;
    is >> name_prefix;
    is.ignore();
    std::getline(is, s.name);
    is >> password_prefix >> s.password;
    is >> filename_prefix >> s.filename;
    is >> break_point;
    return is;
}

//---------------------------------------------------------------------

std::ostream &operator<<(std::ostream &os, const School_entry &s)
{
    const std::string break_point = "---";
    os << "\nname: " << s.name << '\n'
       << "password: " << s.password << '\n'
       << "filename: " << s.filename << '\n'
       << break_point;
    return os;
}
