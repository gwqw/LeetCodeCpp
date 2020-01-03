/**
    844. Backspace String Compare
Given two strings S and T, return if they are equal when both are typed into empty text editors. 
# means a backspace character.

Example 1:
Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".

Example 2:
Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".

Example 3:
Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".

Example 4:
Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".

Note:
1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.

Follow up:
Can you solve it in O(N) time and O(1) space?

Algo: O(N) + O(1)
- go from the end:
    go while symb is not significant --i, --j
        if (s[i] != t[j]) return false

Algo: naive O(N) + O(N)
- 2 commands: add symbol and delete symbol

*/

class Solution {
public:
    bool backspaceCompare(const string& s, const string& t) {
        auto i = s.rbegin();
        auto j = t.rbegin();
        size_t sbc = 0, tbc = 0;
        while (i != s.rend() || j != t.rend()) {
            while (i != s.rend() && (*i == '#' || sbc != 0))  {
                if (*i == '#') {
                    ++sbc;
                } else {
                    --sbc;
                }
                ++i;
            }
            while (j != t.rend() && (*j == '#' || tbc != 0))  {
                if (*j == '#') {
                    ++tbc;
                } else {
                    --tbc;
                }
                ++j;
            }
            if ((i == s.rend() && j != t.rend()) || (i != s.rend() && j == t.rend())) {
                return false;
            }
            if (i != s.rend() && j != t.rend()) {
                if (*i != *j) return false;
                ++i;
                ++j;
            }
        }
        return true;
    }
};




