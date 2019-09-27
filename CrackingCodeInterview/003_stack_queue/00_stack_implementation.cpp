/**
    Simple stack implementation
    push
    pop
    top
    empty
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
