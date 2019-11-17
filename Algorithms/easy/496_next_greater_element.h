/**
    496. Next Greater Element I
You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. 
Find all the next greater numbers for nums1's elements in the corresponding places of nums2.
The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. 
If it does not exist, output -1 for this number.

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
    
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.

Short descr:
for every element in nums1:
    - find this element in nums2
    - find el2 > element and righter than element in nums2
    
Algo1: O(N^2) + O(1)
- for n in num1
    - find pos, n in num2
    - find n2: n < n2 in pos, end

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



