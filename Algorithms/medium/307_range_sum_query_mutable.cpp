/**
    307. Range Sum Query - Mutable
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
The update(i, val) function modifies nums by updating the element at index i to val.

Example:
Given nums = [1, 3, 5]
sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8

Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.

Algo1: sqrt decomposition O(sqrt(N))

Algo2: Binary Indexed Tree (BIT or Fenwick tree)
sum(r):
    s = 0
    while i > 0:
        s += t[i]
        i = i & (i+1)-1
    return s

sum(l, r):
    sum(r) - sum(l-1)
    
update(i, val):
    while i < n:
        t[i] += val
        i = i | (i+1)
        
init(a : array):
    t(a.size())
    for i,v in a:
        update(i, v)
        
Algo3: segment tree
build(a):
    build(a, n=1, l=0, r=n-1)

build(a, n, tl, tr):
    if tl == tr:
        t[tl] = a[tl]
    else:
        tm = (tl+tr) / 2
        build(a, 2*n, tl, tm)
        build(a, 2*n+1, tm+1, tr)
        t[n] = t[2*n] + t[2*n+1]
    
sum(l, r):
    sum(1, 0, n-1, l, r)
    
sum(n, tl, tr, l, r):
    if l > r: return 0
    if l == tl and r == tr:
        return t[n]
    tm = (tl + tr) / 2
    return sum(2*n, tl, tm, l, min(r, tm))
         + sum(2*n+1, tm+1, tr, max(l, tm+1), r)

update(i, val):
    update(n, val, 1, 0, n-1)
    
update(i, val, n, tl, tr):
    if tl == tr:
        t[tl] = val
    else:
        tm = (tl+tr)/2
        if i <= tm:
            update(i, val, 2*n, tl, tm)
        else:
            update(i, val, 2*n+1, tm+1, tr)
    t[n] = t[2*n] + t[2*n+1]
    
t = []

*/

class NumArray {
	using Chunk = vector<int>;
	
public:
    NumArray(vector<int>& nums) 
	{
	    chunk_size = max((size_t)sqrt(nums.size()), size_t(1u));
		size_t size = nums.size() % chunk_size == 0 ? nums.size() / chunk_size : nums.size() / chunk_size + 1;
		data.resize(size);
		sums.resize(size);
        int chunk_idx = 0;
		int idx = 0;
		for (int num : nums) {
			data[chunk_idx].push_back(num);
			sums[chunk_idx] += num;
			idx++;
			if (idx == chunk_size) {
				++chunk_idx;
				idx = 0;
				if (chunk_idx < data.size()) {
				    data[chunk_idx].reserve(chunk_size);				
				}
			}
		}
    }
    
    void update(int i, int val) {
        int chunk_idx = i / chunk_size;
		int idx = i % chunk_size;
		sums[chunk_idx] += val - data[chunk_idx][idx];
		data[chunk_idx][idx] = val;
    }
    
    int sumRange(int i, int j) {
        int ch_i = i / chunk_size;
		int ii = i % chunk_size;
		int ch_j = j / chunk_size;
		int ij = j % chunk_size;
		int sum = 0;
		if (ch_i == ch_j) {
		    for (int k = ii; k <= ij; ++k) {
			    sum += data[ch_i][k];
		    }
		} else {
		    // between
		    for (int ch = ch_i+1; ch < ch_j; ++ch) {
			    sum += sums[ch];
		    }
		    // first chunk
		    if (ii != 0) {
			    for (int k = ii; k < data[ch_i].size(); ++k) {
				    sum += data[ch_i][k];
			    }
		    } else {
			    sum += sums[ch_i];
		    }
		    // last chunk
	        if (ij+1 != data[ch_j].size()) {
		        for (int k = 0; k <= ij; ++k) {
			        sum += data[ch_j][k];
		        }
	        } else {
		        sum += sums[ch_j];
	        }
		}
		return sum;
    }
	
private:
	size_t chunk_size = 0;
	vector<Chunk> data;
	vector<int> sums;
	
private:
    void printSums() {
        for (auto s : sums) {
            cout << s << " ";
        }
        cout << '\n';
    }
    
    void printData() {
        int i = 0;
        for (const auto& chunk : data) {
            cout << "chunk" << i++ << ": ";
            for (auto n : chunk) {
                cout << n << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }
};

/*
Algo2: Binary Indexed Tree (BIT or Fenwick tree)
sum(r):
    s = 0
    while i > 0:
        s += t[i]
        i = i & (i+1)-1
    return s

sum(l, r):
    sum(r) - sum(l-1)
    
update(i, val):
    while i < n:
        t[i] += val
        i = i | (i+1)
        
init(a : array):
    t(a.size())
    for i,v in a:
        update(i, v)
*/
class NumArray {
public:
    NumArray(vector<int>& a) 
        : t(a.size()), a(a.size())
    {
        for (int i = 0; i < t.size(); ++i) {
            update(i, a[i]);
        }
    }
    
    void update(int i, int val) {
        int diff = val - a[i];
        a[i] = val;
        while (i < t.size()) {
            t[i] += diff;
            i = (i | (i+1));
        }
    }
    
    int sumRange(int l, int r) {
        return sumTo(r) - sumTo(l-1);
    }
    
private:
    int sumTo(int i) {
        int s = 0;
        while (i >= 0) {
            s += t[i];
            i = (i & (i+1)) - 1;
        }
        return s;
    }
    
private:
    vector<int> t;
    vector<int> a;
};

/*
Algo3: segment tree
build(a, n=1, tl=0, tr=n-1):
    if tl == tr:
        t[tl] = a[tl]
    else:
        tm = (tl+tr) / 2
        build(a, 2*n, tl, tm)
        build(a, 2*n+1, tm+1, tr)
        t[n] = t[2*n] + t[2*n+1]
    
sum(l, r, n=1, tl=0, tr=n-1):
    if l > r: return 0
    if l == tl and r == tr:
        return t[n]
    tm = (tl + tr) / 2
    return sum(l, min(r, tm), 2*n, tl, tm)
         + sum(max(l, tm+1), r, 2*n+1, tm+1, tr)

update(i, val, n=1, tl=0, tr=n-1):
    if tl == tr:
        t[tl] = val
    else:
        tm = (tl+tr)/2
        if i <= tm:
            update(i, val, 2*n, tl, tm)
        else:
            update(i, val, 2*n+1, tm+1, tr)
    t[n] = t[2*n] + t[2*n+1]
    
t = []
*/

class NumArray {
public:
    NumArray(const vector<int>& a) 
        : t(4*a.size()), n(a.size())
    {
        build(a, 1, 0, n-1);
    }
    
    void update(int i, int val) {
        update(i, val, 1, 0, n-1);
    }
    
    int sumRange(int l, int r) {
        return sum(l, r, 1, 0, n-1);
    }
    
private:
    void build(const vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl+tr) / 2;
            build(a, 2*v, tl, tm);
            build(a, 2*v+1, tm+1, tr);
            t[v] = t[2*v] + t[2*v+1];
        }
    }
    
    void update(int i, int val, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = val;
        } else {
            int tm = (tl+tr)/2;;
            if (i <= tm) {
                update(i, val, 2*v, tl, tm);
            } else {
                update(i, val, 2*v+1, tm+1, tr);
            }
            t[v] = t[2*v] + t[2*v+1];
        }
    }
    
    int sum(int l, int r, int v, int tl, int tr) {
        if (l > r) return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return sum(l, min(r, tm), 2*v, tl, tm)
             + sum(max(l, tm+1), r, 2*v+1, tm+1, tr);
    }
    
    void print() {
        for (size_t i = 0; i < t.size(); ++i) {
            cout << i << ':' << t[i] << " ";
        }
        cout << '\n';
    }
    
private:
    vector<int> t;
    int n = 0;
};

["NumArray","sumRange","update","sumRange"]
[[[1,3,5]],[0,2],[1,2],[0,2]]
["NumArray","sumRange","sumRange","sumRange","update","update","update","sumRange","update","sumRange","update"]
[[[0,9,5,7,3]],[4,4],[2,4],[3,3],[4,5],[1,7],[0,8],[1,2],[1,9],[4,4],[3,4]]
["NumArray","sumRange","update","sumRange","sumRange","update","update","sumRange","sumRange","update","update"]
[[[-28,-39,53,65,11,-56,-65,-39,-43,97]],[5,6],[9,27],[2,3],[6,7],[1,-82],[3,-72],[3,7],[1,8],[5,13],[4,-67]]

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
