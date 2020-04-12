/**
    105. Construct Binary Tree from Preorder and Inorder Traversal
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
   
Algo: recursive O(height*N)
- if from == to: return nullptr
- root = preorder[from]
- find root->val in in_order in [from, to) -> iroot
- left_length = iroot - ifrom, right_length = ito - iroot - 1
- root->left = rec(pre, pfrom+1, pfrom+1+left_length, inorder, ifrom, left_length)
- root->right = rec(pre, pfrom+1+left_length, pto, inorder, iroot+1, ito)

Algo (enhanced): use dict for fast index search
- for inrder make dict val -> pos

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
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    
private:
    TreeNode* buildTree(const vector<int>& preorder, size_t pfrom, size_t pto, 
        const vector<int>& inorder, size_t ifrom, size_t ito) 
    {
        if (pfrom == pto) return nullptr;
        auto root = new TreeNode(preorder[pfrom]);
        auto iroot = distance(inorder.begin(), 
            find(inorder.begin() + ifrom, inorder.begin() + ito, root->val)
        );
        assert(iroot != ito);
        size_t left_length = iroot - ifrom;
        // left
        root->left = buildTree(
            preorder, pfrom+1, pfrom+1+left_length,
            inorder, ifrom, ifrom + left_length
        );
        // right
        root->right = buildTree(
            preorder, pfrom+1+left_length, pto,
            inorder, iroot+1, ito
        );
        return root;
    }
};

class Solution {
public:
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
        // make dict
        for (size_t i = 0; i < inorder.size(); ++i) {
            inordered_val_to_pos[inorder[i]] = i;
        }
    
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    
private:
    TreeNode* buildTree(const vector<int>& preorder, size_t pfrom, size_t pto, 
        const vector<int>& inorder, size_t ifrom, size_t ito) 
    {
        if (pfrom == pto) return nullptr;
        auto root = new TreeNode(preorder[pfrom]);
        auto iroot = inordered_val_to_pos[root->val];
        assert(iroot != ito);
        size_t left_length = iroot - ifrom;
        // left
        root->left = buildTree(
            preorder, pfrom+1, pfrom+1+left_length,
            inorder, ifrom, ifrom + left_length
        );
        // right
        root->right = buildTree(
            preorder, pfrom+1+left_length, pto,
            inorder, iroot+1, ito
        );
        return root;
    }
    
    unordered_map<int, size_t> inordered_val_to_pos;
};


/*
[1,2,4,5,3,6,7]
[4,2,5,1,6,3,7]
[3,9,20,15,7]
[9,3,15,20,7]
*/
