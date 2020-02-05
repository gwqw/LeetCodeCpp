/**
    572. Subtree of Another Tree
Given two non-empty binary trees s and t, 
check whether tree t has exactly the same structure and node values with a subtree of s. 
A subtree of s is a tree consists of a node in s and all of this node's descendants. 
The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:
     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.

Example 2:
Given tree s:
     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.

Algo1: naive O(size(s)*size(t)) + O(height(s))
- for every node check if this subtree needed

Algo2: use tree height O(size(s)+size(t)) + O(height(s))
- calc t height
- use lrn dfs, and get height and is (h1 == h2): check if equal
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
//naive
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (isEqual(s, t)) return true;
        if (!s) return false;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
private:
    bool isEqual(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        return s->val == t->val && isEqual(s->left, t->left) 
            && isEqual(s->right, t->right);
    }
};

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        int t_height = getHeight(t);
        int s_height = 0;

        return checkSubTree(s, s_height, t_height, t);
    }
private:
    bool checkSubTree(TreeNode* n, int& s_height, int t_height, TreeNode* t) {
        if (!n) {
            s_height = 0;
            return false;
        }
        auto res = checkSubTree(n->left, s_height, t_height, t);
        if (res) return true;
        int lheight = s_height;
        res = checkSubTree(n->right, s_height, t_height, t);
        if (res) return true;
        int rheight = s_height;
        s_height = 1 + max(lheight, rheight);
        if (s_height == t_height) 
            return isEqual(n, t);
        else
            return false;
    }

    bool isEqual(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        return s->val == t->val && isEqual(s->left, t->left) 
            && isEqual(s->right, t->right);
    }
    
    int getHeight(TreeNode* n) {
        if (!n) return 0;
        return 1 + max(getHeight(n->left), getHeight(n->right));
    }
};




