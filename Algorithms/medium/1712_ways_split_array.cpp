/**
    1712. Ways to Split Array Into Three Subarrays
A split of an integer array is good if:
- The array is split into three non-empty contiguous subarrays - named left, mid, right respectively from left to right.
- The sum of the elements in left is less than or equal to the sum of the elements in mid, and the sum of the elements in mid is less than or equal to the sum of the elements in right.
- Given nums, an array of non-negative integers, return the number of good ways to split nums. As the number may be too large, return it modulo 10^9 + 7.

Example 1:
Input: nums = [1,1,1]
Output: 1
Explanation: The only good way to split nums is [1] [1] [1].

Example 2:
Input: nums = [1,2,2,2,5,0]
Output: 3
Explanation: There are three good ways of splitting nums:
[1] [2] [2,2,5,0]
[1] [2,2] [2,5,0]
[1,2] [2,2] [5,0]

Example 3:
Input: nums = [3,2,1]
Output: 0
Explanation: There is no good way to split nums.

Constraints:
3 <= nums.length <= 10^5
0 <= nums[i] <= 10^4

Algo1: prefix sum and bin_search
for r in n-1, -1:
    bin_search m:
        s[m] <= s[r] - s[m] <= s[-1] - s[r]
        if m == 0: break;

*/

class Solution {
    static constexpr int P = (int)1e9 + 7;
public:
    int waysToSplit(const vector<int>& a) {
        auto prefix_sum = calcPrefix(a);
        int right_min_sum = prefix_sum.back() % 3 == 0 ? 
            prefix_sum.back() - prefix_sum.back() / 3 :
            prefix_sum.back() - prefix_sum.back() / 3 - 1;
        auto rit = upper_bound(prefix_sum.begin(), prefix_sum.end(), prefix_sum.back() - right_min_sum);
        if (rit == prefix_sum.begin()) return 0;
        int64_t cnt = 0;
        while (rit != prefix_sum.begin()) {
            int left_sum = *prev(rit);
            int first_sum = left_sum % 2 == 0 ? left_sum / 2 : left_sum / 2 - 1;
            auto it = upper_bound(prefix_sum.begin(), rit, first_sum);
            if (it == prefix_sum.begin()) continue;
            --it;
            if (it != prefix_sum.begin()) {
                cnt = mplus(cnt, (it - prefix_sum.begin()));
            }
            --rit;
        }
        return cnt;
    }
    
private:
    vector<int> calcPrefix(const vector<int>& a) {
        vector<int> pref(a.size());
        for (size_t i = 1; i < a.size(); ++i) {
            pref[i] = pref[i-1] + a[i];
        }
        return pref;
    }
    
    int64_t mplus(int64_t n, int64_t m) {
        n %= P;
        m %= P;
        return (n + m) % P;
    }
};

