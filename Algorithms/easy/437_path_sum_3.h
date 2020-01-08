/**
    437. Path Sum III
You are given a binary tree in which each node contains an integer value.
Find the number of paths that sum to a given value.
The path does not need to start or end at the root or a leaf, 
but it must go downwards (traveling only from parent nodes to child nodes).
The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11

Algo: dfs pre-order: O(N^2) + O(N + log(N))
- go through daughter and save paths
- in node add to all paths value
- and cmp it to sum (inc max_sum if needed)

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
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        getSums(root, sum);
        return max_sum;
    }
private:
    vector<int> getSums(TreeNode* node, int sum) {
        if (!node) return {};
        int v = node->val;
        if (v == sum) ++max_sum;
        auto left_sums = getSums(node->left, sum);
        auto right_sums = getSums(node->right, sum);
        vector<int> res = move(left_sums);
        res.insert(res.end(), move_iterator(right_sums.begin()), move_iterator(right_sums.end()));
        for (auto& value : res) {
            value += v;
            if (value == sum) ++max_sum;
        }
        res.push_back(v);
        return res;
    }
    
    int max_sum = 0;
};


class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        int cur_sum = 0;
        calc_sum(root, sum, cur_sum);
        return max_sum;
    }
    
private:

    void calc_sum(TreeNode* node, int sum, int cur_sum) {
        if (!node) return;
        cur_sum += node->val;
        if (cur_sum == sum) ++max_sum;
        calc_sum(node->left, sum, cur_sum);
        calc_sum(node->right, sum, cur_sum);
    }

    int max_sum = 0;
};



