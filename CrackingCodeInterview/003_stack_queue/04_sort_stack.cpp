/**
Write a program to sort a stack in ascending order. You should not make any assump-
tions about how the stack is implemented. The following are the only functions that
should be used to write this program: push | pop | peek | isEmpty.

Algo:
sort(stack):
    if (stack.size() <= 1) return;
    mv = stack.pop()
    st1 = stack()
    st2 = stack()
    while (!stack.empty()) {
        v = stack.pop()
        if (v <= mv):
            st1.push(v)
        else:
            st2.push(v)
    }
    sort(st1)
    sort(st2)
    while (!st1.empty()):
        stack.push(st1.pop())
    stack.push(mv)
    while (!st2.empty()):
        stack.push(st2.pop())
*/

#include <deque>

template <typename T>
class Stack {
public:
    void push(const T& value) {
        data_.push_back(value);
    }
    void push(T&& value) {
        data_.push_back(std::move(value));
    }
    T pop() {
        auto temp = std::move(data_.back());
        data_.pop_back();
        return temp;
    }
    const T& top() const {
        return data_.back();
    }
    bool empty() const {
        return data_.empty();
    }
    std::size_t size() const {return data_.size();}
    friend std::ostream& operator<<(std::ostream& out, const Stack& st) {
        for (const auto& v : st.data_) {
            out << v << ", ";
        }
        return out;
    }
private:
    std::deque<T> data_;
};
using namespace std;

void append_stack(Stack<int>& stack_to, Stack<int>& stack_from) {
    while (!stack_from.empty()) {
       stack_to.push(stack_from.pop());
    }
}

void sort_stack(Stack<int>& stack, bool frwrd = false) {
    if (stack.size() <= 1) return;

    auto mv = stack.pop();
    Stack<int> st1, st2;
    while (!stack.empty()) {
        auto v = stack.pop();
        if (v <= mv) {
            st1.push(move(v));
        } else {
            st2.push(move(v));
        }
    }
    sort_stack(st1, !frwrd);
    sort_stack(st2, !frwrd);
    if (frwrd) {
      append_stack(stack, st1);
      stack.push(mv);
      append_stack(stack, st2);
    } else {
      append_stack(stack, st2);
      stack.push(mv);
      append_stack(stack, st1);
    }
}





