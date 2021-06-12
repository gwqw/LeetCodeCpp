/**
    771. Jewels and Stones
You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.
Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:
Input: jewels = "aA", stones = "aAAbbbb"
Output: 3

Example 2:
Input: jewels = "z", stones = "ZZ"
Output: 0

Constraints:
1 <= jewels.length, stones.length <= 50
jewels and stones consist of only English letters.
All the characters of jewels are unique.

Algo: use dict
- make set from jewels
for stone if in set:
    cnt+=1
return cnt
*/

class Solution {
public:
    int numJewelsInStones(string_view jewels, string_view stones) {
        unordered_set<char> jew_set{jewels.begin(), jewels.end()};
        int cnt = 0;
        for (auto c : stones) {
            if (jew_set.count(c)) {
                ++cnt;
            }
        }
        return cnt;
    }
};
