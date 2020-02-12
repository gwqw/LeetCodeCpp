/**
    401. Binary Watch
A binary watch has 4 LEDs on the top which represent the hours (0-11), 
and the 6 LEDs on the bottom represent the minutes (0-59).
Each LED represents a zero or one, with the least significant bit on the right.
For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, 
return all possible times the watch could represent.

Example:
Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]

Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".

Algo1: calc number of ones: 720 operations (12*60)
- go through all possible hours and mins and calculate ones
- if one_h + one_min == num: add to res

Algo2: use next_permutation


*/

class Solution {
public:
    vector<string> readBinaryWatch(int n) {
        if (n == 0) return {"0:00"};
        vector<string> res;
        for (int h = 0; h <= n && h <= 4; ++h) {
            int m = n - h;
            vector<int> hours;
            for (int i = 0; i < 12; ++i) {
                auto ones = count_ones(i);
                if (ones == h) hours.push_back(i);
            }
            vector<int> mins;
            for (int i = 0; i < 60; ++i) {
                auto ones = count_ones(i);
                if (ones == m) mins.push_back(i);
            }
            for (auto hour : hours) {
                for (auto minute: mins) {
                    res.push_back(format(hour, minute));
                }
            }
        }
        return res;
    }
private:
    int count_ones(int n) {
        int res = 0;
        while (n > 0) {
            n &= n-1;
            ++res;
        }
        return res;
    }
    
    string format(int hour, int minute) {
        stringstream ss;
        ss << hour << ':' << setw(2) << setfill('0') << minute;
        return ss.str();
    }
};

class Solution {
public:
    vector<string> readBinaryWatch(int n) {
        if (n == 0) return {"0:00"};
        vector<string> res;
        for (int h = 0; h < 12; ++h) {
            int h_o = count_ones(h);
            if (h_o > n) continue;
            for (int m = 0; m < 60; ++m) {
                int m_o = count_ones(m);
                if (m_o + h_o == n) {
                    res.push_back(format(h,m));
                }
            }
        }
        return res;
    }
private:
    static int count_ones(int n) {
        int res = 0;
        while (n > 0) {
            n &= n-1;
            ++res;
        }
        return res;
    }
    
    string format(int hour, int minute) {
        string res;
        res.reserve(5);
        res += to_string(hour) + ':';
        if (minute <= 9) {
            res.push_back('0');
        }
        res += to_string(minute);
        return res;
    }
};

class Solution {
public:
    Solution() {
        if (ones[1] == 0) {
            init();
        }
    }

    vector<string> readBinaryWatch(int n) {
        if (n == 0) return {"0:00"};
        vector<string> res;
        for (int h = 0; h < 12; ++h) {
            int h_o = ones[h];
            if (h_o > n) continue;
            for (int m = 0; m < 60; ++m) {
                int m_o = ones[m];
                if (m_o + h_o == n) {
                    res.push_back(format(h,m));
                }
            }
        }
        return res;
    }
private:
    int count_ones(int n) {
        int res = 0;
        while (n > 0) {
            n &= n-1;
            ++res;
        }
        return res;
    }
    
    string format(int hour, int minute) {
        string res;
        res.reserve(5);
        res += to_string(hour) + ':';
        if (minute <= 9) {
            res.push_back('0');
        }
        res += to_string(minute);
        return res;
    }
    
    static array<int, 60> ones;
    
    static void init() {
        for (int i = 0; i < 60; ++i) {
            ones[i] = count_ones(i);
        }
    }
};
array<int, 60> Solution::ones;


class Solution {
public:
    vector<string> readBinaryWatch(int n) {
        if (n == 0) return {"0:00"};
        vector<string> res;
        array<int, 10> bits;
        fill(bits.begin(), bits.end(), 0);
        for (int i = 10-n; i < 10; ++i) {
            bits[i] = 1;
        }
        do {
            int h = 
                bits[0] * 8 + 
                bits[1] * 4 +
                bits[2] * 2 +
                bits[3] * 1;
            int m = 
                bits[4] * 32 + 
                bits[5] * 16 +
                bits[6] * 8 +
                bits[7] * 4 +
                bits[8] * 2 +
                bits[9] * 1;
            if (h < 12 && m < 60) {
                res.push_back(format(h, m));
            }        
        } while (next_permutation(bits.begin(), bits.end()));
        return res;
    }
private:
   
    string format(int hour, int minute) {
        stringstream ss;
        ss << hour << ':' << setw(2) << setfill('0') << minute;
        return ss.str();
    }
};

/*
0
1
2
3
4
5
6
7
8
*/

