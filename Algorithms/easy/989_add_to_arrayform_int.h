/**
    989. Add to Array-Form of Integer
For a non-negative integer X, the array-form of X is an array of its digits in left to right order.
For example, if X = 1231, then the array form is [1,2,3,1].
Given the array-form A of a non-negative integer X, return the array-form of the integer X+K.

Example 1:
Input: A = [1,2,0,0], K = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234

Example 2:
Input: A = [2,7,4], K = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455

Example 3:
Input: A = [2,1,5], K = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021

Example 4:
Input: A = [9,9,9,9,9,9,9,9,9,9], K = 1
Output: [1,0,0,0,0,0,0,0,0,0,0]
Explanation: 9999999999 + 1 = 10000000000

Note：
1 <= A.length <= 10000
0 <= A[i] <= 9
0 <= K <= 10000
If A.length > 1, then A[0] != 0


Algo: O(max(N, log(K)) + O(max(N, log(K)) (?)
- calc digit from k
- add it and a[i] and one (from past calc if exist) to number res
- save one if needed
- go to next digit

Algo (enhance): can be in place
- use k as "next_one"
- add a[i] to k
- calc digit as k%10 and add to res
- k /= 10
*/

class Solution {
public:
    vector<int> addToArrayForm(const vector<int>& a, int k) {
        vector<int> res;
        res.reserve(a.size());
        bool next_one = false;
        size_t i = 0, n = a.size();
        while (k > 0 || i != n) {
            int d1 = 0;
            if (k > 0) {
                d1 = k % 10;
                k /= 10;
            }
            int d2 = n > i ? a[n-i++-1] : 0;
            d1 += d2 + int(next_one);
            if (d1 >= 10) {
                next_one = true;
                d1 -= 10;
            } else {
                next_one = false;
            }
            res.push_back(d1);
        }

        if (next_one) {
            res.push_back(1);
        }

        reverse(res.begin(), res.end());
        return res;        
    }
};

class Solution {
public:
    vector<int> addToArrayForm(const vector<int>& a, int k) {
        vector<int> res;
        res.reserve(a.size());
        size_t i = 0, n = a.size();
        while (k > 0 || i != n) {
            if (i < n) {
                k += a[n-i++-1];
            }
            res.push_back(k % 10);
            k /= 10;
        }

        reverse(res.begin(), res.end());
        return res;        
    }
};


