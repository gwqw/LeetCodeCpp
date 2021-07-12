/**
    270. Closest Binary Search Tree Value
Given the root of a binary search tree and a target value, return the value in the BST that is closest to the target.

Example 1:
Input: root = [4,2,5,1,3], target = 3.714286
Output: 4

Example 2:
Input: root = [1], target = 4.428571
Output: 1

Constraints:
The number of nodes in the tree is in the range [1, 10^4].
0 <= Node.val <= 10^9
-10^9 <= target <= 10^9

Algo: 
dfs(node, left, right)
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
    int closestValue(TreeNode* root, double target) {
        int left = -1e9;
        int right = 1e9;
        findNum(root, target, left, right);
        return right - target > target - left ? left : right;
    }
    
private:
    void findNum(TreeNode* node, double target, int& left, int& right) {
        if (!node) return;
        if (node->val > target) {
            right = node->val;
            findNum(node->left, target, left, right);
        } else if (node->val < target) {
            left = node->val;
            findNum(node->right, target, left, right);
        } else {
            left = node->val;
            right = node->val;
        }        
    }
};

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int left = -1e9;
        int right = 1e9;
        while (root) {
            if (root->val > target) {
                right = root->val;
                root = root->left;
            } else if (root->val < target) {
                left = root->val;
                root = root->right;
            } else {
                left = root->val;
                right = root->val;
                break;
            } 
        }
        return right - target > target - left ? left : right;
    }
};