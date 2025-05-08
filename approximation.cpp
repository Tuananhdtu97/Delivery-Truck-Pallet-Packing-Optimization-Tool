#include "approximation.h"

/**
 * @brief Solves 0-1 Knapsack Problem using a greedy approach.
 *
 * This function takes the profits and weights of a set of pallets and finds the most valuable subset which does not exceed the truck weight capacity, using a greedy strategy based on the weight to profit ratio of each pallet.
 *
 * @param profits Vector containing the profits associated with each pallet.
 * @param weights Vector containing the weights of each pallet.
 * @param capacity Weight capacity of the truck.
 * @return pair<vector<int>,int> Vector containing the indexes of the pallets that take part of the solution and the sum of their associated profits.
 * @note Time Complexity: O(n log n), where n is the number of pallets.
 * @note Space Complexity: O(n), where n is the number of pallets.
 */
pair<vector<int>, int> knapsackGreedyA(const vector<int> &profits, const vector<int> &weights, int capacity)
{
    vector<int> usedItems;
    vector<int> indexes;
    for (int i=0; i<weights.size(); i++)
    {
        indexes.push_back(i);
    }
    sort(indexes.begin(), indexes.end(), [&](int i, int j)
    {
        auto ratio1 = static_cast<double>(weights[i]) / profits[i];
        auto ratio2 = static_cast<double>(weights[j]) / profits[j];
        return ratio1 < ratio2;
    });
    int totalWeight = 0;
    int totalProfit = 0;
    for (int index: indexes)
    {
        if (totalWeight + weights[index] <= capacity)
        {
            totalWeight += weights[index];
            totalProfit += profits[index];
            usedItems.push_back(index);
        }
    }
    return make_pair(usedItems,totalProfit);
}

/**
 * @brief Solves 0-1 Knapsack Problem using a greedy approach.
 *
 * This function takes the profits and weights of a set of pallets and finds the most valuable subset which does not exceed the truck weight capacity, using a greedy strategy by prioritizing more profitable pallets.
 *
 * @param profits Vector containing the profits associated with each pallet.
 * @param weights Vector containing the weights of each pallet.
 * @param capacity Weight capacity of the truck.
 * @return pair<vector<int>,int> Vector containing the indexes of the pallets that take part of the solution and the sum of their associated profits.
 * @note Time Complexity: O(n log n), where n is the number of pallets.
 * @note Space Complexity: O(n), where n is the number of pallets.
 */
pair<vector<int>, int> knapsackGreedyB(const vector<int> &profits, const vector<int> &weights, int capacity)
{
    vector<int> usedItems;
    vector<int> indexes;
    for (int i=0; i<weights.size(); i++)
    {
        indexes.push_back(i);
    }
    sort(indexes.begin(), indexes.end(), [&](int i, int j)
    {
        return profits[i] > profits[j];
    });
    int totalWeight = 0;
    int totalProfit = 0;
    for (int index: indexes)
    {
        if (totalWeight + weights[index] <= capacity)
        {
            totalWeight += weights[index];
            totalProfit += profits[index];
            usedItems.push_back(index);
        }
    }
    return make_pair(usedItems,totalProfit);
}

/**
 * @brief Solves 0-1 Knapsack Problem using an approximation approach.
 *
 * This function takes the solutions of the greedy approaches to the problem and chooses the one with the best solution.
 *
 * @param approxA Vector containing the indexes of the used items, as well as the associated total profit, obtained from greedy approach, based on the weight to profit ratio from each pallet.
 * @param approxB Vector containing the indexes of the used items, as well as the associated total profit, obtained from greedy approach, prioritizing more profitable pallets.
 * @return pair<vector<int>,int> Parameter with the biggest associated profit.
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */
pair<vector<int>,int> knapsackApprox(const pair<vector<int>,int> &approxA, const pair<vector<int>,int> &approxB)
{
    int profitA = approxA.second;
    int profitB = approxB.second;
    int bestProfit = max(profitA, profitB);
    if (bestProfit==profitA)
    {
        return approxA;
    }
    return approxB;
}

/**
 * @brief Outputs obtained solution for the 0-1 Knapsack Problem.
 *
 * This function takes the profits and weights of the set of pallets, as well as the final solution obtained from the approximation approach and outputs all its data to the user.
 *
 * @param profits Vector containing the profits associated with each pallet.
 * @param weights Vector containing the weights of each pallet.
 * @param usedItems Vector containing the indexes of the pallets that integrate the solution to the problem.
 * @param totalProfit Sum of the profits of each pallet that takes part pf the solution.
 * @note Time Complexity: O(k log k), where k is the number of used items
 * @note Space Complexity: O(1)
 */
void outputSolution(const vector<int> &profits, const vector<int> &weights, vector<int> &usedItems, int totalProfit)
{
    sort(usedItems.begin(), usedItems.end());
    cout<<"\n--- APPROXIMATION(GREEDY) SOLUTION ---\n";
    for (int item : usedItems)
    {
        cout<<item+1<<" "<<weights[item]<<" "<<profits[item]<<endl;
    }
    cout<<"Total Profit: "<<totalProfit<<endl;
}

/**
 * @brief Invokes functions to obtain and output the approximation solution to the 0-1 Knapsack Problem.
 *
 * This function invokes other functions to perform the approximation approach, to obtain the solution to the 0-1 Knapsack Problem and output it to the user.
 *
 * @param profits Vector containing the profits associated with each pallet.
 * @param weights Vector containing the weights of each pallet.
 * @param capacity Weight capacity of the truck.
 * @note Time Complexity: O (n log n), where n is the number of pallets (dominated by greedy algorithms).
 * @note Space Complexity: O(n), where n is the number of pallets.
 */
void mainApprox(const vector<int> &profits, const vector<int> &weights, int capacity)
{
    pair<vector<int>,int> approxA=knapsackGreedyA(profits, weights, capacity);
    pair<vector<int>,int> approxB=knapsackGreedyB(profits, weights, capacity);
    pair<vector<int>,int> approxSol=knapsackApprox(approxA,approxB);
    outputSolution(profits, weights, approxSol.first, approxSol.second);
}