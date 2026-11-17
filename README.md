# DAA-Ecommerce-Delivery-Optimizer (C Implementation)

This repository contains the offline **strict C implementation** of Project 02: E-Commerce Order Fulfilment and Delivery Optimizer (Course: CSEG3053 Design and Analysis of Algorithms). 

It serves as an industry-style logistics engine that models orders, warehouses, products, delivery vehicles, and customer locations using typed records (`typedef struct`), fixed/dynamic arrays, and weighted graphs. The system's core objective is to optimally select fulfillment centers, pack orders, and generate low-cost delivery plans subject to explicit capacity constraints and validation rules. 

The codebase includes independent, from-scratch implementations of algorithms designed to benchmark theoretical and empirical complexities.

## 🚀 Implemented Algorithms

**Phase I**
* **Divide & Conquer:** Merge Sort (Priority/Weight optimization) and Quick Sort (ID alphabetization).
* **Searching:** Iterative Binary Search for Order ID lookups.
* **Dynamic Programming:** 0/1 Knapsack to maximize vehicle packing value within weight constraints.
* **Greedy Methods:** Dijkstra's Algorithm (Min-Heap Priority Queue) for shortest delivery routing.

**Phase II**
* **Network Flow:** Ford-Fulkerson / Edmonds-Karp (BFS) to calculate maximum warehouse dispatch capacity bottlenecks.
* **String Matching:** Knuth-Morris-Pratt (KMP) for high-speed delivery event log scanning and alert detection.

## 📂 Repository Structure

```text
E-Commerce-Optimizer-Repo/
├── .git/
├── .gitignore
├── README.md                  # Offline setup & execution instructions
├── datasets/                  # Sample CSV data
├── docs/                      # Complexity reports, algorithm pseudocode, design guides
├── Phase_I_Timestamped/       # Phase I Evaluation Directory
│   ├── CMakeLists.txt
│   ├── main.c                 # Phase I CLI Interface
│   ├── tests.c                # Phase I Automated Unit Tests
│   ├── domain.h               # Core C Structs (Order, Vehicle, NodeEdges)
│   ├── algorithms.h
│   ├── dp_algorithms.h
│   └── greedy_algorithms.h
└── Phase_II/                  # Phase II Evaluation Directory
    ├── main.c                 # Phase II CLI Interface
    ├── tests.c                # Phase II Automated Unit Tests
    ├── network_flow.h
    └── string_matching.h
