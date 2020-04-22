/**
    456. 132 Pattern
Given a sequence of n integers a1, a2, ..., an, 
a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj. 
Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.

Note: n will be less than 15,000.

Example 1:
Input: [1, 2, 3, 4]
Output: False
Explanation: There is no 132 pattern in the sequence.

Example 2:
Input: [3, 1, 4, 2]
Output: True
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].

Example 3:
Input: [-1, 3, 2, 0]
Output: True
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].

Algo: naive center bruteforce O(N^2) + O(1) TLE
- for every i:
    - find j: j < i and a[j] < a[i]
    - find k: i < k and a[k] < a[i]

Algo2: use left and right set
- make 2sets: left and right or map[value] -> count
- for every i:
    - find min in left
    - find upper in right
    - check ok
    - move right:
        - ++i
        - a[i] -> left
        - a[i+1] <- right
    
Algo3: using stack to remember next greater element
- ak -- a[k]
- go from the end
    - if a[i] < ak: return true
    - else # try may be it is a[i]
    - find max lesser element:
        - extract from stack, while st[i] < a[i]
        - write it to ak
    - if not in stack, we have ak from previous
    - push a[i] to stack
*/

class Solution {
public:
    bool find132pattern(const vector<int>& a) {
        if (a.size() < 3) return false;
        set<int> left;
        map<int, int> right;
        left.insert(a[0]);
        for (size_t i = 2; i < a.size(); ++i) {
            ++right[a[i]];
        }
        
        for (size_t i = 1; i+1 < a.size(); ++i) {
            auto ai = a[i];
            auto aj = *left.begin();
            if (aj >= ai) {
                left.insert(ai);
                auto rit = right.find(a[i+1]);
                --(rit->second);
                if (rit->second == 0) {
                    right.erase(rit);
                }
            }
            
            auto it = right.upper_bound(aj);
            if (it != right.end() && it->first < ai) {
                return true;
            }
            left.insert(ai);
            auto rit = right.find(a[i+1]);
            --(rit->second);
            if (rit->second == 0) {
                right.erase(rit);
            }
        }
        return false;
    }
};
class Solution {
public:
    bool find132pattern(const vector<int>& a) {
        if (a.size() < 3) return false;
        priority_queue<int, vector<int>, greater<int>> left;
        map<int, int> right;
        left.push(a[0]);
        for (size_t i = 2; i < a.size(); ++i) {
            ++right[a[i]];
        }
        
        for (size_t i = 1; i+1 < a.size(); ++i) {
            auto ai = a[i];
            auto aj = left.top();
            if (aj >= ai) {
                left.push(ai);
                auto rit = right.find(a[i+1]);
                --(rit->second);
                if (rit->second == 0) {
                    right.erase(rit);
                }
            }
            
            auto it = right.upper_bound(aj);
            if (it != right.end() && it->first < ai) {
                return true;
            }
            left.push(ai);
            auto rit = right.find(a[i+1]);
            --(rit->second);
            if (rit->second == 0) {
                right.erase(rit);
            }
        }
        return false;
    }
};

class Solution {
public:
    bool find132pattern(const vector<int>& a) {
        if (a.size() < 3) return false;
        stack<int> st;
        int prev = INT_MIN;
        for (size_t i = a.size(); i-->0; ) {
            if (a[i] < prev) {
                return true;
            }
            while (!st.empty() && st.top() < a[i]) {
                prev = st.top();
                st.pop();
            }
            st.push(a[i]);
        }
        return false;
    }
};

/*
[1,2,3,4]
[3, 1, 4, 2]
[-1, 3, 2, 0]
[1,0,1,-4,-3]
[3,5,0,3,4]
*/


