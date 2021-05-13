//Zack Marks
//cs32  Lab05   Prof. Wood  W21

#ifndef DEMOG_H
#define DEMOG_H

#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "raceDemogData.h"
#include "regionData.h"
using namespace std;

//class to represent county demographic data
//define toString in each child class
class demogData : public regionData {
  public:

    //constructor
    demogData(string inN, string inS, double in65, double in18,
        double in5, double inBach, double inHS, double inPov, int totPop14, raceDemogData r): 
        regionData{inN, inS, totPop14}{
            //a whole lot of instance vars here because data downstream must be able to read in multiple types of data
            //regionName = inN;
            state = inS;
            percOver65 = in65;
            percUnder18 = in18;
            percUnder5 = in5;
            percWBach = inBach;
            percWHS = inHS;
            percBelowPov = inPov;
            rdd = r;
            over65 = getOver65();
            under18 = getUnder18();
            under5 = getUnder5();
            bach = getBachAmt();
            hs = getHSAmt();
            pov = getPovAmt();
        }

    //getter functions. self explanatory
    string getName() const { return regionName;}
    string getStateName() const { return state;}
    double getOver65Perc() const { return percOver65;}
    double getUnder18Perc() const { return percUnder18;}
    double getUnder5Perc() const { return percUnder5;}
    double getPercWBach() const { return percWBach;}
    double getPercWHS() const { return percWHS;}
    double getPercBelowPov() const { return percBelowPov;}
    raceDemogData getRaceDemogData() const {return rdd;}

    //getters that do calcs. self explanatory
    virtual int getOver65() const { return /*over65;}/*/round(population * percOver65/100);}
    virtual int getUnder18() const { return /*under18;}/*/round(population * percUnder18/100);} 
    virtual int getUnder5() const { return /*under5;}/*/round(population * percUnder5/100);}
    virtual int getBachAmt() const {return /*bach;}/*/round(population * percWBach/100);}
    virtual int getHSAmt() const { return /*hs;}/*/round(population * percWHS/100);}
    virtual int getPovAmt() const { return /*pov;}/*/round(population * percBelowPov/100);}

    /*void addOver65(int in) {over65 += in;}
    void addUnder18(int in) {under18 += in;}
    void addUnder5(int in) {under5 += in;}
    void addBach(int in) {bach += in;}
    void addHS(int in) {hs += in;}
    void addPov(int in) {pov += in;}*/
    
    //overloading the << operator
    friend std::ostream& operator<<(std::ostream &out, const demogData &DD);

    // basically uses the overload operator
    virtual void toString(ostream& os) const{
        cout << this;
    }
    //https://stackoverflow.com/questions/27350212/c-inheritance-tostring

protected:
    string state;
    double percOver65;
    double percUnder18;
    double percUnder5;
    double percWBach;
    double percWHS;
    double percBelowPov;
    int over65;
    int under18;
    int under5;
    int bach;
    int hs;
    int pov;

    raceDemogData rdd;
};
#endif
