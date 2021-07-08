/**
    41. First Missing Positive
Given an unsorted integer array nums, find the smallest missing positive integer.
You must implement an algorithm that runs in O(n) time and uses constant extra space.

Example 1:
Input: nums = [1,2,0]
Output: 3

Example 2:
Input: nums = [3,4,-1,1]
Output: 2

Example 3:
Input: nums = [7,8,9,11,12]
Output: 1

Constraints:
1 <= nums.length <= 5 * 10^5
-2^31 <= nums[i] <= 2^31 - 1

Algo1: partition + radix sort. O(N), O(1)mem
    partition(neg and positive)
    n = pos size, so nums can be 1..n
    partition(num > size)
    use radix sort: can set '-' for found num
    
Algo2: same, but wo partition. O(N), O(1) mem
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.erase(
            partition(nums.begin(), nums.end(), [](int v){return v > 0;}),
            nums.end()
        );
        size_t size = nums.size();
        nums.erase(
            partition(nums.begin(), nums.end(), [size](int v){return v <= size;}),
            nums.end()
        );
        
        for (size_t i = 0; i < nums.size(); ++i) {
            int n = abs(nums[i])-1;
            if (n < nums.size() && nums[n] > 0) {
                nums[n] = -nums[n];
            }
        }
        
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (nums[i] > 0) return i+1;
        }
        return nums.size()+1;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool is_one_found = false;
        for (auto& n : nums) {
            if (n == 1) is_one_found = true;
            if (n <= 0) n = 1;
            if (n > nums.size()) n = 1;
        }
        if (!is_one_found) return 1;
        for (size_t i = 0; i < nums.size(); ++i) {
            int n = abs(nums[i])-1;
            if (n < nums.size() && nums[n] > 0) {
                nums[n] = -nums[n];
            }
        }
        
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (nums[i] > 0) return i+1;
        }
        return nums.size()+1;
    }
};
