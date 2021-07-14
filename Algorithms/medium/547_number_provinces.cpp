/**
    547. Number of Provinces
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.

Example 1:
Input: isConnected = 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2

Example 2:
Input: isConnected = 
[[1,0,0],
 [0,1,0],
 [0,0,1]]
Output: 3

Constraints:
1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]

Algo: searching linked components, dfs in graph
1) using graph[node]->children
2) using matrix of connections
*/

class Solution {
	using Graph = vector<vector<int>>;
public:
    int findCircleNum(const vector<vector<int>>& isConnected) {
		size_t n = isConnected.size();
        auto graph = makeGraph(isConnected);
		vector<char> visited(n);
		int components = 0;
		for (size_t i = 0; i < n; ++i) {
			if (!visited[i]) {
				dfs(graph, i, visited);
				++components;
			}
		}
		return components;
    }
	
private:
	Graph makeGraph(const vector<vector<int>>& matrix) {
		size_t n = matrix.size();
		Graph graph(n);
		for (size_t i = 0; i < n; ++i) {
			for (size_t j = 0; j < n; ++j) {
				if (matrix[i][j] == 1) {
					graph[i].push_back(j);
				}
			}
		}
		return graph;
	}
	
	void dfs(const Graph& graph, int node, vector<char>& visited) {
		if (visited[node]) return;
		visited[node] = 1;
		for (auto n : graph[node]) {
			dfs(graph, n, visited);
		}
	}
};

class Solution {
	using Graph = vector<vector<int>>;
public:
    int findCircleNum(const vector<vector<int>>& isConnected) {
		size_t n = isConnected.size();
        const auto& graph = isConnected;
		vector<char> visited(n);
		int components = 0;
		for (size_t i = 0; i < n; ++i) {
			if (!visited[i]) {
				dfs(graph, i, visited);
				++components;
			}
		}
		return components;
    }
	
private:
	void dfs(const Graph& graph, int node, vector<char>& visited) {
		if (visited[node]) return;
		visited[node] = 1;
		for (size_t n = 0; n < graph.size(); ++n) {
			if (n == node) continue;
			if (graph[node][n]) {
				dfs(graph, n, visited);
			}
		}
	}
};

