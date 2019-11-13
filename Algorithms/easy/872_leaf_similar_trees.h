/**
    872. Leaf-Similar Trees
    
Consider all the leaves of a binary tree. 
From left to right order, the values of those leaves form a leaf value sequence.

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
Two binary trees are considered leaf-similar if their leaf value sequence is the same.
Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

Note:
Both of the given trees will have between 1 and 100 nodes.

Algo1: use dfs and count leaves: O(N1 + N2) + O(N1 + N2)
can be recursive, can be iterative
- go dfs and fill list with leafs
- repeat for tree2
- cmp lists

Algo2: Go throug 2 trees in parallel: O(N1 + N2) + O(H1 + H2)
- go dfs (iterative) through 2 trees
- and chek leaf1 == leaf2

Algo3: combined (1+2): O(N1 + N2) + O(N1 + H2)
- go through 1-st and fill vector of leaves
- go through second with vector1 and we can break out ahead of time

Algo4: create Iterator class, which goes to next leaf
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        list<int> t1, t2;
        find_leaves(root1, t1);
        find_leaves(root2, t2);
        return t1 == t2;
    }
private:
    static void find_leaves(TreeNode* root, list<int>& leaves) {
        if (!root) return;
        if (!root->left && !root->right) {
            leaves.push_back(root->val);
        }
        find_leaves(root->left, leaves);
        find_leaves(root->right, leaves);
    }
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> t1, t2;
        find_leaves(root1, t1);
        find_leaves(root2, t2);
        return t1 == t2;
    }
private:
    static void find_leaves(TreeNode* root, vector<int>& leaves) {
        if (!root) return;
        if (!root->left && !root->right) {
            leaves.push_back(root->val);
        }
        find_leaves(root->left, leaves);
        find_leaves(root->right, leaves);
    }
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> t1, t2;
        find_leaves(root1, t1);
        find_leaves(root2, t2);
        return t1 == t2;    
    }
private:
    static void find_leaves(TreeNode* root, vector<int>& leaves) {
        stack<TreeNode*> st1;
        if (!root) return;
        st1.push(root);
        while (!st1.empty()) {
            auto node = st1.top();
            st1.pop();
            if (node->right) {
                st1.push(node->right);
            }
            if (node->left) {
                st1.push(node->left);
            }
            if (!node->left && !node->right) {
                leaves.push_back(node->val);
            }
        }
    }
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (!root1 || !root2) return root1 == root2;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(root1);
        st2.push(root2);
        optional<int> v1 = nullopt, v2 = nullopt;
        while (!st1.empty() && !st2.empty()) {
            // get value 1
            v1 = nullopt;
            while (!st1.empty()) {                
                auto node = st1.top();
                st1.pop();
                if (node->right) {
                    st1.push(node->right);
                }
                if (node->left) {
                    st1.push(node->left);
                }
                if (!node->left && !node->right) {
                    v1 = node->val;
                    break;
                }
            }
            // get value 2
            v2 = nullopt;
            while (!st2.empty()) {
                auto node = st2.top();
                st2.pop();
                if (node->right) {
                    st2.push(node->right);
                }
                if (node->left) {
                    st2.push(node->left);
                }
                if (!node->left && !node->right) {
                    v2 = node->val;
                    break;
                }
            }
            if (!v1 || !v2 || v1 != v2) return false;
        }
        return st1.empty() && st2.empty();  
    }
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (!root1 || !root2) return root1 == root2;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(root1);
        st2.push(root2);
        optional<int> v1 = nullopt, v2 = nullopt;
        while (!st1.empty() && !st2.empty()) {
            v1 = get_value(st1);
            v2 = get_value(st2);
            if (!v1 || !v2 || v1 != v2) return false;
        }
        return st1.empty() && st2.empty();  
    }
private:
    static optional<int> get_value(stack<TreeNode*>& st) {
        while (!st.empty()) {                
            auto node = st.top();
            st.pop();
            if (node->right) {
                st.push(node->right);
            }
            if (node->left) {
                st.push(node->left);
            }
            if (!node->left && !node->right) {
                return node->val;
            }
        }
        return nullopt;
    }  
};



