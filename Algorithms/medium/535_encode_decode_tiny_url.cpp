/**
    535. Encode and Decode TinyURL
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk. Design a class to encode a URL and decode a tiny URL.

There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

Implement the Solution class:
Solution() Initializes the object of the system.
String encode(String longUrl) Returns a tiny URL for the given longUrl.
String decode(String shortUrl) Returns the original long URL for the given shortUrl. It is guaranteed that the given shortUrl was encoded by the same object.

Example 1:
Input: url = "https://leetcode.com/problems/design-tinyurl"
Output: "https://leetcode.com/problems/design-tinyurl"

Explanation:
Solution obj = new Solution();
string tiny = obj.encode(url); // returns the encoded tiny url.
string ans = obj.decode(tiny); // returns the original url after deconding it.
 

Constraints:
1 <= url.length <= 10^4
url is guranteed to be a valid URL.

Algo: make hash for dict
- generate short string 
- insert string with url to dict
- and back
*/

class Solution {
	static constexpr int KEY_LEN = 6;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        auto key = generateKey();
		while (dict.count(key)) {
			key = generateKey();
		}
		dict[key] = move(longUrl);
		return key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(const string& shortUrl) {
        return dict.at(shortUrl);
    }
	
private:
	string generateKey() {
		string key(KEY_LEN, 0);
		for (int i = 0; i < KEY_LEN; ++i) {
			char c = 0;
			if (rand() % 36 > 9) {
				c = rand() % 26 + 'a';
			} else {
				c = rand() % 10 + '0';
			}
			key[i] = c;
		}
		return key;
	}
	
private:
	unordered_map<string, string> dict;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));