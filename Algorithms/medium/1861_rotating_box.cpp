/**
    1861. Rotating the Box
You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:

A stone '#'
A stationary obstacle '*'
Empty '.'
The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box.

Return an n x m matrix representing the box after the rotation described above.

Example 1:
Input: box = [["#",".","#"]]
Output: [["."],
         ["#"],
         ["#"]]

Example 2:

Input: box = [["#",".","*","."],
              ["#","#","*","."]]
Output: [["#","."],
         ["#","#"],
         ["*","*"],
         [".","."]]

Example 3:
Input: box = [["#","#","*",".","*","."],
              ["#","#","#","*",".","."],
              ["#","#","#",".","#","."]]
Output: [[".","#","#"],
         [".","#","#"],
         ["#","#","*"],
         ["#","*","."],
         ["#",".","*"],
         ["#",".","."]]
 

Constraints:
m == box.length
n == box[i].length
1 <= m, n <= 500
box[i][j] is either '#', '*', or '.'.

Algo: stable partition for row: O(n*m), O(n*m)answer
- make stable partition for all rows i to '*' pos and after
- rotate box
*/

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        // partition
        for (auto& row : box) {
            auto bit = row.begin();
            auto eit = find(bit, row.end(), '*');
            while (true) {
                stable_partition(bit, eit, [](char c){return c == '.';});
                if (eit == row.end()) break;
                bit = eit+1;
                eit = find(bit, row.end(), '*');
            }
        }
        // rotate
        vector<vector<char>> res(box[0].size(), vector<char>(box.size()));
        for (size_t i = 0; i < res.size(); ++i) {
            for (size_t j = 0; j < res[0].size(); ++j) {
                res[i][j] = box[res[0].size()-1-j][i];
            }
        }
        return res;
    }
};