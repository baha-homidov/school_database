#include "marks.h"

Marks::Marks(std::vector<std::pair<std::string, int>> new_list) : marks_list(new_list)
{
}

//------------------------------------------------------------------------------------------------------

void Marks::print(std::ostream &os)
{ // print all the marks with explanations
    for (std::pair<std::string, int> p : marks_list)
    {
        os << p.first << ": " << p.second << " %\n";
    }
}

//------------------------------------------------------------------------------------------------------

double Marks::av_mark()
{ // calculate the average score
    double marks_sum = 0;
    for (std::pair<std::string, int> p : marks_list)
    {
        marks_sum += p.second;
    }
    return marks_sum / marks_list.size();
}

//------------------------------------------------------------------------------------------------------

std::ostream &operator<<(std::ostream &os, const Marks &m)
{ // output all the marks
    const std::string end_mark = "xxx";
    for (std::pair<std::string, int> p : m.marks_list)
    {
        os << "\nsubj_name: " << p.first
           << "\nmark: " << p.second ;
    }
    os <<  '\n'<<end_mark ;

    return os;
}

//------------------------------------------------------------------------------------------------------

std::istream &operator>>(std::istream &is, Marks &m)
{

    const std::string end_mark = "xxx";
    while (true)
    { // get arbitrary entries until breakpoint is found

        std::pair<std::string, int> new_mark;
        std::string subj_prefix; // prefix to check for the end of the input loop
        std::string score_prefix;
        is >> subj_prefix;

        if (subj_prefix == end_mark)
            return is;
        else
        {
            is.ignore();
            std::getline(is, new_mark.first);
        };
        is >> score_prefix >> new_mark.second;
        m.marks_list.push_back(new_mark);
    }
    return is;
}

//------------------------------------------------------------------------------------------------------

// Marks::Marks(){
//     computer_science=0;
//     calculus=0;
//     linear_algebra=0;
//     machine_learning=0;
// }