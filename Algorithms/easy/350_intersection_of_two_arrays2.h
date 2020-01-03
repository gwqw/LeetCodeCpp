/**
    350. Intersection of Two Arrays II
Given two arrays, write a function to compute their intersection.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, 
and the memory is limited such that you cannot load all elements into the memory at once?

Algo1: naive O(N+M) amortized + O(M)
make dicts from nums2: num -> count (good idea -- make dict from shorter array)
go through nums1 
    search num in dict
    if found and count > 0:
        push to res

Algo2: for sorted O(N+M) + O(1)
two itterators:
for (it1):
    while (*it2 < *it1): ++it2;
    if *it1 == *it2:
        insert(*it);
        ++it2;

Algo3: for nums1 on disk: O(N+M) + O(1)
- for every n in nums1 find in nums2:
    if n in nums2:
        insert(n)
        remove(n) in nums2 for O(1)

*/

class Solution {
public:
    vector<int> intersect(const vector<int>& nums1, const vector<int>& nums2) {
        unordered_map<int, int> d;
        //if (nums1.size() < nums2.size()) {
        //    swap(nums1, nums2);
        //}
        for (auto n : nums2) {
            ++d[n];
        }
        vector<int> res;
        res.reserve(d.size());
        for (auto n : nums1) {
            if (auto it = d.find(n); it != d.end() && it->second > 0) {
                res.push_back(n);
                --it->second;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        auto it2 = nums2.begin();
        for (auto it1 = nums1.begin(); it1 < nums1.end(); ++it1) {
            while (it2 != nums2.end() && *it2 < *it1) ++it2;
            if (it2 == nums2.end()) break;
            if (*it1 == *it2) {
                res.push_back(*it1);
                ++it2;
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        set_intersection(nums1.begin(), nums1.end(), 
            nums2.begin(), nums2.end(), 
            back_inserter(res)
        );
        return res;
    }
};

class Solution {
public:
    vector<int> intersect(const vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for (auto n : nums1) {
            if (auto it = find(nums2.begin(), nums2.end(), n); it != nums2.end()) {
                res.push_back(n);
                if (it != prev(nums2.end())) {
                    swap(*it, *prev(nums2.end()));
                }
                nums2.pop_back();
            }
        }
        return res;
    }
};
