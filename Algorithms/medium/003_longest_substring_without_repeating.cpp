/**
    Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.

Example 1:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

Algo: O(N + k), O(k)
- go through the string and save substring (add collected in queue) and hash_map
- if we have collision, 
    - update max_length if needed
    - then pop out of queue and map until cur symbol
- repeat the first step


*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t max_length = 0;
        deque<char> q;
        unordered_set<char> hsh;
        for (auto c : s) {
            if (!hsh.count(c)) {
                hsh.insert(c);
                q.push_back(c);
            } else {
                if (q.size() > max_length) max_length = q.size();
                bool stop = false;
                while (!stop) {
                    if (q.empty()) break;
                    stop = q.front() == c;
                    hsh.erase(
                        q.front()
                    );
                    q.pop_front();
                }
                hsh.insert(c);
                q.push_back(c);
            }
        }
        return max(max_length, q.size());
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t max_length = 0;
        int idx = 0;
        unordered_set<char> hsh;
        for (auto c : s) {
            if (!hsh.count(c)) {
                hsh.insert(c);
            } else {
                if (hsh.size() > max_length) max_length = hsh.size();
                while (s[idx] != c) {
                    hsh.erase(s[idx++]);
                }
                idx++;
            }
        }
        return max(max_length, hsh.size());
    }
};
