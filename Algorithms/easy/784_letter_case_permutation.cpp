/**
    784. Letter Case Permutation
Given a string S, we can transform every letter individually to be lowercase or 
uppercase to create another string.
Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]

Note:
S will be a string with length between 1 and 12.
S will consist only of letters or digits.

Algo1: recursive: O(N*2^N) + O(N*2^N)
- list = premutation(s[1:])
- if char is letter:
    - copy lst -> lst_temp
    - change letter to other case
    - insert lst_temp to lst
- return list

Algo2: itterative: O(N*2^N) + O(N*2^N)
- make res = {}
- go from begin to end
- if c is digit:
    - add c to all s in res
- else (is letter):
    - add letter to all
    - copy
    - change letter
    - insert

*/

class Solution {
public:
    vector<string> letterCasePermutation(string_view s) {
        return permutation(s, 0, s.size());
    }
private:
    static vector<string> permutation(string_view s, size_t from, size_t to) {
        if (to - from == 1) {
            if (is_letter(s[from])) {
                vector<string> res{string(s), string(s)};
                res.back()[from] = toOtherCase(res.back()[from]);
                return res;
            } else {
                return {string(s)};
            }
        }
        
        auto lst = permutation(s, from+1, to);
        if (is_letter(s[from])) {
            auto lst_tmp = lst;
            for (auto& line : lst_tmp) {
                line[from] = toOtherCase(line[from]);
            }

            lst.insert(lst.end(), make_move_iterator(lst_tmp.begin()), 
                       make_move_iterator(lst_tmp.end()));
        }
        return lst;
    }

    static bool is_letter(char c) {
        return std::isalpha(static_cast<unsigned char>(c));
    }
    
    static char toOtherCase(char c) {
        if ('a' <= c && c <= 'z') {
            return static_cast<char>(toupper(static_cast<unsigned char>(c)));
        }
        if ('A' <= c && c <= 'Z') {
            return static_cast<char>(tolower(static_cast<unsigned char>(c)));
        }
        throw invalid_argument("Required only letter");
    }
};

/*
Algo2: itterative: O(N*2^N) + O(N*2^N)
- make res = {}
- go from begin to end
- if c is digit:
    - add c to all s in res
- else (is letter):
    - add letter to all
    - copy
    - change letter
    - insert
*/

class Solution {
public:
    vector<string> letterCasePermutation(string_view s) {
        auto letter_count = countLetters(s);
        vector<string> res;
        res.reserve(pow(2, letter_count));
        res.emplace_back("");
        res.back().reserve(s.size());
        for (auto c : s) {
            for (auto& line : res) {
                line.push_back(c);
            }
            if (is_letter(c)) {
                auto lst_tmp = res;
                for (auto& line : lst_tmp) {
                    line.back() = toOtherCase(line.back());
                }
                res.insert(res.end(), make_move_iterator(lst_tmp.begin()), 
                       make_move_iterator(lst_tmp.end()));
            }
        }
        return res;        
    }
private:
    static bool is_letter(char c) {
        return std::isalpha(static_cast<unsigned char>(c));
    }
    
    static char toOtherCase(char c) {
        if ('a' <= c && c <= 'z') {
            return static_cast<char>(toupper(static_cast<unsigned char>(c)));
        }
        if ('A' <= c && c <= 'Z') {
            return static_cast<char>(tolower(static_cast<unsigned char>(c)));
        }
        throw invalid_argument("Required only letter");
    }
    
    static size_t countLetters(string_view s) {
        size_t counter = 0;
        for (auto c : s) {
            if (is_letter(c)) ++counter;
        }
        return counter;
    }
};



