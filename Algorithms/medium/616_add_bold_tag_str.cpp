/**
    616. Add Bold Tag in String
You are given a string s and an array of strings words. You should add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in words. If two such substrings overlap, you should wrap them together with only one pair of closed bold-tag. If two substrings wrapped by bold tags are consecutive, you should combine them.

Return s after adding the bold tags.

Example 1:
Input: s = "abcxyz123", words = ["abc","123"]
Output: "<b>abc</b>xyz<b>123</b>"

Example 2:
Input: s = "aaabbcc", words = ["aaa","aab","bc"]
Output: "<b>aaabbc</b>c"

Constraints:
1 <= s.length <= 1000
0 <= words.length <= 100
1 <= words[i].length <= 1000
s and words[i] consist of English letters and digits.
All the values of words are unique.

Note: This question is the same as 758: https://leetcode.com/problems/bold-words-in-string/

Algo:
for all words find all position and make intervals
sort intervals
combine intervals
fill string with tags
*/

class Solution {
public:
    string addBoldTag(string_view s, const vector<string>& words) {
        vector<pair<int, int>> intervals;
        for (const auto& word : words) {
            for (auto sit = search(s.begin(), s.end(), word.begin(), word.end()); 
                sit != s.end();
                sit = search(++sit, s.end(), word.begin(), word.end())
            ) {
                intervals.push_back(
                    {int(sit - s.begin()), int(sit - s.begin()) + (int)word.size()}
                );
            }
        }
        sort(intervals.begin(), intervals.end());
        merge(intervals);
        //printIntervals(intervals);
        if (intervals.empty()) return string(s);
        
        string res;
        res.reserve(s.size() + intervals.size()*7);
        size_t int_idx = 0;
        for (size_t i = 0; i < s.size(); ) {
            if (int_idx == intervals.size() || i < intervals[int_idx].first) {
                res += s[i++];
            } else {
                res += "<b>";
                while (i < intervals[int_idx].second) {
                    res += s[i++];
                }
                res += "</b>";
                ++int_idx;
            }
        }        
        
        return res;
    }
    
private:
    void merge(vector<pair<int, int>>& intervals) {
        vector<pair<int, int>> newintervals;
        newintervals.reserve(intervals.size());
        for (size_t i = 0; i < intervals.size(); ) {
            auto [l,r] = intervals[i];
            size_t j = i+1;
            while (j < intervals.size() && r >= intervals[j].first) {
                r = max(r, intervals[j++].second);
            }
            newintervals.push_back({l, r});
            i = j;
        }
        intervals = move(newintervals);
    }

    void printIntervals(const vector<pair<int, int>>& intervals) {
        for (auto [start, end] : intervals) {
            cout << start << " -> " << end << '\n';
        }
    }
};