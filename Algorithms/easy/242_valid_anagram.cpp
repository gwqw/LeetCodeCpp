/**
    242. Valid Anagram
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? 
How would you adapt your solution to such case?
*/

class Solution {
public:
    bool isAnagram(const string& s, const string& t) {
        if (s.size() != t.size()) return false;
        
        unordered_map<char, int> counter;
        for (auto c : s) {
            ++counter[c];
        }
        
        for (auto c : t) {
            if (!counter.count(c) || counter[c] == 0) return false;
            --counter[c];
        }
        return true;
    }
};

