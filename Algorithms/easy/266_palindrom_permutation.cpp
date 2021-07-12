/**
    266. Palindrome Permutation
Given a string s, return true if a permutation of the string could form a palindrome.

Example 1:
Input: s = "code"
Output: false

Example 2:
Input: s = "aab"
Output: true

Example 3:
Input: s = "carerac"
Output: true

Constraints:
1 <= s.length <= 5000
s consists of only lowercase English letters.

Algo: make dict, max 1 symbol has odd cnt
*/

class Solution {
public:
    bool canPermutePalindrome(string_view s) {
        unordered_map<char, int> dict;
        for (char c : s) {
            ++dict[c];
        }
        int odd_cnt = 0;
        for (auto [_, cnt] : dict) {
            if (cnt % 2 == 1) {
                ++odd_cnt;
                if (odd_cnt > 1) return false;
            }
        }
        return true;
    }
};