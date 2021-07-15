/**
    855. Exam Room
In an exam room, there are n seats in a single row, numbered 0, 1, 2, ..., n-1.

When a student enters the room, they must sit in the seat that maximizes the distance to the closest person.  If there are multiple such seats, they sit in the seat with the lowest number.  (Also, if no one is in the room, then the student sits at seat number 0.)

Return a class ExamRoom(int n) that exposes two functions: ExamRoom.seat() returning an int representing what seat the student sat in, and ExamRoom.leave(int p) representing that the student in seat number p now leaves the room.  It is guaranteed that any calls to ExamRoom.leave(p) have a student sitting in seat p.

Example 1:
Input: ["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]
Output: [null,0,9,4,2,null,5]
Explanation:
ExamRoom(10) -> null
seat() -> 0, no one is in the room, then the student sits at seat number 0.
seat() -> 9, the student sits at the last seat number 9.
seat() -> 4, the student sits at the last seat number 4.
seat() -> 2, the student sits at the last seat number 2.
leave(4) -> null
seat() -> 5, the student sits at the last seat number 5.

Note:
1 <= n <= 10^9
ExamRoom.seat() and ExamRoom.leave() will be called at most 10^4 times across all test cases.
Calls to ExamRoom.leave(p) are guaranteed to have a student currently sitting in seat number p.

Algo:
0..n-1
set<seat_num> with sorted order
leave:
	seat.erase(seat_num)
seat:
	if seat.empty():
		seat.insert(0)
		return 0
	s = 0
	md = 0
	if seat.begin() != 0:
		md = seat.begin()
	prev = seat.begin()
	for s in 1,seat:
		d = s - p# 1->0, s-p-1   000 -> 1, 0000->1 (n-1)/2 + 1
		if d > md:
			s = p + d
			md = d
		p = s
	d = n - last
	if d > md:
		s = last
*/

class ExamRoom {
public:
    ExamRoom(int n) 
		: n(n)
	{}
    
    int seat() {
        if (seats.empty()) {
			seats.insert(0);
			return 0;
		}
		int s = 0;
		int prev = *seats.begin();
		int md = prev;
		for (auto it = next(seats.begin()); it != seats.end(); ++it) {
			int d = *it - prev - 1;
			d = (d+1)/2;
			if (d > md) {
				md = d;
				s = prev + d;
			}
			prev = *it;
		}
		int d = n-1 - prev;
		if (d > md) {
			s = n-1;
		}
		seats.insert(s);
		return s;
    }
    
    void leave(int p) {
        seats.erase(p);
    }
private:
	int n = 0;
	set<int> seats;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
 
 
 n=10
 0 1 2 3 4 5 6 7 8 9
 1 0 1 0 0 0 0 0 0 1
 seats: 0 2 9
 0,9,4,2
 0,9,4,2,null,5