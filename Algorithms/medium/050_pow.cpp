/**
    50. Pow(x, n)
Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:
Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

Constraints:
-100.0 < x < 100.0
-2^31 <= n <= 2^31-1
-10^4 <= xn <= 10^4

Algo1: naive O(n) tle
res = 1
for i in range(n):
    res *= x
return res

Algo2: bin_split with rec O(logN)
    n = n/2
    d = n % 1
    res = pow(n/2)
    res = res*res
    res *= d ? x : 1
    return res
    
Algo3: bin_split (non recursion) O(logN)
 a^(2*n) -> (a^2)^n: a -> a*a, n /= 2
 a^(2*n+1) -> (a^2)^n * a: a -> a*a, (n-1) /= 2, res *= a

*/

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        if (n > 0) {
            for (int i = 0; i < n; ++i) {
                res *= x;
            }
        } else if (n < 0) {
            n = -n;
            for (int i = 0; i < n; ++i) {
                res /= x;
            }
        }
        return res;
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 1) return x;
        if (n == -1) return 1/x;
        if (n == 0) return 1;
        
        double res = myPow(x, n / 2);
        res = res * res;
        auto resid = n % 2;
        if (resid == 1) {
            res *= x;
        } else if (resid == -1) {
            res /= x;
        }
        return res;
    }
};

// Algo3
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                res *= x;
                --n;
            }
            x = x*x;
            n /= 2;            
        }
        while (n < 0) {
            if (n % 2 == -1) {
                res /= x;
                ++n;
            }
            x = x * x;
            n /= 2;
        }
        return res;
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        bool is_neg = n < 0;
        if (n < 0) n = -n;
        while (n > 0) {
            if (n % 2 == 1) {
                res *= x;
                --n;
            }
            x = x*x;
            n /= 2;            
        }
        if (is_neg) {
            res = 1/res;
        }

        return res;
    }
};

