/**
    107. Binary Tree Level Order Traversal II
Given a binary tree, return the bottom-up level order traversal of its nodes' values.
(ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

Algo: bfs: O(N) + O(N)
- go through tree bfs and saves lvl
- for same level push to res.back()
- for new lvl push new vector to res and push val to res.back
- reverse res

Algo2: dfs
- need to push in different places

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        res.push_back({});
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        int prev_lvl = 0;
        while (!q.empty()) {
            auto [node, lvl] = q.front();
            q.pop();
            if (lvl != prev_lvl) {
                ++prev_lvl;
                res.push_back({});
            }
            res.back().push_back(node->val);
            if (node->left) {
                q.emplace(node->left, lvl+1);
            }
            if (node->right) {
                q.emplace(node->right, lvl+1);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        visit(root, res, 0);
        reverse(res.begin(), res.end());
        return res;
    }
private:
    void visit(TreeNode* node, vector<vector<int>>& res, int lvl) {
        if (!node) return;
        if (lvl == res.size()) {
            res.push_back({});
        }
        res[lvl].push_back(node->val);
        visit(node->left, res, lvl+1);
        visit(node->right, res, lvl+1);
    }
};

/*
        3
       / \
      9  20
     /  /  \
    6  15   7
[[3], [9, 20], [6, 15, 7]]

*/
