/**
    703. Kth Largest Element in a Stream
Design a class to find the kth largest element in a stream. 
Note that it is the kth largest element in the sorted order, not the kth distinct element.

Your KthLargest class will have a constructor which accepts an integer k and an integer array n_, 
which contains initial elements from the stream. 
For each call to the method KthLargest.add, 
return the element representing the kth largest element in the stream.

Example:
int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8

Note:
You may assume that n_' length ≥ k-1 and k ≥ 1.

Algo1: sorted vector: O(NlogN) ctor, O(N) add, O(1) mem
- ctor
    - sort array in ctor O(NlogN)
- add
    - add num to array to correct pos O(N + logN)
        - upper_bound and insert to to it
    - return k-th num O(1)

Algo2: multiset O(NlogN) in ctor && O(logN + k) add, O(N)
- ctor:
    - add values to multiset in ctor: O(NlogN)
add
    - add value to multiset: O(logN)
    - return k-th element: O(k <- ?)

Algo3: priority_queue: ctor O(NlogN), add O(1) or O(logK)
- ctor
    - sort vector O(NlogN)
    - add k values to p_q O(klogk)
- add
    - if value > p_q.top: return p_q.top
    - push value to p_q
    - pop value
    - return top

*/

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : n_(nums), k(k) {
        if (k < nums.size()) {
            partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
            n_.resize(k);
        } else {        
            sort(nums.begin(), nums.end(), greater<int>());
        }
    }
    
    int add(int val) {
        if (n_.size() == k && val < n_.back()) return n_.back();
        auto it = upper_bound(n_.begin(), n_.end(), val, greater<int>());
        n_.insert(it, val);
        n_.resize(k);
        return n_.back();
    }
private:
    vector<int>& n_;
    int k;
};

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k)
    {
        if (k < nums.size()) {
            partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
        } else {        
            sort(nums.begin(), nums.end(), greater<int>());
        }
        for (auto it = nums.begin(); it != nums.end() && it != nums.begin() + k; ++it) {
            s.insert(*it);
        }
    }
    
    int add(int val) {
        if (s.size() == k && val < *s.begin()) {
            return *s.begin();
        }
        
        if (s.size() == k) {
            s.erase(s.begin());
        }
    
        s.insert(val);
        return *s.begin();
    }
private:
    multiset<int> s;
    int k;
};

class KthLargest {
public:
KthLargest(int k, vector<int>& nums) : k(k) {
        if (k < nums.size()) {
            partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
        } else {        
            sort(nums.begin(), nums.end(), greater<int>());
        }
        for (auto it = nums.begin(); it != nums.end() && it != nums.begin() + k; ++it) {
            pq.push(*it);
        }
    }
    
    int add(int val) {
        if (pq.size() == k && val < pq.top()) {
            return pq.top();
        }
        if (pq.size() == k) {
            pq.pop();
        }
        pq.push(val);
        return pq.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
};


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, n_);
 * int param_1 = obj->add(val);
 */
