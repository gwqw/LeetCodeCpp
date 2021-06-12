/**
    91. Decode Ways
A message containing letters from A-Z can be encoded into numbers using the following mapping:
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:
"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.
The answer is guaranteed to fit in a 32-bit integer.

Example 1:
Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).

Example 2:
Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

Example 3:
Input: s = "0"
Output: 0
Explanation: There is no character that is mapped to a number starting with 0.
The only valid mappings with 0 are 'J' -> "10" and 'T' -> "20", neither of which start with 0.
Hence, there are no valid ways to decode this since all digits need to be mapped.

Example 4:
Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").

Constraints:
1 <= s.length <= 100
s contains only digits and may contain leading zero(s).

Algo1: recursive: back_track: 2^N variants
1 -- A
26 -- Z
decode(s, pos, cnt):
	if pos == s.size(): 
		cnt += 1
		return
	if s[pos] == '0': return
	# 1 symbol
	decode(s, pos+1, cnt)
	# 2 symbols
	if pos+1 != s.size():
		num = int(s[pos:pos+2])
		if num <= 26:
		decode(s, pos+2, cnt)		

Algo2: dp O(N), O(N) mem (could be O(1) if use 3 vars: cur, pred, predpred)
[prefix] -> cnt
i-1 -> cnt[i-1]
for i in s.size(): 
	if c == 0:
		if prev == '1' or '2':
			cnt[i] = cnt[i-2]
		else:
			return 0
	else:
		cnt[i] = cnt[i-1]
		if int(prev+c) <= 26:
			cnt[i] += cnt[i-2]
Fibonacci numbers
*/

class Solution {
public:
    int numDecodings(string_view s) {
		int cnt = 0;
		decode(s, 0, cnt);
		return cnt;
    }
	
private:
	void decode(string_view s, size_t pos, int& cnt) {
		if (pos == s.size()) {
			++cnt;
			return;
		}
		if (s[pos] == '0') return;
		// 1 symbol
		decode(s, pos+1, cnt);
		// 2 symbol
		int num = stoi(string(s.substr(pos, 2)));
		if (num <= 26) {
			decode(s, pos+2, cnt);
		}
	}
};

class Solution {
public:
    int numDecodings(string_view s) {
        if (s.empty() || s[0] == '0') return 0;
		if (s.size() == 1) return 1;
		vector<int> cnt(s.size());
		cnt[0] = 1;
		cnt[1] = StrToInt(s.substr(0,2)) <= 26 ? 1 : 0;
		cnt[1] += s[1] != '0' ? 1 : 0;
        for (size_t i = 2; i < s.size(); ++i) {
            if (s[i] == '0') {
                if (s[i-1] == '1' || s[i-1] == '2') {
                    cnt[i] = cnt[i-2];
                } else {
                    return 0;
                }
            } else {
                cnt[i] = cnt[i-1];
                if (int num = StrToInt(s.substr(i-1,2)); 
                    s[i-1] != '0' && num <= 26) 
                {
                    cnt[i] += cnt[i-2];
                }
            }
        }
        return cnt.back();
    }
    
private:
    static int StrToInt(string_view s) {
        int value = 0;
        auto [end, ec] = from_chars(s.begin(), s.end(), value);
        return value;
    }
};

