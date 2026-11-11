// network_flow.h
#ifndef NETWORK_FLOW_H
#define NETWORK_FLOW_H

#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

// BFS to find augmenting paths in the residual capacity graph
inline bool bfsAugmentingPath(const std::vector<std::vector<int>>& residualGraph, int source, int sink, std::vector<int>& parentPath) {
    int numNodes = residualGraph.size();
    std::vector<bool> visited(numNodes, false);
    std::queue<int> q;
    
    q.push(source);
    visited[source] = true;
    parentPath[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < numNodes; v++) {
            // If not visited and there is available capacity on the edge
            if (!visited[v] && residualGraph[u][v] > 0) {
                if (v == sink) {
                    parentPath[v] = u;
                    return true;
                }
                q.push(v);
                parentPath[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

// Ford-Fulkerson algorithm for Maximum Warehouse Dispatch Flow
inline int calculateMaxFlow(const std::vector<std::vector<int>>& capacityGraph, int source, int sink) {
    int u, v;
    int numNodes = capacityGraph.size();
    
    // Create a residual graph initialized identically to the capacity graph
    std::vector<std::vector<int>> residualGraph = capacityGraph;
    std::vector<int> parentPath(numNodes);
    int maxFlow = 0;

    // Augment the flow while there is a path from source to sink
    while (bfsAugmentingPath(residualGraph, source, sink, parentPath)) {
        int pathFlow = std::numeric_limits<int>::max();
        
        // Find the maximum flow through the augmenting path
        for (v = sink; v != source; v = parentPath[v]) {
            u = parentPath[v];
            pathFlow = std::min(pathFlow, residualGraph[u][v]);
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
