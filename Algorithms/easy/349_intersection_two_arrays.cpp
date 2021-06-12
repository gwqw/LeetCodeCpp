/**
    349. Intersection of Two Arrays
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

Algo1: make_set and find intersection: O(N), O(N)mem
    return list(set(nums1) & set(nums2))
    
Algo2: sort arrays and insert to res. O(NlogN)
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1{nums1.begin(), nums1.end()};
        unordered_set<int> set2{nums2.begin(), nums2.end()};
        vector<int> res;
        res.reserve(max(set1.size(), set2.size()));
        for (int n : set1) {
            if (set2.count(n)) {
                res.push_back(n);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        res.reserve(max(nums1.size(), nums2.size()));
        for (size_t i = 0, j = 0; i < nums1.size() && j < nums2.size(); ) {
            if (nums1[i] == nums2[j]) {
                if (res.empty() || nums1[i] != res.back()) {
                    res.push_back(nums[i]);
                }
                ++i;
                ++j;
            } else if (nums1[i] < nums2[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return res;
    }
};
