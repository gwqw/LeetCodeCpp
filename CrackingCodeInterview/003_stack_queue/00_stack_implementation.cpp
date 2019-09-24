/**
    Simple stack implementation
    push
    pop
    top
    empty
*/

#include <deque>

using namespace std;

template <typename T>
class Stack {
public:
    void push(const T& value) {
        data_.push_back(value);
    }
    T pop() {
        return data_.pop_back();
    }
    const T& top() const {
        return data_.back();
    }
    bool empty() const {
        return data_.empty();1
    }
private:
    deque<T> data_;
};