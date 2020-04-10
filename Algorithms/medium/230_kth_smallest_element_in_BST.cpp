/**
    230. Kth Smallest Element in a BST
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:
Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Algo: rec dfs: O(max(k, height)) + O(height)
- lvr-dfs
- use counter and answer and reference to visit
- go left()
- ++counter
- if counter == k:
    - ans = value
    - return
- if counter > k:
    - return 
- else: 
    - go right
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
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        int ans = 0;
        visit(root, k, counter, ans);
        return ans;
    }
    
private:
    void visit(TreeNode* node, int k, int& counter, int& ans) {
        if (!node) {
            return;
        }
        visit(node->left, k, counter, ans);
        ++counter;
        if (counter == k) {
            ans = node->val;
            return;
        }
        if (counter > k) return;
        visit(node->right, k, counter, ans);
    }
};



