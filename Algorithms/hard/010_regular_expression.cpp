/**
    10. Regular Expression Matching
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where: 
- '.' Matches any single character.​​​​
- '*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Example 4:
Input: s = "aab", p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".

Example 5:
Input: s = "mississippi", p = "mis*is*p*."
Output: false

Constraints:
0 <= s.length <= 20
0 <= p.length <= 30
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

Algo1: recursion with dp(memo)
*/

// recursion
class Solution {
public:
    bool isMatch(string_view s, string_view p) {
        if (p.empty()) return s.empty();
        bool first_match = (!s.empty()) && (p[0] == s[0] || p[0] == '.');
        
        // without '*'
        if (p.size() < 2 || p[1] != '*') {
            return first_match && isMatch(s.substr(1, s.size()-1), p.substr(1, p.size()-1));
        }
        // with '*'
        return first_match && isMatch(s.substr(1, s.size()-1), p) || isMatch(s, p.substr(2,p.size()-2));
    }
};

// recursion with dp
class Solution {
public:
    bool isMatch(string_view s, string_view p) {
        if (p.empty()) return s.empty();
        if (memo.count(s) && memo[s].count(p)) return memo[s][p];
        
        bool first_match = (!s.empty()) && (p[0] == s[0] || p[0] == '.');
        
        // without '*'
        if (p.size() < 2 || p[1] != '*') {
            memo[s][p] = first_match && isMatch(s.substr(1, s.size()-1), p.substr(1, p.size()-1));
            return memo[s][p];
        }
        // with '*'
        memo[s][p] = first_match && isMatch(s.substr(1, s.size()-1), p) || isMatch(s, p.substr(2,p.size()-2));
        return memo[s][p];
    }
    
private:
    unordered_map<string_view, unordered_map<string_view, bool>> memo;
};