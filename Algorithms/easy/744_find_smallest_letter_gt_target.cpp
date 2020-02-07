/**
    744. Find Smallest Letter Greater Than Target
Given a list of sorted characters letters containing only lowercase letters, 
and given a target letter target, 
find the smallest element in the list that is larger than the given target.
Letters also wrap around. 
For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.

Examples:
Input:
letters = ["c", "f", "j"]
target = "a"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "c"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "d"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "g"
Output: "j"

Input:
letters = ["c", "f", "j"]
target = "j"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "k"
Output: "c"

Note:
letters has a length in range [2, 10000].
letters consists of lowercase letters, and contains at least 2 unique letters.
target is a lowercase letter.

Algo: O(logN) + O(1)
- f = upper_bound(target)
- if f: return f
- else: return first

*/

class Solution {
public:
    char nextGreatestLetter(const vector<char>& letters, char target) {
        auto it = upper_bound(letters.begin(), letters.end(), target);
        if (it != letters.end()) {
            return *it;
        } else {
            return letters.front();
        }        
    }
};

class Solution {
public:
    char nextGreatestLetter(const vector<char>& letters, char target) {
        size_t l = 0;
        size_t r = letters.size();
        while (l < r) {
            size_t m = l + (r - l) / 2;        
            if (letters[m] <= target) {
                l = m+1;
            } else {
                r = m;
            }
        }
        if (r != letters.size()) {
            return letters[r];
        } else {
            return letters[0];
        }        
    }
};
class Solution {
public:
    char nextGreatestLetter(const vector<char>& letters, char target) {
        int l = -1;
        int r = (int)letters.size();
        while (l+1 < r) {
            size_t m = l + (r - l) / 2;        
            if (letters[m] <= target) {
                l = m;
            } else {
                r = m;
            }
        }
        if (r != letters.size()) {
            return letters[r];
        } else {
            return letters[0];
        }        
    }
};


