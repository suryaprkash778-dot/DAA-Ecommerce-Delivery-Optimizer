// domain.h
#ifndef DOMAIN_H
#define DOMAIN_H

#define MAX_ID_LENGTH 50
#define MAX_NODES 100
#define MAX_EDGES_PER_NODE 50

// Represents customer locations, warehouses, or road junctions
typedef struct {
    int nodeId;
    double lat;
    double lon;
} Location;

// Represents an e-commerce order
typedef struct {
    char orderId[MAX_ID_LENGTH];
    int destinationNode;
    double totalWeight;
    int priority; // 1 = High (Express), 2 = Standard
} Order;

// Represents a delivery vehicle
typedef struct {
    char vehicleId[MAX_ID_LENGTH];
    int startNode;
    double weightCapacity;
} Vehicle;

// Weighted graph edge representing the delivery network (roads)
typedef struct {
    int targetNode;
    double travelTime;
    double cost;
} Edge;

// Adjacency list representation of the delivery network graph for C
typedef struct {
    Edge edges[MAX_EDGES_PER_NODE];
    int edgeCount;
} NodeEdges;

// Equivalent to std::vector<std::vector<Edge>> using standard C arrays
typedef NodeEdges DeliveryNetwork[MAX_NODES];

#endif
