/**
    557. Reverse Words in a String III
Given a string, you need to reverse the order of characters in each word within
 a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Note: In the string, each word is separated by single space and there will not 
be any extra space in the string.

Algo: O(N) + O(1)
while e != size:
- find e = end of word (pos(' '))
- reverse word (b, e)

*/

class Solution {
public:
    string reverseWords(string s) {
        size_t beg = 0, e = 0;
        while (e != s.size()) {
            e = s.find(' ', beg);
            if (e == string::npos) {
                e = s.size();
            }
            reverse(s, beg, e);
            beg = e+1;
        }        
        return move(s);
    }
    
private:
    static void reverse(string& word, const size_t from, const size_t to) {
        for (size_t i = 0; i < (to - from)/2; ++i) {
            swap(word[from + i], word[to-i-1]);
        }
    }
};
