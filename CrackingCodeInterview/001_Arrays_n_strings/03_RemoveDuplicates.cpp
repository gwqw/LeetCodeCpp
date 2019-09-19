/**
    Design an algorithm and write code to remove the duplicate characters in a string
    without using any additional buffer. NOTE: One or two additional variables are fine.
    An extra copy of the array is not.
    FOLLOW UP
    Write the test cases for this method.
    
    Algo:
    - go through string:
    - for every char check if there is a duplicate
    - swap duplicate with last
    - shrink last pos
    O(n^2)
    
    Tests:
    "", "a", "aa", "aaa", "aba"
*/

#include <cstring>

using namespace std;

void remove_duplicates(char* str) {
    size_t n = strlen(str);
    if (n < 2) return;
    char* end = str + n;
    for (char* c = str; c+1 != end; ++c) {
        char* d = c+1;
        while (d != end) {
            if (*c == *d) {
                *d = *--end;
            } else {
                ++d;
            }
        }
        if (c+1 == end) break;
    }
    *end = '\0';
}
