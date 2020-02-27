/**
    104. Maximum Depth of Binary Tree
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node 
down to the farthest leaf node.
Note: A leaf is a node with no children.

Example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.

Algo: use dfs: O(N), O(height)
- go through tree by dfs and calc depth
- if leaf update max_depth
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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        stack<pair<TreeNode*, int>> st;
        st.emplace(root, 1);
        int max_depth = 0;
        while (!st.empty()) {
            auto [node, lvl] = st.top();
            st.pop();
            if (node->left) {
                st.emplace(node->left, lvl+1);
            }
            if (node->right) {
                st.emplace(node->right, lvl+1);
            }
            if (!node->left && !node->right) {
                max_depth = max(max_depth, lvl);
            }
        }
        return max_depth;
    }
};


