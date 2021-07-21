/**
    426. Convert Binary Search Tree to Sorted Doubly Linked List
Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

You can think of the left and right pointers as synonymous to the predecessor and successor pointers in a doubly-linked list. For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.

We want to do the transformation in place. After the transformation, the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. You should return the pointer to the smallest element of the linked list.

Example 1:
Input: root = [4,2,5,1,3]
Output: [1,2,3,4,5]
Explanation: The figure below shows the transformed BST. The solid line indicates the successor relationship, while the dashed line means the predecessor relationship.

Example 2:
Input: root = [2,1,3]
Output: [1,2,3]

Example 3:
Input: root = []
Output: []
Explanation: Input is an empty tree. Output is also an empty Linked List.

Example 4:
Input: root = [1]
Output: [1]

Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
All the values of the tree are unique.

dfs: lnr
dfs(node, prev, first):
    if not node: return
    dfs(node->left)
    if prev:
        prev->right = node
        node->left = prev
    else:
        first = node
    prev = node
    dfs(node->right)
    if prev == node:
        node->right = first
        first->left = node


*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

/*
dfs(node, prev, first):
    if not node: return
    dfs(node->left)
    if prev:
        prev->right = node
        node->left = prev
    else:
        first = node
    prev = node
    dfs(node->right)
    if prev == node:
        node->right = first
        first->left = node
*/

class Solution {
    using NodePtr = Node*;
public:
    Node* treeToDoublyList(Node* root) {
        Node* new_root = nullptr;
        Node* prev = nullptr;
        dfs(root, prev, new_root);
        return new_root;
    }
private:
    void dfs(Node* node, NodePtr& prev, NodePtr& first) {
        if (!node) return;
        dfs(node->left, prev, first);
        if (prev) {
            prev->right = node;
            node->left = prev;
        } else {
            first = node;
        }
        prev = node;
        dfs(node->right, prev, first);
        if (prev == node) {
            node->right = first;
            first->left = node;
        }
    }
};