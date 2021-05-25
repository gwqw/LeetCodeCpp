/**
    438. Find All Anagrams in a String
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
The order of output does not matter.

Example 1:
Input:
s: "cbaebabacd" p: "abc"
Output:
[0, 6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
Input:
s: "abab" p: "ab"
Output:
[0, 1, 2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

Algo1: dict + sliding window, O(N*Letters), O(Letters)mem
- if n < p: return []
dict_p = char2count(p)
dict_s = char2count(s, 0, p)
- if nh == ph: indx.append(0)
for i in [1, n-p):
    dict_s.remove(s[i-1])
    dict_s.add(s[i+p-1])
    if dict_s == dict_p: indx.append(i)
- return idx
*/

class Solution {
public:
    vector<int> findAnagrams(string_view s, string_view p) {
        size_t n = s.size();
        size_t m = p.size();
        if (n < m || m == 0) return {};
        auto dict_p = calcCharCount(p);
        auto dict_s = calcCharCount(s.substr(0,m));
        vector<int> idx;
        if (dict_p == dict_s) idx.push_back(0);
        for (size_t i = 1; i <= n-m; ++i) {
            --dict_s[s[i-1]];
            if (dict_s[s[i-1]] == 0) dict_s.erase(s[i-1]);
            ++dict_s[s[i+m-1]];
            if (dict_p == dict_s) idx.push_back(i);
        }
        return idx;
    }
private:
    unordered_map<char, size_t> calcCharCount(string_view s) {
        unordered_map<char, size_t> res;
        for (auto c : s) {
            ++res[c];
        }
        return res;
    }
};
