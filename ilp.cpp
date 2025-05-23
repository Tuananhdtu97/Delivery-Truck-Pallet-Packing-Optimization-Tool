#include "ilp.h"
#include <algorithm>
#include <iostream>

struct Item{
    int index;
    int weight;
    int profit;
    double profitPerWeight;

    bool operator<(const Item& other) const{
        return profitPerWeight > other.profitPerWeight;
    }
};

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