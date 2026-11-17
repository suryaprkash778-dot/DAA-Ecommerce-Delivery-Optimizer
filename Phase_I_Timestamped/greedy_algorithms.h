// greedy_algorithms.h
#ifndef GREEDY_ALGORITHMS_H
#define GREEDY_ALGORITHMS_H

#include "domain.h"
#include <stdlib.h>
#include <math.h>

// --- Min-Heap Priority Queue Implementation for C ---
typedef struct {
    double dist;
    int node;
} PQNode;

typedef struct {
    PQNode* nodes;
    int size;
    int capacity;
} MinPQ;

static inline void swapPQNode(PQNode* a, PQNode* b) {
    PQNode temp = *a;
    *a = *b;
    *b = temp;
}

static inline void pushPQ(MinPQ* pq, double dist, int node) {
    if (pq->size == pq->capacity) return; // Safeguard against overflow
    
    int i = pq->size++;
    pq->nodes[i] = (PQNode){dist, node};
    
    // Heapify up
    while (i != 0 && pq->nodes[(i - 1) / 2].dist > pq->nodes[i].dist) {
        swapPQNode(&pq->nodes[i], &pq->nodes[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

static inline void minHeapify(MinPQ* pq, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < pq->size && pq->nodes[left].dist < pq->nodes[smallest].dist) smallest = left;
    if (right < pq->size && pq->nodes[right].dist < pq->nodes[smallest].dist) smallest = right;
    
    if (smallest != i) {
        swapPQNode(&pq->nodes[i], &pq->nodes[smallest]);
        minHeapify(pq, smallest);
    }
}

static inline PQNode popPQ(MinPQ* pq) {
    if (pq->size <= 0) return (PQNode){0, -1};
    if (pq->size == 1) return pq->nodes[--pq->size];
    
    PQNode root = pq->nodes[0];
    pq->nodes[0] = pq->nodes[--pq->size];
    minHeapify(pq, 0);
    
    return root;
}

static inline int isEmptyPQ(MinPQ* pq) {
    return pq->size == 0;
}
// ---------------------------------------------------

// Dijkstra's algorithm to find non-negative shortest paths for delivery routing
// Returns a dynamically allocated array of distances. 
// NOTE: The caller is responsible for freeing the returned memory.
static inline double* calculateShortestPaths(const DeliveryNetwork graph, int numNodes, int sourceNode) {
    double* dist = (double*)malloc(numNodes * sizeof(double));
    for (int i = 0; i < numNodes; i++) {
        dist[i] = INFINITY;
    }
    dist[sourceNode] = 0.0;

    MinPQ pq;
    pq.capacity = MAX_NODES * MAX_EDGES_PER_NODE; // Max possible queue size
    pq.size = 0;
    pq.nodes = (PQNode*)malloc(pq.capacity * sizeof(PQNode));

    pushPQ(&pq, 0.0, sourceNode);

    while (!isEmptyPQ(&pq)) {
        PQNode current = popPQ(&pq);
        double currentDist = current.dist;
        int u = current.node;

        // Skip if we already found a shorter path to u
        if (currentDist > dist[u]) continue;

        // Traverse all adjacent nodes
        for (int i = 0; i < graph[u].edgeCount; i++) {
            int v = graph[u].edges[i].targetNode;
            double weight = graph[u].edges[i].travelTime; // Routing optimized for travel time

            // Relaxation step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pushPQ(&pq, dist[v], v);
            }
        }
    }

    free(pq.nodes);
    return dist;
}

#endif
