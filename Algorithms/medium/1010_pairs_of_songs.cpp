/**
    1010. Pairs of Songs With Total Durations Divisible by 60
You are given a list of songs where the ith song has a duration of time[i] seconds.
Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.

Example 1:
Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60

Example 2:
Input: time = [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.

Constraints:
1 <= time.length <= 6 * 10^4
1 <= time[i] <= 500

Algo: counter dict of residuals: O(N), O(N)mem
dict[resid] -> cnt
for r, cnt:
	if r == 0:
		Cn2 = n! / (n-2)! / 2 = n(n-1)/2
	else if 60 - r in dict:
		cnt1 * cnt2
*/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> dict;
		for (int t : time) {
			t %= 60;
			++dict[t];
		}
		int res = 0;
		unordered_set<int> was;
		for (auto [t, cnt] : dict) {
			if (t == 0 || t == 30) {
				res += cnt * (cnt - 1) / 2;
			} else if (!was.count(t) && dict.count(60 - t)) {
				int cnt2 = dict[60 - t];
				res += cnt * cnt2;
				was.insert(60 - t);
			}
		}
		return res;
    }
};
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        array<int,60> dict(60);
		for (int t : time) {
			t %= 60;
			++dict[t];
		}
		int res = 0;
		for (size_t t = 0; t < dict.size(); ++t) {
            int cnt = dict[t];
            if (cnt < 1) continue;
			if (t == 0 || t == 30) {
				res += cnt * (cnt - 1) / 2;
			} else if (dict[t] > 0 && dict[60 - t] > 0) {
				int cnt2 = dict[60 - t];
				res += cnt * cnt2;
				dict[60 - t] = -1;
			}
		}
		return res;
    }
};


[30,20,150,100,40]
[30 20 30 40 40]
d: 20:1, 30:2, 40:2
r: 2+1
w: 40
[60 60 60]
d: 0:3 -> 3