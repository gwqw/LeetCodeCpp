/**
    669. Trim a Binary Search Tree
Given a binary search tree and the lowest and highest boundaries as L and R, 
trim the tree so that all its elements lies in [L, R] (R >= L). 
You might need to change the root of the tree,
so the result should return the new root of the trimmed binary search tree.

Example 1:
Input: 
    1
   / \
  0   2
  L = 1
  R = 2
Output: 
    1
      \
       2

Example 2:
Input: 
    3
   / \
  0   4
   \
    2
   /
  1
  L = 1
  R = 3
Output: 
      3
     / 
   2   
  /
 1

Algo: O(Height) + O(1)
- find new root: go while node->val must be in [L, R]
- find left edge:
    - go left:
    - if n->val < L:
    - n = n->right and go here
    - if n-> val > L:
        - go left
- find right edge:
    - go right:
    - if n->val > R:
    - n = n-> left and repeat    

Algo2: simple recursion: O(N) + O(height), worse than prev, because more node are visited
- if root < L:
    - return trim(root->right)
- if root > R:
    - return trim(root->left)
- root->left = trim(root->left)
- root->right = trim(root->right)

Algo2: recursion: O(Height) + O(height)
- if root < L:
    - return trim(root->right, from_where)
- if root > R:
    - return trim(root->left, from_where)
- if from_left or find_root:
    - root->left = trim(root->left, from_left)
- if from right or find_root:
    - root->right = trim(root->right, from_right)

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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        root = findNewRoot(root, L, R);
        if (!root) return root;
        
        trimLeft(root, L);
        trimRight(root, R);

        return root;
    }
    
private:

    static TreeNode* findNewRoot(TreeNode* root, int L, int R) {
        while (root) {
            if (L <= root->val && root->val <= R) break;
            if (root->val < L) {
                root = root->right;
            } else if (root->val > R) {
                root = root->left;
            }
        }
        return root;
    }
    
    static void trimLeft(TreeNode* root, int L) {
        auto node = root->left;
        auto prev_node = root;
        while (node) {
            if (node->val < L) {
                prev_node->left = node->right;
                node = node->right;
            } else {
                prev_node = node;
                node = node->left;
            }
        }
    }
    
    static void trimRight(TreeNode* root, int R) {
        auto node = root->right;
        auto prev_node = root;
        while (node) {
            if (node->val > R) {
                prev_node->right = node->left;
                node = node->left;
            } else {
                prev_node = node;
                node = node->right;
            }
        }
    }
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return nullptr;
        if (root->val < L) {
            return trimBST(root->right, L, R);
        }
        if (root->val > R) {
            return trimBST(root->left, L, R);
        }
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);

        return root;
    }
};

class Solution {
    enum class GoFrom {left, right, undef};
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        return trimBST(root, L, R, GoFrom::undef);
    }
    
private:
    TreeNode* trimBST(TreeNode* root, int L, int R, GoFrom go_from) {
        if (!root) return nullptr;
        if (root->val < L) {
            return trimBST(root->right, L, R, go_from);
        }
        if (root->val > R) {
            return trimBST(root->left, L, R, go_from);
        }
        if (go_from == GoFrom::left || go_from == GoFrom::undef) {
            root->left = trimBST(root->left, L, R, GoFrom::left);
        } 
        if (go_from == GoFrom::right || go_from == GoFrom::undef) {
            root->right = trimBST(root->right, L, R, GoFrom::right);
        }

        return root;
    }
};


