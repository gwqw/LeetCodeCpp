/**
    136. Single Number

Given a non-empty array of integers, every element appears twice except for one. 
Find that single one.

Note:
Your algorithm should have a linear runtime complexity. 
Could you implement it without using extra memory?

Example 1:
Input: [2,2,1]
Output: 1

Example 2:
Input: [4,1,2,1,2]
Output: 4

Algo1: naive O(NlogN) + O(1)
- sort and go through array and find single number

Algo2: more complex: O(N) + O(N)
- array -> map[int, int]: key -- num, value -- counter
- find key with value == 1

Algo3: O(N) + O(1) xor all with 0 (num xor el xor el -> the same num)
- have var = 0
- go through array and xor element with var
- return var
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        auto it = nums.begin();
        while (it != nums.end()) {
            if (next(it) == nums.end() || *it != *next(it)) return *it;
            it += 2;
        }
        assert(false);
    }
};

class Solution {
public:
    int singleNumber(const vector<int>& nums) {
       std::unordered_map<int, int> dict;
       for (auto i : nums) {
           ++dict[i];
       }
       for (auto it = dict.begin(); it != dict.end(); ++it) {
           if (it->second == 1) {
               return it->first;
           }
       }
       assert(false);
    }
};

class Solution {
public:
    int singleNumber(const vector<int>& nums) {
        int num = 0;
        for (auto i : nums) {
            num ^= i;            
        }
        return num;
    }
};


/**
    The same but triple and find only one
    x x x y y y z
    1 2 3 1 2 1 2
    (x + x + x) % 3 for every bit
*/

