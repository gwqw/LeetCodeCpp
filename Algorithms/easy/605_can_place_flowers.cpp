/**
    605. Can Place Flowers
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: false

Constraints:
1 <= flowerbed.length <= 2 * 10^4
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length

Algo: count 0s
0, 00 -> 0
000 -> 1
0000 -> 1
00000 -> 2
rule: (n-1) / 2 or n / 2 if edge
*/

class Solution {
public:
    bool canPlaceFlowers(const vector<int>& flowerbed, int n) {
        int zc = 0;
		bool is_start = flowerbed[0] == 0;
		for (char p : flowerbed) {
			if (p == 0) {
				++zc;
			} else if (zc > 0) {
				n -= is_start ? zc / 2 : (zc-1) / 2;
				if (n <= 0) return true;
				is_start = false;
				zc = 0;
			} else {
			    is_start = false;
			}
		}
		if (zc > 0) n -= is_start ? (zc+1)/2 : zc/2;
		return n <= 0;
    }
};
