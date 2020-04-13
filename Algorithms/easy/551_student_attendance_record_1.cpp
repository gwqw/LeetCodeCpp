/**
    551. Student Attendance Record I
You are given a string representing an attendance record for a student. 
The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False

Algo: go through array: O(N) + O(1)
- a_cnt = 0, l_cnt = 0
- for each letter:
    - if c == 'A':
        ++a_cnt;
        if a_cnt = 2: return false
        l_cnt = 0
    - elif c == 'L':
        ++l_cnt
        if l_cnt == 3: return false
    - else:
        l_cnt = 0
- return true
*/

class Solution {
public:
    bool checkRecord(const string& s) {
        size_t a_cnt = 0;
        size_t l_cnt = 0;
        for (auto c : s) {
            if (c == 'A') {
                ++a_cnt;
                if (a_cnt >= 2) return false;
                l_cnt = 0;
            } else if (c == 'L') {
                ++l_cnt;
                if (l_cnt >= 3) return false;
            } else {
                l_cnt = 0;
            }
        }
        return true;        
    }
};
