/**
   55. Jump Game
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

Constraints:
1 <= nums.length <= 10^4
0 <= nums[i] <= 10^5

Algo1: dp (solved for prefixes) O(N^2), O(N) (tle)
	dp = [steps+1, false]
	for step in nums:
		for j < i:
			if dp[j] and i-j < nums[j]:
				dp[i] = true
				break
	return dp[nums.size()]
	
Algo2: greedy max jump O(N^2) 800ms
we can jump maximum, because all less positions are reachable
for next position we search if we can jump here for numbers before
    if found: jump max
    else: return false

Algo3: greedy2: O(N)
take max availiable step in range:
    max_pos = max from nums[i] + i
    make step to max pos:
    search next step in (prev_pos, cur_pos]
    if next_pos <= cur_pos: return false
*/

class Solution {
public:
    bool canJump(const vector<int>& nums) {
		if (nums.size() <= 1) return true;
		for (size_t i = nums[0]; i < nums.size(); ) {
            bool is_found = false;
			for (size_t j = 0; j < i; ++j) {
				if (nums[j] >= i-j) {
				    i = jump_forward(i+1, nums[i], nums.size());
                    is_found = true;
					break;
				}
			}
            if (!is_found) return false;
		}
		return true;
    }
    
private:
    size_t jump_forward(size_t start, size_t count, size_t max_size) {
        return min(start+count, max_size);
    }
};

/*
take max availiable step in range:
    max_pos = max from nums[i] + i
    make step to max pos:
    search next step in (prev_pos, cur_pos]
    if next_pos <= cur_pos: return false
*/
class Solution {
public:
    bool canJump(const vector<int>& nums) {
		if (nums.size() <= 1) return true;
		size_t prev_pos = 0;
		size_t cur_pos = 0;
		while (true) {
		    size_t new_pos = search_max_pos(nums, prev_pos, cur_pos);
		    if (new_pos <= cur_pos) return false;
		    if (new_pos+1 >= nums.size()) return true;
		    prev_pos = cur_pos+1;
		    cur_pos = new_pos;
		}
		return true;
    }
    
private:
    size_t search_max_pos(const vector<int>& nums, size_t prev_pos, size_t cur_pos) {
        size_t max_pos = 0;
        for (size_t i = prev_pos; i <= cur_pos; ++i) {
            max_pos = max(max_pos, i + nums[i]);
        }
        return min(max_pos, nums.size());
    }
};


