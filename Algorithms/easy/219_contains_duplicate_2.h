/**
    219. Contains Duplicate II
Given an array of integers and an integer k, 
find out whether there are two distinct indices i and j in the array 
such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
(not greater)

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:
Input: nums = [1,2,3,1,2,3], k = 2
Output: false

Algo1: naive: O(Nk) + O(1)
- brute-force

Algo2: O(N) amortized + O(K)
- k = min(k, nums.size())
- make a set (0,k-1)
- check set.size() == k
- go to the right:
- remove i-k
- add i
- check size

*/

class Solution {
public:
    bool containsNearbyDuplicate(const vector<int>& nums, int k) {
        if (k <= 0 || nums.empty()) return false;
        if (k >= nums.size()) k = (int)nums.size()-1;
        for (size_t i = k; i < nums.size(); ++i) {
            for (size_t j = 1; j <= k; ++j) {
                if (nums[i] == nums[i-j]) return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(const vector<int>& nums, int k) {
        if (k <= 0 || nums.empty()) return false;
        if (k >= nums.size()) k = (int)nums.size()-1;
        unordered_set<int> cache;
        for (size_t i = 0; i < k+1; ++i) {
            cache.insert(nums[i]);
        }
        if (cache.size() != k+1) return true;
        
        for (size_t i = k+1; i < nums.size(); ++i) {
            cache.erase(nums[i-k-1]);
            cache.insert(nums[i]);
            if (cache.size() != k+1) return true;
        }
        return false;
    }
};

//Algo2 try to enhance
class Solution {
public:
    bool containsNearbyDuplicate(const vector<int>& nums, int k) {
        if (k <= 0 || nums.empty()) return false;
        if (k >= nums.size()) k = (int)nums.size()-1;
        unordered_set<int> cache;
        for (size_t i = 0; i < k+1; ++i) {
            auto [_, res] = cache.insert(nums[i]);
            if (!res) return true;
        }
        
        for (size_t i = k+1; i < nums.size(); ++i) {
            cache.erase(nums[i-k-1]);
            auto [_, res] = cache.insert(nums[i]);
            if (!res) return true;
        }
        return false;
    }
};

