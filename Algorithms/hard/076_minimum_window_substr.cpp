/**
    76. Minimum Window Substring
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.
A substring is a contiguous sequence of characters within the string.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

Constraints:
m == s.length
n == t.length
1 <= m, n <= 10^5
s and t consist of uppercase and lowercase English letters.

Follow up: Could you find an algorithm that runs in O(m + n) time?

Algo: sliding window
s=0, e=0
# find first window
while e != size():
    d += s[e]
    if (d contains dt) break;
if e == size(): return ""
# shrink window
while d contains dt:
    ++i
ws = e-s+1

# move window
while e != size:
    d+c
    d-c
    if contains:
        shrink left
        update ws
*/

class Solution {
    using Dict = unordered_map<char, int>;
public:
    string minWindow(const string& s, const string& t) {
        if (s.size() < t.size() || t.empty()) return "";
        size_t f = 0, e = 0, min_f = 0, min_e = 0;
        int window_size = (int)s.size() + 1;
        int min_window_size = window_size;
        auto td = makeDict(t);
        Dict d;
        
        // move e
        while (e < s.size()) {
            while (e < s.size()) {
                if (td.count(s[e])) ++d[s[e]];
                ++e;
                if (contains(d, td)) break;
            }
            if (e == s.size() && !contains(d, td)) break;
            
            // move f
            while (f < e) {
                char c = s[f];
                if (d.count(s[f])) --d[s[f]];
                ++f;
                if (!contains(d, td)) break;
            }
            if (f == e) return string{s[f-1]};
            
            // update min
            window_size = e - f + 1;
            if (window_size < min_window_size) {
                min_window_size = window_size;
                min_f = f-1;
                min_e = e;
            }
        }
       
        return window_size <= s.size() ? s.substr(min_f, min_window_size) : "";
    }
    
private:
    Dict makeDict(const string& s) {
        Dict dict;
        for (char c : s) {
            ++dict[c];
        }
        return dict;
    }
    
    bool contains(const Dict& d, const Dict& dt) {
        for (const auto& [k,v] : dt) {
            if (!d.count(k) || d.at(k) < v) return false;
        }
        return true;
    }
};