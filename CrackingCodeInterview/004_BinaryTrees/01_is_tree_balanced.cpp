/**
Implement a function to check if a tree is balanced. For the purposes of this question,
a balanced tree is defined to be a tree such that no two leaf nodes differ in distance
from the root by more than one.

Algo:
is_balanced(root):
    lb, lh = is_balanced(root->left)
    if (!lb) return {false, 0}
    rb, rh = is_balanced(root->left)
    if (!rb || abs(lh - rh) > 1):
        return {false, 0}
    return {true, max(lh, rh)+1}
    
Algo2:
|maxDepth - minDepth| <= 1
*/

struct Node {
    int value = 0;
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;    
};

#include <optional>

using namespace std;

optional<int> is_balanced(Node* root) {
    if (!root) return nullopt;
    auto lhs = is_balanced(root->left);
    if (!lhs) return nullopt;
    auto rhs = is_balanced(root->right);
    if (!rhs || abs(*lhs - *rhs) > 1) return nullopt;
    return max(*lhs, *rhs)+1;
}



