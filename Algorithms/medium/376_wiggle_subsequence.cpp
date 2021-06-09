/**
    376. Wiggle Subsequence
A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

Given an integer array nums, return the length of the longest wiggle subsequence of nums.

Example 1:
Input: nums = [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).

Example 2:
Input: nums = [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length.
One is [1, 17, 10, 13, 10, 16, 8] with differences (16, -7, 3, -3, 6, -8).

Example 3:
Input: nums = [1,2,3,4,5,6,7,8,9]
Output: 2

Constraints:
1 <= nums.length <= 1000
0 <= nums[i] <= 1000

Follow up: Could you solve this in O(n) time?

Algo: greedy: take only vertexes: O(N), O(1)mem
\
 \/\/\
4 3 2 3 1 4 2
 -1 -1 1 -2 3 -2
 
strategy: 
- if we have \\ or // -- take 1-st and last
- or the same is: take points at vertex


*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(const vector<int>& nums) {
		if (nums.size() <= 1) return nums.size();
        // search first change
		bool is_raise = false;
		int prev_num = nums[0];
		int b = 1;
		for (; b < (int)nums.size(); ++b) {
		    if (prev_num < nums[b]) {
		        is_raise = true;
		        break;
		    }
		    if (prev_num > nums[b]) {
		        is_raise = false;
		        break;
		    }
	    }
	    if (b == (int)nums.size()) return 1;
	    
		prev_num = nums[b];
		int cur_length = 2;
		for (int i = b+1; i < (int)nums.size(); ++i) {
			if (is_raise && prev_num > nums[i]) {
				is_raise = false;
				cur_length++;
			} else if (!is_raise && prev_num < nums[i]) {
				is_raise = true;
				cur_length++;
			}
			prev_num = nums[i];
		}
		return cur_length;
    }
};

class Solution {
public:
    int wiggleMaxLength(const vector<int>& nums) {
		if (nums.size() <= 1) return nums.size();
        int dir = 0;
		int prev_num = nums[0];
		int cur_length = 1;
		for (int i = 1; i < (int)nums.size(); ++i) {
			if (dir > 0 && prev_num > nums[i]) {
				dir = -1;
				cur_length++;
			} else if (dir < 0 && prev_num < nums[i]) {
				dir = 1;
				cur_length++;
			} else if (dir == 0) {
			    if (prev_num < nums[i]) {
			        dir = 1;
			        cur_length++;
		        }
			    if (prev_num > nums[i]) {
			        dir = -1;
			        cur_length++;
		        }
			}
			prev_num = nums[i];
		}
		return cur_length;
    }
};

//    static vector<int> getWiggleSubsec(const vector<int>& nums) {
//		if (nums.size() <= 2) return nums;
//		vector<int> res(2);
//		res.reserve(nums.size());
//		res[0] = nums[0];
//		res[1] = nums[1];
//		bool is_raise = nums[1] > nums[0];
//		for (int i = 2; i < (int)nums.size(); ++i) {
//			if (is_raise && res.back() > nums[i]) {
//				is_raise = false;
//				res.push_back(nums[i]);
//			} else if (!is_raise && res.back() < nums[i]) {
//				is_raise = true;
//				res.push_back(nums[i]);
//			}
//			res.back() = nums[i];
//		}
//		return res;
//	}
//	
//	static bool isWiggle(const vector<int>& nums) {
//		if (nums.size() <= 2) return true;
//		int prev_num = nums[1];
//		bool is_raise = nums[1] > nums[0];
//		for (int i = 2; i < (int)nums.size(); ++i) {
//			if (is_raise && prev_num <= nums[i]) return false;
//			if (!is_raise && prev_num >= nums[i]) return false;
//			prev_num = nums[i];
//		}
//		return true;
//    }


void printVec(const vector<int> v, ostream& out) {
	for (auto n : v) {
		out << n << " ";
	}
	out << '\n';
}

int main() {
	{
		cout << "**\n";
		vector<int> a{1,7,4,9,2,5};
		auto res = Solution().getWiggleSubsec(a);
		printVec(res, cout);
		cout << res.size() << " " << Solution().isWiggle(res) << endl;
	}
	{
		cout << "**\n";
		vector<int> a{1,17,5,10,13,15,10,5,16,8};
		auto res = Solution().getWiggleSubsec(a);
		printVec(res, cout);
		cout << res.size() << " " << Solution().isWiggle(res) << endl;
	}
	{
		cout << "**\n";
		vector<int> a{1,2,3,4,5,6,7,8,9};
		auto res = Solution().getWiggleSubsec(a);
		printVec(res, cout);
		cout << res.size() << " " << Solution().isWiggle(res) << endl;
	}
	return 0;
}
