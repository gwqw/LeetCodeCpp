/**
    57. Insert Interval
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

Example 3:
Input: intervals = [], newInterval = [5,7]
Output: [[5,7]]

Example 4:
Input: intervals = [[1,5]], newInterval = [2,3]
Output: [[1,5]]

Example 5:
Input: intervals = [[1,5]], newInterval = [2,7]
Output: [[1,7]]

Constraints:
0 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= intervals[i][0] <= intervals[i][1] <= 10^5
intervals is sorted by intervals[i][0] in ascending order.
newInterval.length == 2
0 <= newInterval[0] <= newInterval[1] <= 10^5

Algo: upper_bound for tail and lower_bound for head
it = upper_bound(tail)
if it == v.begin() push_front
[] [] [] [] 
  [     ]
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& ni) {
		vector<vector<int>> res;
		res.reserve(a.size());
		bool was_inserted = false;
		for (const auto& interval : a) {
			if (interval[1] < ni[0]) {
				res.push_back(interval);
			} else if (isIntersect(interval, ni)) {
				ni[0] = min(ni[0], interval[0]);
				ni[1] = max(ni[1], interval[1]);
			} else if (ni[1] < interval[0]) {
				if (!was_inserted) {
					res.push_back(ni);
					was_inserted = true;
				}
				res.push_back(interval);
			} 			
		}
		if (!was_inserted) {
			res.push_back(ni);
		}
		return res;
    }
	
private:
	bool isIntersect(const vector<int>& i1, const vector<int>& i2) {
		return !(i1[1] < i2[0] || i2[1] < i1[0]);		
	}
};

[[1,5]], newInterval = 
[1,5]