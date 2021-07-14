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
- for l in length:
	for i in 0, n-l:
		j = i+l
		mtx[i, j] = mtx[i+1, j-1] and a[i] == a[j]
	update(max_length)

Algo3: 2 pointers, go from center: O(N^2)
for i in n:
    check if palindrome with center in i
    check if palindrome with center in i, i+1
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

class Solution {
public:
    string longestPalindrome(string_view s) {
        if (s.size() <= 1) return string(s);
        size_t n = s.size();
        int max_length = 1;
        size_t from = 0;
        for (size_t i = 0; i+1 < s.size(); ++i) {
            // check is pali with center in i
            findPalindrome(s, i, i, max_length, from);
            // check is pali with center in i, i+1
            if (s[i] == s[i+1]) {
                findPalindrome(s, i, i+1, max_length, from);
            }
        }
        return string(s.substr(from, max_length));
    }
    
private:
    void findPalindrome(string_view s, size_t l, size_t r, int& max_length, size_t& from) {
        while (l > 0 && r+1 < s.size()) {
            if (s[l-1] != s[r+1]) break;
            --l;
            ++r;
        }
        if (r-l+1 > max_length) {
            max_length = r-l+1;
            from = l;
        }
    }
};

