/**
    75. Sort Colors
Given an array with n objects colored red, white or blue, 
sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
Note: You are not suppose to use the library's sort function for this problem.

Example:
Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?

Algo1: naive counting sort: O(N) + O(1)
- go through array and count 0, 1, 2
- make sort array

Algo2: 
- we have end_pos for 0: ze = 0
- we have before start pos for 2: ts = n-1
- go through array i in [ze,ts]:
    if a[i] == 0: 
        swap(a[ze], a[i])
        ze++
    elif a[i] == 2: 
        swap(a[ts], a[i])
        --ts
    else: do nothing
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        size_t zeroes = 0, ones = 0, twos = 0;
        for (auto n : nums) {
            if (n == 0) {
                ++zeroes;
            } else if (n == 1) {
                ++ones;
            } else {
                ++twos;
            }
        }
        size_t f = 0;
        while (zeroes > 0) {
            nums[f++] = 0;
            --zeroes;
        }
        while (ones > 0) {
            nums[f++] = 1;
            --ones;
        }
        while (twos > 0) {
            nums[f++] = 2;
            --twos;
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& a) {
        if (a.size() <= 1) return;
        size_t ze = 0, ts = a.size()-1;
        size_t i = ze;
        while (i <= ts) {
            if (a[i] == 0) {
                swap(a[i], a[ze]);
                ++ze;
            } else if (a[i] == 2) {
                swap(a[i], a[ts]);
                if (ts == 0) return;
                --ts;
            } else {
                ++i;
            }
        }
    }
};
