/**
    128. Longest Consecutive Sequence
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Constraints:
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9

Algo1: use hash map: O(N), O(N)
make set nums
for any num try to make cons. seq: upper and down
for start_num in nums:
	if start_num not in nums
	set.erase(start_num)
	end_num = start_num
	cur_length = 1
	# up
	while end_num+1 in set:
		end_num += 1
		cur_length += 1
		set.erase(end_num)
	# down
	while start_num-1 in set:
		start_num -= 1
		cur_length += 1
		set.erase(start_num)
	update_max_lenght()
	
Algo2: sort and search
*/

class Solution {
public:
    int longestConsecutive(const vector<int>& nums) {
        unordered_set<int> nums_set{nums.begin(), nums.end()};
		int max_length = 0;
		for (auto num : nums) {
		    if (nums_set.empty()) break;
			if (!nums_set.count(num)) continue;
			nums_set.erase(num);
			int end_num = num;
			int cur_length = 1;
			// up
			while (nums_set.count(end_num+1)) { // TODO: check for MAX_INT
				end_num++;
				cur_length++;
				nums_set.erase(end_num);
			}
			// down
			while (nums_set.count(num-1)) { // TODO: check for MIN_INT
				num--;
				cur_length++;
				nums_set.erase(num);
			}
			max_length = max(max_length, cur_length);
		}
		return max_length;
    }
};

class Solution {
public:
    int longestConsecutive(const vector<int>& nums) {
        unordered_set<int> nums_set{nums.begin(), nums.end()};
		int max_length = 0;
		while (!nums_set.empty()) {
		    auto num = *nums_set.begin();
			nums_set.erase(nums_set.begin());
			int end_num = num;
			int cur_length = 1;
			// up
			while (nums_set.count(end_num+1)) {
				end_num++;
				cur_length++;
				nums_set.erase(end_num);
			}
			// down
			while (nums_set.count(num-1)) {
				num--;
				cur_length++;
				nums_set.erase(num);
			}
			max_length = max(max_length, cur_length);
		}
		return max_length;
    }
};

// Algo2
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
		int max_length = 1;
		int cur_length = 1;
		int prev_value = nums[0];
		for (size_t i = 1; i < nums.size(); ++i) {
		    if (nums[i]+1 == prev_value) {
		        cur_length++;
		    } else if (nums[i] != prev_value) {
		        max_length = max(max_length, cur_length);
		        cur_length = 1;
		    }
		    prev_value = nums[i];
		}
		return max(max_length, cur_length);
    }
};

