/**
    226. Invert Binary Tree
Invert a binary tree.
Example:
Input:
     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:
     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), 
but you can’t invert a binary tree on a whiteboard so f*** off.

Algo: dfs and swap left and right: O(N) + O(height)
- recursive(node):
    - swap(node->left, node->right)
    - if node->left: recursive(node->left)
    - if node->right: recursive(node->right)
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        swapChildren(root);
        return root;
    }
    
private:
    static void swapChildren(TreeNode* node) {
        swap(node->left, node->right);
        if (node->left) swapChildren(node->left);
        if (node->right) swapChildren(node->right);
    }
};



