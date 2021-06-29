/**
    895. Maximum Frequency Stack
Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

Implement the FreqStack class:
FreqStack() constructs an empty frequency stack.
void push(int val) pushes an integer val onto the top of the stack.
int pop() removes and returns the most frequent element in the stack.
If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.

Example 1:
Input
["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]
Output
[null, null, null, null, null, null, null, 5, 7, 5, 4]

Explanation
FreqStack freqStack = new FreqStack();
freqStack.push(5); // The stack is [5]
freqStack.push(7); // The stack is [5,7]
freqStack.push(5); // The stack is [5,7,5]
freqStack.push(7); // The stack is [5,7,5,7]
freqStack.push(4); // The stack is [5,7,5,7,4]
freqStack.push(5); // The stack is [5,7,5,7,4,5]
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].

Constraints:
0 <= val <= 10^9
At most 2 * 10^4 calls will be made to push and pop.
It is guaranteed that there will be at least one element in the stack before calling pop.

Algo1: dicts
dfreq:  [n]->cnt
df2num: [cnt]->[n1, n2, ..., nk]
def push(n):
    if n in dfreq:
        cnt = dfreq[n]+1
    else:
        cnt = 1
    dfreq[n] = cnt
    df2num[cnt].push_back(n)
def pop():
    n, cnt = prev(df2num.end()).back()
    df2num.end()-1.pop_back()
    dfreq[n] -= 1
    return n

Algo2: same but use unordered and max_value

*/

class FreqStack {
public:
    FreqStack() {
        
    }
    
    void push(int n) {
        int cnt = 1;
        if (dn2f.count(n)) {
            cnt = dn2f[n]+1;
        }
        dn2f[n] = cnt;
        df2n[cnt].push_back(n);
    }
    
    int pop() {
        assert(!df2n.empty());
        auto it = prev(df2n.end());
        int cnt = it->first-1;
        auto& lst = it->second;
        int n = lst.back();
        lst.pop_back();
        if (lst.empty()) {
            df2n.erase(it);
        }
        if (cnt > 0) {
            dn2f[n] = cnt;
        } else {
            dn2f.erase(n);
        }
        return n;
    }

private:
    unordered_map<int, int> dn2f;
    map<int, vector<int>> df2n;
};

class FreqStack {
public:
    FreqStack() {
        
    }
    
    void push(int n) {
        int cnt = 1;
        if (dn2f.count(n)) {
            cnt = dn2f[n]+1;
        }
        dn2f[n] = cnt;
        df2n[cnt].push_back(n);
        if (cnt > max_freq) max_freq = cnt;
    }
    
    int pop() {
        assert(!df2n.empty() && max_freq > 0);
        int cnt = max_freq-1;
        auto& lst = df2n[max_freq];
        int n = lst.back();
        lst.pop_back();
        if (lst.empty()) {
            df2n.erase(max_freq);
            --max_freq;
        }
        if (cnt > 0) {
            dn2f[n] = cnt;
        } else {
            dn2f.erase(n);
        }
        return n;
    }

private:
    unordered_map<int, int> dn2f;
    unordered_map<int, vector<int>> df2n;
    int max_freq = 0;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */