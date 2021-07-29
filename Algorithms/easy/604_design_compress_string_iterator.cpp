/**
    604. Design Compressed String Iterator
Design and implement a data structure for a compressed string iterator. The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter existing in the original uncompressed string.
Implement the StringIterator class:
next() Returns the next character if the original string still has uncompressed characters, otherwise returns a white space.
hasNext() Returns true if there is any letter needs to be uncompressed in the original string, otherwise returns false.

Example 1:
Input
["StringIterator", "next", "next", "next", "next", "next", "next", "hasNext", "next", "hasNext"]
[["L1e2t1C1o1d1e1"], [], [], [], [], [], [], [], [], []]
Output
[null, "L", "e", "e", "t", "C", "o", true, "d", true]

Explanation
StringIterator stringIterator = new StringIterator("L1e2t1C1o1d1e1");
stringIterator.next(); // return "L"
stringIterator.next(); // return "e"
stringIterator.next(); // return "e"
stringIterator.next(); // return "t"
stringIterator.next(); // return "C"
stringIterator.next(); // return "o"
stringIterator.hasNext(); // return True
stringIterator.next(); // return "d"
stringIterator.hasNext(); // return True

Constraints:
1 <= compressedString.length <= 1000
compressedString consists of lower-case an upper-case English letters and digits.
The number of a single character repetitions in compressedString is in the range [1, 10^9]
At most 100 calls will be made to next and hasNext.

Algo:
read c and cnt
*/

class StringIterator {
public:
    StringIterator(string_view compressedString) 
        : str(compressedString)
    {
        readNext();
    }
    
    char next() {
        if (!hasNext()) {
            return ' ';
        }
		--cnt;
		return symb;
    }
    
    bool hasNext() {
		if (cnt == 0) readNext();
		return cnt > 0;
    }
	
private:
	void readNext() {
		cnt = 0;
		if (pos == str.size()) {
			symb = -1;
		} else {
			symb = str[pos++];
			while (pos < str.size() && isdigit(str[pos])) {
				cnt = cnt*10 + str[pos++] - '0';
			}
		}
	}
	
private:
	string_view str;
	int symb = -1;
	int cnt = 0;
	size_t pos = 0;
};

"L1e2t1C1o1d1e1"
   ^ 

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */