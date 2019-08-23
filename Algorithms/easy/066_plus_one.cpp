/**
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:
Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:
Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

Example 3:
Input: [0]
Output: [1]

Example 3:
Input: [9,9]
Output: [1,0,0]

Algo:
rb = true
for i = size-1 to 0:
	if v[i] == 9;
		v[i] = 0
		rb = true
	else:
		v[i] += 1
		rb = false
		break
if rb:
	v.insert(0, 1)
return v
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		for (auto it = rbegin(digits); it != rend(digits); ++it) {
			if (*it == 9) {
				*it = 0;
			} else {
				++(*it);
				return digits;
			}
		}
		digits.insert(begin(digits), 1);
		return digits;
    }
};
