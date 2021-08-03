/**
    93. Restore IP Addresses
Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s. You can return them in any order.
A valid IP address consists of exactly four integers, each integer is between 0 and 255, separated by single dots and cannot have leading zeros. For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. 

Example 1:
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

Example 2:
Input: s = "0000"
Output: ["0.0.0.0"]

Example 3:
Input: s = "1111"
Output: ["1.1.1.1"]

Example 4:
Input: s = "010010"
Output: ["0.10.0.10","0.100.1.0"]

Example 5:
Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

Constraints:
0 <= s.length <= 3000
s consists of digits only.

Algo: backtracking
if len > nums*3 or len < nums: return
if nums == 0 && len == 0:
	res.push(createAns(poses))
for pos in 0..2, len(s):
	take pos
	if correct num:
		backtrack(s.substr(pos))
*/

class Solution {
public:
    vector<string> restoreIpAddresses(string_view s) {
        vector<string> res;
		vector<string_view> cur;
		cur.reserve(4);
		backtrack(s, 4, cur, res);
		return res;
    }
	
private:
	void backtrack(string_view s, int nums, vector<string_view>& cur, vector<string>& res) {
        if (nums == 0 && s.size() == 0) {
			res.emplace_back(createAnswer(cur));
            return;
		}
		if (s.size() > 3*nums || s.size() < nums) return;
		for (int i = 1; i <= min(size_t(3u), s.size()); ++i) {
            assert(i <= s.size());
			string_view part = s.substr(0, i);
			int n = stoi(string(part)); //TODO: from_char
            if (n > 255 || i > 1 && part[0] == '0') continue;
            cur.push_back(part);
            backtrack(s.substr(i), nums-1, cur, res);
            cur.pop_back();
		}
	}
	
	string createAnswer(const vector<string_view>& ip) {
		string res;
		bool is_fisrt = true;
		for (auto part : ip) {
			if (is_fisrt) {
				is_fisrt = false;
			} else {
				res += '.';
			}
			res += string(part);
		}
		return res;
	}
};