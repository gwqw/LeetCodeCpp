/**
    532. K-diff Pairs in an Array
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
0 <= i < j < nums.length
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.

Example 1:
Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.

Example 2:
Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).

Example 3:
Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).

Example 4:
Input: nums = [1,2,4,4,3,3,0,9,2,3], k = 3
Output: 2

Example 5:
Input: nums = [-1,-2,-3], k = 1
Output: 2

Constraints:
1 <= nums.length <= 10^4
-10^7 <= nums[i] <= 10^7
0 <= k <= 10^7

Algo1: hash_set
for n in 0,nums.size():
    if canSubstr(n, k) && n-k in set && n not in was[n-k]:
        cnt += 1
    if canSum(n, k) and n+k in set && n not in was[n+k]:
        cnt += 1
    set.insert(n)
    
Algo2: dict
counter_dict
for n, freq in dict:
    k != 0:
        if n+k in dict:
            ++cnt
    k == 0:
        if freq > 1:
            ++cnt
*/

class Solution {
public:
    int findPairs(const vector<int>& nums, int k) {
        unordered_set<int> num_set;
        unordered_map<int, unordered_set<int>> was;
        int cnt = 0;
        for (int n : nums) {
            if (canSubstr(n, k) && num_set.count(n-k) && !was[n-k].count(n)) {
                ++cnt;
                was[n-k].insert(n);
            }
            if (canSum(n, k) && num_set.count(n+k) && !was[n].count(n+k)) {
                ++cnt;
                was[n].insert(n+k);
            }
            num_set.insert(n);
        }
        return cnt;
    }
    
private:
    bool canSubstr(int n, int k) {
        return n >= INT_MIN+k;
    }
    
    bool canSum(int n, int k) {
        return n <= INT_MAX-k;
    }
};

class Solution {
public:
    int findPairs(const vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        int cnt = 0;
        for (int n : nums) {
            ++dict[n];
        }
        for (auto [n, freq] : dict) {
            if (k != 0) {
                if (dict.count(n+k)) {
                    ++cnt;
                }    
            } else {
                if (freq > 1) ++cnt;
            }
        }
        return cnt;
    }
};
