/**
    538. Convert BST to Greater Tree
Given a Binary Search Tree (BST), 
convert it to a Greater Tree such that every key of the original BST is changed 
to the original key plus sum of all keys greater than the original key in BST.

Example:
Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13

Algo: O(N) + O(height ~ logN)
sum = 0
- reverse in-order
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
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return nullptr;
        convertBST(root->right);
        root->val += sum_;
        sum_ = root->val;
        convertBST(root->left);
        return root;
    }
private:
    int sum_ = 0;
};