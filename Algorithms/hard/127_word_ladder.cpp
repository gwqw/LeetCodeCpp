/**
    127. Word Ladder
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

Constraints:
1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.

Algo1: graph+bfs O(N^2*w), O(N*w) mem
make graph
use bfs for searching endword
return path_length

Algo2: bfs in-place wo graph (generate all availiable words) O(N*w^2*alphabet)

*/

// 1236 ms
class Solution {
    using Graph = unordered_map<int, vector<int>>;
    using Dict = unordered_map<string, int>;
public:
    int ladderLength(const string& beginWord, const string& endWord, vector<string>& wordList) {
        pushIfNotExist(wordList, beginWord);
        auto [graph, dict] = makeGraph(wordList);
        if (dict.count(beginWord) == 0 || dict.count(endWord) == 0) return 0;
        int beg_idx = dict[beginWord];
        int end_idx = dict[endWord];

        // bfs
        queue<pair<int, int>> q;
        unordered_set<int> visited;
        q.push({beg_idx, 0});
        bool is_found = false;
        int found_level = 0;
        while (!q.empty()) {
            auto [node, lvl] = q.front();
            q.pop();
            if (visited.count(node)) continue;
            if (node == end_idx) {
                is_found = true;
                found_level = lvl;
                break;
            }
            visited.insert(node);
            for (const auto& n : graph[node]) {
                if (!visited.count(n)) {
                    q.push({n, lvl+1});
                }
            }
        }
        return is_found ? found_level+1 : 0;
    }
    
private:
     pair<Graph, Dict> makeGraph(const vector<string>& wordList) {
        Dict dict;
        for (size_t i = 0; i < wordList.size(); ++i) {
            dict[wordList[i]] = i;
        }
        Graph graph;
        for (size_t i = 0; i < wordList.size(); ++i) {
            const auto word = wordList[i];            
            vector<int> close_words;
            for (size_t j = 0; j < wordList.size(); ++j) {
                if (i == j) continue;
                if (calcDiff(word, wordList[j]) == 1) {
                    close_words.push_back(j);
                }
            }
            graph[i] = move(close_words);
        }
        return {graph, dict};
     }
     
     size_t calcDiff(string_view w1, string_view w2) {
        size_t res = 0;
        assert(w1.size() == w2.size());
        for (size_t i = 0; i < w1.size(); ++i) {
            if (w1[i] != w2[i]) ++res;
            if (res > 1) break;
        }
        return res;
     }
     
     void pushIfNotExist(vector<string>& wordList, const string& beginWord) {
        if (auto it = find(wordList.begin(), wordList.end(), beginWord); it == wordList.end()) {
            wordList.push_back(beginWord);
        }
     }
};

// 180ms
class Solution {
public:
    int ladderLength(const string& beginWord, const string& endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) return 0;
        words.insert(beginWord);
        constexpr int ALPHABET_SIZE = 26;
        
        // bfs
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({beginWord, 0});
        int found_level = 0;
        while (!q.empty()) {
            auto [node, lvl] = move(q.front());
            q.pop();
            if (visited.count(node)) continue;
            if (node == endWord) {
                found_level = lvl+1;
                break;
            }
            visited.insert(node);
            for (size_t i = 0; i < node.size(); ++i) {
                for (size_t j = 0; j < ALPHABET_SIZE; ++j) {
                    string new_node = node;
                    new_node[i] = char('a' + j);
                    if (words.count(new_node) && !visited.count(new_node)) {
                        q.push({move(new_node), lvl+1});
                    }
                }
            }            
        }
        return found_level;
    }
};

