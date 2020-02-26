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

Algo1: use dict: O(N) + O(alphabet)
- if have diff sizes: return false

Algo2: sort: O(NlogN) + O(1..logN)
- we can change strings
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
class Solution {
public:
    bool isAnagram(const string& s, const string& t) {
        if (s.size() != t.size()) return false;
        
        array<int, 26> counter;
        fill(counter.begin(), counter.end(), 0);
        for (auto c : s) {
            ++counter[c - 'a'];
        }
        
        for (auto c : t) {
            if (counter[c - 'a'] == 0) return false;
            --counter[c - 'a'];
        }
        return true;
    }
};

class Solution {
public:
    bool isAnagram(string& s, string& t) {
        if (s.size() != t.size()) return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;
    }
};
