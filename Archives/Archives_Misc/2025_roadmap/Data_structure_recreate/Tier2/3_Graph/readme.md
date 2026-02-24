# 📘 Graph Algorithms Cheat Sheet

A complete reference of graph algorithms, when to use them, and key comparisons.

---

## ✅ 1. Shortest Path Algorithms

| Algorithm         | Graph Type           | Weights         | Negative Weights | Detects Cycles | Use Case                                       |
|------------------|----------------------|------------------|------------------|----------------|------------------------------------------------|
| **BFS**           | Unweighted           | Equal (Unit)     | ❌               | ❌             | Shortest path in unweighted graphs             |
| **Dijkstra**      | Directed/Undirected  | Positive only     | ❌               | ❌             | Fastest for routing (Google Maps, etc.)        |
| **Bellman-Ford**  | Directed             | Any               | ✅               | ✅             | Graphs with negative weights or cycle check     |
| **Floyd-Warshall**| Directed             | Any (small V)     | ✅               | ✅             | All-pairs shortest path in dense graphs         |
| **0-1 BFS**       | Directed/Undirected  | 0 or 1            | ✅ (0 only)      | ❌             | Shortest path with binary weights (0 or 1)      |

---

## ✅ 2. Minimum Spanning Tree (MST) Algorithms

| Algorithm     | Graph Type         | Edge Weights | Uses DSU | Time Complexity | Best Use Case                         |
|--------------|--------------------|--------------|----------|-----------------|---------------------------------------|
| **Kruskal's** | Undirected         | Any          | ✅       | O(E log E)      | Sparse graphs, edge list input        |
| **Prim's**    | Undirected         | Any          | ❌       | O(E log V)      | Dense graphs, adjacency list input    |

---

## ✅ 3. Topological Sort & DAG Techniques

| Algorithm         | Graph Type     | Cycles Allowed | Key Use Cases                                  |
|-------------------|----------------|----------------|------------------------------------------------|
| **DFS Topo Sort** | Directed (DAG) | ❌             | Task scheduling, course prerequisites          |
| **Kahn's Algo**   | Directed (DAG) | ❌             | Topo sort + cycle detection                    |
| **Topo + DP**     | DAG            | ❌             | Longest path in DAG, count #paths, etc.        |

---

## ✅ 4. Cycle Detection

| Graph Type      | Method                   | Approach Type        | Notes                                      |
|------------------|--------------------------|-----------------------|--------------------------------------------|
| **Directed**     | DFS + RecStack / Kahn    | DFS / BFS             | RecStack for DFS, Kahn for BFS detection   |
| **Undirected**   | DFS + Parent / DSU       | DFS / Union-Find      | Use parent node in DFS or DSU to track     |

---

## ✅ 5. SCC Detection (Strongly Connected Components)

| Algorithm         | DFS Passes | Transpose Needed? | Time Complexity | Notes                             |
|------------------|------------|--------------------|------------------|-----------------------------------|
| **Tarjan's**      | 1          | ❌                 | O(V + E)         | Based on low-link values          |
| **Kosaraju's**    | 2          | ✅                 | O(V + E)         | Easier logic using reverse graph  |

---

## ✅ 6. Connectivity & Critical Components

### 🔹 Bridges

| Concept     | What It Detects                     | Condition              | Use Case                     |
|-------------|--------------------------------------|-------------------------|-------------------------------|
| **Bridge**  | Critical edge; removal splits graph | low[v] > tin[u]         | Network cables, road failure |

### 🔹 Articulation Points

| Concept                | What It Detects                         | Condition                                | Use Case                        |
|------------------------|------------------------------------------|-------------------------------------------|---------------------------------|
| **Articulation Point** | Critical node; removal disconnects graph | low[v] ≥ tin[u] (non-root) / ≥ 2 children (root) | Network routers, hubs          |

---

## ✅ 7. Disjoint Set Union (DSU) / Union-Find

| Feature                | Used For                             | Optimizations                  | Time Complexity |
|------------------------|--------------------------------------|--------------------------------|-----------------|
| **DSU / Union-Find**   | Kruskal’s MST, cycle detection       | Path Compression + Union by Rank | O(α(N)) approx |

---

## ✅ 8. TL;DR – What to Use When

| Problem Type                     | Best Algorithm                  |
|----------------------------------|---------------------------------|
| Unweighted shortest path         | **BFS**                         |
| Weighted shortest path (+ve)     | **Dijkstra**                    |
| Graphs with negative weights     | **Bellman-Ford**                |
| All-pairs shortest path          | **Floyd-Warshall**              |
| Minimum Spanning Tree            | **Prim’s / Kruskal’s**          |
| Task Scheduling (DAG)            | **Topological Sort**            |
| Strongly Connected Components    | **Tarjan / Kosaraju**           |
| Detect critical connections      | **Bridges / Articulation Points** |
| Check disjoint components        | **DSU / Union-Find**            |
| Detect cycles                    | **DFS/RecStack (Directed)** / **DSU (Undirected)** |

---
