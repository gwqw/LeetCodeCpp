/**
    1353. Maximum Number of Events That Can Be Attended
Given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. Notice that you can only attend one event at any time d.

Return the maximum number of events you can attend.

Example 1:
Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.

Example 2:
Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4

Example 3:
Input: events = [[1,4],[4,4],[2,2],[3,4],[1,1]]
Output: 4

Example 4:
Input: events = [[1,100000]]
Output: 1

Example 5:
Input: events = [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]
Output: 7

Constraints:
1 <= events.length <= 10^5
events[i].length == 2
1 <= startDayi <= endDayi <= 10^5

[000]   1
 [00]   2
  [0]   3
 [000]  4 
  [000] 5 
 ^
 
[00000]
[00000]
   [0]
   [00]
 ^
Algo: sort by begins and ends and use max_heap O(NlogN)
make list [{interval, idx}]
sort list by begin and end
i = 0 # not taken
while i < tasks.size() || !pq.empty():
    if pq.empty():
        cur_time = max(cur_time, tasks[i].start_time
    while tasks[i].start_time <= cur_time:
        pq.push(tasks[i++])
    while pq.top().end_time < cur_time:
        pq.pop()
    if pq.empty(): continue
    task = pq.pop()
    res.push(task.idx)
    cur_time += 1

*/

class Solution {
    using Event = vector<int>;
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        auto cmp = [](const Event& lhs, const Event& rhs) {
            return lhs[1] > rhs[1] || 
                lhs[1] == rhs[1] && lhs[0] > rhs[0];
        };
        priority_queue<Event, vector<Event>, decltype(cmp)> pq(cmp);
        size_t idx = 0;
        int cur_time = events[0][0];
        int cnt = 0;
        while (idx < events.size() || !pq.empty()) {
            if (pq.empty()) {
                cur_time = max(cur_time, events[idx][0]);
            }
            // remove old
            while (!pq.empty() && pq.top()[1] < cur_time) {
                pq.pop();
            }
            // add new
            while (idx < events.size() && events[idx][0] <= cur_time) {
                pq.push(move(events[idx++]));
            }
            // treat event (task)
            if (!pq.empty()) {
                auto event = move(pq.top());
                pq.pop();
                ++cnt;
                ++cur_time;
            }
        }
        return cnt;
    }
};




