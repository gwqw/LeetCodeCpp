/**
    235. Lowest Common Ancestor of a Binary Search Tree
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes p and q as the lowest node 
in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]

Example 1:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Note:
All of the nodes' values will be unique.
p and q are different and both values will exist in the BST.

Algo1: naive: O(N) + O(H)
- use dfs and calc queue for p and q
- pop_front from q and q while ==

Algo2: O(h(lca))
- p - min, q - max
- go and select left or right:
- if p < l < r < q: return parent
- else: go l < p < q < r
can be recursive or iterative

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qu;
        dfs(root, p, q, qu);
        if (q1.empty() || q2.empty()) return nullptr;
        TreeNode* last = nullptr;
        while (!q1.empty() || !q2.empty()) {
            auto v1 = q1.front();
            q1.pop();
            auto v2 = q2.front();
            q2.pop();
            if (v1 != v2) return last;
            last = v1;
        }
        return last;
    }
private:
    void dfs(TreeNode* node, TreeNode* p, TreeNode* q, queue<TreeNode*> qu) {
        if (!node) return;
        qu.push(node);
        if (node == p) {
            q1 = qu;
        }
        if (node == q) {
            q2 = qu;
        }
        if (!q1.empty() && !q2.empty()) {
            return;
        }
        dfs(node->left, p, q, qu);
        dfs(node->right, p, q, qu);
    }
    
    queue<TreeNode*> q1, q2;
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) {
            swap(p, q);
        }
        if (!root) return nullptr;
        if (p->val <= root->val && root->val <= q->val) {
            return root;
        }
        if (q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (root->val < p->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return nullptr;
    }
};

