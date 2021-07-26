/**
    1228. Missing Number In Arithmetic Progression
In some array arr, the values were in arithmetic progression: the values arr[i + 1] - arr[i] are all equal for every 0 <= i < arr.length - 1.
A value from arr was removed that was not the first or last value in the array.
Given arr, return the removed value.

Example 1:
Input: arr = [5,7,11,13]
Output: 9
Explanation: The previous array was [5,7,9,11,13].

Example 2:
Input: arr = [15,13,12]
Output: 14
Explanation: The previous array was [15,14,13,12].

Constraints:
3 <= arr.length <= 1000
0 <= arr[i] <= 10^5
The given array is guaranteed to be a valid array.

Algo: linear search: O(N)

Algo: bin.search
- use knowledge, that only one element is absent -> can find diff:
diff = (a[n-1] - a[0]) / n
r = n-1, l = 0
while l+1 < r:
    m = l + (r-l)/2
    a[m] == a[0] + diff*m:
        l = m
    else:
        r = m
*/

class Solution {
public:
    int missingNumber(const vector<int>& a) {
        int diff = a[1] - a[0];
        for (size_t i = 2; i < a.size(); ++i) {
            if (a[i] - a[i-1] == 2 * diff) {
                return a[i-1] + diff;
            } else if (2 * (a[i] - a[i-1]) == diff) {
                return a[0] + diff / 2;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int missingNumber(const vector<int>& a) {
        int diff = (a.back() - a[0]) / (int)a.size();
        size_t l = 0, r = a.size()-1;
        while (l+1 < r) {
            int m = l + (r-l) / 2;
            if (a[m] == a[0] + m*diff) {
                l = m;
            } else {
                r = m;
            }
        }
        return a[l]+diff;
    }
};
