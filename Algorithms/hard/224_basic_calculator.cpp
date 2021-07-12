/**
    224. Basic Calculator
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:
Input: s = "1 + 1"
Output: 2

Example 2:
Input: s = " 2-1 + 2 "
Output: 3

Example 3:
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23

Example 4:
Input: s = "+48 + -48"
Output: 0
Explanation: Numbers can have multiple digits and start with +/-.

Constraints:
1 <= s.length <= 3 * 10^5
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
Every number and running calculation will fit in a signed 32-bit integer.

Algo: метод рекурсивного спуска (227 prev)
expression = term {('+' | '-') term }
term = factor {('*') factor }
factor = number | ('-') factor | '(' expression ')'
number = 0..9 {0..9}

expression():
t1 = term()
while (true):
    if (c == '+') {
        t2 = term()
        t1 += t2
    } else if (c == '-') {
        t2 = term()
        t1 -= t2
    } else {
        return t1
    }

term:
    f1 = factor()
    while true:
        if c == '*':
            t2 = factor()
            t1 *= t2
        else if c == '/':
            t2 = factor()
            t1 /= t2
            
factor:
    if c == '+':
        nextChar()
        return factor()
    else if c == '-':
        readChar()
        return -factor()
    else if c == '(':
        nextChar()
        res = expression()
        nextChar()
        return res
    else:
        return number()
    
number:
    n = 0
    while c in {0..9}:
        d = c - '0'
        n = n*10 + d
        nextChar()
    return n
*/

class Solution {
public:
    int calculate(string_view s) {
        this->s = s;
        readNext();
        return expression();
    }

private:
    int expression() {
        int t1 = term();
        while (true) {
            if (c == '+') {
                readNext();
                int t2 = term();
                t1 += t2;
            } else if (c == '-') {
                readNext();
                int t2 = term();
                t1 -= t2;
            } else {
                return t1;
            }
        }
    }
    
    int term() {
        int f1 = factor();
        while (true) {
            if (c == '*') {
                readNext();
                int f2 = factor();
                f1 *= f2;
            } else if (c == '/') {
                readNext();
                int f2 = factor();
                f1 /= f2;
            } else {
                return f1;
            }
        }
    }
    
    int factor() {
        if (c == '+') {
            readNext();
            return factor();
        } else if (c == '-') {
            readNext();
            return -factor();
        } else if (c == '(') {
            readNext();
            int res = expression();
            assert(c == ')');
            readNext();
            return res;
        } else {
            return number();
        }
    }
    
    int number() {
        int n = 0;
        while ('0' <= c && c <= '9') {
            int d = c - '0';
            n = n*10 + d;
            readNext();
        }
        return n;
    }
    
    void readNext() {
        if (pos == s.size()) {
            c = -1;
            return;
        }
        c = s[pos++];
        while (pos < s.size() && c == ' ') {
            c = s[pos++];
        }
    }

private:
    string_view s;
    int pos = 0;
    int c = 0;
};