#include "ilp.h"
#include <algorithm>
#include <iostream>

/**
 * @struct Item
 * @brief Structure to store item information including index, weight, profit, and profit-to-weight ratio.
 */
struct Item{
    int index;
    int weight;
    int profit;
    double profitPerWeight;

/**
 * @brief Comparison operator to sort items by descending profit-to-weight ratio.
 */
    bool operator<(const Item& other) const{
        return profitPerWeight > other.profitPerWeight;
    }
};

/**
 * @brief Outputs the ILP solution to the console.
 *
 * @param profits Vector of profits for each item.
 * @param weights Vector of weights for each item.
 * @param usedItems Indices of items included in the optimal solution.
 * @param totalProfit Total profit of the optimal solution.
 */
void outputILP(const std::vector<int>& profits, const std::vector<int>& weights,
                const std::vector<int>& usedItems, int totalProfit){
    std::vector<int> sortedItems = usedItems;
    std::sort(sortedItems.begin(), sortedItems.end());
    std::cout << "\n--- INTEGER LINEAR PROGRAMMING SOLUTION ---\n";
    for (int item : sortedItems)
    {
        std::cout << item + 1 << " " << weights[item] << " " << profits[item] << std::endl;
    }
    std::cout << "\nTotal profit: " << totalProfit << std::endl;
}

static int bestProfit = 0;
static std::vector<int> bestSolution;

/**
 * @brief Recursive Branch and Bound function.
 *
 * @param items Vector of items sorted by profit-to-weight ratio.
 * @param capacity Maximum capacity of the knapsack.
 * @param level Current level (index) in the decision tree.
 * @param currentProfit Accumulated profit.
 * @param currentWeight Accumulated weight.
 * @param currentSolution Vector storing the current subset of item indices being explored.
 */
static void branchAndBound(const std::vector<Item>& items, int capacity, int level, int currentProfit,
                            int currentWeight, std::vector<int>& currentSolution) {
    if (currentWeight > capacity) return;

    if (level == (int)items.size()){
        if (currentProfit > bestProfit){
            bestProfit = currentProfit;
            bestSolution = currentSolution;
        }
        return;
    }

    int remainingCapacity = capacity - currentWeight;
    double bound = currentProfit;
    for (int i = level; i < (int)items.size(); i++){
        if (items[i].weight <= remainingCapacity){
            remainingCapacity -= items[i].weight;
            bound += items[i].profit;
        } else {
            bound += items[i].profitPerWeight * remainingCapacity;
            break;
        }
    }

    if (bound <= bestProfit) return;

    //Take the item
    currentSolution.push_back(items[level].index);
    branchAndBound(items, capacity, level + 1, currentProfit + items[level].profit,
                    currentWeight + items[level].weight, currentSolution);
    currentSolution.pop_back();

    //Skip the item
    branchAndBound(items, capacity, level + 1, currentProfit, currentWeight, currentSolution);

}

/**
 * @brief Solves the 0/1 Knapsack Problem using Branch and Bound.
 *
 * @param profits Vector of profits for each item.
 * @param weights Vector of weights for each item.
 * @param capacity Maximum capacity of the knapsack.
 * @return std::vector<int> Vector of indices of items included in the optimal solution.
 */
std::vector<int> knapsackILP(const std::vector<int>& profits, const std::vector<int>& weights, int capacity){
    bestProfit = 0;
    bestSolution.clear();

    int n = weights.size();
    std::vector<Item> items(n);

    for (int i = 0; i < n; i++){
        items[i].index = i;
        items[i].weight = weights[i];
        items[i].profit = profits[i];
        items[i].profitPerWeight = (weights[i] == 0) ? 0.0 : ((double)profits[i] / weights[i]);
    }

    std::sort(items.begin(), items.end());

    std::vector<int> currentSolution;
    branchAndBound(items, capacity, 0, 0, 0, currentSolution);

    outputILP(profits, weights, bestSolution, bestProfit);
    return bestSolution;
}