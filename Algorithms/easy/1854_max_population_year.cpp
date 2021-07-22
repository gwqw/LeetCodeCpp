/**
    1854. Maximum Population Year
You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the birth and death years of the ith person.

The population of some year x is the number of people alive during that year. The ith person is counted in year x's population if x is in the inclusive range [birthi, deathi - 1]. Note that the person is not counted in the year that they die.

Return the earliest year with the maximum population.

Example 1:
Input: logs = [[1993,1999],[2000,2010]]
Output: 1993
Explanation: The maximum population is 1, and 1993 is the earliest year with this population.

Example 2:
Input: logs = [[1950,1961],[1960,1971],[1970,1981]]
Output: 1960
Explanation: 
The maximum population is 2, and it had happened in years 1960 and 1970.
The earlier year between them is 1960.

Constraints:
1 <= logs.length <= 100
1950 <= birthi < deathi <= 2050

Algo:
array of pair<year, +1born, -1death>
sort array
go through and calc num of people
*/

class Solution {
	using Record = pair<int, int>;
public:
    int maximumPopulation(const vector<vector<int>>& logs) {
        vector<Record> recs;
		recs.reserve(2*logs.size());
		for (size_t i = 0; i < logs.size(); ++i) {
			recs.emplace_back(logs[i][0], 1);
			recs.emplace_back(logs[i][1], -1);
		}
		sort(recs.begin(), recs.end());
		int cnt = 0;
		int max_cnt = 0;
		int max_year = 0;
		for (auto [year, s] : recs) {
			cnt += s;
			if (cnt > max_cnt) {
				max_cnt = cnt;
				max_year = year;
			}
		}
		return max_year;
    }
};