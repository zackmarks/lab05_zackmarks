#include "demogCombo.h"
#include "demogData.h"
#include <sstream>
#include <string>
#include <assert.h>
#include <iomanip>

//add member functions here

/* print state data - as aggregate of all the county data */
/*std::ostream& operator<<(std::ostream &out, const demogCombo& ComboD) {
    return out;
}*/
std::ostream& operator<<(std::ostream &out, const demogCombo &SD) {
    out << "State Info: " << SD.getStateName() << endl;
    out << "Number of Counties: " << SD.getCountyAmt() << endl;
    out << "Population info:\n";
    out << std::setprecision(2) << std::fixed;
    out << "(over 65): " << SD.getOver65Perc() << "\% and total: " << SD.getOver65() << endl;
    out << "(under 18): " << SD.getUnder18Perc() << "\% and total: " << SD.getUnder18() << endl;
    out << "(under 5): " << SD.getUnder5Perc() << "\% and total: " << SD.getUnder5() << endl;
    out << "Education info:\n";
    out << "(Bachelor or more): " <<SD.getPercWBach() << "\% and total: " << SD.getBachAmt() << endl;    
    out << "(high school or more): " <<SD.getPercWHS() << "\% and total: " << SD.getHSAmt() << endl;
    out << "persons below poverty: " <<SD.getPercBelowPov() << "\% and total: " << SD.getPovAmt() << endl;
    out << "Total population: " << SD.getPop() << endl;
    out << "community racial demographics: Racial Demographics Info:\n";
    out << SD.getRaceDemogData() << endl;
    return out;
}
void demogCombo::addCounty(shared_ptr<demogData> c){
	//if(c->getStateName() != this->getName())
	//	return;
	//at this point, the county is in the state. just adds the amount of each data field

	countyAmt++;
    //this->addOver65(c->getOver65());
	/*over65 += c->getOver65();
	under18 += c->getUnder18();
	under5 += c->getUnder5();
	population += c->getPop();
	bach += c->getBachAmt();
	hs += c->getHSAmt();
	pov += c->getPovAmt();*/
    rdd += c->getRaceDemogData();
    population += c->getPop();

    POV += c->getPovAmt();
    OVER65 += c->getOver65();
    UNDER18 += c->getUnder18();
    UNDER5 += c->getUnder5();
    BACH += c->getBachAmt();
    HS += c->getHSAmt();
    //cout << endl<< "added pov: " << c->getPovAmt() << " -- tot pov: " << pov;

}