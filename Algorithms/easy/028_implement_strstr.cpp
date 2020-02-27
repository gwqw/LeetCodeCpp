/**
28. Implement strStr()
Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

Clarification:
What should we return when needle is an empty string?
This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string.
This is consistent to C's strstr() and Java's indexOf().
*/

/**
Algo:
s1, s2
if s1.empty() || s2.size() > s1.size() return -1
if s2.empty(): return 0

for i (0, s1.size() - s2.size() + 1):
  res = true
  for j=0 to s2.size():
    if s1[i+j] != s2[j]:
      res = false
      break
  if res:
    return i
return false
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
      if (needle.empty()) return 0;
      if (haystack.empty() || needle.size() > haystack.size()) return -1;      
      
      for (int i = 0; i < haystack.size() - needle.size() + 1; ++i) {
        bool res = true;
        for (int j = 0; j < needle.size(); ++j) {
          if (haystack[i+j] != needle[j]) {
            res = false;
            break;
          }
        }
        if (res) {
          return i;
        }
      }
      
      return -1;
    }
};
