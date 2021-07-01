/**
    99. Recover Binary Search Tree
You are given the root of a binary search tree (BST), where exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

Follow up: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

Example 1:
Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.

Example 2:
Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.

Constraints:
The number of nodes in the tree is in the range [2, 1000].
-2^31 <= Node.val <= 2^31 - 1

Algo:
       /
  /\  /
 /  \/
/
swap peak points
dfs(lnr): find peak points
go and swap 2 values
try for 1 pass
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
    void recoverTree(TreeNode* root) {
        TreeNode* prevNode = nullptr;
        TreeNode* firstNode = nullptr; 
        TreeNode* secondNode = nullptr;
        visit(root, prevNode, firstNode, secondNode);
        assert(firstNode && secondNode);
        swap(firstNode->val, secondNode->val);
    }
    
private:
    void visit(TreeNode* node, TreeNode* &prevNode, 
        TreeNode* &firstNode, TreeNode* &secondNode) 
    {
        if (!node) return;
        visit(node->left, prevNode, firstNode, secondNode);
        if (prevNode && node->val < prevNode->val) {
            if (!firstNode) {
                firstNode = prevNode;
            }
            secondNode = node;
        }
        prevNode = node;
        visit(node->right, prevNode, firstNode, secondNode);
    }
};
