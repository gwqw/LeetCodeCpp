/**
    933. Number of Recent Calls
Write a class RecentCounter to count recent requests.
It has only one method: ping(int t), where t represents some time in milliseconds.
Return the number of pings that have been made from 3000 milliseconds ago until now.
Any ping with time in [t - 3000, t] will count, including the current ping.
It is guaranteed that every call to ping uses a strictly larger value of t than before.

Example 1:
Input: inputs = ["RecentCounter","ping","ping","ping","ping"], inputs = [[],[1],[100],[3001],[3002]]
Output: [null,1,2,3,3]

Note:
Each test case will have at most 10000 calls to ping.
Each test case will call ping with strictly increasing values of t.
Each call to ping will have 1 <= t <= 10^9.

Algo1: map (BST)    O(NlogN) + O(N)
- have map: key = time, count
- have calls counter = 0
ping:
- counter++
- calc threshold
- find element lower_bound with key == threshold
- if it != begin
    - --it
    - get counter -= value
- put to map {t, counter}     O(logN)
- return counter

    1   100 3001    3002
    1   2   3       3+1-1
    ^ ^
    1 2
    
Algo2: use queue and paste values here amortized O(N) + O(1)
- have counter
- ping:
    - ++counter
    - add value to queue
    - remove values from queue while t < treshold and --counter
    - return counter
    
Algo3: Algo2 with own Queue
*/

class RecentCounter {
public:
    RecentCounter() = default;
    
    int ping(int t) {
        data_[t] = ++counter_;
        int threshold = t > 3000 ? t - 3000 : 0;
        int was = 0;
        if (auto it = data_.lower_bound(threshold); it != data_.begin()) {
            was = prev(it)->second;
        }        
        return counter_ - was;
    }
    
private:
    std::map<int, int> data_;
    int counter_ = 0;
};

class RecentCounter {
public:
    RecentCounter() = default;
    
    int ping(int t) {
        q_.push(t);
        while (q_.front() < t - 3000) {
            q_.pop();
        }
        return q.size();
    }
private:
    queue<int> q_;
};


template <typename T, std::size_t N>
class CycleQueue {
public:
    // getters
    const T& front() const {
        return data_[b_];
    }
    const T& back() const {
        return data_[(e_-1) % N];
    }
    bool empty() const {
        return false;
    }
    std::size_t size() const {
        return 0;
    }
    // modifiers
    void push(const T& value) {
        data_[e_++] = value;
        e_ %= N;
    }
    void pop() {
        b_ = (b_ + 1) % N;
    }
private:
    std::array<T, N> data_;
    std::size_t b_ = 0;
    std::size_t e_ = 0;
};

template <std::size_t N>
class IntCycleQueue {
public:
    // getters
    int front() const {
        return data_[b_];
    }
    bool empty() const {
        return size_ == 0;
    }
    std::size_t size() const {
        return size_;
    }
    // modifiers
    void push(int value) {
        data_[e_++] = value;
        if (e_ == N) {
            e_ = 0;
        }
        ++size_;
    }
    void pop() {
        ++b_;
        if (b_ == N) {
            b_ = 0;
        }
        --size_;
    }
private:
    std::array<int, N> data_;
    std::size_t b_ = 0;
    std::size_t e_ = 0;
    std::size_t size_ = 0;
};
    
class RecentCounter {
public:
    RecentCounter() = default;
    
    int ping(int t) {
        while (!q_.empty() && q_.front() < t - 3000) {
            q_.pop();
        }      
        q_.push(t);
        return q_.size();
    }
private:
    IntCycleQueue<3001> q_;    
};



/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

