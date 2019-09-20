/**
    Assume you have a method isSubstring which checks if one word is a substring 
    of another. Given two strings, s1 and s2, write code to check if s2 is 
    a rotation of s1 using only one call to isSubstring 
    (i.e., “waterbottle” is a rotation of “erbottlewat”).
    
    Algo: check s1s2 and s2s1
        - check sizes
        - form s1s2 + s1s2 = s1s2s1s2
        - check if s2s1 in s1s2s1s2
*/

#include <string>

using namespace std;

bool isSubstring(const string& source, const string& substr);

bool isRotation(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) return false;
    string ss{s1 + s1};
    return isSubstring(ss, s2);
}
