/**
    1152. Analyze User Website Visit Pattern
We are given some website visits: the user with name username[i] visited the website website[i] at time timestamp[i].
A 3-sequence is a list of websites of length 3 sorted in ascending order by the time of their visits. (The websites in a 3-sequence are not necessarily distinct.)
Find the 3-sequence visited by the largest number of users. If there is more than one solution, return the lexicographically smallest such 3-sequence.

Example 1:
Input: username = ["joe","joe","joe","james","james","james","james","mary","mary","mary"], timestamp = [1,2,3,4,5,6,7,8,9,10], website = ["home","about","career","home","cart","maps","home","home","about","career"]
Output: ["home","about","career"]
Explanation: 
The tuples in this example are:
["joe", 1, "home"]
["joe", 2, "about"]
["joe", 3, "career"]
["james", 4, "home"]
["james", 5, "cart"]
["james", 6, "maps"]
["james", 7, "home"]
["mary", 8, "home"]
["mary", 9, "about"]
["mary", 10, "career"]
The 3-sequence ("home", "about", "career") was visited at least once by 2 users.
The 3-sequence ("home", "cart", "maps") was visited at least once by 1 user.
The 3-sequence ("home", "cart", "home") was visited at least once by 1 user.
The 3-sequence ("home", "maps", "home") was visited at least once by 1 user.
The 3-sequence ("cart", "maps", "home") was visited at least once by 1 user.
 
Note:
3 <= N = username.length = timestamp.length = website.length <= 50
1 <= username[i].length <= 10
0 <= timestamp[i] <= 10^9
1 <= website[i].length <= 10
Both username[i] and website[i] contain only lowercase characters.
It is guaranteed that there is at least one user who visited at least 3 websites.
No user visits two websites at the same time.

Algo: naive: dict[3word_seq]->cnt
*/

class Solution {
    struct Node {
        int timestamp = 0;
        string_view web;
        friend bool operator<(const Node& lhs, const Node& rhs) {
            return lhs.timestamp < rhs.timestamp || 
            (lhs.timestamp == rhs.timestamp && lhs.web < rhs.web);
        }
    };
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        // make dict user -> nodes
        unordered_map<string_view, vector<Node>> user2web;
        for (size_t i = 0; i < username.size(); ++i) {
            user2web[username[i]].push_back(Node{timestamp[i], website[i]});
        }
        // main counter dict
        unordered_map<string_view, 
                unordered_map<string_view, 
                unordered_map<string_view, int>>> dict;
        for (auto& [_, www] : user2web) {
            if (www.size() < 3) continue;
            sort(www.begin(), www.end()); // sort if needed
            unordered_map<string_view, 
                unordered_map<string_view, 
                unordered_set<string_view>>> used;
            for (size_t i = 0; i+2 < www.size(); ++i) {
                for (size_t j = i+1; j+1 < www.size(); ++j) {
                    for (size_t k = j+1; k < www.size(); ++k) {
                        if (!used[www[i].web][www[j].web].count(www[k].web)) {
                            ++dict[www[i].web][www[j].web][www[k].web];
                            used[www[i].web][www[j].web].insert(www[k].web);
                        }
                    }
                }
            }
        }
        // find max pattern
        vector<string> res(3);
        int max_cnt = 0;
        for (const auto& [w1, d1] : dict) {
            for (const auto& [w2, d2] : d1) {
                for (const auto& [w3, cnt] : d2) {
                    vector<string> v{string(w1), string(w2), string(w3)};
                    if (cnt > max_cnt) {
                        max_cnt = cnt;
                        res = move(v);
                    } else if (max_cnt == cnt && res > v) {
                        res = move(v);
                    }
                }
            }
        }
        return res;
    }
};

["joe","joe","joe","james","james","james","james","mary","mary","mary"]
[1,2,3,4,5,6,7,8,9,10]
["home","about","career","home","cart","maps","home","home","about","career"]
["h","eiy","cq","h","cq","txldsscx","cq","txldsscx","h","cq","cq"]
[527896567,334462937,517687281,134127993,859112386,159548699,51100299,444082139,926837079,317455832,411747930]
["hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","yljmntrclw","hibympufi","yljmntrclw"]


