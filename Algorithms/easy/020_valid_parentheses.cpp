/**
20. Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true

Algo: use stack
*/

class Solution {
public:
  bool isValid(string s) {
    enum class BR {round, square, fig};
    vector<BR> st;    
    st.reserve(s.size());
    for (auto ch : s) {
      if (ch == '(') {
        st.push_back(BR::round);
      } else if (ch == '[') {
        st.push_back(BR::square);
      } else if (ch == '{') {
        st.push_back(BR::fig);
      } else if (ch == ')') {
        if (!st.empty() && st.back() == BR::round) {
          st.pop_back();
        } else {return false;}
      } else if (ch == ']') {
        if (!st.empty() && st.back() == BR::square) {
          st.pop_back();
        } else {return false;}
      } else if (ch == '}') {
        if (!st.empty() && st.back() == BR::fig) {
          st.pop_back();
        } else {return false;}
      }      
    }
    return st.empty();
  }
};
