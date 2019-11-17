/**
	868. Binary Gap

Given a positive integer N, find and return the longest distance between two 
consecutive 1's in the binary representation of N.
If there aren't two consecutive 1's, return 0.

Example 1:
Input: 22
Output: 2
Explanation: 
22 in binary is 0b10110.
In the binary representation of 22, there are three ones, and two consecutive pairs of 1's.
The first consecutive pair of 1's have distance 2.
The second consecutive pair of 1's have distance 1.
The answer is the largest of these two distances, which is 2.

Example 2:
Input: 5
Output: 2
Explanation: 
5 in binary is 0b101.

Example 3:
Input: 6
Output: 1
Explanation: 
6 in binary is 0b110.

Example 4:
Input: 8
Output: 0
Explanation: 
8 in binary is 0b1000.
There aren't any consecutive pairs of 1's in the binary representation of 8, so we return 0.

Note:
1 <= N <= 10^9

101010001001
^ ^ ^   ^  ^
Algo1:
- find prev
- find cur
while (!end)
    find next : if !check_bit(num, n):
    cur, prev = pos, cur
    dist = renew_dist(cur - prev)

Algo2:
100010001000 n
010001000100 n >> 1
110011001100 n |= n >> 1
Итого уменьшаем число 00 подряд на 1

Нужно убрать последнии 00, т.к. они будут мешать
10000 n
01111 n-1
11111 n | n-1


*/

class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int cur = -1;
        int pos = 0;
        for (; pos < 31; ++pos) {
            if (check_bit(n, pos)) {
                if (prev == -1) {
                    prev = pos;
                    continue;
                } else if (cur == -1) {
                    cur = pos;
                    break;
                }
            }
        }
        
        if (cur == -1) return 0;
        int dist = cur - prev;
        for (pos = cur + 1; pos < 31; ++pos) {
            if (!check_bit(n, pos)) continue;
            prev = cur;
            cur = pos;
            if (dist < cur - prev) dist = cur - prev;
        }
        return dist;
    }
private:
    static bool check_bit(int num, int pos) {
        return num & (1 << pos);
    }
};

