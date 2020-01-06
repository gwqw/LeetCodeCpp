/**
    925. Long Pressed Name
Your friend is typing his name into a keyboard.
Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.
You examine the typed characters of the keyboard.
Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

Example 1:
Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.

Example 2:
Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.

Example 3:
Input: name = "leelee", typed = "lleeelee"
Output: true

Example 4:
Input: name = "laiden", typed = "laiden"
Output: true
Explanation: It's not necessary to long press any character.

Note:
name.length <= 1000
typed.length <= 1000
The characters of name and typed are lowercase letters.


Algo: O(N1 + N2) + O(1)
- two itterators: i1 - first word, i2 - second word
- two counters: c1, c2
- go through the first word, while the same letter and inc c1
- go through the second word, while the same letter and inc c2
- if c1 > c2: 
    return false
- else:
    ok: c1 = 0, c2 = 0
- check c1 and c2 after cycle (if needed)

*/

class Solution {
public:
    bool isLongPressedName(const string& name, const string& typed) {
        size_t i1 = 0, i2 = 0;
        size_t c1 = 0, c2 = 0;
        while (i1 < name.size() && i2 < typed.size()) {
            char cc1 = name[i1];
            while (i1 < name.size() && name[i1] == cc1) {
                ++i1;
                ++c1;
            }
            char cc2 = typed[i2];
            if (cc1 != cc2) return false;
            while (i2 < typed.size() && typed[i2] == cc2) {
                ++i2;
                ++c2;
            }
            if (c1 > c2) return false;
            c1 = 0;
            c2 = 0;
        }
        return (i1 == name.size() && i2 == typed.size());        
    }
};


