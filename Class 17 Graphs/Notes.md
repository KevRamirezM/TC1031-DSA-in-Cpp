# Graphs Notes

- A graph is a collection of nodes (also called vertices) and edges that connect pairs of nodes.
- A graph is the most general data structure that can be used to represent relationships between objects.
- G = (V, E) where V is a set of vertices and E is a set of edges.
- The degree of a node is the number of edges connected to it.
- A graph can be directed or undirected.
- A graph can be weighted or unweighted.

### Directed Graphs
In a directed graph, edges have a direction, meaning they go from one vertex to another.
If it is strongly connected, there is a path from every vertex to every other vertex.
If it is weakly connected, there can be a path that gets stuck in a node and cannot reach all other nodes.
It can have up to n(n-1) edges, where n is the number of vertices.

### Undirected Graphs
In an undirected graph, edges do not have a direction, meaning they connect two vertices without any specific order.
It can have up to n(n-1)/2 edges, where n is the number of vertices.

### Weighted Graphs
In a weighted graph, each edge has an associated weight or cost, which can represent distance, time, or any other metric.

### Paths

A path in a graph is a sequence of vertices where they are connected by an edge.
A simple path is a path where all vertices are different. 
A cycle is a path that starts and ends at the same vertex (node).

### Memory Representation

For a graph we can use an adjacency matrix to represent it in memory.

Example:

```
  A B C D
A 0 1 0 1
B 1 0 1 0
C 0 1 0 1
D 1 0 1 0
```

We also can use an adjacency list to represent a graph in memory.

Example:

```
A -> B, D
B -> A, C
C -> B, D
D -> A, C
```

