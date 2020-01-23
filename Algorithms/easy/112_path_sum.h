/**
    112. Path Sum
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such 
that adding up all the values along the path equals the given sum.
Note: A leaf is a node with no children.

Example:
Given the below binary tree and sum = 22,
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Algo: dfs and check sum
- use dfs and go to leaf and calc sum
- if leaf: return sum
- else if node: return left || right
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
    bool hasPathSum(TreeNode* root, int sum) {
        return isSum(root, 0, sum);
    }
private:
    bool isSum(TreeNode* node, int sum, int target) {
        if (!node) return false;
        sum += node->val;
        if (!node->left && !node->right) {
            return sum == target;
        }        
        return isSum(node->left, sum, target) || isSum(node->right, sum, target);
    }
};
// the same
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        sum -= root->val;
        if (!root->left && !root->right) {
            return sum == 0;
        }        
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};
