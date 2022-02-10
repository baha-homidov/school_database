#include <iostream>
#include <algorithm>
#include <fstream>
#include "main_menu.h"
#include "marks.h"

int main()
{
  try
  {
    Menu::main_menu();
    }

  catch (std::exception &e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
    return -1;
  }
}

// std::ifstream ifs{"mark2"};

// Marks marks;
// ifs >> marks;
// std::string s = "test";
// Student stud(1, s, s, Date(Month(2), 2,1999), Date( Month(1), 1,2005), marks);
// stud.symbolic_print(std::cout);