//Zack Marks
//cs32  Lab05   Prof. Wood  W21

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "demogData.h"
#include "psData.h"
#include "parse.h"
#include "dataAQ.h"

using namespace std;

int main() {

    dataAQ theAnswers;

    //read in a csv file and create a vector of objects representing each counties data
    std::vector<shared_ptr<regionData>> theDemogData = read_csv(
            "county_demographics.csv", DEMOG);

    std::vector<shared_ptr<regionData>> thePoliceData = read_csv(
            "police_shootings_cleaned.csv", POLICE);

     //debug print out
    /*for (const auto &obj : thePoliceData) {
        //std::cout << *obj << std::endl;
        //std::cout << *((shared_ptr<demogData>&)theDemogData);
    }*/

    theAnswers.createComboDemogDataKey((std::vector<shared_ptr<demogData>>&)theDemogData);
    theAnswers.createComboPoliceDataKey((std::vector<shared_ptr<psData>>&) thePoliceData);

    //theAnswers.printAK();
    //cout << theAnswers;

    //theAnswers.reportTopTenStatesBP();
    //theAnswers.reportTopTenStatesPS();

    return 0;
}

