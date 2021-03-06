/**
621. Task Scheduler

Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. 
Tasks could be done in any order. Each task is done in one unit of time.
For each unit of time, the CPU could complete either one task or just be idle.
However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.
Return the least number of units of times that the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.

Example 2:
Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.

Example 3:
Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A

Constraints:
    1 <= task.length <= 104
    tasks[i] is upper-case English letter.
    The integer n is in the range [0, 100].
    
Algo: math solution
AAAABBBCC..., n
construct table: n rows, first row max count symbol
variant 1
A A A A
B B B B
C . .
variant 2
A A A A F
B B C D

2 variants: 
1) max_count of symb: mc -> (mc-1)*(n+1)+same_symbols
2) many other symbols: task.size()
answer: max((mc-1)*(n+1)+same_symbols, task.size())

*/

class Solution {
public:
    int leastInterval(const vector<char>& tasks, int n) {
        int mc = 0;
        unordered_map<char, int> dict;
        for (auto t : tasks) {
            ++dict[t];
            if (dict[t] > mc) mc = dict[t];
        }
        int same_symbols = 0;
        for (const auto& [t,count] : dict) {
            if (dict[t] == mc) ++same_symbols;
        }
        return max(
            (mc-1)*(n+1)+same_symbols,
            (int)tasks.size()
        );
    }
};

class Solution {
public:
    int leastInterval(const vector<char>& tasks, int n) {
        int mc = 0;
        array<int, 26> dict{};
        for (auto t : tasks) {
            ++dict[t-'A'];
            if (dict[t-'A'] > mc) mc = dict[t-'A'];
        }
        int same_symbols = 0;
        for (auto count : dict) {
            if (count == mc) ++same_symbols;
        }
        return max(
            (mc-1)*(n+1)+same_symbols,
            (int)tasks.size()
        );
    }
};

