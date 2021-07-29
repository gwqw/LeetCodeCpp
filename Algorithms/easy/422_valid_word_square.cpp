/**
    422. Valid Word Square
Given an array of strings words, return true if it forms a valid word square.
A sequence of strings forms a valid word square if the kth row and column read the same string, where 0 <= k < max(numRows, numColumns).

Example 1:
Input: words = ["abcd","bnrt","crmy","dtye"]
Output: true
Explanation:
The 1st row and 1st column both read "abcd".
The 2nd row and 2nd column both read "bnrt".
The 3rd row and 3rd column both read "crmy".
The 4th row and 4th column both read "dtye".
Therefore, it is a valid word square.

Example 2:
Input: words = ["abcd","bnrt","crm","dt"]
Output: true
Explanation:
The 1st row and 1st column both read "abcd".
The 2nd row and 2nd column both read "bnrt".
The 3rd row and 3rd column both read "crm".
The 4th row and 4th column both read "dt".
Therefore, it is a valid word square.

Example 3:
Input: words = ["ball","area","read","lady"]
Output: false
Explanation:
The 3rd row reads "read" while the 3rd column reads "lead".
Therefore, it is NOT a valid word square.

Constraints:
1 <= words.length <= 500
1 <= words[i].length <= 500
words[i] consists of only lowercase English letters.

Algo: compare row with col
for i in range(n):
	if not compare(row[i], col[i]): return false
return true
*/

class Solution {
public:
    bool validWordSquare(const vector<string>& words) {
        if (words.size() != words[0].size()) return false;
        for (size_t i = 0; i < words.size(); ++i) {
			if (!compare(words, i)) return false;
		}
		return true;
    }
	
private:
	static bool compare(const vector<string>& words, size_t i) {
	    if (words[i].size() > words.size()) return false;
		for (size_t j = 0; j < words[i].size(); ++j) {
			if (words[i][j] != words[j][i]) return false;
		}
		return true;
	}
};