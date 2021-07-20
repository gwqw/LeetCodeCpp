/**
    1239. Maximum Length of a Concatenated String with Unique Characters
Given an array of strings arr. String s is a concatenation of a sub-sequence of arr which have unique characters.

Return the maximum possible length of s.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible solutions are "chaers" and "acters".
Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
 

Constraints:
1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lower case English letters.

Algo: backtracking
*/

const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxLength(vector<string>& a) {
        a = filter(a);
        string cur;
        vector<string> res;
        bt(a, cur, 0, res);
        int max_size = 0;
        for (const auto& r : res) {
            max_size = max(max_size, int(r.size()));
        }
        return max_size;
    }
    
private:
    void bt(const vector<string>& a, string cur, int idx, 
        vector<string>& res) 
    {
        if (idx >= a.size()) {
            res.push_back(move(cur));
            return;
        }
        bool is_inserted = false;
        for (int i = idx; i < a.size(); ++i) {
            if (intersect(cur, a[i])) {
                //cout << cur << " and " << a[i] << " intersects\n";
                continue;                
            }
            bt(a, cur+a[i], i+1, res);
            is_inserted = true;
        }
        if (!is_inserted) {
            res.push_back(move(cur));
        }
    }
    
    bool intersect(string_view lhs, string_view rhs) {
        array<char, 26> lar = {0};
        for (char c : lhs) {
            if (lar[c-'a'] == 1) return true;
            lar[c-'a'] = 1;
        }
        array<char, 26> rar = {0};
        for (char c : rhs) {
            if (lar[c-'a'] == 1) return true;
            if (rar[c-'a'] == 1) return true;
            rar[c-'a'] = 1;
        }
        return false;
    }
    
    vector<string> filter(vector<string>& a) {
        vector<string> res;
        res.reserve(a.size());
        for (auto& s : a) {
            bool cr = true;
            array<char, 26> ar = {0};
            for (char c : s) {
                if (ar[c-'a'] == 1) {
                    cr = false;
                    break;
                }
                ar[c-'a'] = 1;
            }
            if (cr) {
                res.push_back(move(s));
            }
        }
        return res;
    }
};