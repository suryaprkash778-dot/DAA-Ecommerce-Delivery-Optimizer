// tests.c
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "network_flow.h"
#include "string_matching.h"

void testNetworkFlow() {
    // Standard test case for max flow
    int capacityGraph[6][6] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };
    
    int maxFlow = calculateMaxFlow(6, capacityGraph, 0, 5);
    
    // The known maximum flow for this graph is 23
    assert(maxFlow == 23);
    printf("[TEST PASSED] Network Flow (Edmonds-Karp / Ford-Fulkerson)\n");
}

void testStringMatching() {
    char eventLog[] = "System Start... ORD123 DISPATCHED... ALERT: ORD123 DELAYED AT HUB...";
    char pattern[] = "DELAYED";
    char missingPattern[] = "CRASH";
    
    // Normal Case: Find existing pattern
    int matchCount = 0;
    int* matches = searchDeliveryEvent(eventLog, pattern, &matchCount);
    assert(matchCount == 1);
    assert(matches[0] == 43); // "DELAYED" starts at index 43
    
    // Free the dynamically allocated array
    if (matches != NULL) {
        free(matches);
    }
    
    // Boundary Case: Pattern not in text
    int noMatchCount = 0;
    int* noMatches = searchDeliveryEvent(eventLog, missingPattern, &noMatchCount);
    assert(noMatchCount == 0);
    assert(noMatches == NULL);
    
    printf("[TEST PASSED] KMP String Matching\n");
}

int main() {
    printf("--- Running Phase II Automated Tests ---\n");
    testNetworkFlow();
    testStringMatching();
    printf("--- All Phase II Tests Passed! ---\n");
    return 0;
}
