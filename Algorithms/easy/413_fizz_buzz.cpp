/**
    412. Fizz Buzz
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]

Algo: naive
- for i = 1 to n:
    - if i % 3 == 0 && i % 5 == 0:
        - res.push("FizzBuzz")
    - ...
    
Algo2: use additional counters

*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        for (int i = 1; i <= n; ++i) {
            if (i % 3 == 0 && i % 5 == 0) {
                ans[i-1] = "FizzBuzz";
            } else if (i % 3 == 0) {
                ans[i-1] = "Fizz";
            } else if (i % 5 == 0) {
                ans[i-1] = "Buzz";
            } else {
                ans[i-1] = to_string(i);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        unsigned int t = 3, f = 5;
        for (int i = 1; i <= n; ++i) {
            if (i != t && i != f) {
                ans[i-1] = to_string(i);
            } else {
                if (i == t) {
                    ans[i-1] = "Fizz";
                    t += 3;
                } 
                if (i == f) {
                    ans[i-1] += "Buzz";
                    f += 5;
                }
            }
        }
        return ans;
    }
};

