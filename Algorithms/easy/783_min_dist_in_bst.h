/**
    783. Minimum Distance Between BST Nodes
Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

Example :
Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.

The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

          4
        /   \
      2      6
     / \    
    1   3  

while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
Note:

The size of the BST will be between 2 and 100.
The BST is always valid, each node's value is an integer, and each node's value is different.

Algo: O(N) + O(height)
use in_order through tree and save previous value and cmp with it
+ check if diff in INT_MAX
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
    int minDiffInBST(TreeNode* root) {
        int prev_value = 0;
        bool has_value = false;
        return calcDiffRecursive(root, prev_value, has_value);
    }
private:
    int calcDiffRecursive(TreeNode* node, int& prev_value, bool& has_value) {
        if (!node) return INT_MAX;
        int diff = calcDiffRecursive(node->left, prev_value, has_value);
        if (has_value) {
            diff = min(safe_diff(node->val, prev_value), diff);
        }
        prev_value = node->val;
        has_value = true;
        diff = min(diff, calcDiffRecursive(node->right, prev_value, has_value));
        return diff;
    }
    
    static int safe_diff(int from, int what) {
        if (what < 0 && from > INT_MAX + what) {    
            return INT_MAX;
        }
        return from - what;
    }
};
