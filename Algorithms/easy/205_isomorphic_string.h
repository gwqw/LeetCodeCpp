/**
    205. Isomorphic Strings
Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true

Example 2:
Input: s = "foo", t = "bar"
Output: false

Example 3:
Input: s = "paper", t = "title"
Output: true

Note:
You may assume both s and t have the same length.

Algo: O(N^2) + O(1) -- naive
- take char: O(N)
    - find same char, (O(N))
    - check if in second string theese chars are the same O(N)
    
Algo2: O(N) + O(N)
- go through string and make chars associations: O(N)
    if (c not in dicts and c2 not in dictt):
        dicts[c] = c2, dictt[c2] = c
    else if (c in dicts and c2 in dictt):
        if dicts[c] != c2 or dictt[c2] != c: return false
    else:
        return false    
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        for (int i = 0; i < s.size(); ++i) {
            char c_s = s[i];
            char c_t = t[i];
            for (int j = i; j < s.size(); ++j) {
                if ((s[j] == c_s && t[j] != c_t) || (t[j] == c_t && s[j] != c_s)) return false;
            }
        }
        return true;
    }
};


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> ds, dt;
        for (int i = 0; i < s.size(); ++i) {
            char cs = s[i];
            char ct = t[i];
            if (!ds.count(cs) && !dt.count(ct)) {
                ds[cs] = ct;
                dt[ct] = cs;
            } else if (ds.count(cs) && dt.count(ct)) {
                if (ds[cs] != ct || dt[ct] != cs) return false;
            } else {
                return false;
            }
        }
        return true;
    }
};
