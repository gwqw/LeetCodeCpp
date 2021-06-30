/**
    1146. Snapshot Array
Implement a SnapshotArray that supports the following interface:
- SnapshotArray(int length) initializes an array-like data structure with the given length.  Initially, each element equals 0.
- void set(index, val) sets the element at the given index to be equal to val.
- int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
- int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id

Example 1:
Input: ["SnapshotArray","set","snap","set","get"]
[[3],[0,5],[],[0,6],[0,0]]
Output: [null,null,0,null,5]
Explanation: 
SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
snapshotArr.set(0,5);  // Set array[0] = 5
snapshotArr.snap();  // Take a snapshot, return snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return 5

Constraints:
1 <= length <= 50000
At most 50000 calls will be made to set, snap, and get.
0 <= index < length
0 <= snap_id < (the total number of times we call snap())
0 <= val <= 10^9

Algo1: vector of map: O(logN) set and get
vector[idx]->snap_map[snap]->value
set(idx, value):
    v[idx][cur_snap] = value
snap():
    return ++cur_snap
get(idx, snap):
    it = v[idx].upper_bound(snap_idx)
    prev(it).value or 0    
    
Algo2: vector of vector<pair>: O(1) set, O(logN) get
*/

class SnapshotArray {
public:
    SnapshotArray(int length) 
        : v(length)
    {}
    
    void set(int idx, int val) {
        v[idx][cur_snap] = val;
    }
    
    int snap() {
        return cur_snap++;
    }
    
    int get(int idx, int snap_id) {
        const auto& m = v[idx];
        auto it = m.upper_bound(snap_id);
        if (it == m.begin()) return 0;
        it = prev(it);
        return it->second;
    }
    
private:
    int cur_snap = 0;
    vector<map<int, int>> v;
};

class SnapshotArray {
public:
    SnapshotArray(int length) 
        : v(length)
    {}
    
    void set(int idx, int val) {
        v[idx].emplace_back(cur_snap, val);
    }
    
    int snap() {
        return cur_snap++;
    }
    
    int get(int idx, int snap_id) {
        const auto& m = v[idx];
        auto it = upper_bound(m.begin(), m.end(), snap_id, 
            [](const int value, const auto& element) {
                return value < element.first;
            }
        );
        if (it == m.begin()) return 0;
        it = prev(it);
        return it->second;
    }
    
private:
    int cur_snap = 0;
    vector<vector<pair<int, int>>> v;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
