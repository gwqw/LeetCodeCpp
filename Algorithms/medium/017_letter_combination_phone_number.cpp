/**
    17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, 
return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below. 
Note that 1 does not map to any letters.

Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

Algo: backtracking
- treat position:
    ans for each add <- dict[num] 1, 2, 3
- recursive
*/

const unordered_map<char, string> dict{
                  {'2', "abc"}, {'3', "def"}, 
    {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
    {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
};

class Solution {
public:
    vector<string> letterCombinations(const string& digits) {
        if (digits.empty()) return {};
        vector<string> ans;
        treatLetter(digits, 0, ans);
        return ans;
    }
private:
    static void treatLetter(const string& digits, size_t from, vector<string>& ans) {
        if (from == digits.size()) return;
        char digit = digits[from];
        auto letters = dict.at(digit);
        if (from == 0) {
            for (auto l : letters) {
                ans.push_back({l});
            }
        } else {
            vector<string> res;
            res.reserve(ans.size() * letters.size());
            for (const auto& s : ans) {
                for (auto l : letters) {
                    res.push_back(s+l);
                }
            }
            swap(ans, res);
        }
        treatLetter(digits, from+1, ans);
    }
};
