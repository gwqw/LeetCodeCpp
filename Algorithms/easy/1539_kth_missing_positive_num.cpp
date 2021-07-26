/**
    1539. Kth Missing Positive Number
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Find the kth positive integer that is missing from this array.

Example 1:
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

Example 2:
Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.

Constraints:
1 <= arr.length <= 1000
1 <= arr[i] <= 1000
1 <= k <= 1000
arr[i] < arr[j] for 1 <= i < j <= arr.length

Algo: binary_search
l = 0, r = n-1
m = r-l/2
missed = a[m]-1-m
if missed < k:
	l = m
elif missed >= k:
	r = m
	
*/

class Solution {
public:
    int findKthPositive(const vector<int>& a, int k) {
		if (a[0] > k) {
			return k;
		}
        size_t l = 0, r = a.size();
		while (l+1 < r) {
			size_t m = l + (r-l)/2;
			int missed = a[m]-1-(int)m;
			if (missed < k) {
				l = m;
			} else {
				r = m;
			}
		}
		if (r == a.size()) {
			int missed = a[r-1]-1-r+1;
			k -= missed;
			return a[r-1] + k;
		}
		int missed = a[l]-1-l;
		k -= missed;
		return a[l] + k;
    }
};