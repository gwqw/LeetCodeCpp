/**
    Given a sorted (increasing order) array, 
    write an algorithm to create a binary tree with minimal height.
    
    Algo:
    take middle and add to tree, 
    next add left and right arrays to tree recursive
    O(NlogN), O(1) (no additional mem)
*/

struct Node {
    int value = 0;
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;    
};

void delete_nodes(Node* node) {
    if (!node) return;
    delete_nodes(node->left);
    delete_nodes(node->right);
    delete node;
}

Node* insert_node(Node* node, int value) {
    if (!node) {
        node = new Node{value};
        return node;
    }
    if (value < node->value) {
        node->left = insert_node(node->left, value);
    } else {
        node->right = insert_node(node->right, value);
    }
    return node;
}

class BST {
public:
    ~BST() {
        delete_nodes(root);
    }
    void insert(int value) {
        insert_node(root, value);
    }
private:
    Node* root = nullptr;
};

Node* create_bin_tree(const vector<int>& v, int from, int to) {
    // exit from recursion
    if (to == from) return nullptr;
    Node* n = new Node{v[from]};
    if (to - front == 1) {
        return n;
    }
    // add middle element to tree
    int m = from  + (to - front) / 2;
    // recursive add left array and right arrays to tree
    n->left = create_bin_tree(v, from, m-1);
    n->right = create_bin_tree(v, m+1, to);
    return n;
}
