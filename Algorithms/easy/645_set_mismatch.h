/**
    645. Set Mismatch
The set S originally contains numbers from 1 to n. But unfortunately, 
due to the data error, one of the numbers in the set got duplicated to another number in the set, 
which results in repetition of one number and loss of another number.

Given an array nums representing the data status of this set after the error. 
Your task is to firstly find the number occurs twice and then find the number that is missing. 
Return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]
Note:
1. The given array size will in the range [2, 10000].
2. The given array's numbers won't have any order.

Algo1: naive: O(N) amortized + O(N)
- go through array and remember num in set
- if n in set -> res[0]
- go through 1..n and look in set, in no -> res[1]

Algo2: radix sort
- go through array and
    - while n[i] != i+1 != idx && n[i] != n[n[i]-1]: swap(n[i], n[n[i]])
- go through array and find duplicate and missing number:
    - if i != n[i]-1: res = [n[i]], i+1]

Algo3: use summ and square summ
- x - needed (deleted), y - inserted
- A = sum(nums), B = n(n+1)/2
- B - A = x - y = C1
- AS = sum(nums^2), BS = sum(1^2..n^2)
- BS - AS = x^2 - y^2 = (x-y)(x+y) = C2
- x + y = C2 / C1
- x = (C1 + C2/C1) / 2
- y = x - C1
    
1 2 2 4
1 2 2 4 
*/

// naive: 64ms
class Solution {
public:
    vector<int> findErrorNums(const vector<int>& n) {
        unordered_set<int> dict;
        vector<int> res(2);
        for (int i = 0; i < (int)n.size(); ++i) {
            if (dict.count(n[i])) {
                res[0] = n[i];
            } else {
                dict.insert(n[i]);
            }
        }
        for (int i = 1; i <= (int)n.size(); ++i) {
            if (dict.count(i) == false) {
                res[1] = i;
                return res;
            }
        }
        throw invalid_argument("Cannot find missing number");
    }
};

// radix (12ms)
class Solution {
public:
    vector<int> findErrorNums(const vector<int>& n) {
        vector<int> res(2);
        for (int i = 0; i < (int)n.size(); ++i) {
            while (n[i] != i+1 && n[i] != n[n[i]-1]) {
                swap(n[i], n[n[i]-1]);
            }
        }
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (n[i] != i+1) {
                return {n[i], i+1};
            }
        }
        throw invalid_argument("Cannot find missing number");
    }
};

// formula (math) (12ms)
class Solution {
public:
    vector<int> findErrorNums(const vector<int>& nums) {
        vector<int> res(2);
        int n = (int)nums.size();
        long long A = n * (n + 1ll) / 2;
        long long B = 0;
        long long AS = 0, BS = 0;
        for (int i = 0; i < n; ++i) {
            B += nums[i];
            AS += (i+1)*(i+1);
            BS += pow(nums[i], 2);            
        }
        long long C1 = A - B;
        long long C2 = AS - BS;
        res[1] = (C1 + C2/C1) / 2;
        res[0] = res[1] - C1;
        
        return res;
    }
};
// optimization1
class Solution {
public:
    vector<int> findErrorNums(const vector<int>& nums) {
        vector<int> res(2);
        int n = (int)nums.size();
        int A = n * (n + 1ll) / 2;
        int B = 0;
        long long C2 = 0;
        for (int i = 0; i < n; ++i) {
            B += nums[i];
            C2 += (pow(i+1, 2) - pow(nums[i], 2));
        }
        int C1 = A - B;
        res[1] = (C1 + C2/C1) / 2;
        res[0] = res[1] - C1;
        
        return res;
    }
};
//optimization2
class Solution {
public:
    vector<int> findErrorNums(const vector<int>& nums) {
        vector<int> res(2);
        int n = (int)nums.size();
        int A = n * (n + 1ll) / 2;
        int B = 0;
        long long C2 = n * (n + 1ll) * (2 * n + 1ll) / 6;
        for (int i : nums) {
            B += i;
            C2 -= i*i;
        }
        int C1 = A - B;
        res[1] = (C1 + C2/C1) / 2;
        res[0] = res[1] - C1;
        
        return res;
    }
};

