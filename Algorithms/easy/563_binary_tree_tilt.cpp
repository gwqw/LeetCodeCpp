/**
    563. Binary Tree Tilt
Given a binary tree, return the tilt of the whole tree.
The tilt of a tree node is defined as the absolute difference between the sum of all
left subtree node values and the sum of all right subtree node values. Null node has tilt 0.
The tilt of the whole tree is defined as the sum of all nodes' tilt.

Example:
Input: 
         1
       /   \
      2     3
Output: 1
Explanation: 
Tilt of node 2 : 0
Tilt of node 3 : 0
Tilt of node 1 : |2-3| = 1
Tilt of binary tree : 0 + 0 + 1 = 1

Note:
The sum of node values in any subtree won't exceed the range of 32-bit integer.
All the tilt values won't exceed the range of 32-bit integer.

Algo: dfs: lrn, O(N) + O(height)
- go through tree:
- lsum = dfs(n->left)
- rsum = dfs(n->right)
- tilt = abs(r-l)
- sum = r+l + val
- update tilt_global: tilt_global += tilt
- return sum
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
    int findTilt(TreeNode* root) {
        calc_sum_n_upd_tilt(root);
        return tilt_max;
    }
    
private:
    int calc_sum_n_upd_tilt(TreeNode* node) {
        if (!node) return 0;
        int lsum = calc_sum_n_upd_tilt(node->left);
        int rsum = calc_sum_n_upd_tilt(node->right);
        tilt_max += abs(lsum - rsum);
        return rsum + lsum + node->val;
    }
    
    int tilt_max = 0;
};
class Solution {
public:
    int findTilt(TreeNode* root) {
        if (!root) return 0;
        calc_sum_n_upd_tilt(root);
        return tilt_max;
    }
    
private:
    int calc_sum_n_upd_tilt(TreeNode* node) {
        int lsum = node->left ? calc_sum_n_upd_tilt(node->left) : 0;
        int rsum = node->right ? calc_sum_n_upd_tilt(node->right) : 0;
        tilt_max += abs(lsum - rsum);
        return rsum + lsum + node->val;
    }
    
    int tilt_max = 0;
};
