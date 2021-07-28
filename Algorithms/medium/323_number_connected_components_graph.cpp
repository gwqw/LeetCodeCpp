/**
    323. Number of Connected Components in an Undirected Graph
You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.
Return the number of connected components in the graph.

Example 1:
Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2

Example 2:
Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1

Constraints:
1 <= n <= 2000
1 <= edges.length <= 5000
edges[i].length == 2
0 <= ai <= bi < n
ai != bi
There are no repeated edges.

Algo1: dfs and count components

Algo2: disjoint sets
*/

class Solution {
	using Graph = vector<vector<int>>;
public:
    int countComponents(int n, const vector<vector<int>>& edges) {
        auto graph = makeGraph(edges, n);
		vector<char> visited(n);
		int cnt = 0;
		for (int i = 0; i < n; ++n) {
			if (!visited[i]) {
				dfs(graph, i, visited);
				++cnt;
			}
		}
		return cnt;
    }
	
private:
	Graph makeGraph(const vector<vector<int>>& edges, int n) {
		Graph graph(n);
		for (const auto& e : edges) {
			graph[e[0]].push_back(e[1]);
			graph[e[1]].push_back(e[0]);
		}
		return graph;
	}
	
	void dfs(const Graph& graph, int node, vector<char>& visited) {
		if (visited[node]) return;
		visited[node] = true;
		for (auto n : graph[node]) {
			dfs(graph, n, visited);
		}
	}
};


class DisjSet {
public:
	DisjSet(int n) 
		: parent(n), rank(n), cnt(n)
	{
		iota(parent.begin(), parent.end(), 0);
	}
	
	int find(int i) {
		if (parent[i] != i) {
			parent[i] = find(parent[i]);
		}
		return parent[i];
	}
	
	void unionSet(int i, int j) {
		int i_id = find(i);
		int j_id = find(j);
		if (i_id == j_id) return;
		if (rank[i_id] >= rank[j_id]) {
			parent[j_id] = i_id;
			if (rank[i_id] == rank[j_id]) {
				++rank[i_id];
			}
		} else {
			parent[i_id] = j_id;
		}
		--cnt;
	}
	
	int getCnt() const {
		return cnt;
	}
	
private:
	vector<int> parent;
	vector<int> rank;
	int cnt = 0;
};

class Solution {
public:
    int countComponents(int n, const vector<vector<int>>& edges) {
        DisjSet ds(n);
		for (const auto& edge : edges) {
			ds.unionSet(edge[0], edge[1]);
		}
		return ds.getCnt();
    }
};

