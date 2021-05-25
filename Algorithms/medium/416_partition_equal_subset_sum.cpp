/**
    416. Partition Equal Subset Sum
Given a non-empty array nums containing only positive integers, 
find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

Constraints:
    1 <= nums.length <= 200
    1 <= nums[i] <= 100

Algo: bf [tle]
0 -> sumx
interate y -> sumy
sumx += all x < y
[(s1, s2)] = sum(arr+y)
for s1,s2 in []:
    if x+s1 == y+s2 or x+s2 == y+s1: return true
    sum1.append(s1 + x, s1 + y)
    sum2.append(s2 + y, s2 + x)
    
Algo2: dp
for all prefix:
    fill all available sums:
        sum[x] = true
        for i,s in sums:
            s == prev_sums[i] or i >= x ? prev_sums[i-x]
*/

// tle
class Solution {
    using Sums = vector<pair<int,int>>;
public:
    bool canPartition(const vector<int>& nums) {
        int max_sum = 0;
        for (auto n : nums) {
            max_sum += n;
        }
        cache.resize(max_sum);
        auto sums = partition(nums, 0);
        for (auto [s1, s2] : sums) {
            if (s1 == s2) return true;
        }
        return false;
    }
private:
    Sums partition(const vector<int>& nums, int begin) {
        if (begin == nums.size()) return {};
        if (!cache[begin].empty()) return cache[begin];
        int x = 0;
        Sums res;
        for (int i = begin; i < nums.size(); ++i) {
            int y = nums[i];
            auto sums = partition(nums, i+1);
            if (!sums.empty()) {
                for (auto [s1, s2] : sums) {
                    res.push_back({s1+x, s2+y});
                    res.push_back({s2+x, s1+y});
                }
            } else {
                res.push_back({x, y});
            }
            x += nums[i]; 
        }
        cache[begin] = res;
        return res;
    }
    
    vector<Sums> cache;
};

/*
for all prefix:
    fill all available sums:
        sum[x] = true
        for i,s in sums:
            s == prev_sums[i] or i >= x ? prev_sums[i-x]
*/
class Solution {
public:
    bool canPartition(const vector<int>& nums) {
        int max_sum = 0;
        for (auto n : nums) {
            max_sum += n;
        }
        if (max_sum % 2 == 1) return false;
        max_sum /= 2;
        vector<bool> prev_sums(max_sum+1, false);
        prev_sums[0] = true;
        for (auto x : nums) {
            vector<bool> sums(max_sum+1, false);
            for (int i = 0; i < sums.size(); ++i) {
                sums[i] = prev_sums[i];
                if (i >= x) {
                    sums[i] = sums[i] || prev_sums[i-x];
                }
            }
            swap(prev_sums, sums);
        }
        return prev_sums[max_sum];
    }
};

class Solution {
public:
    bool canPartition(const vector<int>& nums) {
        int max_sum = 0;
        for (auto n : nums) {
            max_sum += n;
        }
        if (max_sum % 2 == 1) return false;
        max_sum /= 2;
        vector<bool> sums(max_sum+1, false);
        sums[0] = true;
        for (auto x : nums) {
            for (int i = max_sum; i >= x; --i) {
                if (sums[i-x]) {
                    sums[i] = true;
                }
            }
        }
        return sums[max_sum];
    }
};


