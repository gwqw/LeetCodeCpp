/**
    277. Find the Celebrity
Suppose you are at a party with n people (labeled from 0 to n - 1), and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know him/her, but he/she does not know any of them.
Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information about whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).
You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int findCelebrity(n). There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return -1.

Example 1:
Input: graph = [[1,1,0],[0,1,0],[1,1,1]]
Output: 1
Explanation: There are three persons labeled with 0, 1 and 2. graph[i][j] = 1 means person i knows person j, otherwise graph[i][j] = 0 means person i does not know person j. The celebrity is the person labeled as 1 because both 0 and 2 know him but 1 does not know anybody.

Example 2:
Input: graph = [[1,0,1],[1,1,0],[0,1,1]]
Output: -1
Explanation: There is no celebrity.

Constraints:
n == graph.length
n == graph[i].length
2 <= n <= 100
graph[i][j] is 0 or 1.
graph[i][i] == 1

Follow up: If the maximum number of allowed calls to the API knows is 3 * n, could you find a solution without exceeding the maximum number of calls?

1->2-|
L->0<

graph with only 1 leaf (celebrity), and all nodes -> leaf
Algo1: bf:
canbe(n, true)
for (cur = 0; cur < n; ++cur):
    for i in (0, n):
        if i == cur: continue
        if knows(cur, i):
            canbe[cur] = false
        else
            canbe[i] = false
return position of true in canbe

Algo2: check only candidates:
canbe(n, true)
cur = 0
while cur < n:
    for i in (cur+1, n):
        if knows(cur, i):
            canbe[cur] = false
            cur = i
            break
        else
            canbe[i] = false
        if i == n:
            if (checkCur()): return cur
            cur = getNextCur() # is not needed
return -1

Algo3: same as Algo2, but simplified:
cur = 0
while cur < n:
    for i in (cur+1, n):
        if knows(cur, i):
            cur = i
            break
        if i == n:
            if (checkCur()): 
                return cur
            else:
                return -1
return -1

*/

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        vector<char> canbe(n, true);
        for (int cur = 0; cur < n; ++cur) {
            for (int i = 0; i < n; ++i) {
                if (i == cur) continue;
                if (knows(cur, i)) {
                    canbe[cur] = false;
                } else {
                    canbe[i] = false;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (canbe[i]) return i;
        }
        return -1;
    }
};

/*
canbe(n, true)
cur = 0
while cur < n:
    for i in (cur+1, n):
        if knows(cur, i):
            canbe[cur] = false
            cur = i
            break
        else
            canbe[i] = false
        if i == n:
            if (checkCur()): return cur
            cur = getNextCur()
return -1
*/

class Solution {
public:
    int findCelebrity(int n) {
        vector<char> canbe(n, true);
        int cur = 0;
        while (cur < n) {
            int i = cur + 1;
            for (; i < n; ++i) {
                if (knows(cur, i)) {
                    canbe[cur] = false;
                    cur = i;
                    break;
                } else {
                    canbe[i] = false;
                }
            }
            if (i == n) {
                if (checkCur(cur, canbe, n)) return cur;
                cur = getNextCur(cur, canbe);
            }
        }
        return -1;
    }
    
private:
    bool checkCur(int cur, vector<char>& canbe, int n) {
        for (int i = 0; i < cur; ++i) {
            if (knows(cur, i)) {
                canbe[cur] = false;
                return false;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!knows(i, cur)) return false;
        }
        return true;
    }
    
    int getNextCur(int cur, const vector<char>& canbe) {
        for (cur = cur + 1; cur < (int)canbe.size(); ++cur) {
            if (canbe[cur]) return cur;
        }
        return (int)canbe.size();
    }
};

class Solution {
public:
    int findCelebrity(int n) {
        int cur = 0;
        while (cur < n) {
            int i = cur + 1;
            for (; i < n; ++i) {
                if (knows(cur, i)) {
                    cur = i;
                    break;
                }
            }
            if (i == n) break;
        }
        return checkCur(cur, n) ? cur : -1;
    }
    
private:
    bool checkCur(int cur, int n) {
        for (int i = 0; i < cur; ++i) {
            if (knows(cur, i)) {
                return false;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i == cur) continue;
            if (!knows(i, cur)) return false;
        }
        return true;
    }
};

[[1,1,0],[0,1,0],[1,1,1]]
[[1,0,1],[1,1,0],[0,1,1]]
[[1,0],[0,1]]
[[1,1],[1,1]]