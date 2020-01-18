/**
    111. Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.

Example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.

Algo1: dfs post-order: O(N) + O(height)
- calc min_height in left
- calc min_height in right
- return min(l,r)+1

Algo2: dfs wo recursion and use short scheme: O(N) + O(height)

Algo2: bfs wo recursion and use short scheme: O(N) + O(height)
- short scheme ends earlier than in dfs
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if (l == 0 && r == 0) {
            return 1;
        } else if (l == 0) {
            return r+1;
        } else if (r == 0) {
            return l+1;
        } else {
            return min(r,l) + 1;
        }
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        stack<pair<TreeNode*, int>> nodes;
        nodes.push({root,1});
        int min_height = INT_MAX;
        while (!nodes.empty()) {
            auto [node,lvl] = nodes.top();
            nodes.pop();
            if (!node->left && !node->right) {
                min_height = min(min_height, lvl);
                continue;
            }
            if (node->left && lvl < min_height) {
                nodes.push({node->left, lvl+1});
            }
            if (node->right && lvl < min_height) {
                nodes.push({node->right, lvl+1});
            }
        }
        return min_height;
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> nodes;
        nodes.push({root,1});
        while (!nodes.empty()) {
            auto [node,lvl] = nodes.front();
            nodes.pop();
            if (!node->left && !node->right) {
                return lvl;
            }
            if (node->left) {
                nodes.push({node->left, lvl+1});
            }
            if (node->right) {
                nodes.push({node->right, lvl+1});
            }
        }
        return INT_MAX;
    }
};


