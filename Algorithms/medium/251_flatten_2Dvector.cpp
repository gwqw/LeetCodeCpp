/**
    251. Flatten 2D Vector
Design an iterator to flatten a 2D vector. It should support the next and hasNext operations.
Implement the Vector2D class:
- Vector2D(int[][] vec) initializes the object with the 2D vector vec.
- next() returns the next element from the 2D vector and moves the pointer one step forward. You may assume that all the calls to next are valid.
- hasNext() returns true if there are still some elements in the vector, and false otherwise.

Example 1:
Input
["Vector2D", "next", "next", "next", "hasNext", "hasNext", "next", "hasNext"]
[[[[1, 2], [3], [4]]], [], [], [], [], [], [], []]
Output
[null, 1, 2, 3, true, true, 4, false]

Explanation
Vector2D vector2D = new Vector2D([[1, 2], [3], [4]]);
vector2D.next();    // return 1
vector2D.next();    // return 2
vector2D.next();    // return 3
vector2D.hasNext(); // return True
vector2D.hasNext(); // return True
vector2D.next();    // return 4
vector2D.hasNext(); // return False

Constraints:
0 <= vec.length <= 200
0 <= vec[i].length <= 500
-500 <= vec[i][j] <= 500
At most 10^5 calls will be made to next and hasNext.

Follow up: As an added challenge, try to code it using only iterators in C++ or iterators in Java.
*/

class Vector2D {
	using Iterator = vector<int>::iterator;
	using Iterator2D = vector<vector<int>>::iterator;
	
	template <typename Iter>
	struct IteratorRange {
		Iter b;
		Iter e;
		bool empty() const {
			return b == e;
		}
	};
	
public:
    Vector2D(vector<vector<int>>& vec) 
		: global_iter{vec.begin(), vec.end()}
	{
		searchNext();
	}
    
    int next() {
        int el = *local_iter.b;
		++local_iter.b;
		if (!local_iter.empty()) return el;
		++global_iter.b;
		searchNext();
		return el;
    }
    
    bool hasNext() {
        return !global_iter.empty() && !local_iter.empty();
    }
	
private:
	void searchNext() {
		while (!global_iter.empty()) {
			local_iter = IteratorRange<Iterator>{global_iter.b->begin(), global_iter.b->end()};
			if (!local_iter.empty()) break;
			++global_iter.b;
		}
	}
	
private:
	IteratorRange<Iterator2D> global_iter;
	IteratorRange<Iterator> local_iter;
};


/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
