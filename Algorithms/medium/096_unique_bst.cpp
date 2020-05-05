/**
    96. Unique Binary Search Trees
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:
Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

Algo1: dp O(N^2) + O(N)
a[0] = 1, a[1] = 1
a[i] = a[i-1] + a[i-2]a[1] + ... + a[i-j-1]*a[j] + ... + a[0]*a[i-1]

Algo2: Catalan number

*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> a(n+1, 0);
        a[0] = 1;
        a[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                a[i] += a[i-1-j] * a[j];
            }
        }
        return a[n];
    }
};


