/**
    735. Asteroid Collision
We are given an array asteroids of integers representing asteroids in a row.
For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

Example 1:
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

Example 2:
Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.

Example 3:
Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

Example 4:
Input: asteroids = [-2,-1,1,2]
Output: [-2,-1,1,2]
Explanation: The -2 and -1 are moving left, while the 1 and 2 are moving right. Asteroids moving the same direction never meet, so no asteroids will meet each other.

Constraints:
2 <= asteroids.length <= 10^4
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0

Algo: 2 pass && stack
go to right:
    if a[i] > mh: mh = a[i]
    if a[i] < 0:
        if mh > -a[i]:
            destroyed.add[i]
        elif mh == -a[i]:
            destroyed.add(i)
            mh = 0
        else:
            mh = 0
go left:
    if a[i] < mh: mh = a[i]
    if a[i] > 0:
        if -mh > a[i]:
            destroyed.add(i)
        elif -mh == a[i]:
            destroyed.add(i)
            mh = 0
        else:
            mh = 0
create answer

Algo2: one stack
- put all values to stack while not collisions occurs
- remove all exploded asteroids
*/

class Solution {
public:
    vector<int> asteroidCollision(const vector<int>& a) {
        int mh = 0;
        vector<char> destroyed(a.size(), false);
        stack<int> maxs;
        // go to right
        for (size_t i = 0; i < a.size(); ++i) {
            if (a[i] > 0) {
                if (maxs.empty() || maxs.top() <= a[i]) {
                    maxs.push(a[i]);
                }
            } else if (a[i] < 0) {
                if (!maxs.empty() && maxs.top() > -a[i]) {
                    destroyed[i] = true;
                }
                else if (!maxs.empty() && maxs.top() < -a[i]) {
                    stack<int> new_stack;
                    swap(maxs, new_stack);
                }
                else if (!maxs.empty() && maxs.top() == -a[i]) {
                    destroyed[i] = true;
                    maxs.pop();
                }
            }
        }
        // go to left
        stack<int> mins;
        for (size_t i = a.size(); i-->0; ) {
            if (a[i] < 0) {
                if (mins.empty() || mins.top() >= a[i]) {
                    mins.push(a[i]);
                }
            } else if (a[i] > 0) {
                if (!mins.empty() && -mins.top() > a[i]) {
                    destroyed[i] = true;
                }
                else if (!mins.empty() && -mins.top() < a[i]) {
                    stack<int> new_stack;
                    swap(mins, new_stack);
                }
                else if (!mins.empty() && -mins.top() == a[i]) {
                    destroyed[i] = true;
                    mins.pop();
                }
            }
        }
        // create answer
        vector<int> ans;
        for (size_t i = 0; i < a.size(); ++i) {
            if (!destroyed[i]) {
                ans.push_back(a[i]);
            }
        }
        return ans;
    }
};