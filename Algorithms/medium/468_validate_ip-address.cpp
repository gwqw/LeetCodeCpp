/**
    468. Validate IP Address
Given a string IP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 address or "Neither" if IP is not a correct IP of any type.
A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros. For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses but "192.168.01.1", while "192.168.1.00" and "192.168@1.1" are invalid IPv4 addresses.
A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:
1 <= xi.length <= 4
xi is a hexadecimal string which may contain digits, lower-case English letter ('a' to 'f') and upper-case English letters ('A' to 'F').
Leading zeros are allowed in xi.
For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses, while "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.

Example 1:
Input: IP = "172.16.254.1"
Output: "IPv4"
Explanation: This is a valid IPv4 address, return "IPv4".

Example 2:
Input: IP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
Output: "IPv6"
Explanation: This is a valid IPv6 address, return "IPv6".

Example 3:
Input: IP = "256.256.256.256"
Output: "Neither"
Explanation: This is neither a IPv4 address nor a IPv6 address.

Example 4:
Input: IP = "2001:0db8:85a3:0:0:8A2E:0370:7334:"
Output: "Neither"

Example 5:
Input: IP = "1e1.4.5.6"
Output: "Neither"

Constraints:
IP consists only of English letters, digits and the characters '.' and ':'.

Algo:
if has '.' and size in 4*1+3=7 -> 4*3+7 = 19:
	return validIP4(ip)
else has ':': 8*1+7 = 15 -> 8*4+7 -> 39
	return validIP6(ip) 
*/

class Solution {
public:
    string validIPAddress(string_view ip) {
        if (ip.find('.') != string_view::npos) {
			if (7 <= ip.size() && ip.size() <= 19) {
				return validIP4(ip);
			} else {
				return "Neither";
			}
		} else if (ip.find(':') != string_view::npos) {
			if (15 <= ip.size() && ip.size() <= 39) {
				return validIP6(ip);
			} else {
				return "Neither";
			}
		} else {
			return "Neither";
		}
    }
	
private:
	string validIP4(string_view ip) {
        if (ip.back() == '.') return "Neither";
		int cnt = 0;
		while (!ip.empty() && cnt < 4) {
			auto part = nextWord(ip, '.');
			++cnt;
			if (!isValidIP4Part(part)) return "Neither";
		}
		return ip.empty() && cnt == 4 ? "IPv4" : "Neither";
	}
	
	string validIP6(string_view ip) {
        if (ip.back() == ':') return "Neither";
		int cnt = 0;
		while (!ip.empty() && cnt < 8) {
			auto part = nextWord(ip, ':');
			++cnt;
			if (!isValidIP6Part(part)) return "Neither";
		}
		return ip.empty() && cnt == 8 ? "IPv6" : "Neither";
	}
	
	string_view nextWord(string_view& s, char sep) {
		auto pos = s.find(sep);
		string_view res;
		if (pos == string_view::npos) {
			res = s;
			s.remove_prefix(s.size());
			return res;
		}
		res = s.substr(0, pos);
		s.remove_prefix(pos+1);
		return res;
	}
	
	bool isValidIP4Part(string_view part) {
        if (part.empty() || part.size() > 3) return false;
		int n = 0;
		if (auto [p,e] = from_chars(part.data(), part.data() + part.size(), n);
			e == errc()) 
		{
			if (p != part.data() + part.size()) {
				return false;
			}
			if (n < 0 || n > 255) return false;
			if (part.size() > 1 && part[0] == '0') return false;
		} else {
			return false;
		}
		return true;
	}
	
	bool isValidIP6Part(string_view part) {
		if (part.empty() || part.size() > 4) return false;
		for (char c : part) {
			if (!(isdigit(c) || 'a' <= c && c <= 'f' || 'A' <= c && c <= 'F')) return false;
		}
		return true;
	}
};