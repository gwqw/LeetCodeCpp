/**
    917. Reverse Only Letters

Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

Example 1:
Input: "ab-cd"
Output: "dc-ba"

Example 2:
Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"

Example 3:
Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"

Note:
S.length <= 100
33 <= S[i].ASCIIcode <= 122 
S doesn't contain \ or "

Algo1 (in-place): quick-sort (in place): O(N) + O(1)
- we have 2 iterators: b and e
- go through string ++b and --e while !cond (for b and e) and do nothing
- if stop and if b < e: swap *b and *e
- else break and return

Algo2 (copy): O(N) + O(N)
- create letter_stack, other_queue
- go through string and paste to stack and queue
- go through string and take from stack is is letter else from queue and paste to res-string
*/

class Solution {
private:
    bool is_letter(char c) {return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');}
public:
    string reverseOnlyLetters(string& s) {
        if (s.size() <= 1) return s;
        int b = 0;
        int e = (int)s.size()-1;
        while (true) {
            while (b < e && !is_letter(s[b])) {++b;}
            if (b >= e) break;
            while (b < e && !is_letter(s[e])) {--e;}
            if (b >= e) break;
            std::swap(s[b], s[e]);
            ++b;
            --e;
        }
        return std::move(s);
    }
};

class Solution {
private:
    bool is_letter(char c) {return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');}
public:
    string reverseOnlyLetters(const string& s) {
        if (s.size() <= 1) return s;
        string res;
        res.reserve(s.size());
        stack<char> letters;
        queue<char> other;
        
        for (auto c : s) {
            if (is_letter(c)) {
                letters.push(c);
            } else {
                other.push(c);
            }
        }
        for (auto c : s) {
            if (is_letter(c)) {
                res += letters.top();
                letters.pop();
            } else {
                res += other.front();
                other.pop();
            }
        }
        
        return res;
    }
};

