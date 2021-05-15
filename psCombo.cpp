//Zack Marks
//cs32  Lab05   Prof. Wood  W21

#include <iomanip>
#include "psCombo.h"


/* print state data - as aggregate of all incidents in this state */
std::ostream& operator<<(std::ostream &out, const psCombo& PD) {
    out << "key: " << PD.getRegionName();
    out << "\nState Info: " << PD.printState();
    out << "\nNumber of incidents: " << PD.getNumberOfCases();
    out << std::setprecision(2) << std::fixed;
    out << "\nIncidents with age \n(over 65): " << PD.getCasesOver65() << " %: " << PD.getOver65Perc();
    out << "\n(19 to 64): " <<PD.getCasesMidAge() << " %: " << PD.getMidAgePerc();
    out << "\n(under 18): " << PD.getCasesUnder18() << " %: " << PD.getUnder18Perc();
    out << "\nIncidents involving fleeing: " << PD.getFleeingCount() << " %: " << PD.getFleeingPerc();
    out << "\nIncidents involving mental illness: " << PD.getNumMentalI() << " %: " << PD.getMentalIPerc();
    out << "\nMale incidents: " << PD.getnumMales() <<  " female incidents: " << PD.getnumFemales();
    out << "\nRacial demographics of state incidents: " << PD.getRacialData();
    return out;
}

/*
key: KeyAsianVictim
State Info: AK, AR, CA, CO, FL, GA, HI, ID, KY, LA, MD, MI, MN, MO, MS, NC, NJ, NV, NY, OH, OK, PA, SC, SD, TN, TX, UT, VA, WA, WI, WV, total states: 31
Number of incidents: 104
Incidents with age 
(over 65): 0 %: 0.00
(19 to 64): 93 %: 89.42
(under 18): 11 %: 10.58
Incidents involving fleeing: 21 %: 20.19
Incidents involving mental illness: 26 %: 25.00
Male incidents: 100 female incidents: 4
Racial demographics of state incidents: Racial Demographics Info: 
% American Indian and Alaska Native count: 0
% Asian American percent: 100.00 count: 104
% Black/African American count: 0
% Hispanic or Latinx count: 0
% Native Hawaiian and Other Pacific Islander count: 0
% Two or More Races count: 0
% White (inclusive) count: 0
% White (nonHispanic) count: 0
total Racial Demographic Count: 104
*/

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

