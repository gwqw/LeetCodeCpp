/**
    647. Palindromic Substrings
Given a string, your task is to count how many palindromic substrings in this string.
The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Note:
The input string length won't exceed 1000.

Algo: dp O(N^2) + O(N^2)
- if empty => 0
- ct table bool* [size-1][size] fill with false
- init fill:
    - for f:
    - len() == 1 => true:
        t[f][f] = true
    - len() == 2 => s[f] == s[l]
        - t[f][f+1] = s[f] == s[f+1]
- next:
    - for f:
        - for l = f+2:
            - isPalindrom =
                (isPalindrom[f+1][l-1]) &&
                (s[f] == s[l])
- count:
    for f:
        for l = f:
            if isPalindrom[f][l]: ++count

tests:
    abc
    
Algo2: go from middle
- for each center as c in size:
    - start checkIsPalindromExpand(c, c)   # if palindrom has odd size
    - start checkIsPalindromExpand(c, c+1) # if palindrom has even size
checkIsPalindromExpand(f, l):
    while (f>=0 && l < size && s[f] == s[l]):
        ++cnt
        --f
        ++l
    return cnt

*/

//84
class Solution {
public:
    int countSubstrings(const string& s) {
        if (s.empty()) return 0;
        if (s.size() == 1) return 1;
        // init
        vector<vector<bool>> isPalindrom(s.size(), vector<bool>(s.size(), false));
        for (size_t f = 0; f < s.size(); ++f) {
            isPalindrom[f][f] = true;
            if (f+1 < s.size()) {
                isPalindrom[f][f+1] = s[f] == s[f+1];
            }
        }
        // fill
        for (size_t len = 3; len <= s.size(); ++len) {
            for (size_t f = 0; f+len-1 < s.size(); ++f) {
                isPalindrom[f][f+len-1] = isPalindrom[f+1][f+len-2] && s[f] == s[f+len-1];
            }
        }
        // count
        int res = 0;
        for (size_t f = 0; f < s.size(); ++f) {
            for (size_t l = f; l < s.size(); ++l) {
                if (isPalindrom[f][l]) ++res;
            }
        }
        return res;
    }
};
//48ms
class Solution {
public:
    int countSubstrings(const string& s) {
        if (s.empty()) return 0;
        if (s.size() == 1) return 1;
        // init
        int res = s.size();
        vector<vector<bool>> isPalindrom(s.size(), vector<bool>(s.size(), false));
        for (size_t f = 0; f < s.size(); ++f) {
            isPalindrom[f][f] = true;
            if (f+1 < s.size() && s[f] == s[f+1]) {
                isPalindrom[f][f+1] = true;
                ++res;
            }
        }
        // fill
        for (size_t len = 3; len <= s.size(); ++len) {
            for (size_t f = 0; f+len-1 < s.size(); ++f) {
                if (isPalindrom[f+1][f+len-2] && s[f] == s[f+len-1]) {
                    isPalindrom[f][f+len-1] = true;
                    ++res;
                }
            }
        }
        return res;
    }
};
// 16ms
class Solution {
public:
    int countSubstrings(const string& s) {
        if (s.empty()) return 0;
        if (s.size() == 1) return 1;
        // init
        int res = s.size();
        vector<vector<char>> isPalindrom(s.size(), vector<char>(s.size(), 0));
        for (size_t f = 0; f < s.size(); ++f) {
            isPalindrom[f][f] = 1;
            if (f+1 < s.size() && s[f] == s[f+1]) {
                isPalindrom[f][f+1] = 1;
                ++res;
            }
        }
        // fill
        for (size_t len = 3; len <= s.size(); ++len) {
            for (size_t f = 0; f+len-1 < s.size(); ++f) {
                if (isPalindrom[f+1][f+len-2] && s[f] == s[f+len-1]) {
                    isPalindrom[f][f+len-1] = 1;
                    ++res;
                }
            }
        }
        return res;
    }
};

// aba

class Solution {
    
    void checkIsPalindromExpand(string_view s, size_t f, size_t l, int& cnt) {
        while (l < s.size() && s[f] == s[l]) {
            ++cnt;
            if (f == 0) return;
            --f;
            ++l;
        }
    }
    
public:
    int countSubstrings(string_view s) {
        int cnt = 0;
        for (size_t c = 0; c < s.size(); ++c) {
            checkIsPalindromExpand(s, c, c, cnt);
            if (c < s.size()) {
                checkIsPalindromExpand(s, c, c+1, cnt);
            }
        }
        return cnt;
    }
};


