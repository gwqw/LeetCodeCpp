/**
    1574. Shortest Subarray to be Removed to Make Array Sorted
Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.
A subarray is a contiguous subsequence of the array.
Return the length of the shortest subarray to remove.

Example 1:
Input: arr = [1,2,3,10,4,2,3,5]
Output: 3
Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
Another correct solution is to remove the subarray [3,10,4].

Example 2:
Input: arr = [5,4,3,2,1]
Output: 4
Explanation: Since the array is strictly decreasing, we can only keep a single element. Therefore we need to remove a subarray of length 4, either [5,4,3,2] or [4,3,2,1].

Example 3:
Input: arr = [1,2,3]
Output: 0
Explanation: The array is already non-decreasing. We do not need to remove any elements.

Example 4:
Input: arr = [1]
Output: 0

Constraints:
1 <= arr.length <= 10^5
0 <= arr[i] <= 10^9

Algo: lower_bound: O(NlogN)
find after left sorted end -> lit (O(N))
find right sorted begin -> rit(O(N))
for it in [0, lit):
    jt = lower_bound(rid, end)
    max_size = max(max_size, it+1 + n - jt)
for it in [rit, end):
    jt = lower_bound(0, lit)
    max_size = max(max_size, it+1 + n - jt)
    
*/

class Solution {
public:
    int findLengthOfShortestSubarray(const vector<int>& a) {
        if (a.size() <= 1) return 0;
        auto lit = findLeftSortedEnd(a);
        if (lit == a.end()) return 0;
        auto rit = findRightSortedBegin(a);
        int min_size = a.size();
        for (auto it = a.begin(); it != lit; ++it) {
            auto jt = lower_bound(rit, a.end(), *it);
            int i = it - a.begin();
            int j = jt - a.begin();
            min_size = min(min_size, j-i-1);
        }
        for (auto it = rit; it != a.end(); ++it) {
            auto jt = upper_bound(a.begin(), lit, *it);
            int i = jt - a.begin();
            --i;
            int j = it - a.begin();
            min_size = min(min_size, j-i-1);
        }
        return min_size;
    }
    
private:
    vector<int>::const_iterator findRightSortedBegin(const vector<int>& a) {
        auto it = prev(a.end());
        for (; it != a.begin(); --it) {
            if (*prev(it) > *it) break;
        }
        return it;
    }
    
    vector<int>::const_iterator findLeftSortedEnd(const vector<int>& a) {
        auto it = next(a.begin());
        for (; it != a.end(); ++it) {
            if (*prev(it) > *it) break;
        }
        return it;
    }
};


            