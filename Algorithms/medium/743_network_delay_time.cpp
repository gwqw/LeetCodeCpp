/**
    743. Network Delay Time
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.
Now, we send a signal from a certain node K. 
How long will it take for all nodes to receive the signal? If it is impossible, return -1.

Example 1:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2

Algo: O(N*Height) + O(N)
- transmits <- input
- was_transmit = true
- a[N] = time (-1 default)
- a[K] = 0
- while was transmit
    - was_transmit = false
    - for every from, to, time in transmits:
        - cur_time = a[from]
        - if cur_time == -1: continue
        - it a[to] != -1: continue
        - a[to] = cur_time + time
        - was_transmit = true
- max_time, min_time <- a
- if min_time == -1: return -1
- else: return max_time

*/

class Solution {
public:
    int networkDelayTime(const vector<vector<int>>& transmits, int N, int K) {
        bool was_transmit = true;
        vector<int> a(N+1, -1);
        assert(K <= N);
        a[0] = 0;
        a[K] = 0;
        while (was_transmit) {
            was_transmit = false;
            for (const auto& ftt : transmits) {
                int from = ftt[0];
                int to = ftt[1];
                int time = ftt[2];
                int cur_time = a[from];
                if (cur_time == -1) continue;
                int new_time = cur_time + time;
                if (a[to] != -1 && a[to] <= new_time) continue;
                a[to] = new_time;
                was_transmit = true;
            }
        }
        int max_time = -1;
        for (auto time : a) {
            if (time == -1) return -1;
            max_time = max(max_time, time);
        }
        return max_time;
    }
};

