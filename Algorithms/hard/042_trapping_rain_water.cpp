/**
    42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.
Thanks Marcos for contributing this image!

Example:
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

Algo1: using maps
- make map: height -> set(pos)
- find 2 max: go through map
- calc water area between them
- remove all bars between them
- while we have bars:
    - find next max1
    - find closest max2
    - calc water area between them
    - remove all bars between them
*/

class Solution {
    using Map = multimap<int, size_t, greater<int>>;
    using Iterator = Map::iterator;
public:
    int trap(const vector<int>& h) {        
        if (h.size() <= 1) return 0;
        // create map
        Map h2pos;
        for (size_t i = 0; i < h.size(); ++i) {
            h2pos.emplace(h[i], i);
        }
        map<size_t, Iterator> used_pos{{h2pos.begin()->second, h2pos.begin()}};
        // calc water
        int ans = 0;
        for (auto it = next(h2pos.begin()); it != h2pos.end(); ++it) {
            auto jt = findClosest(it, used_pos);
            ans += calcArea(it->second, jt->second, h);
            removeBars(it->second, jt->second, h, h2pos);
            used_pos.emplace(it->second, it);
        }
        return ans;
    }
    
private:
    int calcArea(size_t from, size_t to, const vector<int>& h) {
        if (from > to) {
            swap(from, to);
        }
        int height = min(h[from], h[to]);
        int area = 0;
        for (size_t i = from+1; i < to; ++i) {
            area += height - h[i];
        }
        return area;
    }

    void removeBars(size_t from, size_t to, const vector<int>& h, Map& h2pos) {
        if (from > to) {
            swap(from, to);
        }
        for (size_t i = from+1; i < to; ++i) {
            auto [b, e] = h2pos.equal_range(h[i]);
            for (auto it = b; it != e; ++it) {
                if (it->second == i) {
                    h2pos.erase(it);
                    break;
                }
            }
        }
    }
    
    Iterator findClosest(Iterator target, map<size_t, Iterator>& used_pos) {
        auto it = used_pos.lower_bound(target->second);
        if (it == used_pos.end()) {
            return prev(used_pos.end())->second;
        } else if (it == used_pos.begin()) {
            return used_pos.begin()->second;
        } else {
            size_t i = it->first >= target->second ? it->first - target->second : target->second - it->first;
            auto jt = prev(it);
            size_t j = jt->first >= target->second ? jt->first - target->second : target->second - jt->first;
            return i <= j ? it->second : jt->second;
        }
    }
};

// cout << jt->first << " " << it->first << ", pos= " << jt->second << " " << it->second << ", area= " << new_area << endl;