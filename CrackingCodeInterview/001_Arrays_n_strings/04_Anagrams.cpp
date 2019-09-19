/**
    Write a method to decide if two strings are anagrams or not.
    Examples: ab == ba, asd == ads, asda != ads
    Algo1:
    get statistic and compare them
    O(N1+N2), O(N1+N2)
    Algo2:
    sort and compare
    O(N1*logN1 + N2*logN2), O(1)
*/

#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, int> get_stats(const string& s) {
    unordered_map<char, int> res;
    for (char c : s) {
        ++res[c];
    }
    return res;    
}

bool is_anagram1(const string& s1, const string& s2) {
    auto st1 = get_stats(s1);
    auto st2 = get_stats(s2);
    return st1 == st2;
}

bool is_anagram2(string s1, string s2) {
    sort(begin(s1), end(s1));
    sort(begin(s2), end(s2));
    return s1 == s2;
}

bool is_anagram3(const string& s1, const string& s2) {
    auto st1 = get_stats(s1);
    for (char c : s2) {
        if (st1.count(c)) {
            --st1[c];
            if (st1[c] == 0) st1.erase(c);
        } else {
            return false;
        }
    }
    return st1.empty();
}