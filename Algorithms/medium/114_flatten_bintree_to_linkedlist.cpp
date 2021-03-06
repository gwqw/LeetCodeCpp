/**
	114. Flatten Binary Tree to Linked List
Given the root of a binary tree, flatten the tree into a "linked list":
The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

Example 1:
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [0]
Output: [0]

Constraints:
The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100

Follow up: Can you flatten the tree in-place (with O(1) extra space)?

         1
       2   5
      3 4 n 6
      
1 2 3 4 5 6

Algo1: in-place preorder(nlr) with stack: O(N), O(height) mem+recursion
(can be wo recursion and use list or tree instead stack)
- swap l,r
- cut r to stack
- if no left:
    paste r from stack and go to new l
- if left: 
    go to left
- else: 
    return
 n
l r

   n`
    l
     l1  stack: r, r1
     
Algo2: in-place inversePreOrder(rln) wo stack: O(N), O(height) recursion
go from the end and flatten: and remember current node (head of list)
- flatten right(n->right, &last_node)
- flatten left(n->left, &last_node)
- n->right = last_node
- n->left = nullptr
- last = node

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> st;
        constructLL(root, st);
    }
    
private:
    void constructLL(TreeNode* n, stack<TreeNode*>& st) {
        if (!n) return;
        if (n->left) swap(n->left, n->right);
        if (n->left) {
            st.push(n->left);
            n->left = nullptr;
        }
        if (!n->right && !st.empty()) {
            n->right = st.top();
            st.pop();
        }
        if (n->right) {
            constructLL(n->right, st);
        }
    }
};

class Solution {
using TreeNodePtr = TreeNode*;
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* last_node = nullptr;
        constructLL(root, last_node);
    }
    
private:
    void constructLL(TreeNode* n, TreeNodePtr& last_node) {
        if (!n) return;
        constructLL(n->right, last_node);
        constructLL(n->left, last_node);
        n->right = last_node;
        n->left = nullptr;
        last_node = n;
    }
};


