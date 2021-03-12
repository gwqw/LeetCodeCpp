/**
    236. Lowest Common Ancestor of a Binary Tree
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [1,2], p = 1, q = 2
Output: 1

Constraints:
    The number of nodes in the tree is in the range [2, 10^5].
    -10^9 <= Node.val <= 10^9
    All Node.val are unique.
    p != q
    p and q will exist in the tree.

Algo1: dfs: nlr and fill stack with parents, after compare stacks

Algo2: use dfs and have 2 flags: foundLeft, foundRight

Algo3: the same but return all in ptr
- if n == null: return null
- if n == p or q: return n anyway (or lca is here, or p or q is here)
- if n->left and n->right == null: return n->left (found in left subtree)
- if n->left=null and n->right: return n->right (found in right subtree)
- if n->left=null and n->right=null: return null: not here
- if n->left and n->right: return n (n is lca)


/*

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pq;
        findNode(root, p, pq);
        stack<TreeNode*> qq;
        findNode(root, q, qq);
        if (pq.size() > qq.size()) {
            swap(pq, qq);
        }
        while (qq.size() > pq.size()) {
            qq.pop();
        }
        while (qq.size() > 0 && pq.size() > 0) {
            TreeNode* l = pq.top();
            pq.pop();
            TreeNode* r = qq.top();
            qq.pop();
            if (l == r) return l;
        }
        return nullptr;
    }
    
private:
    bool findNode(TreeNode* root, TreeNode* target, stack<TreeNode*>& q) {
        if (!root) return false;
        q.push(root);
        if (root == target) return true;
        bool res = findNode(root->left, target, q);
        if (res) return true;
        res = findNode(root->right, target, q);
        if (res) return true;
        q.pop();
        return false;
    }
};

class Solution {
    struct Res {
        TreeNode* res = nullptr;
        bool foundp = false;
        bool foundq = false;
    };
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p, q).res;
    }
private:
    Res lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return Res{};

        auto res1 = lca(root->left, p, q);
        if (res1.res) return res1;
        auto res2 = lca(root->right, p, q);
        if (res2.res) return res2;
        Res res;
        res.foundp = res1.foundp || res2.foundp;
        res.foundq = res1.foundq || res2.foundq;
        if (root == p) res.foundp = true;
        if (root == q) res.foundq = true;
        if (res.foundp && res.foundq) res.res = root;
        return res;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* n, TreeNode* p, TreeNode* q) {
        /*
        - if n == null: return null
        - if n == p or q: return n anyway (or lca is here, or p or q is here)
        - if n->left and n->right == null: return n->left (found in left subtree)
        - if n->left=null and n->right: return n->right (found in right subtree)
        - if n->left=null and n->right=null: return null: not here
        - if n->left and n->right: return n (n is lca)
        */
        if (!n || n == p || n == q) return n;
        auto l = lowestCommonAncestor(n->left, p, q);
        auto r = lowestCommonAncestor(n->right, p, q);
        if (l && !r) return l;
        if (!l && r) return r;
        if (!l && !r) return nullptr;
        /*if (l && r)*/ return n;
    }
};


