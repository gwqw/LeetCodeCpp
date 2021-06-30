/**
    676. Implement Magic Dictionary
Design a data structure that is initialized with a list of different words. Provided a string, you should determine if you can change exactly one character in this string to match any word in the data structure.

Implement the MagicDictionary class:

MagicDictionary() Initializes the object.
void buildDict(String[] dictionary) Sets the data structure with an array of distinct strings dictionary.
bool search(String searchWord) Returns true if you can change exactly one character in searchWord to match any string in the data structure, otherwise returns false.

Example 1:
Input
["MagicDictionary", "buildDict", "search", "search", "search", "search"]
[[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
Output
[null, null, false, true, false, false]

Explanation
MagicDictionary magicDictionary = new MagicDictionary();
magicDictionary.buildDict(["hello", "leetcode"]);
magicDictionary.search("hello"); // return False
magicDictionary.search("hhllo"); // We can change the second 'h' to 'e' to match "hello" so we return True
magicDictionary.search("hell"); // return False
magicDictionary.search("leetcoded"); // return False

Constraints:
1 <= dictionary.length <= 100
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case English letters.
All the strings in dictionary are distinct.
1 <= searchWord.length <= 100
searchWord consists of only lower-case English letters.
buildDict will be called only once before search.
At most 100 calls will be made to search.

Algo1: naive: dict[length]->[words]: O(Q*N*W)
search(word): O(N*W)
    for w in dict[len(word)]: # if no such length return false
        diff = count_diff(word, w)
        if (diff == 1) return true
    return false

*/

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    void buildDict(const vector<string>& dictionary) {
        for (const auto& w : dictionary) {
            dict[w.size()].push_back(w);
        }
    }
    
    bool search(string_view word) {
        size_t n = word.size();
        if (!dict.count(n)) return false;
        for (const auto& w : dict[n]) {
            int diff = calcDiff(w, word);
            if (diff == 1) return true;
        }
        return false;
    }
    
private:
    int calcDiff(string_view w1, string_view w2) {
        int diff = 0;
        for (size_t i = 0; i < w1.size(); ++i) {
            if (w1[i] != w2[i]) ++diff;
            if (diff > 1) break;
        }
        return diff;
    }
    
private:
    unordered_map<size_t, vector<string>> dict;
};


class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    void buildDict(const vector<string>& dictionary) {
        for (const auto& w : dictionary) {
            auto& v = dict[w.size()];
            v.resize(w.size());
            for (size_t i = 0; i < v.size(); ++i) {
                v[i][w.substr(0,i) + w.substr(i+1, v.size() - i)].insert(w);
            }
        }
    }
    
    bool search(string_view word) {
        size_t n = word.size();
        if (!dict.count(n)) return false;
        for (const auto& w : dict[n]) {
            int diff = calcDiff(w, word);
            if (diff == 1) return true;
        }
        return false;
    }
    
private:
    int calcDiff(string_view w1, string_view w2) {
        int diff = 0;
        for (size_t i = 0; i < w1.size(); ++i) {
            if (w1[i] != w2[i]) ++diff;
            if (diff > 1) break;
        }
        return diff;
    }
    
private:
    unordered_map<size_t, 
        vector<unordered_map<string, unordered_set<string>>>> 
        dict;
};
dict[length]->[letter_num]->[word-letter]->{orig_words}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
