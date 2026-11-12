// main.cpp (Phase II)
#include <iostream>
#include <vector>
#include <string>
#include "network_flow.h"
#include "string_matching.h"

void displayPhaseIIMenu() {
    std::cout << "\n=== E-Commerce Optimizer: Phase II ===\n";
    std::cout << "1. Calculate Max Warehouse Dispatch (Network Flow)\n";
    std::cout << "2. Search Delivery Logs (KMP String Matching)\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    int choice = -1;

    while (choice != 0) {
        displayPhaseIIMenu();
        std::cin >> choice;
        std::cin.ignore(); // Clear newline for getline later

        switch (choice) {
            case 1: {
                std::cout << "\n--- Warehouse Dispatch Capacity ---\n";
                // Node 0: Fulfillment Center, Node 5: Target Zone
                // Intermediary nodes 1-4 represent sorting hubs with specific capacities
                std::vector<std::vector<int>> capacityGraph = {
                    {0, 16, 13, 0, 0, 0},
                    {0, 0, 10, 12, 0, 0},
                    {0, 4, 0, 0, 14, 0},
                    {0, 0, 9, 0, 0, 20},
                    {0, 0, 0, 7, 0, 4},
                    {0, 0, 0, 0, 0, 0}
                };
                
                int source = 0;
                int sink = 5;
                int maxFlow = calculateMaxFlow(capacityGraph, source, sink);
                
                std::cout << "[SUCCESS] Maximum simultaneous packages that can be dispatched: " 
                          << maxFlow << " units/hr\n";
                break;
            }

            case 2: {
                std::cout << "\n--- Delivery Event Log Search ---\n";
                std::string eventLog = "System Start... ORD123 DISPATCHED... ALERT: ORD123 DELAYED AT HUB... "
                                       "ORD124 DISPATCHED... ALERT: ORD125 DELAYED AT HUB... ROUTING UPDATED.";
                std::string searchPattern = "DELAYED AT HUB";
                
                std::cout << "Log Data: " << eventLog << "\n";
                std::cout << "Searching for pattern: \"" << searchPattern << "\"\n";
                
                std::vector<int> matches = searchDeliveryEvent(eventLog, searchPattern);
                
                if (matches.empty()) {
                    std::cout << "[RESULT] No matching events found in the log.\n";
                } else {
                    std::cout << "[RESULT] Found " << matches.size() << " occurrence(s) at indices: ";
                    for (int index : matches) {
                        std::cout << index << " ";
                    }
                    std::cout << "\n";
                }
                break;
            }

            case 0:
                std::cout << "Exiting Phase II...\n";
                break;

            default:
                std::cout << "[ERROR] Invalid choice. Try again.\n";
        }
    }
    return 0;
}
