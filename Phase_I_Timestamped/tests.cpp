// tests.cpp
#include <iostream>
#include <cassert>
#include <vector>
#include "domain.h"
#include "algorithms.h"
#include "dp_algorithms.h"
#include "greedy_algorithms.h"

void testSorting() {
    // Struct: {orderId, destinationNode, totalWeight, priority}
    std::vector<Order> orders = { 
        {"ORD3", 1, 10.0, 1}, 
        {"ORD1", 2, 5.0, 2}, 
        {"ORD2", 3, 20.0, 1} 
    };
    
    mergeSortOrders(orders, 0, orders.size() - 1);
    
    // Normal Case: Priority 1 items come before Priority 2.
    // Within Priority 1, lighter weights come first.
    assert(orders[0].orderId == "ORD3"); // Pri 1, Wt 10
    assert(orders[1].orderId == "ORD2"); // Pri 1, Wt 20
    assert(orders[2].orderId == "ORD1"); // Pri 2, Wt 5
    
    std::cout << "[TEST PASSED] Merge Sort Logic\n";
}

void testKnapsack() {
    // Struct: {orderId, destinationNode, totalWeight, priority}
    std::vector<Order> orders = { 
        {"ORD1", 1, 5.0, 1},  // Weight 5.0
        {"ORD2", 2, 8.0, 1},  // Weight 8.0
        {"ORD3", 3, 12.0, 2}  // Weight 12.0
    };
    
    // Normal Case: Capacity 15. Should pick ORD1 (Wt 5) and ORD2 (Wt 8).
    // Total weight 13 <= 15.
    std::vector<Order> packed = packVehicleKnapsack(orders, 15.0);
    assert(packed.size() == 2);
    
    // Boundary Case: Zero capacity
    std::vector<Order> zeroPacked = packVehicleKnapsack(orders, 0.0);
    assert(zeroPacked.empty());
    
    std::cout << "[TEST PASSED] 0/1 Knapsack DP\n";
}

void testDijkstra() {
    DeliveryNetwork network(3);
    network[0].push_back({1, 10.0, 5.0});
    network[0].push_back({2, 50.0, 10.0});
    network[1].push_back({2, 10.0, 5.0});
    
    std::vector<double> dist = calculateShortestPaths(network, 0);
    
    // Normal Case: 0->1->2 (10+10=20) is faster than direct 0->2 (50)
    assert(dist[2] == 20.0);
    
    // Boundary Case: Path to self is 0
    assert(dist[0] == 0.0);
    
    std::cout << "[TEST PASSED] Dijkstra Shortest Path\n";
}

int main() {
    std::cout << "--- Running Automated Unit Tests ---\n";
    testSorting();
    testKnapsack();
    testDijkstra();
    std::cout << "--- All Phase I Tests Passed! ---\n";
    return 0;
}
