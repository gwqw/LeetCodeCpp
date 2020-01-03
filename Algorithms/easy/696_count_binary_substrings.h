/**
    696. Count Binary Substrings

Give a string s, count the number of non-empty (contiguous) substrings 
that have the same number of 0's and 1's, and all the 0's and all the 1's 
in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

Example 1:
Input: "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".

Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.

Example 2:
Input: "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.

Note:
* s.length will be between 1 and 50,000.
* s will only consist of "0" or "1" characters.

Algo: O(N) + O(1)
- make counters: c1 for '1' and c0 for '0' (zero init)
- make bool flag: is_one (init by first symb)
- make counter res = 0
- go through string:
    - if c == '1' && flag:
        - c1++
    elif c == '0' && !flag:
        - c0++
    else:
        res += min(c1, c0)
        if c == '1':
            - c1 == 1
        elif c == '0':
            - c0 = 1
- count last pair: res += min(c1, c0)

Algo2: the same, but use previous and current counters, current symbol
*/

class Solution {
public:
    int countBinarySubstrings(const string& s) {
        if (s.empty()) return 0;
        int c1 = 0, c0 = 0, res = 0;
        bool is_one = s[0] == '1';
        for (auto c : s) {
            if (c == '1' && is_one) {
                ++c1;
            } else if (c == '0' && !is_one) {
                ++c0;
            } else {
                res += std::min(c1, c0);
                if (c == '1') {
                    c1 = 1;
                    is_one = true;
                } else {
                    c0 = 1;
                    is_one = false;
                }
            }
        }
        return res + std::min(c0, c1);
    }
};
