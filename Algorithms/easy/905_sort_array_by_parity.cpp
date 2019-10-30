/**
    905. Sort Array By Parity
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
You may return any answer array that satisfies this condition.

Example 1:
Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

Note:
1 <= A.length <= 5000
0 <= A[i] <= 5000

Algo: O(N) + O(N)
- create res vector 
- create 2 counter: from begin and from end
- go through vector: and if is even: to the first counter, else to the second

Algo2(in place): O(N) + O(1)
- use std::partition
- and copy result

Algo3(in place by hand): O(N) + O(1)
- 2 idx(pointers): from begin and from end
- move pointers to problem: 1 must go to odd number, 2-nd to even
- swap
- if (b == e) break
*/


class Solution {
public:
    vector<int> sortArrayByParity(const vector<int>& a) {
        vector<int> res(a.size());
        int b = 0, e = (int)a.size() - 1;
        for (auto i : a) {
            if (i % 2 == 0) {
                res[b++] = i;
            } else {
                res[e--] = i;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        std::partition(begin(a), end(a), [](int value){return value % 2 == 0;});
        return move(a);
    }
};

class Solution {
private:
    bool is_even(int value) {return value % 2 == 0;}
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        auto b = a.begin();
        auto e = a.end();
        --e;
        while (true) {
            while (is_even(*b) and b != e) {++b;}
            if (b == e) break;
            while (!is_even(*e) and b != e) {--e;}
            if (b == e) break;
            swap(*b, *e);
        }
        return move(a);
    }
};



