/**
    253. Meeting Rooms II
Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

Example 1:
Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2

Example 2:
Input: intervals = [[7,10],[2,4]]
Output: 1

Constraints:
1 <= intervals.length <= 10^4
0 <= start_i < end_i <= 10^6

Algo: greedy O(NlogN)
sort(intervals by begins) - O(NlogN)
set tails
for bi,ei in intervals:    - O(N)
    it = tail.upper_bound(b_i) O(logN)
    if it == tails.begin():
        tails.insert(e_i)
    else:
        --it
        *it = e_i
return tails.size()
*/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        map<int, int> tails;
        for (const auto& interval : intervals) {
            auto bi = interval[0];
            auto ei = interval[1];
            auto it = tails.upper_bound(bi);
            if (it == tails.begin()) {
                ++tails[ei];
            } else {
                --it;
                --it->second;
                if (it->second == 0) {
                    tails.erase(it);
                }
                ++tails[ei];
            }
        }
        int ans = 0;
        for (const auto [_, cnt] : tails) {
            ans += cnt;
        }
        return ans;
    }
};

