/**
    392. Is Subsequence
Given a string s and a string t, check if s is subsequence of t.
You may assume that there is only lower case English letters in both s and t. 
t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).
A subsequence of a string is a new string which is formed from the original string
 by deleting some (can be none) of the characters without disturbing the relative positions
  of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"
Return true.

Example 2:
s = "axc", t = "ahbgdc"
Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, 
and you want to check one by one to see if T has its subsequence. 
In this scenario, how would you change your code?

Algo1: naive O(Ns+Nt) + O(1)
- for every char in s
- find it's pos in t(from prev_pos)
- if pos == npos return false

Algo2: 2 iteratirs: O(Ns+Nt) + O(1)
- go both it:
    - if *it1 == *it2: ++it2
    - ++it1

Algo3: use un_map with vector: time: O(Nt) creation + O(Ns*log(symb_count)), mem: O(Nt)
- un_multimap dict: symb -> position
- for every symb of t:
- if symb not in dict return false
- pos = dict[symb].find == 0: return false
- --dict[symb]
- return true
*/

class Solution {
public:
    bool isSubsequence(const string& s, const string& t) {
        int prev_pos = 0;
        for (auto c : s) {
            auto pos = t.find(c, prev_pos);
            if (pos == string::npos) return false;
            prev_pos = pos+1;
        }
        return true;
    }
};

class Solution {
public:
    bool isSubsequence(const string& s, const string& t) {
        if (s.empty()) return true;
        for (auto itt = t.begin(), its = s.begin();
            itt != t.end();
            ++itt) 
        {
            if (*its == *itt) ++its;
            if (its == s.end()) return true;
        }
        return false;
    }
};

class Solution {
public:
    bool isSubsequence(const string& s, const string& t) {
        unordered_map<char, vector<int>> dict;
        for (size_t i = 0; i < t.size(); ++i) {
            dict[t[i]].push_back(i);
        }
        
        size_t prev_pos = 0;
        for (auto c : s) {
            if (auto it = dict.find(c); it != dict.end()) {
                const auto& v = it->second;
                auto np_it = lower_bound(v.begin(), v.end(), prev_pos);
                if (np_it == v.end()) return false;
                prev_pos = *np_it + 1;
            } else {
                return false;
            }
        }
        return true;
    }
};

/*
    ahbgdc 
    abc
    
*/
