#include <fstream>
#include <sstream>
#include "data.h"

#include <iostream>
using namespace std;

pair<vector<int>,vector<int>> extractPalletValues(const string& palletsFileName)
{
    ifstream palletsFile(palletsFileName);
    if (!palletsFile)
    {
        throw runtime_error("Could not open pallet file: " + palletsFileName);
    }
    vector<int> weights;
    vector<int> profits;
    string pallet;
    bool header=false;
    while (getline(palletsFile, pallet))
    {
        if (!header)
        {
            header=true;
            continue;
        }
        stringstream ss(pallet);
        string token;
        int columnIndex=0;
        while (getline(ss,token,','))
        {
            if (columnIndex==1)
            {
                weights.push_back(stoi(token));
            }
            else if (columnIndex==2)
            {
                profits.push_back(stoi(token));
            }
            columnIndex++;
        }
    }
    palletsFile.close();
    return make_pair(weights,profits);
}

int extractTruckCapacity(const string& truckFileName)
{
    ifstream truckFile(truckFileName);
    if (!truckFile)
    {
        throw runtime_error("Could not open truck file: " + truckFileName);
    }
    string truck;
    bool header=false;
    while (getline(truckFile, truck))
    {
        if (!header)
        {
            header=true;
            continue;
        }
        stringstream ss(truck);
        string token;
        while (getline(ss, token,','))
        {
            return stoi(token);
        }
    }
    throw std::runtime_error("No capacity data found in file: " + truckFileName);
}





