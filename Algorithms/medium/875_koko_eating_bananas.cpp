/**
    875. Koko Eating Bananas
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30

Example 3:
Input: piles = [30,11,23,4,20], h = 6
Output: 23

Constraints:
1 <= piles.length <= 10^4
piles.length <= h <= 10^9
1 <= piles[i] <= 10^9

Algo1: naive: usual search
- take k = 1
- calc hi for every pile
- if sum(hi) <= h: return k
- else: continue

Algo: binary_search: O(log(PileSize) * PilesCount)
l = 1
r = 1e9
while l < r:
    m = l + r / 2
    calc sum(hi) for m => hm
    if hm > h:
        l = hm + 1
    else:
        r = hm
return l
*/

class Solution {
public:
    int minEatingSpeed(const vector<int>& piles, int h) {
        int l = 1;
        //int r = 1e9;
        int r = *max_element(piles.begin(), piles.end());
        while (l < r) {
            int m = l + (r - l) / 2;
            auto hm = calcTime(piles, m);
            if (hm > h) {
                l = m+1;
            } else {
                r = m;
            }
        }
        return l;
    }
    
private:
    int calcTime(const vector<int>& piles, int k) {
        int h = 0;
        for (int pile : piles) {
            h += pile % k == 0 ? pile / k : pile / k + 1;
        }
        return h;
    }
};

