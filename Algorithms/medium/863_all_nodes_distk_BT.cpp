/**
    863. All Nodes Distance K in Binary Tree
We are given a binary tree (with root node root), a target node, and an integer value k.
Return a list of the values of all nodes that have a distance k from the target node.  The answer can be returned in any order.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.
Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.

Note:
The given tree is non-empty.
Each node in the tree has unique values 0 <= node.val <= 500.
The target node is a node in the tree.
0 <= k <= 1000.

Algo: dfs
- search target:
    if node == target:
        visit(node->left, 0)
        visit(node->right, 0)
        return true
    else:
        res = search(node->left)
        if res:
            visit(node->right, d)
            return true
        res = search(node->right)
        if res:
            visit(node->left, d)
            return true
        return false
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int d = 0;
        vector<int> res;
        search(root, target, d, res, k);
        return res;
    }
    
private:
    bool search(TreeNode* node, TreeNode* target, int& d, vector<int>& res, int k) {
        if (!node) return false;
        if (node == target) {
            d = 0;
            if (k == d) {
                res.push_back(node->val);
                return true;
            }
            visit(node->left, d, res, k);
            visit(node->right, d, res, k);
            return true;
        }
        bool ok = search(node->left, target, d, res, k);
        if (ok) {
            ++d;
            if (d == k) {
                res.push_back(node->val);
            }
            visit(node->right, d, res, k);
            return true;
        }
        ok = search(node->right, target, d, res, k);
        if (ok) {
            ++d;
            if (d == k) {
                res.push_back(node->val);
            }            
            visit(node->left, d, res, k);
            return true;
        }
        return false;
    }
    
    void visit(TreeNode* node, int d, vector<int>& res, int k) {
        if (!node) return;
        d++;
        if (d == k) {
            res.push_back(node->val);
            return;
        }
        if (d > k) return;
        visit(node->left, d, res, k);
        visit(node->right, d, res, k);
    }
};


