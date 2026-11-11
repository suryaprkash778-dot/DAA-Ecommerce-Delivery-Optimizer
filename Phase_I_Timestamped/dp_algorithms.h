// dp_algorithms.h
#ifndef DP_ALGORITHMS_H
#define DP_ALGORITHMS_H

#include "domain.h"
#include <vector>
#include <algorithm>
#include <iostream>

// 0/1 Knapsack using Dynamic Programming to maximize priority/value within vehicle capacity
std::vector<Order> packVehicleKnapsack(const std::vector<Order>& availableOrders, double vehicleCapacity) {
    int n = availableOrders.size();
    // Multiply capacity by 10 or 100 to handle one decimal place for array indices if needed, 
    // or assume integer weights for the standard DP matrix. We will cast to int for this prototype.
    int W = static_cast<int>(vehicleCapacity); 

    // DP table: dp[i][w] stores maximum priority value
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

    // Build table dp[][] in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            int weight = static_cast<int>(availableOrders[i - 1].totalWeight);
            // Invert priority so 1 (High) has higher value than 2 (Standard). 
            // e.g., Value = 3 - priority (Pri 1 = Val 2; Pri 2 = Val 1)
            int value = 3 - availableOrders[i - 1].priority; 

            if (weight <= w) {
                dp[i][w] = std::max(value + dp[i - 1][w - weight], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Backtrack to find the selected orders
    std::vector<Order> packedOrders;
    int res = dp[n][W];
    int w = W;
    for (int i = n; i > 0 && res > 0; i--) {
        if (res != dp[i - 1][w]) {
            packedOrders.push_back(availableOrders[i - 1]);
            int weight = static_cast<int>(availableOrders[i - 1].totalWeight);
            res -= (3 - availableOrders[i - 1].priority);
            w -= weight;
        }
    }

    return packedOrders;
}

#endif
