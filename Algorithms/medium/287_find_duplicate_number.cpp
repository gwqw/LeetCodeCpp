/**
    287. Find the Duplicate Number
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. 
Assume that there is only one duplicate number, find the duplicate one.

Example 1:
Input: [1,3,4,2,2]
Output: 2

Example 2:
Input: [3,1,3,4,2]
Output: 3

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

Algo:

A 1 i k
B 1 i i
C 1^2 i^2 k^2
D 1^2 i^2 i^2
 
D1 = A - B = k-i
C - D = k^2-i^2 = (k-i)(k+i)
D2 = (C-D)/(A-B) = k+i
k = (D1+D2)/2
i = (D2 - D1)/2
*/

class Solution {
public:
    int findDuplicate(const vector<int>& nums) {
        
    }
};