//Zack Marks
//cs32  Lab05   Prof. Wood  W21

#include <sstream>
#include "psData.h"

/* print police data - fill in*/
std::ostream& operator<<(std::ostream &out, const psData &PD) {
	out << std::setprecision(2) << std::fixed;
    out << "Police Shooting Info: " << PD.getState();
    out << "\nPerson name: " << PD.getName();
    out << "\nAge: " << PD.getAge();
    out << "\nGender: " << PD.getGender();
    out << "\nRace: " << PD.getRace();
    out << "\nMental Illness: " << PD.getMI();
    out << "\nFleeing: " << PD.getFlee();
    return out;
}
