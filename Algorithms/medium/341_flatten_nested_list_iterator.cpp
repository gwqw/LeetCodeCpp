/**
    341. Flatten Nested List Iterator
Given a nested list of integers, implement an iterator to flatten it.
Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Input: [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,1,2,1,1].

Example 2:
Input: [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,4,6].

*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    using Iterator = vector<NestedInteger>::const_iterator;
    using IteratorRange = pair<Iterator, Iterator>;
    
    struct IteratorRange {
        Iterator first;
        Iterator second;
        bool empty() const {return first == second;}
    };
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) 
        : cit(nestedList.begin(), nestedList.end())
    {}
    
    int next() {
        while (cit.empty() && !st.empty()) {
            cit = st.top();
            st.pop();
        }
        if (cit.first == cit.second) {
            throw logic_error("There is no next value");
        }
        while (!cit.first->isInteger()) {
            const auto& lst = cit.first->getList();
            ++cit.first;
            if (cit.first != cit.second) {
                st.push(cit);
            }
            //TODO: check if begin() == end()
            cit = {lst.begin(), lst.end()};
        }
        int ans = cit.first->getInteger();
        ++cit.first;        
        //cout << ans << " " << cit.first->getInteger() << endl;
        return ans;
    }
    
    bool hasNext() const {
        return cit.first != cit.second || !st.empty();
    }
private:
    stack<IteratorRange> st;
    IteratorRange cit;
    bool has_next = false;
    
    void getNextInt() {
        while (cit.empty() && !st.empty()) {
            cit = st.top();
            st.pop();
        }
        if (cit.first == cit.second) {
            has_next = false;
            return;
        }
        while (!cit.first->isInteger()) {
            const auto& lst = cit.first->getList();
            ++cit.first;
            if (cit.first != cit.second) {
                st.push(cit);
                cit = {lst.begin(), lst.end()};
            }
            //TODO: check if begin() == end()
            
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
