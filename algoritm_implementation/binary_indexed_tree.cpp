/**
    Binary Indexed Tree (BIT or Fenwick tree)
Find range sums with updates happens
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
    vector<int> a; // need to calc diff
};