/**
    170. Two Sum III - Data structure design
Design a data structure that accepts a stream of integers and checks if it has a pair of integers that sum up to a particular value.
Implement the TwoSum class:
- TwoSum() Initializes the TwoSum object, with an empty array initially.
- void add(int number) Adds number to the data structure.
- boolean find(int value) Returns true if there exists any pair of numbers whose sum is equal to value, otherwise, it returns false.

Example 1:
Input
["TwoSum", "add", "add", "add", "find", "find"]
[[], [1], [3], [5], [4], [7]]
Output
[null, null, null, null, true, false]

Explanation
TwoSum twoSum = new TwoSum();
twoSum.add(1);   // [] --> [1]
twoSum.add(3);   // [1] --> [1,3]
twoSum.add(5);   // [1,3] --> [1,3,5]
twoSum.find(4);  // 1 + 3 = 4, return true
twoSum.find(7);  // No two integers sum up to 7, return false

Constraints:
-10^5 <= number <= 10^5
-2^31 <= value <= 2^31-1
At most 5 * 10^4 calls will be made to add and find.

Algo:
array[num] a
dict[num]->cnt
add(n):  O(1)
	a.push_back(n)
	dict[n] += 1
find(val): O(N)
	for n in a:
		t = val - n
		if n != t:
			return dict.count(t)
		else:
			return dict.count(t) and dict[t] > 1
*/

class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int num) {
        a.push_back(num);
		++dict[num];
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (int n : a) {
			int64_t t = (int64_t)value - n;
			if (t < INT_MIN || t > INT_MAX) return false;
			if (dict.count(t) && (t != n || dict[t] > 1)) {
				return true;
			}
		}
		return false;
    }
	
private:
	vector<int> a;
	unordered_map<int, int> dict;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */