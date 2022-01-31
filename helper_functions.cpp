#include <string>
#include <iostream>
#include <vector>


using namespace std;
std::string int_to_month(int i){      //helper function for Month to convert int to character representation of a month
  vector<std::string>month_print_tbl={"January", "February", "March", "April", "May", "June", 
                             "July", "August", "September", "October", "November", "December"};
  
  if(i<0||12<i) {throw invalid_argument("Bad month index");}

  return month_print_tbl[i-1];
}

//-------------------------------------------------------------------------------------------------------

void checked_int_input(int& num){        //small function which checks and inputs a digit into a given integer
    std::cin>>num;
        while(std::cin.fail()||num<0)    //check for a non-digit input
        {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Bad entry.  Enter a POSITIVE NUMBER: ";
        std::cin >> num;
        }
}


void checked_int_input(int& num, int min, int max){       //range checked checked_int_input()
    while(true){
        std::cin>>num;
        while(std::cin.fail()||num<0)    //check for a non-digit input
        {

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Bad entry. Enter a POSITIVE NUMBER: ";
        std::cin >> num;
        }
        if(num>=min&&num<=max) break;
        else std::cout<<"Bad entry. Input should be in "<<min<<"-"<<max<<" range\nInput: ";
    }
}

//*******************************************************************************


void checked_double_input(double& num){        //small function which checks and inputs a digit into a given integer
    std::cin>>num;
        while(std::cin.fail()||num<0)    //check for a non-digit input
        {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Bad entry.  Enter a POSITIVE NUMBER: ";
        std::cin >> num;
        }
}


void checked_double_input(double& num, double min, double max){       //range checked checked_int_input()
    while(true){
        std::cin>>num;
        while(std::cin.fail()||num<0)    //check for a non-digit input
        {

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Bad entry. Enter a POSITIVE NUMBER: ";
        std::cin >> num;
        }
        if(num>=min&&num<=max) break;
        else std::cout<<"Bad entry. Input should be in "<<min<<"-"<<max<<" range\nInput: ";
    }
}