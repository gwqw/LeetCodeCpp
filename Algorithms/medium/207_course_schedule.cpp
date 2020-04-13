/**
    207. Course Schedule
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.

Constraints:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. 
Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5

Algo: dfs (search cycle)
has_cycle(v): // has_cycle
    mark[v] = 1
    for u in edges[v]:
        if mark[u] == 0:
            res = has_cycle(u)
            if res: return true
        if mark[u] == 1:
            return false
    mark[v] = 2
    return false

*/

class Solution {
    using Graph = vector<vector<int>>;
public:
    bool canFinish(int numCourses, const vector<vector<int>>& edges) {
        vector<int> marks(numCourses, 0);
        auto graph = createGraph(numCourses, edges); // O(m)
        for (int vertex = nextToVisit(marks); vertex != -1; vertex = nextToVisit(marks)) { // O(n)
            if (has_cycle(vertex, graph, marks)) return false;
        }
        return true;
    }
    
private:
    Graph createGraph(int n, const vector<vector<int>>& edges) {
        Graph g(n);
        for (const auto& edge : edges) {
            g[edge[1]].push_back(edge[0]);
        }
        return g;
    }
    
    int nextToVisit(const vector<int>& marks) {
        for (size_t i = 0; i < marks.size(); ++i) {
            if (marks[i] == 0) {
                return i;
            }
        }
        return -1;
    }
    
    bool has_cycle(int vertex, const Graph& graph, vector<int>& marks) {
        marks[vertex] = 1;
        for (auto u : graph[vertex]) {
            if (marks[u] == 0) {
                bool res = has_cycle(u, graph, marks);
                if (res) return true;
            }
            if (marks[u] == 1) {
                return true;
            }
        }
        marks[vertex] = 2;
        return false;
    }
};

