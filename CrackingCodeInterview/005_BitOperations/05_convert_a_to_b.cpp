/**
Write a function to determine the number of bits required to convert integer A to integer B.
Input: 31, 14: 11111 -> 01110
Output: 2

Algo1: check and compare every bits

Algo2: a = a xor b, count 1
*/

bool check_bit(int num, int pos) {
  return num & (1 << pos);
}

int get_conv_num(int a, int b) {
    MAX_INT_POS = 31;
    int cnt = 0;
    for (int i = 0; i < MAX_INT_POS; ++i) {
        if (check_bit(a,i) != check_bit(b,i)) {
            ++cnt;
        }
    }
    return cnt;
}

int get_conv_num(int a, int b) {
    int cnt = 0;
    a ^= b;
    for (; a; a = a >> 1) {
        if (a & 1) {
            ++cnt;
        }
    }
    return cnt;
}

