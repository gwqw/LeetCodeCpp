/**
    228. Summary Ranges
Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:
Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.

Example 2:
Input:  [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.

Algo:
- go through array a remember left:
- while cur - prev == 1:
    ++cur
- else:
    print range
    - update left
- print after end
*/

class Solution {
public:
    vector<string> summaryRanges(const vector<int>& a) {
        if (a.empty()) return {};
        vector<string> ans;
        int left = a[0];
        size_t li = 0;
        for (size_t i = 1; i < a.size(); ++i) {
            if (!canSubstruct(a[i], a[i-1]) || a[i] - a[i-1] != 1) {
                print(left, a[i-1], i - li, ans);
                li = i;
                left = a[i];
            }
        }
        print(left, a.back(), a.size() - li, ans);
        return ans;
    }
    
private:
    static void print(int from, int to, size_t count, vector<string>& ans) {
        if (count == 1) {
            ans.push_back(to_string(from));
        } else {
            ans.push_back(to_string(from) + "->" + to_string(to));
        }
    }
    
    static bool canSubstruct(int a, int b) {
        return !(
            (a >= 0 && b < 0 && a > INT_MAX + b) ||
            (a <= 0 && b >= 0 && a < INT_MIN + b)
            );
    }
};