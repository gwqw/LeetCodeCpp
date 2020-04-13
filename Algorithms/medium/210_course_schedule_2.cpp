/**
    210. Course Schedule II
There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:
Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .

Example 2:
Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.

Algo: use topological sort
top_sort(v):
    mark(v) = 1
    for u in edges[v]:
        if mark[u] == 0:
            res = top_sort(u)
            if not res: return false
        if mark[u] == 1:
            return false
    mark[v] = 2
    ans.push_back(v)
    return true

*/

class Solution {
    using Graph = vector<vector<int>>;
public:
    vector<int> findOrder(int numCourses, const vector<vector<int>>& edges) {
        vector<int> marks(numCourses, 0);
        auto graph = createGraph(numCourses, edges); // O(m)
        vector<int> ans;
        ans.reserve(numCourses);
        for (int vertex = nextToVisit(marks); vertex != -1; vertex = nextToVisit(marks)) { // O(n)
            if (top_sort(vertex, graph, marks, ans)) return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
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
    
    bool top_sort(int vertex, const Graph& graph, vector<int>& marks, vector<int>& ans) {
        marks[vertex] = 1;
        for (auto u : graph[vertex]) {
            if (marks[u] == 0) {
                bool res = top_sort(u, graph, marks, ans);
                if (res) return true;
            }
            if (marks[u] == 1) {
                return true;
            }
        }
        marks[vertex] = 2;
        ans.push_back(vertex);
        return false;
    }
};

