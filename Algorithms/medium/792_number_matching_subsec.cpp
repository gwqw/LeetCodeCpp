/**
    792. Number of Matching Subsequences
Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".

Example 1:
Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".

Example 2:
Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2

Constraints:
1 <= s.length <= 5 * 10^4
1 <= words.length <= 5000
1 <= words[i].length <= 50
s and words[i] consist of only lowercase English letters.

Algo: naive check if subsec with 2 iterators

Algo: binary search next index: O(N + M*logN*W), where N -- s length, M -- words size, W -- word size
dict[c]->[idxes]
check for w:
    idx = 0
    for c in w:
        if !dict.count(c): break
        v = dict[c]
        it = upper_bound(v, idx)
        if it == v.end(): break
        idx = *it
    return true
*/

class Solution {
public:
    int numMatchingSubseq(string_view s, const vector<string>& words) {
        unordered_map<char, vector<size_t>> dict;
        for (size_t i = 0; i < s.size(); ++i) {
            dict[s[i]].push_back(i);
        }
        int cnt = 0;
        for (string_view w : words) {
            char c = w[0];
            if (!dict.count(c)) continue;
            size_t i = dict[c].front();
            bool is_found = true;
            for (size_t j = 1; j < w.size(); ++j) {
                char c = w[j];
                if (!dict.count(c)) {
                    is_found = false;
                    break;
                }
                const auto& v = dict[c];
                auto it = upper_bound(v.begin(), v.end(), i);
                if (it == v.end()) {
                    is_found = false;
                    break;
                }
                i = *it;
            }
            if (is_found) ++cnt;          
        }
        return cnt;
    }
};