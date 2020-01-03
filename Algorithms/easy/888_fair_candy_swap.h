/**
    888. Fair Candy Swap

Alice and Bob have candy bars of different sizes: 
A[i] is the size of the i-th bar of candy that Alice has, and B[j] is the size of the j-th bar of candy that Bob has.

Since they are friends, they would like to exchange one candy bar each so that after the exchange, 
they both have the same total amount of candy.  
(The total amount of candy a person has is the sum of the sizes of candy bars they have.)

Return an integer array ans where ans[0] is the size of the candy bar that Alice must exchange, 
and ans[1] is the size of the candy bar that Bob must exchange.

If there are multiple answers, you may return any one of them.  It is guaranteed an answer exists.

Example 1:
Input: A = [1,1], B = [2,2]
Output: [1,2]

Example 2:
Input: A = [1,2], B = [2,3]
Output: [1,2]

Example 3:
Input: A = [2], B = [1,3]
Output: [2,3]

Example 4:
Input: A = [1,2,5], B = [2,4]
Output: [5,4]

Note:
1 <= A.length <= 10000
1 <= B.length <= 10000
1 <= A[i] <= 100000
1 <= B[i] <= 100000
It is guaranteed that Alice and Bob have different total amounts of candy.
It is guaranteed there exists an answer.

Algo1: use dictionary as a criteria of number presence: O(N1+N2) + O(N2)
- calc difference: diff = (Sum1 - Sum2) / 2;
- create dict from second array: key = num, value = index (is it needed)
- go through first array and search needed second number in dict

Algo2: sort second_array O(N2logN2 + N1logN2)
- calc difference: diff = (Sum1 - Sum2) / 2;
- sort second
- go through first array and binary_search needed second number in vect2

Algo3: sort both arrays and save current index in b for each search
- calc difference: diff = (Sum1 - Sum2) / 2;
- sort both
- go through first array and search needed second number in vect2 from (prev_idx) and update prev_idx
*/

const int ZERO = [](){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    return 0;
}();

class Solution {
public:
    vector<int> fairCandySwap(const vector<int>& a, const vector<int>& b) {
        int sum1 = accumulate(a.begin(), a.end(), 0);
        int sum2 = accumulate(b.begin(), b.end(), 0);
        int diff = (sum1 - sum2)/2;
        unordered_set<int> dict2{b.begin(), b.end()};
        for (auto v : a) {
            if (dict2.count(v-diff)) {
                return {v, v-diff};
            }
        }
        assert(false);
        return {};
    }
};

class Solution {
public:
    vector<int> fairCandySwap(const vector<int>& a, vector<int>& b) {
        int sum1 = accumulate(a.begin(), a.end(), 0);
        int sum2 = accumulate(b.begin(), b.end(), 0);
        int diff = (sum1 - sum2)/2;
        sort(b.begin(), b.end());
        for (auto v : a) {
            int v2 = v - diff;
            if (binary_search(b.begin(), b.end(), v2)) {
                return {v, v2};
            }
        }
        assert(false);
        return {};
    }
};


