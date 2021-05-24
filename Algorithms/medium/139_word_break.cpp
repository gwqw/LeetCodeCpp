/**
	139. Word Break
Given a string s and a dictionary of strings wordDict, 
return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false

Constraints:
1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.

Algo0: naive: TL
for prefix in s:
	if prefix in dict: # use any of fast search
		res = isCanBeSplitted(suffix)
		if res: return true
return false

Algo1: forward dp, use dict: pos -> bool (can be solved)

Algo2: backward bp:
vector<bool> can_be(n, false)
for i = n-1; i > 0; --i:
    for j = i+1; j <=n; ++j:
        word = s[i:j]
        if word in dict:
            can_be[i] = j == n || can_be[j];
            if can_be[i]: break
return can_be[0]

*/

class Solution {
public:
    bool wordBreak(string_view s, const vector<string>& wordDict) {
        if (s.empty()) return false;
        unordered_set<string> dict{wordDict.begin(), wordDict.end()};
		return isCanBeSplitted(s, 0, dict);
    }
private:
	bool isCanBeSplitted(string_view s, size_t from, const unordered_set<string>& dict) {
		for (size_t i = from+1; i <= s.size(); ++i) {
			auto prefix = s.substr(from, i-from);
			if (dict.count(string(prefix))) {
				if (i == s.size()) return true;
				if (!can_be.count(i)) {
				    can_be[i] = isCanBeSplitted(s, i, dict);
			    }
			    bool res = can_be.at(i);
				if (res) return true;
			}
		}
		return false;		
	}
	
    unordered_map<size_t, bool> can_be;
};

class Solution {
public:
    bool wordBreak(string_view s, const vector<string>& wordDict) {
        if (s.empty()) return false;
        unordered_set<string> dict{wordDict.begin(), wordDict.end()};
        size_t max_size = 0;
        for (const auto& word : wordDict) {
            if (word.size() > max_size) max_size = word.size();
        }
	    vector<bool> can_be(s.size(), false);
        for (size_t i = s.size(); i-->0; ) {
            for (size_t j = i+1; j <= s.size(); ++j) {
                if (j-i > max_size) break; // short scheme
                if (j != s.size() && !can_be[j]) continue; // short scheme
                auto word = s.substr(i, j-i);
                if (dict.count(string(word))) {
                    can_be[i] = j == s.size() || can_be[j];
                    if (can_be[i])  break;
                }
            }
        }
        return can_be[0];
    }
};

// h(i) = (a_0 * x0 + ... + a_i * x^i + ...) % P
class Solution {
    static constexpr size_t P = 1'000'000'000 + 7;
    static constexpr size_t x = 37;
public:
    bool wordBreak(string_view s, const vector<string>& wordDict) {
        unordered_set<size_t> dict;
        for (const auto& word : wordDict) {
            dict.insert(calcHash(word));
        }
		return isCanBeSplitted(s, dict);
    }
private:
	bool isCanBeSplitted(string_view s, const unordered_set<size_t>& dict) {
		if (s.empty()) return false;
		size_t pref_hash = 0;
		for (size_t i = 0; i < s.size(); ++i) {
			pref_hash += s[i] * pow(x, i);
			pref_hash %= P;
			if (dict.count(pref_hash)) {
				if (i+1 == s.size()) return true;
				auto suffix = s.substr(i+1, s.size());
				bool res = isCanBeSplitted(suffix, dict);
				if (res) return true;
			}
		}
		return false;		
	}
	
	size_t calcHash(string_view s) {
	    if (s.empty()) return 0;
	    size_t res = 0;
	    for (size_t i = s.size()-1; i-->0; ) {
	        res *= x;
	        res += s[i];
	        res %= P;
	    }
	    return res;
	}
};


