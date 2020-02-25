/**
    108. Convert Sorted Array to Binary Search Tree
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree 
in which the depth of the two subtrees of every node never differ by more than 1.

Example:
Given the sorted array: [-10,-3,0,5,9],
One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
      0
     / \
   -3   9
   /   /
 -10  5

Algo: recursive
- find center
- create root
- create left from left subarray
- create right from right subarray
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
    TreeNode* sortedArrayToBST(const vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return createBSTrecursive(nums, 0, nums.size()-1);
    }
    
private:
    static TreeNode* createBSTrecursive(const vector<int>& nums, size_t left, size_t right) {
        size_t mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        if (left < mid) {
            root->left = createBSTrecursive(nums, left, mid-1);
        }
        if (mid < right) {
            root->right = createBSTrecursive(nums, mid+1, right);
        }
        return root;
    }
};

