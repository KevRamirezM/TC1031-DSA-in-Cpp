# Search Algorithms: DFS and BFS

## Depth-First Search (DFS)

- Explores as far as possible along each branch before backtracking.
- Uses a stack (either explicitly or through recursion) to keep track of nodes to visit.

```cpp
	void dfs(const ListGraph& g, int v, std::vector<bool>& visited, std::vector<int>& order) {
    visited[v] = true;                     // mark it before going on
    order.push_back(v);                    // visit v first (preorder)
    for (int w : g.neighbors(v))
        if (!visited[w])
            dfs(g, w, visited, order);     // go deep along w
}
```

## Breadth-First Search (BFS)

- Explores all neighbors at the present depth prior to moving on to nodes at the next depth level.
- Uses a queue to keep track of nodes to visit.

```cpp
std::vector<int> bfs(const ListGraph& g, int n, int s, std::vector<int>& parent) {
    std::vector<int> dist(n + 1, -1);      // -1: not discovered (Weiss: ∞)
    parent.assign(n + 1, 0);
    std::queue<int> q;
    dist[s] = 0; q.push(s);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int w : g.neighbors(v))
            if (dist[w] == -1) {           // first time we see w
                dist[w] = dist[v] + 1;
                parent[w] = v;             // came from v (Weiss: path)
                q.push(w);
            }
    }
    return dist;
}
```

