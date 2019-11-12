/**
    897. Increasing Order Search Tree

Given a binary search tree, 
rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, 
and every node has no left child and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9  
Note:
The number of nodes in the given tree will be between 1 and 100.
Each node will have a unique integer value from 0 to 1000.

Algo1: naive copy O(N) + O(N) -- very dumb idea
- go most left
- go right and copy (use stack for parent)

Algo2: dfs - l,c,r (in-order) <- good idea
- use dfs with left, current, right order and add nodes to stack
- take nodes from stack and create tree from bottom

Algo3: dfs wo stack rcl
- use dfs and return right correct tree
- hanging res to the right
- go to the left and make a tree and hanging right tree from the parent
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
    TreeNode* increasingBST(TreeNode* root) {
        // go left
        if (!root) return nullptr;
        root = go_max_left(root);

        // create new tree
        TreeNode* node = new TreeNode(root->val);
        TreeNode* res = node;

        while (root = step_right(root)) {
            node->right = new TreeNode(root->val);
            node = node->right;
        }
        return res;       
    }
private:
    TreeNode* go_max_left(TreeNode* node) { // O(logN) .. O(N)
        while (node->left) {
            parents_.push(node);
            node = node->left;
        }
        return node;
    }
    
    TreeNode* step_right(TreeNode* node) { // O(1) amortized
        if (node->right) {
            parents_.push(node);
            node = node->right;
            return go_max_left(node);
        } else {
            while (!parents_.empty()) {
                TreeNode* parent = parents_.top();
                parents_.pop();
                if (parent->left && parent->left == node) {
                    return parent;
                }
                node = parent;
            }
            return nullptr;
        }
    }
    
    stack<TreeNode*> parents_;
};

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        dfs_add(root);
        TreeNode* previous_node = nullptr;
        while (!nodes_.empty()) {
            auto node = nodes_.top();
            nodes_.pop();
            node->left = nullptr;
            node->right = previous_node;
            previous_node = node;
        }
        return previous_node;   
    }
private:
    void dfs_add(TreeNode* root) {
        if (!root) return;
        dfs_add(root->left);
        nodes_.push(root);
        dfs_add(root->right);
    }
    stack<TreeNode*> nodes_;
};

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* res = nullptr;
        return dfs_add(root, res);
    }
private:
    TreeNode* dfs_add(TreeNode* node, TreeNode* res) {
        if (!node) return res;
        res = dfs_add(node->right, res);    // make a right tree
        node->right = res;                  // hanging it to the right 
        res = node;                         // now it is correct tree
        if (node->left) res = dfs_add(node->left, res); // go to the left with this tree as a parametr and create correct tree
        node->left = nullptr;               // do not forget null left branch for this node
        return res;                         // 
    }
};



















