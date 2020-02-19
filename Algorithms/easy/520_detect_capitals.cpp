/**
    520. Detect Capital
Given a word, you need to judge whether the usage of capitals in it is right or not.
We define the usage of capitals in a word to be right when one of the following cases holds:
All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.

Example 1:
Input: "USA"
Output: True
 
Example 2:
Input: "FlaG"
Output: False

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.

Algo: check all cases
- first small: go and check that all small
- first big go and check that all small or all big


*/

class Solution {
public:
    bool detectCapitalUse(const string& word) {
        if (word.size() <= 1) return true;
        bool first_small = !isCapital(word[0]);
        bool all_capital = isCapital(word[1]);        
        if (first_small && all_capital) return false;
        for (size_t i = 2; i < word.size(); ++i) {
            if (isCapital(word[i]) != all_capital) return false;
        }
        return true;
    }
    
private:
    static bool isCapital(char c) {
        return 'A' <= c && c <= 'Z';
    }
};
// the same, but use isupper, it returns int, so need cast to bool, argument need to be casted to unsigned int
class Solution {
public:
    bool detectCapitalUse(const string& word) {
        if (word.size() <= 1) return true;
        bool first_small = islower(word[0]);
        bool all_capital = isupper(word[1]);        
        if (first_small && all_capital) return false;
        for (int i = 2; i < (int)word.size(); ++i) {
            if ((bool)isupper(word[i]) != all_capital) return false;
        }
        return true;
    }
};

