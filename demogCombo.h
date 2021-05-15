//Zack Marks
//cs32  Lab05   Prof. Wood  W21

#ifndef COMBODEMOG_H
#define COMBODEMOG_H

#include <memory>
#include <string>
#include <iostream>
#include "demogData.h"
#include "raceDemogData.h"
#include "regionData.h"
#include <vector>
#include <map>

//TEST FOR UPDATE
//class to represent combined demographic data 

class demogCombo : public demogData {
  public:
  	//take in only state name, use demogData const to make others 0
    demogCombo(string region, string stateName): demogData{region, stateName, 0,0,0,0,0,0,0, raceDemogData()}{
    	countyAmt = 0;
    	POV = 0;
		OVER65 = 0;
		UNDER18 = 0;
		UNDER5 = 0;
		BACH = 0;
		HS = 0;
    }

    void addCounty(shared_ptr<demogData> c);
    int getCountyAmt() const {return countyAmt;}
    
    //I tried to get these to be inherited but could not
    //getters
    virtual int getPovAmt() const {return POV;}
    virtual int getOver65() const { return OVER65;}
    virtual int getUnder18() const { return UNDER18;} 
    virtual int getUnder5() const { return UNDER5;}
    virtual int getBachAmt() const {return BACH;}
    virtual int getHSAmt() const { return HS;}
    virtual double getOver65Perc() const { return ((OVER65 * 100.0) / population);}
    virtual double getUnder18Perc() const { return ((UNDER18 * 100.0) / population);}
    virtual double getUnder5Perc() const { return ((UNDER5 * 100.0) / population);}
    virtual double getPercWBach() const { return ((BACH * 100.0) / population);}
    virtual double getPercWHS() const { return ((HS * 100.0) / population);}
    virtual double getPercBelowPov() const { return ((POV * 100.0) / population);}
    
    //basically the <<
    virtual void toString(ostream& os) const{
        cout << this;
    }

    //overloading <<
    friend std::ostream& operator<<(std::ostream &out, const demogCombo &SD);

private:
	int countyAmt;
	int POV;
	int OVER65;
	int UNDER18;
	int UNDER5;
	int BACH;
	int HS;
};
#endif
