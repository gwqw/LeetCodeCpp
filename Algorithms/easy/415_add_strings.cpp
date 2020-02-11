/**
    415. Add Strings
Given two non-negative integers num1 and num2 represented as string, 
return the sum of num1 and num2.

Note:
The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

Algo: O(N)
- go through both strings and saves exceed number
*/

class Solution {
public:
    string addStrings(const string& n1, const string& n2) {
        string res;
        res.reserve(max(n1.size(), n2.size())+1);
        int exc = 0;
        for (int i = (int)n1.size()-1, j = (int)n2.size()-1; 
             i >= 0 || j >= 0 || exc > 0; 
             --i, --j) 
        {
            int x = 0, y = 0;
            if (i >= 0) x = n1[i] - '0';
            if (j >= 0) y = n2[j] - '0';
            int sum = x + y + exc;
            if (sum > 9) {
                exc = 1;
                sum -= 10;
            } else {
                exc = 0;
            }
            res.push_back(char(sum + '0'));
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
class Solution {
public:
    string addStrings(const string& n1, const string& n2) {
        string res;
        res.reserve(max(n1.size(), n2.size())+1);
        int exc = 0;
        for (int i = (int)n1.size()-1, j = (int)n2.size()-1; 
             i >= 0 || j >= 0 || exc > 0; 
             --i, --j) 
        {
            int x = 0, y = 0;
            if (i >= 0) x = n1[i] - '0';
            if (j >= 0) y = n2[j] - '0';
            exc += x + y;
            res.push_back(char(exc % 10 + '0'));
            exc /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
