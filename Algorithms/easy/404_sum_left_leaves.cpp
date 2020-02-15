/**
    404. Sum of Left Leaves
Find the sum of all left leaves in a given binary tree.
Example:
    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. 
Return 24.

Algo: dfs: O(N) + O(height)
- go through tree and pass from the left or no we came
- if leef and through left: res += value

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
    int sumOfLeftLeaves(TreeNode* root) {
        return calcLeftSum(root, true); 
    }
    
private:
    static int calcLeftSum(TreeNode* node, bool from_left) {
        if (!node) return 0;
        if (isLeaf(node)) {
            return from_left ? node->val : 0;
        }
        return calcLeftSum(node->left, true) + calcLeftSum(node->right, false);
    }
    
    static bool isLeaf(TreeNode* node) {
        return node->left == nullptr && node->right == nullptr;
    }
};

