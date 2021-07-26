/**
    1180. Count Substrings with Only One Distinct Letter
Given a string s, return the number of substrings that have only one distinct letter.

Example 1:
Input: s = "aaaba"
Output: 8
Explanation: The substrings with one distinct letter are "aaa", "aa", "a", "b".
"aaa" occurs 1 time.
"aa" occurs 2 times.
"a" occurs 4 times.
"b" occurs 1 time.
So the answer is 1 + 2 + 4 + 1 = 8.

Example 2:
Input: s = "aaaaaaaaaa"
Output: 55

Constraints:
1 <= s.length <= 1000
s[i] consists of only lowercase English letters.

Algo: 
for c in s:
    if c == prev:
        ++cnt
    else:
        res += cnt * (cnt+1) / n
return res
*/

class Solution {
public:
    int countLetters(string_view s) {
        int cnt = 1;
        char prev = s[0];
        int res = 1;
        for (size_t i = 1; i < s.size(); ++i) {
            char c = s[i];
            if (c == prev) {
                ++cnt;
            } else {
                cnt = 1;
                prev = c;
            }
            res += cnt;
        }
        return res;
    }
};
