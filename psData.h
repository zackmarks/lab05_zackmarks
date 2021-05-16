//Zack Marks
//cs32  Lab05   Prof. Wood  W21

#ifndef POLICE_H
#define POLICE_H

#include <string>
#include <utility>
#include <sstream>
#include <assert.h>
#include <iomanip>
#include <memory>
#include <iostream>
#include "raceDemogData.h"
#include "regionData.h"

using namespace std;


class psData : public regionData {
  public:

    //constuctor
    psData(string inN, string inS, int inA, string inG, string inR, string inC, bool inMI, string inFlee) : 
        regionData{inS, inS, 1}{
            name = inN;
            age = inA; 
            gender = inG;
            race = inR;
            county = inC;
            MI = inMI;
            if(inFlee == "Not fleeing" || inFlee == "")
                flee = false;
            else
                flee = true;
            fleeing = inFlee;
    }

    //getters
    string getState() const { return regionName; }
    string getName() const {return name;}
    int getAge() const {return age;}
    string getGender() const {return gender;}
    string getRace() const {return race;}
    bool getMI() const {return MI;}
    bool getFlee() const {return flee;}
    string getCounty() const {return county;}
    string getFleeing() const {return fleeing;}

    //overloading << operator
    friend std::ostream& operator<<(std::ostream &out, const psData &PD);
    virtual void toString(ostream& os) const{
        cout << this;
    }
    
private:
    //const string state;
    string name;
    int age;
    string gender;
    string race;
    string county;
    bool MI;
    bool flee;
    raceDemogData r;
    string fleeing;
};

#endif
