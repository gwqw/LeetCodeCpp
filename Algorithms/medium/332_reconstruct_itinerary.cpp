/**
    332. Reconstruct Itinerary
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. 
All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.
For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.

Example 1:
Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]

Example 2:
Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.

Algo: use dfs for path search
- create graph

*/

class Solution {
    using Graph = unordered_map<int, vector<int>>;
    using Edge = pair<int, int>;
    using UnusedTickets = map<Edge, int>;
    using IndexDict = vector<string>;
    using StringDict = unordered_map<string, int>;
public:
    vector<string> findItinerary(const vector<vector<string>>& tickets) {
        auto [i2str, str2int] = makeDicts(tickets);        
        auto [graph, unused] = createGraph(tickets, i2str, str2int);
        vector<string> path;
        dfs(str2int["JFK"], graph, unused, path, i2str);
        reverse(path.begin(), path.end());
        return path;        
    }

private:
    pair<IndexDict, StringDict>
        makeDicts(const vector<vector<string>>& tickets) 
        {
            IndexDict i2str;
            StringDict str2int;
            for (const auto& t : tickets) {
                if (!str2int.count(t[0])) {
                    i2str.push_back(t[0]);
                    str2int[i2str.back()] = (int)i2str.size()-1;
                }
                if (!str2int.count(t[1])) {
                    i2str.push_back(t[1]);
                    str2int[i2str.back()] = (int)i2str.size()-1;
                }                
            }
            sort(i2str.begin(), i2str.end());
            for (int i = 0; i < (int)i2str.size(); ++i) {
                str2int[i2str[i]] = i;
            }
            return {i2str, str2int};
        }

    pair<Graph, UnusedTickets>
        createGraph(const vector<vector<string>>& tickets, const IndexDict& i2str, const StringDict& str2int) 
    {
        Graph graph;
        UnusedTickets unused;
        for (const auto& t : tickets) {
            int from = str2int.at(t[0]);
            int to = str2int.at(t[1]);
            graph[from].push_back(to);
            ++unused[{from, to}];
        }
        for (auto& [_,v] : graph) {
            sort(v.begin(), v.end());
        }
        return {graph, unused};
    }
    
    void dfs(int cur, const Graph& graph, UnusedTickets& unused, vector<string>& path, const IndexDict& i2str) {
        if (graph.count(cur)) {
            const auto& children = graph.at(cur);
            for (const auto& child : children) {
                if (unused[{cur, child}] > 0) {
                    --unused[{cur, child}];
                    dfs(child, graph, unused, path, i2str);
                }
            }
        }
        path.push_back(i2str.at(cur));
    }
    
    static bool is_last(int vertex, const Graph& graph, UnusedTickets& unused) {
        bool is_last = !graph.count(vertex);
        if (is_last) return true;
        for (auto child : graph.at(vertex)) {
            if (unused[{vertex, child}] > 0) return false;
        }
        return true;
    }
};