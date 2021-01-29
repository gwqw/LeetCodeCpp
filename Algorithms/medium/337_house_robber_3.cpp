/**
    337. House Robber III
The thief has found himself a new place for his thievery again. 
There is only one entrance to this area, called the "root." 
Besides the root, each house has one and only one parent house. 
After a tour, the smart thief realized that "all houses in this place forms a binary tree". 
It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

Example 2:
Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

Algo: dfs and accum 2 sums: max connected with leaf and disconnected
O(N) + O(height) memory
visit(n):
    if n: return 0, 0
    con_l, disc_l = visit(n->left)
    con_r, disc_r = visit(n->right)
    con = n->value + disc_l + disc_r
    disc = max(con_l, disc_l) + max(con_r, disc_r)
    return con, disc
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
    int rob(TreeNode* root) {
        auto [con, disc] = visit(root);
        return max(con, disc);
    }
private:
    pair<int, int> visit(TreeNode* node) {
        if (!node) return {0,0};
        
        auto [con_l, disc_l] = visit(node->left);
        auto [con_r, disc_r] = visit(node->right);
        
        int con = node->val + disc_l + disc_r;
        int disc = max(con_l, disc_l) + max(con_r, disc_r);
        return {con, disc};
    }
};

