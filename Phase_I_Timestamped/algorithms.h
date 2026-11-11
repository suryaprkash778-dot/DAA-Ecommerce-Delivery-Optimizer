// algorithms.h
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "domain.h"
#include <vector>
#include <string>
#include <utility>

// Merge Sort to prioritize orders by weight or priority[cite: 1]
inline void merge(std::vector<Order>& orders, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<Order> L(n1), R(n2);

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
}

inline void mergeSortOrders(std::vector<Order>& orders, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortOrders(orders, left, mid);
        mergeSortOrders(orders, mid + 1, right);
        merge(orders, left, mid, right);
    }
}

// Quick Sort to organize orders alphabetically by orderId[cite: 1]
inline int partition(std::vector<Order>& orders, int left, int right) {
    std::string pivot = orders[right].orderId;
    int i = (left - 1);
    for (int j = left; j <= right - 1; j++) {
        if (orders[j].orderId < pivot) {
            i++;
            std::swap(orders[i], orders[j]);
        }
    }
    std::swap(orders[i + 1], orders[right]);
    return (i + 1);
}

inline void quickSortOrdersById(std::vector<Order>& orders, int left, int right) {
    if (left < right) {
        int pi = partition(orders, left, right);
        quickSortOrdersById(orders, left, pi - 1);
        quickSortOrdersById(orders, pi + 1, right);
    }
}

// Iterative binary search to retrieve a specific order by orderId (requires array to be sorted by ID first)[cite: 1]
inline int binarySearchOrder(const std::vector<Order>& orders, const std::string& targetId) {
    int left = 0, right = orders.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (orders[mid].orderId == targetId) return mid;
        if (orders[mid].orderId < targetId) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

#endif
