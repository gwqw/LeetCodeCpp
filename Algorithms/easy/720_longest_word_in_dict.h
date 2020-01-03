/**
    720. Longest Word in Dictionary
Given a list of strings words representing an English Dictionary, 
find the longest word in words that can be built one character at a time by other words in words. 
If there is more than one possible answer, return the longest word with the smallest lexicographical order.
If there is no answer, return the empty string.

Example 1:
Input: 
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation: 
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".

Example 2:
Input: 
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation: 
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".

Note:
All the strings in the input will only contain lowercase letters.
The length of words will be in the range [1, 1000].
The length of words[i] will be in the range [1, 30].

Algo1: n = sum()
- sort lexigraphically
- go and calc length
- if failed: updated max_length

Algo2: 
- make dict: word -> has substr in map
- go through dict and find if this word has substr 
- if true: update max

*/

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](const auto& lhs, const auto& rhs){
            return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
        });
        
        string res = "";
        string cur = "";
        for (const auto& w : words) {
            if (w.size() == cur.size() + 1 && startswith(w, cur)) {
                cur += w.back();
            } else {
                if (res.size() < cur.size()) res = cur;
                if (w.size() == 1 || startswith(cur, w.substr(0, w.size()-1)) ) {
                    cur = w;
                }
            }
        }
        if (res.size() < cur.size()) res = cur;
        return res;
    }
    
private:

    bool startswith(const string& str, const string& pref) {
        if (pref.size() > str.size()) return false;
        for (size_t i = 0; i < pref.size(); ++i) {
            if (pref[i] != str[i]) return false;
        }
        return true;
    }
    
};

class Solution {
    enum class State {UNDEF, TRUE, FALSE};
    using Dict = unordered_map<string, State>;
public:
    string longestWord(const vector<string>& words) {
        string res;
        Dict dict;
        for (const auto& w : words) {
            State s = w.size() == 1 ? State::TRUE : State::UNDEF;
            dict[w] = s;
        }
        
        for (const auto& [w, has] : dict) {
            if (w.size() < res.size() || (w.size() == res.size() && w > res)) continue;
            
            if (getStrState(w, dict) == State::TRUE) {
                res = w;
            }
        }
        
        return res;
    }
    
private:

    State getStrState(const string& w, Dict& dict) {
        if (!dict.count(w)) return State::FALSE;
        if (dict[w] == State::TRUE) return State::TRUE;
        return dict[w] = getStrState(w.substr(0, w.size()-1), dict);
    }
    
};

/*
["w","wo","wor","worl","world"]
["a", "banana", "app", "appl", "ap", "apply", "apple"]
["a", "banana", "app", "appl", "ap", "apps", "appsa"]
["yo","ew","fc","zrc","yodn","fcm","qm","qmo","fcmz","z","ewq","yod","ewqz","y"]
["rac","rs","ra","on","r","otif","o","onpdu","rsf","rs","ot","oti","racy","onpd"]
*/
