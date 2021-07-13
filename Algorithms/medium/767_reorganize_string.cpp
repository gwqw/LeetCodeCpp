/**
    767. Reorganize String
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
Return any possible rearrangement of s or return "" if not possible.

Example 1:
Input: s = "aab"
Output: "aba"

Example 2:
Input: s = "aaab"
Output: ""

Constraints:
1 <= s.length <= 500
s consists of lowercase English letters.

Algo: dict[char]->cnt, heap{cnt, char}
make dict[char]->cnt
make pq{cnt, char}
if pq.top().cnt > s.size(): return ""
while not pq.empty():
    s1 = pq.pop()
    s2 = pq.pop()
    if res[-1] == s1: return ""
    res += s1 + s2
*/

class Solution {
    using Node = pair<int, char>;
public:
    string reorganizeString(string_view s) {
        unordered_map<char, int> dict;
        for (char c : s) {
            ++dict[c];
        }
        priority_queue<Node> pq;
        for (auto [c, cnt] : dict) {
            pq.emplace(cnt, c);
        }
        //if (pq.top().first > s.size() / 2) return "";
        string res;
        res.reserve(s.size());
        while (!pq.empty()) {
            // take 1st
            auto [cnt1, c1] = pq.top();
            pq.pop();
            if (!res.empty() && res.back() == c1) return "";
            if (pq.empty()) {
                if (cnt1 > 1) return "";
                res += string(cnt1, c1);
                return res;
            }

            // take 2nd
            auto [cnt2, c2] = pq.top();
            pq.pop();
            res += c1;
            res += c2;

            // return to pq
            --cnt1;
            --cnt2;
            if (cnt1 != 0) {
                pq.emplace(cnt1, c1);
            }
            if (cnt2 != 0) {
                pq.emplace(cnt2, c2);
            }
        }
        return res;
    }
};