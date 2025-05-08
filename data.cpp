#include <fstream>
#include <sstream>
#include "data.h"

#include <iostream>
using namespace std;

/**
 * @brief Reads and extracts data from a set of pallets.
 *
 * This function takes the name of the file containing information about the pallets, extracts it and stores it accordingly to be used by other functions.
 *
 * @param palletsFileName String containing the name of the .csv file containing the data about the pallets.
 * @return pair<vector<int>, vector<int>> Two vectors, one containing the weights, and, the other, the values of each pallet in the file.
 * @note Time Complexity: O(n), where n is the number of pallets.
 * @note Space Complexity: O(n), where n is the number of pallets.
 */
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

/**
 * @brief Reads and extracts data from a truck.
 *
 * This function takes the name of the file containing information about the truck, extracts it and stores it to be used by other functions.
 *
 * @param truckFileName String containing the name of the .csv file containing the data about the truck.
 * @return int Truck´s maximum weight capacity.
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */
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





