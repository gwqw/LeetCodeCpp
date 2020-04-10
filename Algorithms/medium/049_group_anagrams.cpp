/**
    49. Group Anagrams
Given an array of strings, group anagrams together.

Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:
All inputs will be in lowercase.
The order of your output does not matter.

Algo: use dict: O(words_count * word_length) + O(words_count * word_length)
- LetterCount = array<size_t, 26>;
- dict<LetterCount, vector<string>>
- to ans
*/

class Solution {
    using LetterCount = array<size_t, 26>;
    struct Hasher {
        static constexpr size_t P = 37;
        static constexpr size_t N = 1000000007;
        size_t operator()(const LetterCount value) const {
            size_t res = 0;
            size_t x = 1;
            for (auto v : value) {
                res += v * x;
                res %= N;
                x *= P;
                x %= N;
            }
            return res;
        }
    };
public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        unordered_map<LetterCount, vector<string>, Hasher> dict;
        for (const auto& word : strs) {
            auto word_print = getWordCount(word);
            dict[word_print].push_back(word);
        }
        // convert to  answer
        vector<vector<string>> ans;
        ans.reserve(dict.size());
        for (auto& [_,v] : dict) {
            ans.push_back(move(v));
        }
        return ans;
    }
    
private:
    LetterCount getWordCount(const string& word) {
        LetterCount res = {0};
        for (auto c : word) {
            ++res[c - 'a'];
        }
        return res;
    }
};


class Solution {
    using LetterCount = array<size_t, 26>;
    struct Hasher {
        static constexpr size_t P = 37;
        static constexpr size_t N = 1000000007;
        size_t operator()(const LetterCount value) const {
            size_t res = 0;
            size_t x = 1;
            for (auto v : value) {
                res += v * x;
                res %= N;
                x *= P;
                x %= N;
            }
            return res;
        }
    };
public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        unordered_map<size_t, vector<string>> dict;
        for (const auto& word : strs) {
            auto word_print = getWordHash(word);
            dict[word_print].push_back(word);
        }
        // convert to  answer
        vector<vector<string>> ans;
        ans.reserve(dict.size());
        for (auto& [_,v] : dict) {
            ans.push_back(move(v));
        }
        return ans;
    }
    
private:
    size_t getWordHash(const string& word) {
        LetterCount res = {0};
        for (auto c : word) {
            ++res[c - 'a'];
        }
        return hash(res);
    }
    
    Hasher hash;
};

const int _ = [](){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    return 0;
}();

