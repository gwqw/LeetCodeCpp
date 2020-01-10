/**
    110. Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as:
a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

Example 1:
Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:
Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.

Algo: dfs: post-order: O(N) + O(logN)
- if !node -> h = 0
- left_height = get_height(left)
- right_height = get_height(right)
- if (left is balanced and right is balanced and abs(left_hight-right_height)<2):
    - sub_tree is balanced and its height is max(left_height, right_height)+1
- else:
    - tree is unbalanced

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
    bool isBalanced(TreeNode* root) {
        auto [is_balanced,_] = getHeight(root);
        return is_balanced;
    }
private:
    static pair<bool, int> getHeight(TreeNode* node) {
        if (!node) return {true, 0};
        auto [is_left_balanced, left_height] = getHeight(node->left);
        if (!is_left_balanced) return {false, 0};
        auto [is_right_balanced, right_height] = getHeight(node->right);
        return {is_right_balanced && abs(left_height - right_height) < 2,
                max(left_height, right_height)+1};
    }
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return static_cast<bool>(getHeight(root));
    }
private:
    static optional<int> getHeight(TreeNode* node) {
        if (!node) return 0;
        auto left_height = getHeight(node->left);
        if (!left_height) return nullopt;
        auto right_height = getHeight(node->right);
        if (right_height && abs(*left_height - *right_height) < 2) {
            return max(*left_height, *right_height)+1;
        } else {
            return nullopt;
        }
    }
};

