/**
    155. Min Stack
Design a stack that supports push, pop, top, 
and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

Algo: two stacks, one saves value, next saves mins on this step: O(1) -- all operations, O(N)
- make stv, stm
- push:
    - push value to stv
    - push min(value, stm.top()) to stm (if stm isn't empty)
- pop:
    - pop val from stv
    - pop val from stm
- top:
    - return stv.top()
- getMin:
    - return stm.top()
    
Algo (unworking): one stack and min_value
- make one stack, and min_value as MAX_INT
- push:
    - push value to st
    - if min_value < value: min_value = value
- pop:
    - pop_val = st.top
    - st.pop
    - if pop_val == min_value: min_value = st.top
    

*/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stv.push(x);
        if (!stm.empty()) {
            stm.push(min(x, stm.top()));
        } else {
            stm.push(x);
        }
    }
    
    void pop() {
        stv.pop();
        stm.pop();
    }
    
    int top() {
        return stv.top();
    }
    
    int getMin() {
        return stm.top();
    }
    
private:
    stack<int, vector<int>> stv, stm;
};

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (!st.empty()) {
            st.push({x, min(x, getMin())});
        } else {
            st.push({x,x});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
    
private:
    stack<pair<int, int>, vector<pair<int, int>>> st;
};

/*
-2  0 -3
-2 -2 -3
*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
