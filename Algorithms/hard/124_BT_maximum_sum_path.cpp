/**
    124. Binary Tree Maximum Path Sum
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any path.

Example 1:
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Example 2:
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

Constraints:
The number of nodes in the tree is in the range [1, 3 * 10^4].
-1000 <= Node.val <= 1000

Algo: df(lrn)+dp
max_sum_l, line_sum_l = visit(node->left)
max_sum_r, line_sum_r = visit(node->right)
line_sum = max(max(line_sum_l, line_sum_r) + node->val, node->val)
max_sum = max(max_sum_l, max_sum_r, line_sum, line_sum_l + line_sum_r + node->val)

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
    int maxPathSum(TreeNode* root) {
        auto [max_sum, _] = visit(root);
        return max_sum;
    }
    
private:
    pair<int, int> visit(TreeNode* node) {
        if (!node) return {-1000, -1000};
        auto [max_sum_l, line_sum_l] = visit(node->left);
        auto [max_sum_r, line_sum_r] = visit(node->right);
        int line_sum = max(line_sum_l, line_sum_r) + node->val;
        line_sum = max(line_sum, node->val);
        int max_sum = max(max_sum_l, max_sum_r);
        max_sum = max(max_sum, line_sum);
        max_sum = max(max_sum, line_sum_l + node->val + line_sum_r);
        return {max_sum, line_sum};
    }
};
