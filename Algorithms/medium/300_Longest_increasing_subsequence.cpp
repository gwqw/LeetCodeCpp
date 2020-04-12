/**
    300. Longest Increasing Subsequence
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:
Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 

Note:
There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

Algo: dp: O(N^2) + O(N)
- make d(0,n-1)
- for i in [0, n):
    - d[i] = 0
    - for j in [0,i):
        - if a[i] > a[j]
            - d[i] = max(d[i], d[j]+1)
        - else:
            - d[i] = max(d[i], d[j])
- return d[n-1]

*/

class Solution {
public:
    int lengthOfLIS(const vector<int>& a) {
        if (a.empty()) return 0;
        vector<int> d(a.size(), 1);
        d[0] = 1;
        for (size_t i = 1; i < a.size(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (a[i] > a[j] && d[i] < d[j]+1) {
                    d[i] = d[j]+1;
                }
            }
        }
        int ans = 0;
        for (auto v : d) {
            if (v > ans) ans = v;
        }
        return ans;
    }
};
