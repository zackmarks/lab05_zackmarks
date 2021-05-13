//Zack Marks
//cs32  Lab05   Prof. Wood  W21

#include <iomanip>
#include "psCombo.h"


/* print state data - as aggregate of all incidents in this state */
std::ostream& operator<<(std::ostream &out, const psCombo& PD) {
    out << "State Info: " << PD.getRegionName();
    out << "\nNumber of incidents: " << PD.getNumberOfCases();
    out << std::setprecision(2) << std::fixed;
    out << "\nIncidents with age \n(over 65): " << PD.getCasesOver65();
    out << "\n(19 to 64): " <<PD.getCasesMidAge();
    out << "\n(under 18): " << PD.getCasesUnder18();
    out << "\nIncidents involving fleeing: " << PD.getFleeingCount();
    out << "\nIncidents involving mental illness: " << PD.getNumMentalI();
    out << "\nMale incidents: " << PD.getnumMales() <<  " female incidents: " << PD.getnumFemales();
    out << "\nRacial demographics of state incidents: " << PD.getRacialData();
    return out;
}

//prereq: inci, a pointer to a psData object. represents an individual shooting
//postreq: updates instance vars to include the new shooting
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

