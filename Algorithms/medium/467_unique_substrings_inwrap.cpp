/**
    467. Unique Substrings in Wraparound String
We define the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this:
"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
Given a string p, return the number of unique non-empty substrings of p are present in s.

Example 1:
Input: p = "a"
Output: 1
Explanation: Only the substring "a" of p is in s.

Example 2:
Input: p = "cac"
Output: 2
Explanation: There are two substrings ("a", "c") of p in s.

Example 3:
Input: p = "zab"
Output: 6
Explanation: There are six substrings ("z", "a", "b", "za", "ab", and "zab") of p in s.

Constraints:
1 <= p.length <= 10^5
p consists of lowercase English letters.

Algo1: dp O(N + |alphabet|^2)
dp[letter][length] -- for each letter write number of strings ending at this symbol
cur_length = 1
prev_idx = idx[p[0]]
dp[p[0]][0] = 1
for c in p:
    cur_idx = idx(c)
    if is_next(prev_idx, cur_idx):
        cur_length += 1
    else:
        cur_length = 1
    dp[c][0:cur_length] = 1
    prev_idx = cur_idx
ans = sum dp

Algo2: dp
dp[letter] -> length ending here
char c = p[0]
prev_idx = idx[c]
cur_length = 1
dp[c] = 1
for c in p:
    cur_idx = idx(c)
    if is_next(prev_idx, cur_idx):
        cur_length += 1
    else:
        cur_length = 1
    dp[c] = max(dp[c], cur_length)
    prev_idx = cur_idx
ans = sum dp
*/

class Solution {
public:
    int findSubstringInWraproundString(string_view p) {
        if (p.empty()) return 0;
        vector<vector<int>> dp(26, vector<int>(26, 0));
        int cur_length = 1;
        int prev_idx = calcIdx(p[0]);
        dp[prev_idx][0] = 1;
        for (size_t i = 1; i < p.size(); ++i) {
            char c = p[i];
            int cur_idx = calcIdx(c);
            if (isNext(prev_idx, cur_idx)) {
                cur_length++;
            } else {
                cur_length = 1;
            }
            for (size_t j = max(cur_length-26, 0); j < cur_length; ++j) {
                int n = j / 26 + 1;
                int idx = j % 26;
                dp[cur_idx][idx] = max(dp[cur_idx][idx], n);
            }
            prev_idx = cur_idx;
        }
        int ans = 0;
        for (const auto& row : dp) {
            for (auto c : row) {
                ans += c;
            }
        }
        return ans;
    }

private:
	int calcIdx(char c) {
		return c - 'a';
	}
	
	bool isNext(int prev_idx, int cur_idx) {
		return prev_idx + 1 == cur_idx || prev_idx - 25 == cur_idx;
	}
};

/*
dp[letter] -> length ending here
char c = p[0]
prev_idx = idx[c]
cur_length = 1
dp[c] = 1
for c in p:
    cur_idx = idx(c)
    if is_next(prev_idx, cur_idx):
        cur_length += 1
    else:
        cur_length = 1
    dp[c] = max(dp[c], cur_length)
    prev_idx = cur_idx
ans = sum dp
*/

class Solution {
public:
    int findSubstringInWraproundString(string_view p) {
        if (p.empty()) return 0;
        vector<int> dp(26, 0);
        char c = p[0];
        int cur_length = 1;
        int prev_idx = calcIdx(c);
        dp[prev_idx] = 1;
        for (size_t i = 1; i < p.size(); ++i) {
            c = p[i];
            int cur_idx = calcIdx(c);
            if (isNext(prev_idx, cur_idx)) {
                cur_length++;
            } else {
                cur_length = 1;
            }
            dp[cur_idx] = max(dp[cur_idx], cur_length);
            prev_idx = cur_idx;
        }
        int ans = 0;
        for (auto c : dp) {
            ans += c;
        }
        return ans;
    }

private:
	int calcIdx(char c) {
		return c - 'a';
	}
	
	bool isNext(int prev_idx, int cur_idx) {
		return prev_idx + 1 == cur_idx || prev_idx - 25 == cur_idx;
		// return (prev_idx + 1) % 26 == cur_idx;
	}
};

class Solution {
public:
    int findSubstringInWraproundString(string_view p) {
        if (p.empty()) return 0;
        array<int, 26> dp{0};
        char prev_c = p[0];
        int cur_length = 1;
        dp[calcIdx(prev_c)] = 1;
        for (size_t i = 1; i < p.size(); ++i) {
            char c = p[i];
            if (isNext(prev_c, c)) {
                cur_length++;
            } else {
                cur_length = 1;
            }
            int cur_idx = calcIdx(c);
            dp[cur_idx] = max(dp[cur_idx], cur_length);
            prev_c = c;
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }

private:
	int calcIdx(char c) {
		return c - 'a';
	}
	
	bool isNext(int prev_idx, int cur_idx) {
		return prev_idx + 1 == cur_idx || prev_idx - 25 == cur_idx;
		// return (prev_idx + 1) % 26 == cur_idx;
	}
};

