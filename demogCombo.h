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

//class to represent combined demographic data 
class demogCombo : public demogData {
  public:
  	//take in only state name, use demogData const to make others 0
    demogCombo(string region, string stateName): demogData{region, stateName, 0,0,0,0,0,0,0, raceDemogData()}{
    	countyAmt = 0;
    }

    //updates instance variables with the addition of a new county into the dataset
    void addCounty(shared_ptr<demogData> c);

    //returns countyAmt
    int getCountyAmt() const {return countyAmt;}
        
    //basically the <<
    virtual void toString(ostream& os) const{
        cout << this;
    }

    //overloading <<
    friend std::ostream& operator<<(std::ostream &out, const demogCombo &SD);

private:
	int countyAmt;
};
#endif
