/**
    912. Sort an Array
Given an array of integers nums, sort the array in ascending order.

Example 1:
Input: nums = [5,2,3,1]
Output: [1,2,3,5]

Example 2:
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]

Constraints:
1 <= nums.length <= 5 * 10^4
-5 * 10^4 <= nums[i] <= 5 * 10^4
*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size());
        return move(nums);
    }
    
private:
    void quick_sort(vector<int>& nums, size_t from, size_t to) {
        if (to - from <= 1) return;
        size_t p = rand() % (to - from) + from;
        swap(nums[from], nums[p]);
        size_t l = from+1;
        int pivot = nums[from];
        for (size_t i = from+1; i < to; ++i) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[l++]);
            }
        }
        if (from < l) {
            swap(nums[from], nums[l-1]);
        }
        quick_sort(nums, from, l-1);
        quick_sort(nums, l, to);
    }
};