/**
    451. Sort Characters By Frequency
Given a string s, sort it in decreasing order based on the frequency of characters, and return the sorted string.

Example 1:
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:
Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:
Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

Constraints:
1 <= s.length <= 5 * 10^5
s consists of English letters and digits.

Algo1: use counter and sort: O(NlogN), O(alphabet)

Algo2: radix sort: O(N + AlogA), where A -- alphabet size
counter
freq->chars
create string

Algo3: same but with pq
*/

class Solution {
public:
    string frequencySort(string& s) {
        unordered_map<char, int> dict;
        for (char c : s) {
            ++dict[c];
        }
        sort(s.begin(), s.end(), [&dict](char l, char r){
            return dict[l] > dict[r] || dict[l] == dict[r] && l > r;
        });
        return move(s);
    }
};

class Solution {
public:
    string frequencySort(string& s) {
        unordered_map<char, int> dict;
        for (char c : s) {
            ++dict[c];
        }
        map<int, vector<char>> freq;
        for (auto [c, cnt] : dict) {
            freq[cnt].push_back(c);
        }
        size_t i = 0;
        for (auto it = freq.end(); it != freq.begin(); ) {
            --it;
            const auto& [cnt, fv] = *it;
            for (auto c : fv) {
                for (size_t j = i; j < i+cnt; ++j) {
                    s[j] = c;
                }
                i += cnt;
            }
        }
        return move(s);
    }
};

class Solution {
public:
    string frequencySort(string& s) {
        unordered_map<char, int> dict;
        for (char c : s) {
            ++dict[c];
        }
        priority_queue<pair<int, char>> pq;
        for (auto [c, cnt] : dict) {
            pq.emplace(cnt, c);
        }
        size_t i = 0;
        while (!pq.empty()) {
            auto [cnt, c] = pq.top(); pq.pop();
            for (size_t j = i; j < i+cnt; ++j) {
                s[j] = c;
            }
            i += cnt;
       }
        return move(s);
    }
};
class Solution {
public:
    string frequencySort(string& s) {
        array<int, 128> dict = {0};
        for (char c : s) {
            ++dict[c];
        }
        priority_queue<pair<int, char>> pq;
        for (int c = 0; c < dict.size(); ++c) {
            if (c > 0) {
                pq.emplace(dict[c], c);
            }
        }
        size_t i = 0;
        while (!pq.empty()) {
            auto [cnt, c] = pq.top(); pq.pop();
            for (size_t j = i; j < i+cnt; ++j) {
                s[j] = c;
            }
            i += cnt;
       }
        return move(s);
    }
};
