/**
    949. Largest Time for Given Digits
Given an array of 4 digits, return the largest 24 hour time that can be made.
The smallest 24 hour time is 00:00, and the largest is 23:59. 
Starting from 00:00, a time is larger if more time has elapsed since midnight.
Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

Example 1:
Input: [1,2,3,4]
Output: "23:41"

Example 2:
Input: [5,5,5,5]
Output: ""

Note:
A.length == 4
0 <= A[i] <= 9
*/

class Solution {
public:
    string largestTimeFromDigits(vector<int>& a) {
        assert(a.size() == 4);
        auto h = getMaxHour(a);
        if (h < 0) return "";
        return asStr(a);
    }

private:
    int getMaxHour(vector<int>& a) {
        if (auto it = find(a.begin(), a.end(), 2); it != a.end()) {
            swap(*it, *a.begin());
            int h = findGoodHour(a, 3);
            if (h >= 0) return h;
        }
        if (auto it = find(a.begin(), a.end(), 1); it != a.end()) {
            swap(*it, *a.begin());
            int h = findGoodHour(a, 9);
            if (h >= 0) return h;
        }
        if (auto it = find(a.begin(), a.end(), 0); it != a.end()) {
            swap(*it, *a.begin());
            int h = findGoodHour(a, 9);
            if (h >= 0) return h;
        }
        return -1;
    }

    int findGoodHour(vector<int>& a, int max_init) {
        while (max_init >= 0) {
            size_t max_pos = 0;
            int max_value = -1;
            for (size_t i = 1; i < a.size(); ++i) {
                if (a[i] <= max_init && a[i] > max_value) {
                    max_pos = i;
                    max_value = a[i];
                    if (max_value == max_init) break;
                }
            }
            max_init = max_value;
            if (max_pos > 0) {
                swap(a[1], a[max_pos]);
                if (getMaxMin(a) >= 0) {
                    return a[0]*10+a[1];
                } else {
                    --max_init;
                }
            }
        }
        return -1;
    }

    int getMaxMin(vector<int>& a) {
        size_t max_pos = a.size();
        int max_value = -1;
        for (size_t i = 2; i < a.size(); ++i) {
            if (a[i] <= 5 && a[i] > max_value) {
                max_pos = i;
                max_value = a[i];
                if (max_value == 5) break;
            }
        }
        if (max_pos != a.size()) {
            swap(a[max_pos], a[2]);
            return a[2]*10+a[3];
        } else {
            return -1;
        }
    }

    string asStr(vector<int>& a) {
        string res(5, '\0');
        res[0] = a[0] + '0';
        res[1] = a[1] + '0';
        res[2] = ':';
        res[3] = a[2] + '0';
        res[4] = a[3] + '0';
        return res;
    }

};
