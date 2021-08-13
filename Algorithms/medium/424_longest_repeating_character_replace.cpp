/**
    424. Longest Repeating Character Replacement
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.

Constraints:
1 <= s.length <= 10^5
s consists of only uppercase English letters.
0 <= k <= s.length

Algo: sliding window + set
l = 0, r = 0
c = s[l]
cnt = 0
while r < s.size():
	++dict[s[r]]
	++r
	if s[r] != s[l]: 
		++cnt
	while l < r && cnt > k:
		--dict[l]
		cnt += dict[l]
		++l
		cnt -= dict[l]
	max = max(max, r-l)
abbab
 ^  ^
ba
*/

class Solution {
public:
    int characterReplacement(string_view s, int k) {
        int l = 0, r = 0;
		int cnt = 0;
		int max_cnt = 0;
		unordered_map<char, int> dict;
		while (r < s.size()) {
			++dict[s[r]];
			if (s[r] != s[l]) ++cnt;
			++r;
			while (l < r && cnt > k) {
				--dict[s[l]];
				cnt += dict[s[l++]];
				cnt -= dict[s[l]];
			}
			max_cnt = max(max_cnt, r-l);
		}
		if (cnt < k) {
            int cur = min(r - l + k-cnt, (int)s.size());
            max_cnt = max(max_cnt, cur);
        }
		return max_cnt;
    }
};

