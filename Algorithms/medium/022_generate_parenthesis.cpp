/**
    22. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

Algo: recursive
- recursion exit
- split every call:
    - call with cur+'(' if '(' count < n
    - call with cur+')' if ')' count < '(' count
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesis(n, 0, 0, "", res);
        return res;
    }
    
private:
    void generateParenthesis(int n, int open, int close, string brackets, vector<string>& ans) {
        if (open == n && close == n) {
            ans.push_back(move(brackets));
            return;
        }
        if (open < n) {
            generateParenthesis(n, open+1, close, brackets + '(', ans);
        }
        if (close < open) {
            generateParenthesis(n, open, close+1, brackets + ')', ans);
        }
    }

};

