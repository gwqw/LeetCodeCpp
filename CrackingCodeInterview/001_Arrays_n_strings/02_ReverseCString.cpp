/**
    Write code to reverse a C-Style String. 
    (C-String means that “abcd” is represented as five characters, 
    including the null character.)
    
    Algo: 
    n = strlen(str)
    0 <-> n-1
    ...
    i <-> n-i-1
    O(N) + O(1)
    
    Examples: "", "a", "ab", "aa", "abc"
*/

#include <cstring>

using namespace std;

void reverse_str(char* str) {
    size_t n = strlen(str);
    for (size_t i = 0; i < n / 2; ++i) {
        swap(str[i], str[n-i-1]);
    }
}
