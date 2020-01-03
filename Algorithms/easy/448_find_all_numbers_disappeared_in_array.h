/**
    448. Find All Numbers Disappeared in an Array
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), 
some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? 
You may assume the returned list does not count as extra space.

Example:
Input:
[4,3,2,7,8,2,3,1]
Output:
[5,6]

Algo1: naive: use sort and find missed elements O(NLogN)

Algo2: use bucket sort: O(N)
- go through array for i in [0,N):
    while a[i] != i+1 and a[a[i]-1] != a[i]:
        swap(a[i], a[a[i]-1])
- create v = []
- second go through array:
    - if a[i] != i+1:
        v.append(i+1)
- return v

Algo3: add bit to a[a[i]-1] value, for example make negative or add n

    
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& a) {
        for (int i = 0; i < a.size(); ++i) {
            while (a[i] != i+1 && a[a[i]-1] != a[i]) {
                swap(a[i], a[a[i]-1]);
            }
        }
        vector<int> res;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != i+1) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};

/*
    [4,3,2,7,8,2,3,1]
     ^     |
    [7,3,2,4,8,2,3,1] 
     ^
    [3,3,2,4,8,2,7,1] 
     ^
    [2,3,3,4,8,2,7,1]
     ^
    [2,3,3,4,8,2,7,1]
     ^ 
    [3,2,3,4,8,2,7,1]
     ^
    [3,2,3,4,8,2,7,1] 
       ^
    ...
    [3,2,3,4,8,2,7,1]
             ^
    [3,2,3,4,1,2,7,8]
             ^
    [1,2,3,4,3,2,7,8]
             ^  
    [1,2,3,4,3,2,7,8]
               ^
    [1,2,3,4,3,2,7,8] -> [5, 6]
     
*/
