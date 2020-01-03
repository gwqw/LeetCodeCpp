/**
    409. Longest Palindrome

Given a string which consists of lowercase or uppercase letters, 
find the length of the longest palindromes that can be built with those letters.
This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:
Input:
"abccccdd"
Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

palindrome:
if we have pali and pair letter aa, we can add them from right and left
apalia
if we don't have single letter we can insert it in center

Algo1: use dict O(N) + O(L) L -- letters
- go through string and insert in dict: letter -> count
- have bool flag if we already added one symbol
- go through dict and add count % 2 ==0 || !added ? count : count-1 to res

Algo2: sort and go through string: O(NlogN) + O(1)
- sort string 
- go through string:
    v1 == next(v) (if has next): 
        res += 2
        inc it;
    else if (is_need):
        ++res
        is_need = false
    
*/

class Solution {
public:
    int longestPalindrome(const string& s) {
        if (s.empty()) return 0;
        unordered_map<char, int> d;
        for (auto c : s) {
            ++d[c];
        }
        bool need_add = true;
        int res = 0;
        for (auto [ch, count] : d) {
            if (count % 2 == 0) {
                res += count;
            } else if (need_add) {
                res += count;
                need_add = false;
            } else {
                res += count - 1;
            }
        }
        return res;
    }
};
class Solution {
public:
    int longestPalindrome(const string& s) {
        if (s.empty()) return 0;
        array<int, 128> a;
        fill(a.begin(), a.end(), 0);
        for (auto c : s) {
            ++a[c];
        }
        bool need_add = true;
        int res = 0;
        for (auto count : a) {
            if (!count) continue;
            if (count % 2 == 0) {
                res += count;
            } else if (need_add) {
                res += count;
                need_add = false;
            } else {
                res += count - 1;
            }
        }
        return res;
    }
};

class Solution {
public:
    int longestPalindrome(string s) {
        if (s.empty()) return 0;
        sort(s.begin(), s.end());
        bool needed = true;
        int res = 0;
        for (auto it = s.begin(); it != s.end(); ++it) {
            if (next(it) != s.end() && *it == *next(it)) {
                res += 2;
                ++it;
            } else if (needed) {
                ++res;
                needed = false;
            }
        }        
        return res;
    }
};

/*
abccccdd
a - 1
b - 1
c - 4
d - 2
1 + 4 + 2 = 7

1 + 2 + 2 + 2 = 7
*/
