/**
    746. Min Cost Climbing Stairs

On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
Once you pay the cost, you can either climb one or two steps. 
You need to find minimum cost to reach the top of the floor, 
and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.

Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].

Note:
cost will have a length in the range [2, 1000].
Every cost[i] will be an integer in the range [0, 999].

Algo: dynamic programming O(N) + O(N or 1)
- min(prev, prevprev) + value

*/

class Solution {
public:
    int minCostClimbingStairs(const vector<int>& cost) {
        int p = 0, pp = 0;
        for (auto c : cost) {
            int n = min(p, pp) + c;
            pp = p;
            p = n;
        }
        return min(p, pp);
    }
};

class Solution {
public:
    int minCostClimbingStairs(const vector<int>& cost) {
        assert(cost.size() > 1);
        vector<int> weights(cost.size());
        weights[0] = cost[0];
        weights[1] = cost[1];
        for (size_t i = 2; i < cost.size(); ++i) {
            weights[i] = min(weights[i-1], weights[i-2]) + cost[i];
        }
        return min(weights[weights.size()-2], weights.back());
    }
};

class Solution {
public:
    vector<int> minCostClimbingStairs(const vector<int>& cost) {
        assert(cost.size() > 1);
        vector<int> weights(cost.size());
        weights[0] = cost[0];
        weights[1] = cost[1];
        for (size_t i = 2; i < cost.size(); ++i) {
            weights[i] = min(weights[i-1], weights[i-2]) + cost[i];
        }
        
        size_t n = weights.size();
        vector<int> res;
        int i = weights.back() <= weights[n-2] ? n-1 : n-2;
        while (i > 0) {
            res.push_back(i);
            int nv = weights[i] - cost[i];
            i = weights[i-1] == nv ? i-1 : i-2;
        }
        if (i == 0) res.push_back(0);
        reverse(res.begin(), res.end());
        return res;
    }
};

