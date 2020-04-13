/**
    395. Longest Substring with At Least K Repeating Characters
Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

Example 1:
Input:
s = "aaabb", k = 3
Output:
3
The longest substring is "aaa", as 'a' is repeated 3 times.

Example 2:
Input:
s = "ababbc", k = 2
Output:
5
The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.

Algo: naive brute-force: O(N^2) + O(dict)
- max_length = 0
- for every first:
    - go and calc dict[char]++
        - if  all dict[char] >= k (or ==0)
        - max_length = lst - first+1

Algo: divide and couquer
- calc statistic: char -> count
- if stat[char] < k: divide point
- if no divide points: return string length
- split string on substrings
- l = recursion for every substr
- return max_l = max(l_i)
*/

class Solution {
public:
    int longestSubstring(string_view s, int k) {
        if (s.empty()) return 0;
        if (s.size() == 1) return k == 1 ? 1 : 0;
        size_t max_length = 0;
        for (size_t f = 0; f+1 < s.size(); ++f) {
            array<int, 26> dict = {0};
            ++dict[s[f] - 'a'];
            bool was_good = false;
            for (size_t l = f+1; l < s.size(); ++l) {
                ++dict[s[l] - 'a'];
                if (was_good) {
                    was_good = dict[s[l]] >= k;
                    if (was_good) max_length = max(max_length, l-f+1);
                } else if (has_all(dict, k)) {
                    was_good = true;
                    max_length = max(max_length, l-f+1);
                } else {
                    was_good = false;
                }
            }
        }
        return max_length;
    }
    
private:
    static bool has_all(const array<int, 26>& a, int k) {
        for (auto v : a) {
            if (v != 0 && v < k) return false;
        }
        return true;
    }
};

class Solution {
public:
    int longestSubstring(string_view s, int k) {
        return recursive_search(s, 0, s.size(), k);
    }
    
private:
    static int recursive_search(string_view s, size_t from, size_t to, int k) {
        assert(from <= to);
        if (from == to) return 0;
        if (to - from == 1) return k == 1 ? 1 : 0;
        unordered_map<char, int> d;
        for (size_t i = from; i < to; ++i) {
            ++d[s[i]];
        }
        size_t f = from;
        int max_l = 0;
        while (f < to) {
            while (f < to && d[s[f]] < k) {
                ++f;
            }
            if (f >= to) break;
            size_t t = f;
            while (t < to && d[s[t]] >= k) {
                ++t;
            }
            if (f != from || t != to) {
                auto l = recursive_search(s, f, t, k);
                max_l = max(max_l, l);
            } else {
                return to - from;
            }            
            f = t;
        }
        return max_l;
    }
};



cout << from << " " << to << endl;

