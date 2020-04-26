/**
    244. Shortest Word Distance II
Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list. Your method will be called repeatedly many times with different parameters. 

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

Algo: make dict[word]->vector<pos>: O(N) for request
ctor:
- for every word:
    - dict[word].push_back(pos)
shortest:
- pos1 = dict[w1], pos2 = dict[w2]
- 2 iterators: move '<' iterator and calc dist
*/

class WordDistance {
public:
    WordDistance(const vector<string>& words) {
        for (size_t i = 0; i < words.size(); ++i) {
            dict[words[i]].push_back(i);
        }
    }
    
    int shortest(const string& w1, const string& w2) {
        const auto& pos1 = dict.at(w1);
        const auto& pos2 = dict.at(w2);
        int min_dist = INT_MAX;
        for (size_t i = 0, j = 0; i < pos1.size() && j < pos2.size(); ) {
            min_dist = min(min_dist, abs(pos1[i] - pos2[j]));
            if (pos1[i] < pos2[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return min_dist;
    }
private:
    unordered_map<string, vector<int>> dict;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
