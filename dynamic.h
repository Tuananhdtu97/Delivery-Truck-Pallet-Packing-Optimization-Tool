//
// Created by bccvg on 14/05/2025.
//

#ifndef DYNAMIC_H
#define DYNAMIC_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dynamicProgramming(const vector<int> &profits, const vector<int> &weights, int capacity);
void outputDP(const vector<int> &profits, const vector<int> &weights, const vector<int> &usedItems, int totalProfit);



#endif //DYNAMIC_H
