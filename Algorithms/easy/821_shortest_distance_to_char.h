/**
    821. Shortest Distance to a Character
Given a string S and a character C, 
return an array of integers representing the shortest distance from the character C in the string.

Example 1:
Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]

Note:
S string length is in [1, 10000].
C is a single character, and guaranteed to be in string S.
All letters in S and C are lowercase.

Algo1: O(NlogN) + O(N + P) = O(N) (P <= N), дополнительно O(P)
- make a set with c positions cp = {p0, .., pn} : O(N)
- go through the string: O(N)
    - for symbol position pj find 2 closest c position in set cp: pi-1, pi: O(logN)
    - find min dist as: min(pj - pi-1, pi - pj) : O(1)
    - add it to vector
    
Algo2: O(N) + O(N), дополнительной O(1)
- create vector:
- go right and write to array distances after smbol 'C'
- go left and write to array the same, but it will distances before symbol

Algo3: O(N) + O(N) + дополнительной O(1)
- идём по строке, пока не встретим 'c'
- идём по вектору влево и заполняем distance++
- запоминаем p1
- идём дальше по строке и ищем позицию 'c'
- если нашлась -- p2
    - идём по вектору и записываем в min(d1++, d2--)
- не нашлась (конец строки)
    - идём по вектору и записываем d++
*/

class Solution {
public:
    vector<int> shortestToChar(const string& s, char c) {
        set<int> cp;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == c) {
                cp.insert(i);
            }
        }
        
        vector<int> res(s.size());
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == c) {
                res[j] = 0;
                continue;
            }
            auto it = cp.lower_bound(j);
            if (it == cp.begin()) {
                res[j] = *it - j;
            } else if (it == cp.end()) {
                res[j] = j - *prev(it);
            } else {
                res[j] = min(*it - j, j - *prev(it));
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> shortestToChar(const string& s, const char c) {
        vector<int> res(s.size());
        int d = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == c) {
                res[i] = 0;
                d = 0;
            } else if (d != -1) {
                res[i] = ++d;
            } else {
                res[i] = -1;
            }
        }
        
        d = -1;
        for (int i = (int)s.size() - 1; i >= 0; --i) {
            if (s[i] == c) {
                d = 0;
            } else if (d != -1) {
                ++d;
                if (res[i] == -1 || res[i] > d) res[i] = d;
            }
        }
        
        return res;
    }
};

class Solution {
public:
    vector<int> shortestToChar(const string& s, const char c) {
        vector<int> res(s.size());
        int d1 = -1, d2 = -1;
        for (int i = 0; i < s.size(); ++i) {
            // fill first part of vector
            if (d1 == -1 && d2 == -1) {
                if (s[i] != c) continue;
                d1 = 0;
                for (int j = i; j >= 0; --j) {
                    res[j] = d1++;
                }
                d1 = i;
                continue;
            }
            // fill part of vector between c
            else if (d1 != -1 && d2 == -1) {
                if (s[i] != c) continue;
                int j = d1;
                d2 = i - d1;                
                d1 = 0;
                for ( ; j <= i; ++j) {
                    res[j] = min(d1++, d2--);
                }
                d1 = i;
                d2 = -1;
            }
        }
        // fill the rest part
        if (d1 != (int)s.size()-1) {
            d2 = 1;
            for (int i = d1+1; i < s.size(); ++i) {
                res[i] = d2++;
            }
        }
        
        return res;
    }
};






