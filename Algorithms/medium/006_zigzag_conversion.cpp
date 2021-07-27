/**
    6. ZigZag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);

Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Example 3:
Input: s = "A", numRows = 1
Output: "A"

Constraints:
1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000

Algo1: simple form matrix (slow): O(N), O(N)mem
col = 1 + r-2 --> elements: r + r - 2
2 modes: col, diag
cur_col, cur_row
fill col to numRows
fill diag
+col, -row while row >= 0
fill col ...

Algo2: find next idx for r,c in str: O(N), O(1)
for r in row_nums:
    for i in 0, n, k: # k = r + r - 2 = 2*r-2
        res.add(i-r) # check conditions >=0 && < size && r != 0 && r != row_nums-1
        res.add(i+r)
*/

class Solution {
	enum class Mode {FC, FD};
	static constexpr char EMPTY = ' ';
public:
    string convert(const string& s, int n) {
        if (n == 1) return s;
		int m = calcColNums(s.size(), n);
		vector<vector<char>> mtx(n, vector<char>(m, EMPTY));
		Mode mode(Mode::FC);
		int r = 0, c = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (mode == Mode::FC) {
				mtx[r++][c] = s[i];
			} else {
				mtx[r--][c++] = s[i];
			}
			// switch mode
			if (mode == Mode::FC && r == n-1) {
				mode = Mode::FD;
			} else if (mode == Mode::FD && r == 0) {
				mode = Mode::FC;
			}
		}
		// for ans
		string ans;
		ans.reserve(s.size());
		for (const auto& row : mtx) {
			for (auto e : row) {
				if (e != EMPTY) {
					ans.push_back(e);
				}
			}
		}
		return ans;
    }
	
private:
	int calcColNums(int n, int r) {
		// 1 + r-2 --> r + r - 2
		int m = n * (r-1) / (2*r-2) + n * (r-1) % (2*r-2);
		return m;
	}
};


class Solution {
public:
    string convert(const string& s, int n) {
        if (n == 1) return s;
        int k = n + n - 2;
        string res; res.reserve(s.size());
        for (int r = 0; r < n; ++r) {
            for (int i = 0; i-r < (int)s.size(); i += k) {
                int j1 = i - r;
                if (j1 >= 0 && r+1 != n) {
                    res.push_back(s[j1]);
                }
                int j2 = i + r;
                if (j2 != j1 && j2 < (int)s.size()) {
                    res.push_back(s[j2]);
                }
            }
        }
        return res;
    }
};