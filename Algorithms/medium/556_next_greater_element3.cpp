/**
    556. Next Greater Element III
Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.
Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

Example 1:
Input: n = 12
Output: 21

Example 2:
Input: n = 21
Output: -1

Constraints:
1 <= n <= 2^31 - 1

Algo: next permutation
n->n_str
while (next_permutation(n_str)) {
    if (n_str not in int32) return -1
    n2 = from_str(n_str)
    if n2 > n1: return n2
    if n1 < n2: return -1
}
*/

class Solution {
public:
    int nextGreaterElement(int n) {
        string n_str = to_string(n);
        while (next_permutation(n_str.begin(), n_str.end())) {
            if (!isInInt32(n_str)) return -1;
            int n2 = stoi(n_str);
            if (n2 > n) return n2;
            if (n2 < n) return -1;
        }
        return -1;
    }
    
    bool isInInt32(const string& s) {
        if (s.size() < 10) return true;
        return s <= "2147483647";
    }
};

