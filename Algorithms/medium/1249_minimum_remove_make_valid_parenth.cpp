/**
    1249. Minimum Remove to Make Valid Parentheses
Given a string s of '(' , ')' and lowercase English characters. 
Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
Formally, a parentheses string is valid if and only if:
- It is the empty string, contains only lowercase characters, or
- It can be written as AB (A concatenated with B), where A and B are valid strings, or
- It can be written as (A), where A is a valid string.

Example 1:
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

Example 2:
Input: s = "a)b(c)d"
Output: "ab(c)d"

Example 3:
Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.

Example 4:
Input: s = "(a(b(c)d)"
Output: "a(b(c)d)"

Constraints:
1 <= s.length <= 10^5
s[i] is one of  '(' , ')' and lowercase English letters.


Algo1: use stack for '(' -- usual counter
for c in s:
    if c == '(':
        cnt += 1
        print(c)
    elif c == '0':
        cnt -=1
        if cnt < 0:
            cnt = 0
        else:
            print(c)
    else:
        print(c)
if cnt > 0:
    go in backward and remove '('

Algo2: same but in-place (use 2 iterators)

*/

class Solution {
public:
    string minRemoveToMakeValid(string_view s) {
        int cnt = 0;
        string res;
        res.reserve(s.size());
        // first pass
        for (char c : s) {
            if (c == '(') {
                ++cnt;
                res += c;
            } else if (c == ')') {
                --cnt;
                if (cnt < 0) {
                    cnt = 0;
                } else {
                    res += c;
                }
            } else {
                res += c;
            }
        }
        // second pass
        if (cnt == 0) {
            return res;
        }
        string res2;
        res2.reserve(res.size() - cnt);
        for (size_t i = res.size(); i-->0;) {
            char c = res[i];
            if (cnt > 0 && c == '(') {
                --cnt;
            } else {
                res2 += c;
            }
        }
        reverse(res2.begin(), res2.end());
        return res2;
    }
};

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt = 0;
        // forward pass
        size_t i = 0;
        for (size_t j = 0; j < s.size(); ++j) {
            char c = s[j];
            if (c == '(') {
                ++cnt;
                s[i++] = s[j];
            } else if (c == ')') {
                --cnt;
                if (cnt < 0) {
                    cnt = 0;
                } else {
                    s[i++] = s[j];
                }
            } else {
                s[i++] = s[j];
            }
        }
        s.resize(i);
        if (cnt == 0) {
            return s;
        }
        
        // backward pass
        reverse(s.begin(), s.end());
        i = 0;
        for (size_t j = 0; j < s.size(); ++j) {
            char c = s[j];
            if (cnt > 0 && c == '(') {
                --cnt;
            } else {
                s[i++] = s[j];
            }
        }
        s.resize(i);
        reverse(s.begin(), s.end());
        return s;
    }
};

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt = 0;
        // forward pass
        size_t i = 0;
        for (size_t j = 0; j < s.size(); ++j) {
            char c = s[j];
            if (c == '(') {
                ++cnt;
                s[i++] = s[j];
            } else if (c == ')') {
                --cnt;
                if (cnt < 0) {
                    cnt = 0;
                } else {
                    s[i++] = s[j];
                }
            } else {
                s[i++] = s[j];
            }
        }
        s.resize(i);
        if (cnt == 0) {
            return s;
        }
        
        // backward pass
        i = s.size();
        for (size_t j = s.size(); j-->0; ) {
            char c = s[j];
            if (cnt > 0 && c == '(') {
                --cnt;
            } else {
                s[--i] = s[j];
            }
        }
        s = string{s.begin()+i, s.end()};
        return s;
    }
};


())()(((
     ^
()() 
c:0

()()(
(()

"lee(t(c)o)de)"
"a)b(c)d"
"))(("
"(a(b(c)d)"
"())()((("

