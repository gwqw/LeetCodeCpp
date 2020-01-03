/**
    543. Diameter of Binary Tree
    
Given a binary tree, you need to compute the length of the diameter of the tree. 
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
 
 Algo: O(N) + O(Height)
post-order dfs: 
for every node:
 - get max left length (ll)
 - get max right length (rl)
 - calc path for this node: as ll+rl+1 
 - if it is greater than max_path (class field)
    - update max_path
- return max length+1: max(ll, rl)+1

Algo universal for every tree: O(N) + O(N)
- convert to Tree with parent Node* (write new struct and recursive convert)
- find the farthest node from root: far_node
- find the farthest node from far_node
- distance will be answer
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;    // and remove here
        get_max_length(root);
        return mp-1;
    }
private:
    int get_max_length(TreeNode* node) {
        if (!node) return 0;
        
        int ll = get_max_length(node->left);
        int rl = get_max_length(node->right);
        mp = max(mp, ll+rl+1); // it's easy to remove +1 here and -1 in answer
        return max(rl, ll) + 1;
    }
    int mp = 0;
};

