/**
28. Implement strStr()
Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

Clarification:
What should we return when needle is an empty string?
This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string.
This is consistent to C's strstr() and Java's indexOf().
*/

/**
Algo: O(N*M) + O(1)
s1, s2
if s1.empty() || s2.size() > s1.size() return -1
if s2.empty(): return 0

for i (0, s1.size() - s2.size() + 1):
  res = true
  for j=0 to s2.size():
    if s1[i+j] != s2[j]:
      res = false
      break
  if res:
    return i
return false


Algo2: O(N) + O(1) use poly-hash
- Rabin–Karp algorithm
/**
 * m = sub.size()
 * H0 = (a0 + a1*x + a2*x^2 + .. + am-1*x^m-1) % P
 * H1 = (a1 + a2*x + a3*x^2 + .. + am-1*x^m-2 + am*x^m-1) % P
 * H0 = (H1 - am*x^m-1) * x + a0
 * 
 * x = 199
 * P = 1000000007
 */
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
      if (needle.empty()) return 0;
      if (haystack.empty() || needle.size() > haystack.size()) return -1;      
      
      for (int i = 0; i < haystack.size() - needle.size() + 1; ++i) {
        bool res = true;
        for (int j = 0; j < needle.size(); ++j) {
          if (haystack[i+j] != needle[j]) {
            res = false;
            break;
          }
        }
        if (res) {
          return i;
        }
      }
      
      return -1;
    }
};
class Solution {
public:
    int strStr(const string& str, const string& substr) {
        if (substr.empty()) {return 0;}
        if (substr.size() > str.size()) {return -1;}
        for (size_t i = 0; i <= str.size() - substr.size(); ++i) {
            if (equal(str, i, substr)) return i;
        }
        return -1;
    }
    
private:
    int equal(const string& s, size_t start, const string& substr) {
        for (size_t i = 0; i < substr.size(); ++i) {
            if (s[start+i] != substr[i]) return false;
        }
        return true;
    }
};

class Solution {
public:
    int strStr(const string& str, const string& substr) {
        if (substr.empty()) {return 0;}
        if (substr.size() > str.size()) {return -1;}
        size_t m = substr.size();
        const auto h1 = getHash(substr, 0, m);
        auto h0 = getHash(str, str.size() - substr.size(), m);
        int last_found = -1;
        if (h1 == h0) last_found = str.size() - substr.size();
        size_t xm1 = modPow(H, m-1);
        for (size_t i = str.size() - substr.size(); i > 0; --i) {
            size_t xm = str[i+m-1] * xm1 % P;
            h0 = h0 >= xm ? h0 - xm : P + h0 - xm;
            h0 = (
                h0 * H + str[i-1]
                ) % P;
            if (h1 == h0) last_found = i-1;
        }
        return last_found;
    }
    
private:
    static constexpr size_t P = 1000000007;
    static constexpr size_t H = 37;

    size_t getHash(const string& s, size_t pos, size_t m) {
        size_t r = 0;
        size_t x = 1;
        for (size_t i = pos; i < pos+m; ++i) {
            r += (s[i] * x) % P;
            x *= H;
            x %= P;
        }
        return r % P;
    }
    
    static size_t modPow(size_t value, size_t power) {
        size_t res = 1;
        for (size_t i = 0; i < power; ++i) {
            res *= value;
            res %= P;
        }
        return res % P;
    }
};


