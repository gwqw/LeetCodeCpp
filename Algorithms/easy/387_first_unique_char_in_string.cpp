/**
    387. First Unique Character in a String
Given a string, find the first non-repeating character in it and return it's index.
If it doesn't exist, return -1.

Examples:
s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.

Algo1: dict: O(N) + O(min(N, dict_size))
- make dict: letter -> count
- go through string check 
    - if dict[letter] == 1: return pos
- return -1
*/

//36ms
class Solution {
public:
    int firstUniqChar(const string& s) {
        unordered_map<char, int> dict;
        for (auto c : s) {
            ++dict[c];
        }
        for (int i = 0; i < (int)s.size(); ++i) {
            if (dict[s[i]] == 1) return i;            
        }
        return -1;
    }
};
//4ms
class Solution {
public:
    int firstUniqChar(const string& s) {
        constexpr int ENG_DICT_SIZE = 26;
        array<int, ENG_DICT_SIZE> dict{0};
        fill(dict.begin(), dict.end(), 0);
        for (auto c : s) {
            ++dict[c - 'a'];
        }
        for (int i = 0; i < (int)s.size(); ++i) {
            if (dict[s[i]-'a'] == 1) return i;            
        }
        return -1;
    }
};

