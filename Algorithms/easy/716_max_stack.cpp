/**
    716. Max Stack
Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
Example 1:
MaxStack stack = new MaxStack();
stack.push(5); 
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5
Note:
-1e7 <= x <= 1e7
Number of operations won't exceed 10000.
The last four operations won't be called when stack is empty.

Algo1: 2 stacks O(N) for pop_max, O(1) for other, O(N) for mem

Algo2: list for vals and map for max[val]->it: O(logN) for all operations, O(N) mem

Algo3 : list + monotnoic stack (not working)

*/

class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        stv.push(x);
        if (!stm.empty()) {
            stm.push(max(x, stm.top()));
        } else {
            stm.push(x);
        }
    }
    
    int pop() {
        auto res = stv.top();
        stv.pop();
        stm.pop();
        return res;
    }
    
    int top() {
        return stv.top();
    }
    
    int peekMax() {
        return stm.top();
    }
    
    int popMax() {
        auto res = stm.top();
        stack<int> tmp;
        // search max value
        while (stv.top() != res) {
            tmp.push(pop());
        }
        // remove from stack
        stv.pop();
        stm.pop();
        // push values back
        while(!tmp.empty()) {
            push(tmp.top());
            tmp.pop();
        }
        return res;
    }
private:
    stack<int, vector<int>> stv, stm;
};

class MaxStack {
    using Iterator = list<int>::iterator;
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        data.push_back(x);
        maxs[x].push_back(prev(data.end()));
    }
    
    int pop() {
        auto res = data.back();
        data.pop_back();
        auto it = maxs.find(res);
        if (it->second.size() == 1) {
            maxs.erase(it);
        } else {
            it->second.pop_back();
        }
        return res;
    }
    
    int top() {
        return data.back();
    }
    
    int peekMax() {
        return prev(maxs.end())->first;
    }
    
    int popMax() {
        auto jt = prev(maxs.end());
        auto res = jt->first;
        auto it = jt->second.back();
        data.erase(it);
        if (jt->second.size() == 1) {
            maxs.erase(jt);
        } else {
            jt->second.pop_back();
        }      
        return res;
    }
private:
    list<int> data;
    map<int, vector<Iterator>> maxs;
};


/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */



