//Zack Marks
//cs32  Lab05   Prof. Wood  W21    

#ifndef RACEDEMOG_H
#define RACEDEMOG_H

#include <iostream>
#include <cmath>

class raceDemogData {
  public:
      //default constructor
      raceDemogData() :
          FirstNationCount(0), AsianCount(0), BlackCount(0), LatinxCount(0), HIPacificIsleCount(0),
          MultiRaceCount(0), WhiteCount(0), WhiteNHCount(0), otherCount(0), pop(0) {}

      //non-default constuctor
      raceDemogData(double FN, double A, double B, double L, double HPI, double MR, double W, double WNH, int size) :
          FirstNationCount(round(FN*size)), AsianCount(round(size*A)), BlackCount(round(size*B)), LatinxCount(round(size*L)), 
          HIPacificIsleCount(round(size*HPI)), MultiRaceCount(round(size*MR)), WhiteCount(round(size*W)), 
          WhiteNHCount(round(size*WNH)), otherCount(0), pop(size) {}

      //getters
      double getFirstNationPercent() const  { return 100.0f*(double)(FirstNationCount)/pop; }
      double getAsianPercent() const { return 100.0f*(double)(AsianCount)/pop; }
      double getBlackPercent() const { return 100.0f*(double)(BlackCount)/pop; }
      double getLatinxPercent() const { return 100.0f*(double)(LatinxCount)/pop; }
      double getHIPacificIslePercent() const  { return 100.0f*(double)(HIPacificIsleCount)/pop; }
      double getMultiRacePercent() const { return 100.0f*(double)(MultiRaceCount)/pop; }
      double getWhitePercent() const { return 100.0f*(double)(WhiteCount)/pop; }
      double getWhiteNHPercent() const { return 100.0f*(double)(WhiteNHCount)/pop; }
      double getOtherPercent() const { return 100.0f*(double)(otherCount)/pop; }
      int getFirstNationCount() const { return FirstNationCount;}
      int getAsianCount() const { return AsianCount;}
      int getBlackCount() const { return BlackCount;}
      int getLatinxCount() const { return LatinxCount;}
      int getHIPacificIsleCount() const { return HIPacificIsleCount;}
      int getMultiRaceCount() const  { return MultiRaceCount;}
      int getWhiteCount() const { return WhiteCount;}
      int getWhiteNHCount() const { return WhiteNHCount;}
      int getOtherCount() const { return otherCount;}
      int getCommunityCount() const { return pop;}
      int getTotalRace() const{return pop;}

      //setters
      void addFirstNationCount(int inNum){FirstNationCount += inNum;}
      void addAsianCount(int inNum){AsianCount+= inNum;}
      void addBlackCount(int inNum){BlackCount+= inNum;}
      void addLatinxCount(int inNum){LatinxCount+= inNum;}
      void addHIPacificIsleCount(int inNum){HIPacificIsleCount+= inNum;}
      void addMultiRaceCount(int inNum){MultiRaceCount+= inNum;}
      void addWhiteCount(int inNum){WhiteCount+= inNum;}
      void addWhiteNHCount(int inNum){WhiteNHCount+= inNum;}
      void addOtherCount(int inNum){otherCount+= inNum;}
      void addCommunityCount(int inNum){pop+= inNum;}

      //prereq: rd, an instance of radeDemogData
      //postreq: updates this instance vars
      raceDemogData& operator+=(const raceDemogData rd) {
          addFirstNationCount(rd.getFirstNationCount());
          addAsianCount(rd.getAsianCount());
          addBlackCount(rd.getBlackCount());
          addLatinxCount(rd.getLatinxCount());
          addHIPacificIsleCount(rd.getHIPacificIsleCount());
          addMultiRaceCount(rd.getMultiRaceCount());
          addWhiteCount(rd.getWhiteCount());
          addWhiteNHCount(rd.getWhiteNHCount());
          addOtherCount(rd.getOtherCount());
          addCommunityCount(rd.getCommunityCount());
          return *this;
      }

      friend std::ostream& operator<<(std::ostream &out, const raceDemogData &DD);

  private:
    //count of population for various racial/ethinic identifies 
    int FirstNationCount;
    int AsianCount;
    int BlackCount;
    int LatinxCount;
    int HIPacificIsleCount;
    int MultiRaceCount;
    int WhiteCount;
    int WhiteNHCount;
    int otherCount;
    int pop;
};

#endif
