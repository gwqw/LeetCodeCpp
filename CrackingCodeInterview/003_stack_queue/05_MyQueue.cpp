/**
Implement a MyQueue class which implements a queue using two stacks.

Algo:
    push(element): // O(1)
        stack1.push(element)
    pop(): O(1) <- average
        if (!stack2.empty()):
            return stack2.pop()
        while(!stack1.empty()):
            element = stack1.pop()
            stack2.push(element)
        return stack2.pop()
*/

#includes <stack>

using namespace std;

class MyQueue {
public:
    void push(int element) {
        st_for_.push(element);
    }
    int pop() {
        if (!st_rew_.empty()) {
            int i = st_rew_.top();
            st_rew_.pop();
            return i;
        }
        while (!st_for_.empty()) {
            int el = st_for_.top();
            st_for_.pop();
            st_rew_.push(el);
        }
        int el = st_rew_.top();
        st_rew_.pop();
        return el;
    }
private:
    stack<int> st_for_;
    stack<int> st_rew_;
};