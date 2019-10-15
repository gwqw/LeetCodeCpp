/**
    189. Rotate Array
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?

Algo1 - copy: O(N), O(N)
    n = nums.size()
    k %= n
    copy [n-k, ... n-1]
    copy [0, n-k-1]
    
Algo2 - in place: O(k * N), O(1) -- time limit
    rotate1:
        t = last;
        n-2 -> n-1
        ..
        n-i-2 -> n-i-1
        n[0] = t
        
Algo3 - copy part:
    copy last part: [n-k, n-1] -> tarr
    move rest(i+k < n):
        n-1-k -> n-1
        n-1-k-i -> n-1-i
    move back tarr -> to the begin 
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto n = nums.size();
        k %= n;
        vector<int> res(n);
        auto it = std::move(nums.begin() + (n-k), nums.end(), res.begin());
        std::move(nums.begin(), nums.begin() + (n-k), it);
        nums = std::move(res);
    }
};

class Solution {
private:
    void rotate1(vector<int>& nums) {
        auto t = nums.back();
        auto n = nums.size();
        for (int i = 0; i+1 < n; ++i) {
            nums[n-i-1] = nums[n-i-2];
        }
        nums[0] = t;
    }
public:
    void rotate(vector<int>& nums, int k) {
        auto n = nums.size();
        if (!n) return;
        k %= n;
        for (int i = 0; i < k; ++i) {
            rotate1(nums);
        }
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto n = nums.size();
        if (!n) return;
        k %= n;
        
        vector<int> tarr(k);
        std::move(nums.begin() + (n-k), nums.end(), tarr.begin());
        for (int i = 0; i+k < n; ++i) {
            nums[n-i-1] = nums[n-i-1-k];
        }
        std::move(tarr.begin(), tarr.end(), nums.begin());
    }
};