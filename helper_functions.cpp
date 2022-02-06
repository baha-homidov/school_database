#include <string>
#include <iostream>
#include <vector>

std::string int_to_month(int i)
{ // helper function for Month to convert int to character representation of a month
    std::vector<std::string> month_print_tbl = {"January", "February", "March", "April", "May", "June",
                                                "July", "August", "September", "October", "November", "December"};

    if (i < 0 || 12 < i)
    {
        throw std::invalid_argument("Bad month index");
    }

    return month_print_tbl[i - 1];
}

//-------------------------------------------------------------------------------------------------------

int checked_int_input()
{
    int num;
    std::cin >> num;
    while (std::cin.fail() || num < 0) // check for a non-digit input
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Bad entry.  Enter a POSITIVE NUMBER: ";
        std::cin >> num;
    }
    return num;
}

//-------------------------------------------------------------------------------------------------------

int checked_int_input(int min, int max)
{
    int num;
    while (true)
    {
        std::cin >> num;
        while (std::cin.fail() || num < 0) // check for a non-digit input
        {

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Bad entry. Enter a POSITIVE NUMBER: ";
            std::cin >> num;
        }
        if (num >= min && num <= max)
            break;
        else
            std::cout << "Bad entry. Input should be in " << min << "-" << max << " range\nInput: ";
    }
    return num;
}

//*******************************************************************************

double checked_double_input()
{
    double num;
    std::cin >> num;
    while (std::cin.fail() || num < 0) // check for a non-digit input
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Bad entry.  Enter a POSITIVE NUMBER: ";
        std::cin >> num;
    }
    return num;
}

double checked_double_input(double min, double max)
{
    double num;
    while (true)
    {
        std::cin >> num;
        while (std::cin.fail() || num < 0) // check for a non-digit input
        {

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Bad entry. Enter a POSITIVE NUMBER: ";
            std::cin >> num;
        }
        if (num >= min && num <= max)
            break;
        else
            std::cout << "Bad entry. Input should be in " << min << "-" << max << " range\nInput: ";
    }
    return num;
}