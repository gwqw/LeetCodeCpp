/**
    239. Sliding Window Maximum
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:
Input: nums = [1], k = 1
Output: [1]

Example 3:
Input: nums = [1,-1], k = 1
Output: [1,-1]

Example 4:
Input: nums = [9,11], k = 2
Output: [11]

Example 5:
Input: nums = [4,-2], k = 2
Output: [4]

Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= nums.length

Algo1: naive: sliding window + map

Algo2: monotinic queue
queue has only monotonic decrease values
push_back(n):
    while not q.empty() and q.back() < num
        q.pop_back()
    q.push(num)
pop_front(n):
    if (q.front() == n) {
        q.pop_front()
    }
get_max():
    return q.front()
*/

// 528 ms
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // fill sliding window
        map<int, int> cnt;
        for (size_t i = 0; i < k; ++i) {
            ++cnt[nums[i]];
        }
        
        // move window and fill res
        vector<int> res;
        res.reserve(nums.size() - k + 1);
        res.push_back(prev(cnt.end())->first);
        for (size_t i = k; i < nums.size(); ++i) {
            // remove i-k
            --cnt[nums[i-k]];
            if (cnt[nums[i-k]] == 0) cnt.erase(nums[i-k]);
            // add i
            ++cnt[nums[i]];
            // find max
            res.push_back(prev(cnt.end())->first);
        }
        return res;
    }
};

class Solution {
    struct MonoQueue {
        void push_back(int n) {
            while (!q.empty() && q.back() < n) {
                q.pop_back();
            }
            q.push_back(n);
        }
        
        void pop_front(int n) {
            if (q.front() == n) {
                q.pop_front();
            }
        }
        
        int get_max() const {
            assert(!q.empty());
            return q.front();
        }
        
        deque<int> q;
    };
    
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // fill sliding window
        MonoQueue q;
        for (size_t i = 0; i < k; ++i) {
            q.push_back(nums[i]);
        }
        
        // move window and fill res
        vector<int> res;
        res.reserve(nums.size() - k + 1);
        res.push_back(q.get_max());
        for (size_t i = k; i < nums.size(); ++i) {
            // remove i-k
            q.pop_front(nums[i-k]);
            // add i
            q.push_back(nums[i]);
            // find max
            res.push_back(q.get_max());
        }
        return res;
    }
};