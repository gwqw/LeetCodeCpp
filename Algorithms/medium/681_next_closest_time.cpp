/**
    681. Next Closest Time
Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.
You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

Example 1:
Input: time = "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.
It is not 19:33, because this occurs 23 hours and 59 minutes later.

Example 2:
Input: time = "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22.
It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.

Constraints:
time.length == 5
time is a valid time in the form "HH:MM".
0 <= HH < 24
0 <= MM < 60


*/

class Solution {
public:
    string nextClosestTime(string_view time) {
        int d1 = time[0] - '0';
        int d2 = time[1] - '0';
        int d3 = time[3] - '0';
        int d4 = time[4] - '0';
        set<int> nums{d1, d2, d3, d4};
        // rule 1
        if (auto it = nums.upper_bound(d4); it != nums.end()) {
            d4 = *it;
            return formatString(d1, d2, d3, d4);
        }
        // rule 2
        if (auto it = nums.upper_bound(d3); it != nums.end() && *it < 6) {
            d3 = *it;
            d4 = *(nums.begin());
            return formatString(d1, d2, d3, d4);
        }
        // rule 3
        if (d1 < 2) {
            if (auto it = nums.upper_bound(d2); it != nums.end()) {
                d2 = *it;
                d3 = d4 = *(nums.begin());
                return formatString(d1, d2, d3, d4);
            }
        } else {
            if (auto it = nums.upper_bound(d2); it != nums.end() && *it < 4) {
                d2 = *it;
                d3 = d4 = *(nums.begin());
                return formatString(d1, d2, d3, d4);
            }            
        }
        // rule 4
        if (auto it = nums.upper_bound(d1); it != nums.end() && *it < 3) {
            d1 = *it;
            d2 = d3 = d4 = *(nums.begin());
            return formatString(d1, d2, d3, d4);
        }
        // it was max string
        d1 = d2 = d3 = d4 = *(nums.begin());
        return formatString(d1, d2, d3, d4);
    }
    
private:
    string formatString(int d1, int d2, int d3, int d4) {
        return to_string(d1) + to_string(d2) + ":" + 
            to_string(d3) + to_string(d4);
    }
};