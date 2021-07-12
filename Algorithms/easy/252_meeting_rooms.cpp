/**
    252. Meeting Rooms
Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.

Example 1:
Input: intervals = [[0,30],[5,10],[15,20]]
Output: false

Example 2:
Input: intervals = [[7,10],[2,4]]
Output: true

Constraints:
0 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti < endi <= 10^6

Algo: sort and check
*/

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (isIntersect(intervals[i-1], intervals[i])) return false;
        }
        return true;
    }
    
private:
    bool isIntersect(const vector<int>& lhs, const vector<int>& rhs) {
        return lhs[1] > rhs[0];
    }
};