/**
    1048. Longest String Chain
You are given an array of words where each word consists of lowercase English letters.
wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.
For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.
Return the length of the longest possible word chain with words chosen from the given list of words.

Example 1:
Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

Example 2:
Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].

Example 3:
Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.

Constraints:
1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of lowercase English letters.

Algo: dp like LIS:
dp[idx] -> len of LSC, ending here
dp[0] = 1
for i in range(1,n):
    dp[i] = 0
    for j in range 0, i:
        if pred(w[j], w[i]):
            dp[i] = max(dp[i], dp[j]+1)
return dp.back()
*/

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<int> dp(words.size(), 1);
        sort(words.begin(), words.end(), 
            [](const auto& lhs, const auto& rhs){
                return lhs.size() < rhs.size();
            }
        );
        int max_length = 1;
        for (size_t i = 1; i < words.size(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (isPred(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            max_length = max(max_length, dp[i]);
        }
        return max_length;
    }
private:
    bool isPred(string_view sub, string_view s) {
        if (sub.size()+1 != s.size()) return false;
        size_t i = 0;
        size_t j = 0;
        int fail_cnt = 0;
        while (i < sub.size() && j < s.size()) {
            if (sub[i] != s[j]) {
                if (fail_cnt == 1) return false;
                ++fail_cnt;
                ++j;
            } else {
                ++i;
                ++j;
            }
        }
        return true;
    }
};