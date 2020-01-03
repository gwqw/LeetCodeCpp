/**
    169. Majority Element
Given an array of size n, find the majority element. 
The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:
Input: [3,2,3]
Output: 3

Example 2:
Input: [2,2,1,1,1,2,2]
Output: 2

Algo1: naive: use dict(value -> cnt): O(N) amortized + O(N)

Algo2: sort: O(NlogN) + O(1)
- sort
- have prev_value = nums[0] && count = 1, max_count = 1, max_value = nums[0]
- if *it > nums.size() / prev_value: update max_count, max_value and reset count and prev_value
- else ++count
- after exit: update max

Algo3: sort and find median: O(NlogN) + O(1)
- sort
- return nums[size//2]

Algo4: use nth_element for median: O(N) + O(1)

Algo5: quick-select: O(N) + O(1)
- select a pivot: a[0]
- rearrange: 
    - if a[i] > pivot:
        - swap(a[i], pivot)
- left.size() == right.size() => pivot == 

Algo6: probability: O(N) + O(1)
- select random element
- check if it is correct (O(N))
- if not: repeat

Algo7: Boyer-Moore majority vote algorithm 
- cand = nums[0], count = 1
- go through nums:
    - if cnt ==0:
        cand = nums[i]
        cnt = 1
    - elif nums[i] == cand:
        ++cnt
    - else:
        --cnt
    if (cnt == 0):
        cand = nums[-1]
    return cand
*/

// dict
class Solution {
public:
    int majorityElement(const vector<int>& nums) {
        unordered_map<int, int> dict;
        for (auto n : nums) {
            ++dict[n] ;
        }
        
        int max_value = nums.size() / 2;
        for (auto [k,v] : dict) {
            if (v > max_value) {
                return k;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max_count = 1, cnt = 1;
        int max_value = nums[0], prev_value = nums[0];
        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] != prev_value) {
                if (cnt > max_count) {
                    max_count = cnt;
                    max_value = prev_value;
                }
                cnt = 1;
                prev_value = nums[i];
            } else {
                ++cnt;
            }
        }
        if (cnt > max_count) {
            max_count = cnt;
            max_value = prev_value;
        }
        return max_value;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int idx = nums.size() / 2;
        nth_element(nums.begin(), nums.begin() + idx, nums.end());
        return nums[idx];
    }
};

class Solution {
public:
    int majorityElement(const vector<int>& nums) {
        int cand = nums[0];
        int cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (cnt == 0) {
                cand = nums[i];
                cnt = 1;
            } else if (cand == nums[i]) {
                ++cnt;
            } else {
                --cnt;
            }
        }
        if (cnt == 0) {
            cand = nums.back();
        }
        return cand;
    }
};



