/**
    340. Longest Substring with At Most K Distinct Characters
Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.

Example 1:
Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with length 3.

Example 2:
Input: s = "aa", k = 1
Output: 2
Explanation: The substring is "aa" with length 2.

Constraints:
1 <= s.length <= 5 * 10^4
0 <= k <= 50

Algo: sliding window with dict
make dict window size 1
while dict.size <= k:
	move right
	update max_length
while dict.size > k:
	move left
*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string_view s, int k) {
		if (k == 0) return 0;
        unordered_map<char, int> dict;
		size_t l = 0;
		size_t r = 0;
		int max_length = 0;
		while (r < s.size()) {
			++dict[s[r++]];
			while (l < r && dict.size() > k) {
				--dict[s[l]];
				if (dict[s[l]] == 0) {
					dict.erase(s[l]);
				}
				++l;
			}
			max_length = max(max_length, int(r-l));
		}
		return max_length;
    }
};