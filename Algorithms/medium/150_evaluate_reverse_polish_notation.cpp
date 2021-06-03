/**
    150. Evaluate Reverse Polish Notation
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
Note that division between two integers should truncate toward zero.
It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

Example 1:
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

Constraints:
1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

Algo: stack
take tokens:
    if token is num: 
        push to stack(n)
    else:
        n2, n1 = pop from stack
        make operation(n1, n2, op)
        push res to stack
*/

class Solution {
public:
    int evalRPN(const vector<string>& tokens) {
        stack<int, vector<int>> nums;
        for (auto token : tokens) {
            if (is_num(token)) {
                nums.push(stoi(token));
            } else {
                char op = token[0];
                auto n2 = nums.top();
                nums.pop();
                auto n1 = nums.top();
                nums.pop();
                nums.push(
                    make_operation(n1, n2, op));
            }
        }
        return nums.top();
    }
    
private:
    bool is_num(string_view s) {
        return s.size() > 1 || ('0' <= s[0] && s[0] <= '9');
    }
    
    int make_operation(int n1, int n2, char op) {
        switch (op) {
            case '+':
                return n1 + n2;
            case '-':
                return n1 - n2;
            case '*':
                return n1 * n2;
            case '/':
                return n1 / n2;
            default:
                throw invalid_argument("Bad operation");
        }
    }
};
