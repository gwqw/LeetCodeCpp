/**
    680. Valid Palindrome II

Given a non-empty string s, you may delete at most one character. 
Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True

Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.

Note:
The string will only contain lowercase characters a-z. 
The maximum length of the string is 50000.

Algo: 2iterators: O(N) + O(1)
- 2 iterators: go from left and from right
- if l >= r: return true
- if l != r:
    - check l+1, r is palindrome
    - check l, r-1 is palindrome    
*/

class Solution {
public:
    bool validPalindrome(const string& s) {
        if (s.size() <= 2) return true;
        size_t l = 0;
        size_t r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                string_view sv(s);
                return isPalindrome(sv.substr(l, r - l)) || 
                       isPalindrome(sv.substr(l+1, r - l)); 
            }
            ++l;
            --r;
        }
        return true;
    }
private:
    bool isPalindrome(string_view s) {
        auto n = s.size();
        for (size_t i = 0; i < n / 2; ++i) {
            if (s[i] != s[n-1 - i]) return false;
        }
        return true;
    }
};

// with int
class Solution {
public:
    bool validPalindrome(const string& s) {
        if (s.size() <= 2) return true;
        int l = 0;
        int r = (int)s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                string_view sv(s);
                return isPalindrome(sv.substr(l, r - l)) || 
                       isPalindrome(sv.substr(l+1, r - l)); 
            }
            ++l;
            --r;
        }
        return true;
    }
private:
    bool isPalindrome(string_view s) {
        int n = (int)s.size();
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] != s[n-1 - i]) return false;
        }
        return true;
    }
};

/*
"aba"
"abc"
"aab"
"abca"
"aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga"
"aguokepatgbnvfqmgmlucupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuclmgmqfvnbgtapekouga"
*/


