/**
    292. Nim Game
You are playing the following Nim Game with your friend: 
There is a heap of stones on the table, 
each time one of you take turns to remove 1 to 3 stones. 
The one who removes the last stone will be the winner. 
You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. 
Write a function to determine whether you can win the game given the number of stones in the heap.

Example:
Input: 4
Output: false 
Explanation: If there are 4 stones in the heap, then you will never win the game;
             No matter 1, 2, or 3 stones you remove, the last stone will always be 
             removed by your friend.

Algo:
1 -> true   5 -> 4 -> true
2 -> true   6 -> 4 -> true
3 -> true   7 -> 4 -> true
4 -> false  8 -> ? -> false

- you can win if num % 4 != 0

*/

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
