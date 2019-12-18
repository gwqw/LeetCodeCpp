/**
    268. Missing Number

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, 
find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

Algo1: naive: O(N) + O(N)
- have same size vector<bool>
- go through first and set to true value in second with right idx
- go through second and find this value

Algo2: radix sort O(N) + O(1)
- inc size by 1 and set -1 value here (or can be wo resizing)
- for i in range(n):
    - if n[i] != -1 && n[i] != i: swap n[i], n[n[i]] // n[i] != n.size()
- for all values search -1

Algo3: xor all values and indexes+1. O(N) + O(1)

Algo4: sum all values, sum all indexes + size (formula can be used) and substract: s - f. O(N) + O(1)

*/

class Solution {
public:
    int missingNumber(const vector<int>& nums) {
        vector<bool> is_in(nums.size()+1, false);
        for (auto n : nums) {
            is_in[n] = true;
        }
        for (int i = 0; i < (int)is_in.size(); ++i) {
            if (!is_in[i]) return i;
        }
        throw runtime_error("Something goes wrong");
    }
};

class Solution {
public:
    int missingNumber(vector<int>& n) {
        n.push_back(-1);
        for (int i = 0; i < (int)n.size(); ++i) {
            while (n[i] != -1 && n[i] != i) {
                swap(n[i], n[n[i]]);
            }
        }
        
        for (int i = 0; i < (int)n.size(); ++i) {
            if (n[i] != i) return i;
        }
        throw runtime_error("Something goes wrong");
    }
};
class Solution {
public:
    int missingNumber(vector<int>& n) {
        for (int i = 0; i < (int)n.size(); ++i) {
            while (n[i] != n.size() && n[i] != i) {
                swap(n[i], n[n[i]]);
            }
        }
        
        for (int i = 0; i < (int)n.size(); ++i) {
            if (n[i] != i) return i;
        }
        return n.size();
    }
};

class Solution {
public:
    int missingNumber(const vector<int>& n) {
        int res = (int)n.size();
        
        for (int i = 0; i < (int)n.size(); ++i) {
            res ^= i ^ n[i];
        }
        
        return res;
    }
};

class Solution {
public:
    int missingNumber(const vector<int>& nums) {
        int res = (int)nums.size();
        res = (res * (res+1)) / 2;
        
        for (auto n : nums) {
            res -= n;
        }
        
        return res;
    }
};


