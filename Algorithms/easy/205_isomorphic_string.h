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
- go through string and set chars nums: O(N)
    if (c not in dicts and c2 not in dictt):
        dicts[c] = 1, dictt[c2] = 1
    else if (c in dicts and c2 in dictt):
        if dicts[c] != dictt[c2]: return false
    else:
        return false    
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        for (int i = 0; i < s.size(); ++i) {
            char c_s = s[i];
            char c_t = t[i];
            for (int j = i; j < s.size(); +j) {
                if (s[j] == c_s && t[j] != c_t) return false;
            }
        }
        return true;
    }
};

/*
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> ds, dt;
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            cs = s[i];
            ct = t[i];
            if (!ds.count(cs) && !dt.count(ct)) {
                ds[cs] = cnt;
                dt[ct] = cnt++;
            } else if (ds.count(cs) && dt.count(ct)) {
                if (ds[cs] != dt[ct]) return false;
            } else {
                return false;
            }
        }
        return true;
    }
};
*/