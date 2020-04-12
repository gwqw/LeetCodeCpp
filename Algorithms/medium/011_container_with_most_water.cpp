/**
    11. Container With Most Water
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, 
such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Example:
Input: [1,8,6,2,5,4,8,3,7]
Output: 49

Algo: 2 pointers: O(N) + O(1)
- make max_height
- use 2 pointers: i=0, j=n-1
- calc cur_ares
- update max_area
- move pointer for shorter line (because if we move longer line we won'ty obtain more area, cause it's restricted by shorter line)

*/

class Solution {
public:
    int maxArea(const vector<int>& heights) {
        if (heights.empty()) return 0;
        size_t i = 0;
        size_t j = heights.size()-1;
        int max_area = 0;
        while (i < j) {
            int min_height = min(heights[i], heights[j]);
            int cur_area = (j - i) * min_height;
            if (cur_area > max_area) max_area = cur_area;
            if (min_height == heights[i]) {
                ++i;
            } else {
                --j;
            }
        }
        return max_area;
    }
};
