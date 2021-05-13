#include <iomanip>
#include "psCombo.h"



/* print state data - as aggregate of all incidents in this state */


std::ostream& operator<<(std::ostream &out, const psCombo& PD) {
    out << "State Info: " << PD.printState();
    //out << "\nNumber of incidents: " << PD.getNumberOfCases();
    out << std::setprecision(2) << std::fixed;
    //fill in
    return out;
}

void psCombo::addIncident(shared_ptr<psData> inci){
	population++;
	numMentalI += inci->getMI();
	fleeCount += inci->getFlee();

	if(inci->getAge() >= 65)
    	over65++;
	else if(inci->getAge() <= 18)
    	under18++;
	else if(inci->getAge() != -1)
    	midAge++;

	if(inci->getGender() == "M")
    	male++;
	else if(inci->getGender() == "F")
    	female++;


	string r = inci->getRace();
    if(r == "W"){
        rdd.addWhiteCount(1);
        rdd.addWhiteNHCount(1);
    }
    else if(r == "A")
        rdd.addAsianCount(1);
    else if(r == "B")
    	rdd.addBlackCount(1);
    else if(r == "H")
    	rdd.addLatinxCount(1);
	else if (r == "N")
    	rdd.addFirstNationCount(1);
	else
    	rdd.addOtherCount(1);

	rdd.addCommunityCount(1);
}

