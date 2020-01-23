/**
    303. Range Sum Query - Immutable
    
Given an integer array nums, 
find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]
sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.

Algo: O(Elements)ctor, O(1) sumRange + O(Elements) memory
- use integral sums
- sums[i] = sums[i-1] + nums[i]
- return sums[j] - sums[i] (or zero if i == 0)
*/

class NumArray {
public:
    NumArray(vector<int>& nums) : sums_(nums.size()) {
        if (nums.empty()) return;
        sums_[0] = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            sums_[i] = sums_[i-1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return i ? sums_[j] - sums_[i-1] : sums_[j];
    }
private:
    vector<int> sums_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
 
class NumArray {
public:
    NumArray(vector<int>& nums) : sums_(nums.size()+1) {
        if (nums.empty()) return;
        sums_[0] = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            sums_[i+1] = sums_[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return sums_[j+1] - sums_[i];
    }
private:
    vector<int> sums_;
};

class NumArray {
public:
    NumArray(vector<int>& nums) {
        if (nums.empty()) return;
        assert(nums.size() < 10007);
        sums_[0] = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            sums_[i+1] = sums_[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return sums_[j+1] - sums_[i];
    }
private:
    array<int, 10007> sums_;
};

class NumArray {
public:
    NumArray(const vector<int>& nums) : sums_(nums.size()+1) {
        if (nums.empty()) return;
        sums_[0] = 0;
        partial_sum(nums.begin(), nums.end(), sums_.begin()+1);
    }
    
    int sumRange(int i, int j) {
        return sums_[j+1] - sums_[i];
    }
private:
    vector<int> sums_;
};



