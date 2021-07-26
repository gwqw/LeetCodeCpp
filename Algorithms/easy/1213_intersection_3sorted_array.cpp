/**
    1213. Intersection of Three Sorted Arrays
Given three integer arrays arr1, arr2 and arr3 sorted in strictly increasing order, return a sorted array of only the integers that appeared in all three arrays.

Example 1:
Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
Output: [1,5]
Explanation: Only 1 and 5 appeared in the three arrays.

Example 2:
Input: arr1 = [197,418,523,876,1356], arr2 = [501,880,1593,1710,1870], arr3 = [521,682,1337,1395,1764]
Output: []

Constraints:
1 <= arr1.length, arr2.length, arr3.length <= 1000
1 <= arr1[i], arr2[i], arr3[i] <= 2000

Algo:
itterate through first
    - find i in second
    - find i in third
    ...
*/

class Solution {
public:
    vector<int> arraysIntersection(const vector<int>& a0, 
        const vector<int>& a1, const vector<int>& a2) 
    {
        vector<int> res;
        size_t i1 = 0, i2 = 0;
        for (size_t i = 0; i < a0.size(); ++i) {
            int val = a0[i];
            // i1
            while (i1 < a1.size() && a1[i1] < val) {
                ++i1;
            }
            if (i1 == a1.size()) break;
            if (a1[i1] != val) continue;
            // i2
            while (i2 < a2.size() && a2[i2] < val) {
                ++i2;
            }
            if (i2 == a2.size()) break;
            if (a2[i2] != val) continue;
            
            // res
            res.push_back(val);
        }
        return res;
    }
};

// for k
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& a0, 
        vector<int>& a1, vector<int>& a2) 
    {
        constexpr int k = 3;
        vector<int> res;
        array<size_t, k> idxs{0};
        array<vector<int>, k> a{move(a0), move(a1), move(a2)};
        for (size_t i = 0; i < a[0].size(); ++i) {
            int val = a[0][i];
            bool all_good = true;
            for (int j = 1; j < (int)a.size(); ++j) {
                while (idxs[j] < a[j].size() && a[j][idxs[j]] < val) {
                    ++idxs[j];
                }
                if (idxs[j] == a[j].size()) return res;
                if (a[j][idxs[j]] != val) {
                    all_good = false;
                    break;
                }
            }
            
            // res
            if (all_good) {
                res.push_back(val);
            }
        }
        return res;
    }
};


