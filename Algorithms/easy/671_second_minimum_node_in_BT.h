/**
    671. Second Minimum Node In a Binary Tree
Given a non-empty special binary tree consisting of nodes with the non-negative value, 
where each node in this tree has exactly two or zero sub-node. 
If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. 
More formally, the property root.val = min(root.left.val, root.right.val) always holds.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.
If no such second minimum value exists, output -1 instead.

Example 1:
Input: 
    2
   / \
  2   5
     / \
    5   7
Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.

Example 2:
Input: 
    2
   / \
  2   2
Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.

Algo1: use bfs and check all values: O(N) + O(N)
- bfs through all nodes
- min = root->val
- second = node->val != min && node->val < second

Algo2: use short scheme with level O(N) + O(N)
- add level also
- if on level all values != min so return second

Algo3: cut branches for non-min values O(N) + O(N)

Algo_other: dfs, heap(?)
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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        queue<TreeNode*> q;
        q.push(root);
        int first = root->val;
        int second = -1;
        while (!q.empty()) {
            auto n = q.front();
            q.pop();
            if (n->val != first && (second == -1 || n->val < second)) {
                second = n->val;
            }
            if (n->left) {
                q.push(n->left);
                q.push(n->right);
            }
        }
        return second;
    }
};

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        queue<pair<TreeNode*, size_t>> q;
        q.emplace(root, 0);
        int first = root->val;
        int second = -1;
        int prev_level = 0;
        bool all_greater = true;
        while (!q.empty()) {
            auto [n,level] = q.front();
            q.pop();
            // short scheme
            if (level != prev_level) {
                if (all_greater) return second;
                prev_level = level;
                all_greater = true;
            }
            if (n->val == first && n->left) all_greater = false;
            // update second
            if (n->val != first && (second == -1 || n->val < second)) {
                second = n->val;
            }
            // push children
            if (n->left) {
                q.emplace(n->left, level+1);
                q.emplace(n->right, level+1);
            }
        }
        return second;
    }
};

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        queue<TreeNode*> q;
        q.push(root);
        int first = root->val;
        int second = -1;
        while (!q.empty()) {
            auto n = q.front();
            q.pop();
            if (n->val != first && (second == -1 || n->val < second)) {
                second = n->val;
            }
            if (n->left && n->val == first) {
                q.push(n->left);
                q.push(n->right);
            }
        }
        return second;
    }
};

/*
[2,2,5,null,null,5,7]
[2,2,2]
[2,2,5,3,4,5,7]
[2,2,2147483647]
*/

