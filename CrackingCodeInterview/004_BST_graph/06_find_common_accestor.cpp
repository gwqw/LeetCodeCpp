/**
Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree. 
Avoid storing additional nodes in a data structure. NOTE: This is not necessarily a binary search tree.
Algo:    
              4
        2           5       
    1       3   6       7

input: n1, n2
find depths: d1 and d2:
let max_d = d1
up n1 to d2
while (n1 != n2) {
    if (!n1->parent) return nullptr;
    up(n1)
    up(n2)
}
*/

struct Node {
    int value = 0;
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;    
};

int find_depth(Node* n) {
    int depth = 0;
    while (n) {
        n = n->parent;
        depth++;
    }
    return depth;
}

Node* up(Node* n) {
    return n->parent;
}

Node* find_common_ancestor(Node* n1, Node* n2) {
    if (!n1 || !n2) return nullptr;
    int d1 = find_depth(n1);
    int d2 = find_depth(n2);
    if (d1 > d2) {
        while (d1 != d2) {
            n1 = up(n1);
            d1--;
        }
    } else {
        while (d1 != d2) {
            n2 = up(n2);
            d2--;
        }
    }
    while (n1 != n2) {
        if (!n1->parent) return nullptr;
        n1 = up(n1);
        n2 = up(n2);
    }
    return n1;
}

