// dp_algorithms.h
#ifndef DP_ALGORITHMS_H
#define DP_ALGORITHMS_H

#include "domain.h"
#include <vector>
#include <algorithm>

// 0/1 Knapsack DP to maximize vehicle packing
inline std::vector<Order> packVehicleKnapsack(const std::vector<Order>& orders, double weightCapacity) {
    int n = orders.size();
    int W = static_cast<int>(weightCapacity); 
    
    // DP table initialized to 0
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));
    
    // Build table
    for (int i = 1; i <= n; i++) {
        int wt = static_cast<int>(orders[i-1].totalWeight);
        
        // FIX: Invert priority for DP math. Priority 1 (High) = 10 value, Priority 2 (Std) = 5 value.
        int val = (orders[i-1].priority == 1) ? 10 : 5; 
        
        for (int w = 0; w <= W; w++) {
            if (wt <= w) {
                dp[i][w] = std::max(val + dp[i-1][w - wt], dp[i-1][w]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    // Backtrack to find which exact orders were packed
    std::vector<Order> packedOrders;
    int w = W;
    for (int i = n; i > 0 && dp[i][w] > 0; i--) {
        // If the value came from the current item, we packed it
        if (dp[i][w] != dp[i-1][w]) {
            packedOrders.push_back(orders[i-1]);
            w -= static_cast<int>(orders[i-1].totalWeight);
        }
    }
    
    return packedOrders;
}

#endif
