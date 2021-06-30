/**
    496. Next Greater Element I
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
    
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
    
Constraints:
1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 10^4
All integers in nums1 and nums2 are unique.
All the integers of nums1 also appear in nums2.

Short descr:
for every element in nums1:
    - find this element in nums2
    - find el2 > element and righter than element in nums2
    
Algo1: O(N^2) + O(1)
for n in num1
    find idx for n in num2
    find n2: n < n2 in (idx, end)

Algo2: O(N^2) + O(N)
make dict[num]->idx from nums2
for n in num1
    find idx for n in dict
    find n2: n < n2 in (idx, end)

Algo2: O(N) + O(N)
-        

*/

class Solution {
public:
    vector<int> nextGreaterElement(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> res;
        if (nums2.size() <= 1) return res;
        unordered_map<int, int> dict;
        stack<int> st;
        for (auto n : nums2) {  // O(N)
            if (st.empty()) {
                st.push(n);
            } else {
                while (!st.empty() && st.top() < n) {
                    dict[st.top()] = n;
                    st.pop();
                }
                st.push(n);
            }
        }
        res.reserve(nums1.size());
        for (auto n : nums1) {  // O(N)
            if (auto it = dict.find(n); it != dict.end()) {
                res.push_back(it->second);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};



