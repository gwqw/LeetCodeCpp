/**
    116. Populating Next Right Pointers in Each Node
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

Follow up:
You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.

Example 1:
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

Constraints:
The number of nodes in the given tree is less than 4096.
-1000 <= node.val <= 1000
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Algo: bfs O(N), O(N)
queue q({Node, level})
level = 0
Node* prev = null
prev_lvl = 0
while q:
    node, lvl = q.front()
    if prev and prev_lvl = lvl:
        prev->next = node
    prev = node
    if node->left:
        q.push(node->left, lvl+1)
    if node->right:
        q.push(node->right, lvl+1)
        
Algo2: dfs wo mem: O(N), O(h)
left: n->left->next = n->right
right: n->right->next = n->next->left (if n->next)

Algo3: bfs wo recursion with next
p = root
while p->left:
    q = p
    while q:
        q->left->next = q->right
        if q->next:
            q->right->next = q->next->left
        q = q->next
    p = p->left
        

*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        queue<pair<Node*, size_t>> q;
        size_t prev_lvl = 0;
        Node* prev = nullptr;
        q.push({root, 0});
        while (!q.empty()) {
            auto [node, lvl] = q.front();
            q.pop();
            if (prev && prev_lvl == lvl) {
                prev->next = node;
            }
            prev = node;
            prev_lvl = lvl;
            if (node->left) q.push({node->left, lvl+1});
            if (node->right) q.push({node->right, lvl+1});
        }
        return root;
    }
};


class Solution {
public:
    Node* connect(Node* root) {
        if (!root || !root->left) return root;
        root->left->next = root->right;
        if (root->next) {
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root || !root->left) return root;
        auto p = root;
        while (p->left) {
            for (auto q = p; q; q = q->next) {
                q->left->next = q->right;
                if (q->next) {
                    q->right->next = q->next->left;
                }
            }
            p = p->left;
        }
        return root;
    }
};
