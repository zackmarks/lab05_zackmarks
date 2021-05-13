//Zack Marks
//cs32  Lab05   Prof. Wood  W21

#ifndef PARSE_H
#define PARSE_H

#include <memory>
#include <vector>
#include <string>
#include <fstream>
#include <sstream> // std::stringstream
#include "demogData.h"
#include "psData.h"

/*static functions to help parse CSV data */

/* For future assignments when we read different types of data */
enum typeFlag {
	DEMOG = 0,
	HOSPITAL = 1,
	POLICE = 2
};

/* helper to strip out quotes from a string */
string stripQuotes(std::string temp) ;

/* helper: get field from string stream */
/* assume field has quotes for CORGIS */
string getField(std::stringstream &ss);

/* helper: read out column names for CSV file */
void consumeColumnNames(std::ifstream &myFile);

//NEW INHEREITED VERSION
std::vector<shared_ptr<regionData>> read_csv(std::string filename, typeFlag fileType);

// Read one line from a CSV file for county demographic data specifically
shared_ptr<demogData> readCSVLineDemog(std::string theLine);

// Read one line from a CSV file for police shooting data specifically
shared_ptr<psData> readCSVLinePolice(std::string theLine);

#endif
