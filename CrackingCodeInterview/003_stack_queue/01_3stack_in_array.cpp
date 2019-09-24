/**
    Describe how you could use a single array to implement three stacks.
    
    Algo:
    i1 = 3*i1
    i2 = 3*i+1
    i3 = 3*i+2
*/

#include <vector>

using namespace std;

class ThreeStacks {
public:
    void push1(int value) {
        size_t idx = get_idx1(i1++);
        resize(idx);
        data_[idx] = value;
    }
    void push2(int value) {
        size_t idx = get_idx2(i2++);
        resize(idx);
        data_[idx] = value;
    }
    void push3(int value) {
        size_t idx = get_idx3(i3++);
        resize(idx);
        data_[idx] = value;
    }
    int pop1() {
        size_t idx = get_idx(--i1)
        return data_[idx];
    }
private:
    vector<int> data_;
    size_t i1{0}, i2{0}, i3{0};
    void resize(size_t idx) {
        if (idx+1 > data_.size()) {
            if (idx == 0) idx = 1;
            data.resize(2*idx);
        }
    }
    static size_t get_idx1(size_t i) {return 3*i;}
    static size_t get_idx2(size_t i) {return 3*i+1;}
    static size_t get_idx3(size_t i) {return 3*i+2;}
};