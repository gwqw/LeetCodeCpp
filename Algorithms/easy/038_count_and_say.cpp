/**
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:
Input: 1
Output: "1"

Example 2:
Input: 4
Output: "1211"

algo:
out_v = {1}
for n in (1, n):
  value = 0
  cnt = 0
  v = out_v
  out_v = {}
  for n in v:
    if value == n:
      cnt++
    else:
      out_v.push_back(value)
      out_v.push_back(cnt)
      value = n
      cnt = 1
  out_v.push_back(value)
  out_v.push_back(cnt)
return string(out_v)
*/

class Solution {
public:
    string countAndSay(int n) {
      vector<int> out_v = {1};
      for (int i = 1; i < n; ++i) {
        int value = 0;
        int cnt = 0;
        vector<int> = out_v;
        out_v.clear();
        for (int j : v) {
          if (value == j) {
            cnt++;
          } else {
            if (value) {
              out_v.push_back(cnt);
              out_v.push_back(value);              
            }
            value = j;
            cnt = 1;
          }
        }
        out_v.push_back(cnt);
        out_v.push_back(value);        
      }
      string res;
      for (int j : out_v) {
        res += to_string(j);
      }
      return res;
    }
};