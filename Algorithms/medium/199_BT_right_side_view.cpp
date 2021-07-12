/**
    199. Binary Tree Right Side View
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:
Input: root = [1,null,3]
Output: [1,3]

Example 3:
Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

Algo1: bfs with lvl

Algo2: dfs with lvl
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        int prev_lvl = 0;
        int prev = 0;
        while (!q.empty()) {
            auto [node, lvl] = q.front();
            q.pop();
            if (lvl != prev_lvl) {
                res.push_back(prev);
                prev_lvl = lvl;
            }
            prev = node->val;
            if (node->left) {
                q.emplace(node->left, lvl+1);
            }
            if (node->right) {
                q.emplace(node->right, lvl+1);
            }
        }
        res.push_back(prev);
        return res;
    }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        dfs(root, res, 0);
        return res;
    }
    
private:
    void dfs(TreeNode* node, vector<int>& res, int lvl) {
        if (!node) return;
        if (res.size() < lvl+1) {
            res.push_back(node->val);
        } else {
            res[lvl] = node->val;
        }
        dfs(node->left, res, lvl+1);
        dfs(node->right, res, lvl+1);
    }
};