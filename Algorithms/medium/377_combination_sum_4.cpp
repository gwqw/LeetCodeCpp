/**
    377. Combination Sum IV
Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.
The answer is guaranteed to fit in a 32-bit integer.

Example 1:
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.

Example 2:
Input: nums = [9], target = 3
Output: 0

Constraints:
1 <= nums.length <= 200
1 <= nums[i] <= 1000
All the elements of nums are unique.
1 <= target <= 1000

Follow up: What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?

Algo1: bf + recursion
def cnt(nums, target):
	if target = 0: return 1
	res = 0
	for num in nums:
		if target >= num:
			res += cnt(nums, target - num)
			
1 2 3  
t=1: r=1
t=2: r=1+2=3
t=3: r=3+1+1=5
t=4: r=5+3+1=8

Algo2: recursion with memoisation: O(target*N)
dict[num] -> number of combination
def cnt(nums, target):
	if target == 0: return 1
	res = 0
	for num in nums:
		if target >= num:
			test = target - num
			if test not in dict:
				dict[test] = cnt(nums, test)
			res += dict[test]

Algo3: dp: O(target*N)
cnt [num] -> combination count
cnt[0] = 1
for i in range(1, target):
	for n in nums:
		if n <= i:
			cnt[i] += cnt[i-n]

*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (target == 0) return 1;
		int res = 0;
		for (auto num : nums) {
			int test = target - num;
			if (test < 0) continue;
			if (!dict.count(test)) {
				dict[test] = combinationSum4(nums, test);
			}
			res += dict[test];
		}
		return res;
    }
	
private:
	unordered_map<int, int> dict;
};

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
		vector<int> cnt(target+1, 0);
        cnt[0] = 1;
		for (int i = 0; i <= target; ++i) {
			for (int num : nums) {
				if (i >= num) {
					cnt[i] = safe_sum(cnt[i], cnt[i-num]);
				}
			}
		}
		return cnt[target];
    }
    
private:
    int safe_sum(int a, int b) { // or use unsigned
        if (a > INT_MAX - b) {
            return INT_MAX;
        }
        return a+b;
    }
};

// Alog1 with vector
class Solution {
public:
    Solution() 
        : dict(1001, -1)
    {
    }

    int combinationSum4(vector<int>& nums, int target) {
        if (target == 0) return 1;
		int res = 0;
		for (auto num : nums) {
			int test = target - num;
			if (test < 0) continue;
			if (dict[test] == -1) {
				dict[test] = combinationSum4(nums, test);
			}
			res += dict[test];
		}
		return res;
    }
	
private:
	vector<int> dict;
};

