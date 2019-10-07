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

Algo:
    - first and last edges:
        min_r = max(abs(H0 - h0), abs(hb - Hb))
    - go through houses, while h_coord < next heater :
    - store fidx, lidx
    - r = (Hi+1 - H_i) / 2
    - d1 = lb(fidx, lidx, r)
    - d2 = ub(fidx, lidx, Hi+1 - r)
    - min_r = max(min_r, d1, d2)

Algo2:
    - sort arrays O(NlogN)
    - for every house bs closest heater and update max radius O(NlogN)
*/

class Solution {
public:
    int findRadius(const vector<int>& houses_, const vector<int>& heaters_) {
        std::vector<int> houses(houses_);
        std::vector<int> heaters(heaters_);
        if (houses.empty() || heaters.empty()) return 0;
        std::sort(begin(houses), end(houses));
        std::sort(begin(heaters), end(heaters));
        int md = 0;
        auto bit = heaters.begin();
        for (int house : houses) {
            auto it = upper_bound(bit, end(heaters), house);
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
                bit = it;
            }
        }
        return md;
    }
};

class Solution {
public:
    int findRadius(const vector<int>& houses_, const vector<int>& heaters_) {
        std::vector<int> houses(houses_);
        std::vector<int> heaters(heaters_);
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
