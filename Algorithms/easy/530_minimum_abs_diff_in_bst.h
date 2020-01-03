/**
    530. Minimum Absolute Difference in BST
Given a binary search tree with non-negative values, 
find the minimum absolute difference between values of any two nodes.

Example:
Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).

Note: There are at least two nodes in this BST.

Algo1: use pre-order and find min dist: O(N) + O(Heght)
- go pre-order and pass cur min and cur max values and exist flag

Algo2: use in-order and pass previous element: for BST in-order gives sorted array, so pass previous element and flag

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
    int getMinimumDifference(TreeNode* root) {
        return getMinRec(root, -1, -1);
    }
private:
    static int getMinRec(TreeNode* node, int min_value, int max_value) {
        if (!node) return INT_MAX;
        int res = INT_MAX;
        if (min_value != -1) {
            res = min(res, node->val - min_value);
        }
        if (max_value != -1) {
            res = min(res, max_value - node->val);
        }
        res = min(res, getMinRec(node->left, min_value, node->val));
        res = min(res, getMinRec(node->right, node->val, max_value));
        return res;
    }
};

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int prev_value = -1;
        return getMinRec(root, prev_value);
    }
private:
    static int getMinRec(TreeNode* node, int& prev_value) {
        if (!node) return INT_MAX;
        int min_value = getMinRec(node->left, prev_value);
        if (prev_value != -1) {
            min_value = min(min_value, node->val - prev_value);
        }
        prev_value = node->val;
        min_value = min(
            min_value,
            getMinRec(node->right, prev_value)
        );

        return min_value;
    }
};


