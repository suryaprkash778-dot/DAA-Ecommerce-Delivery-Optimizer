// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "domain.h"
#include "algorithms.h"
#include "dp_algorithms.h"
#include "greedy_algorithms.h"

void displayMenu() {
    printf("\n=== E-Commerce Order & Delivery Optimizer (C Version) ===\n");
    printf("1. Load Dummy Order Data\n");
    printf("2. Sort Orders (Merge Sort)\n");
    printf("3. Search Order (Binary Search)\n");
    printf("4. Pack Delivery Vehicle (0/1 Knapsack DP)\n");
    printf("5. Calculate Shortest Routes (Dijkstra)\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    Order orders[MAX_NODES];
    int num_orders = 0;
    int choice = -1;

    // Menu-driven CLI for loading data, selecting algorithms, and running scenarios.
    while (choice != 0) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            // Clear input buffer in case of non-integer input
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                // Loading small, reproducible datasets for testing.
                orders[0] = (Order){"ORD003", 5, 12.5, 2};
                orders[1] = (Order){"ORD001", 2, 5.0, 1};
                orders[2] = (Order){"ORD002", 8, 20.0, 1};
                orders[3] = (Order){"ORD004", 3, 2.5, 2};
                num_orders = 4;
                
                printf("[SUCCESS] 4 dummy orders loaded.\n");
                break;

            case 2:
                if (num_orders == 0) {
                    printf("[ERROR] Please load data first (Option 1).\n");
                    break;
                }
                // Testing the Divide and Conquer module.
                mergeSortOrders(orders, 0, num_orders - 1);
                
                printf("[SUCCESS] Orders sorted by Priority (High=1, Std=2) then Weight:\n");
                for (int i = 0; i < num_orders; i++) {
                    printf(" - %s | Pri: %d | Wt: %.1f | Dest Node: %d\n", 
                           orders[i].orderId, orders[i].priority, 
                           orders[i].totalWeight, orders[i].destinationNode);
                }
                break;

            case 3: {
                if (num_orders == 0) {
                    printf("[ERROR] Please load and sort data first.\n");
                    break;
                }
                
                char targetId[MAX_ID_LENGTH];
                printf("Enter Order ID to search (e.g., ORD002): ");
                scanf("%s", targetId);
                
                // Array must be sorted by ID for binary search to work properly; 
                // We run quick sort here first to ensure the array is sorted alphabetically.
                quickSortOrdersById(orders, 0, num_orders - 1);
                
                int index = binarySearchOrder(orders, num_orders, targetId);
                if (index != -1) {
                    printf("[FOUND] Order at index %d | Weight: %.1f | Priority: %d\n", 
                           index, orders[index].totalWeight, orders[index].priority);
                } else {
                    printf("[NOT FOUND] Order ID does not exist.\n");
                }
                break;
            }

            case 4: {
                if (num_orders == 0) {
                    printf("[ERROR] Please load data first (Option 1).\n");
                    break;
                }
                // Testing dynamic programming 0/1 knapsack implementation.
                Vehicle truck = {"TRK-99", 0, 15.0}; // Vehicle with 15kg capacity
                printf("\nAttempting to pack vehicle %s (Capacity: %.1fkg)\n", 
                       truck.vehicleId, truck.weightCapacity);
                
                int packedCount = 0;
                Order* packed = packVehicleKnapsack(orders, num_orders, truck.weightCapacity, &packedCount);
                
                double totalPackedWeight = 0;
                printf("[SUCCESS] Packed Orders:\n");
                for (int i = 0; i < packedCount; i++) {
                    printf(" - %s | Pri: %d | Wt: %.1f\n", 
                           packed[i].orderId, packed[i].priority, packed[i].totalWeight);
                    totalPackedWeight += packed[i].totalWeight;
                }
                printf("Total Weight Packed: %.1fkg / %.1fkg\n", totalPackedWeight, truck.weightCapacity);
                
                // Free the dynamically allocated array
                free(packed);
                break;
            }

            case 5: {
                // Testing Greedy Methods (Dijkstra) implementation
                printf("\n--- Calculating Shortest Delivery Routes ---\n");
                
                // Create a dummy network graph with 4 nodes (0 to 3)
                // Node 0: Fulfillment Center, Nodes 1-3: Customer Zones
                DeliveryNetwork network;
                
                // Initialize edge counts to 0 for all nodes
                for (int i = 0; i < 4; i++) {
                    network[i].edgeCount = 0;
                }
                
                // Add edges: {targetNode, travelTime, cost}
                network[0].edges[network[0].edgeCount++] = (Edge){1, 10.5, 5.0};
                network[0].edges[network[0].edgeCount++] = (Edge){2, 15.0, 7.5};
                network[1].edges[network[1].edgeCount++] = (Edge){2, 3.5,  2.0};
                network[1].edges[network[1].edgeCount++] = (Edge){3, 20.0, 10.0};
                network[2].edges[network[2].edgeCount++] = (Edge){3, 10.0, 5.0};
                
                int fulfillmentCenter = 0;
                double* shortestTimes = calculateShortestPaths(network, 4, fulfillmentCenter);
                
                printf("[SUCCESS] Shortest travel times from Fulfillment Center (Node 0):\n");
                for (int i = 0; i < 4; i++) {
                    if (shortestTimes[i] == INFINITY) {
                        printf(" - Node %d: Unreachable\n", i);
                    } else {
                        printf(" - Node %d: %.1f mins\n", i, shortestTimes[i]);
                    }
                }
                
                // Free the dynamically allocated array
                free(shortestTimes);
                break;
            }

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("[ERROR] Invalid choice. Try again.\n");
        }
    }
    return 0;
}
