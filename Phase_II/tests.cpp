// tests.cpp (Phase II)
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include "network_flow.h"
#include "string_matching.h"

void testNetworkFlow() {
    // Standard test case for max flow
    std::vector<std::vector<int>> capacityGraph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };
    
    int maxFlow = calculateMaxFlow(capacityGraph, 0, 5);
    
    // The known maximum flow for this graph is 23
    assert(maxFlow == 23);
    std::cout << "[TEST PASSED] Network Flow (Edmonds-Karp / Ford-Fulkerson)\n";
}

void testStringMatching() {
    std::string eventLog = "System Start... ORD123 DISPATCHED... ALERT: ORD123 DELAYED AT HUB...";
    std::string pattern = "DELAYED";
    std::string missingPattern = "CRASH";
    
    // Normal Case: Find existing pattern
    std::vector<int> matches = searchDeliveryEvent(eventLog, pattern);
    assert(matches.size() == 1);
    assert(matches[0] == 43); // "DELAYED" starts at index 43
    
    // Boundary Case: Pattern not in text
    std::vector<int> noMatches = searchDeliveryEvent(eventLog, missingPattern);
    assert(noMatches.empty());
    
    std::cout << "[TEST PASSED] KMP String Matching\n";
}

int main() {
    std::cout << "--- Running Phase II Automated Tests ---\n";
    testNetworkFlow();
    testStringMatching();
    std::cout << "--- All Phase II Tests Passed! ---\n";
    return 0;
}
