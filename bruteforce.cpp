//
// Created by bccvg on 14/05/2025.
//

#include "bruteforce.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void outputBrute(const vector<int> &profits, const vector<int> &weights, vector<int> &usedItems, int totalProfit) {
    sort(usedItems.begin(), usedItems.end());
    cout << "\n--- BRUTE-FORCE SOLUTION ---\n";
    for (int item : usedItems) {
        cout << item + 1 << " " << weights[item] << " " << profits[item] << endl;
    }
    cout << "Total Profit: " << totalProfit << endl;
}

void bruteForce(const vector<int> &profits, const vector<int> &weights, int capacity) {
    int n = profits.size();
    int maxProfit = 0;
    vector<int> bestSubset;

    // Iterate over all subsets (2^n combinations)
    for (int mask = 0; mask < (1 << n); ++mask) {
        int totalWeight = 0;
        int totalProfit = 0;
        vector<int> subset;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                totalWeight += weights[i];
                totalProfit += profits[i];
                subset.push_back(i);
            }
        }

        if (totalWeight <= capacity && totalProfit > maxProfit) {
            maxProfit = totalProfit;
            bestSubset = subset;
        }
    }

    outputBrute(profits, weights, bestSubset, maxProfit);
}