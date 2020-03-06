/**
    94. Binary Tree Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values.

Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?

Algo1: recursive dfs

Algo2: iterative dfs
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
    
private:
    void inorder(TreeNode* node, vector<int>& nodes) {
        if (!node) return;
        inorder(node->left, nodes);
        nodes.push_back(node->val);
        inorder(node->right, nodes);
    }
};

/*
    1
     \
      2
     /
    3
    st: 
    v:  1, 3, 2
    r:  1, 3, 2
    
*/



class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        unordered_set<TreeNode*> visited;
        while (!st.empty()) {
            auto node = st.top();
            if (node->left && visited.count(node->left) == 0) {
                st.push(node->left);
            } else {
                st.pop();
                res.push_back(node->val);
                visited.insert(node);
                if (node->right) {
                    st.push(node->right);
                }
            }
        }

        return res;
    }
};


