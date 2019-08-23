/**
14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/


// O(k)O(N)
class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
      if (strs.empty()) return "";
      int min_size = strs[0].size();
      for (const auto& str : strs) {
          if (min_size > str.size()) {min_size = str.size();}
      }
      string lcp;
      for(int i = 0; i < min_size; ++i) {
          char c = strs[0][i];
          for(int j = 1; j < strs.size(); ++j) {
              if (c != strs[j][i]) return lcp;
          }
          lcp += c;
      }
      return lcp;
  }
};