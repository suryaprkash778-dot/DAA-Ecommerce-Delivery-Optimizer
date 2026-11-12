# Phase II: Algorithm Complexity Analysis

| Algorithm | Time Complexity | Auxiliary Space | Justification |
| :--- | :--- | :--- | :--- |
| **Ford-Fulkerson (Edmonds-Karp)** | O(V * E^2) | O(V^2) | Using BFS to find augmenting paths ensures the shortest path is chosen, bounding total augmentations to O(V * E). Each BFS takes O(E), yielding O(V * E^2) time. The adjacency matrix requires O(V^2) space. |
| **Knuth-Morris-Pratt (KMP)** | O(N + M) | O(M) | N is text length, M is pattern length. Precomputing the LPS (Longest Prefix Suffix) array takes O(M) time and space. Searching the text requires a single pass, taking O(N) time. |
