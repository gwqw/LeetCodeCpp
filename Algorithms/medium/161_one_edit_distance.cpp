/**
    161. One Edit Distance
Given two strings s and t, return true if they are both one edit distance apart, otherwise return false.
A string s is said to be one distance apart from a string t if you can:
- Insert exactly one character into s to get t.
- Delete exactly one character from s to get t.
- Replace exactly one character of s with a different character to get t.

Example 1:
Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.

Example 2:
Input: s = "", t = ""
Output: false
Explanation: We cannot get t from s by only one step.

Example 3:
Input: s = "a", t = ""
Output: true

Example 4:
Input: s = "", t = "A"
Output: true

Constraints:
0 <= s.length <= 10^4
0 <= t.length <= 10^4
s and t consist of lower-case letters, upper-case letters and/or digits.

Algo: naive: 3 pass
if s1 == s2: return false
find first diff -> i
test 3 methods:
    if s[i:] == t[i+1:]: return true  # insert to s
    if s[i+1:] == t[i+1:]: return true # replace 
    if s[i+1:] == t[i:]: return true   # delete from s
return false
*/

class Solution {
public:
    bool isOneEditDistance(string_view s, string_view t) {
        if (s.size()+1 < t.size() || t.size()+1 < s.size()) return false;
        if (s == t) return false;
        size_t i = 0;
        for (; i < min(s.size(), t.size()); ++i) {
            if (s[i] != t[i]) break;
        }
        if (i != t.size())
            if (s.substr(i) == t.substr(i+1)) return true;
        if (i != t.size() && i != s.size())
            if (s.substr(i+1) == t.substr(i+1)) return true;
        if (i != s.size())
            if (s.substr(i+1) == t.substr(i)) return true;
        return false;
    }
};