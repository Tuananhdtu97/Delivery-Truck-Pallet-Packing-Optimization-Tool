#include "bruteforce.h"
#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Outputs the solution for the 0-1 Knapsack problem using brute-force.
 *
 * This function prints the selected items (by index, weight, and profit) and the total profit
 * based on the best subset found by the bruteForce algorithm.
 *
 * @param profits Vector containing the profits associated with each item.
 * @param weights Vector containing the weights of each item.
 * @param usedItems Vector containing the indices of the items included in the best solution subset.
 * @param totalProfit Total profit corresponding to the selected subset of items.
 */

using namespace std;

void outputBrute(const vector<int> &profits, const vector<int> &weights, vector<int> &usedItems, int totalProfit) {
    sort(usedItems.begin(), usedItems.end());
    cout << "\n--- BRUTE-FORCE SOLUTION ---\n";
    for (int item : usedItems) {
        cout << item + 1 << " " << weights[item] << " " << profits[item] << endl;
    }
    cout << "Total Profit: " << totalProfit << endl;
}

/**
 * @brief Solves the 0-1 Knapsack Problem using a brute-force approach.
 *
 * This function evaluates all possible combinations (subsets) of items to find the subset
 * that yields the maximum profit without exceeding the given weight capacity.
 *
 * @param profits Vector containing the profits associated with each item.
 * @param weights Vector containing the weights of each item.
 * @param capacity Maximum allowable weight capacity.
 * @note Time Complexity: O(2^n), where n is the number of items.
 * @note Space Complexity: O(n), due to storage of the current subset.
 */
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
