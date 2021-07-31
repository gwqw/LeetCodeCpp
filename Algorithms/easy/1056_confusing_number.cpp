/**
    1056. Confusing Number
Given a number n, return true if and only if it is a confusing number, which satisfies the following condition:
We can rotate digits by 180 degrees to form new digits. When 0, 1, 6, 8, 9 are rotated 180 degrees, they become 0, 1, 9, 8, 6 respectively. When 2, 3, 4, 5 and 7 are rotated 180 degrees, they become invalid. A confusing number is a number that when rotated 180 degrees becomes a different number with each digit valid.

Example 1:
Input: n = 6
Output: true
Explanation: 
We get 9 after rotating 6, 9 is a valid number and 9!=6.

Example 2:
Input: n = 89
Output: true
Explanation: 
We get 68 after rotating 89, 86 is a valid number and 86!=89.

Example 3:
Input: n = 11
Output: false
Explanation: 
We get 11 after rotating 11, 11 is a valid number but the value remains the same, thus 11 is not a confusing number.

Example 4:
Input: n = 25
Output: false
Explanation: 
We get an invalid number after rotating 25.

Note:
0 <= n <= 10^9
After the rotation we can ignore leading zeros, for example if after rotation we have 0008 then this number is considered as just 8.
*/

class Solution {
public:
    bool confusingNumber(int n) {
		int orig = n;
		int rot_num = 0;
        while (n > 0) {
			int d = n % 10;
			n /= 10;
			d = rotateDigit(d);
			if (d == -1) return false;
			rot_num= rot_num * 10 + d;
		}
		return rot_num != orig;
    }
	
private:
	int rotateDigit(int d) {
		if (!(d == 0 || d == 1 || d == 9 || d == 8 || d == 6)) return -1;
		if (d == 0 || d == 8 || d == 1) return d;
		if (d == 6) return 9;
		if (d == 9) return 6;
		return -1;
	}
};