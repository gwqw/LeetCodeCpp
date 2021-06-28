/**
    986. Interval List Intersections
You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.
Return the intersection of these two interval lists.
A closed interval [a, b] (with a < b) denotes the set of real numbers x with a <= x <= b.
The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].

Example 1:
Input: 
firstList = [[0,2],[5,10],[13,23],[24,25]], 
secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]

Example 2:
Input: firstList = [[1,3],[5,9]], secondList = []
Output: []

Example 3:
Input: firstList = [], secondList = [[4,8],[10,12]]
Output: []

Example 4:
Input: firstList = [[1,7]], secondList = [[3,10]]
Output: [[3,7]]

Constraints:
0 <= firstList.length, secondList.length <= 1000
firstList.length + secondList.length >= 1
0 <= start_i < end_i <= 10^9
end_i < starti+1
0 <= start_j < end_j <= 10^9
end_j < start_j+1

Algo: 2 iterators:
i=0
j=0
while i < f.size() && j < s.size():
    if f[i] & s[i] >= 0:
        res.add(f[i] & s[i])
    if f[i].end < s[j].end:
        i++
    else if f[i].end > s[j].end:
        j++
    else:
        i++
        j++

[[0,2],[5,12],[13,23],[24,25]], 
       ^               
[[1,5],[8,12],[15,24],[25,26]]
       ^                
 [1,2],[5,5],[8,10],[15,23],[24,24],[25,25]
[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(const vector<vector<int>>& f, const vector<vector<int>>& s) {
        vector<vector<int>> res;
        size_t i = 0, j = 0;
        while (i < f.size() && j < s.size()) {
            if (has_intersect(f[i], s[j])) {
                res.emplace_back(intersection(f[i], s[j]));
            }
            if (f[i][1] < s[j][1]) {
                ++i;
            } else if (f[i][1] > s[j][1]) {
                ++j;
            } else {
                ++i;
                +j;
            }
        }
        return res;
    }
    
private:
    bool has_intersect(const vector<int>& f, const vector<int>& s) {
        return !(f[1] < s[0] || s[1] < f[0]);
    }
    
    vector<int> intersection(const vector<int>& f, const vector<int>& s) {
        int left = max(f[0], s[0]);
        int right = min(f[1], s[1]);
        return {left, right};
    }
};