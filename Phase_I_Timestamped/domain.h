// domain.h
#ifndef DOMAIN_H
#define DOMAIN_H

#include <string>
#include <vector>

// Represents customer locations, warehouses, or road junctions
struct Location {
    int nodeId;
    double lat;
    double lon;
};

// Represents an e-commerce order[cite: 1]
struct Order {
    std::string orderId;
    int destinationNode;
    double totalWeight;
    int priority; // 1 = High (Express), 2 = Standard
};

// Represents a delivery vehicle[cite: 1]
struct Vehicle {
    std::string vehicleId;
    int startNode;
    double weightCapacity;
};

// Weighted graph edge representing the delivery network (roads)[cite: 1]
struct Edge {
    int targetNode;
    double travelTime;
    double cost;
};

// Adjacency list representation of the delivery network graph[cite: 1]
using DeliveryNetwork = std::vector<std::vector<Edge>>;

#endif
