/**
    217. Contains Duplicate
Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct.

Example 1:
Input: [1,2,3,1]
Output: true

Example 2:
Input: [1,2,3,4]
Output: false

Example 3:
Input: [1,1,1,3,3,4,3,2,4,2]
Output: true

Algo1: sort O(NlogN) + O(logN)

Algo2: use dict(set from vector) O(N) + O(N)

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) return false;
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (prev == nums[i]) return true;
            prev = nums[i];
        }
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s{nums.begin(), nums.end()};
        return s.size() < nums.size();
    }
};
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return unordered_set<int>{nums.begin(), nums.end()}.size() < nums.size();
    }
};

