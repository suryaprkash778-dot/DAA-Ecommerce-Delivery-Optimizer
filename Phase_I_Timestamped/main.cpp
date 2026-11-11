// main.cpp
#include <iostream>
#include <vector>
#include <string>
#include "domain.h"
#include "algorithms.h"
#include "dp_algorithms.h"

void displayMenu() {
    std::cout << "\n=== E-Commerce Order & Delivery Optimizer ===\n";
    std::cout << "1. Load Dummy Order Data\n";
    std::cout << "2. Sort Orders (Merge Sort)\n";
    std::cout << "3. Search Order (Binary Search)\n";
    std::cout << "4. Pack Delivery Vehicle (0/1 Knapsack DP)\n";
    std::cout << "5. Calculate Shortest Routes (Dijkstra - Pending)\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    std::vector<Order> orders;
    int choice = -1;

    // Menu-driven CLI for loading data, selecting algorithms, and running scenarios.
    while (choice != 0) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                // Loading small, reproducible datasets for testing.
                orders = {
                    {"ORD003", 5, 12.5, 2},
                    {"ORD001", 2, 5.0, 1},
                    {"ORD002", 8, 20.0, 1},
                    {"ORD004", 3, 2.5, 2}
                };
                std::cout << "[SUCCESS] 4 dummy orders loaded.\n";
                break;

            case 2:
                if (orders.empty()) {
                    std::cout << "[ERROR] Please load data first (Option 1).\n";
                    break;
                }
                // Testing the Divide and Conquer module[cite: 1].
                mergeSortOrders(orders, 0, orders.size() - 1);
                std::cout << "[SUCCESS] Orders sorted by Priority (High=1, Std=2) then Weight:\n";
                for (const auto& o : orders) {
                    std::cout << " - " << o.orderId << " | Pri: " << o.priority 
                              << " | Wt: " << o.totalWeight << " | Dest Node: " << o.destinationNode << "\n";
                }
                break;

            case 3: {
                if (orders.empty()) {
                    std::cout << "[ERROR] Please load and sort data first.\n";
                    break;
                }
                std::string targetId;
                std::cout << "Enter Order ID to search (e.g., ORD002): ";
                std::cin >> targetId;
                
                // Array must be sorted by ID for binary search to work properly; 
                // in a production build, you would maintain a separate index[cite: 1].
                int index = binarySearchOrder(orders, targetId);
                if (index != -1) {
                    std::cout << "[FOUND] Order at index " << index 
                              << " | Weight: " << orders[index].totalWeight 
                              << " | Priority: " << orders[index].priority << "\n";
                } else {
                    std::cout << "[NOT FOUND] Order ID does not exist.\n";
                }
                break;
            }

            case 4: {
                if (orders.empty()) {
                    std::cout << "[ERROR] Please load data first (Option 1).\n";
                    break;
                }
                // Testing dynamic programming 0/1 knapsack implementation[cite: 1].
                Vehicle truck = {"TRK-99", 0, 15.0}; // Vehicle with 15kg capacity
                std::cout << "\nAttempting to pack vehicle " << truck.vehicleId 
                          << " (Capacity: " << truck.weightCapacity << "kg)\n";
                
                std::vector<Order> packed = packVehicleKnapsack(orders, truck.weightCapacity);
                
                double totalPackedWeight = 0;
                std::cout << "[SUCCESS] Packed Orders:\n";
                for (const auto& o : packed) {
                    std::cout << " - " << o.orderId << " | Pri: " << o.priority 
                              << " | Wt: " << o.totalWeight << "\n";
                    totalPackedWeight += o.totalWeight;
                }
                std::cout << "Total Weight Packed: " << totalPackedWeight << "kg / " 
                          << truck.weightCapacity << "kg\n";
                break;
            }

            case 5:
                std::cout << "[PENDING] Greedy Methods (Dijkstra) module not yet implemented.\n";
                break;

            case 0:
                std::cout << "Exiting...\n";
                break;

            default:
                std::cout << "[ERROR] Invalid choice. Try again.\n";
        }
    }
    return 0;
}
