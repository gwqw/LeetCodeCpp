/**
    938. Range sum of BST
Given the root node of a binary search tree, return the sum of values of all nodes 
with value between L and R (inclusive).
The binary search tree is guaranteed to have unique values.

Example 1:
Input: root = [10, 5, 15, 3, null]

Algo1: naive: O(N), O(N)
- save BST to vector
- find left_bound and right_bound
- calc sum between left and right

Algo2: naive: O(N), O(N)
- save BST to vector between L and R
- calc sum between left and right

Algo3: O(N), O(1)
- same but + to sum 
*/

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        vector<int> arr;
        tree2arr(root, arr);
        auto lit = lower_bound(arr.begin(), arr.end(), L);
        if (lit == arr.end()) return 0;
        auto rit = lower_bound(arr.begin(), arr.end(), R);
        int sum = 0;
        for (; lit != rit; ++lit) {
            sum += *lit;
        }
        if (rit != arr.end()) sum += *rit;
        return sum;
    }
    
private:
    void tree2arr(TreeNode* node, vector<int>& res) {
        if (!node) return;
        tree2arr(node->left, res);
        res.push_back(node->val);
        tree2arr(node->right, res);
    }
};


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
        if (L < node->val) {
            tree2arr(node->left, L, R, res);
        }
        if (L <= node-> val && node->val <= R) {
            res.push_back(node->val);
        }
        if (node->val >= R) return sum;
        tree2arr(node->right, L, R, res);
    }
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        calcSum(root, L, R, sum);
        return sum;
    }
    
private:
    void calcSum(TreeNode* node, int L, int R, int& sum) {
        if (!node) return;
        if (L < node->val) {
            calcSum(node->left, L, R, sum);
        }
        if (L <= node-> val && node->val <= R) {
            sum += node->val;
        }
        if (node->val >= R) return sum;
        calcSum(node->right, L, R, sum);
    }
};
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) return 0;
        int sum = 0;
        if (L < root->val) {
            sum += rangeSumBST(root->left, L, R);
        }
        if (L <= root-> val && root->val <= R) {
            sum += root->val;
        }
        if (root->val >= R) return sum;
        sum += rangeSumBST(root->right, L, R);
        return sum;
    }
};

