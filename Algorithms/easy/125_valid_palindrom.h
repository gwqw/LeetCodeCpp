/**
    125. Valid Palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:
Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:
Input: "race a car"
Output: false

simple_tests: a, aa, aba, ab

Algo1: naive O(N) + O(N)
- create new string with only letters and to lower case
- compare first part with second

Algo2: 2terators(reverse order): O(N) + O(1)
- we have 2 iterators: b and e
- go through string while !letter: ++b and --e
- if b >= e: return true
- if !cmp(b, e) return true
- ++b --e
*/


#pragma once

//Algo1: naive
class Solution {
    static bool is_letter(char c) { // isalnum can be used, but isalnum((unsigned char)c)
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9');
    }
public:
    bool isPalindrome(const string& s) {
        string res;
        res.reserve(s.size());
        for (auto c : s) {
            if (!is_letter(c)) continue;
            res += tolower((unsigned char)c);
        }
        
        size_t n = res.size();
        for (size_t i = 0; i < n / 2; ++i) {
            if (res[i] != res[n-1-i]) return false;
        }
        return true;
    }
};

class Solution {
    static bool is_letter(char c) {
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9');
    }
    
    static bool cmp(char lhs, char rhs) { // isalnum can be used, but isalnum((unsigned char)c)
        return tolower((unsigned char)lhs) == tolower((unsigned char)rhs);
    }
public:
    bool isPalindrome(const string& s) {
        if (s.size() <= 1) return true;
        size_t b = 0;
        size_t e = s.size()-1;
        while (true) {
            while (b < e && !is_letter(s[b])) ++b;
            if (b >= e) return true;
            while (b < e && !is_letter(s[e])) --e;
            if (b >= e) return true;
            if (!cmp(s[b], s[e])) return false;
            ++b;
            --e;
        }
        return true;
    }
};



