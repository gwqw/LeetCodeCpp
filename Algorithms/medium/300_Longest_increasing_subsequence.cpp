/**
    300. Longest Increasing Subsequence
Given an unsorted array of integers, find the length of longest increasing subsequence.
A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Example 1:
Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1

Constraints:
1 <= nums.length <= 2500
-10^4 <= nums[i] <= 10^4

Note:
There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

Algo: dp: O(N^2) + O(N)
find answer for all prefixes. For next element go through all prefixes and search best result
- make d(0,n-1)
- for i in [0, n):
    - d[i] = 0
    - for j in [0,i): # find best subsequnce for prev elements
        - if a[i] > a[j] # can be next element of subsequence
            - d[i] = max(d[i], d[j]+1)
        - else:          # cannot be next element, can be skipped
            - d[i] = max(d[i], d[j])
- return d[n-1]

Algo2: dp2 O(N^2), O(N) mem
make dict[num]->max_len
for new element update all lengths

Algo3: dp3 O(N^2), O(N) mem
use vector as dict, original -- keys, new -- lengths

Algo4: O(N*logN)
vec len -> min_num with this len
for new num:
    search first bigger num and add change it on new num: O(logN)
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

//dp2 with map
class Solution {
public:
    int lengthOfLIS(const vector<int>& nums) {
        map<int, int> dict;
        for (int num : nums) {
            int max_len = 1;
            auto eit = dict.lower_bound(num);
            for (auto it = dict.begin(); it != eit; ++it) {
                if (it->second + 1 > max_len) {max_len = it->second+1;}
            }
            dict[num] = max(dict[num], max_len);
        }
        int ans = 0;
        for (auto [k,v] : dict) {
            if (ans < v) ans = v;
        }
        return ans;
    }
};
class Solution {
public:
    int lengthOfLIS(const vector<int>& nums) {
        unordered_map<int, int> dict;
        for (int num : nums) {
            int max_len = 1;
            for (auto& [k, v] : dict) {
                if (k < num && v+1 > max_len) {
                    max_len = v+1;
                }
            }
            dict[num] = max(dict[num], max_len);
        }
        int ans = 0;
        for (auto [k,v] : dict) {
            if (ans < v) ans = v;
        }
        return ans;
    }
};

//dp2 with vector
class Solution {
public:
    int lengthOfLIS(const vector<int>& nums) {
        vector<int> lengths(nums.size(), 1);
        for (size_t i=0; i < nums.size(); ++i) {
            int num = nums[i];
            int max_len = 1;
            for (size_t j=0; j < i; ++j) {
                if (nums[j] < num && lengths[j]+1 > max_len) {
                    max_len = lengths[j]+1;
                }
            }
            lengths[i] = max(lengths[i], max_len);
        }
        int ans = 0;
        for (auto v : lengths) {
            if (ans < v) ans = v;
        }
        return ans;
    }
};

// algo4
class Solution {
public:
    int lengthOfLIS(const vector<int>& nums) {
        vector<int> l2n(nums.size(), INT_MAX);
        for (auto num : nums) {
            auto it = lower_bound(l2n.begin(), l2n.end(), num);
            *it = num;
        }
        auto it = lower_bound(l2n.begin(), l2n.end(), INT_MAX);
        return distance(l2n.begin(), it);
    }
};

