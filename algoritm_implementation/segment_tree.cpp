/*
    Segment Tree
build(a, n=1, tl=0, tr=n-1):
    if tl == tr:
        t[v] = a[tl]
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
        t[v] = val
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
