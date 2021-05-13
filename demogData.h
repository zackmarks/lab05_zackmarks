//Zack Marks
//cs32  Lab05   Prof. Wood  W21
//Fully copied over. need to delete duplicat functions
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
    //use region data constuctor as well
    //demogCombo(string stateName): demogData(...),


    demogData(string inN, string inS, double in65, double in18,
        double in5, double inBach, double inHS, double inPov, int totPop14, raceDemogData r): 
        regionData{inN, inS, totPop14}{
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
            //cout << "hs: "<< round(population * percBelowPov/100) << " " << inPov << endl;
            //cout << "pov:"<< round(population * percBelowPov/100) << " " << inPov << endl<<endl;

        }

    //getter functions. self explanatory
    string getName() const { return regionName;}
    string getStateName() const { return state;}
    //int get2014Pop() const { return population;}//getPop() in regionData.h
    virtual double getOver65Perc() const { return percOver65;}
    virtual double getUnder18Perc() const { return percUnder18;}
    virtual double getUnder5Perc() const { return percUnder5;}
    virtual double getPercWBach() const { return percWBach;}
    virtual double getPercWHS() const { return percWHS;}
    virtual double getPercBelowPov() const { return percBelowPov;}
    raceDemogData getRaceDemogData() const {return rdd;}

    //getters that do calcs. self explanatory
    virtual int getOver65() const { return round(population * percOver65/100);}
    virtual int getUnder18() const { return round(population * percUnder18/100);} 
    virtual int getUnder5() const { return round(population * percUnder5/100);}
    virtual int getBachAmt() const {return round(population * percWBach/100);}
    virtual int getHSAmt() const { return round(population * percWHS/100);}
    virtual int getPovAmt() const { return round(population * percBelowPov/100);}

    void addOver65(int in) {over65 += in;}
    void addUnder18(int in) {under18 += in;}
    void addUnder5(int in) {under5 += in;}
    //void addPop(int in) {pop += in;}
    void addBach(int in) {bach += in;}
    void addHS(int in) {hs += in;}
    void addPov(int in) {pov += in;}
    
   friend std::ostream& operator<<(std::ostream &out, const demogData &DD);
   //void toString(ostream& os);
   //maybe move or change
   //std::vector<shared_ptr<demogData>> read_csv(std::string filename, typeFlag fileType);


    //DEFINE
    virtual void toString(ostream& os) const{
        cout << "a";
    }
    //https://stackoverflow.com/questions/27350212/c-inheritance-tostring

protected:
    //string name;//change to regionName
    string state;
    double percOver65;
    double percUnder18;
    double percUnder5;
    double percWBach;
    double percWHS;
    double percBelowPov;
    //const int totalPopulation2014;
    //CHANGE ALL PERCS TO ACTUAL NUMBERS


    int over65;
    int under18;
    int under5;
    int bach;
    int hs;
    int pov;

    raceDemogData rdd;
};
#endif
