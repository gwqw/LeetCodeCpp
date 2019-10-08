/**
Given a binary search tree, design an algorithm which creates a linked list of 
all the nodes at each depth (i.e., if you have a tree with depth D, you’ll have D linked lists).
Algo:
use bfs
*/

#include <vector>

struct Node {
    int value = 0;
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;    
};

struct ListNode {
    int value = 0;
    ListNode* next = nullptr;
};

using namespace std;

vector<ListNode*> get_lists(Node* root) {
    vector<ListNode*> lists;
    if (!root) return lists;
    
    queue<Node*> cache;
    cache.push(root);
    // also add level number
    queue<int> levels;
    levels.push(0);
    while (!cache.empty()) {
        // take node and level from cache 
        Node* v = cache.front();
        cache.pop();
        int lvl = levels.front();
        levels.pop();
        // resize res vector
        if (lvl+1 >= lists.size()) {
            lists.resize(lvl+1);
        }
        // add node value to the begining
        ListNode* n = new ListNode{v->value};
        n->next = lists[lvl];
        lists[lvl] = n;
        
        // add node left and right to the cache (and its levels)
        if (v->left) {
            cache.push(v->left);
            levels.push(lvl+1);
        }
        if (v->right) {
            cache.push(v->right);
            levels.push(lvl+1);
        }
    }
}

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