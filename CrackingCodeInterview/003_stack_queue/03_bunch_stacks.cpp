/**
Imagine a (literal) stack of plates. If the stack gets too high, it might topple. There-
fore, in real life, we would likely start a new stack when the previous stack exceeds
some threshold. Implement a data structure SetOfStacks that mimics this. SetOf-
Stacks should be composed of several stacks, and should create a new stack once
the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should
behave identically to a single stack (that is, pop() should return the same values as it
would if there were just a single stack).

Algo:
    make vector<stack<T>>
    cur_idx = 0
    vec_idx = cur_idx // capacity
    stack_idx = cur_idx % capacity
*/

#include <stack>
#include <vector>

using namespace std;

class BunchStack {
public:
    explicit BunchStack(size_t capacity) : capacity_(capacity) {}
    void push(int value) {
        size_t vidx = idx / capacity_;
        if (vidx >= data_.size()) {
            data_.resize(vidx+1);
        }
        //size_t sidx = idx % capacity_;
        data_[vidx].push(value);
        idx++;
    }
    int pop() {
        idx--;
        size_t vidx = idx / capacity_;
        return data_[vidx].top();
        data_[vidx].pop();
    }
    friend ostream& operator<<(ostream& out, const BunchStack& st) {
        size_t vidx = st.idx / st.capacity_ + 1;
        for (size_t i = 0; i < vidx; ++i) {
            for (const auto v : st.data_[i]) {
                out << v << ", ";
            }
            out << '\n';
        }
        return out;
    }
private:
    size_t capacity_{0};
    vector<stack<int>> data_;
    size_t idx{0};
};

