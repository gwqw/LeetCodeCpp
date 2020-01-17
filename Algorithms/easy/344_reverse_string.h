/**
    344. Reverse String
Write a function that reverses a string. 
The input string is given as an array of characters char[].
Do not allocate extra space for another array, 
you must do this by modifying the input array in-place with O(1) extra memory.
You may assume all the characters consist of printable ascii characters.

Example 1:
Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

Algo: O(N) + O(1)
- go through string with 2 iterators and swap elements

*/

// size_t
class Solution {
public:
    void reverseString(vector<char>& s) {
        size_t n = s.size();
        for (size_t i = 0; i < n / 2; ++i) {
            swap(s[i], s[n-1-i]);
        }
    }
};

// int
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = (int)s.size();
        for (int i = 0; i < n / 2; ++i) {
            swap(s[i], s[n-1-i]);
        }
    }
};

// iterator
class Solution {
public:
    void reverseString(vector<char>& s) {
        size_t n = s.size();
        auto m = s.begin() + n/2;
        auto rit = s.end();
        for (auto it = s.begin(); it != m; ++it) {
            --rit;
            swap(*it, *rit);
        }
    }
};



