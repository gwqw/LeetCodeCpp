/**
Given an integer, print the next smallest and next largest number that have the 
same number of 1 bits in their binary representation.

00 -> 00, 00
10 -> 01, 100
11 -> 11, 101

Algo1:
    calc 1 nums
    if all 1: num is smallest
    go backward:
        calc 1 nums if the same -- stop
    go forward:
        calc 1 nums if the same -- stop


Algo2:
    0 -> 0, 0
    largest:
    find first 0 (from backward) and not the real first bit: 
    if found:                   10010101>0<_1_111111
        swap 0 with right 1:    10010101_1_>0<111111
    else:                               111111      110
        insert 0 in second position     1011111     1010
        
    smallest:
    find first 1 (from backward) it must not be first digit: 1010101>1<000
        if bit is not the last:         10>1<_0_0
            swap it with the right 0:   10_0_>1<0
        else:   111
        it is the smallest
*/

void print_bits(int num, std::ostream& out) {
  std::string s;
  while (num) {
    s += (num % 2) ? '1' : '0';
    num /= 2;
  }   
  std::reverse(s.begin(), s.end());
  out << s;
}

bool check_bit(int num, int pos) {
  return num & (1 << pos);
}

void set_bit(int& num, int pos) {
  num |= (1 << pos);
}

void unset_bit(int& num, int pos) {
  num &= !(1 << pos);
}

void switch_bit(int& num, int pos) {
  num ^= (1 << pos);
}

std::pair<int,int> get_next_ints(int num) {
    if (nums == 0) return make_pair(0,0);
    constexpr int MAX_POS = 31;
    
    int small = num;
    int large = num;
    
    //smallest
    int one_pos = 0;
    for (int pos = 0; pos < MAX_POS; ++pos) {
        if (check_bit(num, pos) && pos) {
            one_pos = pos;
            break;
        }
    }
    if (one_pos) {
        unset_bit(small, one_pos);
        one_pos--;
        set_bit(small, one_pos);
    }
    
    // largest
    int zero_pos = 0;
    for (int pos = 0; pos < MAX_POS; ++pos) {
        if (!check_bit(num,pos) && pos) {
            zero_pos = pos;
            break;
        }
    }
    if (one_pos && one_pos != MAX_POS-1) {
        set_bit(large, zero_pos);
        unset_bit(large, --zero_pos);
    } else if (one_pos ) {
        
    } else {
        unset_bit(large, zero_pos);
        set_bit(large, ++zero_pos);        
    }
    return make_pair(small, large);
}