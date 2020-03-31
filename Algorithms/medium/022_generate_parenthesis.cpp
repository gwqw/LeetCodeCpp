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
    
Algo: itterative
- go from end and calc opened and closed
- if open and closed > opened:
    - paste close here
    - form rest minimum string: opened*'(' + closed-1*')'
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


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string par_str;
        par_str.reserve(2*n);
        for (int i = 0; i < n; ++i) {
            par_str.push_back('(');
        }
        for (int i = 0; i < n; ++i) {
            par_str.push_back(')');
        }
        vector<string> ans;
        do {
            ans.push_back(par_str);
        } while (generateNextParenthesis(par_str));
        return ans;
    }
    
private:
    bool generateNextParenthesis(string& str) {
        int opened = 0;
        int closed = 0;
        for (int i = (int)str.size()-1; i > 0; --i) {
            if (str[i] == ')') {
                ++closed;
            } else {
                ++opened;
                if (closed > opened) {
                    str[i] = ')';
                    --closed;
                    while (opened > 0) {
                        str[++i] = '(';
                        --opened;
                    }
                    while (closed > 0) {
                        str[++i] = ')';
                        --closed;
                    }
                    return true;
                }
            }
        }
        return false;
    }

};

