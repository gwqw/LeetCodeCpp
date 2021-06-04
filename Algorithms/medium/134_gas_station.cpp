/**
    134. Gas Station
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.
Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique

Example 1:
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.

Example 2:
Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.

Constraints:
gas.length == n
cost.length == n
1 <= n <= 10^4
0 <= gas[i], cost[i] <= 10^4

Algo1: bf O(N^2)
g: 1, 2, 3, 4, 5
c: 3, 4, 5, 1, 2
d: -2,-2,-2,3, 3

Algo2:
search d > 0:
go clockwise and calc sum
if sum < 0:
    search new d from this position
    
Algo3: 1pass
calc total sum
calc sum from d
    if sum_from_d < 0:
        from  = i+1
        sum_from_d = 0
if total < 0: return -1
return from

*/

class Solution {
public:
    int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
        vector<int> diff(gas.size());
        for (size_t i = 0; i < gas.size(); ++i) {
            diff[i] = gas[i] - cost[i];
        }
        
        for (int start_d = searchNextStart(diff, -1);
            start_d != -1;
            start_d = searchNextStart(diff, start_d))
        {
            int sum = 0;
            for (int i = start_d; i < (int)diff.size(); ++i) {
                sum += diff[i];
                if (sum < 0) break;
            }
            if (sum < 0) continue;
            for (int i = 0 ; i < start_d; ++i) {
                sum += diff[i];
                if (sum < 0) break;
            }
            if (sum < 0) continue;
            return start_d;
        }
        return -1;
    }
    
private:
    int searchNextStart(const vector<int> diff, int cur_start) {
        for (int i = cur_start+1; i < (int)diff.size(); ++i) {
            if (diff[i] >= 0) return i;
        }
        return -1;
    }
};

class Solution {
public:
    int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
        vector<int> diff(gas.size());
        int total = 0;
        for (size_t i = 0; i < gas.size(); ++i) {
            diff[i] = gas[i] - cost[i];
            total += diff[i];
        }
        if (total < 0) return -1;
        size_t from = 0;
        int from_sum = 0;
        for (size_t i = 0; i < diff.size(); ++i) {
            from_sum += diff[i];
            if (from_sum < 0) {
                from = i+1;
                from_sum = 0;
            }
        }
        return from;
    }
};

class Solution {
public:
    int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
        int total = 0;
        int from = 0;
        int from_sum = 0;
        for (int i = 0; i < (int)gas.size(); ++i) {
            from_sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (from_sum < 0) {
                from = i+1;
                from_sum = 0;
            }
        }
        return total >= 0 ? from : -1;
    }
};


