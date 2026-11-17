// network_flow.h
#ifndef NETWORK_FLOW_H
#define NETWORK_FLOW_H

#include <stdbool.h>
#include <limits.h>

// Macro to find the minimum of two values
#define MIN_VAL(a, b) ((a) < (b) ? (a) : (b))

// BFS to find augmenting paths in the residual capacity graph
// Note: We use C99 Variable Length Arrays (VLA) for the 2D array parameters and local arrays
static inline bool bfsAugmentingPath(int numNodes, int residualGraph[numNodes][numNodes], int source, int sink, int parentPath[]) {
    // Array to track visited nodes
    bool visited[numNodes];
    for (int i = 0; i < numNodes; i++) {
        visited[i] = false;
    }

    // Simple array-based queue for BFS
    int q[numNodes];
    int front = 0, rear = 0;
    
    q[rear++] = source;
    visited[source] = true;
    parentPath[source] = -1;

    while (front < rear) {
        int u = q[front++];

        for (int v = 0; v < numNodes; v++) {
            // If not visited and there is available capacity on the edge
            if (!visited[v] && residualGraph[u][v] > 0) {
                if (v == sink) {
                    parentPath[v] = u;
                    return true;
                }
                q[rear++] = v;
                parentPath[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

// Ford-Fulkerson algorithm for Maximum Warehouse Dispatch Flow
static inline int calculateMaxFlow(int numNodes, int capacityGraph[numNodes][numNodes], int source, int sink) {
    int u, v;
    
    // Create a residual graph initialized identically to the capacity graph
    int residualGraph[numNodes][numNodes];
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            residualGraph[i][j] = capacityGraph[i][j];
        }
    }
    
    int parentPath[numNodes];
    int maxFlow = 0;

    // Augment the flow while there is a path from source to sink
    while (bfsAugmentingPath(numNodes, residualGraph, source, sink, parentPath)) {
        int pathFlow = INT_MAX;
        
        // Find the maximum flow through the augmenting path
        for (v = sink; v != source; v = parentPath[v]) {
            u = parentPath[v];
            pathFlow = MIN_VAL(pathFlow, residualGraph[u][v]);
        }

        // Update residual capacities of the edges and reverse edges
        for (v = sink; v != source; v = parentPath[v]) {
            u = parentPath[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }
    
    return maxFlow;
}

#endif
