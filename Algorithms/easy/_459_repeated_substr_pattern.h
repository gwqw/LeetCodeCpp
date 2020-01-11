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

Algo: 
- go through string and add to substr while symb != 1st
- if symb == first,
    - go and paste to the second substr i
    - cmp strs if they are equal go further else s1 += s2
    
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string s1, s2; 
        bool find_template = true;
        for (auto c : s) {
            // accumulate s1
            if (s1.empty() || (find_template && c != s1[0])) {
                s1 += c;
            // start accumulate second template
            } else if (find_template) {
                find_template = false;
                s2 += c;
            } else {
                if (c != s[0]) {
                    s2 += c;
                } else {
                    if (s1 == s2) {
                        s2 = "c";
                    } else {
                        s1 += s2;
                        s2 = "c";
                    }
                }
            }
        }
        return s1 == s2;
    }
};