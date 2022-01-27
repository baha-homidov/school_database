#pragma once
#include <iostream>



void checked_int_input(int& num){        //small function which checks and inputs a digit into a given integer
    cin>>num;
        while(cin.fail()||num<0)    //check for a non-digit input
        {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Bad entry.  Enter a POSITIVE NUMBER: ";
        cin >> num;
        }
}


void checked_int_input(int& num, int min, int max){       //range checked checked_int_input()
    while(true){
        cin>>num;
        while(cin.fail()||num<0)    //check for a non-digit input
        {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Bad entry. Enter a POSITIVE NUMBER: ";
        cin >> num;
        }
        if(num>=min&&num<=max) break;
        else cout<<"Bad entry. Input should be in "<<min<<"-"<<max<<" range\nInput: ";
    }
}

