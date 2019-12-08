/**
   167. Two Sum II - Input array is sorted
Given an array of integers that is already sorted in ascending order, 
find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers 
such that they add up to the target, where index1 must be less than index2.

Note:
Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly 
one solution and you may not use the same element twice.

Example:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

Algo: O(NlogN) + O(1)
- go through array and for every num:
    - find add = target - num using bin_search
    - if found: return
    - else: continue
    
Algo2: O(N) + O(N)
- add to dict and for every number search in dict

Algo3: O(N) + O(1)
- have two iterators: from begin and from end
- for every value:
    - find target - value from the end
    - if yes: return
    - else: move to the next value

*/

class Solution {
public:
    vector<int> twoSum(const vector<int>& numbers, int target) {
        for (auto it = numbers.begin(); it+1 != numbers.end(); ++it) {
            int add = target - *it;
            auto f = lower_bound(it+1, numbers.end(), add);
            if (f != numbers.end() && *f == add) {
                return {int(it - numbers.begin()) + 1, int(f - numbers.begin()) + 1};
            }
        }
        throw runtime_error("There is no spoon");
    }
};

class Solution {
public:
    vector<int> twoSum(const vector<int>& numbers, int target) {
        unordered_map<int, int> dict;
        for (int i = 0; i < numbers.size(); ++i) {
            int add = target - numbers[i];
            if (auto it = dict.find(add); it != dict.end()) {
                return {it->second+1, i+1};
            }
            
            dict.try_emplace(numbers[i], i);
        }
        throw runtime_error("There is no spoon");
    }
};

class Solution {
public:
    vector<int> twoSum(const vector<int>& numbers, int target) {
        int j = (int)numbers.size()-1;
        for (int i = 0; i < j; ++i) {
            int add = target - numbers[i];
            while (numbers[j] > add) --j;
            if (add == numbers[j]) return {i+1,j+1};
        }
        throw runtime_error("There is no spoon");
    }
};




/*
   2 7 11 15, t = 9
   ^ ^
*/
