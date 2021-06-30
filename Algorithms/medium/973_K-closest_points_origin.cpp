/**
    973. K Closest Points to Origin
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

Example 1:
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

Example 2:
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.

Constraints:
1 <= k <= points.length <= 10^4
-10^4 < xi, yi < 10^4

Algo1: sort with special operator

Algo2: nth_element with special operator

*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if (points.size() <= k) return points;
        sort(points.begin(), points.end(), 
            [](const auto& lhs, const auto& rhs){
                int64_t dst1 = lhs[0]*lhs[0] + lhs[1]*lhs[1];
                int64_t dst2 = rhs[0]*rhs[0] + rhs[1]*rhs[1];
                return dst1 < dst2;
            }
        );
        points.resize(k);
        return points;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if (points.size() <= k) return points;
        nth_element(points.begin(), points.begin()+k-1, points.end(), 
            [](const auto& lhs, const auto& rhs){
                int64_t dst1 = lhs[0]*lhs[0] + lhs[1]*lhs[1];
                int64_t dst2 = rhs[0]*rhs[0] + rhs[1]*rhs[1];
                return dst1 < dst2;
            }
        );
        points.resize(k);
        return points;
    }
};

