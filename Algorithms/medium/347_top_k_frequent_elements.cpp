/**
    347. Top K Frequent Elements
Given a non-empty array of integers, return the k most frequent elements.
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

Algo1: O(N + klogN) amortized, O(N)
- use dict value -> freq    O(N)
- make array of all unique elements with their frequencies O(N)
- use partial_sort with cmp function
- form result array

Algo2: the same but use nth-element, will be unordered: O(N) + O(N)

Algo3: freq. dict (as in Algo) and use reversed dict: dict<freq, value>
different frequencies ~sqrt(n)

*/

class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        unordered_map<int, size_t> dict;
        for (auto n : nums) {
            ++dict[n];
        }        
        vector<pair<int, size_t>> elements{dict.begin(), dict.end()};
        partial_sort(elements.begin(), elements.begin() + k, elements.end(),
            [](const auto& lhs, const auto& rhs){
                    return lhs.second > rhs.second;
                }
        );
        vector<int> res;
        res.reserve(k);
        for (auto it = elements.begin(); it != elements.begin() + k; ++it) {
            res.push_back(it->first);
        }
        return res;
    }
};
