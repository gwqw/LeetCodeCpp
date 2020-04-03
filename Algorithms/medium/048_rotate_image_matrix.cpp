/**
    48. Rotate Image
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).

Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:
Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],
rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

Example 2:
Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 
rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

Algo: calc new pos for every element O(N^2) + O(1)

1     2


4     3

0: 1 -> t
1: 4 -> 1
2: 3 -> 4
3: 2 -> 3
4: t -> 2
a[r][c]
1->2: a[i][j] -> a[j][n-1-i]        a[j][n-1-i]
2->3: a[i][j] -> a[j][n-1-i]        a[n-1-i][n-1-j]
3->4: a[i][j] -> a[j][n-1-i]        a[n-1-j][i]
4->1: a[i][j] -> a[j][n-1-i]        a[i][j]

i from [0,n/2)
j from [i, n-i)


*/

class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        size_t n = a.size();
        for (size_t i = 0; i < n/2; ++i) {
            for (size_t j = i; j < n-i-1; ++j) {
                int t = a[i][j];
                a[i][j] = a[n-1-j][i];
                a[n-1-j][i] = a[n-1-i][n-1-j];
                a[n-1-i][n-1-j] = a[j][n-1-i];
                a[j][n-1-i] = t;
            }
        }
    }
};

/*


*/

