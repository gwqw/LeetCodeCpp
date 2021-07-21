/**
    1604. Alert Using Same Key-Card Three or More Times in a One Hour Period
LeetCode company workers use key-cards to unlock office doors. Each time a worker uses their key-card, the security system saves the worker's name and the time when it was used. The system emits an alert if any worker uses the key-card three or more times in a one-hour period.

You are given a list of strings keyName and keyTime where [keyName[i], keyTime[i]] corresponds to a person's name and the time when their key-card was used in a single day.

Access times are given in the 24-hour time format "HH:MM", such as "23:51" and "09:49".

Return a list of unique worker names who received an alert for frequent keycard use. Sort the names in ascending order alphabetically.

Notice that "10:00" - "11:00" is considered to be within a one-hour period, while "22:51" - "23:52" is not considered to be within a one-hour period.

Example 1:
Input: keyName = ["daniel","daniel","daniel","luis","luis","luis","luis"], keyTime = ["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]
Output: ["daniel"]
Explanation: "daniel" used the keycard 3 times in a one-hour period ("10:00","10:40", "11:00").

Example 2:
Input: keyName = ["alice","alice","alice","bob","bob","bob","bob"], keyTime = ["12:01","12:00","18:00","21:00","21:20","21:30","23:00"]
Output: ["bob"]
Explanation: "bob" used the keycard 3 times in a one-hour period ("21:00","21:20", "21:30").

Example 3:
Input: keyName = ["john","john","john"], keyTime = ["23:58","23:59","00:01"]
Output: []

Example 4:
Input: keyName = ["leslie","leslie","leslie","clare","clare","clare","clare"], keyTime = ["13:00","13:20","14:00","18:00","18:51","19:30","19:49"]
Output: ["clare","leslie"]
 
Constraints:
1 <= keyName.length, keyTime.length <= 105
keyName.length == keyTime.length
keyTime[i] is in the format "HH:MM".
[keyName[i], keyTime[i]] is unique.
1 <= keyName[i].length <= 10
keyName[i] contains only lowercase English letters.

Algo: sliding window
dict[name] -> [times]
for u, times:
	sort times 
	if times.size() < 3: continue
	sliding window with size = 3
	if sw[i+2] - sw[i] <= 60: 
		res.push_back(user)
		continue
	++i
*/

class Solution {
public:
    vector<string> alertNames(const vector<string>& keyName, const vector<string>& keyTime) {
        auto dict = makeDict(keyName, keyTime);
		vector<string> res;
		for (auto& [user, times] : dict) {
			if (times.size() < 3) continue;
			sort(times.begin(), times.end());
			for (size_t i = 0; i+2 < times.size(); ++i) {
				if (times[i+2] - times[i] <= 60) {
					res.push_back(user);
					break;
				}
			}
		}
		sort(res.begin(), res.end());
		return res;
    }
	
private:
	unordered_map<string, vector<int>> makeDict(const vector<string>& keyName, const vector<string>& keyTime) {
		unordered_map<string, vector<int>> dict;
		for (size_t i = 0; i < keyName.size(); ++i) {
			dict[keyName[i]].push_back(parseTime(keyTime[i]));
		}
		return dict;
	}
	
	int parseTime(const string& time) {
		int h = time[0]*10 + time[1];
		int m = time[3]*10 + time[4];
		return h*60 + m;
	}
};