/**
    1650. Lowest Common Ancestor of a Binary Tree III
Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).
Each node will have a reference to its parent node. The definition for Node is below:
```
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
```
According to the definition of LCA on Wikipedia: "The lowest common ancestor of two nodes p and q in a tree T is the lowest node that has both p and q as descendants (where we allow a node to be a descendant of itself)."

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5 since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [1,2], p = 1, q = 2
Output: 1

Constraints:
The number of nodes in the tree is in the range [2, 10^5].
-10^9 <= Node.val <= 10^9
All Node.val are unique.
p != q
p and q exist in the tree.

Algo1:
n:
    res = search(n->left, q)
    if res: return n
    res = search(n->right, q)
    while n has parent:
        n = n->parent
        if prev = n->left:
            search(n->right, q)
        else:
            search(n->left, q)

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        assert(p && q);
        // check children for p
        bool res = search(p->left, q);
        if (res) return p;
        res = search(p->right, q);
        if (res) return p;
        auto n = p;
        auto prev = p;
        while (n->parent) {
            n = n->parent;
            if (n == q) return n;
            if (n->left == prev) {
                res = search(n->right, q);
                if (res) return n;
            } else {
                res = search(n->left, q);
                if (res) return n;
            }
            prev = n;
        }
        return n;
    }
    
private:
    bool search(Node* n, Node* t) {
        if (!n) return false;
        if (n == t) return true;
        if (search(n->left, t)) return true;
        return search(n->right, t);
    }
};

/*
    3
  5   1
6  2 0  8
  7 4  

*/