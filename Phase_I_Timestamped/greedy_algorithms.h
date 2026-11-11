case 5: {
                // Testing Greedy Methods (Dijkstra) implementation[cite: 1]
                std::cout << "\n--- Calculating Shortest Delivery Routes ---\n";
                
                // Create a dummy network graph with 4 nodes (0 to 3)[cite: 1]
                // Node 0: Fulfillment Center, Nodes 1-3: Customer Zones
                DeliveryNetwork network(4);
                
                // Add edges: {targetNode, travelTime, cost}
                network[0].push_back({1, 10.5, 5.0});
                network[0].push_back({2, 15.0, 7.5});
                network[1].push_back({2, 3.5,  2.0});
                network[1].push_back({3, 20.0, 10.0});
                network[2].push_back({3, 10.0, 5.0});
                
                int fulfillmentCenter = 0;
                std::vector<double> shortestTimes = calculateShortestPaths(network, fulfillmentCenter);
                
                std::cout << "[SUCCESS] Shortest travel times from Fulfillment Center (Node 0):\n";
                for (size_t i = 0; i < shortestTimes.size(); ++i) {
                    if (shortestTimes[i] == std::numeric_limits<double>::infinity()) {
                        std::cout << " - Node " << i << ": Unreachable\n";
                    } else {
                        std::cout << " - Node " << i << ": " << shortestTimes[i] << " mins\n";
                    }
                }
                break;
            }
