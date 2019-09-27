/**
Depth First Search: DFS involves searching a node and all its children before proceed-
ing to its siblings.
Breadth First Search: BFS involves searching a node and its siblings before going on
to any children.
*/

#include <vector>
#include <deque>

struct Node {
    int value = 0;
    Node* parent = nullptr;
    std::vector<Node*> children;
};

Node* dfs(Node* from, int value) {
    if (!from) return nullptr;
    if (from->value == value) return from;
    for (Node* v : from->children) {
        Node* res = dfs(v);
        if (res) return res;
    }
    return nullptr;
}

Node* bfs(Node* from, int value) {
    if (!from) return;
    using std::deque;
    deque<Node*> cache;
    cache.push_back(from);
    while (!cache.empty()) {
        node* n = cache.front();
        cache.pop_front();
        if (n->value == value) return n;
        for (Node* c : n->children) {
            cache.push_back(c);
        }
    }
    return nullptr;    
}

