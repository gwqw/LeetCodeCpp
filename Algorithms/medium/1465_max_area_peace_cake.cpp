/**
    1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:
- horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
- verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 10^9 + 7.

Example 1:
Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
Output: 4 
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.

Example 2:
Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
Output: 6
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.

Example 3:
Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
Output: 9

Constraints:
2 <= h, w <= 10^9
1 <= horizontalCuts.length <= min(h - 1, 10^5)
1 <= verticalCuts.length <= min(w - 1, 10^5)
1 <= horizontalCuts[i] < h
1 <= verticalCuts[i] < w
All the elements in horizontalCuts are distinct.
All the elements in verticalCuts are distinct.

Algo: find max width and max height, so area will be max: O(N + M)

*/

class Solution {
    static constexpr int P = 1'000'000'000+7;
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        uint64_t max_h = 0, max_w = 0;
        int prev = 0;
        for (int hc : horizontalCuts) {
            max_h = max(max_h, uint64_t(hc - prev));
            prev = hc;
        }
        max_h = max(max_h, uint64_t(h - prev)) % P;
        prev = 0;
        for (int vc : verticalCuts) {
            max_w = max(max_w, uint64_t(vc - prev));
            prev = vc;
        }
        max_w = max(max_w, uint64_t(w - prev)) % P;
        
        return static_cast<int>((max_w * max_h) % P);
    }
};
