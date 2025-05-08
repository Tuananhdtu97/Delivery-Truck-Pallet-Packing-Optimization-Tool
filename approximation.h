#ifndef APPROXIMATION_H
#define APPROXIMATION_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

pair<vector<int>, int> knapsackGreedyA(const vector<int> &profits, const vector<int> &weights, int capacity);

pair<vector<int>, int> knapsackGreedyB(const vector<int> &profits, const vector<int> &weights, int capacity);

pair<vector<int>,int> knapsackApprox(const pair<vector<int>,int> &approxA, const pair<vector<int>,int> &approxB);

void mainApprox(const vector<int> &profits, const vector<int> &weights, int capacity);

void outputSolution(const vector<int> &profits, const vector<int> &weights, vector<int> &usedItems, int totalProfit);

#endif //APPROXIMATION_H
