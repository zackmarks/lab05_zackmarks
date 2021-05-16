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
    out << "Number of Counties: " << SD.getCountyAmt() << endl;
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
    //out << "Racial Demographics Info:\n";
    out << SD.getRaceDemogData() << endl;
    return out;
}

//Pre-req: a pointer to demogData c. c represents a county
//updates each instance var based on c's data.
void demogCombo::addCounty(shared_ptr<demogData> c){
    rdd += c->getRaceDemogData();
    population += c->getPop();
    countyAmt++;
    POV += c->getPovAmt();
    OVER65 += c->getOver65();
    UNDER18 += c->getUnder18();
    UNDER5 += c->getUnder5();
    BACH += c->getBachAmt();
    HS += c->getHSAmt();
    //cout << c->getStateName() << ": added pov: " << c->getPovAmt() << " -- tot pov: " << pov << " -- perc: " << c->getPercBelowPov() << endl;
    //line above for testing
}

/*
Test Failed: 
'Testing aggregate demographic data\n
PASSED: subReport1\n
PASSED: subReport2\n
PASSED: subReport3' != 'Testing aggregate demographic data\n  
FAILED: subReport1\n
Expected: 
Combo Info: AK, AL, AR, CA, CO, CT, FL, GA, HI, IA, ID, IL, IN, KS, KY, LA, MA, MD, ME, MI, MN, MO, MS, MT, NC, ND, NE, NH, NJ, NM, NV, NY, OH, OK, OR, PA, RI, SD, TN, TX, UT, VA, VT, WA, WI, WY, total states: 46\nNumber of Counties: 431 County Demographics Info: comboData, many\n 
Actual: 
Combo Demographic Info: key: KeyBelowPovLessTenPer\nCombo Info: AK, AL, AR, CA, CO, CT, FL, GA, HI, IA, ID, IL, IN, KS, KY, LA, MA, MD, ME, MI, MN, MO, MS, MT, NC, ND, NE, NH, NJ, NM, NV, NY, OH, OK, OR, PA, RI, SD, TN, TX, UT, VA, VT, WA, WI, WY, total states: 46\nNumber of Count\n   
Fixed:
Combo Info: AK, AL, AR, CA, CO, CT, FL, GA, HI, IA, ID, IL, IN, KS, KY, LA, MA, MD, ME, MI, MN, MO, MS, MT, NC, ND, NE, NH, NJ, NM, NV, NY, OH, OK, OR, PA, RI, SD, TN, TX, UT, VA, VT, WA, WI, WY, total states: 46\nNumber of Count\n   


FAILED: subReport2\n
Expected: 
Education info: \n(Bachelor or more): 38.30% and total: 19714949\n(high school or more): 91.51% and total: 47106146\npersons below poverty: 7.55% and total: 3885127\nTotal population: 51476603\n 
Actual: 
Education info:\n(Bachelor or more): 38.31% and total: 19707335\n(high school or more): 91.51% and total: 47073510\npersons below poverty: 7.55% and total: 3881503\nTotal population: 51440355\nR\n   
Fixed:
Education info: \n(Bachelor or more): 38.31% and total: 19707335\n(high school or more): 91.51% and total: 47073510\npersons below poverty: 7.55% and total: 3881503\nTotal population: 51440355\nR\n   



FAILED: subReport3\n
Expected:
Racial Demographics Info: \n% American Indian and Alaska Native percent: 0.69 count: 353361\n% Asian American percent: 7.28 count: 3746319\n% Black/African American percent: 8.98 count: 4621551\n% Hispanic or Latinx percent: 10.58 count: 5443920\n% Native Hawaiian and Other Pacific Islander percent: 0.32 count: 163485\n% Two or More Races percent: 2.63 count: 1355686\n% White (inclusive) percent: 80.12 count: 41241222\n% White (nonHispanic) percent: 71.08 count: 36587127\ntotal Racial Demographic Count: 51476603 
Actual: 
Racial Demographics Info: \n% American Indian and Alaska Native percent: 0.69 count: 353205\n% Asian American percent: 7.28 count: 3745693\n% Black/African American percent: 8.98 count: 4621171\n% Hispanic or Latinx percent: 10.58 count: 5442607\n% Native Hawaiian and Other Pacific Islander percent: 0.32 count: 163474\n% Two or More Races percent: 2.63 count: 1355340\n% White (inclusive) percent: 80.11 count: 41206530\n% White (nonHispanic) percent: 71.06 count: 36553573\ntotal Racial Demographic Count: 51440355

*/