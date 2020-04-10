/**
    215. Kth Largest Element in an Array
Find the kth largest element in an unsorted array. 
Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:
Input: [3,2,1,5,6,4] and k = 2
Output: 5

Example 2:
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

Algo1: naive: sort and find idx: O(NlogN) + O(logN)

Algo2: use nth-element: O(N) + O(?)

Algo3: use heap: O(klogN) + O(N)


*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        size_t n = nums.size();
        assert(k <= n);
        size_t i = n-k;
        return nums[i];
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto it = nums.end() - k;
        nth_element(nums.begin(), it, nums.end());
        return *it;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q{nums.begin(), nums.end()};
        for (int i = 0; i+1 < k; ++i) {
            q.pop();
        }
        return q.top();
    }
};


