/**
    Write a method to replace all spaces in a string with ‘%20’.
    Algo:
    - find space:
    - inc string size on 2
    - shift to the right rest on 2
    - replace " " on "%20"
    O(N^2) + O(1)
*/

#include <string>

using namespace std;

string replace_spaces(const string& s) {
    size_t spaces_cnt = 0;
    for (char c : s) {
        if (c == ' ') spaces_cnt++;
    }
    string res(s.size() + spzces_cnt);
}