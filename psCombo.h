//Zack Marks
//cs32  Lab05   Prof. Wood  W21

#ifndef POLICECOMBODATA_H
#define POLICECOMBODATA_H

#include "raceDemogData.h"
#include "psData.h"
#include "regionData.h"
#include <memory>
#include <cassert>
#include <string>
#include <iostream>
using namespace std;

class psCombo : public regionData  {
  public:

    // psCombo constructor
    psCombo(string key, string inS) : regionData{key, inS}{
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
    
    //getters
    int getNumMentalI() const {return numMentalI; }
    int getFleeingCount() const {return fleeCount;}
    int getCasesOver65() const {return over65;}
    int getCasesUnder18() const {return under18;}
    raceDemogData getRacialData() const {return rdd;}
    int getnumMales() const {return male;}
    int getnumFemales()const {return female;}
    int getNumberOfCases() const {return population;}
    //string getState() const {return regionName; } 
    int getCasesMidAge() const {return midAge;}
    string getStateName() const {return stateName;}


    double getMentalIPerc() const {return numMentalI * 100.0 / population; }
    double getFleeingPerc() const {return fleeCount * 100.0 / population;}
    double getOver65Perc() const {return over65 * 100.0 / population;}
    double getUnder18Perc() const {return under18 * 100.0 / population;}
    double getMidAgePerc() const {return midAge * 100.0 / population;}


    //child class versin of toString, which prints the psCombo data
    virtual void toString(ostream& os) const{
        cout << this;
    }

    //prereq: pointer to a psData object, named i. each i represents an incident of a police hooting
    //updates the instance vars after adding a new incident
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
    int midAge;
};

#endif