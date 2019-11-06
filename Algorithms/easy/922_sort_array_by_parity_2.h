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
2 pass through:
    1. if cond  push_back
    2. if !cond push_back
    
Algo2: use quick sort:
    2 iterators: begin and end:
    - begin goes while cond
    - end goes while !cond
    - if b > e: break
    - swap values
*/

class Solution {
private:
    static bool cond(int idx, int value) {
        return (i % 2 == 0 && value % 2 == 0) ||
               (i % 2 == 1 && value % 2 == 1);
    }
public:
    vector<int> sortArrayByParityII(const vector<int>& a) {
        vector<int> res;
        res.reserve(a.size());
        for (int i = 0; i < s.size(); ++i) {
            if (cond(i, a[i])) {
                res.push_back(i);
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            if (!cond(i, a[i])) {
                res.push_back(i);
            }
        }
        return res;
    }
};

class Solution {
private:
    static bool cond(int idx, int value) {
        return (i % 2 == 0 && value % 2 == 0) ||
               (i % 2 == 1 && value % 2 == 1);
    }
public:
    vector<int> sortArrayByParityII(vector<int>& a) {
        int b = 0;
        int e = (int)a.size() - 1;
        while (true) {
            while (cond(b, a[b])) ++b;
            if (b > e) break;
            while (!cond(e, a[e])) --e;
            if (b > e) break;
            std::swap(a[b], a[e]);
        }
        return std::move(a);
    }
};
