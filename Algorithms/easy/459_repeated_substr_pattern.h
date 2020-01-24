/**
    459. Repeated Substring Pattern
    
Given a non-empty string check if it can be constructed by taking a substring of it 
and appending multiple copies of the substring together. 
You may assume the given string consists of lowercase English letters only 
and its length will not exceed 10000.

Example 1:
Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.

Example 2:
Input: "aba"
Output: False

Example 3:
Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

Algo1: use class pattern: make methods: calcPattern and checkPattern: O(N*d(N)), d -- number of dividers
- get pattern: while s[i] != s[0] && pattern.back != s.back
- check pattern: s.size() % pattern.size() == 0 (good cut) && pattern lies in s from start

Algo2: O(N^2) + O(N)
- (s+s).find(s, 1) < s.size();
    
*/

class Solution {
public:
    bool repeatedSubstringPattern(const string& s) {
        if (s.empty()) return true;
        size_t start = 0;
        string pattern;
        while (calcPattern(s, start, pattern)) {
            if (checkPattern(s, pattern, start)) return true;
        }
        return false;
    }
private:
    bool calcPattern(const string& s, size_t& start, string& pattern) {
        pattern += s[start];
        for (size_t i = start+1; i < s.size(); ++i) {
            if (pattern.empty() || s[i] != pattern[0] || pattern.back() != s.back()) {
                pattern += s[i];
            } else {
                start = i;
                return true;
            }
        }
        return false;
    }
    
    bool checkPattern(const string& s, const string& pattern, size_t start) {
        if (s.size() % pattern.size() != 0) return false;
        size_t j = 0;
        for (size_t i = start; i < s.size(); ++i) {
            if (j == pattern.size()) j = 0;
            if (s[i] != pattern[j++]) return false;
        }
        return (j == pattern.size());
    }
};

/*
"abab"
"aba"
"abcabcabcabc"
"abaababaab"

*/
