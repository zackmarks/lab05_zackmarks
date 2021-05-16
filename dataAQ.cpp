//Zack Marks
//cs32  Lab05   Prof. Wood  W21

#include "dataAQ.h"
#include "demogData.h"
#include "psData.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

dataAQ::dataAQ() {}

//for later
string makeKeyExample(shared_ptr<demogData> theData){
	string theKey = "Key";
	if(theData->getPercBelowPov() < 10)
		theKey += "BelowPovLessTenPer";
	else if(theData->getPercBelowPov() < 20)
		theKey += "BelowPovLessTwentyPer";
	else if(theData->getPercBelowPov() < 30)
		theKey += "BelowPovLessThirtyPer";
	else
		theKey += "BelowPovAboveThirtyPer";

	return theKey;
}

//for later
string makeKeyExample(shared_ptr<psData> theData) {
	string theKey = "Key";

	if(theData->getRace() == "W")
		theKey += "WhiteVictim";
	else if(theData->getRace() == "A")
		theKey += "AsianVictim";
	else if(theData->getRace() == "H")
		theKey += "HispanicVictim";
	else if(theData->getRace() == "N")
		theKey += "NativeAmericanVictim";
	else if(theData->getRace() == "B")
		theKey += "AfricanAmericanVictim";
	else if(theData->getRace() == "O")
		theKey += "OtherRaceVictim";
	else
		theKey += "RaceUnspecifiedVictim";
  return theKey;
}

//for later
//swtich to a function parameter
void dataAQ::createComboDemogDataKey(std::vector<shared_ptr<demogData> >& theData) {
	string key = "";
	for (auto county : theData){
		key = makeKeyExample(county);
		if(allComboDemogData.count(key) == 0){
			demogCombo newKey(key, county->getStateName());
			auto keyPtr = make_shared<demogCombo>(newKey);
			allComboDemogData[key] = keyPtr;
		}
		allComboDemogData[key]->addCounty(county);
		allComboDemogData[key]->addState(county->getState());
	}
	//cout << "\nDemogSize: "<<allComboDemogData.size() << endl;

	/*for (auto combo : allComboDemogData){
		cout << *(combo).second << endl;
	}*/
}

//for later
void dataAQ::createComboPoliceDataKey(std::vector<shared_ptr<psData> >& theData) {
//fill in
	string key = "";
	for(auto inci : theData){
		key = makeKeyExample(inci);
		if(allComboPoliceData.count(key) == 0){
			psCombo newKey(key, inci->getState());
			auto keyPtr = make_shared<psCombo>(newKey);
			allComboPoliceData[key] = keyPtr;
		}
		allComboPoliceData[key]->addIncident(inci);
		allComboPoliceData[key]->addState(inci->getState());
	}
	//cout << "\nPSSize: "<<allComboPoliceData.size() << endl;
	for (auto group : allComboPoliceData){
		//cout << *(group).second << endl << endl;
	}

}


void dataAQ::createComboDemogData(std::vector<shared_ptr<demogData> >&  theData) {
    string stateOfCounty = "";

    /*for each county, find the state that its in. if its state is not already 
    created in the map, create a new state. then adds the county to the state*/
    for(auto county : theData){
        stateOfCounty = county->getStateName();
        if(allComboDemogData.count(stateOfCounty) == 0){
            demogCombo newState(stateOfCounty, stateOfCounty);
            auto statePtr = make_shared<demogCombo>(newState);
            allComboDemogData[stateOfCounty] = statePtr;
        }
        allComboDemogData[stateOfCounty]->addCounty(county);
    }
}

void dataAQ::createComboPoliceData(std::vector<shared_ptr<psData> >& theData) {
    string stateOfIncident = "";

    /*for each incident, find the state that its in. if its state is not already 
    created in the map, create a new state. then adds the incident to the state*/
    for(auto incident : theData){
        stateOfIncident = incident->getState();
        if(allComboPoliceData.count(stateOfIncident) == 0){
            psCombo newState(stateOfIncident, stateOfIncident);
            auto statePtr = make_shared<psCombo>(newState);
            allComboPoliceData[stateOfIncident] = statePtr;
        }
        allComboPoliceData[stateOfIncident]->addIncident(incident);
    }
}

//predicate comparison for poverty rates
bool comparePovRates(shared_ptr<demogCombo> i, shared_ptr<demogCombo> j){
    return (i->getPercBelowPov() > j->getPercBelowPov());
}

//predicate comparison for shootings
bool comparePSRates(shared_ptr<psCombo> i, shared_ptr<psCombo> j){
    //due to inheritance, population stores the shooting data. that is why i'm using getPop
    return (i->getPop() > j->getPop());
}

//sort and report the top ten states in terms of number of police shootings 
void dataAQ::reportTopTenStatesPS() {
    std::cout << std::setprecision(2) << std::fixed;
    //add all mapped data to a vector, making it easier to sift through
    vector<shared_ptr<psCombo>> stateVec;
    for(auto inci : allComboPoliceData){
        stateVec.push_back(inci.second);
    }
    //sort using my defined predicate function
    sort(stateVec.begin(), stateVec.end(), comparePSRates);
    
    //print data
    for(int i = 0 ; i < 10 ; i++){
        cout << stateVec[i]->getStateName();
        cout << "\nTotal population: " << allComboDemogData[stateVec[i]->getState()]->getPop();
        cout << "\nPolice shooting incidents: " << stateVec[i]->getNumberOfCases();
        cout << "\nPercent below poverty: " << allComboDemogData[stateVec[i]->getState()]->getPercBelowPov();
        cout << endl;
    }
    cout << "\n**Full listings for top 3 Below Poverty data & the associated police shooting data for top 3:\n";
    for(int i = 0 ; i < 3 ; i++){
        cout << *(allComboDemogData[stateVec[i]->getState()]) << endl;
        cout << *(allComboPoliceData[stateVec[i]->getState()]) << endl;
    }
}

//sort and report the top ten states with largest population below poverty 
void dataAQ::reportTopTenStatesBP() {
    std::cout << std::setprecision(2) << std::fixed;

    //put to a vector
    vector<shared_ptr<demogCombo>> stateVec;
    for(auto state : allComboDemogData){
      stateVec.push_back(state.second);
    }

    //sort using predicate
    sort(stateVec.begin(), stateVec.end(), comparePovRates);
    //print
    cout << "Top ten states sorted on Below Poverty data & the associated police shooting data:\n";
    for(int i = 0 ; i < 10 ; i++){
        cout << stateVec[i]->getName();
        cout << "\nTotal population: " << stateVec[i]->getPop();
        cout << "\nPercent below poverty: " << stateVec[i]->getPercBelowPov();//ISSUE HERE
        cout << "\nPolice shooting incidents: " << allComboPoliceData[stateVec[i]->getName()]->getNumberOfCases();
        cout << endl;
    }
    cout << "\n**Full listings for top 3 Below Poverty data & the associated police shooting data for top 3:\n";
    for(int i = 0 ; i < 3 ; i++){
        cout << *(allComboDemogData[stateVec[i]->getState()]) << endl;
        cout << *(allComboPoliceData[stateVec[i]->getState()]) << endl;
    }
}

/* print all combo data */
std::ostream& operator<<(std::ostream &out, const dataAQ &theAnswers) {
  out << "Combo Demographic Info: ";
  for (auto const& entry : theAnswers.allComboDemogData) {
      out << "key: " << entry.first << endl;
      out << *(entry.second) << "\n";
  }

  for (auto const& entry : theAnswers.allComboPoliceData) {
      out << "key: " << entry.first << endl;
      out << *(entry.second) << "\n";
  }
  return out;
}


//test function that only prints alaska's data
void dataAQ::printAK(){
    cout <<endl<< *(allComboDemogData["AK"]);
    cout <<endl<< *(allComboPoliceData["AK"]);
}

//test function
void dataAQ::printAsian(){
    cout << endl << *(allComboDemogData["KeyAsianVictim"]);
    cout << endl << *(allComboPoliceData["KeyAsianVictim"]);
}



/*

testAgDemog (0.0/20.0)
Test Failed: 'Testing aggregate demographic data\nPASSED: subReport1\nPASSED: subReport2\nPASSED: subReport3' != 'Testing aggregate demographic data\n   

FAILED: subReport1\n     
Expected: 
Combo Info: AK, AL, AR, CA, CO, CT, FL, GA, HI, IA, ID, IL, IN, KS, KY, LA, MA, MD, ME, MI, MN, MO, MS, MT, NC, ND, NE, NH, NJ, NM, NV, NY, OH, OK, OR, PA, RI, SD, TN, TX, UT, VA, VT, WA, WI, WY, total states: 46\nNumber of Counties: 431 County Demographics Info: comboData, many\n 
Actual: 
Combo Demographic Info: key: KeyBelowPovLessTenPer\nCombo Info: AK, AL, AR, CA, CO, CT, FL, GA, HI, IA, ID, IL, IN, KS, KY, LA, MA, MD, ME, MI, MN, MO, MS, MT, NC, ND, NE, NH, NJ, NM, NV, NY, OH, OK, OR, PA, RI, SD, TN, TX, UT, VA, VT, WA, WI, WY, total states: 46\nNumber of Count\n   

FAILED: subReport2\n     
Expected: 
Education info: \n(Bachelor or more): 38.30% and total: 19714949\n(high school or more): 91.51% and total: 47106146\npersons below poverty: 7.55% and total: 3885127\nTotal population: 51476603\n
Actual: 
Education info:\n(Bachelor or more): 38.31% and total: 19707335\n(high school or more): 91.51% and total: 47073510\npersons below poverty: 7.55% and total: 3881503\nTotal population: 51440355\nR\n

FAILED: subReport3\n     
Expected: 
Racial Demographics Info: \n% American Indian and Alaska Native percent: 0.69 count: 353361\n% Asian American percent: 7.28 count: 3746319\n% Black/African American percent: 8.98 count: 4621551\n% Hispanic or Latinx percent: 10.58 count: 5443920\n% Native Hawaiian and Other Pacific Islander percent: 0.32 count: 163485\n% Two or More Races percent: 2.63 count: 1355686\n% White (inclusive) percent: 80.12 count: 41241222\n% White (nonHispanic) percent: 71.08 count: 36587127\ntotal Racial Demographic Count: 51476603
Actual: 
Racial Demographics Info: \n% American Indian and Alaska Native percent: 0.69 count: 353205\n% Asian American percent: 7.28 count: 3745693\n% Black/African American percent: 8.98 count: 4621171\n% Hispanic or Latinx percent: 10.58 count: 5442607\n% Native Hawaiian and Other Pacific Islander percent: 0.32 count: 163474\n% Two or More Races percent: 2.63 count: 1355340\n% White (inclusive) percent: 80.11 count: 41206530\n% White (nonHispanic) percent: 71.06 count: 36553573\ntotal Racial D'



testAgPS (0.0/20.0)
Test Failed: 'Testing aggregate police shooting data\nPASSED: subReport1\nPASSED: subReport2' != 'Testing aggregate police shooting data\n

FAILED: subReport1\n    
Expected:
State Info: AK, AZ, CA, CO, ID, KS, KY, MN, MT, ND, NE, NM, NV, OK, SD, TX, UT, VA, VT, WA, WI, WY, total states: 22\nNumber of incidents: 87\n 
Actual:
key: KeyNativeAmericanVictim\nState Info: AK, AZ, CA, CO, ID, KS, KY, MN, MT, ND, NE, NM, NV, OK, SD, TX, UT, VA, VT, WA, WI, WY, total states\n
PASSED: subReport2'


*/