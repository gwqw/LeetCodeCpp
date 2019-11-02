/**
Write a program to swap odd and even bits in an integer with as few instructions as possible 
(e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, etc).

11 -> 11
01 -> 10
10 -> 01
00 -> 00

Algo:
take even bits:  & 1010101010 -> AAAAAAAA and shift right
take odd bits:   & 0101010101 -> 55555555 and shift left
a1 | a2

*/

int swap_bits(int a) {
    int evens = a & 0xAAAAAAAA;
    evens >>= 1;
    int odds  = a & 0x55555555;
    odds << 1;
    return even | odds;
}