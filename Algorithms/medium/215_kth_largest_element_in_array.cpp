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

Algo3: use heap: O(N + klogN) + O(N)

Algo4: write nth-element: divide and conquer: O(N) amortized + O(logN) recursion
random_select(a, l, r, k):
    if l >= r:
        return a[l]
    x <- rand from a
    split on 3 range: l, m1, m2, r
        i in l..m1: a[i] < x
        i in m1..m2: a[i] == x
        i in m2..r: x < a[i]
    if l <= k < m1:
        return random_select(a, l, m1, k)
    elif m1 <= k < m2:
        return x
    else: # m2 <= k < r
        return random_select(a, m2, r, k)        

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

/*
Algo4: write nth-element: divide and conquer: O(N) amortized + O(logN) recursion
random_select(a, l, r, k):
    if l >= r:
        return a[l]
    x <- rand from a
    split on 3 range: l, m1, m2, r
        i in l..m1: a[i] < x
        i in m1..m2: a[i] == x
        i in m2..r: x < a[i]
    if l <= k < m1:
        return random_select(a, l, m1, k)
    elif m1 <= k < m2:
        return x
    else: # m2 <= k < r
        return random_select(a, m2, r, k)    
*/
class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        assert(!a.empty());
        return randomSelect(a, 0, a.size(), k);
    }
private:
    int randomSelect(vector<int>& a, size_t l, size_t r, int k) {
        if (l+1 == r) {
            return a[l];
        }
        int x = a[l + rand() % r];
        
    }
    
};


