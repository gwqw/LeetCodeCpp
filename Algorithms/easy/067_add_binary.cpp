/**
Given two binary strings, return their sum (also a binary string).
The input strings are both non-empty and contains only characters 1 or 0.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

O(N) -- algo, O(1) -- memory

algo:
  swap strings, so first is maximal
  reverse strings
  for every symbol:
    convert symbols to int
    calculate sum and take into account the residue
    renew the residue
    update the result symbol to first string
  end of max string
  if residual add '1' to string
  reverse string
  return it
*/

class Solution {
public:
    string addBinary(string a, string b) {
      if (b.size() > a.size()) {swap(a, b);}
      int s = 0;
      reverse(a.begin(), a.end());
      reverse(b.begin(), b.end());
      for (size_t i = 0; i < a.size(); ++i) {
        int x = a[i] == '1' ? 1 : 0;
        int y = 0;
        if (i < b.size()) {
          y = b[i] == '1' ? 1 : 0;
        }
        int r = x + y + s;
        if (r <= 1) {s = 0;} else {s = 1;}
        r %= 2;
        a[i] = r > 0 ? '1' : '0';
      }
      if (s > 0) {
        a += '1';
      }
      reverse(a.begin(), a.end());
      return a;
    }
};

class Solution {
public:
    string addBinary(const string& a, const string& b) {
      string res;
      res.reserve(max(a.size(), b.size())+1);
      int s = 0;
      for (int i = (int)a.size()-1, j = (int)b.size()-1; i >= 0 || j >= 0; --i, --j) {
        int x = 0;
        if (i >= 0){
            x = a[i] == '1' ? 1 : 0;
        }
        int y = 0;
        if (j >= 0) {
          y = b[j] == '1' ? 1 : 0;
        }
        int r = x + y + s;
        s = r / 2;
        res.push_back(r % 2 == 0 ? '0' : '1');
      }
      if (s > 0) {
        res.push_back('1');
      }
      reverse(res.begin(), res.end());
      return res;
    }
};

