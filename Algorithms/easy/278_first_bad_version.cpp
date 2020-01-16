/**
    278. First Bad Version
You are a product manager and currently leading a team to develop a new product. 
Unfortunately, the latest version of your product fails the quality check. 
Since each version is developed based on the previous version, 
all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, 
which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. 
Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example:
Given n = 5, and version = 4 is the first bad version.
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version. 

Algo: binary_search: O(logN), O(1)
    _____
 ___|
^       ^
b       e
check(n)
b = 0, e = n
while e - b > 1:
    m = b + (e - b) / 2
    if isBadVersion(m):
        e = m
    else:
        b = m
return e
*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (!isBadVersion(n)) return -1;
        int b = 0;
        while ((n - b) > 1) {
            int m = b + (n - b) / 2;
            if (isBadVersion(m)) {
                n = m;
            } else {
                b = m;
            }
        }
        return n;
    }
};
