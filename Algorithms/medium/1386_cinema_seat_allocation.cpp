/**
    1386. Cinema Seat Allocation
A cinema has n rows of seats, numbered from 1 to n and there are ten seats in each row, labelled from 1 to 10 as shown in the figure above.

Given the array reservedSeats containing the numbers of seats already reserved, for example, reservedSeats[i] = [3,8] means the seat located in row 3 and labelled with 8 is already reserved.

Return the maximum number of four-person groups you can assign on the cinema seats. A four-person group occupies four adjacent seats in one single row. Seats across an aisle (such as [3,3] and [3,4]) are not considered to be adjacent, but there is an exceptional case on which an aisle split a four-person group, in that case, the aisle split a four-person group in the middle, which means to have two people on each side.

Example 1:
Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
Output: 4
Explanation: The figure above shows the optimal allocation for four groups, where seats mark with blue are already reserved and contiguous seats mark with orange are for one group.

Example 2:
Input: n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
Output: 2

Example 3:
Input: n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
Output: 4

Constraints:
1 <= n <= 10^9
1 <= reservedSeats.length <= min(10*n, 10^4)
reservedSeats[i].length == 2
1 <= reservedSeats[i][0] <= n
1 <= reservedSeats[i][1] <= 10
All reservedSeats[i] are distinct.

Algo: count places in reserved and add free
reserved: dict[row] -> {cols}
better: dict[row] -> {pairs} p1 = !(2 or 3), p2 = !(4 or 5), p3 = !(6 or 7), p4 = !(8 or 9)
for _, c:
    if not 1 and 2: cnt += 1
    if not 2 and 3: cnt += 1
    if not 3 and 4: cnt += 1
cnt += (n - dict.size()) * 3

*/

class Solution {
public:
    int maxNumberOfFamilies(int n, const vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> reserved;
        for (const auto& seat : reservedSeats) {
            auto p = makep(seat[1]);
            if (p != 0) {
                reserved[seat[0]].insert(p);
            }
        }
        // count in reserved
        int cnt = 0;
        for (const auto& [_,row_set] : reserved) {
            bool p1 = !row_set.count(1);
            bool p2 = !row_set.count(2);
            bool p3 = !row_set.count(3);
            bool p4 = !row_set.count(4);
            if (p1 && p2 && p3 && p4) {
                cnt += 2;
            } else if (p1 && p2) {
                ++cnt;
            } else if (p2 && p3) {
                ++cnt;
            } else if (p3 && p4) {
                ++cnt;
            }
        }
        cnt += (n - (int)reserved.size()) * 2;
        return cnt;
    }
    
private:
    int makep(int n) {
        if (n == 2 || n == 3) return 1;
        if (n == 4 || n == 5) return 2;
        if (n == 6 || n == 7) return 3;
        if (n == 8 || n == 9) return 4;
        return 0;
    }
};