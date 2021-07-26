/**
    697. Degree of an Array
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: nums = [1,2,2,3,1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.

Example 2:
Input: nums = [1,2,2,3,1,4,2]
Output: 6
Explanation: 
The degree is 3 because the element 2 is repeated 3 times.
So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.

Constraints:
nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.

Algo1: sliding window + dict: O(N)
find array degree
have s,e iterators
move e while degree < needed
move s while degree >= needed

Algo2: n->[left, right]
find for n: [left_index, right_index]
dict[n]->cnt
for n in nums:
    if dict[n] == dig:
        min_len = min(min_len, ri-li+1)
return min_len 
*/

class Solution {
public:
    int findShortestSubArray(const vector<int>& nums) {
        if (nums.empty()) return 0;
		int deg = calcDegree(nums);
		int s = 0;
		int e = 0;
		unordered_map<int, int> dict;
		int cd = 0;
		int min_len = (int)nums.size();
		while (e < (int)nums.size() && cd < deg) {
			++dict[nums[e]];
			cd = max(cd, dict[nums[e]]);
            e++;
            while (s <= e && cd >= deg) {
                --dict[nums[s]];
				if (dict.count(nums[s]) == 0) {
				    dict.erase(nums[s]);
				}
                ++s;
				cd = recalcDegree(dict);
				if (cd+1 == deg) {
				    min_len = min(min_len, e - s + 1);
				}
			}
		}
		return min_len;
    }
	
private:
	int calcDegree(const vector<int>& a) {
		unordered_map<int, int> dict;
		int deg = 0;
		for (int n : a) {
			++dict[n];
			deg = max(deg, dict[n]);
		}
		return deg;
	}
	
	int recalcDegree(const unordered_map<int, int>& dict) {
		int deg = 0;
		for (auto [_,cnt] : dict) {
			deg = max(deg, cnt);
		}
		return deg;
	}
};
class Solution {
public:
    int findShortestSubArray(const vector<int>& nums) {
        if (nums.empty()) return 0;
		int deg = calcDegree(nums);
		int s = 0;
		int e = 0;
		unordered_map<int, int> dict;
		unordered_map<int, unordered_set<int>> freq;
		int cd = 0;
		int min_len = (int)nums.size();
		while (e < (int)nums.size() && cd < deg) {
		    int ce = nums[e];
			++dict[ce];
			int fr = dict[ce];
			if (fr-1 != 0) {
			    freq[fr-1].erase(ce);
			}
			freq[fr].insert(ce);
			cd = max(cd, fr);
			++e;
			while (s <= e && cd >= deg) {
			    int cs = nums[s];
				--dict[cs];
				fr = dict[cs];
				freq[fr+1].erase(cs);
				if (fr == 0) {
				    dict.erase(cs);
				} else {
				    freq[fr].insert(cs);
				}
				++s;
				if (freq[fr+1].empty()) {
				    freq.erase(fr+1);
				}
				if (!freq.count(cd)) {
				    --cd;
				}
				if (cd+1 == deg) {
				    min_len = min(min_len, e - s + 1);
				}
			}
		}
		return min_len;
    }
	
private:
	int calcDegree(const vector<int>& a) {
		unordered_map<int, int> dict;
		int deg = 0;
		for (int n : a) {
			++dict[n];
			deg = max(deg, dict[n]);
		}
		return deg;
	}
};

class Solution {
public:
    int findShortestSubArray(const vector<int>& nums) {
        auto [dict, indexes, deg] = calcDegree(nums);
        int min_len = nums.size();
        for (int n : nums) {
            if (dict[n] == deg) {
                min_len = min(min_len, indexes[n].second - indexes[n].first + 1);
            }
        }
        return min_len;
    }
	
private:
    tuple<
    	unordered_map<int, int>,
	    unordered_map<int, pair<int, int>>,
	    int
    > calcDegree(const vector<int>& a) {
		unordered_map<int, int> dict;
		unordered_map<int, pair<int, int>> indexes;
		int deg = 0;
		for (int i = 0; i < a.size(); ++i) {
		    int n = a[i];
			++dict[n];
			if (!indexes.count(n)) {
			    indexes[n].first = i;
			}
			indexes[n].second = i;
			deg = max(deg, dict[n]);
		}
		return {dict, indexes, deg};
	}
};
