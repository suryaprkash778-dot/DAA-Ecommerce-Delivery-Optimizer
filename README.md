# DAA-Ecommerce-Delivery-Optimizer
This repository contains the offline C++ implementation of Project 02: E-Commerce Order Fulfilment and Delivery Optimizer. It serves as an industry-style logistics engine that models orders, warehouses, products, delivery vehicles, and customer locations using typed records, arrays, trees, and weighted graphs. The system's core objective is to optimally select fulfilment centres, pack orders, and generate low-cost delivery plans subject to explicit capacity constraints and validation rules. The codebase includes independent, from-scratch implementations of divide-and-conquer sorting, greedy routing (Dijkstra), dynamic programming capacity allocation (0/1 Knapsack), and network flow algorithms to benchmark theoretical and empirical complexities.

E-Commerce-Optimizer-Repo/
* .git/
* .gitignore
* README.md                  # Needs offline setup & execution instructions
* datasets/                  # Sample JSON/CSV data goes here
* docs/                      # Complexity reports, algorithm pseudocode, design guides
* Phase_I_Timestamped/       # Current working directory for first evaluation
    * CMakeLists.txt
    * main.cpp
    * domain.h
    * algorithms.h
