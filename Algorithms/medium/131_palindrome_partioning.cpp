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

Algo: dp O(N^3)
for e in len(s): for all prefixes, e = end of prefix: O(N)
    for i in 0, e:  O(N)
        if is_palindrom(i,e): O(N)
            pali = s[i,e]
            pali[i] += pali[j] + pali
	return pali[-1]
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

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
//		cout << "palis:\n";
//		for (size_t i=0; i < palis.size(); ++i) {
//		    cout << "i: " << i << '\n';
//		    const auto& res = palis[i];
//		    for (const auto& l : res) {
//                for (const auto& w : l) {
//                    cout << w << ", ";
//                }
//                cout << '\n';
//            }
//        }
		
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

int main() {
    Solution sol;
    auto res = sol.partition("aaaaaaaaaaaaaaaa");
    cout << "res.size: " << res.size() << endl;
//    for (const auto& l : res) {
//        for (const auto& w : l) {
//            cout << w << ", ";
//        }
//        cout << '\n';
//    }
    return 0;
}
