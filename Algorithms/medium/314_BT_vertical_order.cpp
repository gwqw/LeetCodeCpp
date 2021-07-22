/**
    314. Binary Tree Vertical Order Traversal
Given the root of a binary tree, return the vertical order traversal of its nodes' values. (i.e., from top to bottom, column by column).
If two nodes are in the same row and column, the order should be from left to right.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]

Example 2:
Input: root = [3,9,8,4,0,1,7]
Output: [[4],[9],[3,0,1],[8],[7]]

Example 3:
Input: root = [3,9,8,4,0,1,7,null,null,null,2,5]
Output: [[4],[9,5],[3,0,1],[8,2],[7]]

Example 4:
Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

Algo1: bfs with map for res O(NlogN)
use map for columns:
while q not empty:
    node, i = q.pop()
    columns[i].push_back(node)
    if node->left: q.push_back(node->left, i-1)
    if node->right: q.push_back(node->left, i+1)
for k, v in columns:
    res.push_back(v)
return res

Algo1: bfs with un_map for res O(N)

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        map<int, vector<int>> columns;
        while (!q.empty()) {
            auto [node, i] = q.front(); q.pop();
            columns[i].push_back(node->val);
            if (node->left) q.emplace(node->left, i-1);
            if (node->right) q.emplace(node->right, i+1);
        }
        vector<vector<int>> res;
        res.reserve(columns.size());
        for (auto& [_, col] : columns) {
            res.push_back(move(col));
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        unordered_map<int, vector<int>> columns;
        int min_i = INT_MAX;
        int max_i = INT_MIN;
        while (!q.empty()) {
            auto [node, i] = q.front(); q.pop();
            columns[i].push_back(node->val);
            min_i = min(min_i, i);
            max_i = max(max_i, i);
            if (node->left) q.emplace(node->left, i-1);
            if (node->right) q.emplace(node->right, i+1);
        }
        vector<vector<int>> res(max_i - min_i+1);
        for (auto& [i, col] : columns) {
            res[i-min_i] = move(col);
        }
        return res;
    }
};



