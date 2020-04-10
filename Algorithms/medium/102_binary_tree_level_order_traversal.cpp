/**
    102. Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values.
(ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

Algo: use bfs and save lvl: O(N) + O(N)
- add to queue node and level
- pop from queue node and level
- if level != cur_level:
    - cur_level = level
    - res.push_back()
- add to res.back()
- add all not null childs to queue

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<pair<TreeNode*, size_t>> q;
        q.emplace(root, 0);
        vector<vector<int>> res {{}};
        size_t cur_lvl = 0;
        while (!q.empty()) {
            auto [node, lvl] = q.front();
            q.pop();
            if (lvl != cur_lvl) {
                res.push_back({});
                cur_lvl = lvl;
            }
            res.back().push_back(node->val);
            if (node->left) {
                q.emplace(node->left, lvl+1);
            }
            if (node->right) {
                q.emplace(node->right, lvl+1);
            }
        }
        return res;
    }
};

