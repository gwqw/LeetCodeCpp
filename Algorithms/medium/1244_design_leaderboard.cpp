/**
    1244. Design A Leaderboard
Design a Leaderboard class, which has 3 functions:
- addScore(playerId, score): Update the leaderboard by adding score to the given player's score. If there is no player with such id in the leaderboard, add him to the leaderboard with the given score.
- top(K): Return the score sum of the top K players.
- reset(playerId): Reset the score of the player with the given id to 0 (in other words erase it from the leaderboard). It is guaranteed that the player was added to the leaderboard before calling this function.
Initially, the leaderboard is empty.

Example 1:
Input: 
["Leaderboard","addScore","addScore","addScore","addScore","addScore","top","reset","reset","addScore","top"]
[[],[1,73],[2,56],[3,39],[4,51],[5,4],[1],[1],[2],[2,51],[3]]
Output: 
[null,null,null,null,null,null,73,null,null,null,141]
Explanation: 
Leaderboard leaderboard = new Leaderboard ();
leaderboard.addScore(1,73);   // leaderboard = [[1,73]];
leaderboard.addScore(2,56);   // leaderboard = [[1,73],[2,56]];
leaderboard.addScore(3,39);   // leaderboard = [[1,73],[2,56],[3,39]];
leaderboard.addScore(4,51);   // leaderboard = [[1,73],[2,56],[3,39],[4,51]];
leaderboard.addScore(5,4);    // leaderboard = [[1,73],[2,56],[3,39],[4,51],[5,4]];
leaderboard.top(1);           // returns 73;
leaderboard.reset(1);         // leaderboard = [[2,56],[3,39],[4,51],[5,4]];
leaderboard.reset(2);         // leaderboard = [[3,39],[4,51],[5,4]];
leaderboard.addScore(2,51);   // leaderboard = [[2,51],[3,39],[4,51],[5,4]];
leaderboard.top(3);           // returns 141 = 51 + 51 + 39;

Constraints:
1 <= playerId, K <= 10000
It's guaranteed that K is less than or equal to the current number of players.
1 <= score <= 100
There will be at most 1000 function calls.

Algo: O(S)
scores_list[score]->{id}
dict[id]->score
add(id, score): O(1)
	dict[id]=score
	scores[score].insert(id)

reset(id): O(1)
	score = dict[id]
	dict.erase(id)
	scores[score].erase(id)
		
top(k): O(S)
	for score reverse(scores):
		sum_score = 0
		score, cnt <- scores
		if cnt < k:
			k -= cnt
			sum_score += cnt*score
		else:
			sum_score += k*score
			return sum_score
	return sum_score
	
Algo: try binary indexed tree or 
*/

class Leaderboard {
public:
    Leaderboard() {}
    
    void addScore(int id, int score) {
        if (dict.count(id)) {
            int old_score = dict[id];
            --scores[old_score];
            if (scores[old_score] == 0) {
                scores.erase(old_score);
            }
        }
        dict[id] += score;
        score = dict[id];
		++scores[score];
    }
    
    int top(int k) {
        int sum_score = 0;
		for (auto it = scores.end(); it != scores.begin(); ) {
            --it;
            auto [s, cnt] = *it;
            if (cnt < k) {
				sum_score += cnt * s;
                k -= cnt;
			} else {
				sum_score += k*s;
				return sum_score;
			}
		}
		return sum_score;
    }
    
    void reset(int id) {
        int score = dict[id];
		dict.erase(id);
		--scores[score];
        if (scores[score] == 0) {
            scores.erase(score);
        }
    }
	
private:
	unordered_map<int, int> dict;
	map<int, int> scores;
};
/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
 