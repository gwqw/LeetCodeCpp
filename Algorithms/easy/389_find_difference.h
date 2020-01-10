/**
    389. Find the Difference
Given two strings s and t which consist of only lowercase letters.
String t is generated by random shuffling string s and then add one more letter at a random position.
Find the letter that was added in t.

Example:
Input:
s = "abcd"
t = "abcde"
Output:
e

Explanation:
'e' is the letter that was added.

Algo1: use dict(map, un_map or vector(26)): O(N) + O(1) // because size(alphabet) = 26
- go through 2-nd string and make a dict: k = char, v = cnt
- go through 1-st string and decrease values from dict

Algo2: xor or sum all: O(N) + O(1)
*/

// unordered_map
class Solution {
public:
    char findTheDifference(const string& s, const string& t) {
        unordered_map<char, int> dict;
        for (auto c : s) {
            ++dict[c];
        }
        for (auto c : t) {
            if (auto it = dict.find(c); it != dict.end()) {
                if (it->second == 0) return c;
                --(it->second);
            } else {
                return c;
            }
        }
        assert(false);
        return '0';
    }
};

// map: faster than unordered_map
class Solution {
public:
    char findTheDifference(const string& s, const string& t) {
        map<char, int> dict;
        for (auto c : s) {
            ++dict[c];
        }
        for (auto c : t) {
            if (auto it = dict.find(c); it != dict.end()) {
                if (it->second == 0) return c;
                --(it->second);
            } else {
                return c;
            }
        }
        assert(false);
        return '0';
    }
};

// vector
class Solution {
public:
    char findTheDifference(const string& s, const string& t) {
        vector<int> dict(26, 0);
        for (auto c : s) {
            ++dict[c - 'a'];
        }
        for (auto c : t) {
            int idx = c - 'a';
            if (dict[idx] > 0) {
                --dict[idx];
            } else {
                return c;
            }
        }
        assert(false);
        return '0';
    }
};

class Solution {
public:
    char findTheDifference(const string& s, const string& t) {
        unsigned char res = 0;
        for (auto c : s) {
            res ^= c;
        }
        for (auto c : t) {
            res ^= c;
        }
        return static_cast<char>(res);
    }
};










