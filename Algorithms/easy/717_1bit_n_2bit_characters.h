/**
    717. 1-bit and 2-bit Characters
We have two special characters. The first character can be represented by one bit 0. 
The second character can be represented by two bits (10 or 11).
Now given a string represented by several bits. 
Return whether the last character must be a one-bit character or not. 
The given string will always end with a zero.

Example 1:
Input: 
bits = [1, 0, 0]
Output: True
Explanation: 
The only way to decode it is two-bit character and one-bit character. 
So the last character is one-bit character.

Example 2:
Input: 
bits = [1, 1, 1, 0]
Output: False
Explanation: 
The only way to decode it is two-bit character and two-bit character. 
So the last character is NOT one-bit character.

Note:
1 <= len(bits) <= 1000.
bits[i] is always 0 or 1.

Algo: O(N) + O(1)
is_one = true
for i in v:
    is_one = v[i] == 0
    if (is_one) ++i
    ++i
return is_one

Algo: short scheme:
0111...110 - can determine what symb is last: 
if 11..1 is even: one_bit
else: not one
- find from behind 0
- get 1 size
- return size // 2

*/

class Solution {
public:
    bool isOneBitCharacter(const vector<int>& bits) {
        bool is_one = false;
        for (auto it = bits.begin(); it != bits.end(); ++it) {
            is_one = *it == 0;
            if (!is_one) ++it;
            assert(it != bits.end());
        }
        return is_one;
    }
};

class Solution {
public:
    bool isOneBitCharacter(const vector<int>& bits) {
        if (bits.size() == 1) return true;
        auto it = find(bits.rbegin()+1, bits.rend(), 0);
        int sze = int(it - bits.rbegin())-1;
        return sze % 2 == 0;
    }
};




