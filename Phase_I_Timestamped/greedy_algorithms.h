// greedy_algorithms.h
#ifndef GREEDY_ALGORITHMS_H
#define GREEDY_ALGORITHMS_H

#include "domain.h"
#include <vector>
#include <queue>
#include <limits>
#include <iostream>
#include <utility>

// Dijkstra's algorithm to find non-negative shortest paths for delivery routing[cite: 1]
inline std::vector<double> calculateShortestPaths(const DeliveryNetwork& graph, int sourceNode) {
    int n = graph.size();
    std::vector<double> dist(n, std::numeric_limits<double>::infinity());
    dist[sourceNode] = 0.0;

    // Min-heap priority queue storing pairs of (distance, node)
    using pdi = std::pair<double, int>;
    std::priority_queue<pdi, std::vector<pdi>, std::greater<pdi>> pq;
    
    pq.push({0.0, sourceNode});

    while (!pq.empty()) {
        double currentDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Skip if we already found a shorter path to u
        if (currentDist > dist[u]) continue;

        // Traverse all adjacent nodes
        for (const Edge& edge : graph[u]) {
            int v = edge.targetNode;
            double weight = edge.travelTime; // Routing optimized for travel time

            // Relaxation step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

#endif
