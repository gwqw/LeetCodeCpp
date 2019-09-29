/**
Depth First Search: DFS involves searching a node and all its children before proceed-
ing to its siblings.
Breadth First Search: BFS involves searching a node and its siblings before going on
to any children.
*/

#include <vector>
#include <unordered_set>
#include <deque>

using Vertex = int;

struct Node {
    Vertex v = 0;
    std::vector<Vertex> links;
};

using Graph = std::vector<Node>;

using namespace std;

Node* dfs(const Graph& graph, Vertex from, Vertex to, unordered_set<Vertex>& visited) {
    if (graph.empty()) return nullptr;
    
    if (from == to) return &graph[from];
    
    visited.insert(from);
    for (auto v : graph[from].links) {
        if (visited.count(v)) continue;
        visited.insert(v);
        auto res = dfs(graph, v, to);
        if (res) return res;
    }
    return nullptr;
}

Node* bfs(const Graph& graph, Vertex from, Vertex to) {
    is (graph.empty()) return nullptr;
    
    if (from == to) return &graph[from];
    unordered_set<Vertex> visited;
    visited.insert(from);
    deque<Vertex> cache;
    cache.push_back(from);
    while (!cache.empty()) {
        Vertex v = cache.front();
        cache.pop_front();
        if (visited.count(v)) continue;
        if (v == to) return &graph[v];
        visited.insert(v);
        
        for (Vertex c : graph[v].links) {
            if (!visited.count(c)) {
                cache.push_back(c);
            }
        }
    }
}
