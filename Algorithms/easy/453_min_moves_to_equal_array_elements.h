/**
   453. Minimum Moves to Equal Array Elements
Given a non-empty integer array of size n, 
find the minimum number of moves required to make all array elements equal, 
where a move is incrementing n - 1 elements by 1.

Example:
Input:
[1,2,3]
Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

Algo:
min = O(N)
diff += (a[i] - min)
return diff

Solution: inc (n-1) element => inc all and dec 1 => dec 1
So solution -- minimize dec to equal: find min and find sum of diffs

Descr:
inc 1-st => decrease difference from 1-st on n-1
inc n-2  => increase difference from 1-st on n-2
total: sum diff decrease on 1

1 2 3   0 1 2  
2 3 3   0 1 1  
3 4 3   0 1 0  
4 4 4   0 0 0

1 2 2   0 1 1
2 2 3   0 0 1
3 3 3   0 0 0

1 1 3   0 0 2
2 2 3   0 0 1
3 3 3   0 0 0

1 1 2 2   0 0 1 1        
2 2 2 3   0 0 0 1
3 3 3 3   0 0 0 0

1 1 2 3   0 0 1 2
2 2 3 3   0 0 1 1
3 3 3 4   0 0 0 1
4 4 4 4   0 0 0 0

1 2 3 4   0 1 2 3
2 3 4 4   0 1 2 2
3 4 4 5   0 1 1 2
4 5 5 5   0 1 1 1
5 5 6 6   0 0 1 1
6 6 6 7   0 0 0 1
7 7 7 7   0 0 0 0

*/

class Solution {
public:
    int minMoves(const vector<int>& nums) {
        int m = *(min_element(nums.begin(), nums.end()));
        return accumulate(nums.begin(), nums.end(), 0, [m](int d, int val){return d+= val - m;});
        int diff = 0;
        for (auto n : nums) {
            diff += n - m;
        }
        return diff;
    }
};
