/**
    470. Implement Rand10() Using Rand7()
Given the API rand7() that generates a uniform random integer in the range [1, 7], write a function rand10() that generates a uniform random integer in the range [1, 10]. You can only call the API rand7(), and you shouldn't call any other API. Please do not use a language's built-in random API.

Each test case will have one internal argument n, the number of times that your implemented function rand10() will be called while testing. Note that this is not an argument passed to rand10().

Follow up:
What is the expected value for the number of calls to rand7() function?
Could you minimize the number of calls to rand7()?

Example 1:
Input: n = 1
Output: [2]

Example 2:
Input: n = 2
Output: [2,8]

Example 3:
Input: n = 3
Output: [3,8,10]

Constraints:
1 <= n <= 10^5

Algo:
generate 1s: o = rand7()
generate 7s: s = rand7()
n = s*7 + o
n in [0,63] -> [0,54]
return n % 11
*/

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int s = rand7();
        int o = rand7();
        int n = (s-1)*7+o;
        while (n > 40) {
            s = rand7();
            o = rand7();
            n = (s-1)*7+o;
        }
        return n % 10 + 1;
    }
};