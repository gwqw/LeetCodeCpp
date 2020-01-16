/**
    475 Heaters
Winter is coming! Your first job during the contest is to design a standard heater 
with fixed warm radius to warm all the houses.
Now, you are given positions of houses and heaters on a horizontal line, 
find out minimum radius of heaters so that all houses could be covered by those heaters.
So, your input will be the positions of houses and heaters seperately, 
and your expected output will be the minimum radius standard of heaters.

Note:
Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.

Example 1:
Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, 
and if we use the radius 1 standard, then all the houses can be warmed.

Example 2:
Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. 
We need to use radius 1 standard, then all the houses can be warmed.

Algo1: sort heaters and for every house use bin_search: O(NlogN) + O(1)
- sort heaters O(NlogN)
- for every house bs closest heater and update max radius O(NlogN)
    
Algo2: sort both for every house find closest heater O(NlogN) 
- sort houses, heaters 
- closest heater = heater[0]
- for every house:
    - while (heater < house):
        ++heater
    - min_dist = min(heater-house, prev(heater-house));
    radius = max(min_dist, radius)
 
*/

class Solution {
public:
    int findRadius(const vector<int>& houses, vector<int>& heaters) {
        if (houses.empty() || heaters.empty()) return 0;
        std::sort(begin(heaters), end(heaters));
        int md = 0;
        for (int house : houses) {
            auto it = upper_bound(heaters.begin(), end(heaters), house);
            // H .. h
            if (it == end(heaters)) {
                --it;
                md = std::max(md, house - *it);
        	} else if (it == begin(heaters)) {
			// h .. H
                md = std::max(md, *it - house);
            } else {
			// Hp .. h .. H
				md = std::max(md, std::min(*it - house, house - *prev(it)));
            }
        }
        return md;
    }
};

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        std::sort(begin(heaters), end(heaters));
        std::sort(begin(houses), end(houses));
        int md = 0;
        int cur_hidx = 0;
        for (int house : houses) {
            while (cur_hidx+1 != heaters.size() && heaters[cur_hidx] < house) {
                ++cur_hidx;
            }
            int min_dst = abs(heaters[cur_hidx] - house);
            if (cur_hidx > 0) {
                min_dst = min(min_dst, house - heaters[cur_hidx-1]);
            }
            md = max(md, min_dst);
        }
        return md;
    }
};

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        std::sort(begin(heaters), end(heaters));
        std::sort(begin(houses), end(houses));
        int md = 0;
        int cur_hidx = 0;
        for (int house : houses) {
            while (cur_hidx+1 != heaters.size() && heaters[cur_hidx+1] < house) {
                ++cur_hidx;
            }
            int min_dst = abs(house - heaters[cur_hidx]);
            if (cur_hidx+1 != heaters.size()) {
                min_dst = min(min_dst, abs(heaters[cur_hidx+1] - house));
            }
            md = max(md, min_dst);
        }
        return md;
    }
};
