/**
    179. Largest Number
Given a list of non-negative integers nums, arrange them such that they form the largest number.
Note: The result may be very large, so you need to return a string instead of an integer.

Example 1:
Input: nums = [10,2]
Output: "210"

Example 2:
Input: nums = [3,30,34,5,9]
Output: "9534330"

Example 3:
Input: nums = [1]
Output: "1"

Example 4:
Input: nums = [10]
Output: "10"

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 10^9

Algo1: O(RlogR) R - res.size()
nums -> string
lexeg.sort
join from max
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        str.reserve(nums.size());
        size_t sze = 0;
        for (auto n : nums) {
            str.push_back(to_string(n));
            sze += str.back().size();
        }
        
        sort(str.begin(), str.end(), 
            [](const auto& lhs, const auto& rhs) {
                string l = lhs + rhs;
                string r = rhs + lhs;
                return l > r;               
            });
        
        string res;
        res.reserve(sze);
        for (auto& s : str) {
            if (res != "0") {
                res += move(s);
            }
        }
        return res;
    }
};
