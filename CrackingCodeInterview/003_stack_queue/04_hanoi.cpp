/**
In the classic problem of the Towers of Hanoi, you have 3 rods and N disks of different sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending order of size from top to bottom (e.g., each disk sits on top of an even larger one). You have the following constraints:
(A) Only one disk can be moved at a time.
(B) A disk is slid off the top of one rod onto the next rod.
(C) A disk can only be placed on top of a larger disk.
Write a program to move the disks from the first rod to the last using Stacks.

Algo recursive:
1
2
3
4
--  --  --

hanoi(rod1, rod2, rod3, N):
    if N == 1:
        disc = rod1.get_disk()
        rod2.add_disk(disc)
        return
    hanoi(rod1, rod3, rod2, N-1)
    rod2.add(rod1.pop())
    hanoi(rod3, rod2, rod1, N-1)
*/

#include <stack>

using namespace std;

using Rod = stack<int>;

void hanoi(Rod& rod1, Rod& rod2, Rod& rod3, size_t n) {
    // TODO: check 0
    // recursion exit
    if (n == 1) {
        rod2.push(rod1.top());
        rod1.pop();
        return;
    }
    
    // move N-1 on 3-rd
    hanoi(rod1, rod3, rod2, n-1);
    // move largest on 2-nd
    rod2.push(rod1.top());
    rod1.pop();
    // move N-1 from 3-rd on 2-nd
    hanoi(rod3, rod2, rod1, n-1);
}