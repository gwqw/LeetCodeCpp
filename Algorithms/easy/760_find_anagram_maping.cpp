/**
    760. Find Anagram Mappings
You are given two integer arrays nums1 and nums2 where nums2 is an anagram of nums1. Both arrays may contain duplicates.
Return an index mapping array mapping from nums1 to nums2 where mapping[i] = j means the ith element in nums1 appears in nums2 at index j. If there are multiple answers, return any of them.
An array a is an anagram of an array b means b is made by randomizing the order of the elements in a.

Example 1:
Input: nums1 = [12,28,46,32,50], nums2 = [50,12,32,46,28]
Output: [1,4,3,2,0]
Explanation: As mapping[0] = 1 because the 0th element of nums1 appears at nums2[1], and mapping[1] = 4 because the 1st element of nums1 appears at nums2[4], and so on.

Example 2:
Input: nums1 = [84,46], nums2 = [84,46]
Output: [0,1]

Constraints:
1 <= nums1.length <= 100
nums2.length == nums1.length
0 <= nums1[i], nums2[i] <= 10^5
nums2 is an anagram of nums1.

Algo: dict
dict[n]->{idx} or [idx], make from nums2
for n in nums1:
	j = dict[n].first()
	dict.pop_front()
	res[i] = j

*/

class Solution {
public:
    vector<int> anagramMappings(const vector<int>& nums1, const vector<int>& nums2) {
        auto dict = makeDict(nums2);
		vector<int> res(nums1.size());
		for (size_t i = 0; i < nums1.size(); ++i) {
			int n = nums1[i];
			int j = *dict[n].begin();
			dict[n].erase(dict[n].begin());
			res[i] = j;
		}
		return res;
    }

private:	
	unordered_map<int, unordered_set<int>> makeDict(const vector<int>& nums) {
		unordered_map<int, unordered_set<int>> dict;
		for (size_t i = 0; i < nums.size(); ++i) {
			dict[nums[i]].insert(i);
		}
		return dict;
	}
};
class Solution {
public:
    vector<int> anagramMappings(const vector<int>& nums1, const vector<int>& nums2) {
        auto dict = makeDict(nums2);
		vector<int> res(nums1.size());
		for (size_t i = 0; i < nums1.size(); ++i) {
			int n = nums1[i];
			int j = dict[n].back();
			dict[n].pop_back();
			res[i] = j;
		}
		return res;
    }

private:	
	unordered_map<int, vector<int>> makeDict(const vector<int>& nums) {
		unordered_map<int, vector<int>> dict;
		for (size_t i = 0; i < nums.size(); ++i) {
			dict[nums[i]].push_back(i);
		}
		return dict;
	}
};

