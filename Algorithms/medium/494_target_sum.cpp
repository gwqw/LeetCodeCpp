/**
	494. Target Sum
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. 
Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 
-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
There are 5 ways to assign symbols to make the sum of nums be target 3.

Constraints:
    The length of the given array is positive and will not exceed 20.
    The sum of elements in the given array will not exceed 1000.
    Your output answer is guaranteed to be fitted in a 32-bit integer.
    
Algo: recursion: O(2^n) (2^20 ~10^6), O(n) mem
    sums, nums, target
    if nums.size() == 1:
        cnt = 0
        n = nums[0]
        for s in sums:
            if s+n == target: ++cnt
        return cnt
    n = nums[0]
    new_sums
    for s in sum:
        new_sums += s+n
        new_sums ++ s-n
    nums = nums[1:]
    return calcSums(new_sums, nums, target)
    
Algo2: caught in the middle: O(2^(n/2)), O(n) mem
- for 1-st half of array: calc availiable sums: dict[sum]->cnt
- for second: calc cums and check with 1-st dict

Algo3: dp
count[prefix_size][sum] = count[prefix_size-1][sum-n] + count[prefix_size-1][sum+n]
count[0][0] = 1,  count[0][sum != 0] = 0
i: 0 .. nums.size()-1    (max 20)
j: -sum(nums)..sum(nums) (max 2001)
Итого nums.size() шагов, в каждом заполняем 2*sum(nums)+1 вариантов: 4e4
*/

class Solution {
public:
    int findTargetSumWays(const vector<int>& nums, int S) {
        if (nums.empty()) return 0;
        int n = nums[0];
        int sums_cnt = pow(2, nums.size());
        vector<int> sums;
        sums.reserve(sums_cnt);
        if (nums.size() == 1) {
            int cnt = 0;
            if (n == S) ++cnt;
            if (-n == S) ++cnt;
            return cnt;
        }
        sums.push_back(n);
        sums.push_back(-n);
        return calcSums(nums, 1, sums, S);
    }
private:
    int calcSums(const vector<int>& nums, size_t from, vector<int>& sums, int target) {
        int n = nums[from];
        if (from+1 == nums.size()) {
            int cnt = 0;
            for (auto s : sums) {
                if (s + n == target) ++cnt;
                if (s - n == target) ++cnt;
            }
            return cnt;
        }
        size_t ssize = sums.size();
        for (size_t i = 0; i < ssize; ++i) {
            sums.push_back(sums[i]-n);
            sums[i] += n;
        }
        return calcSums(nums, from+1, sums, target);
    }
};

class Solution {
public:
    int findTargetSumWays(const vector<int>& nums, int S) {
        // edge cases
        if (nums.empty()) return 0;
        int n = nums[0];
        if (nums.size() == 1) {
            int cnt = 0;
            if (n == S) ++cnt;
            if (-n == S) ++cnt;
            return cnt;
        }
        
        // first sums
        int sums_cnt = pow(2, nums.size()/2);
        vector<int> sums;
        sums.reserve(sums_cnt);
        unordered_map<int, int> sum_dict;
        calcSums(nums, 0, nums.size()/2, sums, S, sum_dict);
        // second sums
        vector<int> sums2;
        sums_cnt = pow(2, nums.size() - nums.size()/2);
        sums2.reserve(sums_cnt);
        findSums(nums, nums.size()/2, nums.size(), sums2, S);
        // print dict
        for (auto [k,v] : sum_dict) {
            cerr << k << " : " << v << '\n';
        }
        for (auto s : sums2) {
            cout << s << ", ";
        }
        cout << '\n';
        // compare (count)
        int cnt = 0;
        for (auto s : sums2) {
            int64_t t = int64_t(S) - s;
            if (INT_MIN <= t && t <= INT_MAX && sum_dict.count(t)) {
                cnt += sum_dict[t];
            }
        }
        return cnt;
    }
private:
    void calcSums(const vector<int>& nums, size_t from, size_t to, vector<int>& sums, int target, unordered_map<int, int>& res) {
        int n = nums[from];
        if (from+1 == to) {
            if (!sums.empty()) {
                for (auto s : sums) {
                    ++res[s+n];
                    ++res[s-n];
                }
            } else {
                ++res[n];
                ++res[-n];
            }
            return;
        }
        size_t ssize = sums.size();
        if (ssize != 0) {
            for (size_t i = 0; i < ssize; ++i) {
                sums.push_back(sums[i]-n);
                sums[i] += n;
            }
        } else {
            sums.push_back(n);
            sums.push_back(-n);
        }
        calcSums(nums, from+1, to, sums, target, res);
    }
    void findSums(const vector<int>& nums, size_t from, size_t to, vector<int>& sums, int target) {
        int n = nums[from];
        size_t ssize = sums.size();
        if (ssize != 0) {
            for (size_t i = 0; i < ssize; ++i) {
                sums.push_back(sums[i]-n);
                sums[i] += n;
            }
        } else {
            sums.push_back(n);
            sums.push_back(-n);
        }
        if (from+1 != to) {
            findSums(nums, from+1, to, sums, target);
        }
    }
};

/*
Algo3: dp
count[prefix_size][sum] = count[prefix_size-1][sum-n] + count[prefix_size-1][sum+n]
count[0][0] = 1,  count[0][sum != 0] = 0
i: 0 .. nums.size()-1    (max 20)
j: -sum(nums)..sum(nums) (max 2001)
Итого nums.size() шагов, в каждом заполняем 2*sum(nums)+1 вариантов: 4e4
*/

class Solution {
public:
    int findTargetSumWays(const vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        const auto ssize = calcSum(nums);
        const auto max_ssize = 2*ssize+1;
        if (target < -ssize || ssize < target) return 0;
        vector<vector<int>> dp(nums.size()+1, vector<int>(max_ssize, 0));
        dp[0][ssize] = 1;
        for (int i = 1; i <= nums.size(); ++i) {
            for (int sum = 0; sum < max_ssize; ++sum) {
                int n = nums[i-1];
                dp[i][sum] = (sum-n >=0 ? dp[i-1][sum-n] : 0) + 
                             (sum+n < max_ssize ? dp[i-1][sum+n] : 0);
            }
        }
        return dp[nums.size()][target+ssize];
    }
private:
    int calcSum(const vector<int>& nums) {
        int sum = 0;
        for (auto n : nums) {
            sum += n;
        }
        return sum;
    }
};

/*
1 1
sum = 2
maxs = 5
  -2 -1  0  1  2
   0  1  2  3  4
0: 0  0  1  0  0
1: 0  1  0  1  0 n=1 
2: 1  0  2  0  1 n=1





*/

