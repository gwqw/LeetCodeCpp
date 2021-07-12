/**
    31. Next Permutation
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
The replacement must be in place and use only constant extra memory.

Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]

Example 3:
Input: nums = [1,1,5]
Output: [1,5,1]

Example 4:
Input: nums = [1]
Output: [1]

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 100

Algo:
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2

2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1

3 4 2 1

3 5 4 2 1
^     ^   

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = (int)nums.size()-1;
	    while (i > 0 && nums[i] <= nums[i-1]) {
		    --i;
	    }
	    // nothing to permute
	    if (i == 0) {
		    reverse(nums.begin(), nums.end());
		    return;
	    }
		--i;
		// search element to permute
		int j = (int)nums.size()-1;
		while (j > i && nums[j] <= nums[i]) {
			--j;
		}
		// swap i and j elements
		swap(nums[i], nums[j]);
		// reverse left part
		++i;
		if (i+1 != nums.size()) {
			reverse(nums.begin()+i, nums.end());
		}
    }
};


void printVector(const vector<int>& v) {
	for (auto n : v) {
		cout << n << " ";
	}
	cout << '\n';
}

int main() {
	Solution s;
	vector<int> v {1, 2, 3, 4};
	printVector(v);
	for (int i = 0; i < 25; ++i) {
		s.nextPermutation(v);
		printVector(v);
	}
	return 0;
}