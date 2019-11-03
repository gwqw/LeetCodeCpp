/**
    922. Sort Array By Parity II
Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.
Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.
You may return any answer array that satisfies this condition.

Example 1:
Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.

Note:
2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000

Algo1: O(N) + O(N)
1 pass through:
    1. if is_even res[i]; i+2
    2. if is_odd res[j];j+2
    
Algo2: use quick sort:
    2 iterators: even_idx and odd_idx:
    - even goes while a[i] is even or isn't end: += 2
    - odd goes while a[j] is odd or isn't end: += 2
    - if i >= end or j >= end: break
    - swap values
*/

class Solution {
public:
    vector<int> sortArrayByParityII(const vector<int>& a) {
        vector<int> res;
        res.resize(a.size());
        int i{0}, j{1};
        for (auto v : a) {
            if (v % 2 == 0) {
                res[i] = v;
                i += 2;
            } else {
                res[j] = v;
                j += 2;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& a) {
        int i = 0;
        int j = 1;
        while (true) {
            while (i < a.size() && a[i] % 2 == 0) i += 2;
            if (i >= a.size()) break;
            while (j < a.size() && a[j] % 2 == 1) j += 2;
            if (j >= a.size()) break;
            i += 2;
            j += 2;
            std::swap(a[i], a[j]);
        }
        return std::move(a);
    }
};
