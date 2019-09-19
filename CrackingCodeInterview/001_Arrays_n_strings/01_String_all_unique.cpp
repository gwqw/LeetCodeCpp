/**
    Implement an algorithm to determine if a string has all unique characters. 
    What if you can not use additional data structures?
    Variant1: use cache: unordered_set: O(N) + O(N)
    Variant2: O(N^2) + O(1)
    
    Examples: 1) "", 2) "a", 3) "ab", 4) "aa", 5) "aba"
*/

#include <string>
#include <unordered_set>

using namespace std;

bool all_unique1(const std::string& str) {
    unordered_set<char> cache;
    for (auto c : str) {
        if (cache.count(c)) {
            return false;
        } else {
            cache.insert(c);
        }
    }
    return true;
}

bool all_unique2(const std::string& str) {
    for (size_t i = 0; i+1 < str.size(); ++i) {
        for (size_t j = i+1; j < str.size(); ++j) {
            if (str[i] == str[j]) return false;
        }
    }
    return true;
}


