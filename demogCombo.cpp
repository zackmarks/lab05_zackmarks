//Zack Marks
//cs32  Lab05   Prof. Wood  W21

#include "demogCombo.h"
#include "demogData.h"
#include <sstream>
#include <string>
#include <assert.h>
#include <iomanip>


//overloads the << operator
std::ostream& operator<<(std::ostream &out, const demogCombo &SD) {
    //out << "Combo Demographic Info: key: " << SD.getRegionName() << endl;
    out << "Combo Info: " << SD.getState() << endl;
    out << "Number of Counties: " << SD.getCountyAmt();// << endl;
    out << " County Demographics Info: comboData, many\n"; 
    out << "Population info:\n";
    out << std::setprecision(2) << std::fixed;
    out << "(over 65): " << SD.getOver65Perc() << "\% and total: " << SD.getOver65() << endl;
    out << "(under 18): " << SD.getUnder18Perc() << "\% and total: " << SD.getUnder18() << endl;
    out << "(under 5): " << SD.getUnder5Perc() << "\% and total: " << SD.getUnder5() << endl;
    out << "Education info: \n";
    out << "(Bachelor or more): " <<SD.getPercWBach() << "\% and total: " << SD.getBachAmt() << endl;    
    out << "(high school or more): " <<SD.getPercWHS() << "\% and total: " << SD.getHSAmt() << endl;
    out << "persons below poverty: " <<SD.getPercBelowPov() << "\% and total: " << SD.getPovAmt() << endl;
    out << "Total population: " << SD.getPop() << endl;
    out << SD.getRaceDemogData() << endl;
    return out;
}

//Pre-req: a pointer to demogData c. c represents a county
//updates each instance var based on c's data.
void demogCombo::addCounty(shared_ptr<demogData> c){
    rdd += c->getRaceDemogData();
    population += c->getPop();
    countyAmt++;

    over65 += c->getOver65();
    under18 += c->getUnder18();
    under5 += c->getUnder5();
    bach += c->getBachAmt();
    hs += c->getHSAmt();
    povAmt += c->getPovAmt();
}
