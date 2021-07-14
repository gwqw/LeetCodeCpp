/**
    398. Random Pick Index
Given an integer array nums with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the array nums.
int pick(int target) Picks a random index i from nums where nums[i] == target. If there are multiple valid i's, then each index should have an equal probability of returning.
 

Example 1:

Input
["Solution", "pick", "pick", "pick"]
[[[1, 2, 3, 3, 3]], [3], [1], [3]]
Output
[null, 4, 0, 2]

Explanation
Solution solution = new Solution([1, 2, 3, 3, 3]);
solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(1); // It should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
 

Constraints:

1 <= nums.length <= 2 * 10^4
-2^31 <= nums[i] <= 2^31 - 1
target is an integer from nums.
At most 10^4 calls will be made to pick.

Algo1: dict[num]->[idx] 

Algo2: Reservoir sampling (can be used for big arrays)
idx = 0
count = 0
for i in n:
    if a[i] == target:
        ++count
        if (rand() % count == 0):
            idx = i

*/

class Solution {
public:
    Solution(const vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); ++i) {
            dict[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        const auto& v = dict.at(target);
        int rand_idx = random() % v.size();
        return v[rand_idx];
    }
private:
    unordered_map<int, vector<int>> dict;
};

class Solution {
public:
    Solution(const vector<int>& nums) 
        : nums(nums)
    {}
    
    int pick(int target) {
        int idx = 0;
        int count = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] == target) {
                ++count;
                if (rand() % count == 0) {
                    idx = i;
                }
            }
        }
        return idx;        
    }
private:
    const vector<int>& nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */