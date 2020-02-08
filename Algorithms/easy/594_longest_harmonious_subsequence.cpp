/**
    594. Longest Harmonious Subsequence
We define a harmounious array as an array 
where the difference between its maximum value and its minimum value is exactly 1.
Now, given an integer array, you need to find the length of its longest harmonious 
subsequence among all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].

Note: The length of the input array will not exceed 20,000.

Algo1: use dict O(NlogN) + O(N), O(N)amortized + O(N)
- dict: num -> count
- go through array and add values to dict
- go through the dict and cmp near sums
- and update max

Algo2: sort: O(NlogN) + O(logN)


*/

class Solution {
public:
    int findLHS(const vector<int>& nums) {
        map<int, int> n2c;
        for (auto n : nums) {
            ++n2c[n];
        }
        int max_sum = 0;
        int cur_sum = 0;
        int prev_value = 0;
        for (auto it = n2c.begin(); it != n2c.end(); ++it) {
            if (it != n2c.begin() && it->first - prev_value == 1) {
                cur_sum += it->second;
                max_sum = max(cur_sum, max_sum);
            }
            prev_value = it->first;
            cur_sum = it->second;
        }
        return max_sum;
    }
};
class Solution {
public:
    int findLHS(const vector<int>& nums) {
        unordered_map<int, int> n2c;
        for (auto n : nums) {
            ++n2c[n];
        }
        int max_sum = 0;
        for (auto [n, c] : n2c) {
            if (auto it = n2c.find(n+1); it != n2c.end()) {
                if (c + it->second > max_sum) max_sum = c + it->second;
            }
        }
        return max_sum;
    }
};

class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        
        int max_sum = 0;
        int prev_sum = 0;
        int cur_value = nums.front();
        int cur_sum = 1;
        for (auto it = next(nums.begin()); it != nums.end(); ++it) {
            if (*it == cur_value) {
                ++cur_sum;
            } else {
                if (prev_sum) {
                    max_sum = max(max_sum, prev_sum + cur_sum);
                }
                if (*it == cur_value+1) {
                    prev_sum = cur_sum;
                } else {
                    prev_sum = 0;
                }
                cur_value = *it;
                cur_sum = 1;
            }
        }
        if (prev_sum) {
            max_sum = max(max_sum, prev_sum + cur_sum);
        }
        return max_sum;
    }
};




