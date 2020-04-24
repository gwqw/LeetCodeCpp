/**
    173. Binary Search Tree Iterator
Implement an iterator over a binary search tree (BST). 
Your iterator will be initialized with the root node of a BST.
Calling next() will return the next smallest number in the BST.

Example:
BSTIterator iterator = new BSTIterator(root);
iterator.next();    // return 3
iterator.next();    // return 7
iterator.hasNext(); // return true
iterator.next();    // return 9
iterator.hasNext(); // return true
iterator.next();    // return 15
iterator.hasNext(); // return true
iterator.next();    // return 20
iterator.hasNext(); // return false

Note:
next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
You may assume that next() call will always be valid, that is, 
there will be at least a next smallest number in the BST when next() is called.

Algo: use stack for parents
- go to the left and paste to the stack
if have right: 
    go right and go max left
if don't have right:
    go up
    if it was left:
        that's it
    else: # from right
        go up again while it will be from left or st.empty
        if st.empty and from: right -> no more values

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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) 
        : cur(root)
    {
        has_next = cur != nullptr;
        if (cur && cur->left) {
            goMaxLeft();
        }
    }
    
    /** @return the next smallest number */
    int next() {
        assert(has_next);
        auto res = cur->val;
        if (cur->right) {
            parents.push(cur);
            cur = cur->right;
            goMaxLeft();
        } else {
            bool from_right = true;
            while (!parents.empty()) {
                from_right = parents.top()->right == cur;
                cur = parents.top();
                parents.pop();
                if (!from_right) break;
            }
            if (parents.empty() && from_right) {
                has_next = false;
            }
        }
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() const {
        return has_next;
    }
    
private:
    TreeNode* cur;
    stack<TreeNode*> parents;
    bool has_next = true;

    void goMaxLeft() {
        while (cur->left) {
            parents.push(cur);
            cur = cur->left;
        }
    }
    
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
