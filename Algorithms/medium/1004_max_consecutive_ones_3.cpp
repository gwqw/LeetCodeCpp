/**
    1004. Max Consecutive Ones III
Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
Return the length of the longest (contiguous) subarray that contains only 1s. 

Example 1:
Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
Output: 6
Explanation: 
[1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.

Example 2:
Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
Output: 10
Explanation: 
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.

Note:
1 <= A.length <= 20000
0 <= K <= A.length
A[i] is 0 or 1 

Algo: sliding window: O(N) + O(1)
- have l = 0, r = 0
- k <- cap
- go forward and count 1 and 0:
    if zc == k:
        move l and substract 0 and 1

*/

class Solution {
public:
    int longestOnes(const vector<int>& a, int k) {
        int zeroes = 0;
        int ones = 0;
        size_t l = 0;
        size_t r = 0;
        int max_ones = 0;
        while (r < a.size()) {
            if (a[r] == 1) {
                ++ones;
            } else {
                ++zeroes;
                if (zeroes > k) {
                    max_ones = max(max_ones, ones + k);
                    while (zeroes > k) {
                        if (a[l] == 1) {
                            --ones;
                        } else {
                            --zeroes;
                        }
                        ++l;
                    }
                }
            }
            ++r;
        }
        zeroes = min(zeroes, k);
        return max(max_ones, ones + zeroes);
    }
};