/**
    Write an algorithm to find the ‘next’ node (i.e., in-order successor) 
    of a given node in a binary search tree where each node has a link to its parent.
    
              4
        2           5       
    1       3   6       7
    if has right: 
        to to the right 
        and go to max left
    if don't have right: 
        go to the parent
        if value was left:
            parent is next
        else if value was right: 
            go to parent while going from the right
            if came from the left: return parent
            else return nullptr
*/

struct Node {
    int value = 0;
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;    
};

Node* go_to_max_left(Node* n) {
    if (!n) return nullptr;
    while (n->left) {
        n = n->left;
    }
    return n;
}

Node* next_node(Node* n) {
    if (!n) return nullptr;
    // has right
    if (n->right) {
        n = n->right;
        return go_to_max_left(n);
    }
    // go to the parent
    while (true) {
        if (!n->parent) return nullptr;
        if (n->parent->left == n) return n->parent;
        n = n->parent;
    }    
}

