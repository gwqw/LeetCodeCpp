/**
  base bit operations
  
*/

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

void print_bits(int num, std::ostream& out) {
  std::string s;
  while (num) {
    if (num % 2) {
      s += '1';
    } else {
      s += '0';
    }
    num /= 2;
  }   
  std::reverse(s.begin(), s.end());
  out << s;
}

