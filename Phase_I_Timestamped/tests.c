// tests.c
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "domain.h"
#include "algorithms.h"
#include "dp_algorithms.h"
#include "greedy_algorithms.h"

void testSorting() {
    Order orders[3] = { 
        {"ORD3", 1, 10.0, 1}, 
        {"ORD1", 2, 5.0, 2}, 
        {"ORD2", 3, 20.0, 1} 
    };
    
    // Sort by priority, then weight
    mergeSortOrders(orders, 0, 2);
    
    // In our C implementation, mergeSortOrders sorts descending based on priority/weight logic
    assert(strcmp(orders[0].orderId, "ORD3") == 0); 
    assert(strcmp(orders[1].orderId, "ORD2") == 0); 
    assert(strcmp(orders[2].orderId, "ORD1") == 0); 
    printf("[TEST PASSED] Merge Sort Logic\n");
}

void testKnapsack() {
    Order orders[3] = { 
        {"ORD1", 1, 5.0, 1},  // Pri 1, Wt 5
        {"ORD2", 2, 8.0, 1},  // Pri 1, Wt 8
        {"ORD3", 3, 12.0, 2}  // Pri 2, Wt 12
    };
    
    int packedCount = 0;
    Order* packed = packVehicleKnapsack(orders, 3, 15.0, &packedCount);
    
    assert(packedCount == 2); 
    free(packed);
    
    int zeroPackedCount = 0;
    Order* zeroPacked = packVehicleKnapsack(orders, 3, 0.0, &zeroPackedCount);
    assert(zeroPackedCount == 0); 
    free(zeroPacked);
    
    printf("[TEST PASSED] 0/1 Knapsack DP\n");
}

void testDijkstra() {
    DeliveryNetwork network;
    
    // Initialize edge counts
    for (int i = 0; i < 3; i++) {
        network[i].edgeCount = 0;
    }
    
    // Add edges
    network[0].edges[network[0].edgeCount++] = (Edge){1, 10.0, 5.0};
    network[0].edges[network[0].edgeCount++] = (Edge){2, 50.0, 10.0};
    network[1].edges[network[1].edgeCount++] = (Edge){2, 10.0, 5.0};
    
    double* dist = calculateShortestPaths(network, 3, 0);
    
    assert(dist[2] == 20.0);
    assert(dist[0] == 0.0);
    
    free(dist);
    printf("[TEST PASSED] Dijkstra Shortest Path\n");
}

int main() {
    printf("--- Running Automated Unit Tests ---\n");
    testSorting();
    testKnapsack();
    testDijkstra();
    printf("--- All Phase I Tests Passed! ---\n");
    return 0;
}
