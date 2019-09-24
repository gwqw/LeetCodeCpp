/**
How would you design a stack which, in addition to push and pop, 
also has a function min which returns the minimum element? 
Push, pop and min should all operate in O(1) time.
*/

#include <stack>

using namespace std;

class MinStack {
public:
    void push(int value) {
        data_.push(value);
        if (!mins_.empty()) {
            mins_.push(min(mins_.top(), value));
        } else {
          mins_.push(value);
        }
    }
    void pop() {
        data_.pop();
        mins_.pop();
    }
    int min() const {
        return mins_.top();
    }
private:
    stack<int> data_;
    stack<int> mins_;
};
