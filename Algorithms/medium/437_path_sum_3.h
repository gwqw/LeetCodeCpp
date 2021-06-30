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

Algo: dfs pre-order and save sums to vector: O(N^2) + O(N + log(N))
- go through daughter and save paths
- in node add to all paths value
- and cmp it to sum (inc max_sum if needed)

Algo2: prefix sums in dict (pref sum -> count): O(N) + O(N)
- go through tree 
    - add new sum to dict 
    - search pref_sum - sum in dict: ++max_sum if true
    - if pref_sum == sum: ++max_sum
    - go to left and right
    - remove prefix sum
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
        unordered_map<int, int> pref_sum_dict;
        calc_sum(root, sum, pref_sum_dict, 0);
        return max_sum;
    }
    
private:

    void calc_sum(TreeNode* node, int sum, unordered_map<int, int>& sum_dict, int pref_sum) {
        if (!node) return;
        
        pref_sum += node->val;
        if (auto it = sum_dict.find(pref_sum - sum); it != sum_dict.end()) {
            max_sum += it->second;            
        }
        ++sum_dict[pref_sum];
        if (pref_sum == sum) {
            ++max_sum;
        }
        calc_sum(node->left, sum, sum_dict, pref_sum);
        calc_sum(node->right, sum, sum_dict, pref_sum);
        --sum_dict[pref_sum];
        //if (sum_dict[pref_sum] == 0) {
        //    sum_dict.erase(pref_sum);
        //}
    }

    int max_sum = 0;
};

/*
[10,5,-3,3,2,null,11,3,-2,null,1]
8
[5,4,8,11,null,13,4,7,2,null,null,5,1]
22
[1]
0
[1,-2,-3,1,3,-2,null,-1]
-1

cout << "found p - s: p= " << pref_sum << " count= " << it->second <<endl;
*/


