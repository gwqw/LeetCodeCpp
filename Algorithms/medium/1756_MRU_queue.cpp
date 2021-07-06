/**
    1756. Design Most Recently Used Queue
Design a queue-like data structure that moves the most recently used element to the end of the queue.
Implement the MRUQueue class:
- MRUQueue(int n) constructs the MRUQueue with n elements: [1,2,3,...,n].
- int fetch(int k) moves the kth element (1-indexed) to the end of the queue and returns it.

Example 1:
Input:
["MRUQueue", "fetch", "fetch", "fetch", "fetch"]
[[8], [3], [5], [2], [8]]
Output:
[null, 3, 6, 2, 2]

Explanation:
MRUQueue mRUQueue = new MRUQueue(8); // Initializes the queue to [1,2,3,4,5,6,7,8].
mRUQueue.fetch(3); // Moves the 3rd element (3) to the end of the queue to become [1,2,4,5,6,7,8,3] and returns it.
mRUQueue.fetch(5); // Moves the 5th element (6) to the end of the queue to become [1,2,4,5,7,8,3,6] and returns it.
mRUQueue.fetch(2); // Moves the 2nd element (2) to the end of the queue to become [1,4,5,7,8,3,6,2] and returns it.
mRUQueue.fetch(8); // The 8th element (2) is already at the end of the queue so just return it.

Constraints:
1 <= n <= 2000
1 <= k <= n
At most 2000 calls will be made to fetch.

Follow up: Finding an O(n) algorithm per fetch is a bit easy. Can you find an algorithm with a better complexity for each fetch call?

Algo1: naive: deque
fetch:
	remove: O(N)
	push_back: O(1)

Algo2: sqrt-decomposition 
use sqrt(n) chunks
*/

class MRUQueue {
public:
    MRUQueue(int n) 
        : q(n)
    {
        iota(q.begin(), q.end(), 1);
    }
    
    int fetch(int k) {
        int val = q[k-1];
        q.erase(remove(q.begin(), q.end(), val), q.end());
        q.push_back(val);
        return val;
    }
	
private:
	deque<int> q; 
};

class MRUQueue {
	using Chunk = vector<int>;
	
	struct ChunkVector {
		ChunkVector(size_t size) {
			chunk_size = max((int)sqrt(size), 1);
			if (size % chunk_size == 0) {
				data.resize(size / chunk_size);
			} else {
				data.resize(size / chunk_size + 1);
			}
		}
		
		void fill_iota(int n) {
			int i = 1;
			for (auto& chunk : data) {
			    for (size_t j = 0; j < chunk_size; ++j) {
			        chunk.push_back(i++);
			        if (i == n+1) break;
			    }
				if (i == n+1) break;
			}
			assert(data.back().size() != 0);
		}
		
		int pop(int idx) {
			int cur_idx = 1;
			int chunk_idx = 0;
			for (; chunk_idx < data.size(); ++chunk_idx) {
				cur_idx += data[chunk_idx].size();
				if (cur_idx > idx) break;
			}
			cur_idx -= data[chunk_idx].size();
			int val = data[chunk_idx][idx - cur_idx];
			data[chunk_idx].erase(
				remove(data[chunk_idx].begin(), data[chunk_idx].end(), val),
				data[chunk_idx].end()
			);
			if (data[chunk_idx].empty()) {
			    data.erase(data.begin() + chunk_idx);
			}
			return val;
		}
		
		void push(int val) {
			if (!data.empty() && data.back().size() < chunk_size) {
				data.back().push_back(val);
			} else {
				data.push_back(Chunk{});
				data.back().push_back(val);
			}
		}
		
		size_t chunk_size = 1;
		vector<Chunk> data;
	};
public:
    MRUQueue(int n)
        : data(n)
    {
        data.fill_iota(n);
    }
    
    int fetch(int k) {
        int val = data.pop(k);
        data.push(val);
        return val;
    }
	
private:
	ChunkVector data;
};

class MRUQueue {
	using Chunk = vector<int>;
	
	struct ChunkVector {
		ChunkVector(size_t size) {
			chunk_size = max((int)sqrt(size), 1);
			if (size % chunk_size == 0) {
				data.resize(size / chunk_size);
			} else {
				data.resize(size / chunk_size + 1);
			}
		}
		
		void fill_iota(int n) {
			int i = 1;
			for (auto& chunk : data) {
			    for (size_t j = 0; j < chunk_size; ++j) {
			        chunk.push_back(i++);
			        if (i == n+1) break;
			    }
				if (i == n+1) break;
			}
			assert(data.back().size() != 0);
		}
		
		pair<int,bool> pop_not_last(int idx) {
			int cur_idx = 1;
			int chunk_idx = 0;
			for (; chunk_idx < data.size(); ++chunk_idx) {
				cur_idx += data[chunk_idx].size();
				if (cur_idx > idx) break;
			}
			cur_idx -= data[chunk_idx].size();
			int val = data[chunk_idx][idx - cur_idx];
			if (chunk_idx + 1 == data.size() && idx-cur_idx+1 == data.back().size()) {
			    return {val, false};
			}
			data[chunk_idx].erase(
				remove(data[chunk_idx].begin(), data[chunk_idx].end(), val),
				data[chunk_idx].end()
			);
			if (data[chunk_idx].empty()) {
			    data.erase(data.begin() + chunk_idx);
			}
			return {val, true};
		}
		
		void push(int val) {
			if (!data.empty() && data.back().size() < chunk_size) {
				data.back().push_back(val);
			} else {
				data.push_back(Chunk{});
				data.back().push_back(val);
			}
		}
		
		size_t chunk_size = 1;
		vector<Chunk> data;
	};
public:
    MRUQueue(int n)
        : data(n)
    {
        data.fill_iota(n);
    }
    
    int fetch(int k) {
        auto [val,res] = data.pop_not_last(k);
        if (res) {
            data.push(val);
        }
        return val;
    }
	
private:
	ChunkVector data;
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */