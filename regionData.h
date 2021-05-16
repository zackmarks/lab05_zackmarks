//Zack Marks
//cs32  Lab05   Prof. Wood  W21

#ifndef REGION_H
#define REGION_H

#include <string>
#include <iostream>
#include <vector>
#include <set>

using namespace std;


/* very general data type for any kind of regional data*/
class regionData {
  public:
    //t constuctors
    regionData(const string inN, const string inS, const int pop) : regionName(inN), population(pop) {
      stateS.insert(inS);
      //stateAmt = 1;
    }
    regionData(const string inN, const string inS) : regionName(inN), population(0) {
      stateS.insert(inS);
      //stateAmt = 1;
    }

    //getters
    string getRegionName() const { return regionName; }
    string getState() const {
        if (stateS.size() == 1){
            return *(stateS.begin()); 
        }else{
            return printState();
        }
    }
    void addState(string inS) { stateS.insert(inS);}
    string printState() const { 
      string s;
      for (std::set<string>::iterator it=stateS.begin(); it != stateS.end(); it++) 
        s+=*it+", "; 
      s+= "total states: " + to_string(stateS.size());
      return s;
    }
    void setName(string inN) {regionName = inN;}
    int getPop() const { return population; }
    void setPop(int inPop) { population = inPop; }
    void addPop(int inPop) {population += inPop; }

    //pure virtual to show that it should always go to child class's function
    virtual void toString(ostream& os) const = 0;

  protected:
  	string regionName; //city or county or place name
    //region data could be more than one state
    std::set<string> stateS; //all regions should have identifying state in US
  	int population; //region population
    //int stateAmt;
  	
};
#endif
