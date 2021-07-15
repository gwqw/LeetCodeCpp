/**
    849. Maximize Distance to Closest Person
In a row of seats, 1 represents a person sitting in that seat, 
and 0 represents that the seat is empty. 
There is at least one empty seat, and at least one person sitting.
Alex wants to sit in the seat such that the distance between him and 
the closest person to him is maximized. 
Return that maximum distance to closest person.

Example 1:
Input: [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.

Example 2:
Input: [1,0,0,0]
Output: 3
Explanation: 
If Alex sits in the last seat, the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.

Note:
1 <= seats.length <= 20000
seats contains only 0s or 1s, at least one 0, and at least one 1.

Algo: 1 iterator O(N) + O(1)
- it = find(0)
- go through array and count 0 and save in start and size
- if edge: size = 2*size-1 (size != 0)
- update_max 
*/

class Solution {
public:
    int maxDistToClosest(const vector<int>& seats) {
        pair<int, int> max_zeros{0,0}, cur{-1,0};
        for (auto it = find(seats.begin(), seats.end(), 0); it != seats.end(); ++it) {
            if (*it == 0) {
                if (cur.first == -1) {cur.first = it - seats.begin();}
                ++cur.second;
            } else {
                if (cur.first == 0) cur.second = 2*cur.second-1;
                if (cur.second > max_zeros.second) max_zeros = cur;
                cur.first = -1;
                cur.second = 0;
            }
        }
        if (cur.second != 0) cur.second = 2*cur.second-1;
        if (cur.second > max_zeros.second) max_zeros = cur;
        return (max_zeros.second + 1) / 2;
    }
};
class Solution {
public:
    int maxDistToClosest(const vector<int>& seats) {
        pair<decltype(seats.begin()), int> max_zeros{seats.end(),0}, cur{seats.end(),0};
        for (auto it = find(seats.begin(), seats.end(), 0); it != seats.end(); ++it) {
            if (*it == 0) {
                if (cur.first == seats.end()) {cur.first = it;}
                ++cur.second;
            } else {
                if (cur.first == seats.begin()) cur.second = 2*cur.second-1;
                if (cur.second > max_zeros.second) max_zeros = cur;
                cur.first = seats.end();
                cur.second = 0;
            }
        }
        if (cur.second != 0) cur.second = 2*cur.second-1;
        if (cur.second > max_zeros.second) max_zeros = cur;
        return (max_zeros.second + 1) / 2;
    }
};
class Solution {
public:
    int maxDistToClosest(const vector<int>& seats) {
        int zc = 0;
        auto it = find(seats.begin(), seats.end(), 1);
        int covid_dist = it - seats.begin();
        for (auto n : seats) {
            if (n == 0) {
                ++zc;
            } else if (zc != 0) {
                covid_dist = max(covid_dist, (zc-1) / 2 + 1);
                zc = 0;
            }
        }
        if (zc != 0) {
            covid_dist = max(covid_dist, zc);
        }
        return covid_dist;
    }
};

/*
    1 0 0 0 1 0 1
            ^     
      f =1, s = 3
      mf = 1, ms = 3
      ans = 1 + 3/2 = 2
      
[1,0,0,0,1,0,1]
[1,0,0,0]
[0,1]
[1,1,1,0,1,1]
[1,0,0,0,0,1,0,1]
[0,0,1]
[0,1,1,1,0,0,1,0,0]
*/

