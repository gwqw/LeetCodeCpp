/**
Given a directed graph, design an algorithm to find out whether there is a route
between two nodes.

Algo:
    use bfs from one node and try to find another one
*/

#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using Vertex = int;
using Node = std::vector<Vertex>;
using Graph = std::vector<Node>;

using namespace std;

/// nonrecursive bfs
void bfs(const Graph& graph, Vertex from, Vertex to) {
    if (graph.empty()) return;
    if (from == to) return true;

    unordered_set<Vertex> visited;
    queue<Vertex> cache;
    cache.push(from);
    while (!cache.empty()) {
        Vertex v = cache.front();
        cache.pop();
        if (v == to) return true;
        if (visited.count(v)) continue;
        visited.insert(v);

        for (Vertex c : graph[v]) {
            if (!visited.count(c)) {
                cache.push(c);
            }
        }
    }
    return false;
}
