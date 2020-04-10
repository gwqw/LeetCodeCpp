/**
    Write a method to replace all spaces in a string with ‘%20’.
    Algo1:
    - copy char from 1 string to another
    - if " " then copy %20
    O(N) + O(N)
    Algo2:
    - find space:
    - inc string size on 2
    - shift to the right rest on 2
    - replace " " on "%20"
    O(N^2) + O(1)
    Algo3:
    - get spaces_cnt
    - inc string size
    - go from end:
        - if c != ' ': shift to the rigth on 2*sp_cnt
        - else: --sp_cnt, shift to the right on 2*sp_cnt and paste %20
    O(N) + O(1)
*/

#include <string>

using namespace std;

string replace_spaces(const string& s) {
    size_t spaces_cnt = 0;
    for (char c : s) {
        if (c == ' ') spaces_cnt++;
    }
    string res;
    res.reserve(s.size() + 2*spaces_cnt);
    for (auto c : s) {
        if (c != ' ') {
            res += c;
        } else {
            res += "%20";
        }
    }
    return res;
}

void replace_spaces2(string& s) {
    if (s.empty()) return;
    // get spaces count
    size_t spaces_cnt = 0;
    for (char c : s) {
        if (c == ' ') spaces_cnt++;
    }
    // resize
    size_t old_size = s.size();
    s.resize(old_size + 2*spaces_cnt);
    // shifting symbols from the end
    for (int i = old_size-1; i >= 0; --i) {
        if (s[i] != ' ') {
            s[i+2*spaces_cnt] = s[i];
        } else {
            --spaces_cnt;
            s[i+2*spaces_cnt  ] = '%';
            s[i+2*spaces_cnt+1] = '2';
            s[i+2*spaces_cnt+2] = '0';
        }
    }
}
