#include "marks.h"


Marks::Marks(double cs,double calc,double lin_algebra,double ml){    //constructor
computer_science=cs;
calculus=calc;
linear_algebra=lin_algebra;
machine_learning=ml;
}

//------------------------------------------------------------------------------------------------------

void Marks::print(ostream& os){              //print all the marks with explanations
    os<<"Computer science: "<<computer_science<<" points.\n"
      <<"Calculus: "<<calculus<<" points.\n"
      <<"Linear algebra: "<<linear_algebra<<" points.\n"
      <<"Machine learning: "<<machine_learning<<" points.\n";
    }

//------------------------------------------------------------------------------------------------------

double Marks::av_mark(){         //calculate the average score
   return double (computer_science+calculus+linear_algebra+machine_learning)/4;
}

//------------------------------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Marks& m){        //output all the marks
    os<<m.computer_science<<' '<<m.calculus<<' '<<m.linear_algebra<<' '<<m.machine_learning<<'\n';
    return os;
} 

//------------------------------------------------------------------------------------------------------

istream& operator>>(std::istream& is, Marks& m){
    double cs;
    double calc;
    double lin_algebra;
    double ml;
    is>>cs>>calc>>lin_algebra>>ml;
    if((cs<1||cs>100)||
       (calc<1||calc>100)||
       (lin_algebra<1||lin_algebra>100)||
       (ml<1||ml>100)) throw std::invalid_argument("Marks cannot be lower than 0 or higher than 100\n");
    m.computer_science=cs;
    m.calculus=calc;
    m.linear_algebra=lin_algebra;
    m.machine_learning=ml;
    return is;
}

//------------------------------------------------------------------------------------------------------

Marks::Marks(){
    computer_science=0;
    calculus=0;
    linear_algebra=0;
    machine_learning=0;
}