// algorithms.h
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "domain.h"
#include <stdlib.h>
#include <string.h>

// Merge Sort to prioritize orders by weight or priority
static inline void merge(Order orders[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    Order *L = (Order *)malloc(n1 * sizeof(Order));
    Order *R = (Order *)malloc(n2 * sizeof(Order));

    for (int i = 0; i < n1; i++) L[i] = orders[left + i];
    for (int j = 0; j < n2; j++) R[j] = orders[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        // Sorting by priority first, then weight
        if (L[i].priority < R[j].priority || (L[i].priority == R[j].priority && L[i].totalWeight <= R[j].totalWeight)) {
            orders[k++] = L[i++];
        } else {
            orders[k++] = R[j++];
        }
    }
    while (i < n1) orders[k++] = L[i++];
    while (j < n2) orders[k++] = R[j++];

    free(L);
    free(R);
}

static inline void mergeSortOrders(Order orders[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortOrders(orders, left, mid);
        mergeSortOrders(orders, mid + 1, right);
        merge(orders, left, mid, right);
    }
}

// Quick Sort to organize orders alphabetically by orderId
static inline int partition(Order orders[], int left, int right) {
    char* pivot = orders[right].orderId;
    int i = (left - 1);
    for (int j = left; j <= right - 1; j++) {
        // String comparison for alphabetical sorting
        if (strcmp(orders[j].orderId, pivot) < 0) {
            i++;
            // Swap orders[i] and orders[j]
            Order temp = orders[i];
            orders[i] = orders[j];
            orders[j] = temp;
        }
    }
    // Swap orders[i + 1] and orders[right]
    Order temp = orders[i + 1];
    orders[i + 1] = orders[right];
    orders[right] = temp;
    
    return (i + 1);
}

static inline void quickSortOrdersById(Order orders[], int left, int right) {
    if (left < right) {
        int pi = partition(orders, left, right);
        quickSortOrdersById(orders, left, pi - 1);
        quickSortOrdersById(orders, pi + 1, right);
    }
}

// Iterative binary search to retrieve a specific order by orderId (requires array to be sorted by ID first)
static inline int binarySearchOrder(const Order orders[], int num_orders, const char* targetId) {
    int left = 0, right = num_orders - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(orders[mid].orderId, targetId);
        
        if (cmp == 0) return mid;
        if (cmp < 0) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

#endif
