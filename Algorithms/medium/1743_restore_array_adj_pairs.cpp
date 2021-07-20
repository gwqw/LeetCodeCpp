/**
    1743. Restore the Array From Adjacent Pairs
There is an integer array nums that consists of n unique elements, but you have forgotten it. However, you do remember every pair of adjacent elements in nums.

You are given a 2D integer array adjacentPairs of size n - 1 where each adjacentPairs[i] = [ui, vi] indicates that the elements ui and vi are adjacent in nums.

It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in adjacentPairs, either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order.

Return the original array nums. If there are multiple solutions, return any of them.

Example 1:
Input: adjacentPairs = [[2,1],[3,4],[3,2]]
Output: [1,2,3,4]
Explanation: This array has all its adjacent pairs in adjacentPairs.
Notice that adjacentPairs[i] may not be in left-to-right order.

Example 2:
Input: adjacentPairs = [[4,-2],[1,4],[-3,1]]
Output: [-2,4,1,-3]
Explanation: There can be negative numbers.
Another solution is [-3,1,4,-2], which would also be accepted.

Example 3:
Input: adjacentPairs = [[100000,-100000]]
Output: [100000,-100000]

Constraints:
nums.length == n
adjacentPairs.length == n - 1
adjacentPairs[i].length == 2
2 <= n <= 105
-10^5 <= nums[i], ui, vi <= 10^5
There exists some nums that has adjacentPairs as its pairs.

Algo: like graph
make graph and start nums
dfs through graph
return ar
*/

class Solution {
    using Graph = unordered_map<int, vector<int>>;
public:
    vector<int> restoreArray(const vector<vector<int>>& adjacentPairs) {
        auto graph = makeGraph(adjacentPairs);
        int start = findStart(graph);
        unordered_set<int> visited;
        vector<int> res;
        res.reserve(graph.size());
        dfs(graph, start, visited, res);
        return res;
    }
    
private:
    Graph makeGraph(const vector<vector<int>>& a) {
        Graph graph;
        bool is_found = false;
        int start_num = 0;
        for (const auto& nums : a) {
            graph[nums[0]].push_back(nums[1]);
            graph[nums[1]].push_back(nums[0]);
        }
        return graph;
    }
    
    int findStart(const Graph& graph) {
        for (const auto& [n, children] : graph) {
            if (children.size() == 1) return n;
        }
        return 0;
    }
    
    void dfs(const Graph& graph, int num, unordered_set<int>& visited, vector<int>& res) {
        res.push_back(num);
        visited.insert(num);
        for (auto n : graph.at(num)) {
            if (!visited.count(n)) {
                dfs(graph, n, visited, res);
            }
        }
    }
};