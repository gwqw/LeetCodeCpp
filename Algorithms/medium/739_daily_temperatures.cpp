/**
    739. Daily Temperatures
Given a list of daily temperatures T, return a list such that, for each day in the input, 
tells you how many days you would have to wait until a warmer temperature.
If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures 
T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be 
    [1,  1,  4,  2,  1,  1,  0,  0].

Note: The length of temperatures will be in the range [1, 30000]. 
Each temperature will be an integer in the range [30, 100]. 


73, 1
74, 1
75, 2
76, 6

Algo: O(N) + O(N)
- make stack<pair<value, idx>>
- go from the end
- look for greater value in stack (pop less or equal)
- if greater exists:
    - write difference between stack and current
- else (stack is empty):
    - write 0
- push current value and idx to stack

2, 3, 5, 6
1, 1, 1, 1

6, 5, 4, 3
0, 0, 0, 0

73, 74, 75, 71, 69, 72, 76, 73
1   1   4   2   1   1   0   0
0   1   2   3   4   5   6   7


74, 1
75, 2
76, 6

Algo: dynamic programing
- go from the end
- search greater to the right
    - if next temp > cur:
        - res[i] = j - i
    - else if res[j] == 0: # means all values to the right are less th. current
        - res[i] = 0
        - break
    - else: # j-value is less, next greater in res[j] steps
        - j += res[j]

*/

class Solution {
public:
    vector<int> dailyTemperatures(const vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<pair<int, size_t>> st;
        for (size_t i = temperatures.size(); i-->0; ) {
            while (!st.empty() && st.top().first <= temperatures[i]) {
                st.pop();
            }
            res[i] = st.empty() ? 0 : st.top().second - i;
            st.emplace(temperatures[i], i);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(const vector<int>& temperatures) {
        int n = (int)temperatures.size();
        vector<int> res(n);
        for (int i = n-2; i >= 0; --i) {
            for (int j = i+1; j < n; ) {
                if (temperatures[j] > temperatures[i]) {
                    res[i] = j - i;
                    break;
                } else if (res[j] == 0) {
                    break;
                }
                j += res[j];
            }
        }
        return res;
    }
};



