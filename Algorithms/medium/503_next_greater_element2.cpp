/**
    503. Next Greater Element II
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

Example 1:
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.

Example 2:
Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]

Constraints:
1 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9

Algo1: monotinic stack 2 pass (may be short scheme), O(N), O(N)mem
1st pass (classic) from the end
2nd go while same value

Algo2: same but use i=2*n and use nums[i % n]

*/

class Solution {
public:
    vector<int> nextGreaterElements(const vector<int>& nums) {
        stack<int> st;
        vector<int> res(nums.size());
        // 1st pass
        for (size_t i = nums.size(); i-->0; ) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }
        // 2nd pass
        for (size_t i = nums.size(); i-->0; ) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(const vector<int>& nums) {
        stack<int> st;
        vector<int> res(nums.size());
        int mo_cnt = 0;
        // 1st pass
        for (size_t i = nums.size(); i-->0; ) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
            if (res[i] == -1) ++mo_cnt;
        }
        // 2nd pass
        for (size_t i = nums.size(); i-->0; ) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            if (res[i] == -1) --mo_cnt;
            res[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
            if (mo_cnt <= 0) break;
        }
        return res;
    }
};