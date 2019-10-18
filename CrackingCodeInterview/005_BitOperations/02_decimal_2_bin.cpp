/**
Given a (decimal - e.g. 3.72) number that is passed in as a string, 
print the binary representation. 
If the number can not be represented accurately in binary, print “ERROR”

d -> bin
d % 2 -> 1
d // 2
reverse

// fraction
0.1 -> 1/10 -> 
bin fraction -> to dec
0.1 -> 1/2 -> 0.5
0.01 -> 1/4 -> 0.25
0.11 -> 3/4 -> 0.75

m = 1
n = 1
for d:
    m /= 2
    n += d * m
    
// dec frac to bin
1/10 -> 
a1/2^1 + a2/2^2 + ai/2^i + a/2^n = Sum(ai * (1/2)^i)

a1 = int(frac * 2^1)
frac -= a1/(2)^1
a2 = int(frac * 2^2)
frac -= a2 / (2)^2

mult = 2
while frac > 1e-10:
    a = int(frac * mult)
    frac -= a / mult
    mult *= 2
return {a1..an}
*/

std::string int_to_binstr(int num) {
    std::string s;
    while (num) {
        s += (num % 2) ? '1' : '0';
        num /= 2;
    }   
    std::reverse(s.begin(), s.end());
    return s;
}

std::string bin_frac_to_dec(const std::string& bfrac) {
    double m = 1;
    double n = 1;
    for (char d : bfrac) {
        m /= 2;
        n += (d - '0') * m;
    }
    return to_string(n);
}

std::vector<int> dec_frac_to_bin(double frac) {
    vector<int> res;
    mult = 2;
    while (fabs(frac) > 1e-10) {
        int a = int(frac * mult);
        frac -= (double)a / mult;
        mult *= 2;
    }
    return res;
}

std::string real_to_bin(std::string num_str) {
    int num = stol(num_str);
    string res = int_to_binstr(num) + '.';
    double frac = stod(num_str) - num;
    auto frac_digits = dec_to_frac(frac);
    res.reserve(res.size() + frac_digits.size());
    for (int d : frac_digits) {
        res += char(d) + '0';
    }
    return res;    
}

