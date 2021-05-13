//Zack Marks
//cs32  Lab05   Prof. Wood  W21
//fully copied over

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
    //change later. error coming from here
    //add appropriate function paramaters to constructor once you add data
    psData(string inN, string inS, int inA, string inG, string inR, string inC, bool inMI, string inFlee) : 
        regionData{inS, inS, 1}{
        //name(inN), state(inS), age(inA), gender(inG), race(inR), county(inC), MI(inMI) {
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
    }


/*
    psData(const string inN, const string inS, const int inPop):
        state(inS), population(1) {
    const int age;
    const string gender;
    const string race;
    const string county;
    const bool MI;
    bool flee;
    raceDemogData r;



            //regionData(inN, "", population);
        }*/

    //getters
    string getState() const { return regionName; }
    string getName() const {return name;}
    int getAge() const {return age;}
    string getGender() const {return gender;}
    string getRace() const {return race;}
    bool getMI() const {return MI;}
    bool getFlee() const {return flee;}
    string getCounty() const {return county;}

    //overloading << operator
    friend std::ostream& operator<<(std::ostream &out, const psData &PD);
    virtual void toString(ostream& os) const{
        cout << "a";
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
};

#endif
