/**
    1209. Remove All Adjacent Duplicates in String II
You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

Example 1:
Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.

Example 2:
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"

Example 3:
Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"

Constraints:
1 <= s.length <= 10^5
2 <= k <= 10^4
s only contains lower case English letters.

Algo1: stack or vector
for letter check if last k-1 same: remove k-1 and continue

Algo2: vector [{c, cnt}]
*/

class Solution {
public:
    string removeDuplicates(string_view s, int k) {
        string res;
        res.reserve(s.size());
        for (char c : s) {
            if (res.size() >= k-1 && hasSameChar(res, c, k-1)) {
                res.resize(res.size()-k+1);
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
    
private:
    bool hasSameChar(string_view s, char c, int k) {
        bool is_same = true;
        for (size_t i = s.size()-k; i < s.size(); ++i) {
            if (s[i] != c) {
                is_same = false;
                break;
            }
        }
        return is_same;
    }
};


class Solution {
public:
    string removeDuplicates(string_view s, int k) {
        vector<pair<char, int>> res;
        res.reserve(s.size());
        for (char c : s) {
            if (!res.empty() && res.back().first == c && res.back().second == k-1) {
                res.pop_back();
            } else if (!res.empty() && res.back().first == c) {
                ++res.back().second;
            } else {
                res.push_back({c, 1});
            }
        }
        string res_str;
        res_str.reserve(s.size());
        for (auto [c, cnt] : res) {
            res_str += string(c, cnt);
        }
        return res_str;
    }    
};
