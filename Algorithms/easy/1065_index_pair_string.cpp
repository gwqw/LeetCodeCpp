/**
    1065. Index Pairs of a String
Given a text string and words (a list of strings), return all index pairs [i, j] so that the substring text[i]...text[j] is in the list of words.

Example 1:
Input: text = "thestoryofleetcodeandme", words = ["story","fleet","leetcode"]
Output: [[3,7],[9,13],[10,17]]

Example 2:
Input: text = "ababa", words = ["aba","ab"]
Output: [[0,1],[0,2],[2,3],[2,4]]
Explanation: 
Notice that matches can overlap, see "aba" is found in [0,2] and [2,4].

Note:
All strings contains only lowercase English letters.
It's guaranteed that all strings in words are different.
1 <= text.length <= 100
1 <= words.length <= 20
1 <= words[i].length <= 50
Return the pairs [i,j] in sorted order (i.e. sort them by their first coordinate in case of ties sort them by their second coordinate).

Algo: O(N*W*WL) ~ 1e5
dict[size]->{words}
for i in range(s): O(N)
	for size in sizes: O(W)
		check if s.substr(i, size) in dict[size]: O(WL)
			res.push(i, i+s)
*/

class Solution {
public:
    vector<vector<int>> indexPairs(string_view text, const vector<string>& words) {
        auto dict = makeDict(words);
		vector<vector<int>> res;
		for (int i = 0; i < text.size(); ++i) {
			for (const auto& [size, words] : dict) {
				if (i + size > text.size()) continue;
				if (words.count(text.substr(i, size))) {
					res.push_back({i, i+size-1});
				}
			}
		}
		return res;
    }
	
private:
	map<int, unordered_set<string_view>> makeDict(const vector<string>& words) {
		map<int, unordered_set<string_view>> dict;
		for (const auto& w : words) {
			dict[(int)w.size()].insert(w);
		}
		return dict;
	}
};