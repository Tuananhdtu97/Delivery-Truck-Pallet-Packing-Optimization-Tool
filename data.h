#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>
#include <utility>
using namespace std;

pair<vector<int>, vector<int>> extractPalletValues(const string& palletsFileName);

int extractTruckCapacity(const string& truckFileName);


#endif //DATA_H
