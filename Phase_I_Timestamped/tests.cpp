// tests.cpp
#include <iostream>
#include <cassert>
#include <vector>
#include "domain.h"
#include "algorithms.h"
#include "dp_algorithms.h"
#include "greedy_algorithms.h"

void testSorting() {
    std::vector<Order> orders = { 
        {"ORD3", 1, 10.0, 1}, 
        {"ORD1", 2, 5.0, 2}, 
        {"ORD2", 3, 20.0, 1} 
    };
    mergeSortOrders(orders, 0, orders.size() - 1);
    
    assert(orders[0].orderId == "ORD3"); 
    assert(orders[1].orderId == "ORD2"); 
    assert(orders[2].orderId == "ORD1"); 
    std::cout << "[TEST PASSED] Merge Sort Logic\n";
}

void testKnapsack() {
    std::vector<Order> orders = { 
        {"ORD1", 1, 5.0, 1},  // Pri 1, Wt 5
        {"ORD2", 2, 8.0, 1},  // Pri 1, Wt 8
        {"ORD3", 3, 12.0, 2}  // Pri 2, Wt 12
    };
    
    // With capacity 15, it should now correctly pick ORD1 and ORD2 
    // because Priority 1 is mathematically valued higher by our fixed logic.
    std::vector<Order> packed = packVehicleKnapsack(orders, 15.0);
    assert(packed.size() == 2); 
    
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
    assert(dist[2] == 20.0);
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
}// tests.cpp
#include <iostream>
#include <cassert>
#include <vector>
#include "domain.h"
#include "algorithms.h"
#include "dp_algorithms.h"
#include "greedy_algorithms.h"

void testSorting() {
    std::vector<Order> orders = { 
        {"ORD3", 1, 10.0, 1}, 
        {"ORD1", 2, 5.0, 2}, 
        {"ORD2", 3, 20.0, 1} 
    };
    mergeSortOrders(orders, 0, orders.size() - 1);
    
    assert(orders[0].orderId == "ORD3"); 
    assert(orders[1].orderId == "ORD2"); 
    assert(orders[2].orderId == "ORD1"); 
    std::cout << "[TEST PASSED] Merge Sort Logic\n";
}

void testKnapsack() {
    std::vector<Order> orders = { 
        {"ORD1", 1, 5.0, 1},  // Pri 1, Wt 5
        {"ORD2", 2, 8.0, 1},  // Pri 1, Wt 8
        {"ORD3", 3, 12.0, 2}  // Pri 2, Wt 12
    };
    
    // With capacity 15, it should now correctly pick ORD1 and ORD2 
    // because Priority 1 is mathematically valued higher by our fixed logic.
    std::vector<Order> packed = packVehicleKnapsack(orders, 15.0);
    assert(packed.size() == 2); 
    
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
    assert(dist[2] == 20.0);
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
}// tests.cpp
#include <iostream>
#include <cassert>
#include <vector>
#include "domain.h"
#include "algorithms.h"
#include "dp_algorithms.h"
#include "greedy_algorithms.h"

void testSorting() {
    std::vector<Order> orders = { 
        {"ORD3", 1, 10.0, 1}, 
        {"ORD1", 2, 5.0, 2}, 
        {"ORD2", 3, 20.0, 1} 
    };
    mergeSortOrders(orders, 0, orders.size() - 1);
    
    assert(orders[0].orderId == "ORD3"); 
    assert(orders[1].orderId == "ORD2"); 
    assert(orders[2].orderId == "ORD1"); 
    std::cout << "[TEST PASSED] Merge Sort Logic\n";
}

void testKnapsack() {
    std::vector<Order> orders = { 
        {"ORD1", 1, 5.0, 1},  // Pri 1, Wt 5
        {"ORD2", 2, 8.0, 1},  // Pri 1, Wt 8
        {"ORD3", 3, 12.0, 2}  // Pri 2, Wt 12
    };
    
    // With capacity 15, it should now correctly pick ORD1 and ORD2 
    // because Priority 1 is mathematically valued higher by our fixed logic.
    std::vector<Order> packed = packVehicleKnapsack(orders, 15.0);
    assert(packed.size() == 2); 
    
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
    assert(dist[2] == 20.0);
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
}// tests.cpp
#include <iostream>
#include <cassert>
#include <vector>
#include "domain.h"
#include "algorithms.h"
#include "dp_algorithms.h"
#include "greedy_algorithms.h"

void testSorting() {
    std::vector<Order> orders = { 
        {"ORD3", 1, 10.0, 1}, 
        {"ORD1", 2, 5.0, 2}, 
        {"ORD2", 3, 20.0, 1} 
    };
    mergeSortOrders(orders, 0, orders.size() - 1);
    
    assert(orders[0].orderId == "ORD3"); 
    assert(orders[1].orderId == "ORD2"); 
    assert(orders[2].orderId == "ORD1"); 
    std::cout << "[TEST PASSED] Merge Sort Logic\n";
}

void testKnapsack() {
    std::vector<Order> orders = { 
        {"ORD1", 1, 5.0, 1},  // Pri 1, Wt 5
        {"ORD2", 2, 8.0, 1},  // Pri 1, Wt 8
        {"ORD3", 3, 12.0, 2}  // Pri 2, Wt 12
    };
    
    // With capacity 15, it should now correctly pick ORD1 and ORD2 
    // because Priority 1 is mathematically valued higher by our fixed logic.
    std::vector<Order> packed = packVehicleKnapsack(orders, 15.0);
    assert(packed.size() == 2); 
    
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
    assert(dist[2] == 20.0);
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
}// tests.cpp
#include <iostream>
#include <cassert>
#include <vector>
#include "domain.h"
#include "algorithms.h"
#include "dp_algorithms.h"
#include "greedy_algorithms.h"

void testSorting() {
    std::vector<Order> orders = { 
        {"ORD3", 1, 10.0, 1}, 
        {"ORD1", 2, 5.0, 2}, 
        {"ORD2", 3, 20.0, 1} 
    };
    mergeSortOrders(orders, 0, orders.size() - 1);
    
    assert(orders[0].orderId == "ORD3"); 
    assert(orders[1].orderId == "ORD2"); 
    assert(orders[2].orderId == "ORD1"); 
    std::cout << "[TEST PASSED] Merge Sort Logic\n";
}

void testKnapsack() {
    std::vector<Order> orders = { 
        {"ORD1", 1, 5.0, 1},  // Pri 1, Wt 5
        {"ORD2", 2, 8.0, 1},  // Pri 1, Wt 8
        {"ORD3", 3, 12.0, 2}  // Pri 2, Wt 12
    };
    
    // With capacity 15, it should now correctly pick ORD1 and ORD2 
    // because Priority 1 is mathematically valued higher by our fixed logic.
    std::vector<Order> packed = packVehicleKnapsack(orders, 15.0);
    assert(packed.size() == 2); 
    
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
    assert(dist[2] == 20.0);
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
}// tests.cpp
#include <iostream>
#include <cassert>
#include <vector>
#include "domain.h"
#include "algorithms.h"
#include "dp_algorithms.h"
#include "greedy_algorithms.h"

void testSorting() {
    std::vector<Order> orders = { 
        {"ORD3", 1, 10.0, 1}, 
        {"ORD1", 2, 5.0, 2}, 
        {"ORD2", 3, 20.0, 1} 
    };
    mergeSortOrders(orders, 0, orders.size() - 1);
    
    assert(orders[0].orderId == "ORD3"); 
    assert(orders[1].orderId == "ORD2"); 
    assert(orders[2].orderId == "ORD1"); 
    std::cout << "[TEST PASSED] Merge Sort Logic\n";
}

void testKnapsack() {
    std::vector<Order> orders = { 
        {"ORD1", 1, 5.0, 1},  // Pri 1, Wt 5
        {"ORD2", 2, 8.0, 1},  // Pri 1, Wt 8
        {"ORD3", 3, 12.0, 2}  // Pri 2, Wt 12
    };
    
    // With capacity 15, it should now correctly pick ORD1 and ORD2 
    // because Priority 1 is mathematically valued higher by our fixed logic.
    std::vector<Order> packed = packVehicleKnapsack(orders, 15.0);
    assert(packed.size() == 2); 
    
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
    assert(dist[2] == 20.0);
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
}// tests.cpp
#include <iostream>
#include <cassert>
#include <vector>
#include "domain.h"
#include "algorithms.h"
#include "dp_algorithms.h"
#include "greedy_algorithms.h"

void testSorting() {
    std::vector<Order> orders = { 
        {"ORD3", 1, 10.0, 1}, 
        {"ORD1", 2, 5.0, 2}, 
        {"ORD2", 3, 20.0, 1} 
    };
    mergeSortOrders(orders, 0, orders.size() - 1);
    
    assert(orders[0].orderId == "ORD3"); 
    assert(orders[1].orderId == "ORD2"); 
    assert(orders[2].orderId == "ORD1"); 
    std::cout << "[TEST PASSED] Merge Sort Logic\n";
}

void testKnapsack() {
    std::vector<Order> orders = { 
        {"ORD1", 1, 5.0, 1},  // Pri 1, Wt 5
        {"ORD2", 2, 8.0, 1},  // Pri 1, Wt 8
        {"ORD3", 3, 12.0, 2}  // Pri 2, Wt 12
    };
    
    // With capacity 15, it should now correctly pick ORD1 and ORD2 
    // because Priority 1 is mathematically valued higher by our fixed logic.
    std::vector<Order> packed = packVehicleKnapsack(orders, 15.0);
    assert(packed.size() == 2); 
    
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
    assert(dist[2] == 20.0);
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
