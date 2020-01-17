/**
    290. Word Pattern
Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, 
such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:
Input: pattern = "abba", str = "dog cat cat dog"
Output: true

Example 2:
Input:pattern = "abba", str = "dog cat cat fish"
Output: false

Example 3:
Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false

Example 4:
Input: pattern = "abba", str = "dog dog dog dog"
Output: false

Notes:
You may assume pattern contains only lowercase letters, 
and str contains lowercase letters that may be separated by a single space.

Algo: O(N+W) + O(N+W)
- string -> map: letter -> word and map word -> letter
- if no recs: add
- if exist and the same: continue
- else: ret false

*/

class Solution {
public:
    bool wordPattern(const string& pattern, const string& str) {
        map<char, string_view> c2s;
        map<string_view, char> s2c;
        size_t ci = 0;
        string_view sv(str);
        while (!sv.empty()) {
            auto pos = sv.find(' ');
            if (ci == pattern.size()) return false;
            string_view word = sv.substr(0, pos);
            if (!check_word(word, pattern[ci++], c2s, s2c)) return false;
            if (pos == string_view::npos) break;
            sv.remove_prefix(pos+1);
        }
        return ci == pattern.size();
        
    }
private:
    bool check_word(string_view word, char c, map<char, string_view>& c2s,
        map<string_view, char>& s2c) 
    {
        auto ci = c2s.find(c);
        auto si = s2c.find(word);
        if (ci != c2s.end() && ci->second == word && si != s2c.end() && si->second == c) {
            return true;
        }
        if (ci == c2s.end() && si == s2c.end()) {
            c2s[c] = word;
            s2c[word] = c;
            return true;
        }
        return false;
    }
};
