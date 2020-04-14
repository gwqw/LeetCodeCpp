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

Algo2: dp: O(N^2) + O(N^2)
- make matrix is_palindrom[start][end]
- find longest

Algo3: go from center: O(N^2)
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
        if (s.size() <= 1) return s;
        size_t n = s.size();
        vector<vector<char>> is_palindrom(n, vector<char>(n, 1));
        size_t max_length = 1;
        pair<size_t, size_t> max_ilen{0,1};
        for (size_t i = 0; i+1 < n; ++i) {
            is_palindrom[i][i+1] = s[i] == s[i+1] ? : 0;
            if (is_palindrom[i][i+1] && max_length < 2) {
                max_length = 2;
                max_ilen = {i,2};
            }
        }
        
        for (size_t length = 3; length <= n; ++length) {
            for (size_t i = 0; i+length <= n; ++i) {
                size_t j = i+length-1;
                is_palindrom[i][j] = is_palindrom[i+1][j-1] 
                    && (s[i] == s[j]);
                if (is_palindrom[i][j] && length > max_length) {
                    max_length = length;
                    max_ilen = {i,length};
                }
            }
        }

        auto [i,l] = max_ilen;
        return s.substr(i, l);
    }
};

/*
"babad"
"cbbd"
"ccc"
"abcba"
"bananas"
*/
