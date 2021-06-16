/**
    658. Find K Closest Elements
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
An integer a is closer to x than an integer b if:
|a - x| < |b - x|, or
|a - x| == |b - x| and a < b

Example 1:
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Example 2:
Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]

Constraints:
1 <= k <= arr.length
1 <= arr.length <= 10^4
arr is sorted in ascending order.
-10^4 <= arr[i], x <= 10^4

Algo: find closest and shrink window with 2 iterators: O(logN + k)
    i = find_closest(a, x)
    f,t = i,i
    len = 1
    while f > 0 and t+1 < a.size() and l < k:
        if x - a[f-1] <= a[t+1] - x:
            f -= 1
        else:
            t += 1
        l += 1
    while l < k and f > 0:
        f -= 1
        l += 1
    while l < k and t+1 < a.size():
        t += 1
        l += 1
    return vector<int>{a.begin()+f, a.begin()+t+1};
    
Algo2 (bad): sorting with comparator abs(x - a[i]) and return k first: O(NlogN)

Algo3: binary_search of left window edge: O(logN) + O(k) on copy
*/

class Solution {
public:
    vector<int> findClosestElements(const vector<int>& a, int k, int x) {
        if (k >= (int)a.size()) return a;
        auto it = lower_bound(a.begin(), a.end(), x);
        if (it == a.end()) {
            return {a.end()-k, a.end()};
        } else if (it == a.begin()) {
            return {a.begin(), a.begin()+k};
        }
        int f = 0;
        int t = (int)a.size()-1;
        if (x - *prev(it) <= *it - x) {
            f = t = prev(it) - a.begin();
        } else {
            f = t = it - a.begin();
        }
        int l = 1;
        while (l < k && f > 0 && t+1 < (int)a.size()) {
            if (x - a[f-1] <= a[t+1] - x) {
                --f;
            } else {
                ++t;
            }
            ++l;
        }
        while (l < k && f > 0) {
            --f;
            ++l;
        }
        while (l < k && t+1 < (int)a.size()) {
            ++t;
            ++l;
        }
        return {a.begin()+f, a.begin()+t+1};
    }
};

class Solution {
public:
    vector<int> findClosestElements(const vector<int>& a, int k, int x) {
        if (k >= (int)a.size()) return a;
        auto it = lower_bound(a.begin(), a.end(), x);
        if (it == a.end()) {
            return {a.end()-k, a.end()};
        } else if (it == a.begin()) {
            return {a.begin(), a.begin()+k};
        }
        int f = 0;
        int t = (int)a.size()-1;
        if (x - *prev(it) <= *it - x) {
            f = t = prev(it) - a.begin();
        } else {
            f = t = it - a.begin();
        }
        int l = 1;
        while (l < k && f > 0 && t+1 < (int)a.size()) {
            if (x - a[f-1] <= a[t+1] - x) {
                --f;
            } else {
                ++t;
            }
            ++l;
        }
        if (l < k && f > 0) {
            f -= k-l;
        }
        else if (l < k && t+1 < (int)a.size()) {
            t += k-l;
        }
        return {a.begin()+f, a.begin()+t+1};
    }
};

class Solution {
public:
    vector<int> findClosestElements(const vector<int>& a, int k, int x) {
        if (k >= (int)a.size()) return a;
        int l = 0;
        int r = (int)a.size() - k;
        while (l+1 < r) {
            int m = l + (r - l) / 2;
            if (x - a[m] <= a[m+k] - x) {
                r = m;
            } else {
                l = m+1;
            }
        }
        return {a.begin()+l, a.begin()+l+k};
    }
};


