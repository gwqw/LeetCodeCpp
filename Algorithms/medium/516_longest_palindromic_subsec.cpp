/**
    516. Longest Palindromic Subsequence
Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

Example 2:
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".

Constraints:
1 <= s.length <= 1000
s consists only of lowercase English letters.

Algo: dp: longest common subsequence for reverse string: O(N^2), O(N)mem
s2 = reverse string
dp[str1][str2] = len
*/

class Solution {
public:
    int longestPalindromeSubseq(string_view s1) {
		string s2(s1);
		reverse(s2.begin(), s2.end());
		vector<int> prev(s2.size()+1);
		for (size_t i = 1; i <= s1.size(); ++i) {
		    vector<int> cur(s2.size()+1);
		    for (size_t j = 1; j <= s2.size(); ++j) {
		        cur[j] = max(prev[j], cur[j-1]);
		        if (s1[i-1] == s2[j-1]) {
		            cur[j] = max(cur[j], prev[j-1]+1);
		        }
		    }
		    prev = move(cur);
		}
		return prev.back();
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string_view s1) {
		vector<int> prev(s1.size()+1);
		for (size_t i = 1; i <= s1.size(); ++i) {
		    vector<int> cur(s1.size()+1);
		    for (size_t j = 1; j <= s1.size(); ++j) {
		        cur[j] = max(prev[j], cur[j-1]);
		        if (s1[i-1] == s1[s1.size()-j]) {
		            cur[j] = max(cur[j], prev[j-1]+1);
		        }
		    }
		    prev = move(cur);
		}
		return prev.back();
    }
};
