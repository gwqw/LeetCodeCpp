/**
    692. Top K Frequent Words
Given a non-empty list of words, return the k most frequent elements.
Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.

Algo: counter (dict) and partial sort with lambda
*/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> dict;
        vector<string> res;
        res.reserve(words.size());
		for (const auto& word : words) {
		    if (!dict.count(word)) res.push_back(word);
			++dict[word];
		}
		
		partial_sort(res.begin(), res.begin() + k, res.end(), 
			[&dict](const auto& lhs, const auto& rhs){
				return dict[lhs] > dict[rhs] || 
					(dict[lhs] == dict[rhs] && lhs < rhs);
			}
		);
		return {res.begin(), res.begin() + k};
    }
};
