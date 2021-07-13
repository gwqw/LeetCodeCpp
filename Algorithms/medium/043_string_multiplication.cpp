/**
    43. Multiply Strings
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"

Constraints:
1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.

Algo: column multiplication
for d in num2:
    terms.push_back(multiply(d on n1))
    sum all terms
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() < num2.size()) multiply(num2, num1);
        if (num1 == "0" || num2 == "0") return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<string> terms;
        terms.reserve(num2.size());
        for (size_t i = 0; i < num2.size(); ++i) {
            auto tmp = string(i, '0') + multiply(num1, num2[i]);
            terms.push_back(move(tmp));
        }
        auto res = sum(terms);        
        reverse(res.begin(), res.end());
        return res;
    }
    
private:
    string multiply(string_view num, char c) {
        int m = digit(c);
        int carry = 0;
        string res;
        res.reserve(num.size() + 1);
        for (size_t i = 0; i < num.size() || carry != 0; ) {
            int d = 0;
            if (i < num.size()) {
                d = digit(num[i++]);
            }
            int mult = d * m + carry;
            carry = mult / 10;
            res.push_back(symbol(mult % 10));
        }
        return res;
    }
    
    string sum(const vector<string>& terms) {
        string res;
        vector<size_t> idxs(terms.size(), 0);
        vector<size_t> eidxs(terms.size());
        for (size_t i = 0; i < terms.size(); ++i) {
            eidxs[i] = terms[i].size();
        }
        int carry = 0;
        while (idxs != eidxs || carry != 0) {
            vector<int> digits(terms.size());
            for (size_t i = 0; i < terms.size(); ++i) {
                if (idxs[i] != eidxs[i]) {
                    digits[i] = digit(terms[i][idxs[i]]);
                    ++idxs[i];
                }
            }
            int s = accumulate(digits.begin(), digits.end(), carry);
            carry = s / 10;
            res.push_back(symbol(s % 10));
        }
        return res;
    }
    
    int digit(char c) {
        return c - '0';
    }
    
    char symbol(int d) {
        return d + '0';
    }
};