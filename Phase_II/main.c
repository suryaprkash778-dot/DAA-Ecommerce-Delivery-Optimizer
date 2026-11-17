// main.c (Phase II)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "network_flow.h"
#include "string_matching.h"

void displayPhaseIIMenu() {
    printf("\n=== E-Commerce Optimizer: Phase II (C Version) ===\n");
    printf("1. Calculate Max Warehouse Dispatch (Network Flow)\n");
    printf("2. Search Delivery Logs (KMP String Matching)\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice = -1;

    while (choice != 0) {
        displayPhaseIIMenu();
        if (scanf("%d", &choice) != 1) {
            // Clear input buffer in case of non-integer input
            while (getchar() != '\n'); 
            continue;
        }
        
        // Clear trailing newline left by scanf
        while (getchar() != '\n');

        switch (choice) {
            case 1: {
                printf("\n--- Warehouse Dispatch Capacity ---\n");
                // Node 0: Fulfillment Center, Node 5: Target Zone
                // Intermediary nodes 1-4 represent sorting hubs with specific capacities
                int capacityGraph[6][6] = {
                    {0, 16, 13, 0, 0, 0},
                    {0, 0, 10, 12, 0, 0},
                    {0, 4, 0, 0, 14, 0},
                    {0, 0, 9, 0, 0, 20},
                    {0, 0, 0, 7, 0, 4},
                    {0, 0, 0, 0, 0, 0}
                };
                
                int source = 0;
                int sink = 5;
                
                // Assuming calculateMaxFlow takes the number of vertices (6) and the 2D array
                int maxFlow = calculateMaxFlow(6, capacityGraph, source, sink);
                
                printf("[SUCCESS] Maximum simultaneous packages that can be dispatched: %d units/hr\n", maxFlow);
                break;
            }

            case 2: {
                printf("\n--- Delivery Event Log Search ---\n");
                char eventLog[] = "System Start... ORD123 DISPATCHED... ALERT: ORD123 DELAYED AT HUB... "
                                  "ORD124 DISPATCHED... ALERT: ORD125 DELAYED AT HUB... ROUTING UPDATED.";
                char searchPattern[] = "DELAYED AT HUB";
                
                printf("Log Data: %s\n", eventLog);
                printf("Searching for pattern: \"%s\"\n", searchPattern);
                
                int matchCount = 0;
                // Assuming searchDeliveryEvent returns a dynamically allocated int array and updates matchCount
                int* matches = searchDeliveryEvent(eventLog, searchPattern, &matchCount);
                
                if (matchCount == 0) {
                    printf("[RESULT] No matching events found in the log.\n");
                } else {
                    printf("[RESULT] Found %d occurrence(s) at indices: ", matchCount);
                    for (int i = 0; i < matchCount; i++) {
                        printf("%d ", matches[i]);
                    }
                    printf("\n");
                }
                
                // Free dynamically allocated memory
                if (matches != NULL) {
                    free(matches);
                }
                break;
            }

            case 0:
                printf("Exiting Phase II...\n");
                break;

            default:
                printf("[ERROR] Invalid choice. Try again.\n");
        }
    }
    return 0;
}
