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
    
Algo4: move each element to his place: O(N) + O(1)
- new_i = (i+k) % n
- previous save to tmp and move further
- stop after n moves

Algo5: 3 reverse: O(N) + O(1)
- reverse whole array
- reverse [0..k)
- reverse [k..n)

Algo6: std::rotate

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

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        auto n = nums.size();
        k %= n;
        if (n == 1 || k == 0) return;
        
        size_t idx = 0;
        size_t init_idx = 0;
        int t = nums[idx];
        for (size_t i = 0; i < n; ++i) {
            idx = (idx + k) % n;
            swap(t, nums[idx]);
            if (idx == init_idx) {
                idx = ++init_idx;
                t = nums[idx];
            }
        }
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        auto n = nums.size();
        k %= n;
        if (n == 1 || k == 0) return;
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto n = nums.size();
        if (n == 1) return;
        k %= n;
        if (k == 0) return;
        
        std::rotate(nums.begin(), nums.begin() + (n-k), nums.end());
    }
};


/*
k = 3
1 2 3 4 5 6 7 t = 1, i = 0
1 2 3 1 5 6 7 t = 4, i = 3
1 2 3 1 5 6 4 t = 7, i = 6
1 2 7 1 5 6 4 t = 3, i = 2
1 2 7 1 5 3 4 t = 6, i = 5
1 6 7 1 5 3 4 t = 2, i = 1
1 6 7 1 2 3 4 t = 5, i = 4
5 6 7 1 2 3 4 t = 1, i = 0
    

[1,2,3,4,5,6,7]
3
[1,2,3,4,5,6]
2
[1,2]
1
[1,2,3,4]
2
[1,2,3,4]
3

*/


