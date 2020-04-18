/**
    56. Merge Intervals
Given a collection of intervals, merge all overlapping intervals.

Example 1:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Algo: O(NlogN) + O(N)
- make map
- res
- go through map:
    l, r, was_update = true
    for all li <= r:
        r = max(r, ri)
        delete li, ri from map
    - move lr to res and remove from map  
    
Algo: the same with vector O(NlogN) + O(N)
- sort vector li < lj
- res
- for all li, ri:
    - for all lj, rj: lj <= ri
        - ri = max(ri, rj)
    - i = j
        
        
*/

class Solution {
public:
    vector<vector<int>> merge(const vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        map<int, int> l2r = makeMap(intervals);
        auto it = l2r.begin();
        while (it != l2r.end()) {
            auto& [l,r] = *it;
            auto jt = next(it);
            while (jt != l2r.end() && jt->first <= r) {
                auto [li, ri] = *jt;
                r = max(r, ri);
                jt = l2r.erase(jt);
            }
            res.push_back({l, r});
            it = l2r.erase(it);
        }
        return res;
    }
private:
    map<int, int> makeMap(const vector<vector<int>>& intervals) {
        map<int, int> res;
        for (const auto& v : intervals) {
            auto l = v[0];
            auto r = v[1];
            if (!res.count(l) || res[l] < r) {
                res[l] = r;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), 
            [](const auto& lhs, const auto& rhs){return lhs[0] < rhs[0];}
        );
        vector<vector<int>> res;
        size_t i = 0;
        while (i < a.size()) {
            int& r = a[i][1];
            size_t j = i+1;
            while (j < a.size() && a[j][0] <= r) {
                r = max(r, a[j][1]);
                ++j;
            }
            res.push_back({a[i][0], r});
            i = j;
        }
        return res;
    }
};



