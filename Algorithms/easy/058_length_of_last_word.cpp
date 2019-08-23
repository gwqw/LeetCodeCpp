/**
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:
Input: "Hello World"
Output: 5

algo:
length = 0
for rbegin(s):
  if c != ' ': ++length
return length
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
      int length = 0;
      for (auto it = rbegin(s); it != rend(s); ++it) {
        if (*it != ' ') {
          ++length;
        } else if (length) {
          break;
        }
      }
      return length;
    }
};
