/**
Graph: n=|V|, m=|E|
Depth First Search: DFS involves searching a node and all its children before proceed-
ing to its siblings.
Breadth First Search: BFS involves searching a node and its siblings before going on
to any children.
*/

#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using Vertex = int;
using Node = std::vector<Vertex>;
using Graph = std::vector<Node>;

using namespace std;

///recursive dfs 
void dfs(const Graph& graph, Vertex from, unordered_set<Vertex>& visited) {
    if (graph.empty()) return;

    visited.insert(from);
    for (auto v : graph[from]) {
        if (visited.count(v)) continue;
        visited.insert(v);
        dfs(graph, v, visited);
    }
}

/// nonrecursive dfs
void dfs(const Graph& graph, Vertex from) {
    if (graph.empty()) return;

    unordered_set<Vertex> visited;
    stack<Vertex> cache;
    cache.push(from);
    while (!cache.empty()) {
        Vertex v = cache.top();
        cache.pop();
        if (visited.count(v)) continue;
        visited.insert(v);

        for (Vertex c : graph[v]) {
            if (!visited.count(c)) {
                cache.push(c);
            }
        }
    }
}

/// nonrecursive bfs
void bfs(const Graph& graph, Vertex from) {
    if (graph.empty()) return;

    unordered_set<Vertex> visited;
    queue<Vertex> cache;
    cache.push(from);
    while (!cache.empty()) {
        Vertex v = cache.front();
        cache.pop();
        if (visited.count(v)) continue;
        visited.insert(v);

        for (Vertex c : graph[v]) {
            if (!visited.count(c)) {
                cache.push(c);
            }
        }
    }
}

