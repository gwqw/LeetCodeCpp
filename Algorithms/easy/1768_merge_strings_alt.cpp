/**
    1768. Merge Strings Alternately
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
Return the merged string.

Example 1:
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r

Example 2:
Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
 
Constraints:
1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.

Algo: zig-zag iterator use queue or is_first
if word1.empty() and word2.empty(): return ""
is_first = not word1.empty()
i = 0
j = 0
while i < w1.size() or j < w2.size():
	if is_first:
		res += w1[i++]
		if_first = j == w2.size()
	else:
		res += w2[j++]
		is_first = i < w1.size()
return res
*/

class Solution {
public:
    string mergeAlternately(string_view w1, string_view w2) {
        if (w1.empty() && w2.empty()) return "";
		bool is_first = !w1.empty();
		size_t i = 0, j = 0;
		string res;
		res.reserve(w1.size() + w2.size());
		while (i < w1.size() || j < w2.size()) {
			if (is_first) {
				res += w1[i++];
				is_first = j == w2.size();
			} else {
				res += w2[j++];
				is_first = i < w1.size();
			}
		}
		return res;
    }
};