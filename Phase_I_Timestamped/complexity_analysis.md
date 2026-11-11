# Phase I: Algorithm Complexity Analysis

| Algorithm | Time Complexity | Auxiliary Space | Justification |
| :--- | :--- | :--- | :--- |
| **Merge Sort** | $O(N \log N)$ | $O(N)$ | The array of $N$ orders is recursively halved. Merging takes linear time $O(N)$ at each level, requiring an auxiliary array of size $N$. |
| **Quick Sort** | $O(N \log N)$ avg | $O(\log N)$ | Partitioning elements takes $O(N)$ time. Average recursion depth requires $O(\log N)$ stack space. |
| **Binary Search**| $O(\log N)$ | $O(1)$ | Search space is halved iteratively. Only a few integer variables are stored, resulting in constant auxiliary space. |
| **0/1 Knapsack** | $O(N \cdot W)$ | $O(N \cdot W)$ | Evaluates $N$ items against weight capacity $W$. The DP table requires $N \times W$ space to track selected items. |
| **Dijkstra** | $O((V + E) \log V)$ | $O(V + E)$ | Extracting from the min-heap takes $O(\log V)$. Graph representation and priority queue take $O(V + E)$ space. |
