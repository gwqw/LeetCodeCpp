/**
    406. Queue Reconstruction by Height
Suppose you have a random list of people standing in a queue.
Each person is described by a pair of integers (h, k),
where h is the height of the person and k is the number of people in front of this person
who have a height greater than or equal to h. 
Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.
 
Example
Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

Ex1:
[[2,1], [2,0], [2,2]]

Algo: O(N^2 + NlogN) + O(1)
- sort vector: people with max height and with lower higher_people_count == hpc
- for all in vector:
    - take man:
    - insert_to_queue:
        hpc -> index to insert

Algo2: enhanced (use list): O(N*diffHeight + NLogN) + O(N)
- insert to list (remember current position)
- form vector from list
*/

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), 
            [](const auto& lhs, const auto& rhs){
                return (lhs[0] > rhs[0]) || 
                (lhs[0] == rhs[0] && lhs[1] < rhs[1]);
            }
        );
        vector<vector<int>> res;
        res.reserve(people.size());
        for (const auto& man : people) {
            res.insert(res.begin() + man[1], man);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), 
            [](const auto& lhs, const auto& rhs){
                return (lhs[0] > rhs[0]) || 
                (lhs[0] == rhs[0] && lhs[1] < rhs[1]);
            }
        );
        list<vector<int>> lst;
        auto it = lst.begin();
        int cur_pos = 0;
        for (auto& man : people) {
            auto pos = man[1];
            if (pos > cur_pos) {
                it = next(it, pos - cur_pos);
            } else if (pos < cur_pos) {
                it = next(lst.begin(), pos);
            }
            it = lst.insert(it, move(man));
            cur_pos = pos;
        }
        return {make_move_iterator(lst.begin()), make_move_iterator(lst.end())};
    }
};


