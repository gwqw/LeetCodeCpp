/**
    567. Permutation in String
Given two strings s1 and s2, return true if s2 contains the permutation of s1.
In other words, one of s1's permutations is the substring of s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false

Constraints:
1 <= s1.length, s2.length <= 10^4
s1 and s2 consist of lowercase English letters.

Algo: dict + sliding window: O(N*|alphabet|)
- if s1.size() > s2.size()
- make counter dict from s1
- make dict from s2.substr(0, s1.size())
if d1 == d2: return true
l = s1.size()
for i in 1,n-l:
    dict2 -= s[i-1]
    dict2 += s[i+l-1]
    if d1 == d2: return true
reutrn false
*/

class Solution {
    using Counter = unordered_map<char, int>;
public:
    bool checkInclusion(string_view s1, string_view s2) {
        if (s1.size() > s2.size()) return false;
        if (s1.empty()) return true;
        size_t len = s1.size();
        auto d1 = getDict(s1);
        auto d2 = getDict(s2.substr(0, len));
        if (d1 == d2) return true;
        for (size_t i = 1; i + len-1 < s2.size(); ++i) {
            char pc = s2[i-1];
            --d2[pc];
            if (d2[pc] == 0) d2.erase(pc);
            ++d2[s2[i+len-1]];
            if (d1 == d2) return true;
        }
        return false;
    }
    
private:
    Counter getDict(string_view s) {
        Counter d;
        for (char c : s) {
            ++d[c];
        }
        return d;
    }
};

class Solution {
    using Counter = array<int, 128>;
public:
    bool checkInclusion(string_view s1, string_view s2) {
        if (s1.size() > s2.size()) return false;
        if (s1.empty()) return true;
        size_t len = s1.size();
        auto d1 = getDict(s1);
        auto d2 = getDict(s2.substr(0, len));
        if (d1 == d2) return true;
        for (size_t i = 1; i + len-1 < s2.size(); ++i) {
            char pc = s2[i-1];
            --d2[pc];
            ++d2[s2[i+len-1]];
            if (d1 == d2) return true;
        }
        return false;
    }
    
private:
    Counter getDict(string_view s) {
        Counter d = {0};
        for (char c : s) {
            ++d[c];
        }
        return d;
    }
};

class Solution {
    using Counter = array<int, 26>;
public:
    bool checkInclusion(string_view s1, string_view s2) {
        if (s1.size() > s2.size()) return false;
        if (s1.empty()) return true;
        size_t len = s1.size();
        auto d1 = getDict(s1);
        auto d2 = getDict(s2.substr(0, len));
        if (d1 == d2) return true;
        for (size_t i = 1; i + len-1 < s2.size(); ++i) {
            char pc = s2[i-1];
            --d2[pc-'a'];
            ++d2[s2[i+len-1]-'a'];
            if (d1 == d2) return true;
        }
        return false;
    }
    
private:
    Counter getDict(string_view s) {
        Counter d = {0};
        for (char c : s) {
            ++d[c-'a'];
        }
        return d;
    }
};


