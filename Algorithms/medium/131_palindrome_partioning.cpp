/**
    131. Palindrome Partitioning
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
A palindrome string is a string that reads the same backward as forward.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]

Constraints:
1 <= s.length <= 16
s contains only lowercase English letters.

Algo: bf
w=1: 1
w=2: search w=2 if found: add polynoms from str_part
w=3: search w=3 if ...

Algo1: dp O(N^2)
for e in len(s): for all prefixes, e = end of prefix: O(N)
    for i in 0, e:  O(N)
        if is_palindrom(i,e): O(1)
            pali = s[i,e]
            pali[i] += pali[i-1] + pali
	return pali[-1]
	
Algo2: same but use is_pali as dp

Algo3: is_pali: vector[first] -> list of ends
*/

class Solution {
public:
    vector<vector<string>> partition(const string& s) {
		vector<vector<vector<string>>> palis(s.size());
		palis[0].push_back({string{s[0]}});
		for (size_t e = 1; e < s.size(); ++e) {
		    for (size_t i = 0; i <= e; ++i) {
		        if (is_pali(s, i, e)) {
		            string pali = s.substr(i, e-i+1);
		            vector<vector<string>> curp = i > 0 ? palis[i-1] : vector<vector<string>>{};
		            if (!curp.empty()) {
		                for (auto& p : curp) {
        		            p.push_back(pali);
        		            palis[e].push_back(p);
		                }
		            } else {
		                palis[e].push_back({pali});
		            }
		        }
		    }
		}
		return palis.back();
    }
private:
    bool is_pali(const string& s, size_t init, size_t e) {
        if (init == e) return true;
        for (size_t i = init; i <= (e + init) / 2; ++i) {
            if (s[i] != s[e-i+init]) return false;
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> partition(const string& s) {
		vector<vector<vector<string>>> palis(s.size());
		palis[0].push_back({string{s[0]}});
		auto is_pali = checkForPalis(s);
		for (size_t e = 1; e < s.size(); ++e) {
		    for (size_t i = 0; i <= e; ++i) {
		        if (is_pali[i][e]) {
		            string pali = s.substr(i, e-i+1);
		            vector<vector<string>> curp = i > 0 ? palis[i-1] : vector<vector<string>>{};
		            if (!curp.empty()) {
		                for (auto& p : curp) {
        		            p.push_back(pali);
        		            palis[e].push_back(p);
		                }
		            } else {
		                palis[e].push_back({pali});
		            }
		        }
		    }
		}
		return palis.back();
    }
private:
    vector<vector<char>> checkForPalis(string_view s) {
        vector<vector<char>> is_pali(s.size(), vector<char>(s.size(), 1));
        for (size_t i = 0; i+1 < s.size(); ++i) {
            is_pali[i][i+1] = s[i] == s[i+1];
        }
        for (size_t len = 3; len <= s.size(); ++len) {
            for (size_t start = 0; start+len <= s.size(); ++start) {
                size_t end = start + len - 1;
                is_pali[start][end] = s[start] == s[end] && is_pali[start+1][end-1];
            }
        }
        return is_pali;
    }
};
