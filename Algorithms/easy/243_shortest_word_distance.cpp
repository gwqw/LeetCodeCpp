/**
    243. Shortest Word Distance
Given an array of strings wordsDict and two different strings that already exist in the array word1 and word2, return the shortest distance between these two words in the list.

Example 1:
Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "coding", word2 = "practice"
Output: 3

Example 2:
Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "coding"
Output: 1

Constraints:
1 <= wordsDict.length <= 3 * 10^4
1 <= wordsDict[i].length <= 10
wordsDict[i] consists of lowercase English letters.
word1 and word2 are in wordsDict.
word1 != word2

Algo: pass with 2 prev_pos
*/

class Solution {
public:
    int shortestDistance(const vector<string>& wordsDict, string_view word1, string_view word2) {
        int w1pos = -1;
        int w2pos = -1;
        int min_dist = INT_MAX;
        for (int i = 0; i < (int)wordsDict.size(); ++i) {
            if (wordsDict[i] == word1) {
                if (w2pos != -1) {
                    min_dist = min(min_dist, i - w2pos);
                }
                w1pos = i;
            } else if (wordsDict[i] == word2) {
                if (w1pos != -1) {
                    min_dist = min(min_dist, i - w1pos);
                }
                w2pos = i;
            }
        }
        return min_dist;
    }
};

"practice", "makes", "perfect", "coding", "makes"
                                           ^
w1pos = 1
w2pos = 3
min_dist = 1
makes
coding