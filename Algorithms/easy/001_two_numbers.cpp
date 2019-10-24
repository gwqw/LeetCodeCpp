/**
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Ex.1
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
Corner.ex.:
01: [], 0 - empty
02: [9], 9 - empty

Algo: O(N), O(N)
make unordered_map: key = a[i], value = i
for every a[i] find (target - a[i]) in unordered_map and get idx j
if i != j: return {i,j}

Algo2: O(N), O(N)
the same, but seaarch at the same time, when adding (first -- search, second -- add)

feature: think about over INT_MIN && INT_MAX
*/

//O(N^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() < 2) return {};
        for(int i = 0; i < nums.size()-1; ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

// O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // check boundaries
        if (nums.size() < 2) return {};
        
        // first go through
        unordered_map<int, int> hash_nums;
        for (int i = 0; i < nums.size(); ++i) {
            hash_nums[nums[i]] = i;
        }
        
        // second go through
        for (int i = 0; i < nums.size(); ++i) {
            if (auto it = hash_nums.find(target - nums[i]); it != end(hash_nums) && it->second != i) {
                return {i, it->second};
            }
        }
        return {};
    }
};
