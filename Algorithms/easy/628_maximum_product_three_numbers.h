/**
    628. Maximum Product of Three Numbers
Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
Input: [1,2,3]
Output: 6

Example 2:
Input: [1,2,3,4]
Output: 24
 
Note:
The length of the given array will be in range [3,10^4] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.

Algo1: naive O(N*logN) + O(logN) (sort can take logN)
- sort
- nn - first 2 numbers
- sn = n[ms-1] * n[ms-2]
- return n[ms] * max(nn, sn);

Algo2: nth_element O(N) + O(1)
- find min num 
    - if if min < 0:
        - find next min and calc prod
    - find max
    - find next
    - find nextnext
    - prod max(sn, nn) * max
        
Algo3: priority_queue O(N + logN)
- make pq - O(N)
- take 3 elements O(logN)
- make min pq O(N)
- take 2 elements O(logN)

Algo4: find 2 mins and 3 max by hand

Algo5: partial sort

*/

// sort
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ms = (int)nums.size() - 1;
        int sn = nums[ms-2] * nums[ms-1];
        int nn = nums[0] * nums[1];
        return nums[ms] * max(sn, nn);
    }
};


// nth_element
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int ms = (int)nums.size() - 1;
        nth_element(nums.begin(), nums.begin() + ms-2, nums.end());
        int mm1 = nums[ms];
        int mm2 = nums[ms-1];
        int mm3 = nums[ms-2];
        if (mm1 < mm2) {
            swap(mm1, mm2);
        }
        nth_element(nums.begin(), nums.begin() + 1, nums.end());
        int mm4 = nums[0];
        int mm5 = nums[1];
        return mm1 * max(mm2* mm3, mm4 * mm5);
    }
};

// priority_queue
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int> pq1(less<int>(), nums);
        auto m = pq1.top();
        auto res1 = m;
        for (int i = 0; i < 2; ++i) {
            res1 *= pq1.top();
            pq1.pop();
        }
        
        priority_queue<int, vector<int>, greater<int>> pq2(greater<int>(), nums);
        auto res2 = m;
        for (int i = 0; i < 2; ++i) {
            res2 *= pq2.top();
            pq2.pop();
        }
        
        return max(res1, res2);
    }
};

class Solution {
public:
    int maximumProduct(const vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minpq;
        priority_queue<int> maxpq;
        for (int n : nums) {
            if (minpq.size() < 3 || minpq.top() < n) {
                minpq.push(n);
                if (minpq.size() > 3) minpq.pop();
            }
            if (maxpq.size() < 2 || maxpq.top() > n) {
                maxpq.push(n);
                if (maxpq.size() > 2) maxpq.pop();
            }
        }
        int a1 = maxpq.top(); maxpq.pop();
        int a0 = maxpq.top();
        int am3 = minpq.top(); minpq.pop();
        int am2 = minpq.top(); minpq.pop();
        int am1 = minpq.top();
        return am1 * max(a0*a1, am2*am3);       
    }
};


// hand-made
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        auto [m, m1, m2] = find3max(nums);
        auto [m3, m4] = find2min(nums);
        return m * max(m1*m2, m3*m4);
    }
private:
    tuple<int, int, int> find3max(const vector<int>& nums) {
        assert(nums.size() >= 3);
        int m = nums[0];
        int m1 = nums[1];
        int m2 = nums[2];
        if (m1 > m) {swap(m, m1);}
        if (m2 > m) {swap(m, m2);}
        if (m2 > m1) {swap(m1, m2);}
        for (size_t i = 3; i < nums.size(); ++i) {
            int n = nums[i];
            if (n > m) {m2 = m1; m1 = m; m = n;}
            else if (n > m1) {m2 = m1; m1 = n;}
            else if (n > m2) {m2 = n;}
        }
        return make_tuple(m, m1, m2);
    }
    
    tuple<int, int> find2min(const vector<int>& nums) {
        int m = nums[0];
        int m1 = nums[1];
        if (m1 < m) {swap(m, m1);}
        for (size_t i = 2; i < nums.size(); ++i) {
            int n = nums[i];
            if (n < m) {m1 = m; m = n;}
            else if (n < m1) {m1 = n;}
        }
        return make_tuple(m, m1);
    }    
};

class Solution {
public:
    int maximumProduct(const vector<int>& nums) {
        int m = nums[0];
        int m1 = nums[1];
        int m2 = nums[2];
        int m3 = nums[0];
        int m4 = nums[1];
        int tmp = nums[2];
        if (m1 > m) {swap(m, m1);}
        if (m2 > m) {swap(m, m2);}
        if (m2 > m1) {swap(m1, m2);}
        if (m4 < m3) {swap(m3, m4);}
        if (tmp < m3) {swap(m3,tmp);}
        if (tmp < m4) {swap(m4, tmp);}
        
        for (size_t i = 3; i < nums.size(); ++i) {
            int n = nums[i];
            if (n > m) {m2 = m1; m1 = m; m = n;}
            else if (n > m1) {m2 = m1; m1 = n;}
            else if (n > m2) {m2 = n;}
            
            if (n < m3) {m4 = m3; m3 = n;}
            else if (n < m4) {m4 = n;}
        }
        return m * max(m1*m2, m3*m4);
    }      
};


