/**
You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to set all bits between i and j in N equal to M (e.g., M becomes a substring of N located at i and starting at j).
EXAMPLE:
Input: N = 10000000000, M = 10101, i = 2, j = 6
Output: N = 10001010100

Algo1:
idx
for idx = 0 idx <=j-i:
  set(N[idx+i], M[idx])
return N

Algo2:
- make mask to zeo [i-j] bits
- & to zero [i-j] region
- shift m to make [i-j]000 mask
- set mask with |=

*/

int copy_num(int n, int m, int i, int j) {
  int zero_mask = ~((1 << (j-i+1)) - 1);
  n &= zero_mask;
  m <<= i;
  n |= m;
  return n;
}