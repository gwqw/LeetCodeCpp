struct Node {
    int value = 0;
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;    
};

template <typename Pred>
void in_order(Node* root, Pred p) {
    if (!root) return;
    in_order(root->left, p);
    p(root);
    in_order(root->right, p);
}

template <typename Pred>
void pre_order(Node* root, Pred p) {
    if (!root) return;
    p(root);
    pre_order(root->left, p);
    pre_order(root->right, p);
}

template <typename Pred>
void post_order(Node* root, Pred p) {
    if (!root) return;
    post_order(root->left, p);
    post_order(root->right, p);
    p(root);
}

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

void print_nodes(Node* node) {
    in_order(node, [](Node* n){std::cout << n->value;});
}

