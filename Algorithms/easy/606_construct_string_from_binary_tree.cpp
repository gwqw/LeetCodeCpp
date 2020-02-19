/**
    606. Construct String from Binary Tree
You need to construct a string consists of parenthesis
and integers from a binary tree with the preorder traversing way.
The null node needs to be represented by empty parenthesis pair "()".
And you need to omit all the empty parenthesis pairs that
don't affect the one-to-one mapping relationship between the string and the original binary tree.

Example 1:
Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     
Output: "1(2(4))(3)"
Explanation: Originallay it needs to be "1(2(4)())(3()())", 
but you need to omit all the unnecessary empty parenthesis pairs. 
And it will be "1(2(4))(3)".

Example 2:
Input: Binary tree: [1,2,3,null,4]
       1
     /   \
    2     3
     \  
      4 
Output: "1(2()(4))(3)"
Explanation: Almost the same as the first example, 
except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.

Algo: use pre-order dfs: O(N) + O(N)
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
 
// 36ms, 54Mb
class Solution {
public:
    string tree2str(TreeNode* n) {
        if (!n) return "";
        string res = to_string(n->val);
        if (!n->left && !n->right) return res;
        res += '(' + tree2str(n->left) + ')';
        if (n->right) {
            res += '(' + tree2str(n->right) + ')';
        }
        return res;
    }
};

// 16ms, 22.3 Mb
class Solution {
public:
    string tree2str(TreeNode* n) {
        string res;
        tree2str(n, res);
        return res;
    }
private:
    void tree2str(TreeNode* n, string& res) {
        if (!n) return;
        res += to_string(n->val);
        if (!n->left && !n->right) return;
        res.push_back('(');
        tree2str(n->left, res);
        res.push_back(')');
        if (n->right) {
            res.push_back('(');
            tree2str(n->right, res);
            res.push_back(')');
        }
    }
};

// 12ms, 21.5Mb
class Solution {
public:
    string tree2str(TreeNode* n) {
        tree2str_internal(n);
        return ss.str();
    }
private:
    void tree2str_internal(TreeNode* n) {
        if (!n) return;
        ss << n->val;
        if (!n->left && !n->right) return;
        ss << '(';
        tree2str_internal(n->left);
        ss << ')';
        if (n->right) {
            ss << '(';
            tree2str_internal(n->right);
            ss << ')';
        }
    }
    stringstream ss;
};



