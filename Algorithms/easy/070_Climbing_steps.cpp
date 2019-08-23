/**
70. Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Note: Given n will be a positive integer.
Example 1:
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Algo:
l1 = 1
l2 = 0
for i in range(1, n):
  t = l2
  l2 = l1
  l1 += t
return l1 + l2

O(N), O(1) mem
*/

class Solution {
public:
    int climbStairs(int n) {
      int64_t l1 = 1, l2 = 0;
      for (int i = 1; i < n; ++i) {
        int64_t t = l2;
        l2 = l1;
        l1 += t;
      }
      return l1 + l2;
    }
};
