/**
    101. Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

Algo:
1. Recursive: O(N), O(logN) or O(N)
    left tree are sym equal to the right
2. Iterative: O(N), O(logN) or O(N)
    use queue or deque
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isBranchSymmetric(root->left, root->right);
    }
    
    bool isBranchSymmetric(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        
        if (p->val != q->val) return false;
        
        return  isBranchSymmetric(p->left, q->right) and
                isBranchSymmetric(p->right, q->left);
    }
};

