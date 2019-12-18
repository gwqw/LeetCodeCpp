/**
    796. Rotate String

We are given two strings, A and B.
A shift on A consists of taking string A and moving the leftmost character to the rightmost position. 
For example, if A = 'abcde', then it will be 'bcdea' after one shift on A. 
Return True if and only if A can become B after some number of shifts on A.

Example 1:
Input: A = 'abcde', B = 'cdeab'
Output: true

Example 2:
Input: A = 'abcde', B = 'abced'
Output: false

Note:
A and B will have length at most 100.

Algo: O(N^2) + O(1)
- find start: sit1 = b1, sit2 = b2
    - while (sit2 != end() && *sit1 != sit2) ++sit2;
- check seq from start:
    - it1 = sit1, it2 = sit2
    - inc(it1), inc(it2) and check ==
    - if true: return true
    - else search start

Algo2: O(N^2) + O(N)
- check sizes
- return B in A+A

*/


class Solution {
public:
    bool rotateString(const string& s1, const string& s2) {
        if (s1.size() != s2.size()) return false;
        if (s1.empty()) return true;
        auto sit1 = s1.begin();
        auto sit2 = s2.begin();
        while (sit2 != s2.end()) {
            while (sit2 != s2.end() && *sit1 != *sit2) {
                ++sit2;
            }
            if (sit2 == s2.end()) return false;
            auto it1 = sit1;
            auto it2 = sit2;
            while (it1 != s1.end() && *it1 == *it2) {
                ++it1;
                ++it2;
                if (it2 == s2.end()) {
                    it2 = s2.begin();
                }
            }
            if (it1 == s1.end()) return true;
            ++sit2;
        }
        return false;
    }
};

class Solution {
public:
    bool rotateString(const string& s1, const string& s2) {
        if (s1.size() != s2.size()) return false;
        return (s1 + s1).find(s2) != s1.npos;
    }
};


