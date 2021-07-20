/**
    907. Sum of Subarray Minimums
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 10^9 + 7.

Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:
Input: arr = [11,81,94,43,3]
Output: 444
 
Constraints:
1 <= arr.length <= 3 * 10^4
1 <= arr[i] <= 3 * 10^4

3 1 2 4
       
Algo1: dp: O(N^2) tle
min[i, size] = (min[i,size-1], min[i+1, size-1])
sum += min[i,size]

Algo2: monotinic stack
PLE, NLE -- prev. less element, next less element
for i in range(0,n)
    left[i] = distance to ple from ple_stack
    right[i] = distance to nle from nle_stack
for i in range(0,n):
    ans += l[i]*r[i]*a[i] mod P
ple:
    for i in range(0,n)
        while st and a[i] > st.top():
            st.pop()
        left[i] = not st.empty() ? i - st.top() : i+1
        st.push(a[i])
nle: 
    for i in range(n-1, -1):
        while st and a[i] < st.top():
            st.pop()
        right[i] = not st.empty() ? st.top()-i : n-i
        st.push(a[i])
            
*/

class Solution {
	static constexpr int P = 1e9+7;
public:
    int sumSubarrayMins(const vector<int>& a) {
        vector<vector<int>> dp(a.size()+1, vector<int>(a.size()));
		int sum = 0;
		for (size_t i = 0; i < a.size(); ++i) {
			dp[1][i] = a[i];
			sum = mplus(sum, dp[1][i]);
		}
		for (size_t len = 2; len <= a.size(); ++len) {
			for (size_t i = 0; i+len-1 < a.size(); ++i) {
				//size_t j = i + len -1;
				dp[len][i] = min(dp[len-1][i], dp[len-1][i+1]);
				sum = mplus(sum, dp[len][i]);
			}
		}
		return sum;
    }
private:
	int mplus(int a, int b) {
	    a = a % P;
	    b = b % P;
	    return (a + b) % P;
	}
};

class Solution {
	static constexpr int P = 1e9+7;
public:
    int sumSubarrayMins(const vector<int>& a) {
        int sum = 0;
        stack<int> ple;
        stack<int> nle;
        vector<int> left(a.size());
        vector<int> right(a.size());
        for (int i = 0; i < (int)a.size(); ++i) {
            while (!ple.empty() && a[ple.top()] >= a[i]) {
                ple.pop();
            }
            left[i] = !ple.empty() ? i - ple.top() : i+1;
            ple.push(i);
        }
        for (int i = (int)a.size()-1; i >= 0; --i) {
            while (!nle.empty() && a[nle.top()] >= a[i]) {
                nle.pop();
            }
            right[i] = !nle.empty() ? nle.top()-i : a.size()-i;
            nle.push(i);
        }
        for (int i = 0; i < (int)a.size(); ++i) {
            sum = mplus(sum, mmult(mmult(a[i],left[i]), right[i]));
        }
		
		return sum;
    }
private:
	int64_t mplus(int64_t a, int64_t b) {
	    a = a % P;
	    b = b % P;
	    return (a + b) % P;
	}
	
	int64_t mmult(int64_t a, int64_t b) {
	    a = a % P;
	    b = b % P;
	    return (a * b) % P;
	}
};