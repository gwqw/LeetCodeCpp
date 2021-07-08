/**
    227. Basic Calculator II
Given a string s which represents an expression, evaluate this expression and return its value. 
The integer division should truncate toward zero.
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:
Input: s = "3+2*2"
Output: 7

Example 2:
Input: s = " 3/2 "
Output: 1

Example 3:
Input: s = " 3+5 / 2 "
Output: 5

Constraints:
1 <= s.length <= 3 * 10^5
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 2^31 - 1].
The answer is guaranteed to fit in a 32-bit integer.

Algo1:
- tokenize
- first pass: make op *, /
- second pass: op +, -
return

Algo2: метод рекурсивного спуска
expression = term {('+' | '-') term }
term = factor {('*') factor }
factor = number | ('-') factor
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
        auto [nums, ops] = tokenize(s);
        assert(nums.size() == ops.size()+1);
        
        // first pass
        vector<int> nums1; nums1.reserve(nums.size());
        vector<char> ops1; ops1.reserve(ops.size());
        int prev_num = nums[0];
        for (size_t i = 0; i < ops.size(); ++i) {
            char op = ops[i];
            int num = nums[i+1];
            if (op == '+' || op == '-') {
                nums1.push_back(prev_num);
                prev_num = num;
                ops1.push_back(op);
            } else {
                if (op == '*') {
                    prev_num *= num;
                } else {
                    prev_num /= num;
                }
            }
        }
        nums1.push_back(prev_num);
        
        // second pass
        assert(nums1.size() >= 1 && nums1.size() == ops1.size() + 1);
        int ans = nums1[0];
        for (size_t i = 0; i < ops1.size(); ++i) {
            char op = ops1[i];
            int num = nums1[i+1];
            if (op == '+') {
                ans += num;
            } else {
                ans -= num;
            }
        }
        return ans;        
    }
    
private:
    pair<vector<int>, vector<char>> tokenize(string_view s) {
        vector<int> nums;
        vector<char> ops;
        auto b = s.begin();
        while (true) {
            // extract num
            for (; b != s.end(); ++b) {
                if (*b != ' ') break;
            }
            int num = 0;
            auto [e, err] = from_chars(b, s.end(), num);
            nums.push_back(num);
            if (e == s.end()) return {nums, ops};
            // extract op
            for (b = e; b != s.end(); ++b) {
                if (*b != ' ') break;
            }
            if (b == s.end()) return {nums, ops};
            char op = *b++;
            ops.push_back(op);
        }
        throw runtime_error("Smth goes wrong");
    }    
};


/*
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
        return number();
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