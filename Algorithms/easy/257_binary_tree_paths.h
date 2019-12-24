/**
    257. Binary Tree Paths
Given a binary tree, return all root-to-leaf paths.
Note: A leaf is a node with no children.

Example:
Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3

Algo1: use pre-order dfs. O(N) + O(Height^2)
- add value to cur_path
- visit left
- visit right

Algo2: Algo1 optimized for memory
- use only one string for current path, add and cut symbols from string
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> res;
        string cur_path;
        visit(root, move(cur_path), res);
        return res;
    }
private:
    void visit(TreeNode* node, string cur_path, vector<string>& res) {
        cur_path += to_string(node->val);
        if (!node->left && !node->right) {
            res.push_back(move(cur_path));
            return;
        }
        if (node->left) {
            visit(node->left, cur_path + "->", res);
        }
        if (node->right) {
            visit(node->right, cur_path + "->", res);
        }
    }
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> res;
        string cur_path;
        visit(root, cur_path, res);
        return res;
    }
private:
    void visit(TreeNode* node, string& cur_path, vector<string>& res) {
        string add_value = to_string(node->val);
        cur_path += add_value;
        if (!node->left && !node->right) {
            res.push_back(cur_path);
            cur_path.resize(cur_path.size() - add_value.size());
            return;
        }
        cur_path += "->";
        if (node->left) {
            visit(node->left, cur_path, res);
        }
        if (node->right) {
            visit(node->right, cur_path, res);
        }
        cur_path.resize(cur_path.size() - add_value.size() - 2);
    }
};
