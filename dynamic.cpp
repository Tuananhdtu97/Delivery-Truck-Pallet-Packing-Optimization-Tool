//
// Created by bccvg on 14/05/2025.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "dynamic.h"

using namespace std;

void outputDP(const vector<int> &profits, const vector<int> &weights, const vector<int> &usedItems, int totalProfit) {
    cout << "\n--- DYNAMIC PROGRAMMING SOLUTION ---\n";
    for (int item : usedItems) {
        cout << item + 1 << " " << weights[item] << " " << profits[item] << endl;
    }
    cout << "Total Profit: " << totalProfit << endl;
}

void dynamicProgramming(const vector<int> &profits, const vector<int> &weights, int capacity) {
    int n = profits.size();

    // dp[i][w] = max profit using first i items and capacity w
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build table
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (weights[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + profits[i - 1]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Find items used
    vector<int> usedItems;
    int w = capacity;
    for (int i = n; i > 0 && w > 0; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            usedItems.push_back(i - 1);
            w -= weights[i - 1];
        }
    }

    outputDP(profits, weights, usedItems, dp[n][capacity]);
}
