// dp_algorithms.h
#ifndef DP_ALGORITHMS_H
#define DP_ALGORITHMS_H

#include "domain.h"
#include <stdlib.h>

// Helper function to find the maximum of two integers
static inline int max_val(int a, int b) {
    return (a > b) ? a : b;
}

// 0/1 Knapsack DP to maximize vehicle packing
// Returns a dynamically allocated array of packed Orders. 
// The number of packed orders is stored in the integer pointed to by packedCount.
// NOTE: The caller is responsible for freeing the returned memory.
static inline Order* packVehicleKnapsack(const Order orders[], int n, double weightCapacity, int* packedCount) {
    int W = (int)weightCapacity; 
    
    // DP table allocation and initialization to 0
    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int*)calloc((W + 1), sizeof(int));
    }
    
    // Build table
    for (int i = 1; i <= n; i++) {
        int wt = (int)orders[i-1].totalWeight;
        
        // FIX: Invert priority for DP math. Priority 1 (High) = 10 value, Priority 2 (Std) = 5 value.
        int val = (orders[i-1].priority == 1) ? 10 : 5; 
        
        for (int w = 0; w <= W; w++) {
            if (wt <= w) {
                dp[i][w] = max_val(val + dp[i-1][w - wt], dp[i-1][w]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    // Backtrack to find which exact orders were packed
    Order* packedOrders = (Order*)malloc(n * sizeof(Order)); // Max possible size is n
    *packedCount = 0;
    
    int w = W;
    for (int i = n; i > 0 && dp[i][w] > 0; i--) {
        // If the value came from the current item, we packed it
        if (dp[i][w] != dp[i-1][w]) {
            packedOrders[*packedCount] = orders[i-1];
            (*packedCount)++;
            w -= (int)orders[i-1].totalWeight;
        }
    }
    
    // Free the dynamically allocated DP table
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return packedOrders;
}

#endif
