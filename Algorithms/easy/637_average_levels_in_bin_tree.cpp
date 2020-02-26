/**
    637. Average of Levels in Binary Tree
Given a non-empty binary tree,
return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.

Algo: use bfs: O(N) + O(N)
- make ave array
- go through tree and saves lvl too
- added all values to array
- calc average through array when new lvl
- and calculate average for last leaves

Also we can use dfs
it is good to save statistic{long long sum, int count}
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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        vector<double> res;
        vector<int> lvl_elements;
        queue<pair<TreeNode*, size_t>> q;
        q.emplace(root, 0);
        size_t prev_lvl = 0;
        while (!q.empty()) {
            auto [n, lvl] = q.front();
            q.pop();
            if (lvl == prev_lvl) {
                lvl_elements.push_back(n->val);
            } else {
                res.push_back(getAverage(lvl_elements));
                lvl_elements.clear();
                lvl_elements.push_back(n->val);
                prev_lvl = lvl;                
            }
            if (n->left) {
                q.emplace(n->left, lvl+1);
            }
            if (n->right) {
                q.emplace(n->right, lvl+1);
            }
        }
        res.push_back(getAverage(lvl_elements));        
        return res;
    }
    
private:
    double getAverage(const vector<int>& vec) {
        double ave = 0;
        for (auto v : vec) {
            ave += (double)v/vec.size();
        }
        return ave;
    }
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        vector<double> res;
        long long sum = 0;
        int el_count = 0;
        queue<pair<TreeNode*, size_t>> q;
        q.emplace(root, 0);
        size_t prev_lvl = 0;
        while (!q.empty()) {
            auto [n, lvl] = q.front();
            q.pop();
            if (lvl == prev_lvl) {
                sum += n->val;
                ++el_count;
            } else {
                res.push_back((double)sum / el_count);
                sum = n->val;
                el_count = 1;
                prev_lvl = lvl;                
            }
            if (n->left) {
                q.emplace(n->left, lvl+1);
            }
            if (n->right) {
                q.emplace(n->right, lvl+1);
            }
        }
        res.push_back((double)sum / el_count);        
        return res;
    }
};


