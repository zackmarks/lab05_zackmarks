#ifndef POLICECOMBODATA_H
#define POLICECOMBODATA_H

#include "raceDemogData.h"
#include "psData.h"
#include "regionData.h"
#include <memory>
#include <cassert>
#include <string>
#include <iostream>
//#include <vector>
//#include <map>
using namespace std;

class psCombo : public regionData  {
  public:

    //write psCombo constructor
    //psCombo():regionData("",""){}
    psCombo(string inS) : regionData{inS, inS}{
        numMentalI = 0;
        fleeCount = 0;
        over65 = 0;
        under18 = 0;
        male = 0;
        female = 0;
        stateName = inS;
        //cases(0);//population in regionData represents cases here
        midAge = 0;
    }
    
    //complete these
    int getNumMentalI() const {return numMentalI; }
    int getFleeingCount() const {return fleeCount;}
    int getCasesOver65() const {return over65;}
    int getCasesUnder18() const {return under18;}
    raceDemogData getRacialData() const {return rdd;}
    int getnumMales() const {return male;}
    int getnumFemales()const {return female;}
    int getNumberOfCases() const {return population;}
    string getState() const {return regionName; } 
    int getCasesMidAge() const {return midAge;}
    string getStateName() const {return stateName;}

    virtual void toString(ostream& os) const{
        cout << "a\n";
    }

    void addIncident(shared_ptr<psData> i);

    friend std::ostream& operator<<(std::ostream &out, const psCombo& PD);

private:
    string stateName;
    int numMentalI;
    int fleeCount;
    int over65;
    int under18;
    raceDemogData rdd;
    int male;
    int female;
    //int cases;
    int midAge;
};

#endif