/**
    1143. Longest Common Subsequence
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

Constraints:
1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.

Algo1: dp2D: string1 vs string2: O(N^2), O(N^2) mem
dp[s1.size+1][s2.size+1]->length
dp[i][j] = max(dp[i-1][j], dp[i][j-1])
if s[i] == s[j]:
    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1)
    
Algo1: dp with reduced space
*/

class Solution {
public:
    int longestCommonSubsequence(string_view text1, string_view text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1));
        for (size_t i = 1; i <= text1.size(); ++i) {
            for (size_t j = 1; j <= text2.size(); ++j) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                }
            }
        }
        return dp.back().back();
    }
};

class Solution {
public:
    int longestCommonSubsequence(string_view text1, string_view text2) {
        vector<int> prev(text2.size()+1);
        for (size_t i = 1; i <= text1.size(); ++i) {
            vector<int> cur(text2.size()+1);
            for (size_t j = 1; j <= text2.size(); ++j) {
                cur[j] = max(prev[j], cur[j-1]);
                if (text1[i-1] == text2[j-1]) {
                    cur[j] = max(cur[j], prev[j-1] + 1);
                }
            }
            swap(cur, prev);
        }
        return prev.back();
    }
};