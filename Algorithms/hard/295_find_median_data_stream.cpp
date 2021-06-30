/**
    295. Find Median from Data Stream
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.
- For example, for arr = [2,3,4], the median is 3.
- For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:
- MedianFinder() initializes the MedianFinder object.
- void addNum(int num) adds the integer num from the data stream to the data structure.
- double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

Example 1:
Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0

Constraints:
-10^5 <= num <= 10^5
There will be at least one element in the data structure before calling findMedian.
At most 5 * 10^4 calls will be made to addNum and findMedian.

Follow up:
If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?

Algo:
inserterd container
insert to container: < O(logN)
findMedian(): O(1) or O(logN)

Algo1: bf O(N)
inserted to sorted array: O(N)
find median in sorted array: O(1)

Algo2: 
c1: [x11 ... xn1] -- max heap
c2: [x12 ... xn2] -- min heap
xin < x12
len(c1) - len(c2) <= 1

insert:
x < xn1:
insert x to c1, 
if len(c1) - len(c2) > 1:
	pop xn1 from c1
	push xn1 to c2

findMedian:
	len(c1) == len(c2):
		(x1n + x21) / 2
	else:
		x1n

*/

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
		if (s.empty()) {
			f.push(num);
		} else {
			int min_value = s.top();
			if (num <= min_value) {
				f.push(num);
			} else {
				s.push(num);
			}
		}
		if (f.size() > s.size() && f.size() - s.size() > 1) {
			s.push(f.top());
			f.pop();
		} else if (s.size() > f.size()) {
			f.push(s.top());
			s.pop();
		}
    }
    
    double findMedian() {
        assert(f.size() > 0);
		if (f.size() == s.size()) {
			return (f.top() + s.top()) / 2.0;
		} else {
			return f.top();
		}
    }
	
private:
	priority_queue<int> f;
	priority_queue<int, vector<int>, greater<int>> s;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
 
 [1]
 [2, 3]
