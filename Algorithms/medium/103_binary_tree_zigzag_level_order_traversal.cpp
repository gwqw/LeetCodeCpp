/**
    103. Binary Tree Zigzag Level Order Traversal
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

Algo1: bfs: O(N) + O(N)

Algo2: dfs: O(N) + O(N)
visit(node, level, &res)
    if not node: return
    res[level].append(node->val) # resize res by push_back 
    visit(node->left, level+1, res)
    visit(node->rigth, level+1, res)
visit(root, res, 0)
for i in range(0, res.size(), 2):
    reverse(res[i])
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        queue<pair<TreeNode*, size_t>> q;
        vector<vector<int>> res{{}};
        q.emplace(root, 0);
        size_t cur_lvl = 0;
        while (!q.empty()) {
            auto [node, lvl] = q.front();
            q.pop();
            if (lvl != cur_lvl) {
                if (cur_lvl % 2 == 1) {
                    reverse(res.back().begin(), res.back().end());
                }
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
        if (cur_lvl % 2 == 1) {
            reverse(res.back().begin(), res.back().end());
        }
        return res;
    }
};
