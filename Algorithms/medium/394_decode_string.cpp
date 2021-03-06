/**
    394. Decode String
Given an encoded string, return its decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:
Input: s = "3[a2[c]]"
Output: "accaccacc"

Example 3:
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

Example 4:
Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"

Constraints:
1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].

Algo: recursion O(N)
for c in s:
    if c not in '[]'+nums:
        res += c
    elif c in nums:
        n = read_num(pos(c))
    elif c == '[':
        res += substr(pos(c)+1)

Algo2:    

*/

class Solution {
public:
    string decodeString(const string& s) {
        size_t i = 0;
        return subStr(s, i);
    }
private:
    bool is_num(char c) {
        return '0' <= c && c <= '9';
    }
    
    int parse_num(const string& s, size_t& i) {
        int res = 0;
        for (; i < s.size() && is_num(s[i]); ++i) {
            int d = int(s[i]) - '0';
            res = res*10 + d;
        }
        return res;
    }
    
    string repeatStr(const string& s, int n) {
        string res;
        res.reserve(s.size() * n);
        for (int i = 0; i < n; ++i) {
            res += s;
        }
        return res;
    }
    
    string subStr(const string& s, size_t& i) {
        int n = 0;
        string res;
        while (i < s.size() && s[i] != ']') {
            char c = s[i];
            if (is_num(c)) {
                n = parse_num(s, i);
            } else if (c == '[') {
                ++i;
                res += repeatStr(subStr(s, i), n);
                if (i != s.size()) ++i;
            } else {
                res += c;
                ++i;
            }
        }
        return res;
    }
};



