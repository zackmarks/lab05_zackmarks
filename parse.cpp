//Zack Marks
//cs32  Lab05   Prof. Wood  W21

#include "parse.h"
#include <algorithm>
#include <cmath>

/* helper to strip out quotes from a string */
string stripQuotes(std::string temp){
    temp.erase(
        remove(temp.begin(), temp.end(), '\"' ),
        temp.end());
    return temp;
}

/* helper: get field from string stream */
string getField(std::stringstream &ss){
    string data, junk;
    //ignore the first quotes and prep data
    std::getline(ss, junk, '\"');
    std::getline(ss, data, '\"');
    std::getline(ss, junk, ',');
    return stripQuotes(data);
}

string getFieldNQ(std::stringstream &ss){
    string temp;
    std::getline(ss, temp, ',');
    //std::cout << temp << std:: endl;
    return temp;
}

/* helper: read out column names for CSV file */
void consumeColumnNames(std::ifstream &myFile){
    std::string line;
    std::string colname;

    // Extract the first line in the file
    std::getline(myFile, line);

    // Create a stringstream from line
    std::stringstream ss(line);

    // Read the column names (for debugging)
    // Extract each column name for debugging
    while(std::getline(ss, colname, ',')){}
}

/* Read one line from a CSV file for county demographic data specifically */
shared_ptr<demogData> readCSVLineDemog(std::string theLine){
    std::stringstream ss(theLine);
    
    string name = getField(ss);
    string state = getField(ss);
    //turn into mathematical percent
    double popOver65 = stod(getField(ss));
    double popUnder18 = stod(getField(ss));
    double popUnder5 = stod(getField(ss));
    double bach = stod(getField(ss));
    double hs = stod(getField(ss));

    //now skip over some data
    for (int i=0; i < 4; i++)
        getField(ss);

    //store initial data as percent (then convert to count)
    double FirstNation = stod(getField(ss))/100.0;
    double Asian = stod(getField(ss))/100.0;
    double Black = stod(getField(ss))/100.0;
    double Latinx = stod(getField(ss))/100.0;
    double HIPacificIsle = stod(getField(ss))/100.0;
    double MultiRace = stod(getField(ss))/100.0;
    double White = stod(getField(ss))/100.0;
    double WhiteNH  = stod(getField(ss))/100.0;

    //now skip over some data 
    for (int i=0; i < 6; i++)
        getField(ss);

    int medHouseIncome = stoi(getField(ss)); //dont use
    //skip per capita
    getField(ss);
    double belowPoverty = stod(getField(ss));
    //cout << belowPoverty << endl;

    //skip over some data 
    for (int i=0; i < 10; i++)
        getField(ss);

    int totalPop2014 = stoi(getField(ss));
 
    raceDemogData r(FirstNation, Asian, Black, Latinx, HIPacificIsle, MultiRace, White, WhiteNH, totalPop2014);

    return make_shared<demogData>(name, state, popOver65, popUnder18,
            popUnder5, bach, hs, belowPoverty, totalPop2014, r);
}

//read one line of police data
shared_ptr<psData> readCSVLinePolice(std::string theLine){
    std::stringstream ss(theLine);
    
    getFieldNQ(ss); //ignore id
    string name = getFieldNQ(ss);
    for(int i = 0; i < 3; i++){
        getFieldNQ(ss);
    }
    int age = 0;
    string tmp = getFieldNQ(ss);
    if(tmp != "")
        age = stoi(tmp);
    else
        age = -1;
    
    string gender = getFieldNQ(ss);
    string race = getFieldNQ(ss);
    string county = getFieldNQ(ss);
    string state = getFieldNQ(ss);
    bool MI = false;
    tmp = getFieldNQ(ss);
    if(tmp == "True")
        MI = true;
    else if(tmp != "False")
        cout << "oh no" << endl;
    getFieldNQ(ss);
    string flee = getFieldNQ(ss);

    //return a singular psData object
    return make_shared<psData>(name, state, age, gender, race, county, MI, flee);
}


//read from a CSV file (for a given data type) return a vector of the data
std::vector<shared_ptr<regionData>> read_csv(std::string filename, typeFlag fileType){
    //the actual data
    std::vector<shared_ptr<regionData>> theData;
    std::ifstream myFile(filename);
    if(!myFile.is_open())
        throw std::runtime_error("Could not open file");

    if(myFile.good()){
        consumeColumnNames(myFile);
        std::string line;

        // Now read data, line by line and create demographic dataobject
        while(std::getline(myFile, line)){
            if (fileType == DEMOG){
                //
                theData.push_back(readCSVLineDemog(line));
            }else if(fileType == POLICE){
                theData.push_back(readCSVLinePolice(line));
            }else{
                cout << "ERROR - unknown file type" << endl;
                exit(0);
            }
        }
        myFile.close();
    }
    return theData;
}