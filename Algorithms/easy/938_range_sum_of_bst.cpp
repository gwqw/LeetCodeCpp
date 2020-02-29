/**
    938. Range sum of BST
Given the root node of a binary search tree, return the sum of values of all nodes 
with value between L and R (inclusive).
The binary search tree is guaranteed to have unique values.

Example 1:
Input: root = [10, 5, 15, 3, null]

Algo1: naive: O(N), O(N)
- save BST to vector between L and R
- calc sum between left and right

Algo2: O(N), O(1)
- same but + to sum 
*/

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        vector<int> arr;
        tree2arr(root, L, R, arr);
        int sum = 0;
        for (auto v : arr) {
            sum += v;
        }
        return sum;
    }
    
private:
    void tree2arr(TreeNode* node, int L, int R, vector<int>& res) {
        if (!node) return;
        if (node->val < L) return;
        tree2arr(node->left, L, R, res);
        res.push_back(node->val);
        if (node->val > R) return;
        tree2arr(node->left, L, R, res);
    }
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        tree2arr(root, L, R, sum);
        return sum;
    }
    
private:
    void tree2arr(TreeNode* node, int L, int R, int& sum) {
        if (!node) return;
        if (node->val < L) return;
        tree2arr(node->left, L, R, res);
        sum += node->val;
        if (node->val > R) return;
        tree2arr(node->left, L, R, res);
    }
};
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!node) return 0;
        if (node->val < L) return 0;
        int sum = tree2arr(node->left, L, R, res);
        sum += node->val;
        if (node->val > R) return sum;
        sum += tree2arr(node->left, L, R, res);
        return sum
    }
};

