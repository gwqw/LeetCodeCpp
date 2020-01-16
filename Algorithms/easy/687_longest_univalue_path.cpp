/**
    687. Longest Univalue Path
Given a binary tree, find the length of the longest path where each node in the path has the same value. 
This path may or may not pass through the root.
The length of path between two nodes is represented by the number of edges between them.
Example 1:
Input:
              5
             / \
            4   5
           / \   \
          1   1   5
Output: 2

Example 2:
Input:
              1
             / \
            4   5
           / \   \
          4   4   5
Output: 2

Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.

Algo:
1) Lets start from the root:
    get_max_route(root):
        ml = get_max_route(left)
        mr = get_max_route(right)
        int nm = 0
        if left and left == value:
            nm += ml
        if right and right == value:
            nm += mr
        max_path = max(max_path, nm)
        return max(ml, mr)+1
        
 
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
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        std::max(get_max_route(root), max_path);
        return max_path;
    }
    int get_max_route(TreeNode* node) {
        if (!node) return 0;
        int ml = get_max_route(node->left);
        int mr = get_max_route(node->right);
        int al = 0;
        int ar = 0;
        if (node->left && node->left->val == node->val) {
            al = ml+1;
        }
        if (node->right && node->right->val == node->val) {
            ar = mr+1;
        }
        if (al+ar > max_path) max_path = al+ar;
        return std::max(al, ar);
    }
    int max_path = 0;
};
 
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        get_max_route(root);
        return max_path;
    }
    int get_max_route(TreeNode* node) {
        if (!node) return 0;
        int ml = get_max_route(node->left);
        int mr = get_max_route(node->right);
        if (node->left && node->left->val != node->val) {
            ml = 0;
        }
        if (node->right && node->right->val != node->val) {
            mr = 0;
        }
        if (ml+mr > max_path) max_path = ml+mr;
        return std::max(ml, mr) + 1;
    }
    int max_path = 0;
};
