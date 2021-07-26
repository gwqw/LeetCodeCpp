/**
    1470. Shuffle the Array
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
Return the array in the form [x1,y1,x2,y2,...,xn,yn].

Example 1:
Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7] 
Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].

Example 2:
Input: nums = [1,2,3,4,4,3,2,1], n = 4
Output: [1,4,2,3,3,2,4,1]

Example 3:
Input: nums = [1,1,2,2], n = 2
Output: [1,2,1,2]

Constraints:
1 <= n <= 500
nums.length == 2n
1 <= nums[i] <= 10^3

Algo: simple print

Algo2: inplace
make -num for swaped on its place
remember number idx for swap and calc new idx

*/

class Solution {
public:
    vector<int> shuffle(const vector<int>& nums, int n) {
        vector<int> res;
        res.reserve(nums.size());
        for (size_t i = 0, j = n; i < n && j < nums.size(); ++i, ++j) {
            res.push_back(nums[i]);
            res.push_back(nums[j]);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> shuffle(vector<int>& a, int n) {
        for (size_t i = 0; i < a.size(); ++i) {
            size_t from_pos = i;
            while (a[i] >= 0) {
                size_t to_pos = calcNewIdx(from_pos, n);
                swap(a[i], a[to_pos]);
                a[to_pos] = -a[to_pos];
                from_pos = to_pos;
            }
        }
        for (auto& num : a) {
            num = -num;
        }
        return move(a);
    }
    
private:
    static size_t calcNewIdx(size_t i, int n) {
        return i < n ? 2*i : 2*(i-n)+1;
    }
};