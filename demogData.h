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
    demogData(string inN, string inS, int in65, int in18,
        int in5, int inBach, int inHS, int inPov, int totPop14, raceDemogData r): 
        regionData{inN, inS, totPop14}{

            state = inS;
            rdd = r;
            over65 = in65;
            under18 = in18;
            under5 = in5;
            bach = inBach;
            hs = inHS;
            povAmt = inPov;

            /*percOver65 = in65;
            percUnder18 = in18;
            percUnder5 = in5;
            percWBach = inBach;
            percWHS = inHS;
            percBelowPov = inPov * 100.0 / totPop14;*/
        }

    //getter functions. self explanatory
    string getName() const { return regionName;}
    string getStateName() const { return state;}
    double getOver65Perc() const { return 100.0f * ((double)over65)/population;}
    double getUnder18Perc() const { return 100.0f * ((double)under18)/population;}
    double getUnder5Perc() const { return 100.0f * ((double)under5)/population;}
    double getPercWBach() const { return 100.0f * ((double)bach)/population;}
    double getPercWHS() const { return 100.0f * ((double)hs)/population;}
    double getPercBelowPov() const { return 100.0f * ((double)povAmt)/population;}
    raceDemogData getRaceDemogData() const {return rdd;}

    //getters that do calcs. self explanatory
    virtual int getOver65() const { return over65;}//round(population * percOver65/100);}
    virtual int getUnder18() const { return under18;}//round(population * percUnder18/100);} 
    virtual int getUnder5() const { return under5;}//round(population * percUnder5/100);}
    virtual int getBachAmt() const {return bach;}//round(population * percWBach/100);}
    virtual int getHSAmt() const { return hs;}//round(population * percWHS/100);}
    virtual int getPovAmt() const { return povAmt;}//round(population * percBelowPov/100);}

    
    //overloading the << operator
    friend std::ostream& operator<<(std::ostream &out, const demogData &DD);

    // basically uses the overload operator
    virtual void toString(ostream& os) const{
        cout << this;
    }
    //https://stackoverflow.com/questions/27350212/c-inheritance-tostring

protected:
    string state;
    /*double percOver65;
    double percUnder18;
    double percUnder5;
    double percWBach;
    double percWHS;
    double percBelowPov;*/
    int over65;
    int under18;
    int under5;
    int bach;
    int hs;
    int povAmt;

    raceDemogData rdd;
};
#endif
