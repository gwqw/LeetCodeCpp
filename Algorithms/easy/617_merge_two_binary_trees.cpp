/**
    617. Merge Two Binary Trees
Given two binary trees and imagine that when you put one of them to cover the other,
 some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. 
The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node.
Otherwise, the NOT null node will be used as the node of new tree.

Example 1:

Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7

Note: The merging process must start from the root nodes of both trees.

Algo: dfs 
- node = t1 ? t1->val : 0 + t2 ? t2->val : 0
- if (t1 and t2):
    - node->left = merge(t1->left, t2->left)
    - node->right = merge(t1->right, t2->right)
- elif (t1)
    - ...
- elif (t2)
    ...
- return node

Algo2: use same node from Tree (unchange) like Final in Java

Algo3: use one of tree nodes

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return nullptr;
        TreeNode* res = new TreeNode(
            (t1 ? t1->val : 0) + (t2 ? t2->val : 0)
        );
        if (t1 && t2) {
            res->left = mergeTrees(t1->left, t2->left);
            res->right = mergeTrees(t1->right, t2->right);
        } else if (t1) {
            res->left = mergeTrees(t1->left, nullptr);
            res->right = mergeTrees(t1->right, nullptr);
        } else if (t2) {
            res->left = mergeTrees(nullptr, t2->left);
            res->right = mergeTrees(nullptr, t2->right);
        }
        return res;
    }
};
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return nullptr;
        TreeNode* res = new TreeNode(0);
        if (t1 && t2) {
            res->val = t1->val + t2->val;
            res->left = mergeTrees(t1->left, t2->left);
            res->right = mergeTrees(t1->right, t2->right);
        } else if (t1) {
            res->val = t1->val;
            res->left = mergeTrees(t1->left, nullptr);
            res->right = mergeTrees(t1->right, nullptr);
        } else if (t2) {
            res->val = t2->val;
            res->left = mergeTrees(nullptr, t2->left);
            res->right = mergeTrees(nullptr, t2->right);
        }
        return res;
    }
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        //if (!t1 && !t2) return nullptr;
        if (!t1) {
            return t2;
        }
        if (!t2) {
            return t1;
        }
        TreeNode* res = new TreeNode(t1->val + t2->val);
        res->left = mergeTrees(t1->left, t2->left);
        res->right = mergeTrees(t1->right, t2->right);
        
        return res;
    }
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) {
            return t2;
        }
        if (!t2) {
            return t1;
        }
        
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        
        return t1;
    }
};
