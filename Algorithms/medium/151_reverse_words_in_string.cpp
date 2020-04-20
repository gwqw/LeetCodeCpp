/**
    151. Reverse Words in a String
Given an input string, reverse the string word by word.

Example 1:
Input: "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

Note:
A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.

Follow up:
For C programmers, try to solve it in-place in O(1) extra space.

Algo1: not in-place
- i = s.size()
- was_space = false
- go through string from behind:
    - if char == ' ':
        if j+1 != i or s[j] == ' ' && !was_space:
            s[j..i) -> ans
            if j+1 == i && s[j] == ' ':
                was_space == true
            else:
                was_space == false
        i = j
- s[0..i) -> ans
        
Algo2: reverse string + reverse each word

*/

class Solution {
public:
    string reverseWords(const string& s) {
        if (s.empty()) return s;
        size_t i = s.size();
        string ans;
        bool is_first = true;
        for (size_t j = s.size(); j-->0; ) {
            if (s[j] == ' ') {
                if (j+1 < i) {
                    if (is_first) {
                        is_first = false;
                    } else {
                        ans.push_back(' ');
                    }
                    ans += s.substr(j+1, i-j-1);
                }
                i = j;
            }
        }
        if (0 < i) {
            if (is_first) {
                is_first = false;
            } else {
                ans.push_back(' ');
            }
            ans += s.substr(0, i);
        }
        return ans;
    }
};
