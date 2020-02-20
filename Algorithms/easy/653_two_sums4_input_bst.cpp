/**
    653. Two Sum IV - Input is a BST
Given a Binary Search Tree and a target number,
return true if there exist two elements in the BST
such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7
Target = 9
Output: True

Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7
Target = 28
Output: False

Algo1: O(NlogN) + O(Height)
- for every number 
    - search in bst target - number if target != 2*number
 
Algo2: O(N)amortized + O(N)
- for every number
    - if target != 2*number:
        - search target - number in cache 
        - add number to cache
        
Algo3: O(N)amortized + O(N)
- use dfs and save to array
- use O(N) method to search 2 numbers in sorted array
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
 // 20 ms, 23.9Mb
class Solution {
public:
    bool findTarget(TreeNode* root, int target) {
        root_ = root;
        return findTargetRecursive(root, target);
    }

private:
    bool findTargetRecursive(TreeNode* node, int target) {
        if (!node) return false;
        if (target != 2*node->val && searchInBST(root_, target - node->val)) return true;
        if (2 * node->val > target) {
            return findTargetRecursive(node->left, target);
        } else {            
            return findTargetRecursive(node->left, target) ||
                   findTargetRecursive(node->right, target);
        }
    }

    bool searchInBST(TreeNode* root, int value) {
        if (!root) return false;
        if (value == root->val) return true;
        if (value < root->val) {
            return searchInBST(root->left, value);
        } else {
            return searchInBST(root->right, value);
        }
    }
    
    TreeNode* root_;
};

// 24 ms, 26.2Mb
class Solution {
public:
    bool findTarget(TreeNode* root, int target) {
        if (!root) return false;
        if (target != 2*root->val) {
            if (cache.count(target - root->val)) return true;
            cache.insert(root->val);
        }
        return findTarget(root->left, target) ||
               findTarget(root->right, target);
    }

private:
    unordered_set<int> cache;
};

//12ms, 25Mb
class Solution {
public:
    bool findTarget(TreeNode* root, int target) {
        if (!root) return false;
        makeArray(root);
        int j = (int)nums.size()-1;
        for (int i = 0; i < j; ++i) {
            int val = target - nums[i];
            while (j > i && nums[j] > val) {
                --j;
            }
            if (j == i) break;
            if (val == nums[j]) return true;
        }
        return false;
    }

private:

    void makeArray(TreeNode* node) {
        if (!node) return;
        makeArray(node->left);
        nums.push_back(node->val);
        makeArray(node->right);
    }

    std::vector<int> nums;
};



