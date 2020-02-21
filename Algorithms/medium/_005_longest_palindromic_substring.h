/**
    5. Longest Palindromic Substring
Given a string s, find the longest palindromic substring in s. 
You may assume that the maximum length of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"

Algo: naive: brute-force: O(N^3)
- select all begins, all ends and check if it is palindrome

Algo2:
- for every idx has max palindrom ends here
- for next idx:
- check if adding left and right or only right make a greater palindrome:
    - update max palindrome
- else:
    - create new palindrome with l = 1
    
*/

class Solution {
public:
    string longestPalindrome(const string& s) {
        string_view sv(s);
        int n = (int)s.size();
        int mi = 0, mj = 0;
        for (int i = 0; i+1 < n; ++i) {
            for (int j = i+(mj-mi)+1; j < n; ++j) {
                if (isPalindrome(sv.substr(i, j-i+1))) {
                    if (j-i+1 > mj-mi+1) {
                        mi = i;
                        mj = j;
                    }
                }
            }
        }
        return s.substr(mi, mj-mi+1);
    }
private:
    bool isPalindrome(string_view sv) {
        if (sv.size() <= 1) return true;
        int n = (int)sv.size();
        for (int i = 0; i < n/2; ++i) {
            if (sv[i] != sv[n-1-i]) return false;
        }
        return true;
    }
};

class Solution {
public:
    string longestPalindrome(const string& s) {
        int n = (int)s.size();
        int l = 1;
        int mi = 0, ml = 1;
        bool el = true;
        for (int i = 1; i < n; ++i) {
            if (l == 1) {
                if (s[i] == s[i-1]) {
                    l = 2;
                    update(i, l, mi, ml);
                }
                if (i >= 2 && s[i] == s[i-2]) {
                    l = 3;
                    el = s[i] == s[i-1];
                    update(i, l, mi, ml);
                }
            } else if (i-l > 0 && s[i] == s[i-1-l]) {
                l += 2;
                if (el && s[i] != s[i-1]) el = false;
                update(i, l, mi, ml);
            } else if (el && s[i] == s[i-1]) {
                ++l;
                update(i, l, mi, ml);
            } else {
                l = 1;
                if (s[i] == s[i-1]) {
                    l = 2;
                    update(i, l, mi, ml);
                }
                if (i >= 2 && s[i] == s[i-2]) {
                    l = 3;
                    el = s[i] == s[i-1];
                    update(i, l, mi, ml);
                }
            }
        }
        return s.substr(mi-ml+1, ml); 
    }
    
private:
    void update(int i, int l, int& mi, int& ml) {
        if (l > ml) {
            ml = l;
            mi = i;
        }
    }
};

/*
"babad"
"cbbd"
"ccc"
"abcba"
"bananas"
*/
