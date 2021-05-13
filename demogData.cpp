//Zack Marks
//cs32  Lab05   Prof. Wood  W21

#include "demogData.h"
#include <sstream>
#include <iomanip>

//overloading << operator to print desired data
std::ostream& operator<<(std::ostream &out, const demogData &DD) {
    out << "County Demographics Info: " << DD.getName() << ", " << DD.getStateName();
    out << std::setprecision(2) << std::fixed;
    out << " total population: " << DD.getPop();
    out << "\nPopulation info: \n(\% over 65): " << DD.getOver65Perc();
    out <<  " Count: " << DD.getOver65();
    out << "\n(\% under 18): " << DD.getUnder18Perc();
    out <<  " Count: " << DD.getUnder18();
    out << "\n(\% under 5): " << DD.getUnder5Perc();
    out <<  " Count: " << DD.getUnder5();
    out << "\nEducation info:";
    out << "\n(Bachelor or more): " << DD.getPercWBach();
    out << " Count: " << DD.getBachAmt();
    out << "\n(high school or more): " << DD.getPercWHS();
    out << " Count: " << DD.getHSAmt();
    out << "\npersons below poverty: " << DD.getPercBelowPov();
    out << " Count: " << DD.getPovAmt();  
    return out;
}


/*#include "demogData.h"
#include <sstream>
#include <iomanip>

//print county demographic data 
std::ostream& operator<<(std::ostream &out, const demogData &DD) {
    //out << "County Demographics Info: " << DD.getRegionName() << ", " << DD.getState();
    out << std::setprecision(2) << std::fixed;
    //fill in
    return out;
}
*/